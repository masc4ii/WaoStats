#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>

// QMapControl includes.
#include <QMapControl/QMapControl.h>
#include <QMapControl/GeometryLineString.h>
#include <QMapControl/GeometryWidget.h>
#include <QMapControl/Layer.h>
#include <QMapControl/LayerGeometry.h>

//fit listener
#ifndef FITC
#include "FitListener.h"
#else
#include "FitParser.h"
#endif
#include "GpxParser.h"
#include "TourData.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

using namespace qmapcontrol;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool initSucess();

private slots:
    void adjustMap( void );
    void statistics( void );
    void bikeStatistics( QTreeWidgetItem *item );
    void pointInfo( double x );
    void pointInfoHide( bool on );
    void mapProviderSelected( QAction* action );
    void plotSelected( void );
    void onBikeItemEditingFinished( QTreeWidgetItem *item );
    void on_actionAbout_triggered();
    void on_actionAboutQt_triggered();
    void on_actionNewBike_triggered();
    void on_actionSetArchivePath_triggered();
    void on_actionScanTourFolder_triggered();
    void on_actionShowPlot_triggered( bool checked );
    void on_actionSyncDropbox_triggered();
    void on_actionMapCaching_triggered( bool checked );
    void on_actionDarkMaps_triggered( bool checked );
    void on_actionClearMapCache_triggered();
    void on_actionService_triggered();
    void on_actionStatistics_triggered();
    void on_actionSyncAdb_triggered();
    void on_actionDistanceSearch_triggered();
    void on_actionAverageMarker_triggered( bool checked );
    void on_treeWidgetTours_itemActivated( QTreeWidgetItem *item, int column );
    void on_treeWidgetTours_itemsDropped( QList<QTreeWidgetItem *> pSource, QTreeWidgetItem* pTarget );
    void on_treeWidgetTours_itemDoubleClicked( QTreeWidgetItem *item, int column );
    void on_treeWidgetTours_customContextMenuRequested(const QPoint &pos);
    void on_widgetOsm_customContextMenuRequested( const QPoint &pos );
    void on_widgetPlot_customContextMenuRequested( const QPoint &pos );
    void on_lineEditFilter_textChanged( const QString &arg1 );
    void calcBikeTotalDistances();
    void showServiceInTree();
    void setupArchive( void );
    void showInFinder();
    void mouseOverPlot(QMouseEvent *event);

private:
    Ui::MainWindow *ui;
    void scanTours( void );
    void scanFit( QString fileName );
    void scanGpx( QString fileName );
    void adjustGui();
    void configureMap( void );
    void drawPlots( void );
    void drawTourToMap( TourData *pTourData, bool autoZoom = true );
    void writeSettings();
    void readSettings();
    void configureActionGroups( void );
    void saveTableToJson( void );
    bool loadTrackFromJson( QString fitFile, QTreeWidgetItem *fitItem );
    void markActiveTour( QTreeWidgetItem *item );
    void drawHrPlot(TourData::fitSection_t section );
    void drawPwrPlot(TourData::fitSection_t section );
    double odoInitKm( int bikeIndex );
    double odoInitKm( QString bikePath );
    QString workingPath( void );

    TourData *m_pTourData;
 #ifndef FITC
    FitListener m_fitListener;
#else
    FitParser m_fitParser;
#endif
    GpxParser m_gpxParser;

    QAction *m_pActionShowInFinder;

    /// The main map control.
    QMapControl* m_map_control;
    /// The layer to display/store tours.
    std::shared_ptr<LayerGeometry> m_layer_tours;
    /// The geometry to represent a sight tour.
    std::shared_ptr<GeometryLineString> m_tour_sights;
    /// The layer to display/store symbols.
    std::shared_ptr<LayerGeometry> m_layer_symb;

    QTreeWidgetItem *m_currentActiveTreeWidgetItem;

    QPixmap m_iconCrossHairs;
    QString m_workingPath;

    QMutex m_threadCntMutex;
    uint32_t m_threadCnt;

    bool m_timePlot;

    bool m_initSuccess{false};
};
#endif // MAINWINDOW_H
