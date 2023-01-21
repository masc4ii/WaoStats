#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "DropBoxAuthDialog.h"
#include "BikeEditingDelegate.h"
#include "Splash.h"
#include "Globals.h"

#include <QDebug>
#include <QWidget>
#include <QDateTime>
#include <QPixmap>
#include <QMessageBox>
#include <QDirIterator>
#include <QFileInfo>
#include <QFileDialog>
#include <QSettings>
#include <QByteArray>
#include <QFont>
#include <QSplashScreen>
#include <QScrollArea>
#include <QScrollBar>
#include <QJsonDocument>
#include <QJsonObject>
#include "qwt.h"
#include "math.h"
#include "OsmWidget.h"

#include <qwt_legend.h>
#include <qwt_plot_layout.h>
#include <qwt_series_data.h>
#include <qwt_legend_label.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_canvas.h>
#include <qwt_picker_machine.h>
#include <qwt_symbol.h>
#include <qwt_plot_renderer.h>
#include <qwt_scale_draw.h>
#include <qwt_symbol.h>

// QMapControl includes.
#include <QMapControl/GeometryPointImage.h>
#include <QMapControl/GeometryPointImageScaled.h>
#include <QMapControl/GeometryWidget.h>
#include <QMapControl/LayerMapAdapter.h>
#include <QMapControl/MapAdapterOSM.h>
#include <QMapControl/MapAdapterYahoo.h>
#include <QMapControl/MapAdapterGoogle.h>
#include <QMapControl/MapAdapter4UM.h>
#include <QMapControl/MapAdapterOTM.h>
#include <QMapControl/MapAdapterOCM.h>
#include <QMapControl/MapAdapterThunderCycle.h>
#include <QMapControl/MapAdapterBing.h>

#include "dropbox/DropboxClient.h"
#include "dropbox/files/FilesRoutes.h"
#include "dropbox/endpoint/DropboxAppInfo.h"
#include "dropbox/endpoint/DropboxAuthInfo.h"

using namespace dropboxQt;

/**
 * @brief The Zoomer class
 */
class Zoomer: public QwtPlotZoomer
{
public:
    Zoomer( int xAxis, int yAxis, QwtPlot *plot ):
        QwtPlotZoomer( xAxis, yAxis, plot->canvas() )
    {
        m_pPlot = plot;
        setTrackerMode( QwtPicker::AlwaysOff );
        setRubberBand( QwtPicker::NoRubberBand );

        // RightButton: zoom out by 1
        // Ctrl+RightButton: zoom out to full size
        setMousePattern( QwtEventPattern::MouseSelect2,
            Qt::NoButton, Qt::ControlModifier );
        setMousePattern( QwtEventPattern::MouseSelect3,
            Qt::NoButton );
    }
    virtual void widgetMouseDoubleClickEvent( QMouseEvent *me )
    {
        if ( me->button() == Qt::LeftButton )
        {
            zoom( 0 );
        }
    }
private:
    QwtPlot *m_pPlot;
};

class TimeScaleDraw:public QwtScaleDraw
{
public:
    TimeScaleDraw(void)
    {
        baseTime = QDateTime( QDate( 1989, 12, 31 ), QTime( 1, 0, 0 ) );
    }
virtual QwtText label(double v)const
{
    QDateTime upTime = baseTime.addSecs((int)v);
    return upTime.toString( "hh:mm" );
}
private:
    QDateTime baseTime;
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Splash splash( QPixmap( ":/Icons/Splash.png" ).scaled( 300, 300, Qt::IgnoreAspectRatio, Qt::SmoothTransformation ) );
    splash.show();

    auto editDelegate = new BikeEditingDelegate(this);
    ui->treeWidgetTours->setItemDelegate(editDelegate);
    connect(editDelegate,
            &BikeEditingDelegate::editingFinished,
            [this] (const QModelIndex &index) {
        auto item = ui->treeWidgetTours->getItemFromIndex(index);
        onBikeItemEditingFinished(item); // this is my handler
    });

    //UI setup
    m_pTourData = &m_fitListener;
    m_timePlot = false;
    m_currentActiveTreeWidgetItem = nullptr;
    configureActionGroups();
    ui->qwtPlot->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->widgetOsm->setContextMenuPolicy(Qt::CustomContextMenu);
    configurePlots();
    configureMap();
    readSettings();
    scanTours();
    connect( ui->comboBoxSection, SIGNAL(currentIndexChanged(int)), this, SLOT(statistics()) );

    QTimer::singleShot( 1, this, SLOT( adjustMap() ) );

    splash.finish( this );
}

MainWindow::~MainWindow()
{
    saveTableToJson();
    writeSettings();
    delete ui;
}

void MainWindow::scanTours()
{
    ui->treeWidgetTours->clear();
    ui->treeWidgetTours->setColumnCount( 4 );
    ui->treeWidgetTours->hideColumn( 1 );
    ui->treeWidgetTours->hideColumn( 3 );
    ui->treeWidgetTours->setHeaderLabels( QStringList() << "Tour" << "Path" << "Distance" << "DistanceAsDouble" );
    ui->treeWidgetTours->setColumnWidth( 0, 190 );
    ui->treeWidgetTours->setColumnWidth( 2, 50 );

    QDir directory( workingPath() );
    QStringList subdirs;
    subdirs = directory.entryList( QStringList(), QDir::AllDirs | QDir::NoDotAndDotDot );

    foreach( QString subdir, subdirs )
    {
        QTreeWidgetItem *bikeItem = new QTreeWidgetItem(ui->treeWidgetTours);
        bikeItem->setText( 0, subdir );
        bikeItem->setFlags( Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDropEnabled );
        subdir.prepend( "/" );
        subdir.prepend( directory.absolutePath() );
        bikeItem->setText( 1, subdir );
        QStringList fits;
        QDir subQDir( subdir );
        fits = subQDir.entryList( QStringList() << "*.fit" << "*.FIT" << "*.gpx" << "*.GPX", QDir::Files, QDir::Name | QDir::Reversed );
        if( fits.empty() && bikeItem->text( 0 ) == "New" )
        {
            bikeItem->setHidden( true );
            continue;
        }
        foreach( QString fitFile, fits )
        {
            QTreeWidgetItem *fitItem = new QTreeWidgetItem( bikeItem );
            fitItem->setFlags( Qt::ItemIsDragEnabled | Qt::ItemIsEnabled | Qt::ItemIsSelectable );

            if( !loadTrackFromJson( subdir+"/"+fitFile, fitItem ) )
            {
                if( fitFile.endsWith( ".fit", Qt::CaseInsensitive ) ) scanFit( subdir+"/"+fitFile );
                else scanGpx( subdir+"/"+fitFile );
                QDateTime startQTime( QDate( 1989, 12, 31 ), QTime( 1, 0, 0 ) );
                startQTime = startQTime.addSecs( m_pTourData->getSession().startTime );

                fitItem->setText( 0, startQTime.toString( "yyyy-MM-dd - hh:mm:ss" ) );
                fitItem->setText( 1, subdir+"/"+fitFile );
                fitItem->setText( 2, QString( "%1 km" ).arg( (int)( m_pTourData->getSession().totalDistance / 1000.0 + 0.5 ) ) );
                fitItem->setText( 3, QString( "%1" ).arg( m_pTourData->getSession().totalDistance / 1000.0, 0, 'f', 10 ) );
            }
        }
    }
    ui->treeWidgetTours->expandAll();
    calcBikeTotalDistances();
    saveTableToJson();
    m_currentActiveTreeWidgetItem = nullptr;
}

void MainWindow::scanFit(QString fileName)
{
    fit::Decode decode;
    fit::MesgBroadcaster mesgBroadcaster;
    //FitListener listener;
    std::fstream file;

    file.open( fileName.toStdString().data(), std::ios::in | std::ios::binary);

    m_pTourData = &m_fitListener;

    m_fitListener.reset();
    mesgBroadcaster.AddListener((fit::FileIdMesgListener &)m_fitListener);
    mesgBroadcaster.AddListener((fit::MesgListener &)m_fitListener);

    try
    {
       decode.Read(&file, &mesgBroadcaster, &mesgBroadcaster, &m_fitListener);
    }
    catch (const fit::RuntimeException& e)
    {
       printf("Exception decoding file: %s\n", e.what());
    }

    file.close();
}

void MainWindow::scanGpx(QString fileName)
{
    m_pTourData = &m_gpxParser;
    m_gpxParser.loadGpx( fileName );
}

void MainWindow::adjustGui()
{
    ui->comboBoxSection->clear();
    ui->comboBoxSection->addItem( tr( "Track / Session" ) );
    for( int i = 0; i < m_pTourData->getSections().count(); i++ )
    {
        ui->comboBoxSection->addItem( tr( "Lap / Section " ) + QString::number( i + 1 ) );
    }
}

