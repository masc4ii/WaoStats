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
    class MemberAction{
        /**
            Actions that may be taken on members of a shared folder.

            field: leave_a_copy: Allow the member to keep a copy of the folder
                when removing.
            field: make_editor: Make the member an editor of the folder.
            field: make_owner: Make the member an owner of the folder.
            field: make_viewer: Make the member a viewer of the folder.
            field: make_viewer_no_comment: Make the member a viewer of the
                folder without commenting permissions.
            field: remove: Remove the member from the folder.
        */
    public:
        enum Tag{

        /*Allow the member to keep a copy of the folder when removing.*/
        MemberAction_LEAVE_A_COPY,
        /*Make the member an editor of the folder.*/
        MemberAction_MAKE_EDITOR,
        /*Make the member an owner of the folder.*/
        MemberAction_MAKE_OWNER,
        /*Make the member a viewer of the folder.*/
        MemberAction_MAKE_VIEWER,
        /*Make the member a viewer of the folder without commenting permissions.*/
        MemberAction_MAKE_VIEWER_NO_COMMENT,
        /*Remove the member from the folder.*/
        MemberAction_REMOVE,
        /*None*/
        MemberAction_OTHER
        };

        MemberAction(){}
        MemberAction(Tag v):m_tag(v){}
        virtual ~MemberAction(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<MemberAction>  create(const QByteArray& data);
            static std::unique_ptr<MemberAction>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//MemberAction

}//sharing
}//dropboxQt
