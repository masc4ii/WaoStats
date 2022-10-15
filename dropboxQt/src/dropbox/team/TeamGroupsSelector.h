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
    class GroupsSelector{
        /**
            Argument for selecting a list of groups, either by group_ids, or
            external group IDs.

            field: group_ids: List of group IDs.
            field: group_external_ids: List of external IDs of groups.
        */
    public:
        enum Tag{

        /*List of group IDs.*/
        GroupsSelector_GROUP_IDS,
        /*List of external IDs of groups.*/
        GroupsSelector_GROUP_EXTERNAL_IDS
        };

        GroupsSelector(){}
        GroupsSelector(Tag v):m_tag(v){}
        virtual ~GroupsSelector(){}

        Tag tag()const{return m_tag;}
        ///List of group IDs.
        const std::list <QString>& getGroupIds()const{API_CHECK_STATE((GroupsSelector_GROUP_IDS == m_tag), "expected tag: GroupsSelector_GROUP_IDS", m_tag);return m_group_ids;};

        ///List of external IDs of groups.
        const std::list <QString>& getGroupExternalIds()const{API_CHECK_STATE((GroupsSelector_GROUP_EXTERNAL_IDS == m_tag), "expected tag: GroupsSelector_GROUP_EXTERNAL_IDS", m_tag);return m_group_external_ids;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GroupsSelector>  create(const QByteArray& data);
            static std::unique_ptr<GroupsSelector>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        std::list <QString> m_group_ids;
        std::list <QString> m_group_external_ids;
    };//GroupsSelector

}//team
}//dropboxQt