void MainWindow::statistics( void )
{
    QString info;
    foreach( TourData::deviceInfo_t deviceInfo, m_pTourData->getDeviceInfo() )
    {
        if( info.size() ) info += "\n";
        info += deviceInfo.name;
        if( deviceInfo.software.size() || deviceInfo.battery.size() ) info += ":";
        if( deviceInfo.software.size() ) info += "\n\t" + deviceInfo.software;
        if( deviceInfo.battery.size() ) info += "\n\t" + deviceInfo.battery;
    }
    ui->labelDeviceInfo->setText( info );

    int ind = ui->comboBoxSection->currentIndex();

    ui->groupBoxCadence->setVisible( (int)m_pTourData->getSession().maxCadence != 0 );
    ui->groupBoxHeartRate->setVisible( (int)m_pTourData->getSession().maxHeartRate != 0 );
    ui->groupBoxPower->setVisible( (int)m_pTourData->getSession().maxPower != 0 );
    ui->groupBoxProfile->setVisible( ( (int)m_pTourData->getSession().ascent != 0 ) && ( (int)m_pTourData->getSession().descent != 0 ) );
    ui->groupBoxTemperature->setVisible( (int)m_pTourData->getSession().minTemperature != 9999 );

    ui->actionCadence->setEnabled( (int)m_pTourData->getSession().maxCadence != 0 );
    ui->actionGrade->setEnabled( ( (int)m_pTourData->getSession().ascent != 0 ) && ( (int)m_pTourData->getSession().descent != 0 ) );
    ui->actionHeartRate->setEnabled( (int)m_pTourData->getSession().maxHeartRate != 0 );
    ui->actionCalories->setEnabled( (int)m_pTourData->getSession().totalCalories != 0 );
    ui->actionPower->setEnabled( (int)m_pTourData->getSession().maxPower != 0 );
    ui->actionLRBalance->setEnabled( (int)m_pTourData->getSession().maxPower != 0 );
    ui->actionGearInfo->setEnabled( m_pTourData->containsGearInfoFront() || m_pTourData->containsGearInfoRear() );
    ui->actionTemperature->setEnabled( (int)m_pTourData->getSession().minTemperature != 9999 );
    ui->actionDeviceBattery->setEnabled( (int)m_pTourData->getTourBatterySoc().first() >= 0 );

    if( ( ui->actionCadence->isChecked()        && !ui->actionCadence->isEnabled() )
     || ( ui->actionGrade->isChecked()          && !ui->actionGrade->isEnabled() )
     || ( ui->actionHeartRate->isChecked()      && !ui->actionHeartRate->isEnabled() )
     || ( ui->actionCalories->isChecked()       && !ui->actionCalories->isEnabled() )
     || ( ui->actionPower->isChecked()          && !ui->actionPower->isEnabled() )
     || ( ui->actionLRBalance->isChecked()      && !ui->actionLRBalance->isEnabled() )
     || ( ui->actionGearInfo->isChecked()       && !ui->actionGearInfo->isEnabled() )
     || ( ui->actionDeviceBattery->isChecked()  && !ui->actionDeviceBattery->isEnabled() ) )
    {
        ui->actionSpeed->setChecked( true );
        plotSelected();
    }

    ui->labelPickerCalories->setVisible( (int)m_pTourData->getSession().totalCalories != 0 );
    ui->labelPickerCaloriesName->setVisible( (int)m_pTourData->getSession().totalCalories != 0 );
    ui->labelPickerPower->setVisible( (int)m_pTourData->getSession().maxPower != 0 );
    ui->labelPickerPowerName->setVisible( (int)m_pTourData->getSession().maxPower != 0 );
    ui->labelPickerHeartRate->setVisible( (int)m_pTourData->getSession().maxHeartRate != 0 );
    ui->labelPickerHeartRateName->setVisible( (int)m_pTourData->getSession().maxHeartRate != 0 );
    ui->labelPickerCadence->setVisible( (int)m_pTourData->getSession().maxCadence != 0 );
    ui->labelPickerCadenceName->setVisible( (int)m_pTourData->getSession().maxCadence != 0 );
    ui->labelPickerAltitude->setVisible( (int)m_pTourData->getSession().altitudeMax != 0 && (int)m_pTourData->getSession().altitudeMin != 0 );
    ui->labelPickerAltitudeName->setVisible( (int)m_pTourData->getSession().altitudeMax != 0 && (int)m_pTourData->getSession().altitudeMin != 0 );
    ui->labelPickerGrade->setVisible( (int)m_pTourData->getSession().descent != 0 && (int)m_pTourData->getSession().ascent != 0 );
    ui->labelPickerGradeName->setVisible( (int)m_pTourData->getSession().descent != 0 && (int)m_pTourData->getSession().ascent != 0 );
    ui->labelPickerTemperature->setVisible( (int)m_pTourData->getSession().minTemperature != 9999 );
    ui->labelPickerTemperatureName->setVisible( (int)m_pTourData->getSession().minTemperature != 9999 );

    if( ind < 1 )
    {
        QDateTime startQTime( QDate( 1989, 12, 31 ), QTime( 1, 0, 0 ) );
        startQTime = startQTime.addSecs( m_pTourData->getSession().startTime );
        ui->labelDate->setText( startQTime.toString( "yyyy-MM-dd" ) );
        ui->labelStartTime->setText( startQTime.toString( "hh:mm:ss" ) );

        ui->labelDistance->setText( QString( "%1 km" ).arg( m_pTourData->getSession().totalDistance / 1000.0, 0, 'f', 3 ) );

        ui->labelTimeTotal->setText( QTime(0,0).addSecs( m_pTourData->getSession().totalElapsedTime ).toString( "hh:mm:ss" ) );
        ui->labelTimeMotion->setText( QTime(0,0).addSecs( m_pTourData->getSession().totalTimerTime ).toString( "hh:mm:ss" ) );

        ui->labelAscent->setText( QString( "%1 m" ).arg( (int)m_pTourData->getSession().ascent ) );
        ui->labelDescent->setText( QString( "%1 m" ).arg( (int)m_pTourData->getSession().descent ) );
        ui->labelMaximum->setText( QString( "%1 m" ).arg( (int)m_pTourData->getSession().altitudeMax ) );
        ui->labelMinimum->setText( QString( "%1 m" ).arg( (int)m_pTourData->getSession().altitudeMin ) );
        ui->labelNegGrade->setText( QString( "%1 \%" ).arg( m_pTourData->getSession().minGrade, 0, 'f', 1 ) );
        ui->labelPosGrade->setText( QString( "%1 \%" ).arg( m_pTourData->getSession().maxGrade, 0, 'f', 1 ) );

        ui->labelSpeedAverage->setText( QString( "%1 km/h" ).arg( m_pTourData->getSession().avgSpeed * 3.6, 0, 'f', 2 ) );
        ui->labelSpeedMax->setText( QString( "%1 km/h" ).arg( m_pTourData->getSession().maxSpeed * 3.6, 0, 'f', 2 ) );

        ui->labelCadenceAverage->setText( QString( "%1 rpm" ).arg( (int)m_pTourData->getSession().avgCadence ) );
        ui->labelCadenceMax->setText( QString( "%1 rpm" ).arg( (int)m_pTourData->getSession().maxCadence ) );

        ui->labelHeartRateAverage->setText( QString( "%1 bpm" ).arg( (int)m_pTourData->getSession().avgHeartRate ) );
        ui->labelHeartRateMax->setText( QString( "%1 bpm" ).arg( (int)m_pTourData->getSession().maxHeartRate ) );
        ui->labelHeartRateMin->setText( QString( "%1 bpm" ).arg( (int)m_pTourData->getSession().minHeartRate ) );
        ui->labelCalories->setText( QString( "%1 kcal" ).arg( (int)m_pTourData->getSession().totalCalories ) );

        ui->labelPowerAverage->setText( QString( "%1 W" ).arg( (int)m_pTourData->getSession().avgPower ) );
        ui->labelPowerMax->setText( QString( "%1 W" ).arg( (int)m_pTourData->getSession().maxPower ) );
        ui->labelPowerNormalized->setText( QString( "%1 W" ).arg( (int)m_pTourData->getSession().normalizedPower ) );
        ui->labelLRBalance->setText( QString( "%1" ).arg( (int)m_pTourData->getSession().leftRightBalance ) );

        ui->labelTempAverage->setText( QString( "%1 °C" ).arg( m_pTourData->getSession().avgTemperature ) );
        ui->labelTempMax->setText( QString( "%1 °C" ).arg( m_pTourData->getSession().maxTemperature ) );
        ui->labelTempMin->setText( QString( "%1 °C" ).arg( m_pTourData->getSession().minTemperature ) );
    }
    else
    {
        ind--;

        QDateTime startQTime( QDate( 1989, 12, 31 ), QTime( 1, 0, 0 ) );
        startQTime = startQTime.addSecs( m_pTourData->getSections().at(ind).startTime );
        ui->labelDate->setText( startQTime.toString( "yyyy-MM-dd" ) );
        ui->labelStartTime->setText( startQTime.toString( "hh:mm:ss" ) );

        ui->labelDistance->setText( QString( "%1 km" ).arg( m_pTourData->getSections().at(ind).totalDistance / 1000.0, 0, 'f', 3 ) );

        ui->labelTimeTotal->setText( QTime(0,0).addSecs( m_pTourData->getSections().at(ind).totalElapsedTime ).toString( "hh:mm:ss" ) );
        ui->labelTimeMotion->setText( QTime(0,0).addSecs( m_pTourData->getSections().at(ind).totalTimerTime ).toString( "hh:mm:ss" ) );

        ui->labelAscent->setText( QString( "%1 m" ).arg( (int)m_pTourData->getSections().at(ind).ascent ) );
        ui->labelDescent->setText( QString( "%1 m" ).arg( (int)m_pTourData->getSections().at(ind).descent ) );
        ui->labelMaximum->setText( QString( "%1 m" ).arg( (int)m_pTourData->getSections().at(ind).altitudeMax ) );
        ui->labelMinimum->setText( QString( "%1 m" ).arg( (int)m_pTourData->getSections().at(ind).altitudeMin ) );
        ui->labelNegGrade->setText( QString( "%1 \%" ).arg( m_pTourData->getSections().at(ind).minGrade, 0, 'f', 1 ) );
        ui->labelPosGrade->setText( QString( "%1 \%" ).arg( m_pTourData->getSections().at(ind).maxGrade, 0, 'f', 1 ) );

        ui->labelSpeedAverage->setText( QString( "%1 km/h" ).arg( m_pTourData->getSections().at(ind).avgSpeed * 3.6, 0, 'f', 2 ) );
        ui->labelSpeedMax->setText( QString( "%1 km/h" ).arg( m_pTourData->getSections().at(ind).maxSpeed * 3.6, 0, 'f', 2 ) );

        ui->labelCadenceAverage->setText( QString( "%1 rpm" ).arg( (int)m_pTourData->getSections().at(ind).avgCadence ) );
        ui->labelCadenceMax->setText( QString( "%1 rpm" ).arg( (int)m_pTourData->getSections().at(ind).maxCadence ) );

        ui->labelHeartRateAverage->setText( QString( "%1 bpm" ).arg( (int)m_pTourData->getSections().at(ind).avgHeartRate ) );
        ui->labelHeartRateMax->setText( QString( "%1 bpm" ).arg( (int)m_pTourData->getSections().at(ind).maxHeartRate ) );
        ui->labelHeartRateMin->setText( QString( "%1 bpm" ).arg( (int)m_pTourData->getSections().at(ind).minHeartRate ) );
        ui->labelCalories->setText( QString( "%1 kcal" ).arg( (int)m_pTourData->getSections().at(ind).totalCalories ) );

        ui->labelPowerAverage->setText( QString( "%1 W" ).arg( (int)m_pTourData->getSections().at(ind).avgPower ) );
        ui->labelPowerMax->setText( QString( "%1 W" ).arg( (int)m_pTourData->getSections().at(ind).maxPower ) );
        ui->labelPowerNormalized->setText( QString( "%1 W" ).arg( (int)m_pTourData->getSections().at(ind).normalizedPower ) );
        ui->labelLRBalance->setText( QString( "%1" ).arg( (int)m_pTourData->getSections().at(ind).leftRightBalance ) );

        ui->labelTempAverage->setText( QString( "%1 °C" ).arg( m_pTourData->getSections().at(ind).avgTemperature ) );
        ui->labelTempMax->setText( QString( "%1 °C" ).arg( m_pTourData->getSections().at(ind).maxTemperature ) );
        ui->labelTempMin->setText( QString( "%1 °C" ).arg( m_pTourData->getSections().at(ind).minTemperature ) );
    }
}

