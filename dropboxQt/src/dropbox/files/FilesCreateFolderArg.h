/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"

namespace dropboxQt{
namespace files{
    class CreateFolderArg{
        /**
            field: path: Path in the user's Dropbox to create.
        */

    public:
        CreateFolderArg(){};

        CreateFolderArg(const QString& arg){ m_path = arg; };
        virtual ~CreateFolderArg(){};

    public:
            /**
                Path in the user's Dropbox to create.
            */
        QString path()const{return m_path;};
        CreateFolderArg& setPath(const QString& arg){m_path=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<CreateFolderArg>  create(const QByteArray& data);
            static std::unique_ptr<CreateFolderArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                Path in the user's Dropbox to create.
            */
        QString m_path;

    };//CreateFolderArg

}//files
}//dropboxQt
