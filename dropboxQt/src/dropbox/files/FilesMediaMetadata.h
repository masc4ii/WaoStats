/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesDimensions.h"
#include "dropbox/files/FilesGpsCoordinates.h"

namespace dropboxQt{
namespace files{
    class MediaMetadata{
        /**
            Metadata for a photo or video.

            field: dimensions: Dimension of the photo/video.
            field: location: The GPS coordinate of the photo/video.
            field: time_taken: The timestamp when the photo/video is taken.
        */

    public:
        MediaMetadata(){};

        MediaMetadata(const Dimensions& arg){ m_dimensions = arg; };
        virtual ~MediaMetadata(){};

    public:
            /**
                Dimension of the photo/video.
            */
        const Dimensions& dimensions()const{return m_dimensions;};
        MediaMetadata& setDimensions(const Dimensions& arg){m_dimensions=arg;return *this;};

            /**
                The GPS coordinate of the photo/video.
            */
        const GpsCoordinates& location()const{return m_location;};
        MediaMetadata& setLocation(const GpsCoordinates& arg){m_location=arg;return *this;};

            /**
                The timestamp when the photo/video is taken.
            */
        QDateTime timeTaken()const{return m_time_taken;};
        MediaMetadata& setTimetaken(const QDateTime& arg){m_time_taken=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<MediaMetadata>  create(const QByteArray& data);
            static std::unique_ptr<MediaMetadata>  create(const QJsonObject& js);
        };



    protected:
            /**
                Dimension of the photo/video.
            */
        Dimensions m_dimensions;

            /**
                The GPS coordinate of the photo/video.
            */
        GpsCoordinates m_location;

            /**
                The timestamp when the photo/video is taken.
            */
        QDateTime m_time_taken;

    };//MediaMetadata

}//files
}//dropboxQt
