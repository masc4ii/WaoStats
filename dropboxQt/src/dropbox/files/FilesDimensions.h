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
    class Dimensions{
        /**
            Dimensions for a photo or video.

            field: height: Height of the photo/video.
            field: width: Width of the photo/video.
        */

    public:
        Dimensions(){};

        Dimensions(const int& arg){ m_height = arg; };
        virtual ~Dimensions(){};

    public:
            /**
                Height of the photo/video.
            */
        int height()const{return m_height;};
        Dimensions& setHeight(const int& arg){m_height=arg;return *this;};

            /**
                Width of the photo/video.
            */
        int width()const{return m_width;};
        Dimensions& setWidth(const int& arg){m_width=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<Dimensions>  create(const QByteArray& data);
            static std::unique_ptr<Dimensions>  create(const QJsonObject& js);
        };



    protected:
            /**
                Height of the photo/video.
            */
        int m_height = {0};

            /**
                Width of the photo/video.
            */
        int m_width = {0};

    };//Dimensions

}//files
}//dropboxQt
