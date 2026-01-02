#include "TourData.h"

TourData::TourData()
{
    reset();
}

void TourData::reset()
{
    m_tourTimeStamp.clear();
    m_tourDistance.clear();
    m_tourBatterySoc.clear();
    m_tourSpeed.clear();
    m_tourCadence.clear();
    m_tourAltitude.clear();
    m_tourGpsAccuracy.clear();
    m_tourTemperature.clear();
    m_tourGrade.clear();
    m_tourPosLat.clear();
    m_tourPosLong.clear();
    m_tourHeartRate.clear();
    m_tourCalories.clear();
    m_tourPower.clear();
    m_tourLRBalance.clear();
    m_tourLPedalSmoothness.clear();
    m_tourRPedalSmoothness.clear();
    m_tourWindSpeed.clear();
    m_tourAirSpeed.clear();
    m_altCorrectionDone = false;
    m_posCorrectionDone = false;
    m_tempCorrectionDone = false;
    m_battCorrectionDone = false;
    m_gradeCorrectionDone = false;
    m_caloriesCorrectionDone = false;
    m_heartRateCorrectionDone = false;
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
    m_session.altitudeMin = 0;
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
    for( int i = 0; i < 5; i++ ) m_session.hrTimeInZone[i] = 0.0;
    for( int i = 0; i < 8; i++ ) m_session.pwrTimeInZone[i] = 0.0;
    m_session.avgPower = 0;
    m_session.maxPower = 0;
    m_session.leftRightBalance = 0;
    m_session.leftPedalSmoothness = 0;
    m_session.rightPedalSmoothness = 0;
    m_session.totalWork = 0;
    m_session.totalCalories = 0;
    m_session.normalizedPower = 0;
    m_session.thresholdPower = 0;
    m_session.trainingStressScore = 0;
    m_session.itensityFactor = 0;
    m_altCorrectionDone = false;

    for( int i = 0; i < 5; i++ ) m_hrZoneHigh[i] = 0.0;
    for( int i = 0; i < 8; i++ ) m_pwrZoneHigh[i] = 0.0;

    m_deviceInfo.clear();

    m_pwrCurve.clear();

    m_sections.clear();

    m_workoutName.clear();
}

bool TourData::deviceIdIsIncluded(deviceInfo_t a)
{
    foreach( deviceInfo_t deviceInfo, m_deviceInfo )
    {
        if( deviceInfo.deviceId == a.deviceId ) return true;
        if( deviceInfo.name == a.name ) return true;
    }
    return false;
}

int TourData::deviceIdInVectorAt(deviceInfo_t a)
{
    for( int i = 0; i < m_deviceInfo.size(); i++ )
    {
        if( m_deviceInfo.at( i ).deviceId == a.deviceId ) return i;
        if( m_deviceInfo.at( i ).name == a.name ) return i;
    }
    return -1;
}

void TourData::analysePowerCurve()
{
    const QVector<double> timeIntervals = {0, 5, 15, 30, 60, 120, 180, 300, 480, 600, 900, 1200, 1800, 2700, 3600, 7200, 10800, 18000, 36000}; // in seconds

    if (m_tourTimeStamp.isEmpty() || m_tourPower.isEmpty() ||
        m_tourTimeStamp.size() != m_tourPower.size()) {
        return;
    }

    double startTime = m_tourTimeStamp.first();
    double endTime = m_tourTimeStamp.last();
    double diffTime = endTime - startTime;

    for (auto interval : timeIntervals)
    {
        if (interval > diffTime)
            break;

        m_pwrCurve.push_back(QPair<double, double>(interval, 0));
    }

    m_pwrCurve.first().second = getSession().maxPower;

// for each time interval
#pragma omp parallel for
    for (int intervalIdx = 1; intervalIdx < timeIntervals.size(); ++intervalIdx) {
        double maxAvgPower = 0.0;
        double interval = timeIntervals[intervalIdx];

        if  (startTime + interval < endTime)
        {
            // move window over all start positions
            for (int startIdx = 0; startIdx < m_tourTimeStamp.size(); ++startIdx) {
                double windowStartTime = m_tourTimeStamp[startIdx];
                double windowEndTime = windowStartTime + interval;

                // full windows only
                if (windowEndTime > endTime)
                    break;

                double powerSum = 0.0;
                int count = 0;

                // collect data in window
                for (int idx = startIdx; idx < m_tourTimeStamp.size(); ++idx) {
                    if (m_tourTimeStamp[idx] < windowEndTime) {
                        powerSum += m_tourPower[idx];
                        count++;
                    } else {
                        break; // quit window
                    }
                }

                // calc average
                if (count > 0) {
                    double avgPower = powerSum / count;
                    maxAvgPower = std::max(maxAvgPower, avgPower);
                }
            }
            m_pwrCurve[intervalIdx].second = maxAvgPower;
        }
    }
}

void TourData::analysePedalSmoothness()
{
    double sumL = 0.0;
    double sumR = 0.0;

    if (m_tourTimeStamp.size() != m_tourLPedalSmoothness.size()) return;
    if (m_tourTimeStamp.size() != m_tourRPedalSmoothness.size()) return;

    for (int i = 0; i < m_tourTimeStamp.size(); i++)
    {
        sumL += m_tourLPedalSmoothness.at(i);
        sumR += m_tourRPedalSmoothness.at(i);
    }

    m_session.leftPedalSmoothness = sumL / double(m_tourLPedalSmoothness.size());
    m_session.rightPedalSmoothness = sumR / double(m_tourRPedalSmoothness.size());
}
