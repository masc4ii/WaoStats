#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "DropBoxAuthDialog.h"
#include "BikeEditingDelegate.h"
#include "Splash.h"
#include "Globals.h"
#include "ServiceDialog.h"
#include "StatisticsDialog.h"
#include "AdbSelectDeviceDialog.h"
#include "AdbWrapper.h"
#include "HelperFunctions.h"
#include "ThreadTrack2Point.h"
#include "ProgressDialog.h"

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
#include <QStyleFactory>
#include <QProcess>
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
#include <QMapControl/MapAdapterMtbMap.h>
#include <QMapControl/MapAdapterThunderCycle.h>
#include <QMapControl/MapAdapterBing.h>
#include <QMapControl/MapAdapterSigma.h>
#include <QMapControl/MapAdapterKomoot.h>

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

    qRegisterMetaType<QVector<int> >("QVector<int>");

    auto editDelegate = new BikeEditingDelegate(this);
    ui->treeWidgetTours->setItemDelegate(editDelegate);
    connect(editDelegate,
            &BikeEditingDelegate::editingFinished,
            [this] (const QModelIndex &index) {
        auto item = ui->treeWidgetTours->getItemFromIndex(index);
        onBikeItemEditingFinished(item); // this is my handler
    });

    //UI setup
#ifndef FITC
    m_pTourData = &m_fitListener;
#else
    m_pTourData = &m_fitParser;
#endif
    m_timePlot = false;
    m_currentActiveTreeWidgetItem = nullptr;
    configureActionGroups();
    ui->qwtPlot->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->widgetOsm->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->dockWidgetBikeData->setVisible( false );
    ui->labelHrZone->setVisible( false );
    ui->labelPwrZone->setVisible( false );
    m_pActionShowInFinder = new QAction( tr( "Show In Finder" ), this );
    connect( m_pActionShowInFinder, SIGNAL(triggered(bool)), this, SLOT(showInFinder()) );
    configurePlots();
    configureMap();
    readSettings();
    if( QDir( m_workingPath ).exists() )
    {
        scanTours();
        connect( ui->comboBoxSection, SIGNAL(currentIndexChanged(int)), this, SLOT(statistics()) );

        QTimer::singleShot( 1, this, SLOT( adjustMap() ) );
        QTimer::singleShot( 1000, this, SLOT( setupArchive() ) );

        ui->lineEditFilter->setToolTip( QString( "Filter your archive (examples):\n"
                                                 "-\">10\": show all tracks longer than 10km\n"
                                                 "-\"<=50\": show all tracks shorter than or equal 50km\n"
                                                 "-\"2023-\": show all 2023 tracks\n"
                                                 "-\"-10-\": show all Octobre tracks\n"
                                                 "-\"2023-10-\": show all Octobre 2023 tracks\n"
                                                 "-\"radius0.5km\": show all tracks passing in 0.5km radius from reference marker (after processing a search)" ) );
        m_initSuccess = true;
    }
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
    ui->treeWidgetTours->setColumnCount( 8 );
    ui->treeWidgetTours->hideColumn( 1 );
    ui->treeWidgetTours->hideColumn( 3 );
    ui->treeWidgetTours->hideColumn( 4 );
    ui->treeWidgetTours->hideColumn( 5 );
    ui->treeWidgetTours->hideColumn( 6 );
    ui->treeWidgetTours->hideColumn( 7 );
    ui->treeWidgetTours->setHeaderLabels( QStringList() << "Tour" << "Path" << "Distance" << "DistanceAsDouble" << "TimeInMotionSec" << "AscentMeters" << "DescentMeters" << "DistanceToCursor" );
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
                fitItem->setToolTip( 0, QFileInfo(subdir+"/"+fitFile).fileName() );
                fitItem->setText( 2, QString( "%1 km" ).arg( (int)( m_pTourData->getSession().totalDistance / 1000.0 + 0.5 ) ) );
                fitItem->setText( 3, QString( "%1" ).arg( m_pTourData->getSession().totalDistance / 1000.0, 0, 'f', 10 ) );
                fitItem->setText( 4, QString( "%1" ).arg( (int)( m_pTourData->getSession().totalTimerTime ) ) );
                fitItem->setText( 5, QString( "%1" ).arg( (int)( m_pTourData->getSession().ascent ) ) );
                fitItem->setText( 6, QString( "%1" ).arg( (int)( m_pTourData->getSession().descent ) ) );
                fitItem->setText( 7, QString( "0" ) );
            }
        }
    }
    ui->treeWidgetTours->collapseAll();
    calcBikeTotalDistances();
    showServiceInTree();
    saveTableToJson();
    m_currentActiveTreeWidgetItem = nullptr;
    ui->treeWidgetTours->setFilter( ui->lineEditFilter->text() );
}

void MainWindow::scanFit(QString fileName)
{
#ifndef FITC
    fit::Decode decode;
    fit::MesgBroadcaster mesgBroadcaster;
    FitListener listener;
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
#else
    m_pTourData = &m_fitParser;
    m_fitParser.loadFit( fileName );
#endif
}

void MainWindow::scanGpx(QString fileName)
{
    m_pTourData = &m_gpxParser;
    m_gpxParser.loadGpx( fileName );
}

