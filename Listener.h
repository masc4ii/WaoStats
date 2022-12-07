#ifndef LISTENER_H
#define LISTENER_H

#include "fit_decode.hpp"
#include "fit_mesg_broadcaster.hpp"
#include "fit_developer_field_description.hpp"

#include <fstream>
#include <iostream>
#include <QString>
#include <QVector>

class Listener
        : public fit::FileIdMesgListener
        , public fit::MesgListener
        , public fit::DeveloperFieldDescriptionListener
{
public:
    Listener();
    void reset( void );

    static void PrintValues(const fit::FieldBase& field);
    void OnMesg(fit::Mesg& mesg);
    void OnMesg(fit::FileIdMesg& mesg);
    void OnDeveloperFieldDescription( const fit::DeveloperFieldDescription& desc ) override { return; }

    typedef struct{
        QString name;
        QString battery;
        QString software;
        int deviceId;
    } deviceInfo_t;
    bool deviceIdIsIncluded( deviceInfo_t a );
    int deviceIdInVectorAt( deviceInfo_t a );

    typedef struct{
        double totalElapsedTime;
        double totalTimerTime;
        double avgSpeed;
        double maxSpeed;
        double totalDistance;
        double avgCadence;
        double maxCadence;
        double ascent;
        double descent;
        double altitudeMax;
        double altitudeMin;
        double avgTemperature;
        double maxTemperature;
        double minTemperature;
        double maxGrade;
        double minGrade;
        quint32 startTime;
        double startDistance;
        double minHeartRate;
        double avgHeartRate;
        double maxHeartRate;
        double avgPower;
        double maxPower;
        double leftRightBalance;
        double totalWork;
        double totalCalories;
        double normalizedPower;
        double thresholdPower;
        double trainingStressScore;
        double itensityFactor;
    } fitSection_t;

    fitSection_t getSession(){return m_session;}
    QVector<fitSection_t> getSections(){return m_sections;}
    QVector<double>getTourTimeStamp(){return m_tourTimeStamp;}
    QVector<double>getTourDistance(){return m_tourDistance;}
    QVector<double>getTourBatterySoc(){return m_tourBatterySoc;}
    QVector<double>getTourSpeed(){return m_tourSpeed;}
    QVector<double>getTourCadence(){return m_tourCadence;}
    QVector<double>getTourAltitude(){return m_tourAltitude;}
    QVector<double>getTourTemperature(){return m_tourTemperature;}
    QVector<double>getTourGrade(){return m_tourGrade;}
    QVector<double>getTourPosLat(){return m_tourPosLat;}
    QVector<double>getTourPosLong(){return m_tourPosLong;}
    QVector<double>getTourHeartRate(){return m_tourHeartRate;}
    QVector<double>getTourCalories(){return m_tourCalories;}
    QVector<double>getTourPower(){return m_tourPower;}
    QVector<double>getTourLRBalance(){return m_tourLRBalance;}
    QVector<deviceInfo_t>getDeviceInfo(){return m_deviceInfo;}

    bool containsPositionInfo( void ){return m_posRead;}

private:
    fitSection_t m_session;
    QVector<fitSection_t> m_sections;
    bool m_altCorrectionDone;
    bool m_posCorrectionDone;
    bool m_firstPosRead;
    bool m_posRead;
    bool m_tempCorrectionDone;

    QVector<double>m_tourTimeStamp;
    QVector<double>m_tourDistance;
    QVector<double>m_tourBatterySoc;
    QVector<double>m_tourSpeed;
    QVector<double>m_tourCadence;
    QVector<double>m_tourAltitude;
    QVector<double>m_tourTemperature;
    QVector<double>m_tourGrade;
    QVector<double>m_tourPosLat;
    QVector<double>m_tourPosLong;
    QVector<double>m_tourHeartRate;
    QVector<double>m_tourCalories;
    QVector<double>m_tourPower;
    QVector<double>m_tourLRBalance;

    QVector<deviceInfo_t>m_deviceInfo;
};

#endif // LISTENER_H
