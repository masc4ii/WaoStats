/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamRevokeLinkedApiAppArg.h"

namespace dropboxQt{
namespace team{
    class RevokeLinkedApiAppBatchArg{

    public:
        RevokeLinkedApiAppBatchArg(){};

        RevokeLinkedApiAppBatchArg(const std::list <RevokeLinkedApiAppArg>& arg){ m_revoke_linked_app = arg; };
        virtual ~RevokeLinkedApiAppBatchArg(){};

    public:
        const std::list <RevokeLinkedApiAppArg>& revokeLinkedApp()const{return m_revoke_linked_app;};
        RevokeLinkedApiAppBatchArg& setRevokelinkedapp(const std::list <RevokeLinkedApiAppArg>& arg){m_revoke_linked_app=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<RevokeLinkedApiAppBatchArg>  create(const QByteArray& data);
            static std::unique_ptr<RevokeLinkedApiAppBatchArg>  create(const QJsonObject& js);
        };



    protected:
        std::list <RevokeLinkedApiAppArg> m_revoke_linked_app;

    };//RevokeLinkedApiAppBatchArg

}//team
}//dropboxQt
