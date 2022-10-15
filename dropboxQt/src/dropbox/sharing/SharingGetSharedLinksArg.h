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
    class GetSharedLinksArg{
        /**
            field: path: See :meth:`get_shared_links` description.
        */

    public:
        GetSharedLinksArg(){};

        GetSharedLinksArg(const QString& arg){ m_path = arg; };
        virtual ~GetSharedLinksArg(){};

    public:
            /**
                See :meth:`get_shared_links` description.
            */
        QString path()const{return m_path;};
        GetSharedLinksArg& setPath(const QString& arg){m_path=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GetSharedLinksArg>  create(const QByteArray& data);
            static std::unique_ptr<GetSharedLinksArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                See :meth:`get_shared_links` description.
            */
        QString m_path;

    };//GetSharedLinksArg

}//sharing
}//dropboxQt
