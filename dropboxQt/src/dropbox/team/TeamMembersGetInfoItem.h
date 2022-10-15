/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamTeamMemberInfo.h"

namespace dropboxQt{
namespace team{
    class MembersGetInfoItem{
        /**
            Describes a result obtained for a single user whose id was specified
            in the parameter of :meth:`members_get_info`.

            field: id_not_found: An ID that was provided as a parameter to
                :meth:`members_get_info`, and did not match a corresponding
                user. This might be a team_member_id, an email, or an external
                ID, depending on how the method was called.
            field: member_info: Info about a team member.
        */
    public:
        enum Tag{

        /*An ID that was provided as a parameter to :route:`members/get_info`, and did not match a corresponding user. This might be a team_member_id, an email, or an external ID, depending on how the method was called.*/
        MembersGetInfoItem_ID_NOT_FOUND,
        /*Info about a team member.*/
        MembersGetInfoItem_MEMBER_INFO
        };

        MembersGetInfoItem(){}
        MembersGetInfoItem(Tag v):m_tag(v){}
        virtual ~MembersGetInfoItem(){}

        Tag tag()const{return m_tag;}
        ///An ID that was provided as a parameter to :route:`members/get_info`, and did not match a corresponding user. This might be a team_member_id, an email, or an external ID, depending on how the method was called.
        QString getIdNotFound()const{API_CHECK_STATE((MembersGetInfoItem_ID_NOT_FOUND == m_tag), "expected tag: MembersGetInfoItem_ID_NOT_FOUND", m_tag);return m_id_not_found;};

        ///Info about a team member.
        const TeamMemberInfo& getMemberInfo()const{API_CHECK_STATE((MembersGetInfoItem_MEMBER_INFO == m_tag), "expected tag: MembersGetInfoItem_MEMBER_INFO", m_tag);return m_member_info;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<MembersGetInfoItem>  create(const QByteArray& data);
            static std::unique_ptr<MembersGetInfoItem>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        QString m_id_not_found;
        TeamMemberInfo m_member_info;
    };//MembersGetInfoItem

}//team
}//dropboxQt
