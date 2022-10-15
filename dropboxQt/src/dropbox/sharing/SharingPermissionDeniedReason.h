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
    class PermissionDeniedReason{
        /**
            Possible reasons the user is denied a permission.

            field: user_not_same_team_as_owner: User is not on the same team as
                the folder owner.
            field: user_not_allowed_by_owner: User is prohibited by the owner
                from taking the action.
            field: target_is_indirect_member: Target is indirectly a member of
                the folder, for example by being part of a group.
            field: target_is_owner: Target is the owner of the folder.
            field: target_is_self: Target is the user itself.
            field: target_not_active: Target is not an active member of the
                team.
            field: folder_is_limited_team_folder: Folder is team folder for a
                limited team.
        */
    public:
        enum Tag{

        /*User is not on the same team as the folder owner.*/
        PermissionDeniedReason_USER_NOT_SAME_TEAM_AS_OWNER,
        /*User is prohibited by the owner from taking the action.*/
        PermissionDeniedReason_USER_NOT_ALLOWED_BY_OWNER,
        /*Target is indirectly a member of the folder, for example by being part of a group.*/
        PermissionDeniedReason_TARGET_IS_INDIRECT_MEMBER,
        /*Target is the owner of the folder.*/
        PermissionDeniedReason_TARGET_IS_OWNER,
        /*Target is the user itself.*/
        PermissionDeniedReason_TARGET_IS_SELF,
        /*Target is not an active member of the team.*/
        PermissionDeniedReason_TARGET_NOT_ACTIVE,
        /*Folder is team folder for a limited team.*/
        PermissionDeniedReason_FOLDER_IS_LIMITED_TEAM_FOLDER,
        /*None*/
        PermissionDeniedReason_OTHER
        };

        PermissionDeniedReason(){}
        PermissionDeniedReason(Tag v):m_tag(v){}
        virtual ~PermissionDeniedReason(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<PermissionDeniedReason>  create(const QByteArray& data);
            static std::unique_ptr<PermissionDeniedReason>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//PermissionDeniedReason

}//sharing
}//dropboxQt
