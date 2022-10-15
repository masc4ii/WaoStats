/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamGroupFullInfo.h"

namespace dropboxQt{
namespace team{
    class GroupsGetInfoItem{
        /**
            field: id_not_found: An ID that was provided as a parameter to
                :meth:`groups_get_info`, and did not match a corresponding
                group. The ID can be a group ID, or an external ID, depending on
                how the method was called.
            field: group_info: Info about a group.
        */
    public:
        enum Tag{

        /*An ID that was provided as a parameter to :route:`groups/get_info`, and did not match a corresponding group. The ID can be a group ID, or an external ID, depending on how the method was called.*/
        GroupsGetInfoItem_ID_NOT_FOUND,
        /*Info about a group.*/
        GroupsGetInfoItem_GROUP_INFO
        };

        GroupsGetInfoItem(){}
        GroupsGetInfoItem(Tag v):m_tag(v){}
        virtual ~GroupsGetInfoItem(){}

        Tag tag()const{return m_tag;}
        ///An ID that was provided as a parameter to :route:`groups/get_info`, and did not match a corresponding group. The ID can be a group ID, or an external ID, depending on how the method was called.
        QString getIdNotFound()const{API_CHECK_STATE((GroupsGetInfoItem_ID_NOT_FOUND == m_tag), "expected tag: GroupsGetInfoItem_ID_NOT_FOUND", m_tag);return m_id_not_found;};

        ///Info about a group.
        const GroupFullInfo& getGroupInfo()const{API_CHECK_STATE((GroupsGetInfoItem_GROUP_INFO == m_tag), "expected tag: GroupsGetInfoItem_GROUP_INFO", m_tag);return m_group_info;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GroupsGetInfoItem>  create(const QByteArray& data);
            static std::unique_ptr<GroupsGetInfoItem>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        QString m_id_not_found;
        GroupFullInfo m_group_info;
    };//GroupsGetInfoItem

}//team
}//dropboxQt
