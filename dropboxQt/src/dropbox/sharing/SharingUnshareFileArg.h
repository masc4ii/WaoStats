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
    class UnshareFileArg{
        /**
            Arguments for :meth:`unshare_file`.

            field: file: The file to unshare.
        */

    public:
        UnshareFileArg(){};

        UnshareFileArg(const QString& arg){ m_file = arg; };
        virtual ~UnshareFileArg(){};

    public:
            /**
                The file to unshare.
            */
        QString file()const{return m_file;};
        UnshareFileArg& setFile(const QString& arg){m_file=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<UnshareFileArg>  create(const QByteArray& data);
            static std::unique_ptr<UnshareFileArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                The file to unshare.
            */
        QString m_file;

    };//UnshareFileArg

}//sharing
}//dropboxQt
