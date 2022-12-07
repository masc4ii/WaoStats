#include "Listener.h"
#include "math.h"
#include <QDebug>

//#define LOGOUT

Listener::Listener()
{
    reset();
}

void Listener::reset()
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
    m_firstPosRead = false;
    m_posRead = false;

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

void Listener::PrintValues(const fit::FieldBase& field)
{
    for (FIT_UINT8 j=0; j< (FIT_UINT8)field.GetNumValues(); j++)
    {
#ifdef LOGOUT
        std::wcout << L"       Val" << j << L": ";

        switch (field.GetType())
        {
        // Get float 64 values for numeric types to receive values that have
        // their scale and offset properly applied.
        case FIT_BASE_TYPE_ENUM:
        case FIT_BASE_TYPE_BYTE:
        case FIT_BASE_TYPE_SINT8:
        case FIT_BASE_TYPE_UINT8:
        case FIT_BASE_TYPE_SINT16:
        case FIT_BASE_TYPE_UINT16:
        case FIT_BASE_TYPE_SINT32:
        case FIT_BASE_TYPE_UINT32:
        case FIT_BASE_TYPE_SINT64:
        case FIT_BASE_TYPE_UINT64:
        case FIT_BASE_TYPE_UINT8Z:
        case FIT_BASE_TYPE_UINT16Z:
        case FIT_BASE_TYPE_UINT32Z:
        case FIT_BASE_TYPE_UINT64Z:
        case FIT_BASE_TYPE_FLOAT32:
        case FIT_BASE_TYPE_FLOAT64:
            std::wcout << field.GetFLOAT64Value(j);
            break;
        case FIT_BASE_TYPE_STRING:
            std::wcout << field.GetSTRINGValue(j);
            break;
        default:
            break;
        }
        std::wcout << L" " << field.GetUnits().c_str() << L"\n";;
#endif
    }
}

