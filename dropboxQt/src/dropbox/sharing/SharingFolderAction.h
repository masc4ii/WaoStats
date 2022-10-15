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
    class FolderAction{
        /**
            Actions that may be taken on shared folders.

            field: change_options: Change folder options, such as who can be
                invited to join the folder.
            field: edit_contents: Change or edit contents of the folder.
            field: invite_editor: Invite a user or group to join the folder with
                read and write permission.
            field: invite_viewer: Invite a user or group to join the folder with
                read permission.
            field: invite_viewer_no_comment: Invite a user or group to join the
                folder with read permission but no comment permissions.
            field: relinquish_membership: Relinquish one's own membership in the
                folder.
            field: unmount: Unmount the folder.
            field: unshare: Stop sharing this folder.
            field: leave_a_copy: Keep a copy of the contents upon leaving or
                being kicked from the folder.
            field: share_link: This action is deprecated. Use create_link
                instead.
            field: create_link: Create a shared link for folder.
        */
    public:
        enum Tag{

        /*Change folder options, such as who can be invited to join the folder.*/
        FolderAction_CHANGE_OPTIONS,
        /*Change or edit contents of the folder.*/
        FolderAction_EDIT_CONTENTS,
        /*Invite a user or group to join the folder with read and write permission.*/
        FolderAction_INVITE_EDITOR,
        /*Invite a user or group to join the folder with read permission.*/
        FolderAction_INVITE_VIEWER,
        /*Invite a user or group to join the folder with read permission but no comment permissions.*/
        FolderAction_INVITE_VIEWER_NO_COMMENT,
        /*Relinquish one's own membership in the folder.*/
        FolderAction_RELINQUISH_MEMBERSHIP,
        /*Unmount the folder.*/
        FolderAction_UNMOUNT,
        /*Stop sharing this folder.*/
        FolderAction_UNSHARE,
        /*Keep a copy of the contents upon leaving or being kicked from the folder.*/
        FolderAction_LEAVE_A_COPY,
        /*This action is deprecated. Use create_link instead.*/
        FolderAction_SHARE_LINK,
        /*Create a shared link for folder.*/
        FolderAction_CREATE_LINK,
        /*None*/
        FolderAction_OTHER
        };

        FolderAction(){}
        FolderAction(Tag v):m_tag(v){}
        virtual ~FolderAction(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<FolderAction>  create(const QByteArray& data);
            static std::unique_ptr<FolderAction>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//FolderAction

}//sharing
}//dropboxQt
