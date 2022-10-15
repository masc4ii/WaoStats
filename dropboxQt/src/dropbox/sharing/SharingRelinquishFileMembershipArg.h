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
    class RelinquishFileMembershipArg{
        /**
            field: file: The path or id for the file.
        */

    public:
        RelinquishFileMembershipArg(){};

        RelinquishFileMembershipArg(const QString& arg){ m_file = arg; };
        virtual ~RelinquishFileMembershipArg(){};

    public:
            /**
                The path or id for the file.
            */
        QString file()const{return m_file;};
        RelinquishFileMembershipArg& setFile(const QString& arg){m_file=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<RelinquishFileMembershipArg>  create(const QByteArray& data);
            static std::unique_ptr<RelinquishFileMembershipArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                The path or id for the file.
            */
        QString m_file;

    };//RelinquishFileMembershipArg

}//sharing
}//dropboxQt