void Listener::OnMesg(fit::Mesg& mesg)
{
    if( QString( mesg.GetName().c_str() ) != QString( "device_info" )
     && QString( mesg.GetName().c_str() ) != QString( "record" )
     && QString( mesg.GetName().c_str() ) != QString( "session" )
     && QString( mesg.GetName().c_str() ) != QString( "lap" ) ) return;

#ifdef LOGOUT
    printf("On Mesg:\n");
    std::wcout << L"   New Mesg: " << mesg.GetName().c_str() << L".  It has " << mesg.GetNumFields() << L" field(s) and " << mesg.GetNumDevFields() << " developer field(s).\n";
#endif

    double tourTimeStamp = 0;
    double tourAltitude = 0;
    double tourDistance = 0;
    static double tourBatterySoc = 0;
    double tourCadence = 0;
    double tourSpeed = 0;
    double tourPosLat = 0;
    double tourPosLong = 0;
    static double tourTemperature = 0;
    double tourGrade = 0;
    double tourHeartRate = 0;
    double tourCalories = 0;
    double tourPower = 0;
    double tourLRBalance = 50;
    deviceInfo_t deviceInfo;
    deviceInfo.name = "";
    deviceInfo.battery = "";
    deviceInfo.deviceId = -1;
    fitSection_t lap;
    static double lapPosGrade = 0;
    static double lapNegGrade = 0;
    static double lapMinTemp = 9999;
    static double lastDistance = 0;
    static double lastLapStartDistance = 0;

    for (FIT_UINT16 i = 0; i < (FIT_UINT16)mesg.GetNumFields(); i++)
    {
        fit::Field* field = mesg.GetFieldByIndex(i);
#ifdef LOGOUT
        std::wcout << L"   Field" << i << " (" << field->GetName().c_str() << ") has " << field->GetNumValues() << L" value(s)\n";
        PrintValues(*field);
#endif

        if( QString( mesg.GetName().c_str() ) == QString( "session" ) )
        {
            if(      QString( field->GetName().c_str() ) == QString( "total_elapsed_time" ) ) m_session.totalElapsedTime = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "total_timer_time" ) ) m_session.totalTimerTime = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "avg_speed" ) ) m_session.avgSpeed = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "max_speed" ) ) m_session.maxSpeed = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "total_distance" ) ) m_session.totalDistance = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "avg_cadence" ) ) m_session.avgCadence = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "max_cadence" ) ) m_session.maxCadence = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "total_ascent" ) ) m_session.ascent = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "total_descent" ) ) m_session.descent = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "max_altitude" ) ) m_session.altitudeMax = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "min_altitude" ) ) m_session.altitudeMin = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "avg_temperature" ) ) m_session.avgTemperature = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "max_temperature" ) ) m_session.maxTemperature = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "start_time" ) ) m_session.startTime = field->GetUINT32Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "min_heart_rate" ) ) m_session.minHeartRate = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "avg_heart_rate" ) ) m_session.avgHeartRate = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "max_heart_rate" ) ) m_session.maxHeartRate = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "avg_power" ) ) m_session.avgPower = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "max_power" ) ) m_session.maxPower = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "left_right_balance" ) ) m_session.leftRightBalance = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "total_work" ) ) m_session.totalWork = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "total_calories" ) ) m_session.totalCalories = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "normalized_power" ) ) m_session.normalizedPower = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "threshold_power" ) ) m_session.thresholdPower = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "training_stress_score" ) ) m_session.trainingStressScore = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "intensity_factor" ) ) m_session.itensityFactor = field->GetFLOAT64Value(0);
            //else if( QString( field->GetName().c_str() ) == QString( "max_neg_grade" ) ) m_session.minGrade = field->GetFLOAT64Value(0);
            //else if( QString( field->GetName().c_str() ) == QString( "max_pos_grade" ) ) m_session.maxGrade = field->GetFLOAT64Value(0);
        }
        if( QString( mesg.GetName().c_str() ) == QString( "lap" ) )
        {
            if(      QString( field->GetName().c_str() ) == QString( "total_elapsed_time" ) ) lap.totalElapsedTime = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "total_timer_time" ) ) lap.totalTimerTime = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "avg_speed" ) ) lap.avgSpeed = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "max_speed" ) ) lap.maxSpeed = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "total_distance" ) ) lap.totalDistance = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "avg_cadence" ) ) lap.avgCadence = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "max_cadence" ) ) lap.maxCadence = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "total_ascent" ) ) lap.ascent = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "total_descent" ) ) lap.descent = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "max_altitude" ) ) lap.altitudeMax = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "min_altitude" ) ) lap.altitudeMin = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "avg_temperature" ) ) lap.avgTemperature = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "max_temperature" ) ) lap.maxTemperature = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "start_time" ) ) lap.startTime = field->GetUINT32Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "min_heart_rate" ) ) lap.minHeartRate = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "avg_heart_rate" ) ) lap.avgHeartRate = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "max_heart_rate" ) ) lap.maxHeartRate = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "avg_power" ) ) lap.avgPower = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "max_power" ) ) lap.maxPower = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "left_right_balance" ) ) lap.leftRightBalance = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "total_work" ) ) lap.totalWork = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "total_calories" ) ) lap.totalCalories = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "normalized_power" ) ) lap.normalizedPower = field->GetFLOAT64Value(0);
            //else if( QString( field->GetName().c_str() ) == QString( "max_neg_grade" ) ) lap.minGrade = field->GetFLOAT64Value(0);
            //else if( QString( field->GetName().c_str() ) == QString( "max_pos_grade" ) ) lap.maxGrade = field->GetFLOAT64Value(0);
        }
        if( QString( mesg.GetName().c_str() ) == QString( "record" ) && mesg.GetNumFields() > 5 )
        {
            if(      QString( field->GetName().c_str() ) == QString( "timestamp" ) ) tourTimeStamp = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "altitude" ) ) tourAltitude = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "distance" ) )
            {
                tourDistance = field->GetFLOAT64Value(0) / 1000.0;
                lastDistance = tourDistance;
            }
            else if( QString( field->GetName().c_str() ) == QString( "battery_soc" ) ) tourBatterySoc = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "cadence" ) ) tourCadence = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "speed" ) ) tourSpeed = field->GetFLOAT64Value(0) * 3.6;
            else if( QString( field->GetName().c_str() ) == QString( "position_lat" ) )
            {
                tourPosLat = field->GetFLOAT64Value(0);
                m_posRead = true;
            }
            else if( QString( field->GetName().c_str() ) == QString( "position_long" ) ) tourPosLong = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "grade" ) )
            {
                tourGrade = field->GetFLOAT64Value(0);
                if( tourGrade > m_session.maxGrade ) m_session.maxGrade = tourGrade;
                if( tourGrade < m_session.minGrade ) m_session.minGrade = tourGrade;
                if( tourGrade > lapPosGrade ) lapPosGrade = tourGrade;
                if( tourGrade < lapNegGrade ) lapNegGrade = tourGrade;
            }
            else if( QString( field->GetName().c_str() ) == QString( "temperature" ) )
            {
                tourTemperature = field->GetFLOAT64Value(0);
                if( tourTemperature < m_session.minTemperature ) m_session.minTemperature = tourTemperature;
                if( tourTemperature < lapMinTemp ) lapMinTemp = tourTemperature;
                if( !m_tempCorrectionDone )
                {
                    m_tempCorrectionDone = true;
                    for( int i = 0; i < m_tourTemperature.count(); i++ )
                        m_tourTemperature[i] = tourTemperature;
                }
            }
            else if( QString( field->GetName().c_str() ) == QString( "heart_rate" ) ) tourHeartRate = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "calories" ) ) tourCalories = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "power" ) ) tourPower = field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "left_right_balance" ) ) tourLRBalance = field->GetFLOAT64Value(0);
        }
        if( QString( mesg.GetName().c_str() ) == QString( "device_info" ) )
        {
            if(      QString( field->GetName().c_str() ) == QString( "product_name" ) ) deviceInfo.name = QString::fromStdWString( field->GetSTRINGValue(0) );
            else if( QString( field->GetName().c_str() ) == QString( "device_index" ) ) deviceInfo.deviceId = (int)field->GetFLOAT64Value(0);
            else if( QString( field->GetName().c_str() ) == QString( "charge" ) ) deviceInfo.battery = "Battery " + QString::fromStdWString( field->GetSTRINGValue(0) ) + "%";
            else if( QString( field->GetName().c_str() ) == QString( "software_version" ) ) deviceInfo.software = "Firmware v" + QString::fromStdWString( field->GetSTRINGValue(0) );
            else if( QString( field->GetName().c_str() ) == QString( "battery_status" ) )
            {
                int val = (int)field->GetFLOAT64Value(0);
                //batteryStatus: new=1,good=2,ok=3,low=4,critical=5
                switch( val )
                {
                case 1: deviceInfo.battery = "Battery new";
                    break;
                case 2: deviceInfo.battery = "Battery good";
                    break;
                case 3: deviceInfo.battery = "Battery ok";
                    break;
                case 4: deviceInfo.battery = "Battery low";
                    break;
                case 5: deviceInfo.battery = "Battery critical";
                    break;
                default:
                    break;
                }
            }
        }
    }

    for (auto devField : mesg.GetDeveloperFields())
    {
#ifdef LOGOUT
        std::wcout << L"   Developer Field(" << devField.GetName().c_str() << ") has " << devField.GetNumValues() << L" value(s)\n";
        PrintValues(devField);
#endif
        if( QString( mesg.GetName().c_str() ) == QString( "device_info" ) )
        {
            if( QString( devField.GetName().c_str() ) == QString( "charge" ) ) deviceInfo.battery = "Battery " + QString::fromStdWString( devField.GetSTRINGValue(0) ) + "%";
        }
    }
    if( QString( mesg.GetName().c_str() ) == QString( "record" ) && mesg.GetNumFields() > 5 )
    {
        if( !m_tourAltitude.empty() && fabs( m_tourAltitude.last() - tourAltitude ) > 50 && !m_altCorrectionDone )
        {
            m_altCorrectionDone = true;
            for( int i = 0; i < m_tourAltitude.count(); i++ )
                m_tourAltitude[i] = tourAltitude;
        }

        if( !m_tourPosLat.empty() && m_posRead && !m_firstPosRead ) //GPS not found yet
        {
            m_firstPosRead = true;
            for( int i = 0; i < m_tourPosLat.count(); i++ )
            {
                m_tourPosLat[i] = tourPosLat;
                m_tourPosLong[i] = tourPosLong;
            }
        }
        else if( tourPosLat == 0.0 || tourPosLong == 0.0 ) //No GPS while on track
        {
            m_tourPosLat.append( m_tourPosLat.last() );
            m_tourPosLong.append( m_tourPosLong.last() );
        }
        else //All fine
        {
            m_tourPosLat.append( tourPosLat );
            m_tourPosLong.append( tourPosLong );
        }

        m_tourTimeStamp.append( tourTimeStamp );
        m_tourDistance.append( tourDistance );
        m_tourBatterySoc.append( tourBatterySoc );
        m_tourSpeed.append( tourSpeed );
        m_tourCadence.append( tourCadence );
        m_tourAltitude.append( tourAltitude );
        m_tourTemperature.append( tourTemperature );
        m_tourGrade.append( tourGrade );
        m_tourHeartRate.append( tourHeartRate );
        m_tourCalories.append( tourCalories );
        m_tourPower.append( tourPower );
        m_tourLRBalance.append( tourLRBalance );
    }
    if( QString( mesg.GetName().c_str() ) == QString( "lap" ) && mesg.GetNumFields() > 5 )
    {
        lap.maxGrade = lapPosGrade;
        lap.minGrade = lapNegGrade;
        lap.minTemperature = lapMinTemp;
        lap.startDistance = lastLapStartDistance;
        m_sections.append( lap );
        lastLapStartDistance = lastDistance;
        lapPosGrade = 0;
        lapNegGrade = 0;
        lapMinTemp = 9999;
    }
    if( QString( mesg.GetName().c_str() ) == QString( "device_info" )
     && deviceInfo.deviceId != -1 )
    {
        if( !deviceIdIsIncluded( deviceInfo ) )
        {
            m_deviceInfo.append( deviceInfo );
            qSort(m_deviceInfo.begin(), m_deviceInfo.end(), [](const deviceInfo_t& a, const deviceInfo_t& b) { return a.deviceId < b.deviceId; });
        }
        else
        {
            m_deviceInfo.replace( deviceIdInVectorAt( deviceInfo ), deviceInfo );
        }
    }
}

void Listener::OnMesg(fit::FileIdMesg& mesg)
{
#ifdef LOGOUT
  printf("File ID:\n");
  if (mesg.IsTypeValid())
     printf("   Type: %d\n", mesg.GetType());
  if (mesg.IsManufacturerValid())
     printf("   Manufacturer: %d\n", mesg.GetManufacturer());
  if (mesg.IsProductValid())
     printf("   Product: %d\n", mesg.GetProduct());
  if (mesg.IsSerialNumberValid())
     printf("   Serial Number: %u\n", mesg.GetSerialNumber());
  if (mesg.IsNumberValid())
     printf("   Number: %d\n", mesg.GetNumber());
#endif
}

bool Listener::deviceIdIsIncluded(deviceInfo_t a)
{
    foreach( deviceInfo_t deviceInfo, m_deviceInfo )
    {
        if( deviceInfo.deviceId == a.deviceId ) return true;
    }
    return false;
}

int Listener::deviceIdInVectorAt(deviceInfo_t a)
{
    for( int i = 0; i < m_deviceInfo.size(); i++ )
    {
        if( m_deviceInfo.at( i ).deviceId == a.deviceId ) return i;
    }
    return -1;
}
