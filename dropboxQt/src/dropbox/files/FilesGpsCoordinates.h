/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"

namespace dropboxQt{
namespace files{
    class GpsCoordinates{
        /**
            GPS coordinates for a photo or video.

            field: latitude: Latitude of the GPS coordinates.
            field: longitude: Longitude of the GPS coordinates.
        */

    public:
        GpsCoordinates(){};

        GpsCoordinates(const float& arg){ m_latitude = arg; };
        virtual ~GpsCoordinates(){};

    public:
            /**
                Latitude of the GPS coordinates.
            */
        float latitude()const{return m_latitude;};
        GpsCoordinates& setLatitude(const float& arg){m_latitude=arg;return *this;};

            /**
                Longitude of the GPS coordinates.
            */
        float longitude()const{return m_longitude;};
        GpsCoordinates& setLongitude(const float& arg){m_longitude=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GpsCoordinates>  create(const QByteArray& data);
            static std::unique_ptr<GpsCoordinates>  create(const QJsonObject& js);
        };



    protected:
            /**
                Latitude of the GPS coordinates.
            */
        float m_latitude;

            /**
                Longitude of the GPS coordinates.
            */
        float m_longitude;

    };//GpsCoordinates

}//files
}//dropboxQt