void MainWindow::configureMap()
{
    // Create a new QMapControl.
    m_map_control = new QMapControl( ui->widgetOsm );
    QHBoxLayout* layout = new QHBoxLayout( ui->widgetOsm );
    connect( ui->widgetOsm, SIGNAL(resized()), this, SLOT(adjustMap()) );
    layout->addWidget( m_map_control );
    layout->setMargin(0);

    // Create/add a layer with the default OSM map adapter.
    m_map_control->addLayer(std::make_shared<LayerMapAdapter>("Map", std::make_shared<MapAdapterOTM>()));

    // Create the tours layer.
    m_layer_tours = std::make_shared<LayerGeometry>("Tours");
    m_map_control->addLayer(m_layer_tours);

    //m_map_control->enableScalebar( true );
    //m_map_control->enableCrosshairs( true );
    m_map_control->enableZoomControls( false );

    // Create the map provider actions.
    QActionGroup* map_provider_group = new QActionGroup(this);
    map_provider_group->addAction( ui->action_google_map );
    map_provider_group->addAction( ui->action_google_satelite );
    map_provider_group->addAction( ui->action_google_hybrid );
    map_provider_group->addAction( ui->action_google_terrain );
    map_provider_group->addAction( ui->action_osm );
    map_provider_group->addAction( ui->action_otm );
    map_provider_group->addAction( ui->action_4um );
    map_provider_group->addAction( ui->action_cycle_osm );
    map_provider_group->addAction( ui->action_thunderforest_cycle );
    map_provider_group->addAction( ui->action_thunderforest_landscape );
    map_provider_group->addAction( ui->action_bing );
    // Ensure the map provider actions are checkable.
    ui->action_google_map->setCheckable( true );
    ui->action_google_satelite->setCheckable( true );
    ui->action_google_hybrid->setCheckable( true );
    ui->action_google_terrain->setCheckable( true );
    ui->action_osm->setCheckable( true );
    ui->action_otm->setCheckable( true );
    ui->action_4um->setCheckable( true );
    ui->action_cycle_osm->setCheckable( true );
    ui->action_thunderforest_cycle->setCheckable( true );
    ui->action_thunderforest_landscape->setCheckable( true );
    ui->action_bing->setCheckable( true );
    // Default to OTM map.
    ui->action_otm->setChecked( true );
    // Connect signal/slot to set the map provider.
    QObject::connect( map_provider_group, &QActionGroup::triggered, this, &MainWindow::mapProviderSelected );

    //Default map picture
    m_map_control->setMapFocusPoint( PointWorldCoord( 10.9281, 50.6861 ) );
    m_map_control->setZoom( 5 );

    // Create the symbole layer.
    m_layer_symb = std::make_shared<LayerGeometry>("Symbols");
    m_map_control->addLayer( m_layer_symb );

    m_iconCrossHairs = QPixmap( ":/Icons/Icons/crossed_circle.svg" ).scaled( 20, 20 );
}

void MainWindow::unconfigurePlots()
{
    disconnect( m_picker, SIGNAL( appended(QPoint) ), this, SLOT( pointInfo(QPoint) ) );
    disconnect( m_picker, SIGNAL( moved(QPoint) ), this, SLOT( pointInfo(QPoint) ) );
    disconnect( m_picker, SIGNAL( activated(bool) ), this, SLOT( pointInfoHide(bool) ) );
    delete m_picker;
    delete m_pZoomer[1];
    delete m_pZoomer[0];
    delete m_pPanner;
    delete m_curve[0];
    delete m_curve[1];
    if( m_curve[2] != Q_NULLPTR ) delete m_curve[2];
    if( m_curve[3] != Q_NULLPTR ) delete m_curve[3];
}

