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
    class RelocationArg{
        /**
            field: from_path: Path in the user's Dropbox to be copied or moved.
            field: to_path: Path in the user's Dropbox that is the destination.
        */

    public:
        RelocationArg(){};

        RelocationArg(const QString& arg){ m_from_path = arg; };
        virtual ~RelocationArg(){};

    public:
            /**
                Path in the user's Dropbox to be copied or moved.
            */
        QString fromPath()const{return m_from_path;};
        RelocationArg& setFrompath(const QString& arg){m_from_path=arg;return *this;};

            /**
                Path in the user's Dropbox that is the destination.
            */
        QString toPath()const{return m_to_path;};
        RelocationArg& setTopath(const QString& arg){m_to_path=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<RelocationArg>  create(const QByteArray& data);
            static std::unique_ptr<RelocationArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                Path in the user's Dropbox to be copied or moved.
            */
        QString m_from_path;

            /**
                Path in the user's Dropbox that is the destination.
            */
        QString m_to_path;

    };//RelocationArg

}//files
}//dropboxQt
