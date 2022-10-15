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
    class RevokeLinkedApiAppArg{
        /**
            field: app_id: The application's unique id
            field: team_member_id: The unique id of the member owning the device
            field: keep_app_folder: Whether to keep the application dedicated
                folder (in case the application uses  one)
        */

    public:
        RevokeLinkedApiAppArg():
        m_keep_app_folder(false)
        {};

        RevokeLinkedApiAppArg(const QString& arg):
        m_keep_app_folder(false)
        { m_app_id = arg; };
        virtual ~RevokeLinkedApiAppArg(){};

    public:
            /**
                The application's unique id
            */
        QString appId()const{return m_app_id;};
        RevokeLinkedApiAppArg& setAppid(const QString& arg){m_app_id=arg;return *this;};

            /**
                The unique id of the member owning the device
            */
        QString teamMemberId()const{return m_team_member_id;};
        RevokeLinkedApiAppArg& setTeammemberid(const QString& arg){m_team_member_id=arg;return *this;};

            /**
                Whether to keep the application dedicated folder (in case the
                application uses  one)
            */
        bool keepAppFolder()const{return m_keep_app_folder;};
        RevokeLinkedApiAppArg& setKeepappfolder(const bool& arg){m_keep_app_folder=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<RevokeLinkedApiAppArg>  create(const QByteArray& data);
            static std::unique_ptr<RevokeLinkedApiAppArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                The application's unique id
            */
        QString m_app_id;

            /**
                The unique id of the member owning the device
            */
        QString m_team_member_id;

            /**
                Whether to keep the application dedicated folder (in case the
                application uses  one)
            */
        bool m_keep_app_folder;

    };//RevokeLinkedApiAppArg

}//team
}//dropboxQt
