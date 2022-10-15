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
    class GetFileMetadataArg{
        /**
            Arguments of :meth:`get_file_metadata`

            field: file: The file to query.
            field: actions: File actions to query.
        */

    public:
        GetFileMetadataArg(){};

        GetFileMetadataArg(const QString& arg){ m_file = arg; };
        virtual ~GetFileMetadataArg(){};

    public:
            /**
                The file to query.
            */
        QString file()const{return m_file;};
        GetFileMetadataArg& setFile(const QString& arg){m_file=arg;return *this;};

            /**
                File actions to query.
            */
        const std::list <FileAction>& actions()const{return m_actions;};
        GetFileMetadataArg& setActions(const std::list <FileAction>& arg){m_actions=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GetFileMetadataArg>  create(const QByteArray& data);
            static std::unique_ptr<GetFileMetadataArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                The file to query.
            */
        QString m_file;

            /**
                File actions to query.
            */
        std::list <FileAction> m_actions;

    };//GetFileMetadataArg

}//sharing
}//dropboxQt
