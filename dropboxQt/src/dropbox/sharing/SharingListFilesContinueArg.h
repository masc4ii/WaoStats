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
    class ListFilesContinueArg{
        /**
            Arguments for :meth:`list_received_files_continue`.

            field: cursor: Cursor in ``ListFilesResult.cursor``
        */

    public:
        ListFilesContinueArg(){};

        ListFilesContinueArg(const QString& arg){ m_cursor = arg; };
        virtual ~ListFilesContinueArg(){};

    public:
            /**
                Cursor in ``ListFilesResult.cursor``
            */
        QString cursor()const{return m_cursor;};
        ListFilesContinueArg& setCursor(const QString& arg){m_cursor=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListFilesContinueArg>  create(const QByteArray& data);
            static std::unique_ptr<ListFilesContinueArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                Cursor in ``ListFilesResult.cursor``
            */
        QString m_cursor;

    };//ListFilesContinueArg

}//sharing
}//dropboxQt
