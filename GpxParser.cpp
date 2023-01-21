#include "GpxParser.h"
#include <QFile>
#include <QXmlStreamReader>
#include <QDebug>
#include <QDateTime>

GpxParser::GpxParser() : TourData()
{

}

bool GpxParser::loadGpx( QString fileName )
{
    reset();
    for( int i = 0; i < FILTERSIZE; i++ )
    {
        m_filter[i] = 0.0;
    }
    m_cnt = 0;

    //Open a XML stream for the file
    QXmlStreamReader Rxml;
    QFile file(fileName);
    if( !file.open(QIODevice::ReadOnly | QFile::Text) )
    {
        return false;
    }

    double lastLat = -1, lastLon = -1, lastTime = -1, time = 0, distance = 0, ele = 0, lastEle = -1;
    double factor = ( 180.0 / pow(2,31) );
    double lat = 0, lon = 0, distSinceLast = 0;
    double breakSecs = 0;

    //Parse
    Rxml.setDevice(&file);
    while( !Rxml.atEnd() )
    {
        Rxml.readNext();
        if( Rxml.isStartElement() && ( Rxml.name() == QString( "gpx" ) ) )
        {
            for( int i = 0; i < Rxml.attributes().size(); i++ )
            {
                if( Rxml.attributes().at(i).name() == QString( "creator" ) )
                {
                    deviceInfo_t deviceInfo;
                    deviceInfo.name = Rxml.attributes().at(i).value().toString();
                    deviceInfo.battery = "";
                    deviceInfo.deviceId = 0;
                    m_deviceInfo.append( deviceInfo );
                }
            }
        }
        //GPS Position
        if( Rxml.isStartElement() && ( Rxml.name() == QString( "trkpt" ) ) )
        {
            if( Rxml.attributes().size() != 0 )
            {
                for( int i = 0; i < Rxml.attributes().size(); i++ )
                {
                    if( Rxml.attributes().at(i).name() == QString( "lat" ) )
                    {
                        lat = Rxml.attributes().at(i).value().toDouble();
                        m_posRead = true;
                    }
                    else if( Rxml.attributes().at(i).name() == QString( "lon" ) )
                    {
                        lon = Rxml.attributes().at(i).value().toDouble();
                        m_posRead = true;
                    }
                }
                if( lastLat == -1 )
                {
                    lastLat = lat;
                    lastLon = lon;
                    distance = 0;
                }
                else
                {
                    distSinceLast = getDistanceFromLatLonInKm( lastLat, lastLon, lat, lon );
                    lastLat = lat;
                    lastLon = lon;
                }
            }
        }
        //Altitude
        else if( Rxml.isStartElement() && ( Rxml.name() == QString( "ele" ) ) )
        {
            ele = Rxml.readElementText().toDouble();
            if( lastEle == -1 ) lastEle = ele;
        }
        //Timestamp
        else if( Rxml.isStartElement() && ( Rxml.name() == QString( "time" ) ) )
        {
            QString timeString = Rxml.readElementText();
            timeString.remove( "T" );
            timeString.remove( "Z" );
            time = QDateTime( QDate( 1989, 12, 31 ), QTime( 1, 0, 0 ) ).secsTo( QDateTime().fromString( timeString, "yyyy-MM-ddhh:mm:ss.zzz" ) );
            if( !time ) time = QDateTime( QDate( 1989, 12, 31 ), QTime( 1, 0, 0 ) ).secsTo( QDateTime().fromString( timeString, "yyyy-MM-ddhh:mm:ss" ) );
            if( lastTime == -1 ) lastTime = time;
        }
        //Copy data into vectors
        if( Rxml.isEndElement() && ( Rxml.name() == QString( "trkpt" ) ) )
        {
            distance += distSinceLast;
            m_tourPosLat.append( lat / factor );
            m_tourPosLong.append( lon / factor );
            m_tourDistance.append( distance );
            m_tourTimeStamp.append( time );
            double speedCalc = 0;
            if( time-lastTime != 0 ) speedCalc = distSinceLast / (time-lastTime) * 3600;
            static double lastSpeedCalc = 0;
            m_tourSpeed.append( ( lastSpeedCalc + speedCalc ) / 2.0 );
            if( time - lastTime > 30
             || ( ( lastSpeedCalc + speedCalc ) / 2.0 ) < 1.0 ) breakSecs += time - lastTime;
            lastSpeedCalc = speedCalc;
            m_tourTemperature.append( 0 );
            m_tourAltitude.append( ele );
            double grade = 0;
            if( distSinceLast > 0.005 ) grade = ( ele - lastEle ) / distSinceLast / 10.0;
            m_tourGrade.append( gradeFilter( grade ) );
            m_tourBatterySoc.append( 0 );
            lastTime = time;
            lastEle = ele;
        }
    }
    file.close();

    //Create session statistics
    m_session.startTime = m_tourTimeStamp.first();
    m_session.totalDistance = m_tourDistance.last() * 1000;
    m_session.totalElapsedTime = m_tourTimeStamp.last() - m_tourTimeStamp.first();
    m_session.totalTimerTime = m_tourTimeStamp.last() - m_tourTimeStamp.first() - breakSecs;

    double alt = m_tourAltitude.first();
    double lastAlt = alt;
    double minAlt = alt;
    double maxAlt = alt;
    double gradePos = 0, gradeNeg = 0;
    for( int i = 1; i < m_tourAltitude.size(); i++ )
    {
        alt = m_tourAltitude.at(i);
        if( alt > maxAlt ) maxAlt = alt;
        else if( alt < minAlt ) minAlt = alt;

        if( alt > lastAlt ) gradePos += alt - lastAlt;
        else if( alt < lastAlt ) gradeNeg += lastAlt - alt;

        lastAlt = alt;
    }
    for( int i = 1; i < m_tourSpeed.size(); i++ )
    {
        if( m_session.maxSpeed < m_tourSpeed.at(i) / 3.6 ) m_session.maxSpeed = m_tourSpeed.at(i) / 3.6;
    }
    for( int i = 1; i < m_tourGrade.size(); i++ )
    {
        if( m_session.maxGrade < m_tourGrade.at(i) ) m_session.maxGrade = m_tourGrade.at(i);
        else if( m_session.minGrade > m_tourGrade.at(i) ) m_session.minGrade = m_tourGrade.at(i);
    }
    m_session.altitudeMax = maxAlt;
    m_session.altitudeMin = minAlt;
    m_session.ascent = gradePos;
    m_session.descent = gradeNeg;
    m_session.avgSpeed = m_session.totalDistance / m_session.totalTimerTime;

    return true;
}

double GpxParser::getDistanceFromLatLonInKm( double lat1, double lon1, double lat2, double lon2 )
{
    double R = 6371.0; // Radius of the earth in km
    double dLat = fabs( deg2rad(lat2-lat1) );  // deg2rad below
    double dLon = fabs( deg2rad(lon2-lon1) );
    double a =
        sin( dLat / 2.0 ) * sin( dLat / 2.0 ) +
        cos( deg2rad( lat1 ) ) * cos( deg2rad( lat2 ) ) *
        sin( dLon / 2.0 ) * sin( dLon / 2.0 );
    double c = 2.0 * atan2( sqrt( a ), sqrt( 1.0 - a ));
    double d = R * c; // Distance in km
    return d;
}

double GpxParser::deg2rad( double deg )
{
    return deg * ( M_PI / 180.0 );
}

double GpxParser::gradeFilter( double newValue )
{
    m_filter[m_cnt] = newValue;
    m_cnt++;
    if( m_cnt >= FILTERSIZE ) m_cnt = 0;
    double sum = 0;
    for( int i = 0; i < FILTERSIZE; i++ ) sum += m_filter[i];
    return sum / FILTERSIZE;
}
