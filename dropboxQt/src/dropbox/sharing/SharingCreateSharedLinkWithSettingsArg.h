/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingSharedLinkSettings.h"

namespace dropboxQt{
namespace sharing{
    class CreateSharedLinkWithSettingsArg{
        /**
            field: path: The path to be shared by the shared link
            field: settings: The requested settings for the newly created shared
                link
        */

    public:
        CreateSharedLinkWithSettingsArg(){};

        CreateSharedLinkWithSettingsArg(const QString& arg){ m_path = arg; };
        virtual ~CreateSharedLinkWithSettingsArg(){};

    public:
            /**
                The path to be shared by the shared link
            */
        QString path()const{return m_path;};
        CreateSharedLinkWithSettingsArg& setPath(const QString& arg){m_path=arg;return *this;};

            /**
                The requested settings for the newly created shared link
            */
        const SharedLinkSettings& settings()const{return m_settings;};
        CreateSharedLinkWithSettingsArg& setSettings(const SharedLinkSettings& arg){m_settings=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<CreateSharedLinkWithSettingsArg>  create(const QByteArray& data);
            static std::unique_ptr<CreateSharedLinkWithSettingsArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                The path to be shared by the shared link
            */
        QString m_path;

            /**
                The requested settings for the newly created shared link
            */
        SharedLinkSettings m_settings;

    };//CreateSharedLinkWithSettingsArg

}//sharing
}//dropboxQt
