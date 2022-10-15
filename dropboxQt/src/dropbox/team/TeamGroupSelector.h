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
    class GroupSelector{
        /**
            Argument for selecting a single group, either by group_id or by
            external group ID.

            field: group_id: Group ID.
            field: group_external_id: External ID of the group.
        */
    public:
        enum Tag{

        /*Group ID.*/
        GroupSelector_GROUP_ID,
        /*External ID of the group.*/
        GroupSelector_GROUP_EXTERNAL_ID
        };

        GroupSelector(){}
        GroupSelector(Tag v):m_tag(v){}
        virtual ~GroupSelector(){}

        Tag tag()const{return m_tag;}
        ///Group ID.
        QString getGroupId()const{API_CHECK_STATE((GroupSelector_GROUP_ID == m_tag), "expected tag: GroupSelector_GROUP_ID", m_tag);return m_group_id;};

        ///External ID of the group.
        QString getGroupExternalId()const{API_CHECK_STATE((GroupSelector_GROUP_EXTERNAL_ID == m_tag), "expected tag: GroupSelector_GROUP_EXTERNAL_ID", m_tag);return m_group_external_id;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GroupSelector>  create(const QByteArray& data);
            static std::unique_ptr<GroupSelector>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        QString m_group_id;
        QString m_group_external_id;
    };//GroupSelector

}//team
}//dropboxQt
