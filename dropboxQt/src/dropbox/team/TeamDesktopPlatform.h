/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"

namespace dropboxQt{
namespace team{
    class DesktopPlatform{
        /**
            field: windows: Official Windows Dropbox desktop client
            field: mac: Official Mac Dropbox desktop client
            field: linux: Official Linux Dropbox desktop client
        */
    public:
        enum Tag{

        /*Official Windows Dropbox desktop client*/
        DesktopPlatform_WINDOWS,
        /*Official Mac Dropbox desktop client*/
        DesktopPlatform_MAC,
        /*Official Linux Dropbox desktop client*/
        DesktopPlatform_LINUX,
        /*None*/
        DesktopPlatform_OTHER
        };

        DesktopPlatform(){}
        DesktopPlatform(Tag v):m_tag(v){}
        virtual ~DesktopPlatform(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<DesktopPlatform>  create(const QByteArray& data);
            static std::unique_ptr<DesktopPlatform>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//DesktopPlatform

}//team
}//dropboxQt