void MainWindow::configurePlots( void )
{
    //Plot setup
    //ui->qwtPlot->setTitle( "Session" );
    if( !m_timePlot )
    {
        ui->qwtPlot->setAxisTitle( QwtPlot::xBottom, QwtText( "Distance [km]" ) );
        ui->qwtPlot->setAxisScaleDraw( QwtPlot::xBottom, new QwtScaleDraw() );
    }
    else
    {
        ui->qwtPlot->setAxisTitle( QwtPlot::xBottom, QwtText( "Time [hh:mm]" ) );
        ui->qwtPlot->setAxisScaleDraw( QwtPlot::xBottom, new TimeScaleDraw() );
    }
    ui->qwtPlot->setAxisTitle( QwtPlot::yLeft, QwtText( "Altitude [m]" ) );
    //QwtLegend *legend = new QwtLegend;
    //legend->setDefaultItemMode( QwtLegendData::Checkable );
    //connect( legend, SIGNAL(checked(QVariant,bool,int)), SLOT(onLegendChecked(QVariant,bool,int)) );
    //ui->qwtPlot->insertLegend( legend, QwtPlot::BottomLegend );
    ui->qwtPlot->setAxisAutoScale( QwtPlot::yLeft );
    ui->qwtPlot->setAxisAutoScale( QwtPlot::yRight );
    //ui->qwtPlot->setAxisAutoScale( QwtPlot::xBottom );

    //Background
    QwtPlotCanvas *canvas = (QwtPlotCanvas *)ui->qwtPlot->canvas();
    canvas->setBorderRadius( 10 );
    ui->qwtPlot->setCanvas( canvas );
    ui->qwtPlot->setCanvasBackground( Qt::white );

    // grid
    QwtPlotGrid *grid = new QwtPlotGrid;
    grid->enableXMin( true );
    grid->enableYMin( true );
    grid->setMajorPen( Qt::lightGray, 0, Qt::SolidLine );
    grid->setMinorPen( Qt::lightGray, 0 , Qt::DotLine );
    grid->attach( ui->qwtPlot );

    m_curve[0] = new QwtPlotCurve( QString( "Altitude" ) );
    m_curve[0]->setYAxis( QwtPlot::yLeft );
    m_curve[0]->setRenderHint( QwtPlotItem::RenderAntialiased );
    m_curve[1] = Q_NULLPTR;
    m_curve[2] = Q_NULLPTR;
    m_curve[3] = Q_NULLPTR;

    if( ui->actionSpeed->isChecked() )
    {
        m_curve[1] = new QwtPlotCurve( QString( "Speed" ) );
        ui->qwtPlot->setAxisTitle( QwtPlot::yRight, QwtText( "Speed [km/h]" ) );
    }
    else if( ui->actionDeviceBattery->isChecked() )
    {
        m_curve[1] = new QwtPlotCurve( QString( "Device Battery" ) );
        ui->qwtPlot->setAxisTitle( QwtPlot::yRight, QwtText( "Device Battery [%]" ) );
    }
    else if( ui->actionCadence->isChecked() )
    {
        m_curve[1] = new QwtPlotCurve( QString( "Cadence" ) );
        ui->qwtPlot->setAxisTitle( QwtPlot::yRight, QwtText( "Cadence [rpm]" ) );
    }
    else if( ui->actionTemperature->isChecked() )
    {
        m_curve[1] = new QwtPlotCurve( QString( "Temperature" ) );
        ui->qwtPlot->setAxisTitle( QwtPlot::yRight, QwtText( "Temperature [°C]" ) );
    }
    else if( ui->actionGrade->isChecked() )
    {
        m_curve[1] = new QwtPlotCurve( QString( "Grade" ) );
        ui->qwtPlot->setAxisTitle( QwtPlot::yRight, QwtText( "Grade [%]" ) );
    }
    else if( ui->actionHeartRate->isChecked() )
    {
        m_curve[1] = new QwtPlotCurve( QString( "Heart Rate" ) );
        ui->qwtPlot->setAxisTitle( QwtPlot::yRight, QwtText( "Heart Rate [bpm]" ) );
    }
    else if( ui->actionCalories->isChecked() )
    {
        m_curve[1] = new QwtPlotCurve( QString( "Calories" ) );
        ui->qwtPlot->setAxisTitle( QwtPlot::yRight, QwtText( "Calories [kcal]" ) );
    }
    else if( ui->actionPower->isChecked() )
    {
        m_curve[1] = new QwtPlotCurve( QString( "Power" ) );
        ui->qwtPlot->setAxisTitle( QwtPlot::yRight, QwtText( "Power [W]" ) );
    }
    else if( ui->actionLRBalance->isChecked() )
    {
        m_curve[1] = new QwtPlotCurve( QString( "L/R Balance" ) );
        ui->qwtPlot->setAxisTitle( QwtPlot::yRight, QwtText( "L/R Balance" ) );
    }
    else if( ui->actionGearInfo->isChecked() )
    {
        m_curve[1] = new QwtPlotCurve( QString( "Gear Ratio" ) );
        m_curve[2] = new QwtPlotCurve( QString( "Gear Front" ) );
        m_curve[3] = new QwtPlotCurve( QString( "Gear Rear" ) );
        ui->qwtPlot->setAxisTitle( QwtPlot::yRight, QwtText( "Gear Ratio / Gear Number" ) );
        m_curve[2]->setYAxis( QwtPlot::yRight );
        m_curve[2]->setRenderHint( QwtPlotItem::RenderAntialiased );
        m_curve[3]->setYAxis( QwtPlot::yRight );
        m_curve[3]->setRenderHint( QwtPlotItem::RenderAntialiased );
        QPen p( QColor( 100, 205, 255 ) );
        m_curve[2]->setPen( p );
        p.setColor( QColor( 255, 200, 0 ) );
        m_curve[3]->setPen( p );
    }
    m_curve[1]->setYAxis( QwtPlot::yRight );
    m_curve[1]->setRenderHint( QwtPlotItem::RenderAntialiased );
    ui->qwtPlot->setAxisVisible( QwtPlot::yRight );

    QPen p( Qt::red );
    m_curve[0]->setPen( p );
    m_curve[0]->setBrush( QBrush( QColor( 255, 0, 0, 25 ) ) );
    p.setColor( QColor( 0, 180, 0 ) );
    m_curve[1]->setPen( p );

    //Zoomer init
    m_pZoomer[0] = new Zoomer( QwtPlot::xBottom, QwtPlot::yLeft, ui->qwtPlot );
    m_pZoomer[0]->setRubberBand( QwtPicker::RectRubberBand );
    m_pZoomer[0]->setRubberBandPen( QColor( Qt::gray ) );
    m_pZoomer[1] = new Zoomer( QwtPlot::xTop, QwtPlot::yRight, ui->qwtPlot );

    m_pPanner = new QwtPlotPanner( ui->qwtPlot->canvas() );
    m_pPanner->setMouseButton( Qt::LeftButton, Qt::ControlModifier );

    m_picker = new QwtPlotPicker( QwtAxis::XBottom, QwtAxis::YLeft,
        QwtPlotPicker::VLineRubberBand, QwtPicker::AlwaysOff,
        ui->qwtPlot->canvas() );
    m_picker->setStateMachine( new QwtPickerTrackerMachine() );
    m_picker->setRubberBandPen( QColor( Qt::darkGray ) );
    m_picker->setRubberBand( QwtPicker::VLineRubberBand );

    connect( m_picker, SIGNAL( appended(QPoint) ), this, SLOT( pointInfo(QPoint) ) );
    connect( m_picker, SIGNAL( moved(QPoint) ), this, SLOT( pointInfo(QPoint) ) );
    connect( m_picker, SIGNAL( activated(bool) ), this, SLOT( pointInfoHide(bool) ) );
}

