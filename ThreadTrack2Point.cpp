#include "ThreadTrack2Point.h"
#ifndef FITC
#include "FitListener.h"
#else
#include "FitParser.h"
#endif
#include "GpxParser.h"
#include "TourData.h"
#include "HelperFunctions.h"
#include <QFileInfo>
#include <QDebug>

ThreadTrack2Point::ThreadTrack2Point(double latitude, double longitude, QMutex *mutex, uint32_t *cnt, QTreeWidgetItem *item)
    : m_pItem( item ),
      m_pMutex( mutex ),
      m_pCnt( cnt ),
      m_latitude( latitude ),
      m_longitude( longitude )
{

}

void ThreadTrack2Point::run()
{
    TourData *pTourData;
#ifndef FITC
    FitListener fitListener;
#else
    FitParser fitParser;
#endif
    GpxParser gpxParser;

    if( m_pMutex == nullptr || m_pCnt == nullptr ) return;
    if( m_pItem == nullptr )
    {
        decrementThreadCnt();
        return;
    }
    QString fileName = m_pItem->text( 1 );
    if( !QFileInfo( fileName ).exists() ) return;

    if( fileName.endsWith( ".fit", Qt::CaseInsensitive ) )
    {
        //scanFit
 #ifndef FITC
        fit::Decode decode;
        fit::MesgBroadcaster mesgBroadcaster;
        //FitListener listener;
        std::fstream file;

        file.open( fileName.toStdString().data(), std::ios::in | std::ios::binary);

        pTourData = &fitListener;

        fitListener.reset();
        mesgBroadcaster.AddListener((fit::FileIdMesgListener &)fitListener);
        mesgBroadcaster.AddListener((fit::MesgListener &)fitListener);

        try
        {
            decode.Read(&file, &mesgBroadcaster, &mesgBroadcaster, &fitListener);
        }
        catch (const fit::RuntimeException& e)
        {
            printf("Exception decoding file: %s\n", e.what());
        }
        file.close();
#else
        pTourData = &fitParser;
        fitParser.loadFit( fileName );
#endif
    }
    else
    {
        //scanGpx
        pTourData = &gpxParser;
        gpxParser.loadGpx( fileName );
    }

    HelperFunctions hF;
    double minDist = 99999999;
    for( int i = 0; i < pTourData->getTourPosLat().size(); i++ )
    {
        double dist =  hF.getDistanceFromLatLonInKm( m_latitude,
                                                   m_longitude,
                                                   pTourData->getTourPosLat().at(i) * ( 180 / pow(2,31) ),
                                                   pTourData->getTourPosLong().at(i) * ( 180 / pow(2,31) ) );
        if( dist < minDist ) minDist = dist;
    }
    //qDebug() << "Minimum distance is" << minDist << "km, Trackpoints:" << pTourData->getTourPosLat().size();
    m_pItem->setText( 7, QString( "%1" ).arg( minDist ) );
    decrementThreadCnt();
}

void ThreadTrack2Point::decrementThreadCnt()
{
    m_pMutex->lock();
    *m_pCnt = *m_pCnt - 1;
    //qDebug() << "Threads" << *m_pCnt;
    m_pMutex->unlock();
}
