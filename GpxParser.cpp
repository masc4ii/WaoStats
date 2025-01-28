#include "GpxParser.h"
#include <QFile>
#include <QXmlStreamReader>
#include <QDebug>
#include <QDateTime>
#include <math.h>
#include "HelperFunctions.h"

GpxParser::GpxParser() : TourData()
{

}

bool GpxParser::loadGpx( QString fileName )
{
    reset();
    filterReset( 0.0, FILTERGRADE );
    filterReset( 0.0, FILTERALTIT );

    //Open a XML stream for the file
    QXmlStreamReader Rxml;
    QFile file(fileName);
    if( !file.open(QIODevice::ReadOnly | QFile::Text) )
    {
        return false;
    }

    double lastLat = -1, lastLon = -1, lastTime = -1, time = 0, distance = 0, ele = 0, lastEle = -1, distanceGpx = 0;
    double factor = ( 180.0 / pow(2,31) );
    double lat = 0, lon = 0, distSinceLast = 0, power = 0, cadence = 0, heartrate = 0;
    double breakSecs = 0;
    bool cadenceRead = false, powerRead = false, heartrateRead = false, distanceRead = false;

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
        //Track Name
        if( Rxml.isStartElement() && ( Rxml.name() == QString( "name" ) ) )
        {
            m_workoutName = Rxml.readElementText();
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
                    HelperFunctions hF;
                    distSinceLast = hF.getDistanceFromLatLonInKm( lastLat, lastLon, lat, lon );
                    lastLat = lat;
                    lastLon = lon;
                }
            }
        }
        else if( Rxml.isStartElement() && ( Rxml.name() == QString( "power" ) ) )
        {
            power = Rxml.readElementText().toDouble();
            powerRead = true;
        }
        else if( Rxml.isStartElement() && ( Rxml.name() == QString( "distance" ) ) )
        {
            distanceGpx = Rxml.readElementText().toDouble();
            distanceRead = true;
        }
        else if( Rxml.isStartElement() && ( Rxml.name() == QString( "cadence" ) ) )
        {
            cadence = Rxml.readElementText().toDouble();
            cadenceRead = true;
        }
        else if( Rxml.isStartElement() && ( Rxml.name() == QString( "hr" ) ) )
        {
            heartrate = Rxml.readElementText().toDouble();
            heartrateRead = true;
        }
        //Altitude
        else if( Rxml.isStartElement() && ( Rxml.name() == QString( "ele" ) ) )
        {
            if( lastEle == -1 )
            {
                ele = Rxml.readElementText().toDouble();
                filterReset( ele, FILTERALTIT );
                lastEle = ele;
            }
            else ele = filter( Rxml.readElementText().toDouble(), FILTERALTIT );
        }
        //Timestamp
        else if( Rxml.isStartElement() && ( Rxml.name() == QString( "time" ) ) )
        {
            QString timeString = Rxml.readElementText();
            time = QDateTime( QDate( 1989, 12, 31 ), QTime( 1, 0, 0 ) ).secsTo( QDateTime().fromString( timeString, Qt::ISODateWithMs ) );
            if( !time ) time = QDateTime( QDate( 1989, 12, 31 ), QTime( 1, 0, 0 ) ).secsTo( QDateTime().fromString( timeString, Qt::ISODate ) );
            if( lastTime == -1 ) lastTime = time;
        }
        //Copy data into vectors
        if( Rxml.isEndElement() && ( Rxml.name() == QString( "trkpt" ) ) )
        {
            distance += distSinceLast;
            m_tourPosLat.append( lat / factor );
            m_tourPosLong.append( lon / factor );
            if( distanceRead )
                m_tourDistance.append( distanceGpx / 1000.0 );
            else
                m_tourDistance.append( distance );
            m_tourTimeStamp.append( time );
            double speedCalc = 0;
            if( time-lastTime != 0 ) speedCalc = distSinceLast / (time-lastTime) * 3600;
            static double lastSpeedCalc = 0;
            m_tourSpeed.append( ( lastSpeedCalc + speedCalc ) / 2.0 );
            if( ( time - lastTime > 30 && distSinceLast < 0.05 ) //if time >30s and distance < 50m, or speed < 1km/h, it must be a break...
             || ( ( lastSpeedCalc + speedCalc ) / 2.0 ) < 1.0 ) breakSecs += time - lastTime;
            lastSpeedCalc = speedCalc;
            m_tourTemperature.append( 0 );
            m_tourAltitude.append( ele );
            double grade = 0;
            if( distSinceLast > 0.0005 ) grade = ( ele - lastEle ) / distSinceLast / 10.0;
            m_tourGrade.append( filter( grade, FILTERGRADE ) );
            m_tourBatterySoc.append( -1 );
            lastTime = time;
            lastEle = ele;
            if(cadenceRead) m_tourCadence.append( cadence );
            if(powerRead) m_tourPower.append( power );
            if(heartrateRead) m_tourHeartRate.append( heartrate );
        }
    }
    file.close();

    //Create session statistics
    m_session.startTime = m_tourTimeStamp.first();
    m_session.totalDistance = m_tourDistance.last() * 1000;
    m_session.totalElapsedTime = m_tourTimeStamp.last() - m_tourTimeStamp.first();
    m_session.totalTimerTime = m_tourTimeStamp.last() - m_tourTimeStamp.first() - breakSecs;
    if( m_session.totalTimerTime < 0 ) m_session.totalTimerTime = 0.0;

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
        // if there is a value over 120km/h it most probably is an error in the track -> filter
        if( m_session.maxSpeed < m_tourSpeed.at(i) / 3.6
         && m_tourSpeed.at(i) < 120 ) m_session.maxSpeed = m_tourSpeed.at(i) / 3.6;
    }
    for( int i = 1; i < m_tourGrade.size(); i++ )
    {
        if( m_session.maxGrade < m_tourGrade.at(i) ) m_session.maxGrade = m_tourGrade.at(i);
        else if( m_session.minGrade > m_tourGrade.at(i) ) m_session.minGrade = m_tourGrade.at(i);
    }

    double helpPower = 0;
    for( int i = 1; i < m_tourPower.size(); i++ )
    {
        if( m_session.maxPower < m_tourPower.at(i) ) m_session.maxPower = m_tourPower.at(i);

        if( m_tourPower.size() == m_tourTimeStamp.size() )
        {
            double timeDiff = m_tourTimeStamp.at(i) - m_tourTimeStamp.at(i - 1);
            helpPower += m_tourPower.at(i) * timeDiff;

            m_session.totalCalories += m_tourPower.at(i) * timeDiff / (4184 * 0.215);
            m_tourCalories.append(m_session.totalCalories);
        }
    }
    if( m_session.totalTimerTime != 0 ) m_session.avgPower = helpPower / m_session.totalTimerTime;

    double helpCadence = 0;
    double helpCadenceTime = m_session.totalElapsedTime;
    for( int i = 1; i < m_tourCadence.size(); i++ )
    {
        if( m_session.maxCadence < m_tourCadence.at(i) ) m_session.maxCadence = m_tourCadence.at(i);

        if( m_tourCadence.size() == m_tourTimeStamp.size() )
        {
            double timeDiff = m_tourTimeStamp.at(i) - m_tourTimeStamp.at(i - 1);
            if( m_tourCadence.at(i) > 0 ) helpCadence += m_tourCadence.at(i) * timeDiff;
            else helpCadenceTime -= timeDiff;
        }
    }
    if( helpCadenceTime > 0 ) m_session.avgCadence = helpCadence / helpCadenceTime;

    double helpHeartRate = 0;
    for( int i = 1; i < m_tourHeartRate.size(); i++ )
    {
        if( m_session.maxHeartRate < m_tourHeartRate.at(i) ) m_session.maxHeartRate = m_tourHeartRate.at(i);
        else if( m_session.minHeartRate > m_tourHeartRate.at(i) ) m_session.minHeartRate = m_tourHeartRate.at(i);
        else if( m_session.minHeartRate == 0 ) m_session.minHeartRate = m_tourHeartRate.at(i);

        if( m_tourHeartRate.size() == m_tourTimeStamp.size() )
        {
            double timeDiff = m_tourTimeStamp.at(i) - m_tourTimeStamp.at(i - 1);
            helpHeartRate += m_tourHeartRate.at(i) * timeDiff;
        }
    }
    if( m_session.totalTimerTime != 0 ) m_session.avgHeartRate = helpHeartRate / m_session.totalElapsedTime;

    m_session.altitudeMax = maxAlt;
    m_session.altitudeMin = minAlt;
    m_session.ascent = gradePos;
    m_session.descent = gradeNeg;
    if( m_session.totalTimerTime > 0 ) m_session.avgSpeed = m_session.totalDistance / m_session.totalTimerTime;
    else m_session.avgSpeed = 0;

    return true;
}

double GpxParser::filter( double newValue, int channel )
{
    m_filter[m_cnt[channel]][channel] = newValue;
    m_cnt[channel]++;
    if( m_cnt[channel] >= FILTERSIZE ) m_cnt[channel] = 0;
    double sum = 0;
    for( int i = 0; i < FILTERSIZE; i++ ) sum += m_filter[i][channel];
    return sum / FILTERSIZE;
}

void GpxParser::filterReset( double initValue, int channel )
{
    for( int i = 0; i < FILTERSIZE; i++ )
    {
        m_filter[i][channel] = initValue;
    }
    m_cnt[channel] = 0;
}
