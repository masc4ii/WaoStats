#ifndef TOURDATA_H
#define TOURDATA_H

#include <QString>
#include <QVector>

class TourData
{
public:
    TourData();
    void reset( void );

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
        double hrTimeInZone[5];
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
    QVector<double>getTourGpsAccuracy(){return m_tourGpsAccuracy;}
    QVector<double>getTourTemperature(){return m_tourTemperature;}
    QVector<double>getTourGrade(){return m_tourGrade;}
    QVector<double>getTourPosLat(){return m_tourPosLat;}
    QVector<double>getTourPosLong(){return m_tourPosLong;}
    QVector<double>getTourHeartRate(){return m_tourHeartRate;}
    QVector<double>getTourCalories(){return m_tourCalories;}
    QVector<double>getTourPower(){return m_tourPower;}
    QVector<double>getTourLRBalance(){return m_tourLRBalance;}
    QVector<deviceInfo_t>getDeviceInfo(){return m_deviceInfo;}

    QVector<double>getGearTimeStamp(){return m_gearTimeStamp;}
    QVector<double>getGearDistance(){return m_gearDistance;}
    QVector<double>getGearNumFront(){return m_gearNumFront;}
    QVector<double>getGearToothFront(){return m_gearToothFront;}
    QVector<double>getGearNumRear(){return m_gearNumRear;}
    QVector<double>getGearToothRear(){return m_gearToothRear;}
    QVector<double>getGearRatio(){return m_gearRatio;}

    bool containsPositionInfo( void ){return m_posRead;}
    bool containsGearInfoRear( void ){return m_gearInfoRear;}
    bool containsGearInfoFront( void ){return m_gearInfoFront;}
    uint8_t gearCountFront( void ){return m_gearCountFront;}
    uint8_t gearCountRear( void ){return m_gearCountRear;}

    quint16* getHrZoneHigh( void ){return m_hrZoneHigh;}

protected:
    fitSection_t m_session;
    QVector<fitSection_t> m_sections;
    bool m_altCorrectionDone;
    bool m_posCorrectionDone;
    bool m_firstPosRead;
    bool m_posRead;
    bool m_tempCorrectionDone;
    bool m_battCorrectionDone;
    bool m_gearInfoRear;
    bool m_gearInfoFront;
    uint8_t m_gearCountFront;
    uint8_t m_gearCountRear;

    QVector<double>m_gearTimeStamp;
    QVector<double>m_gearDistance;
    QVector<double>m_gearNumFront;
    QVector<double>m_gearToothFront;
    QVector<double>m_gearNumRear;
    QVector<double>m_gearToothRear;
    QVector<double>m_gearRatio;

    QVector<double>m_tourTimeStamp;
    QVector<double>m_tourDistance;
    QVector<double>m_tourBatterySoc;
    QVector<double>m_tourSpeed;
    QVector<double>m_tourCadence;
    QVector<double>m_tourAltitude;
    QVector<double>m_tourGpsAccuracy;
    QVector<double>m_tourTemperature;
    QVector<double>m_tourGrade;
    QVector<double>m_tourPosLat;
    QVector<double>m_tourPosLong;
    QVector<double>m_tourHeartRate;
    QVector<double>m_tourCalories;
    QVector<double>m_tourPower;
    QVector<double>m_tourLRBalance;

    QVector<deviceInfo_t>m_deviceInfo;

    quint16 m_hrZoneHigh[5];
};

#endif // TOURDATA_H