void MainWindow::drawPlots( void )
{
    TourData *pTourData = m_pTourData;
    /*qDebug() << "DebugSizes"
             << pTourData->getTourTimeStamp().size()
             << pTourData->getTourDistance().size()
             << pTourData->getTourSpeed().size()
             << pTourData->getTourAltitude().size()
             << pTourData->getTourCadence().size();*/

    if( ui->actionCadence->isChecked() && (int)m_pTourData->getSession().maxCadence == 0 )
    {
        unconfigurePlots();
        configurePlots();
        ui->actionSpeed->setChecked( true );
    }

    if( !m_timePlot ) m_curve[0]->setSamples( pTourData->getTourDistance().data(), pTourData->getTourAltitude().data(), pTourData->getTourDistance().count() );
    else              m_curve[0]->setSamples( pTourData->getTourTimeStamp().data(), pTourData->getTourAltitude().data(), pTourData->getTourDistance().count() );
    m_curve[0]->attach( ui->qwtPlot );
    m_curve[0]->setTitle( QString( "Altitude" ) );

    if( ui->actionSpeed->isChecked() )
    {
        if( !m_timePlot ) m_curve[1]->setSamples( pTourData->getTourDistance().data(), pTourData->getTourSpeed().data(), pTourData->getTourDistance().count() );
        else              m_curve[1]->setSamples( pTourData->getTourTimeStamp().data(), pTourData->getTourSpeed().data(), pTourData->getTourDistance().count() );
        m_curve[1]->setTitle( QString( "Speed" ) );
    }
    else if( ui->actionDeviceBattery->isChecked() )
    {
        if( !m_timePlot ) m_curve[1]->setSamples( pTourData->getTourDistance().data(), pTourData->getTourBatterySoc().data(), pTourData->getTourDistance().count() );
        else              m_curve[1]->setSamples( pTourData->getTourTimeStamp().data(), pTourData->getTourBatterySoc().data(), pTourData->getTourDistance().count() );
        m_curve[1]->setTitle( QString( "Device Battery" ) );
    }
    else if( ui->actionCadence->isChecked() )
    {
        if( !m_timePlot ) m_curve[1]->setSamples( pTourData->getTourDistance().data(), pTourData->getTourCadence().data(), pTourData->getTourDistance().count() );
        else              m_curve[1]->setSamples( pTourData->getTourTimeStamp().data(), pTourData->getTourCadence().data(), pTourData->getTourDistance().count() );
        m_curve[1]->setTitle( QString( "Cadence" ) );
        m_curve[1]->setStyle( QwtPlotCurve::CurveStyle::NoCurve );
        m_curve[1]->setSymbol( new QwtSymbol( QwtSymbol::Ellipse, QBrush(), QPen( QColor( 0, 128, 255 ) ), QSize() ) );
        m_curve[1]->setPen( QPen( QColor( 225, 180, 0 ) ) );
    }
    else if( ui->actionTemperature->isChecked() )
    {
        if( !m_timePlot ) m_curve[1]->setSamples( pTourData->getTourDistance().data(), pTourData->getTourTemperature().data(), pTourData->getTourDistance().count() );
        else              m_curve[1]->setSamples( pTourData->getTourTimeStamp().data(), pTourData->getTourTemperature().data(), pTourData->getTourDistance().count() );
        m_curve[1]->setTitle( QString( "Temperature" ) );
    }
    else if( ui->actionGrade->isChecked() )
    {
        if( !m_timePlot ) m_curve[1]->setSamples( pTourData->getTourDistance().data(), pTourData->getTourGrade().data(), pTourData->getTourDistance().count() );
        else              m_curve[1]->setSamples( pTourData->getTourTimeStamp().data(), pTourData->getTourGrade().data(), pTourData->getTourDistance().count() );
        m_curve[1]->setTitle( QString( "Grade" ) );
        m_curve[1]->setBrush( QBrush( QColor( 0, 180, 0, 25 ) ) );
    }
    else if( ui->actionHeartRate->isChecked() )
    {
        if( !m_timePlot ) m_curve[1]->setSamples( pTourData->getTourDistance().data(), pTourData->getTourHeartRate().data(), pTourData->getTourDistance().count() );
        else              m_curve[1]->setSamples( pTourData->getTourTimeStamp().data(), pTourData->getTourHeartRate().data(), pTourData->getTourDistance().count() );
        m_curve[1]->setTitle( QString( "Heart Rate" ) );
    }
    else if( ui->actionCalories->isChecked() )
    {
        if( !m_timePlot ) m_curve[1]->setSamples( pTourData->getTourDistance().data(), pTourData->getTourCalories().data(), pTourData->getTourDistance().count() );
        else              m_curve[1]->setSamples( pTourData->getTourTimeStamp().data(), pTourData->getTourCalories().data(), pTourData->getTourDistance().count() );
        m_curve[1]->setTitle( QString( "Calories" ) );
    }
    else if( ui->actionPower->isChecked() )
    {
        if( !m_timePlot ) m_curve[1]->setSamples( pTourData->getTourDistance().data(), pTourData->getTourPower().data(), pTourData->getTourDistance().count() );
        else              m_curve[1]->setSamples( pTourData->getTourTimeStamp().data(), pTourData->getTourPower().data(), pTourData->getTourDistance().count() );
        m_curve[1]->setTitle( QString( "Power" ) );
    }
    else if( ui->actionLRBalance->isChecked() )
    {
        if( !m_timePlot ) m_curve[1]->setSamples( pTourData->getTourDistance().data(), pTourData->getTourLRBalance().data(), pTourData->getTourDistance().count() );
        else              m_curve[1]->setSamples( pTourData->getTourTimeStamp().data(), pTourData->getTourLRBalance().data(), pTourData->getTourDistance().count() );
        m_curve[1]->setTitle( QString( "L/R Balance" ) );
    }
    else if( ui->actionGearInfo->isChecked() )
    {
        if( !m_timePlot )
        {
            m_curve[1]->setSamples( pTourData->getGearDistance().data(), pTourData->getGearRatio().data(), pTourData->getGearDistance().count() );
            m_curve[2]->setSamples( pTourData->getGearDistance().data(), pTourData->getGearNumFront().data(), pTourData->getGearDistance().count() );
            m_curve[3]->setSamples( pTourData->getGearDistance().data(), pTourData->getGearNumRear().data(), pTourData->getGearDistance().count() );
        }
        else
        {
            m_curve[1]->setSamples( pTourData->getGearTimeStamp().data(), pTourData->getGearRatio().data(), pTourData->getGearDistance().count() );
            m_curve[2]->setSamples( pTourData->getGearTimeStamp().data(), pTourData->getGearNumFront().data(), pTourData->getGearDistance().count() );
            m_curve[3]->setSamples( pTourData->getGearTimeStamp().data(), pTourData->getGearNumRear().data(), pTourData->getGearDistance().count() );
        }
        m_curve[1]->setTitle( QString( "Gear Ratio" ) );
        m_curve[1]->setStyle( QwtPlotCurve::Steps );
        m_curve[2]->setTitle( QString( "Gear Front" ) );
        m_curve[2]->setStyle( QwtPlotCurve::Steps );
        m_curve[3]->setTitle( QString( "Gear Rear" ) );
        m_curve[3]->setStyle( QwtPlotCurve::Steps );
        m_curve[2]->attach( ui->qwtPlot );
        m_curve[3]->attach( ui->qwtPlot );
    }
    m_curve[1]->attach( ui->qwtPlot );

    if( !m_timePlot ) ui->qwtPlot->setAxisScale( QwtPlot::xBottom, 0, pTourData->getTourDistance().last(), (int)(pTourData->getTourDistance().last() / 5) );
    else              ui->qwtPlot->setAxisScale( QwtPlot::xBottom, pTourData->getTourTimeStamp().first(), pTourData->getTourTimeStamp().last(), 60*15 );

    ui->qwtPlot->setAxisAutoScale( QwtPlot::yLeft );
    if( ui->actionDeviceBattery->isChecked() ) ui->qwtPlot->setAxisScale( QwtPlot::yRight, 0, 100, 20 );
    else if( ui->actionGearInfo->isChecked() ) ui->qwtPlot->setAxisScale( QwtPlot::yRight, 0, m_pTourData->gearCountRear(), 2 );
    else ui->qwtPlot->setAxisAutoScale( QwtPlot::yRight );

    foreach(QwtPlotMarker *marker, m_lapMarker) delete marker;
    m_lapMarker.clear();
    if( pTourData->getSections().count() > 1 )
    {
        for( int i = 0; i < pTourData->getSections().count(); i++ )
        {
            QwtPlotMarker *marker = new QwtPlotMarker();
            if(      !m_timePlot && i == 0 ) marker->setValue( 0.0, 0.0 );
            else if( !m_timePlot && i != 0 ) marker->setValue( pTourData->getSections().at( i ).startDistance, 0.0 );
            else                             marker->setValue( pTourData->getSections().at( i ).startTime, 0.0 );
            marker->setLineStyle( QwtPlotMarker::VLine );
            marker->setLabelAlignment( Qt::AlignRight | Qt::AlignBottom );
            marker->setLinePen( Qt::darkMagenta, 1, Qt::DashDotLine );
            QFont font;
            font.setPointSize( 10 );
            QwtText text = QwtText( QString::number( i + 1 ) );
            text.setFont( font );
            marker->setLabel( text );
            marker->setLabelAlignment( Qt::AlignTop | Qt::AlignRight );
            marker->attach( ui->qwtPlot );
            m_lapMarker.append( marker );
        }
    }

    ui->qwtPlot->replot();

    m_pZoomer[0]->setZoomBase( true );
    m_pZoomer[1]->setZoomBase( true );
}

void MainWindow::drawTourToMap(TourData *pTourData, bool autoZoom = true)
{
    if( !pTourData->containsPositionInfo() )
    {
        //Default map picture
        m_layer_tours->clearGeometries();
        m_map_control->setMapFocusPoint( PointWorldCoord( 10.9281, 50.6861 ) );
        m_map_control->setZoom( 5 );
        return;
    }

    // Create a pen to draw.
    QPen pen(QColor(0, 0, 255));
    pen.setWidth(3);
    // Add the points of the sights tour.
    std::vector<PointWorldCoord> points;

    for( int i = 0; i < pTourData->getTourPosLat().size(); i++ )
    {
        points.emplace_back( pTourData->getTourPosLong().at(i) * ( 180 / pow(2,31) ),
                             pTourData->getTourPosLat().at(i) * ( 180 / pow(2,31) ) );
    }
    //qDebug() << "Draw track with" << points.size() << "points.";

    // Autozoom to track
    if( autoZoom ) m_map_control->setMapFocusPoint( points, true );

    // Create the sights tour as a Line String and add it to the notes layer.
    m_tour_sights = std::make_shared<GeometryLineString>(points);
    m_tour_sights->setPen(pen);
    m_layer_tours->clearGeometries();
    m_layer_tours->addGeometry(m_tour_sights);
}

QString MainWindow::workingPath()
{
    if( !m_workingPath.endsWith( '/' ) ) m_workingPath.append( '/' );
    return m_workingPath;
}

void MainWindow::on_treeWidgetTours_itemActivated(QTreeWidgetItem *item, int column)
{
    QString fileName = item->text( 1 );

    markActiveTour( item );

    if( QFileInfo( fileName ).exists() )
    {
        //qDebug() << fileName;
        if( fileName.endsWith( ".fit", Qt::CaseInsensitive ) ) scanFit( fileName );
        else scanGpx( fileName );
        adjustGui();
        statistics();
        drawPlots();
        drawTourToMap( m_pTourData );
    }
}

