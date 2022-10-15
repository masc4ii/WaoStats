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
    class AccessLevel{
        /**
            Defines the access levels for collaborators.

            field: owner: The collaborator is the owner of the shared folder.
                Owners can view and edit the shared folder as well as set the
                folder's policies using :meth:`update_folder_policy`.
            field: editor: The collaborator can both view and edit the shared
                folder.
            field: viewer: The collaborator can only view the shared folder.
            field: viewer_no_comment: The collaborator can only view the shared
                folder and does not have any access to comments.
        */
    public:
        enum Tag{

        /*The collaborator is the owner of the shared folder. Owners can view and edit the shared folder as well as set the folder's policies using :route:`update_folder_policy`.*/
        AccessLevel_OWNER,
        /*The collaborator can both view and edit the shared folder.*/
        AccessLevel_EDITOR,
        /*The collaborator can only view the shared folder.*/
        AccessLevel_VIEWER,
        /*The collaborator can only view the shared folder and does not have any access to comments.*/
        AccessLevel_VIEWER_NO_COMMENT,
        /*None*/
        AccessLevel_OTHER
        };

        AccessLevel(){}
        AccessLevel(Tag v):m_tag(v){}
        virtual ~AccessLevel(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<AccessLevel>  create(const QByteArray& data);
            static std::unique_ptr<AccessLevel>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//AccessLevel

}//sharing
}//dropboxQt
