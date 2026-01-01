#include "FitParser.h"
#include "FitSDKRelease_21.158.00/c/fit_convert.h"
#include <QDebug>
#include <QApplication>

FitParser::FitParser() : TourData()
{

}

bool FitParser::loadFit(QString fileName)
{
    reset();

    FILE *file;
    FIT_UINT8 buf[8];
    FIT_CONVERT_RETURN convert_return = FIT_CONVERT_CONTINUE;
    FIT_UINT32 buf_size;
    //FIT_UINT32 mesg_index = 0;

    int minTemp = 9999;
    int lapMinTemp = 9999;
    double lapPosGrade = 0;
    double lapNegGrade = 0;
    double lastLapStartDistance = 0;
    double batterySoc = 0;

    FIT_CONVERT_STATE state;
    FitConvert_Init(&state, FIT_TRUE);

    if((file = fopen(fileName.toLatin1().data(), "rb")) == NULL)
    {
        printf("Error opening file %s.\n", fileName.toLatin1().data());
        return FIT_FALSE;
    }

    while(!feof(file) && (convert_return == FIT_CONVERT_CONTINUE))
    {
        for(buf_size=0;(buf_size < sizeof(buf)) && !feof(file); buf_size++)
        {
            buf[buf_size] = (FIT_UINT8)getc(file);
        }

        do
        {
#if defined(FIT_CONVERT_MULTI_THREAD)
            convert_return = FitConvert_Read(&state, buf, buf_size);
#else
            convert_return = FitConvert_Read(buf, buf_size);
#endif

            switch (convert_return)
            {
            case FIT_CONVERT_MESSAGE_AVAILABLE:
            {
#if defined(FIT_CONVERT_MULTI_THREAD)
                const FIT_UINT8 *mesg = FitConvert_GetMessageData(&state);
                FIT_UINT16 mesg_num = FitConvert_GetMessageNumber(&state);
#else
                const FIT_UINT8 *mesg = FitConvert_GetMessageData();
                FIT_UINT16 mesg_num = FitConvert_GetMessageNumber();
#endif
                //printf("Mesg %d (%d) - ", mesg_index++, mesg_num);

                switch(mesg_num)
                {
                case FIT_MESG_NUM_FILE_ID:
                {
                    const FIT_FILE_ID_MESG *fileId = (FIT_FILE_ID_MESG *) mesg;
                    deviceInfo_t deviceInfo;
                    deviceInfo.battery = "";
                    deviceInfo.deviceId = -1;
                    deviceInfo.name = fileId->product_name;
                    if( deviceInfo.name.count() && !deviceIdIsIncluded( deviceInfo ) )
                    {
                        m_deviceInfo.append( deviceInfo );
                    }
                    break;
                }

                case FIT_MESG_NUM_USER_PROFILE:
                {
                    //const FIT_USER_PROFILE_MESG *user_profile = (FIT_USER_PROFILE_MESG *) mesg;
                    //printf("User Profile: weight=%0.1fkg\n", user_profile->weight / 10.0f);
                    break;
                }

                case FIT_MESG_NUM_ACTIVITY:
                {
                    /*const FIT_ACTIVITY_MESG *activity = (FIT_ACTIVITY_MESG *) mesg;
                    printf("Activity: timestamp=%u, type=%u, event=%u, event_type=%u, num_sessions=%u\n", activity->timestamp, activity->type, activity->event, activity->event_type, activity->num_sessions);
                    {
                        FIT_ACTIVITY_MESG old_mesg;
                        old_mesg.num_sessions = 1;
#if defined(FIT_CONVERT_MULTI_THREAD)
                        FitConvert_RestoreFields(&state, &old_mesg);
#else
                        FitConvert_RestoreFields(&old_mesg);
#endif
                        printf("Restored num_sessions=1 - Activity: timestamp=%u, type=%u, event=%u, event_type=%u, num_sessions=%u\n", activity->timestamp, activity->type, activity->event, activity->event_type, activity->num_sessions);
                    }*/
                    break;
                }

                case FIT_MESG_NUM_SESSION:
                {
                    const FIT_SESSION_MESG *session = (FIT_SESSION_MESG *) mesg;
                    m_session.totalElapsedTime = session->total_elapsed_time / 1000.0;
                    m_session.totalTimerTime = session->total_timer_time / 1000.0;
                    m_session.totalDistance = session->total_distance / 100.0;
                    m_session.startTime = session->start_time;

                    m_session.avgSpeed = session->avg_speed / 1000.0;
                    m_session.maxSpeed = session->max_speed / 1000.0;

                    if( session->avg_cadence < 255 ) m_session.avgCadence = session->avg_cadence;
                    if( session->max_cadence < 255 ) m_session.maxCadence = session->max_cadence;

                    if( session->total_ascent < 65535 ) m_session.ascent = session->total_ascent;
                    if( session->total_descent < 65535 ) m_session.descent = session->total_descent;
                    m_session.altitudeMax = session->max_altitude / 5 - 500;
                    m_session.altitudeMin = session->min_altitude / 5 - 500;
                    //if( session->max_neg_grade < 32767 ) m_session.minGrade = session->max_neg_grade / 100.0; //wrong!
                    //if( session->max_pos_grade < 32767 ) m_session.maxGrade = session->max_pos_grade / 100.0; //wrong!

                    if( session->avg_temperature < 127 ) m_session.avgTemperature = session->avg_temperature;
                    if( session->min_temperature < 127 ) m_session.minTemperature = session->min_temperature;
                    if( session->max_temperature < 127 ) m_session.maxTemperature = session->max_temperature;

                    if( session->min_heart_rate < 255 ) m_session.minHeartRate = session->min_heart_rate;
                    if( session->avg_heart_rate < 255 ) m_session.avgHeartRate = session->avg_heart_rate;
                    if( session->max_heart_rate < 255 ) m_session.maxHeartRate = session->max_heart_rate;

                    for(int i = 0; i < FIT_SESSION_MESG_TIME_IN_HR_ZONE_COUNT; i++)    if( session->time_in_hr_zone[i]    < 4294967295 ) m_session.hrTimeInZone[i]  = session->time_in_hr_zone[i] / 1000.0;
                    for(int i = 0; i < FIT_SESSION_MESG_TIME_IN_POWER_ZONE_COUNT; i++) if( session->time_in_power_zone[i] < 4294967295 ) m_session.pwrTimeInZone[i] = session->time_in_power_zone[i] / 1000.0;

                    if( session->avg_power             < 65535 ) m_session.avgPower = session->avg_power;
                    if( session->max_power             < 65535 ) m_session.maxPower = session->max_power;
                    if( session->left_right_balance    < 65535 ) {if( session->left_right_balance <= 100 ){m_session.leftRightBalance = session->left_right_balance;}else{m_session.leftRightBalance = session->left_right_balance / 100.0;}}
                    if( session->total_work            < 65535 ) m_session.totalWork = session->total_work;
                    if( session->total_calories        < 65535 ) m_session.totalCalories = session->total_calories;
                    if( session->normalized_power      < 65535 ) m_session.normalizedPower = session->normalized_power;
                    if( session->threshold_power       < 65535 ) m_session.thresholdPower = session->threshold_power;
                    if( session->training_stress_score < 65535 ) m_session.trainingStressScore = session->training_stress_score;
                    if( session->intensity_factor      < 65535 ) m_session.itensityFactor = session->intensity_factor;
                    break;
                }

                case FIT_MESG_NUM_LAP:
                {
                    const FIT_LAP_MESG *lapMesg = (FIT_LAP_MESG *) mesg;
                    fitSection_t lap;
                    lap.totalElapsedTime = lapMesg->total_elapsed_time / 1000.0;
                    lap.totalTimerTime = lapMesg->total_timer_time / 1000.0;
                    lap.totalDistance = lapMesg->total_distance / 100.0;
                    lap.startTime = lapMesg->start_time;
                    lap.startDistance = lastLapStartDistance;

                    lap.avgSpeed = lapMesg->avg_speed / 1000.0;
                    lap.maxSpeed = lapMesg->max_speed / 1000.0;

                    if( lapMesg->avg_cadence < 255 ) lap.avgCadence = lapMesg->avg_cadence;
                    if( lapMesg->max_cadence < 255 ) lap.maxCadence = lapMesg->max_cadence;

                    if( lapMesg->total_ascent < 65535 ) lap.ascent = lapMesg->total_ascent;
                    if( lapMesg->total_descent < 65535 ) lap.descent = lapMesg->total_descent;
                    lap.altitudeMax = lapMesg->max_altitude / 5.0 - 500;
                    lap.altitudeMin = lapMesg->min_altitude / 5.0 - 500;
                    //if( lapMesg->max_neg_grade < 32767 ) lap.minGrade = lapMesg->max_neg_grade / 100.0; //wrong!
                    //if( lapMesg->max_pos_grade < 32767 ) lap.maxGrade = lapMesg->max_pos_grade / 100.0; //wrong!
                    lap.maxGrade = lapPosGrade;
                    lap.minGrade = lapNegGrade;

                    if( lapMesg->avg_temperature < 127 ) lap.avgTemperature = lapMesg->avg_temperature;
                    if( lapMesg->min_temperature < 127 ) lap.minTemperature = lapMesg->min_temperature;
                    else lap.minTemperature = lapMinTemp;
                    if( lapMesg->max_temperature < 127 ) lap.maxTemperature = lapMesg->max_temperature;

                    if( lapMesg->min_heart_rate < 255 ) lap.minHeartRate = lapMesg->min_heart_rate;
                    if( lapMesg->avg_heart_rate < 255 ) lap.avgHeartRate = lapMesg->avg_heart_rate;
                    if( lapMesg->max_heart_rate < 255 ) lap.maxHeartRate = lapMesg->max_heart_rate;

                    for(int i = 0; i < FIT_SESSION_MESG_TIME_IN_HR_ZONE_COUNT; i++)    lap.hrTimeInZone[i]  = lapMesg->time_in_hr_zone[i] / 1000.0;
                    for(int i = 0; i < FIT_SESSION_MESG_TIME_IN_POWER_ZONE_COUNT; i++) lap.pwrTimeInZone[i] = lapMesg->time_in_power_zone[i] / 1000.0;

                    if( lapMesg->avg_power          < 65535 ) lap.avgPower = lapMesg->avg_power;
                    if( lapMesg->max_power          < 65535 ) lap.maxPower = lapMesg->max_power;
                    if( lapMesg->left_right_balance < 65535 ) {if( lapMesg->left_right_balance <= 100 ){lap.leftRightBalance = lapMesg->left_right_balance;}else{lap.leftRightBalance = lapMesg->left_right_balance / 100.0;}}
                    if( lapMesg->total_work         < 65535 ) lap.totalWork = lapMesg->total_work;
                    if( lapMesg->total_calories     < 65535 ) lap.totalCalories = lapMesg->total_calories;
                    if( lapMesg->normalized_power   < 65535 ) lap.normalizedPower = lapMesg->normalized_power;

                    m_sections.append( lap );
                    if( !m_tourDistance.empty() ) lastLapStartDistance = m_tourDistance.last();
                    lapMinTemp = 9999;
                    lapPosGrade = 0;
                    lapNegGrade = 0;
                    break;
                }

                case FIT_MESG_NUM_RECORD:
                {
                    const FIT_RECORD_MESG *record = (FIT_RECORD_MESG *) mesg;

                    if( record->battery_soc < 255 )
                    {
                        if( !batterySoc )
                        {
                            for( int i = 0; i < m_tourBatterySoc.count(); i++ )
                            {
                                m_tourBatterySoc[i] = record->battery_soc / 2.0;
                            }
                        }
                        batterySoc = record->battery_soc / 2.0;
                        //Bring to device_info!
                        deviceInfo_t deviceInfo = m_deviceInfo.first();
                        deviceInfo.battery = QApplication::translate( "FitParser", "Battery %1\%" ).arg( batterySoc );
                        m_deviceInfo.replace( 0, deviceInfo );
                    }

                    if( record->distance >= 4294967295 ) break;

                    m_tourTimeStamp.append( record->timestamp );
                    m_tourDistance.append( record->distance / 100000.0 );

                    if( record->temperature < 127 ) m_tourTemperature.append( record->temperature );
                    else if( m_tourTemperature.count() > 0 ) m_tourTemperature.append( m_tourTemperature.last() );
                    else m_tourTemperature.append( 0 );

                    if( record->position_lat < 2147483647 ) m_tourPosLat.append( record->position_lat );
                    else if( m_tourPosLat.count() > 0 ) m_tourPosLat.append( m_tourPosLat.last() );
                    else m_tourPosLat.append( 0 );

                    if( record->position_long < 2147483647 ) m_tourPosLong.append( record->position_long );
                    else if( m_tourPosLong.count() > 0 ) m_tourPosLong.append( m_tourPosLong.last() );
                    else m_tourPosLong.append( 0 );

                    if( record->speed < 65535 ) m_tourSpeed.append( record->speed * 0.0036 );
                    else if( m_tourSpeed.count() > 0 ) m_tourSpeed.append( m_tourSpeed.last() );
                    else m_tourSpeed.append( 0 );

                    if( record->altitude < 65535 ) m_tourAltitude.append( record->altitude / 5.0 - 500 );
                    else if( m_tourAltitude.count() > 0 ) m_tourAltitude.append( m_tourAltitude.last() );
                    else m_tourAltitude.append( 0 );

                    if( record->cadence < 255 ) m_tourCadence.append( record->cadence );
                    else if( m_tourCadence.count() > 0 ) m_tourCadence.append( m_tourCadence.last() );
                    else m_tourCadence.append( 0 );

                    if( record->gps_accuracy < 255 ) m_tourGpsAccuracy.append( record->gps_accuracy );
                    else if( m_tourGpsAccuracy.count() > 0 ) m_tourGpsAccuracy.append( m_tourGpsAccuracy.last() );
                    else m_tourGpsAccuracy.append( 0 );

                    if( record->grade < 32767 ) m_tourGrade.append( record->grade / 100.0 );
                    else if( m_tourGrade.count() > 0 ) m_tourGrade.append( m_tourGrade.last() );
                    else m_tourGrade.append( 0 );

                    if( record->heart_rate < 255 ) m_tourHeartRate.append( record->heart_rate );
                    else if( m_tourHeartRate.count() > 0 ) m_tourHeartRate.append( m_tourHeartRate.last() );
                    else m_tourHeartRate.append( 0 );

                    if( record->power < 65535 ) m_tourPower.append( record->power );
                    else if( m_tourPower.count() > 0 ) m_tourPower.append( m_tourPower.last() );
                    else m_tourPower.append( 0 );

                    if( record->left_right_balance < 255 ) {
                        uint8_t v = record->left_right_balance;
                        bool right = (v & 0x80) != 0;
                        int percent = v & 0x7F;
                        m_tourLRBalance.append( right ? (100 - percent) : percent );
                    }
                    else if( m_tourLRBalance.count() > 0 ) m_tourLRBalance.append( m_tourLRBalance.last() );
                    else m_tourLRBalance.append( 0 );

                    m_tourCalories.append( record->calories );
                    m_tourBatterySoc.append( batterySoc );

                    //Correction for start of track
                    if( !m_firstPosRead && record->position_lat < 2147483647 && record->position_long < 2147483647 )
                    {
                        m_firstPosRead = true;
                        m_posRead = true;
                        for( int i = 0; i < m_tourPosLat.count(); i++ )
                        {
                            m_tourPosLat[i] = record->position_lat;
                            m_tourPosLong[i] = record->position_long;
                        }
                    }
                    if( !m_altCorrectionDone && record->altitude < 65535 )
                    {
                        m_altCorrectionDone = true;
                        for( int i = 0; i < m_tourAltitude.count(); i++ )
                        {
                            m_tourAltitude[i] = record->altitude / 5.0 - 500;
                        }
                    }
                    if( !m_gradeCorrectionDone && record->grade < 32767 )
                    {
                        m_gradeCorrectionDone = true;
                        for( int i = 0; i < m_tourGrade.count(); i++ )
                        {
                            m_tourGrade[i] = record->grade / 100.0;
                        }
                    }
                    if( record->grade < 32767 )
                    {
                        double grade = record->grade / 100.0;
                        if( grade > m_session.maxGrade ) m_session.maxGrade = grade;
                        if( grade < m_session.minGrade ) m_session.minGrade = grade;
                        if( grade > lapPosGrade ) lapPosGrade = grade;
                        if( grade < lapNegGrade ) lapNegGrade = grade;
                    }
                    if( !m_tempCorrectionDone && record->temperature < 127 )
                    {
                        m_tempCorrectionDone = true;
                        for( int i = 0; i < m_tourTemperature.count(); i++ )
                        {
                            m_tourTemperature[i] = record->temperature;
                        }
                    }
                    if( !m_caloriesCorrectionDone && record->calories < 65535 )
                    {
                        m_caloriesCorrectionDone = true;
                        for( int i = 0; i < m_tourCalories.count(); i++ )
                        {
                            m_tourCalories[i] = record->calories;
                        }
                    }
                    if( !m_heartRateCorrectionDone && record->heart_rate < 255 )
                    {
                        m_heartRateCorrectionDone = true;
                        for( int i = 0; i < m_tourHeartRate.count(); i++ )
                        {
                            m_tourHeartRate[i] = record->heart_rate;
                        }
                    }
                    if( minTemp > record->temperature && record->temperature < 127 ) minTemp = record->temperature;
                    if( lapMinTemp > record->temperature && record->temperature < 127 ) lapMinTemp = record->temperature;

                    break;
                }

                case FIT_MESG_NUM_EVENT:
                {
                    const FIT_EVENT_MESG *event = (FIT_EVENT_MESG *) mesg;

                    if( event->event == 42 || event->event == 43 ) //=42 & =43 for gear change
                    {
                        int gearNumFront = ((event->data & 0x00FF0000)>>16);
                        int gearToothFront = ((event->data & 0xFF000000)>>24);
                        int gearNumRear = (event->data & 0x000000FF);
                        int gearToothRear = ((event->data & 0x0000FF00)>>8);

                        if( gearToothFront > 0 && gearToothRear > 0 && gearToothFront < 255 && gearToothRear < 255 )
                        {
                            m_gearInfoRear = true;
                            m_gearInfoFront = true;
                            m_gearTimeStamp.append( event->timestamp );
                            m_gearNumFront.append( gearNumFront );
                            m_gearToothFront.append( gearToothFront );
                            m_gearNumRear.append( gearNumRear );
                            m_gearToothRear.append( gearToothRear );
                            //Calc ratio only, if tooth info existing
                            if( (int)gearToothFront > 1 && (int)gearToothRear > 1 ) m_gearRatio.append( (double)gearToothFront / (double)gearToothRear );
                            else m_gearRatio.append( 0.0 );
                            //Steel the distance
                            if( m_tourDistance.count() > 0 ) m_gearDistance.append( m_tourDistance.last() );
                            else m_gearDistance.append( 0.0 );
                            if( gearNumFront > m_gearCountFront ) m_gearCountFront = gearNumFront;
                            if( gearNumRear > m_gearCountRear ) m_gearCountRear = gearNumRear;
                        }

                        /*qDebug() << "Gear Event:"
                                 << (event->data & 0x000000FF)
                                 << ((event->data & 0x0000FF00)>>8)
                                 << ((event->data & 0x00FF0000)>>16)
                                 << ((event->data & 0xFF000000)>>24);*/
                    }
                    else if( event->event == 75 ) //=75 for radar
                    {
                        qDebug() << "Radar Event:" << event->data;
                    }
                    break;
                }

                case FIT_MESG_NUM_DEVICE_INFO:
                {
                    const FIT_DEVICE_INFO_MESG *device_info = (FIT_DEVICE_INFO_MESG *) mesg;

                    deviceInfo_t info;
                    if( device_info->device_index == 255 ) break;
                    info.name = device_info->product_name;
                    info.deviceId = device_info->device_index;
                    switch( device_info->battery_status )
                    {
                    case 1: info.battery = QApplication::translate( "FitParser", "Battery new" );
                        break;
                    case 2: info.battery = QApplication::translate( "FitParser", "Battery good" );
                        break;
                    case 3: info.battery = QApplication::translate( "FitParser", "Battery ok" );
                        break;
                    case 4: info.battery = QApplication::translate( "FitParser", "Battery low" );
                        break;
                    case 5: info.battery = QApplication::translate( "FitParser", "Battery critical" );
                        break;
                    default:
                        break;
                    }
                    if( device_info->software_version < 65535 ) info.software = "Firmware v" + QString::number(device_info->software_version/100.0);

                    if( !deviceIdIsIncluded( info ) )
                    {
                        m_deviceInfo.append( info );
                        std::sort(m_deviceInfo.begin(), m_deviceInfo.end(), [](const deviceInfo_t& a, const deviceInfo_t& b) { return a.deviceId < b.deviceId; });
                    }
                    else
                    {
                        if( !deviceIdInVectorAt( info ) && !info.battery.count() ) info.battery = m_deviceInfo.at( deviceIdInVectorAt( info ) ).battery; //save battery info for main device
                        m_deviceInfo.replace( deviceIdInVectorAt( info ), info );

                    }

                    break;
                }

                case FIT_MESG_NUM_WORKOUT:
                {
                    const FIT_WORKOUT_MESG *workout = (FIT_WORKOUT_MESG *) mesg;
                    m_workoutName = workout->wkt_name;
                    break;
                }

                case FIT_MESG_NUM_HR_ZONE:
                {
                    const FIT_HR_ZONE_MESG *hr_zone = (FIT_HR_ZONE_MESG *) mesg;
                    if( hr_zone->message_index < 5 ) m_hrZoneHigh[hr_zone->message_index] = hr_zone->high_bpm;
                    else if( hr_zone->message_index == 65535 ) //support for index-less format
                    {
                        if( !m_hrZoneHigh[0] ) m_hrZoneHigh[0] = hr_zone->high_bpm;
                        else if( !m_hrZoneHigh[1] ) m_hrZoneHigh[1] = hr_zone->high_bpm;
                        else if( !m_hrZoneHigh[2] ) m_hrZoneHigh[2] = hr_zone->high_bpm;
                        else if( !m_hrZoneHigh[3] ) m_hrZoneHigh[3] = hr_zone->high_bpm;
                        else if( !m_hrZoneHigh[4] ) m_hrZoneHigh[4] = hr_zone->high_bpm;
                    }
                    break;
                }

                case FIT_MESG_NUM_POWER_ZONE:
                {
                    const FIT_POWER_ZONE_MESG *pwr_zone = (FIT_POWER_ZONE_MESG *) mesg;
                    if( pwr_zone->message_index < 8 ) m_pwrZoneHigh[pwr_zone->message_index] = pwr_zone->high_value;
                    else if( pwr_zone->message_index == 65535 ) //support for index-less format
                    {
                        if( !m_pwrZoneHigh[0] ) m_pwrZoneHigh[0] = pwr_zone->high_value;
                        else if( !m_pwrZoneHigh[1] ) m_pwrZoneHigh[1] = pwr_zone->high_value;
                        else if( !m_pwrZoneHigh[2] ) m_pwrZoneHigh[2] = pwr_zone->high_value;
                        else if( !m_pwrZoneHigh[3] ) m_pwrZoneHigh[3] = pwr_zone->high_value;
                        else if( !m_pwrZoneHigh[4] ) m_pwrZoneHigh[4] = pwr_zone->high_value;
                        else if( !m_pwrZoneHigh[5] ) m_pwrZoneHigh[5] = pwr_zone->high_value;
                        else if( !m_pwrZoneHigh[6] ) m_pwrZoneHigh[6] = pwr_zone->high_value;
                        else if( !m_pwrZoneHigh[7] ) m_pwrZoneHigh[7] = pwr_zone->high_value;
                    }
                    break;
                }

                case FIT_MESG_NUM_DEVELOPER_DATA_ID:
                {
                    //const FIT_DEVELOPER_DATA_ID_MESG *dev = (FIT_DEVELOPER_DATA_ID_MESG *) mesg;
                    //qDebug() << dev->application_version << dev->developer_data_index << dev->application_id << dev->developer_id << dev->manufacturer_id;
                    break;
                }

                case FIT_MESG_NUM_FIELD_DESCRIPTION:
                {
                    //const FIT_FIELD_DESCRIPTION_MESG *field = (FIT_FIELD_DESCRIPTION_MESG *) mesg;
                    /*qDebug() << field->field_name
                             << field->developer_data_index
                             << field->field_definition_number
                             << field->fit_base_type_id;*/
                    break;
                }

                case FIT_MESG_NUM_SEGMENT_LAP:
                {
                    break;
                }

                case FIT_MESG_NUM_MFG_RANGE_MIN:
                {
                    break;
                }

                default:
                    //printf("Unknown\n");
                    //qDebug() << "Unknown msg:" << mesg_num;
                    break;
                }
                break;
            }

            default:
                break;
            }
        } while (convert_return == FIT_CONVERT_MESSAGE_AVAILABLE);
    }

    if (convert_return == FIT_CONVERT_ERROR)
    {
        printf("Error decoding file.\n");
        fclose(file);
        return 1;
    }

    if (convert_return == FIT_CONVERT_CONTINUE)
    {
        printf("Unexpected end of file.\n");
        fclose(file);
        return 1;
    }

    if (convert_return == FIT_CONVERT_DATA_TYPE_NOT_SUPPORTED)
    {
        printf("File is not FIT.\n");
        fclose(file);
        return 1;
    }

    if (convert_return == FIT_CONVERT_PROTOCOL_VERSION_NOT_SUPPORTED)
    {
        printf("Protocol version not supported.\n");
        fclose(file);
        return 1;
    }

    //if (convert_return == FIT_CONVERT_END_OF_FILE)
    //    printf("File converted successfully.\n");

    fclose(file);

    if( minTemp < m_session.minTemperature ) m_session.minTemperature = minTemp;
    analysePowerCurve();

    return true;
}
