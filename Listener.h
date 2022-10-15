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

    double m_sessionTotalElapsedTime;
    double m_sessionTotalTimerTime;
    double m_sessionAvgSpeed;
    double m_sessionMaxSpeed;
    double m_sessionTotalDistance;
    double m_sessionAvgCadence;
    double m_sessionMaxCadence;
    double m_sessionAscent;
    double m_sessionDescent;
    double m_sessionAltitudeMax;
    double m_sessionAltitudeMin;
    double m_sessionAvgTemperature;
    double m_sessionMaxTemperature;
    double m_sessionMinTemperature;
    double m_sessionMaxGrade;
    double m_sessionMinGrade;
    quint32 m_sessionStartTime;
    bool m_altCorrectionDone;
    bool m_tempCorrectionDone;

    QVector<double>m_tourTimeStamp;
    QVector<double>m_tourDistance;
    QVector<double>m_tourSpeed;
    QVector<double>m_tourCadence;
    QVector<double>m_tourAltitude;
    QVector<double>m_tourTemperature;
    QVector<double>m_tourGrade;
    QVector<double>m_tourPosLat;
    QVector<double>m_tourPosLong;

    QVector<deviceInfo_t>m_deviceInfo;
};

#endif // LISTENER_H
