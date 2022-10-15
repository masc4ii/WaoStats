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
    class GetFileMetadataBatchArg{
        /**
            Arguments of :meth:`get_file_metadata_batch`

            field: files: The files to query.
            field: actions: File actions to query.
        */

    public:
        GetFileMetadataBatchArg(){};

        GetFileMetadataBatchArg(const std::list <QString>& arg){ m_files = arg; };
        virtual ~GetFileMetadataBatchArg(){};

    public:
            /**
                The files to query.
            */
        const std::list <QString>& files()const{return m_files;};
        GetFileMetadataBatchArg& setFiles(const std::list <QString>& arg){m_files=arg;return *this;};

            /**
                File actions to query.
            */
        const std::list <FileAction>& actions()const{return m_actions;};
        GetFileMetadataBatchArg& setActions(const std::list <FileAction>& arg){m_actions=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GetFileMetadataBatchArg>  create(const QByteArray& data);
            static std::unique_ptr<GetFileMetadataBatchArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                The files to query.
            */
        std::list <QString> m_files;

            /**
                File actions to query.
            */
        std::list <FileAction> m_actions;

    };//GetFileMetadataBatchArg

}//sharing
}//dropboxQt
