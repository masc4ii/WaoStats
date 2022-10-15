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
    class ListSharedLinksArg{
        /**
            field: path: See :meth:`list_shared_links` description.
            field: cursor: The cursor returned by your last call to
                :meth:`list_shared_links`.
            field: direct_only: See :meth:`list_shared_links` description.
        */

    public:
        ListSharedLinksArg(){};

        ListSharedLinksArg(const QString& arg){ m_path = arg; };
        virtual ~ListSharedLinksArg(){};

    public:
            /**
                See :meth:`list_shared_links` description.
            */
        QString path()const{return m_path;};
        ListSharedLinksArg& setPath(const QString& arg){m_path=arg;return *this;};

            /**
                The cursor returned by your last call to
                :meth:`list_shared_links`.
            */
        QString cursor()const{return m_cursor;};
        ListSharedLinksArg& setCursor(const QString& arg){m_cursor=arg;return *this;};

            /**
                See :meth:`list_shared_links` description.
            */
        bool directOnly()const{return m_direct_only;};
        ListSharedLinksArg& setDirectonly(const bool& arg){m_direct_only=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListSharedLinksArg>  create(const QByteArray& data);
            static std::unique_ptr<ListSharedLinksArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                See :meth:`list_shared_links` description.
            */
        QString m_path;

            /**
                The cursor returned by your last call to
                :meth:`list_shared_links`.
            */
        QString m_cursor;

            /**
                See :meth:`list_shared_links` description.
            */
        bool m_direct_only;

    };//ListSharedLinksArg

}//sharing
}//dropboxQt
