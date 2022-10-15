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
    class ListRevisionsArg{
        /**
            field: path: The path to the file you want to see the revisions of.
            field: limit: The maximum number of revision entries returned.
        */

    public:
        ListRevisionsArg():
        m_limit(10)
        {};

        ListRevisionsArg(const QString& arg):
        m_limit(10)
        { m_path = arg; };
        virtual ~ListRevisionsArg(){};

    public:
            /**
                The path to the file you want to see the revisions of.
            */
        QString path()const{return m_path;};
        ListRevisionsArg& setPath(const QString& arg){m_path=arg;return *this;};

            /**
                The maximum number of revision entries returned.
            */
        int limit()const{return m_limit;};
        ListRevisionsArg& setLimit(const int& arg){m_limit=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListRevisionsArg>  create(const QByteArray& data);
            static std::unique_ptr<ListRevisionsArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                The path to the file you want to see the revisions of.
            */
        QString m_path;

            /**
                The maximum number of revision entries returned.
            */
        int m_limit = {0};

    };//ListRevisionsArg

}//files
}//dropboxQt
