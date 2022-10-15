/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingFileAction.h"

namespace dropboxQt{
namespace sharing{
    class ListFilesArg{
        /**
            Arguments for :meth:`list_received_files`.

            field: limit: Number of files to return max per query. Defaults to
                100 if no limit is specified.
            field: actions: File actions to query.
        */

    public:
        ListFilesArg():
        m_limit(100)
        {};

        ListFilesArg(const int& arg):
        m_limit(100)
        { m_limit = arg; };
        virtual ~ListFilesArg(){};

    public:
            /**
                Number of files to return max per query. Defaults to 100 if no
                limit is specified.
            */
        int limit()const{return m_limit;};
        ListFilesArg& setLimit(const int& arg){m_limit=arg;return *this;};

            /**
                File actions to query.
            */
        const std::list <FileAction>& actions()const{return m_actions;};
        ListFilesArg& setActions(const std::list <FileAction>& arg){m_actions=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListFilesArg>  create(const QByteArray& data);
            static std::unique_ptr<ListFilesArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                Number of files to return max per query. Defaults to 100 if no
                limit is specified.
            */
        int m_limit = {0};

            /**
                File actions to query.
            */
        std::list <FileAction> m_actions;

    };//ListFilesArg

}//sharing
}//dropboxQt
