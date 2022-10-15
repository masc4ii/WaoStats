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
    class ThumbnailSize{
        /**
            field: w32h32: 32 by 32 px.
            field: w64h64: 64 by 64 px.
            field: w128h128: 128 by 128 px.
            field: w640h480: 640 by 480 px.
            field: w1024h768: 1024 by 768
        */
    public:
        enum Tag{

        /*32 by 32 px.*/
        ThumbnailSize_W32H32,
        /*64 by 64 px.*/
        ThumbnailSize_W64H64,
        /*128 by 128 px.*/
        ThumbnailSize_W128H128,
        /*640 by 480 px.*/
        ThumbnailSize_W640H480,
        /*1024 by 768*/
        ThumbnailSize_W1024H768
        };

        ThumbnailSize(){}
        ThumbnailSize(Tag v):m_tag(v){}
        virtual ~ThumbnailSize(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ThumbnailSize>  create(const QByteArray& data);
            static std::unique_ptr<ThumbnailSize>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//ThumbnailSize

}//files
}//dropboxQt
