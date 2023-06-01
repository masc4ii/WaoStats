#include "FitParser.h"
#include "FitSDKRelease_21.105.00/c/fit_convert.h"
#include <QDebug>

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
    FIT_UINT32 mesg_index = 0;

    FitConvert_Init(FIT_TRUE);

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
                    const FIT_FILE_ID_MESG *id = (FIT_FILE_ID_MESG *) mesg;
                    //printf("File ID: type=%u, number=%u\n", id->type, id->number);
                    break;
                }

                case FIT_MESG_NUM_USER_PROFILE:
                {
                    const FIT_USER_PROFILE_MESG *user_profile = (FIT_USER_PROFILE_MESG *) mesg;
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

                    m_session.avgCadence = session->avg_cadence;
                    m_session.maxCadence = session->max_cadence;

                    m_session.ascent = session->total_ascent;
                    m_session.descent = session->total_descent;
                    m_session.altitudeMax = session->max_altitude / 5 - 500;
                    m_session.altitudeMin = session->min_altitude / 5 - 500;
                    m_session.minGrade = session->max_neg_grade / 100.0; //wrong!
                    m_session.maxGrade = session->max_pos_grade / 100.0; //wrong!

                    m_session.avgTemperature = session->avg_temperature;
                    m_session.minTemperature = session->min_temperature;
                    m_session.maxTemperature = session->max_temperature; //wrong!

                    m_session.minHeartRate = session->min_heart_rate;
                    m_session.avgHeartRate = session->avg_heart_rate;
                    m_session.maxHeartRate = session->max_heart_rate;

                    //m_session.hrTimeInZone[5];
                    m_session.avgPower = session->avg_power;
                    m_session.maxPower = session->max_power;
                    m_session.leftRightBalance = session->left_right_balance;
                    m_session.totalWork = session->total_work;
                    m_session.totalCalories = session->total_calories;
                    m_session.normalizedPower = session->normalized_power;
                    m_session.thresholdPower = session->threshold_power;
                    m_session.trainingStressScore = session->training_stress_score;
                    m_session.itensityFactor = session->intensity_factor;
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

                    lap.avgSpeed = lapMesg->avg_speed / 1000.0;
                    lap.maxSpeed = lapMesg->max_speed / 1000.0;

                    lap.avgCadence = lapMesg->avg_cadence;
                    lap.maxCadence = lapMesg->max_cadence;

                    lap.ascent = lapMesg->total_ascent;
                    lap.descent = lapMesg->total_descent;
                    lap.altitudeMax = lapMesg->max_altitude / 5 - 500;
                    lap.altitudeMin = lapMesg->min_altitude / 5 - 500;
                    lap.minGrade = lapMesg->max_neg_grade / 100.0; //wrong!
                    lap.maxGrade = lapMesg->max_pos_grade / 100.0; //wrong!

                    lap.avgTemperature = lapMesg->avg_temperature;
                    lap.minTemperature = lapMesg->min_temperature;
                    lap.maxTemperature = lapMesg->max_temperature; //wrong!

                    lap.minHeartRate = lapMesg->min_heart_rate;
                    lap.avgHeartRate = lapMesg->avg_heart_rate;
                    lap.maxHeartRate = lapMesg->max_heart_rate;

                    //lap.hrTimeInZone[5];
                    lap.avgPower = lapMesg->avg_power;
                    lap.maxPower = lapMesg->max_power;
                    lap.leftRightBalance = lapMesg->left_right_balance;
                    lap.totalWork = lapMesg->total_work;
                    lap.totalCalories = lapMesg->total_calories;
                    lap.normalizedPower = lapMesg->normalized_power;
                    m_sections.append( lap );
                    break;
                }

                case FIT_MESG_NUM_RECORD:
                {
                    const FIT_RECORD_MESG *record = (FIT_RECORD_MESG *) mesg;
                    m_tourTimeStamp.append( record->timestamp );
                    m_tourPosLat.append( record->position_lat );
                    m_tourPosLong.append( record->position_long );
                    m_tourDistance.append( record->distance );
                    //m_tourBatterySoc.append(  );
                    m_tourSpeed.append( record->speed * 0.0036 );
                    m_tourCadence.append( record->cadence );
                    m_tourAltitude.append( record->altitude / 5 - 500 );
                    m_tourGpsAccuracy.append( record->gps_accuracy );
                    m_tourTemperature.append( record->temperature );
                    m_tourGrade.append( record->grade / 100.0 );
                    m_tourHeartRate.append( record->heart_rate );
                    m_tourCalories.append( record->calories );
                    m_tourPower.append( record->power );
                    m_tourLRBalance.append( record->left_right_balance );

                    /*if( !m_firstPosRead && record->position_lat != 2147483647 && record->position_long != 2147483647 )
                    {
                        m_firstPosRead = true;
                        for( int i = 0; i < m_tourPosLat.count(); i++ )
                        {
                            m_tourPosLat[i] = record->position_lat;
                            m_tourPosLong[i] = record->position_long;
                        }
                    }*/

                    break;
                }

                case FIT_MESG_NUM_EVENT:
                {
                    const FIT_EVENT_MESG *event = (FIT_EVENT_MESG *) mesg;
                    //printf("Event: timestamp=%u\n", event->timestamp);
                    break;
                }

                case FIT_MESG_NUM_DEVICE_INFO:
                {
                    const FIT_DEVICE_INFO_MESG *device_info = (FIT_DEVICE_INFO_MESG *) mesg;
                    //printf("Device Info: timestamp=%u\n", device_info->timestamp);
                    break;
                }

                default:
                    //printf("Unknown\n");
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

    return true;
}
