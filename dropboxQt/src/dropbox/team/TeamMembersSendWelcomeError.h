/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamMemberSelectorError.h"

namespace dropboxQt{
namespace team{
    class MembersSendWelcomeError{
    public:
        enum Tag{

        /*No matching user found. The provided team_member_id, email, or external_id does not exist on this team.*/
        UserSelectorError_USER_NOT_FOUND,
        /*The user is not a member of the team.*/
        MemberSelectorError_USER_NOT_IN_TEAM,
        /*None*/
        MembersSendWelcomeError_OTHER
        };

        MembersSendWelcomeError(){}
        MembersSendWelcomeError(Tag v):m_tag(v){}
        virtual ~MembersSendWelcomeError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<MembersSendWelcomeError>  create(const QByteArray& data);
            static std::unique_ptr<MembersSendWelcomeError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//MembersSendWelcomeError

}//team
}//dropboxQt