void MainWindow::mapProviderSelected(QAction* action)
{
    // Create a replacement map layer.
    std::shared_ptr<LayerMapAdapter> map_layer(std::make_shared<LayerMapAdapter>("Map"));

    // Set the map to Google Maps.
    if(action == ui->action_google_map)
    {
        map_layer->setMapAdapter(std::make_shared<MapAdapterGoogle>(qmapcontrol::MapAdapterGoogle::GoogleLayerType::MAPS));
    }
    // Set the map to Google Sat.
    else if(action == ui->action_google_satelite)
    {
        map_layer->setMapAdapter(std::make_shared<MapAdapterGoogle>(qmapcontrol::MapAdapterGoogle::GoogleLayerType::SATELLITE_ONLY));
    }
    // Set the map to Google Hybrid.
    else if(action == ui->action_google_hybrid)
    {
        map_layer->setMapAdapter(std::make_shared<MapAdapterGoogle>(qmapcontrol::MapAdapterGoogle::GoogleLayerType::HYBRID));
    }
    // Set the map to Google Terrain.
    else if(action == ui->action_google_terrain)
    {
        map_layer->setMapAdapter(std::make_shared<MapAdapterGoogle>(qmapcontrol::MapAdapterGoogle::GoogleLayerType::TERRAIN));
    }
    // Set the map to OSM.
    else if(action == ui->action_osm)
    {
        map_layer->setMapAdapter(std::make_shared<MapAdapterOSM>());
    }
    // Set the map to OTM.
    else if(action == ui->action_otm)
    {
        map_layer->setMapAdapter(std::make_shared<MapAdapterOTM>());
    }
    // Set the map to 4UMaps.
    else if(action == ui->action_4um)
    {
        map_layer->setMapAdapter(std::make_shared<MapAdapter4UM>());
    }
    // Set the map to CycleOSM.
    else if(action == ui->action_cycle_osm)
    {
        map_layer->setMapAdapter(std::make_shared<MapAdapterOCM>());
    }
    // Set the map to Thunderforest Cycle.
    else if(action == ui->action_thunderforest_cycle)
    {
        map_layer->setMapAdapter(std::make_shared<MapAdapterThunderCycle>(qmapcontrol::MapAdapterThunderCycle::ThunderforestLayerType::CYCLE));
    }
    // Set the map to Thunderforest Landscape.
    else if(action == ui->action_thunderforest_landscape)
    {
        map_layer->setMapAdapter(std::make_shared<MapAdapterThunderCycle>(qmapcontrol::MapAdapterThunderCycle::ThunderforestLayerType::LANDSCAPE));
    }
    // Set the map to Bing.
    else if(action == ui->action_bing)
    {
        map_layer->setMapAdapter(std::make_shared<MapAdapterBing>());
    }

    // Add the replacement map layer.
    m_map_control->addLayer(map_layer, 0);
}

void MainWindow::plotSelected( void )
{
    unconfigurePlots();
    if( ui->actionPlotTime->isChecked() )
    {
        m_timePlot = true;
    }
    else if( ui->actionPlotDistance->isChecked() )
    {
        m_timePlot = false;
    }
    configurePlots();
    drawPlots();
}

void MainWindow::adjustMap()
{
    // Set the new viewport size.
    m_map_control->setViewportSize(ui->widgetOsm->size());
}

void MainWindow::pointInfo( QPoint point )
{
    if( !m_timePlot )
    {
        double distance = ui->qwtPlot->invTransform( QwtPlot::xBottom, point.x() );

        for( int i = 0; i < m_pTourData->getTourDistance().size(); i++ )
        {
            if( m_pTourData->getTourDistance().at(i) >= distance )
            {
                ui->labelPickerDistance->setText( QString( "%1 km" ).arg( m_pTourData->getTourDistance().at( i ), 0, 'f', 3 ) );
                ui->labelPickerTime->setText( QDateTime( QDate( 1989, 12, 31 ), QTime( 1, 0, 0 ) ).addSecs( (int)m_pTourData->getTourTimeStamp().at( i ) ).toString( "hh:mm:ss" ) );
                ui->labelPickerAltitude->setText( QString( "%1 m" ).arg( (int)m_pTourData->getTourAltitude().at( i ) ) );
                ui->labelPickerSpeed->setText( QString( "%1 km/h" ).arg( m_pTourData->getTourSpeed().at( i ), 0, 'f', 1 ) );
                ui->labelPickerCadence->setText( QString( "%1 rpm" ).arg( (int)m_pTourData->getTourCadence().at( i ) ) );
                ui->labelPickerTemperature->setText( QString( "%1 °C" ).arg( (int)m_pTourData->getTourTemperature().at( i ) ) );
                ui->labelPickerGrade->setText( QString( "%1 %" ).arg( m_pTourData->getTourGrade().at( i ), 0, 'f', 1 ) );
                ui->labelPickerHeartRate->setText( QString( "%1 bpm" ).arg( (int)m_pTourData->getTourHeartRate().at( i ) ) );
                ui->labelPickerPower->setText( QString( "%1 W" ).arg( m_pTourData->getTourPower().at( i ), 0, 'f', 1 ) );
                ui->labelPickerCalories->setText( QString( "%1 kcal" ).arg( (int)m_pTourData->getTourCalories().at( i ) ) );

                // Create the "cross" and add it to the layer.
                std::shared_ptr<GeometryPoint> cross(std::make_shared<GeometryPointImage>( PointWorldCoord( m_pTourData->getTourPosLong().at(i) * ( 180 / pow(2,31) ),
                                                                                                            m_pTourData->getTourPosLat().at(i)  * ( 180 / pow(2,31) ) ),
                                                                                                            m_iconCrossHairs ) );
                m_layer_symb->clearGeometries();
                m_layer_symb->addGeometry(cross);
                m_layer_symb->setVisible( true );
                return;
            }
        }
    }
    else
    {
        double time = ui->qwtPlot->invTransform( QwtPlot::xBottom, point.x() );

        for( int i = 0; i < m_pTourData->getTourTimeStamp().size(); i++ )
        {
            if( m_pTourData->getTourTimeStamp().at(i) >= time )
            {
                ui->labelPickerDistance->setText( QString( "%1 km" ).arg( m_pTourData->getTourDistance().at( i ), 0, 'f', 3 ) );
                ui->labelPickerTime->setText( QDateTime( QDate( 1989, 12, 31 ), QTime( 1, 0, 0 ) ).addSecs( (int)m_pTourData->getTourTimeStamp().at( i ) ).toString( "hh:mm:ss" ) );
                ui->labelPickerAltitude->setText( QString( "%1 m" ).arg( (int)m_pTourData->getTourAltitude().at( i ) ) );
                ui->labelPickerSpeed->setText( QString( "%1 km/h" ).arg( m_pTourData->getTourSpeed().at( i ), 0, 'f', 1 ) );
                ui->labelPickerCadence->setText( QString( "%1 rpm" ).arg( (int)m_pTourData->getTourCadence().at( i ) ) );
                ui->labelPickerTemperature->setText( QString( "%1 °C" ).arg( (int)m_pTourData->getTourTemperature().at( i ) ) );
                ui->labelPickerGrade->setText( QString( "%1 %" ).arg( m_pTourData->getTourGrade().at( i ), 0, 'f', 1 ) );
                ui->labelPickerHeartRate->setText( QString( "%1 bpm" ).arg( (int)m_pTourData->getTourHeartRate().at( i ) ) );
                ui->labelPickerPower->setText( QString( "%1 W" ).arg( m_pTourData->getTourPower().at( i ), 0, 'f', 1 ) );
                ui->labelPickerCalories->setText( QString( "%1 kcal" ).arg( (int)m_pTourData->getTourCalories().at( i ) ) );

                // Create the "cross" and add it to the layer.
                std::shared_ptr<GeometryPoint> cross(std::make_shared<GeometryPointImage>( PointWorldCoord( m_pTourData->getTourPosLong().at(i) * ( 180 / pow(2,31) ),
                                                                                                            m_pTourData->getTourPosLat().at(i)  * ( 180 / pow(2,31) ) ),
                                                                                                            m_iconCrossHairs ) );
                m_layer_symb->clearGeometries();
                m_layer_symb->addGeometry(cross);
                m_layer_symb->setVisible( true );
                return;
            }
        }
    }
}

void MainWindow::pointInfoHide( bool on )
{
    if( on ) return;
    ui->labelPickerDistance->setText( QString( "-" ) );
    ui->labelPickerTime->setText( QString( "-" ) );
    ui->labelPickerAltitude->setText( QString( "-" ) );
    ui->labelPickerSpeed->setText( QString( "-" ) );
    ui->labelPickerCadence->setText( QString( "-" ) );
    ui->labelPickerTemperature->setText( QString( "-" ) );
    ui->labelPickerGrade->setText( QString( "-" ) );
    ui->labelPickerHeartRate->setText( QString( "-" ) );
    ui->labelPickerPower->setText( QString( "-" ) );
    ui->labelPickerCalories->setText( QString( "-" ) );
    m_layer_symb->setVisible( false );
}

