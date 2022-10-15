/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"

namespace dropboxQt{
namespace sharing{
    class MemberSelector{
        /**
            Includes different ways to identify a member of a shared folder.

            field: dropbox_id: Dropbox account, team member, or group ID of
                member.
            field: email: E-mail address of member.
        */
    public:
        enum Tag{

        /*Dropbox account, team member, or group ID of member.*/
        MemberSelector_DROPBOX_ID,
        /*E-mail address of member.*/
        MemberSelector_EMAIL,
        /*None*/
        MemberSelector_OTHER
        };

        MemberSelector(){}
        MemberSelector(Tag v):m_tag(v){}
        virtual ~MemberSelector(){}

        Tag tag()const{return m_tag;}
        ///Dropbox account, team member, or group ID of member.
        QString getDropboxId()const{API_CHECK_STATE((MemberSelector_DROPBOX_ID == m_tag), "expected tag: MemberSelector_DROPBOX_ID", m_tag);return m_dropbox_id;};

        ///E-mail address of member.
        QString getEmail()const{API_CHECK_STATE((MemberSelector_EMAIL == m_tag), "expected tag: MemberSelector_EMAIL", m_tag);return m_email;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<MemberSelector>  create(const QByteArray& data);
            static std::unique_ptr<MemberSelector>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        QString m_dropbox_id;
        QString m_email;
    };//MemberSelector

}//sharing
}//dropboxQt
