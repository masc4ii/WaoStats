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
    class GetCopyReferenceArg{
        /**
            field: path: The path to the file or folder you want to get a copy
                reference to.
        */

    public:
        GetCopyReferenceArg(){};

        GetCopyReferenceArg(const QString& arg){ m_path = arg; };
        virtual ~GetCopyReferenceArg(){};

    public:
            /**
                The path to the file or folder you want to get a copy reference
                to.
            */
        QString path()const{return m_path;};
        GetCopyReferenceArg& setPath(const QString& arg){m_path=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GetCopyReferenceArg>  create(const QByteArray& data);
            static std::unique_ptr<GetCopyReferenceArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                The path to the file or folder you want to get a copy reference
                to.
            */
        QString m_path;

    };//GetCopyReferenceArg

}//files
}//dropboxQt
