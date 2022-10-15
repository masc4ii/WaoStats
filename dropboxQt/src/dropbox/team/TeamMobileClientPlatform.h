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
    class MobileClientPlatform{
        /**
            field: iphone: Official Dropbox iPhone client
            field: ipad: Official Dropbox iPad client
            field: android: Official Dropbox Android client
            field: windows_phone: Official Dropbox Windows phone client
            field: blackberry: Official Dropbox Blackberry client
        */
    public:
        enum Tag{

        /*Official Dropbox iPhone client*/
        MobileClientPlatform_IPHONE,
        /*Official Dropbox iPad client*/
        MobileClientPlatform_IPAD,
        /*Official Dropbox Android client*/
        MobileClientPlatform_ANDROID,
        /*Official Dropbox Windows phone client*/
        MobileClientPlatform_WINDOWS_PHONE,
        /*Official Dropbox Blackberry client*/
        MobileClientPlatform_BLACKBERRY,
        /*None*/
        MobileClientPlatform_OTHER
        };

        MobileClientPlatform(){}
        MobileClientPlatform(Tag v):m_tag(v){}
        virtual ~MobileClientPlatform(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<MobileClientPlatform>  create(const QByteArray& data);
            static std::unique_ptr<MobileClientPlatform>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//MobileClientPlatform

}//team
}//dropboxQt
