/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingFolderAction.h"

namespace dropboxQt{
namespace sharing{
    class ListFoldersArgs{
        /**
            field: limit: The maximum number of results to return per request.
            field: actions: This is a list indicating whether each returned
                folder data entry will include a boolean field
                ``FolderPermission.allow`` that describes whether the current
                user can perform the `FolderAction` on the folder.
        */

    public:
        ListFoldersArgs():
        m_limit(1000)
        {};

        ListFoldersArgs(const int& arg):
        m_limit(1000)
        { m_limit = arg; };
        virtual ~ListFoldersArgs(){};

    public:
            /**
                The maximum number of results to return per request.
            */
        int limit()const{return m_limit;};
        ListFoldersArgs& setLimit(const int& arg){m_limit=arg;return *this;};

            /**
                This is a list indicating whether each returned folder data
                entry will include a boolean field ``FolderPermission.allow``
                that describes whether the current user can perform the
                `FolderAction` on the folder.
            */
        const std::list <FolderAction>& actions()const{return m_actions;};
        ListFoldersArgs& setActions(const std::list <FolderAction>& arg){m_actions=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListFoldersArgs>  create(const QByteArray& data);
            static std::unique_ptr<ListFoldersArgs>  create(const QJsonObject& js);
        };



    protected:
            /**
                The maximum number of results to return per request.
            */
        int m_limit = {0};

            /**
                This is a list indicating whether each returned folder data
                entry will include a boolean field ``FolderPermission.allow``
                that describes whether the current user can perform the
                `FolderAction` on the folder.
            */
        std::list <FolderAction> m_actions;

    };//ListFoldersArgs

}//sharing
}//dropboxQt
