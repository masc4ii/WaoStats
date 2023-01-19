#include "TourData.h"

TourData::TourData()
{
    reset();
}

void TourData::reset()
{
    m_session.minTemperature = 9999;
    m_tourTimeStamp.clear();
    m_tourDistance.clear();
    m_tourBatterySoc.clear();
    m_tourSpeed.clear();
    m_tourCadence.clear();
    m_tourAltitude.clear();
    m_tourTemperature.clear();
    m_tourGrade.clear();
    m_tourPosLat.clear();
    m_tourPosLong.clear();
    m_tourHeartRate.clear();
    m_tourCalories.clear();
    m_tourPower.clear();
    m_tourLRBalance.clear();
    m_altCorrectionDone = false;
    m_posCorrectionDone = false;
    m_tempCorrectionDone = false;
    m_battCorrectionDone = false;
    m_firstPosRead = false;
    m_posRead = false;

    m_gearTimeStamp.clear();
    m_gearDistance.clear();
    m_gearNumFront.clear();
    m_gearToothFront.clear();
    m_gearNumRear.clear();
    m_gearToothRear.clear();
    m_gearRatio.clear();
    m_gearInfoRear = false;
    m_gearInfoFront = false;
    m_gearCountFront = 0;
    m_gearCountRear = 0;

    m_session.totalElapsedTime = 0;
    m_session.totalTimerTime = 0;
    m_session.avgSpeed = 0;
    m_session.maxSpeed = 0;
    m_session.totalDistance = 0;
    m_session.avgCadence = 0;
    m_session.maxCadence = 0;
    m_session.ascent = 0;
    m_session.descent = 0;
    m_session.altitudeMax = 0;
    m_session.altitudeMin = 9999;
    m_session.avgTemperature = 0;
    m_session.maxTemperature = 0;
    m_session.minTemperature = 9999;
    m_session.startTime = 0;
    m_session.startDistance = 0;
    m_session.maxGrade = 0;
    m_session.minGrade = 0;
    m_session.minHeartRate = 0;
    m_session.avgHeartRate = 0;
    m_session.maxHeartRate = 0;
    m_session.avgPower = 0;
    m_session.maxPower = 0;
    m_session.leftRightBalance = 0;
    m_session.totalWork = 0;
    m_session.totalCalories = 0;
    m_session.normalizedPower = 0;
    m_session.thresholdPower = 0;
    m_session.trainingStressScore = 0;
    m_session.itensityFactor = 0;
    m_altCorrectionDone = false;

    m_deviceInfo.clear();

    m_sections.clear();
}

bool TourData::deviceIdIsIncluded(deviceInfo_t a)
{
    foreach( deviceInfo_t deviceInfo, m_deviceInfo )
    {
        if( deviceInfo.deviceId == a.deviceId ) return true;
    }
    return false;
}

int TourData::deviceIdInVectorAt(deviceInfo_t a)
{
    for( int i = 0; i < m_deviceInfo.size(); i++ )
    {
        if( m_deviceInfo.at( i ).deviceId == a.deviceId ) return i;
    }
    return -1;
}
