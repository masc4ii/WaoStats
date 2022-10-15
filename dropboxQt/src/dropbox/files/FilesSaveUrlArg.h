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
    class SaveUrlArg{
        /**
            field: path: The path in Dropbox where the URL will be saved to.
            field: url: The URL to be saved.
        */

    public:
        SaveUrlArg(){};

        SaveUrlArg(const QString& arg){ m_path = arg; };
        virtual ~SaveUrlArg(){};

    public:
            /**
                The path in Dropbox where the URL will be saved to.
            */
        QString path()const{return m_path;};
        SaveUrlArg& setPath(const QString& arg){m_path=arg;return *this;};

            /**
                The URL to be saved.
            */
        QString url()const{return m_url;};
        SaveUrlArg& setUrl(const QString& arg){m_url=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<SaveUrlArg>  create(const QByteArray& data);
            static std::unique_ptr<SaveUrlArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                The path in Dropbox where the URL will be saved to.
            */
        QString m_path;

            /**
                The URL to be saved.
            */
        QString m_url;

    };//SaveUrlArg

}//files
}//dropboxQt