void MainWindow::on_actionSyncDropbox_triggered()
{
    //todo: how to see, if token is valid?
    //Create token
    DropBoxAuthDialog* dropboxAuth = new DropBoxAuthDialog( workingPath(), this );
    int ret = dropboxAuth->exec();
    QString token = dropboxAuth->getToken();
    delete dropboxAuth;
    if( !ret ) return;

    //Load token
    /*DropboxAuthInfo authInfo;
    // Read auth info file.
    if(!authInfo.readFromFile( workingPath() + "token.info" )){
        QMessageBox::critical( this, tr( "DropBox Error" ), tr( "Error reading DropBox <auth-file> !" ) );
        return;
    }*/
    //ApiListener lsn;
    //DropboxClient c( authInfo.getAccessToken() );
    DropboxClient c( token );
    //QObject::connect(&c, &DropboxClient::downloadProgress, &lsn, &ApiListener::progressDownload);

    //What are the new files?
    QStringList downloadList;
    QDirIterator it( workingPath(), QStringList() << "*.fit", QDir::Files, QDirIterator::Subdirectories);
    QStringList localList;
    while( it.hasNext() ) localList << QFileInfo( it.next() ).fileName();
    foreach( QString fitFile, c.listFolder( "/Apps/WahooFitness/" ) )
    {
        if( !localList.contains( fitFile ) ) downloadList << fitFile;
    }
    //qDebug() << downloadList;
    if( downloadList.isEmpty() )
    {
        QMessageBox::information( this, tr( "DropBox Error" ), tr( "No new file found!" ) );
        return;
    }

    //Create Directory
    if( !QDir( workingPath() + "New/" ).exists() )
        QDir().mkdir( workingPath() + "New/" );

    //Download all files
    foreach( QString fitFile, downloadList )
    {
        QFile out( QString( workingPath() + "New/" + fitFile ) );
        if(!out.open(QFile::WriteOnly|QIODevice::Truncate)){
            QMessageBox::critical( this, tr( "DropBox Error opening file" ), tr( "DropBox Error opening file" ) );
            return;
        }

        try
        {
            files::DownloadArg arg( QString( "/Apps/WahooFitness/" + fitFile ) );
            std::unique_ptr<files::Metadata> res = c.getFiles()->download(arg, &out);
        }
        catch(DropboxException& e)
        {
            QMessageBox::critical( this, tr( "DropBox Exception" ), e.what() );
        }

        out.close();
    }

    scanTours();
}

void MainWindow::on_actionScanTourFolder_triggered()
{
    scanTours();
}

void MainWindow::on_actionNewBike_triggered()
{
    QDir().mkdir( workingPath() + "NewBike/" );

    QTreeWidgetItem *bikeItem = new QTreeWidgetItem(ui->treeWidgetTours);
    bikeItem->setText( 0, "NewBike" );
    bikeItem->setText( 1, workingPath() + "NewBike" );
    bikeItem->setText( 2, "0 km" );

    ui->treeWidgetTours->sortItems( 0, Qt::AscendingOrder );
    for( int i = 0; i < ui->treeWidgetTours->topLevelItemCount(); i++ )
        ui->treeWidgetTours->topLevelItem( i )->sortChildren( 0, Qt::DescendingOrder );
}

//Behavior for treewidget: only paths names ( = bikes ) should be editable
void MainWindow::on_treeWidgetTours_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    Qt::ItemFlags flags = item->flags();
    if( !item->parent() )
    {
        if( column != 0 || item->text( 0 ) == "New" )
        {
            item->setFlags(flags & (~Qt::ItemIsEditable));
        }
        else
        {
            item->setFlags(flags | Qt::ItemIsEditable);
        }
    }
}

//Rename bike and its folder
void MainWindow::onBikeItemEditingFinished(QTreeWidgetItem *item)
{
    if( QDir( item->text( 1 ) ).dirName() == item->text( 0 ) ) return;

    QDir dir = QDir( item->text( 1 ) );
    dir.cdUp();
    QString oldName = dir.absolutePath() + '/' + QDir( item->text( 1 ) ).dirName();
    QString newName = dir.absolutePath() + '/' + item->text( 0 );
    QDir().rename( oldName, newName );

    item->setText( 1, newName );

    for( int i = 0; i < item->childCount(); i++ )
        item->child( i )->setText( 1, item->child( i )->text( 1 ).replace( oldName, newName ) );
}

void MainWindow::on_actionAbout_triggered()
{
    QByteArray byteArray;
    //QString pic = QString("<img width='128' height='112' align='right' src=\"data:image/png;base64,") + byteArray.toBase64() + "\"/>";

    QMessageBox::about( this, APPNAME, QString(
                                         //"<html>%1"
                                         "<body><h3>%1</h3>"
                                         " <p>%1 v%2</p>"
                                         " <p>%3</p>"
                                         " <p>See <a href='%4'>this site</a> for more information.</p>"
                                         " <p>Icon by <a href='https://zez.am/71m'>71M</a>.</p>"
                                         " <p>dropboxQt Copyright (c) 2018 , <a href='%5'>prokarpaty.net</a> under MIT.</p>"
                                         " <p>Qwt under <a href='%6'>Qwt License</a>.</p>"
                                         " <p>QMapControl under <a href='%7'>LGPL 3.0</a>.</p>"
                                         " <p>FitSDKRelease by <a href='%8'>Garmin</a>.</p>"
                                         " </body></html>" )
                                        //.arg( pic ) //1
                                        .arg( APPNAME ) //1
                                        .arg( VERSION ) //2
                                        .arg( "by masc." ) //3
                                        .arg( "https://github.com/masc4ii/WaoStats" ) //4
                                        .arg( "https://github.com/masc4ii/WaoStats/blob/main/dropboxQt/LICENSE" ) //5
                                        .arg( "https://qwt.sourceforge.io/qwtlicense.html" ) //6
                                        .arg( "https://github.com/masc4ii/WaoStats/blob/main/QMapControl/COPYING.LESSER" ) //7
                                        .arg( "https://developer.garmin.com/fit/download/" ) ); //8
}

void MainWindow::on_actionAboutQt_triggered()
{
    QMessageBox::aboutQt( this );
}

void MainWindow::on_treeWidgetTours_itemsDropped(QList<QTreeWidgetItem *> pSource, QTreeWidgetItem *pTarget)
{
    for( int i = 0; i < pSource.count(); i++ )
    {
        QString source = pSource.at(i)->text( 1 );
        QString target = workingPath() + pTarget->text( 0 ) + "/" + QFileInfo( pSource.at(i)->text( 1 ) ).fileName();
        //qDebug() << "Dropped!" << source << "\n" << target;
        QDir().rename( source, target );

        pSource.at(i)->setText( 1, target );
    }
    QTimer::singleShot( 1, this, SLOT( calcBikeTotalDistances() ) );
}

void MainWindow::on_actionSetArchivePath_triggered()
{
    m_workingPath = QFileDialog::getExistingDirectory(this, tr("Choose Working Path"),
                                                            QFileInfo( workingPath() ).absolutePath(),
                                                            QFileDialog::ShowDirsOnly
                                                            | QFileDialog::DontResolveSymlinks);
}

void MainWindow::on_qwtPlot_customContextMenuRequested(const QPoint &pos)
{
    // Handle global position
    QPoint globalPos = ui->qwtPlot->mapToGlobal( pos );

    // Create mark menu
    QMenu myMenu;
    myMenu.addActions( ui->menuPlot->actions() );

    // Show context menu at handling position
    myMenu.exec( globalPos );
}

void MainWindow::on_widgetOsm_customContextMenuRequested(const QPoint &pos)
{
    // Handle global position
    QPoint globalPos = ui->widgetOsm->mapToGlobal( pos );

    // Create mark menu
    QMenu myMenu;
    myMenu.addActions( ui->menu_map->actions() );

    // Show context menu at handling position
    myMenu.exec( globalPos );
}

void MainWindow::on_actionShowPlot_triggered(bool checked)
{
    ui->groupBoxPicker->setVisible( checked );
    ui->qwtPlot->setVisible( checked );
    qApp->processEvents();
    adjustMap();
}

void MainWindow::on_actionMapCaching_triggered(bool checked)
{
    if( checked )
    {
        // Enable caching
        //qDebug() << QCoreApplication::applicationDirPath() + "/QMapCache";
        m_map_control->enablePersistentCache( std::chrono::minutes(0), QDir( QCoreApplication::applicationDirPath() + "/QMapCache" ) );
    }
    else
    {
        // Disable caching
        m_map_control->disablePersistentCache();
    }
}

void MainWindow::on_actionClearMapCache_triggered()
{
    QDir dir( QCoreApplication::applicationDirPath() + "/QMapCache" );
    dir.removeRecursively();
}

