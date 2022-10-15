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
    class ListFileMembersContinueArg{
        /**
            Arguments for :meth:`list_file_members_continue`.

            field: cursor: The cursor returned by your last call to
                :meth:`list_file_members`, :meth:`list_file_members_continue`,
                or :meth:`list_file_members_batch`.
        */

    public:
        ListFileMembersContinueArg(){};

        ListFileMembersContinueArg(const QString& arg){ m_cursor = arg; };
        virtual ~ListFileMembersContinueArg(){};

    public:
            /**
                The cursor returned by your last call to
                :meth:`list_file_members`, :meth:`list_file_members_continue`,
                or :meth:`list_file_members_batch`.
            */
        QString cursor()const{return m_cursor;};
        ListFileMembersContinueArg& setCursor(const QString& arg){m_cursor=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListFileMembersContinueArg>  create(const QByteArray& data);
            static std::unique_ptr<ListFileMembersContinueArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                The cursor returned by your last call to
                :meth:`list_file_members`, :meth:`list_file_members_continue`,
                or :meth:`list_file_members_batch`.
            */
        QString m_cursor;

    };//ListFileMembersContinueArg

}//sharing
}//dropboxQt
