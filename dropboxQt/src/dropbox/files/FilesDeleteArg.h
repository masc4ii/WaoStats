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
    class DeleteArg{
        /**
            field: path: Path in the user's Dropbox to delete.
        */

    public:
        DeleteArg(){};

        DeleteArg(const QString& arg){ m_path = arg; };
        virtual ~DeleteArg(){};

    public:
            /**
                Path in the user's Dropbox to delete.
            */
        QString path()const{return m_path;};
        DeleteArg& setPath(const QString& arg){m_path=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<DeleteArg>  create(const QByteArray& data);
            static std::unique_ptr<DeleteArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                Path in the user's Dropbox to delete.
            */
        QString m_path;

    };//DeleteArg

}//files
}//dropboxQt