//Save some settings to registry
void MainWindow::writeSettings()
{
    QSettings set( QSettings::UserScope, "masc4ii.WaoStats", "WaoStats" );
    set.setValue( "mainWindowGeometry", saveGeometry() );
    //set.setValue( "mainWindowState", saveState() ); // docks, toolbars, etc...
    set.setValue( "mapCaching", ui->actionMapCaching->isChecked() );
    int mapType = 0;
    if( ui->action_google_map->isChecked() ) mapType = 0;
    else if( ui->action_google_satelite->isChecked() ) mapType = 1;
    else if( ui->action_google_hybrid->isChecked() ) mapType = 2;
    else if( ui->action_google_terrain->isChecked() ) mapType = 3;
    else if( ui->action_osm->isChecked() ) mapType = 4;
    else if( ui->action_otm->isChecked() ) mapType = 5;
    else if( ui->action_4um->isChecked() ) mapType = 6;
    else if( ui->action_cycle_osm->isChecked() ) mapType = 7;
    else if( ui->action_thunderforest_cycle->isChecked() ) mapType = 8;
    else if( ui->action_thunderforest_landscape->isChecked() ) mapType = 9;
    else if( ui->action_bing->isChecked() ) mapType = 10;
    set.setValue( "maptype", mapType );
    set.setValue( "lastExportPath", m_workingPath );
}

//Read some settings from registry
void MainWindow::readSettings()
{
    QSettings set( QSettings::UserScope, "masc4ii.WaoStats", "WaoStats" );
    restoreGeometry( set.value( "mainWindowGeometry" ).toByteArray() );
    //restoreState( set.value( "mainWindowState" ).toByteArray() ); // create docks, toolbars, etc...
    if( set.value( "mapCaching", false ).toBool() ) ui->actionMapCaching->setChecked( true );
    on_actionMapCaching_triggered( ui->actionMapCaching->isChecked() );

    switch( set.value( "maptype", 0 ).toInt() )
    {
    case 1: ui->action_google_satelite->setChecked( true );
            mapProviderSelected( ui->action_google_satelite );
            break;
    case 2: ui->action_google_hybrid->setChecked( true );
            mapProviderSelected( ui->action_google_hybrid );
            break;
    case 3: ui->action_google_terrain->setChecked( true );
            mapProviderSelected( ui->action_google_terrain );
            break;
    case 4: ui->action_osm->setChecked( true );
            mapProviderSelected( ui->action_osm );
            break;
    case 5: ui->action_otm->setChecked( true );
            mapProviderSelected( ui->action_otm );
            break;
    case 6: ui->action_4um->setChecked( true );
            mapProviderSelected( ui->action_4um );
            break;
    case 7: ui->action_cycle_osm->setChecked( true );
            mapProviderSelected( ui->action_cycle_osm );
            break;
    case 8: ui->action_thunderforest_cycle->setChecked( true );
            mapProviderSelected( ui->action_thunderforest_cycle );
            break;
    case 9: ui->action_thunderforest_landscape->setChecked( true );
            mapProviderSelected( ui->action_thunderforest_landscape );
            break;
    case 10: ui->action_bing->setChecked( true );
            mapProviderSelected( ui->action_bing );
            break;
    case 0:
    default:
            ui->action_google_map->setChecked( true );
            mapProviderSelected( ui->action_google_map );
            break;
    }

    m_workingPath = set.value( "lastExportPath", QDir::homePath() + "/Documents/FahrradTracking" ).toString();
}

void MainWindow::configureActionGroups( void )
{
    QActionGroup* plotTypeGroup = new QActionGroup(this);
    plotTypeGroup->addAction( ui->actionPlotDistance );
    plotTypeGroup->addAction( ui->actionPlotTime );
    ui->actionPlotDistance->setCheckable( true );
    ui->actionPlotTime->setCheckable( true );
    ui->actionPlotDistance->setChecked( true );
    QObject::connect( plotTypeGroup, &QActionGroup::triggered, this, &MainWindow::plotSelected );

    QActionGroup* plotValueGroup = new QActionGroup(this);
    plotValueGroup->addAction( ui->actionSpeed );
    plotValueGroup->addAction( ui->actionDeviceBattery );
    plotValueGroup->addAction( ui->actionCadence );
    plotValueGroup->addAction( ui->actionTemperature );
    plotValueGroup->addAction( ui->actionGrade );
    plotValueGroup->addAction( ui->actionHeartRate );
    plotValueGroup->addAction( ui->actionCalories );
    plotValueGroup->addAction( ui->actionPower );
    plotValueGroup->addAction( ui->actionLRBalance );
    plotValueGroup->addAction( ui->actionGearInfo );
    ui->actionSpeed->setCheckable( true );
    ui->actionDeviceBattery->setCheckable( true );
    ui->actionCadence->setCheckable( true );
    ui->actionTemperature->setCheckable( true );
    ui->actionGrade->setCheckable( true );
    ui->actionHeartRate->setCheckable( true );
    ui->actionCalories->setCheckable( true );
    ui->actionPower->setCheckable( true );
    ui->actionLRBalance->setCheckable( true );
    ui->actionGearInfo->setCheckable( true );
    ui->actionSpeed->setChecked( true );
    QObject::connect( plotValueGroup, &QActionGroup::triggered, this, &MainWindow::plotSelected );
}

void MainWindow::saveTableToJson()
{
    QJsonObject tours;
    for( int i = 0; i < ui->treeWidgetTours->topLevelItemCount(); i++ )
    {
        QJsonObject parameters;
        for( int j = 0; j < ui->treeWidgetTours->topLevelItem(i)->childCount(); j++ )
        {
            parameters.insert( "name", ui->treeWidgetTours->topLevelItem(i)->child(j)->text(0) );
            parameters.insert( "distanceInt", ui->treeWidgetTours->topLevelItem(i)->child(j)->text(2) );
            parameters.insert( "distanceDouble", ui->treeWidgetTours->topLevelItem(i)->child(j)->text(3) );
            parameters.insert( "bike", ui->treeWidgetTours->topLevelItem(i)->text(0) );
            tours.insert( ui->treeWidgetTours->topLevelItem(i)->child(j)->text(1).remove( workingPath() ), parameters );
        }
    }

    QJsonDocument doc( tours );
    /* write json doc into file */
    QString fileName = QString( "%1%2" ).arg( workingPath() ).arg( "archive.json" );
    QFile file( fileName );
    if( file.open( QIODevice::WriteOnly | QIODevice::Text ) )
    {
        /* Try to write the JSON document */
        file.write( doc.toJson() );
        file.close();
    }
}

bool MainWindow::loadTrackFromJson( QString fitFile, QTreeWidgetItem *fitItem )
{
    /* Read file */
    QString fileName = QString( "%1%2" ).arg( workingPath() ).arg( "archive.json" );
    QFile file( fileName );
    if( !file.open( QIODevice::ReadOnly | QIODevice::Text ) )
    {
        qDebug() << "open coefficients json file failed.";
        return false;
    }
    QJsonDocument doc = QJsonDocument::fromJson( file.readAll() );
    file.close();

    /* JSON is invalid */
    if (doc.isNull()) {
        qDebug() << "archive json file invalid.";
        return false;
    }

    QString archiveFile = fitFile;
    archiveFile.remove( workingPath() );

    if( !doc.object().contains( archiveFile ) ) return false;

    QJsonObject track = doc.object().value( archiveFile ).toObject();
    fitItem->setText( 0, track.value( "name" ).toString() );
    fitItem->setText( 1, fitFile );
    fitItem->setText( 2, track.value( "distanceInt" ).toString() );
    fitItem->setText( 3, track.value( "distanceDouble" ).toString() );

    return true;
}

void MainWindow::markActiveTour(QTreeWidgetItem *item)
{
    for( int i = 0; i < 4; i++ )
    {
        QFont font = item->font( i );
        font.setItalic( false );
        font.setBold( false );
        if( m_currentActiveTreeWidgetItem != nullptr ) m_currentActiveTreeWidgetItem->setFont( i, font );
        font.setItalic( true );
        font.setBold( true );
        item->setFont( i, font );
    }
    m_currentActiveTreeWidgetItem = item;
}

void MainWindow::calcBikeTotalDistances()
{
    for( int i = 0; i < ui->treeWidgetTours->topLevelItemCount(); i++ )
    {
        double totalDistance = 0;
        QTreeWidgetItem *bikeItem = ui->treeWidgetTours->topLevelItem( i );
        QString subdir = bikeItem->text( 1 );
        if( QFileInfo( subdir+"/initKm.txt" ).exists() )
        {
            QFile initFile( subdir+"/initKm.txt" );
            initFile.open( QFile::ReadOnly );
            totalDistance += initFile.readAll().toDouble();
            initFile.close();
        }
        for( int j = 0; j < bikeItem->childCount(); j++ )
        {
            totalDistance += bikeItem->child( j )->text( 3 ).toDouble();
        }
        bikeItem->setText( 2, QString( "%1 km" ).arg( (int)( totalDistance + 0.5 ) ) );
    }

    for( int i = 0; i < ui->treeWidgetTours->topLevelItemCount(); i++ )
        ui->treeWidgetTours->topLevelItem( i )->sortChildren( 0, Qt::DescendingOrder );
}

void MainWindow::on_lineEditFilter_textChanged(const QString &arg1)
{
    ui->treeWidgetTours->setFilter( arg1 );
}
