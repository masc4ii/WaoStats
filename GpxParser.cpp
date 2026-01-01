#include "GpxParser.h"
#include <QFile>
#include <QXmlStreamReader>
#include <QDebug>
#include <QDateTime>
#include <QSettings>
#include <QDir>
#include <QJsonDocument>
#include <QJsonObject>
#include <QtMath>
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
    timeAnalysis(breakSecs);
    tourAnalysis();
    cadenceAnalysis();
    if( powerRead ) {
        initPwrZoneValues();
        powerAnalysis();
    }
    if( heartrateRead ) {
        initHrZoneValues();
        heartRateAnalysis();
    }

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

bool GpxParser::initHrZoneValues()
{
    QSettings set( QSettings::UserScope, "masc.WaoStats", "WaoStats" );
    QString workingPath = set.value( "workingPath", QDir::homePath() + "/Documents/BikeTracking" ).toString();

    QFile file(workingPath + "/heartRateZones.json");
    if (!file.open(QIODevice::ReadOnly)) {
        return false;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        return false;
    }

    if (!jsonDoc.isObject()) {
        return false;
    }

    QJsonObject jsonObject = jsonDoc.object();

    for (int i = 0; i < 5; ++i) {
        QString key = QString::number(i); // Schlüssel als String
        if (jsonObject.contains(key) && jsonObject[key].isString()) {
            m_hrZoneHigh[i] = jsonObject[key].toString().toInt();
        }
    }
    return true;
}

bool GpxParser::initPwrZoneValues()
{
    QSettings set( QSettings::UserScope, "masc.WaoStats", "WaoStats" );
    QString workingPath = set.value( "workingPath", QDir::homePath() + "/Documents/BikeTracking" ).toString();

    QFile file(workingPath + "/powerZones.json");
    if (!file.open(QIODevice::ReadOnly)) {
        return false;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        return false;
    }

    if (!jsonDoc.isObject()) {
        return false;
    }

    QJsonObject jsonObject = jsonDoc.object();

    for (int i = 0; i < 8; ++i) {
        QString key = QString::number(i); // Schlüssel als String
        if (jsonObject.contains(key) && jsonObject[key].isString()) {
            m_pwrZoneHigh[i] = jsonObject[key].toString().toInt();
        }
    }
    return true;
}

void GpxParser::timeAnalysis(double breakSecs)
{
    m_session.startTime = m_tourTimeStamp.first();
    m_session.totalDistance = m_tourDistance.last() * 1000;
    m_session.totalElapsedTime = m_tourTimeStamp.last() - m_tourTimeStamp.first();
    m_session.totalTimerTime = m_tourTimeStamp.last() - m_tourTimeStamp.first() - breakSecs;
    if( m_session.totalTimerTime < 0 ) m_session.totalTimerTime = 0.0;
}

void GpxParser::tourAnalysis()
{
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
    m_session.altitudeMax = maxAlt;
    m_session.altitudeMin = minAlt;
    m_session.ascent = gradePos;
    m_session.descent = gradeNeg;

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

    if( m_session.totalTimerTime > 0 ) m_session.avgSpeed = m_session.totalDistance / m_session.totalTimerTime;
    else m_session.avgSpeed = 0;
}

void GpxParser::powerAnalysis()
{
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

            if(     m_tourPower.at(i) <= m_pwrZoneHigh[0]) m_session.pwrTimeInZone[0] += timeDiff;
            else if(m_tourPower.at(i) <= m_pwrZoneHigh[1]) m_session.pwrTimeInZone[1] += timeDiff;
            else if(m_tourPower.at(i) <= m_pwrZoneHigh[2]) m_session.pwrTimeInZone[2] += timeDiff;
            else if(m_tourPower.at(i) <= m_pwrZoneHigh[3]) m_session.pwrTimeInZone[3] += timeDiff;
            else if(m_tourPower.at(i) <= m_pwrZoneHigh[4]) m_session.pwrTimeInZone[4] += timeDiff;
            else m_session.pwrTimeInZone[5] += timeDiff;
        }
    }
    if( m_session.totalTimerTime != 0 )
    {
        m_session.avgPower = helpPower / m_session.totalTimerTime;
        m_session.normalizedPower = calculateNormalizedPower(m_tourPower, m_tourTimeStamp);
    }
    analysePowerCurve();
}

void GpxParser::heartRateAnalysis()
{
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

            if(     m_tourHeartRate.at(i) <= m_hrZoneHigh[0]) m_session.hrTimeInZone[0] += timeDiff;
            else if(m_tourHeartRate.at(i) <= m_hrZoneHigh[1]) m_session.hrTimeInZone[1] += timeDiff;
            else if(m_tourHeartRate.at(i) <= m_hrZoneHigh[2]) m_session.hrTimeInZone[2] += timeDiff;
            else if(m_tourHeartRate.at(i) <= m_hrZoneHigh[3]) m_session.hrTimeInZone[3] += timeDiff;
            else m_session.hrTimeInZone[4] += timeDiff;
        }
    }
    if( m_session.totalTimerTime != 0 ) m_session.avgHeartRate = helpHeartRate / m_session.totalElapsedTime;
}

void GpxParser::cadenceAnalysis()
{
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
}

double GpxParser::calculateNormalizedPower(const QVector<double>& power, const QVector<double>& time) {
    if (power.size() != time.size() || power.isEmpty()) {
        return 0.0; // Fehlerbehandlung
    }

    QVector<double> smoothedPower;
    int N = power.size();

    // 1. Gleitenden Durchschnitt über 30 Sekunden berechnen
    for (int i = 0; i < N; ++i) {
        double sum = 0.0;
        double duration = 0.0;
        int j = i;

        // Zurückgehen, bis 30 Sekunden erreicht sind
        while (j >= 0 && (time[i] - time[j]) <= 30.0) {
            double dt = (j > 0) ? (time[j] - time[j - 1]) : 1.0; // Zeitdifferenz
            sum += power[j] * dt;
            duration += dt;
            --j;
        }

        double avgPower = (duration > 0) ? (sum / duration) : power[i];
        smoothedPower.append(avgPower);
    }

    // 2. Vierte Potenz berechnen und mitteln
    double sumPower4 = 0.0;
    for (double p : smoothedPower) {
        sumPower4 += qPow(p, 4);
    }
    double meanPower4 = sumPower4 / smoothedPower.size();

    // 3. Vierte Wurzel ziehen
    return qPow(meanPower4, 0.25);
}

double GpxParser::calculateWeightedPower(const QVector<double>& power, const QVector<double>& time) {
    if (power.size() != time.size() || power.isEmpty()) {
        return 0.0; // Fehlerbehandlung
    }

    QVector<double> weightedPower;
    int N = power.size();

    double tau = 30.0; // Zeitkonstante für exponentielle Glättung
    double alpha = 1.0 - qExp(-1.0 / tau); // Glättungsfaktor

    // 1. Exponentielle Glättung berechnen
    double smoothedPower = power[0]; // Startwert setzen
    for (int i = 1; i < N; ++i) {
        smoothedPower = alpha * power[i] + (1 - alpha) * smoothedPower;
        weightedPower.append(smoothedPower);
    }

    // 2. Vierte Potenz berechnen und mitteln
    double sumPower4 = 0.0;
    for (double p : weightedPower) {
        sumPower4 += qPow(p, 4);
    }
    double meanPower4 = sumPower4 / weightedPower.size();

    // 3. Vierte Wurzel ziehen
    return qPow(meanPower4, 0.25);
}