void MainWindow::adjustGui()
{
    //Window Title
    if( !m_pTourData->getWorkoutName().isEmpty() && m_pTourData->getWorkoutName() != QString( "Radfahren" ) ) setWindowTitle( QString( "WaoStats - %1" ).arg( m_pTourData->getWorkoutName() ) );
    else setWindowTitle( QString( "WaoStats" ) );

    //Laps
    ui->comboBoxSection->clear();
    ui->comboBoxSection->addItem( tr( "Track / Session" ) );
    if( m_pTourData->getSections().count() <= 1 ) return;
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
    ui->actionDeviceBattery->setEnabled( (int)m_pTourData->getTourBatterySoc().first() > 0 );
    ui->actionGpsAccuracy->setEnabled( !m_pTourData->getTourGpsAccuracy().empty() );

    if( ( ui->actionCadence->isChecked()        && !ui->actionCadence->isEnabled() )
     || ( ui->actionGrade->isChecked()          && !ui->actionGrade->isEnabled() )
     || ( ui->actionHeartRate->isChecked()      && !ui->actionHeartRate->isEnabled() )
     || ( ui->actionCalories->isChecked()       && !ui->actionCalories->isEnabled() )
     || ( ui->actionPower->isChecked()          && !ui->actionPower->isEnabled() )
     || ( ui->actionLRBalance->isChecked()      && !ui->actionLRBalance->isEnabled() )
     || ( ui->actionGearInfo->isChecked()       && !ui->actionGearInfo->isEnabled() )
     || ( ui->actionDeviceBattery->isChecked()  && !ui->actionDeviceBattery->isEnabled() )
     || ( ui->actionGpsAccuracy->isChecked()    && !ui->actionGpsAccuracy->isEnabled() )
     || ( ui->actionTemperature->isChecked()    && !ui->actionTemperature->isEnabled() ) )
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
    ui->labelPickerGear->setVisible( m_pTourData->containsGearInfoFront() || m_pTourData->containsGearInfoRear() );
    ui->labelPickerGearName->setVisible( m_pTourData->containsGearInfoFront() || m_pTourData->containsGearInfoRear() );

    if( ind < 1 )
    {
        QDateTime startQTime( QDate( 1989, 12, 31 ), QTime( 1, 0, 0 ) );
        startQTime = startQTime.addSecs( m_pTourData->getSession().startTime );
        ui->labelDate->setText( startQTime.toString( "yyyy-MM-dd" ) );
        ui->labelStartTime->setText( startQTime.toString( "hh:mm:ss" ) );

        ui->labelDistance->setText( QString( "%1 km" ).arg( m_pTourData->getSession().totalDistance / 1000.0, 0, 'f', 3 ) );

        //qDebug() << m_pTourData->getSession().totalTimerTime << m_pTourData->getSession().totalTimerTime/3600 << m_pTourData->getSession().totalElapsedTime << m_pTourData->getSession().totalElapsedTime/3600;

        ui->labelTimeTotal->setText( QString( "%1:%2" ).arg( (int)(m_pTourData->getSession().totalElapsedTime/3600), 2, 'f', 0, '0' ).arg( QTime(0,0).addSecs( m_pTourData->getSession().totalElapsedTime ).toString( "mm:ss" ) ) );
        ui->labelTimeMotion->setText( QString( "%1:%2" ).arg( (int)(m_pTourData->getSession().totalTimerTime/3600), 2, 'f', 0, '0' ).arg( QTime(0,0).addSecs( m_pTourData->getSession().totalTimerTime ).toString( "mm:ss" ) ) );

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

        drawHrPlot( m_pTourData->getSession() );
        drawPwrPlot( m_pTourData->getSession() );
    }
    else
    {
        ind--;

        QDateTime startQTime( QDate( 1989, 12, 31 ), QTime( 1, 0, 0 ) );
        startQTime = startQTime.addSecs( m_pTourData->getSections().at(ind).startTime );
        ui->labelDate->setText( startQTime.toString( "yyyy-MM-dd" ) );
        ui->labelStartTime->setText( startQTime.toString( "hh:mm:ss" ) );

        ui->labelDistance->setText( QString( "%1 km" ).arg( m_pTourData->getSections().at(ind).totalDistance / 1000.0, 0, 'f', 3 ) );

        ui->labelTimeTotal->setText( QString( "%1:%2" ).arg( (int)(m_pTourData->getSections().at(ind).totalElapsedTime/3600), 2, 'f', 0, '0' ).arg( QTime(0,0).addSecs( m_pTourData->getSections().at(ind).totalElapsedTime ).toString( "mm:ss" ) ) );
        ui->labelTimeMotion->setText( QString( "%1:%2" ).arg( (int)(m_pTourData->getSections().at(ind).totalTimerTime/3600), 2, 'f', 0, '0' ).arg( QTime(0,0).addSecs( m_pTourData->getSections().at(ind).totalTimerTime ).toString( "mm:ss" ) ) );

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

        drawHrPlot( m_pTourData->getSections().at(ind) );
        drawPwrPlot( m_pTourData->getSections().at(ind) );
    }
}

void MainWindow::bikeStatistics(QTreeWidgetItem *item)
{
    if( item->parent() ) return;

    double initKm = odoInitKm( item->text(1) );

    ui->labelDistanceBike->setText( QString( "%1 km" ).arg( item->text( 3 ).toDouble()-initKm, 0, 'f', 1 ) );
    ui->labelTimeMotionBike->setText( QString( "%1:%2" ).arg( (int)(item->text( 4 ).toDouble()/3600), 2, 'f', 0, '0' ).arg( QTime(0,0).addSecs( item->text( 4 ).toDouble() ).toString( "mm:ss" ) ) );
    ui->labelAscentBike->setText( QString( "%1 km" ).arg( item->text( 5 ).toDouble()/1000, 0, 'f', 3 ) );
    ui->labelDescentBike->setText( QString( "%1 km" ).arg( item->text( 6 ).toDouble()/1000, 0, 'f', 3 ) );
    if( item->text( 4 ).toDouble() > 1 ) ui->labelSpeedAverageBike->setText( QString( "%1 km/h" ).arg( (item->text( 3 ).toDouble()-initKm)/item->text( 4 ).toDouble()*3600, 0, 'f', 1 ) );
    else ui->labelSpeedAverageBike->setText( "-" );
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
    map_provider_group->addAction( ui->action_mtbmap );
    map_provider_group->addAction( ui->action_sigmasport_maps );
    map_provider_group->addAction( ui->action_sigmasport_topo );
    map_provider_group->addAction( ui->action_sigmasport_cycle );
    map_provider_group->addAction( ui->action_komoot );
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
    ui->action_mtbmap->setCheckable( true );
    ui->action_sigmasport_maps->setCheckable( true );
    ui->action_sigmasport_topo->setCheckable( true );
    ui->action_sigmasport_cycle->setCheckable( true );
    ui->action_komoot->setCheckable( true );
    ui->action_komoot->setVisible( false );
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
    delete m_avgMarker;
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
    canvas->setBorderRadius( 5 );
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
    else if( ui->actionGpsAccuracy->isChecked() )
    {
        m_curve[1] = new QwtPlotCurve( QString( "GPS Accuracy" ) );
        ui->qwtPlot->setAxisTitle( QwtPlot::yRight, QwtText( "GPS Accuracy [m]" ) );
    }
    m_curve[1]->setYAxis( QwtPlot::yRight );
    m_curve[1]->setRenderHint( QwtPlotItem::RenderAntialiased );
    ui->qwtPlot->setAxisVisible( QwtPlot::yRight );

    QPen p( Qt::red );
    m_curve[0]->setPen( p );
    m_curve[0]->setBrush( QBrush( QColor( 255, 0, 0, 25 ) ) );
    p.setColor( QColor( 0, 180, 0 ) );
    m_curve[1]->setPen( p );

    //AVG Marker
    m_avgMarker = new QwtPlotMarker();
    m_avgMarker->setValue( 0.0, m_pTourData->getSession().avgSpeed * 3.6 );
    m_avgMarker->setYAxis( QwtPlot::yRight );
    m_avgMarker->setLineStyle( QwtPlotMarker::HLine );
    m_avgMarker->setLabelAlignment( Qt::AlignRight | Qt::AlignBottom );
    m_avgMarker->setLinePen( Qt::darkGray, 1, Qt::DashDotLine );
    m_avgMarker->setVisible( ui->actionAverageMarker->isChecked() );

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

        m_avgMarker->setValue( 0.0, m_pTourData->getSession().avgSpeed * 3.6 );
        m_avgMarker->attach( ui->qwtPlot );
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

        m_avgMarker->setValue( 0.0, m_pTourData->getSession().avgCadence );
        m_avgMarker->attach( ui->qwtPlot );
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

        m_avgMarker->setValue( 0.0, m_pTourData->getSession().avgHeartRate );
        m_avgMarker->attach( ui->qwtPlot );
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
    else if( ui->actionGpsAccuracy->isChecked() )
    {
        if( !m_timePlot ) m_curve[1]->setSamples( pTourData->getTourDistance().data(), pTourData->getTourGpsAccuracy().data(), pTourData->getTourDistance().count() );
        else              m_curve[1]->setSamples( pTourData->getTourTimeStamp().data(), pTourData->getTourGpsAccuracy().data(), pTourData->getTourDistance().count() );
        m_curve[1]->setTitle( QString( "GPS Accuracy" ) );
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
    Q_UNUSED( column );

    markActiveTour( item );

    if( !item->parent() )
    {
        ui->dockWidgetStats->setVisible( false );
        ui->dockWidgetBikeData->setVisible( true );
        bikeStatistics( item );
    }
    else
    {
        ui->dockWidgetStats->setVisible( true );
        ui->dockWidgetBikeData->setVisible( false );
        QString fileName = item->text( 1 );
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
    // Set the map to MtbMap.
    else if(action == ui->action_mtbmap)
    {
        map_layer->setMapAdapter(std::make_shared<MapAdapterMtbMap>());
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
    // Set the map to Sigma Sport Flat.
    else if(action == ui->action_sigmasport_maps)
    {
        map_layer->setMapAdapter(std::make_shared<MapAdapterSigma>(qmapcontrol::MapAdapterSigma::MapAdapterSigmaType::MAPS));
    }
    // Set the map to Sigma Sport Topo.
    else if(action == ui->action_sigmasport_topo)
    {
        map_layer->setMapAdapter(std::make_shared<MapAdapterSigma>(qmapcontrol::MapAdapterSigma::MapAdapterSigmaType::TOPO));
    }
    // Set the map to Sigma Sport Cycle.
    else if(action == ui->action_sigmasport_cycle)
    {
        map_layer->setMapAdapter(std::make_shared<MapAdapterSigma>(qmapcontrol::MapAdapterSigma::MapAdapterSigmaType::CYCLE));
    }
    // Set the map to Komoot.
    else if(action == ui->action_komoot)
    {
        map_layer->setMapAdapter(std::make_shared<MapAdapterKomoot>());
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

        for( int i = 0; i < m_pTourData->getGearDistance().size(); i++ )
        {
            if( m_pTourData->getGearDistance().at(i) >= distance )
            {
                ui->labelPickerGear->setText( QString( "%1;%2;%3" ).arg( (int)m_pTourData->getGearNumFront().at( i ) )
                                                 .arg( (int)m_pTourData->getGearNumRear().at( i ) )
                                                 .arg( m_pTourData->getGearRatio().at( i ), 0, 'f', 2 ) );
                break;
            }
        }
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

        for( int i = 0; i < m_pTourData->getGearTimeStamp().size(); i++ )
        {
            if( m_pTourData->getGearTimeStamp().at(i) >= time )
            {
                ui->labelPickerGear->setText( QString( "%1;%2;%3" ).arg( (int)m_pTourData->getGearNumFront().at( i ) )
                                                 .arg( (int)m_pTourData->getGearNumRear().at( i ) )
                                                 .arg( m_pTourData->getGearRatio().at( i ), 0, 'f', 2 ) );
                break;
            }
        }
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
                ui->labelPickerGear->setText( QString( "%1;%2;%3" ).arg( (int)m_pTourData->getGearNumFront().at( i ) )
                                                                   .arg( (int)m_pTourData->getGearNumRear().at( i ) )
                                                                   .arg( m_pTourData->getGearRatio().at( i ) ) );

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
    ui->labelPickerGear->setText( QString( "Fr;Re;Rat" ) );
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

void MainWindow::on_treeWidgetTours_customContextMenuRequested(const QPoint &pos)
{
    //Reveal in Explorer
#ifdef Q_OS_WIN
    m_pActionShowInFinder->setText( tr( "Reveal in Explorer" ) );
    m_pActionShowInFinder->setToolTip( tr( "Reveal selected file in Explorer" ) );
#endif
#ifdef Q_OS_LINUX
    m_pActionShowInFinder->setText( tr( "Reveal in Nautilus" ) );
    m_pActionShowInFinder->setToolTip( tr( "Reveal selected file in Nautilus" ) );
#endif

    QTreeWidgetItem* item = ui->treeWidgetTours->itemAt( pos );
    if( item )
    {
        // Handle global position
        QPoint globalPos = ui->treeWidgetTours->mapToGlobal( pos );

        // Create menu and insert some actions
        QMenu myMenu;
        myMenu.addAction( m_pActionShowInFinder );

        // Show context menu at handling position
        myMenu.exec( globalPos );
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
    //QByteArray byteArray;
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
    QTimer::singleShot( 2, this, SLOT( showServiceInTree() ) );
}

void MainWindow::on_actionSetArchivePath_triggered()
{
    QString path = QFileDialog::getExistingDirectory(this, tr("Choose Working Path"),
                                                            QFileInfo( workingPath() ).absolutePath(),
                                                            QFileDialog::ShowDirsOnly
                                                            | QFileDialog::DontResolveSymlinks);
    if( path.size() )
    {
        m_workingPath = path;
        if( !QDir( path + "/Planned" ).exists() ) QDir( path ).mkdir( "Planned" );
        scanTours();
    }
}

void MainWindow::on_qwtPlot_customContextMenuRequested(const QPoint &pos)
{
    m_layer_symb->setVisible( false );

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
    pointInfoHide( false );
}

void MainWindow::on_actionMapCaching_triggered(bool checked)
{
    if( checked )
    {
        // Enable caching
#ifdef Q_OS_LINUX
        //qDebug() << QDir::homePath() + "/.cache/WaoStats/QMapCache";
        m_map_control->enablePersistentCache( std::chrono::minutes(0), QDir( QDir::homePath() + "/.cache/WaoStats/QMapCache" ) );
#else
        //qDebug() << QCoreApplication::applicationDirPath() + "/QMapCache";
        m_map_control->enablePersistentCache( std::chrono::minutes(0), QDir( QCoreApplication::applicationDirPath() + "/QMapCache" ) );
#endif
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
    QSettings set( QSettings::UserScope, "masc.WaoStats", "WaoStats" );
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
    else if( ui->action_mtbmap->isChecked() ) mapType = 11;
    else if( ui->action_sigmasport_maps->isChecked() ) mapType = 12;
    else if( ui->action_sigmasport_topo->isChecked() ) mapType = 13;
    else if( ui->action_sigmasport_cycle->isChecked() ) mapType = 14;
    else if( ui->action_komoot->isChecked() ) mapType = 15;
    set.setValue( "maptype", mapType );
    set.setValue( "workingPath", m_workingPath );
}

//Read some settings from registry
void MainWindow::readSettings()
{
    QSettings set( QSettings::UserScope, "masc.WaoStats", "WaoStats" );
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
    case 11: ui->action_mtbmap->setChecked( true );
            mapProviderSelected( ui->action_mtbmap );
            break;
    case 12: ui->action_sigmasport_maps->setChecked( true );
            mapProviderSelected( ui->action_sigmasport_maps );
            break;
    case 13: ui->action_sigmasport_topo->setChecked( true );
            mapProviderSelected( ui->action_sigmasport_topo );
            break;
    case 14: ui->action_sigmasport_cycle->setChecked( true );
            mapProviderSelected( ui->action_sigmasport_cycle );
            break;
    case 15: ui->action_komoot->setChecked( true );
            mapProviderSelected( ui->action_komoot );
            break;
    case 0:
    default:
            ui->action_google_map->setChecked( true );
            mapProviderSelected( ui->action_google_map );
            break;
    }

    m_workingPath = set.value( "workingPath", QDir::homePath() + "/Documents/BikeTracking" ).toString();
    setupArchive();
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
    plotValueGroup->addAction( ui->actionGpsAccuracy );
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
    ui->actionGpsAccuracy->setCheckable( true );
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
            parameters.insert( "timeInMotionSec", ui->treeWidgetTours->topLevelItem(i)->child(j)->text(4) );
            parameters.insert( "ascentMeters", ui->treeWidgetTours->topLevelItem(i)->child(j)->text(5) );
            parameters.insert( "descentMeters", ui->treeWidgetTours->topLevelItem(i)->child(j)->text(6) );
            parameters.insert( "bike", ui->treeWidgetTours->topLevelItem(i)->text(0) );
            tours.insert( ui->treeWidgetTours->topLevelItem(i)->child(j)->text(1).remove( workingPath() ), parameters );
        }
    }

    QJsonDocument doc( tours );
    //write json doc into file
    QString fileName = QString( "%1%2" ).arg( workingPath() ).arg( "archive.json" );
    QFile file( fileName );
    if( file.open( QIODevice::WriteOnly | QIODevice::Text ) )
    {
        //Try to write the JSON document
        file.write( doc.toJson() );
        file.close();
    }
}

bool MainWindow::loadTrackFromJson( QString fitFile, QTreeWidgetItem *fitItem )
{
    //Read file
    QString fileName = QString( "%1%2" ).arg( workingPath() ).arg( "archive.json" );
    QFile file( fileName );
    if( !file.open( QIODevice::ReadOnly | QIODevice::Text ) )
    {
        //qDebug() << "open archive.json file failed.";
        return false;
    }
    QJsonDocument doc = QJsonDocument::fromJson( file.readAll() );
    file.close();

    //JSON is invalid
    if( doc.isNull() )
    {
        qDebug() << "archive.json file invalid.";
        return false;
    }

    QString archiveFile = fitFile;
    archiveFile.remove( workingPath() );

    if( !doc.object().contains( archiveFile ) ) return false;

    QJsonObject track = doc.object().value( archiveFile ).toObject();
    fitItem->setText( 0, track.value( "name" ).toString() );
    fitItem->setToolTip( 0, QFileInfo(fitFile).fileName() );
    fitItem->setText( 1, fitFile );
    fitItem->setText( 2, track.value( "distanceInt" ).toString() );
    fitItem->setText( 3, track.value( "distanceDouble" ).toString() );
    fitItem->setText( 4, track.value( "timeInMotionSec" ).toString() );
    fitItem->setText( 5, track.value( "ascentMeters" ).toString() );
    fitItem->setText( 6, track.value( "descentMeters" ).toString() );

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

void MainWindow::drawHrPlot(TourData::fitSection_t section)
{
    if( !m_pTourData->getHrZoneHigh()[0]
     || !m_pTourData->getHrZoneHigh()[1]
     || !m_pTourData->getHrZoneHigh()[2]
     || !m_pTourData->getHrZoneHigh()[3]
     || !section.hrTimeInZone[0] )
    {
        ui->labelHrZone->setVisible( false );
        return;
    }
    else ui->labelHrZone->setVisible( true );

    int b = 8 * devicePixelRatio(); //boarder
    int h = ( ui->labelHrZone->height() * devicePixelRatio() ) - 1;
    int w = 164 * devicePixelRatio();//ui->labelHrZone->width();
    int w5 = ( w - b ) / 5;
    int max = 0;
    QPixmap pix( w, h );
    QPainter paint( &pix );
    pix.fill( ui->groupBoxCadence->palette().window().color() );
    QVector<QBrush> brushes = { QBrush( "dodgerblue" ), QBrush( "limegreen" ), QBrush( "gold" ), QBrush( "darkorange" ), QBrush( "orangered" ) };
    for( int i = 0; i < 5; i++ )
    {
        if( section.hrTimeInZone[i] > max ) max = section.hrTimeInZone[i];
    }
    for( int i = 0; i < 5; i++ )
    {
        paint.fillRect( QRect( ( w5 * i ) + b, h - b, w5 - b, (int)( -( h - b - b ) * ( section.hrTimeInZone[i] / max ) ) - 1 ), brushes[i] );
    }
    pix.setDevicePixelRatio( devicePixelRatio() );
    ui->labelHrZone->setPixmap( pix );
    QString toolTip = QString( "0..%1: %2\%, %3\n%4..%5: %6\%, %7\n%8..%9: %10\%, %11\n%12..%13: %14\%, %15\n%16..∞: %17\%, %18" )
                        .arg( m_pTourData->getHrZoneHigh()[0] ).arg( (int)( section.hrTimeInZone[0] / section.totalTimerTime * 100 + 0.5 ) ).arg( QTime(0,0).addSecs( section.hrTimeInZone[0] ).toString( "hh:mm:ss" ) )
                        .arg( m_pTourData->getHrZoneHigh()[0] + 1 ).arg( m_pTourData->getHrZoneHigh()[1] ).arg( (int)( section.hrTimeInZone[1] / section.totalTimerTime * 100 + 0.5 ) ).arg( QTime(0,0).addSecs( section.hrTimeInZone[1] ).toString( "hh:mm:ss" ) )
                        .arg( m_pTourData->getHrZoneHigh()[1] + 1 ).arg( m_pTourData->getHrZoneHigh()[2] ).arg( (int)( section.hrTimeInZone[2] / section.totalTimerTime * 100 + 0.5 ) ).arg( QTime(0,0).addSecs( section.hrTimeInZone[2] ).toString( "hh:mm:ss" ) )
                        .arg( m_pTourData->getHrZoneHigh()[2] + 1 ).arg( m_pTourData->getHrZoneHigh()[3] ).arg( (int)( section.hrTimeInZone[3] / section.totalTimerTime * 100 + 0.5 ) ).arg( QTime(0,0).addSecs( section.hrTimeInZone[3] ).toString( "hh:mm:ss" ) )
                        .arg( m_pTourData->getHrZoneHigh()[3] + 1 ).arg( (int)( section.hrTimeInZone[4] / section.totalTimerTime * 100 + 0.5 ) ).arg( QTime(0,0).addSecs( section.hrTimeInZone[4] ).toString( "hh:mm:ss" ) );
    ui->labelHrZone->setToolTip( toolTip );
}

void MainWindow::drawPwrPlot(TourData::fitSection_t section)
{
    if( !m_pTourData->getPwrZoneHigh()[0]
     || !m_pTourData->getPwrZoneHigh()[1]
     || !m_pTourData->getPwrZoneHigh()[2]
     || !m_pTourData->getPwrZoneHigh()[3]
     || !m_pTourData->getPwrZoneHigh()[4]
     || !section.pwrTimeInZone[0] )
    {
        ui->labelPwrZone->setVisible( false );
        return;
    }
    else ui->labelPwrZone->setVisible( true );

    int cnt = 1;
    for( int i = 0; i < 8; i++ ) if( m_pTourData->getPwrZoneHigh()[i] > 20000 ) cnt = i + 1;

    int b = 8 * devicePixelRatio(); //boarder
    int h = ( ui->labelPwrZone->height() * devicePixelRatio() ) - 1;
    int w = 164 * devicePixelRatio();//ui->labelPwrZone->width();
    int wCnt = ( w - b ) / cnt;
    int max = 0;
    QPixmap pix( w, h );
    QPainter paint( &pix );
    pix.fill( ui->groupBoxPower->palette().window().color() );
    QVector<QBrush> brushes = { QBrush( "white" ), QBrush( "darkblue" ), QBrush( "dodgerblue" ), QBrush( "limegreen" ), QBrush( "gold" ), QBrush( "darkorange" ), QBrush( "orangered" ), QBrush( "pink" ) };
    for( int i = 0; i < cnt; i++ )
    {
        if( section.pwrTimeInZone[i] > max ) max = section.pwrTimeInZone[i];
    }
    for( int i = 0; i < cnt; i++ )
    {
        paint.fillRect( QRect( ( wCnt * i ) + b, h - b, wCnt - b, (int)( -( h - b - b ) * ( section.pwrTimeInZone[i] / max ) ) - 1 ), brushes[i] );
    }
    pix.setDevicePixelRatio( devicePixelRatio() );
    ui->labelPwrZone->setPixmap( pix );

    QString toolTip = QString( "0..%1: %2\%, %3" ).arg( m_pTourData->getPwrZoneHigh()[0] ).arg( (int)( section.pwrTimeInZone[0] / section.totalTimerTime * 100 + 0.5 ) ).arg( QTime(0,0).addSecs( section.pwrTimeInZone[0] ).toString( "hh:mm:ss" ) );
    for( int i = 1; i < cnt-1; i++ ) toolTip.append( QString( "\n%1..%2: %3\%, %4" ).arg( m_pTourData->getPwrZoneHigh()[i-1] + 1 ).arg( m_pTourData->getPwrZoneHigh()[i] ).arg( (int)( section.pwrTimeInZone[i] / section.totalTimerTime * 100 + 0.5 ) ).arg( QTime(0,0).addSecs( section.pwrTimeInZone[i] ).toString( "hh:mm:ss" ) ) );
    toolTip.append( QString( "\n%1..∞: %2\%, %3" ).arg( m_pTourData->getPwrZoneHigh()[cnt-2] + 1 ).arg( (int)( section.pwrTimeInZone[cnt-1] / section.totalTimerTime * 100 + 0.5 ) ).arg( QTime(0,0).addSecs( section.pwrTimeInZone[cnt-1] ).toString( "hh:mm:ss" ) ) );

    ui->labelPwrZone->setToolTip( toolTip );
}

double MainWindow::odoInitKm(int bikeIndex)
{
    double odo = 0.0;
    QTreeWidgetItem *bikeItem = ui->treeWidgetTours->topLevelItem( bikeIndex );
    QString subdir = bikeItem->text( 1 );
    if( QFileInfo( subdir+"/initKm.txt" ).exists() )
    {
        QFile initFile( subdir+"/initKm.txt" );
        initFile.open( QFile::ReadOnly );
        odo = initFile.readAll().toDouble();
        initFile.close();
    }
    return odo;
}

double MainWindow::odoInitKm(QString bikePath)
{
    double odo = 0.0;
    if( QFileInfo( bikePath+"/initKm.txt" ).exists() )
    {
        QFile initFile( bikePath+"/initKm.txt" );
        initFile.open( QFile::ReadOnly );
        odo = initFile.readAll().toDouble();
        initFile.close();
    }
    return odo;
}

void MainWindow::calcBikeTotalDistances()
{
    for( int i = 0; i < ui->treeWidgetTours->topLevelItemCount(); i++ )
    {
        QTreeWidgetItem *bikeItem = ui->treeWidgetTours->topLevelItem( i );
        double totalDistance = odoInitKm( i );
        double totalDistanceWithTime = 0;
        unsigned int totalTimeSec = 0;
        unsigned int totalAscent = 0;
        unsigned int totalDescent = 0;
        for( int j = 0; j < bikeItem->childCount(); j++ )
        {
            totalDistance += bikeItem->child( j )->text( 3 ).toDouble();
            totalDistanceWithTime += bikeItem->child( j )->text( 3 ).toDouble();
            totalTimeSec += bikeItem->child( j )->text( 4 ).toDouble();
            totalAscent += bikeItem->child( j )->text( 5 ).toDouble();
            totalDescent += bikeItem->child( j )->text( 6 ).toDouble();
        }
        bikeItem->setText( 3, QString( "%1" ).arg( totalDistance, 0, 'f', 10 ) );
        bikeItem->setText( 4, QString( "%1" ).arg( totalTimeSec ) );
        bikeItem->setText( 5, QString( "%1" ).arg( totalAscent ) );
        bikeItem->setText( 6, QString( "%1" ).arg( totalDescent ) );
        bikeItem->setText( 2, QString( "%1 km" ).arg( (int)( totalDistance + 0.5 ) ) );
    }

    for( int i = 0; i < ui->treeWidgetTours->topLevelItemCount(); i++ )
        ui->treeWidgetTours->topLevelItem( i )->sortChildren( 0, Qt::DescendingOrder );
}

void MainWindow::showServiceInTree()
{
    ServiceDialog *service = new ServiceDialog( this, ui->treeWidgetTours );
    int bike = 0;
    for( int i = 0; i < ui->treeWidgetTours->topLevelItemCount(); i++ )
    {
        //if( "New" == ui->treeWidgetTours->topLevelItem( i )->text( 0 ) ) continue;
        if( service->bikeNeedsService( bike ) )
        {
            ui->treeWidgetTours->topLevelItem( i )->setBackground( 0, QColor( 255, 0, 0, 96 ) );
            ui->treeWidgetTours->topLevelItem( i )->setBackground( 2, QColor( 255, 0, 0, 96 ) );
            ui->treeWidgetTours->topLevelItem( i )->setToolTip( 0, tr( "Check Service List!" ) );
            ui->treeWidgetTours->topLevelItem( i )->setToolTip( 2, tr( "Check Service List!" ) );
        }
        else
        {
            ui->treeWidgetTours->topLevelItem( i )->setBackground( 0, QColor( 255, 0, 0, 0 ) );
            ui->treeWidgetTours->topLevelItem( i )->setBackground( 2, QColor( 255, 0, 0, 0 ) );
            ui->treeWidgetTours->topLevelItem( i )->setToolTip( 0, tr( "" ) );
            ui->treeWidgetTours->topLevelItem( i )->setToolTip( 2, tr( "" ) );
        }
        bike++;
    }
    delete service;
}

void MainWindow::setupArchive( void )
{
    while( !QDir( m_workingPath ).exists() )
    {
        if( QMessageBox::Ok == QMessageBox::information( this,
                                                         APPNAME,
                                                         tr( "Please setup archive path!" ),
                                                         QMessageBox::Ok | QMessageBox::Abort,
                                                         QMessageBox::Ok ) )
        {
            on_actionSetArchivePath_triggered();
        }
        else
        {
            qApp->quit();
            return;
        }
    }
}

void MainWindow::on_lineEditFilter_textChanged(const QString &arg1)
{
    ui->treeWidgetTours->setFilter( arg1 );
}

void MainWindow::on_actionService_triggered()
{
    ServiceDialog *service = new ServiceDialog( this, ui->treeWidgetTours );
    service->exec();
    delete service;
    showServiceInTree();
}

void MainWindow::on_actionStatistics_triggered()
{
    StatisticsDialog *statisticsDialog = new StatisticsDialog( this, ui->treeWidgetTours, (bool)ui->lineEditFilter->text().count() );
    statisticsDialog->exec();
    delete statisticsDialog;
}

void MainWindow::on_actionSyncAdb_triggered()
{
    //Dialog for ADB device selection
    AdbSelectDeviceDialog *adbSelect = new AdbSelectDeviceDialog( this );
    if( QDialog::Rejected == adbSelect->exec() )
    {
        delete adbSelect;
        return;
    }
    QString deviceId = adbSelect->selectedDeviceId();
    delete adbSelect;

    //Get all names of files from Wahoo device
    AdbWrapper *adbWrap = new AdbWrapper( this );
    QStringList trackList = adbWrap->trackList( deviceId );
    delete adbWrap;

    if( trackList.empty() )
    {
        QMessageBox::critical( this, tr( "ADB Sync error" ), tr( "No tracks found on device!" ) );
        return;
    }
    //qDebug() << trackList.size() << trackList;

    //What are the new files?
    QStringList downloadList;
    QDirIterator it( workingPath(), QStringList() << "*.fit", QDir::Files, QDirIterator::Subdirectories);
    QStringList localList;
    while( it.hasNext() ) localList << QFileInfo( it.next() ).fileName();
    foreach( QString fitFile, trackList )
    {
        if( !localList.contains( fitFile ) ) downloadList << fitFile;
    }
    //qDebug() << downloadList;
    if( downloadList.isEmpty() )
    {
        QMessageBox::information( this, tr( "ADB Sync Error" ), tr( "No new track found!" ) );
        return;
    }

    //Create Directory
    if( !QDir( workingPath() + "New/" ).exists() )
        QDir().mkdir( workingPath() + "New/" );

    //Download all files
    adbWrap = new AdbWrapper( this );
    foreach( QString fitFile, downloadList )
    {
        if( !adbWrap->downloadTrack( deviceId, fitFile, workingPath() + "New/" ) )
        {
            QMessageBox::critical( this, tr( "ADB Sync error" ), tr( "ADB copy failed!" ) );
        }
    }
    delete adbWrap;

    scanTours();
}

void MainWindow::on_actionDistanceSearch_triggered()
{
    QThreadPool::globalInstance()->clear();
    m_threadCnt = 0;

    //Count jobs
    for( int i = 0; i < ui->treeWidgetTours->topLevelItemCount(); i++ )
    {
        QTreeWidgetItem *topLevel = ui->treeWidgetTours->topLevelItem( i );
        for( int j = 0; j < topLevel->childCount(); j++ )
        {
            m_threadCnt++;
        }
    }
    int jobs = m_threadCnt;
    //qDebug() << "Threads todo:" << m_threadCnt;
#ifdef FITC
    //QThreadPool::globalInstance()->setMaxThreadCount(1); //Otherwise some results get lost, or change FIT_CONVERT_MULTI_THREAD in fit_config.h
#endif
    //Start threads
    for( int i = 0; i < ui->treeWidgetTours->topLevelItemCount(); i++ )
    {
        QTreeWidgetItem *topLevel = ui->treeWidgetTours->topLevelItem( i );
        for( int j = 0; j < topLevel->childCount(); j++ )
        {
            ThreadTrack2Point *thread = new ThreadTrack2Point( m_map_control->mapFocusPointCoord().latitude(),
                                                               m_map_control->mapFocusPointCoord().longitude(),
                                                               &m_threadCntMutex,
                                                               &m_threadCnt,
                                                               topLevel->child( j ) );
            // QThreadPool takes ownership and deletes 'thread' automatically
            QThreadPool::globalInstance()->start(thread);
        }
    }
    //Wait for threads done
    ProgressDialog *prD = new ProgressDialog( this, jobs, &m_threadCntMutex, &m_threadCnt );
    if( prD->exec() == QDialog::Rejected )
    {
        //Aborted -> clean partial result
        QThreadPool::globalInstance()->clear();
        for( int i = 0; i < ui->treeWidgetTours->topLevelItemCount(); i++ )
        {
            QTreeWidgetItem *topLevel = ui->treeWidgetTours->topLevelItem( i );
            for( int j = 0; j < topLevel->childCount(); j++ )
            {
                topLevel->child( j )->setText( 7, QString( "" ) );
            }
        }
        return;
    }

    if( "radius1.0km" == ui->lineEditFilter->text() ) ui->treeWidgetTours->setFilter( ui->lineEditFilter->text() );
    else ui->lineEditFilter->setText( "radius1.0km" );
}

void MainWindow::on_actionAverageMarker_triggered(bool checked)
{
    m_avgMarker->setVisible( checked );
    ui->qwtPlot->replot();
}

void MainWindow::showInFinder()
{
    QString path = ui->treeWidgetTours->currentItem()->text( 1 );
#ifdef _WIN32    //Code for Windows
    QProcess::startDetached("explorer.exe", {"/select,", QDir::toNativeSeparators(path)});
#elif defined(__APPLE__)    //Code for Mac
    QProcess::execute("/usr/bin/osascript", {"-e", "tell application \"Finder\" to reveal POSIX file \"" + path + "\""});
    QProcess::execute("/usr/bin/osascript", {"-e", "tell application \"Finder\" to activate"});
#elif defined( Q_OS_LINUX )
    QProcess::startDetached(QString( "/usr/bin/nautilus \"%1\"" ).arg( QDir::toNativeSeparators(path) ) );
#endif
}

bool MainWindow::initSucess()
{
    return m_initSuccess;
}

