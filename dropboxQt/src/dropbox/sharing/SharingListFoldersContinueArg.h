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
    class ListFoldersContinueArg{
        /**
            field: cursor: The cursor returned by the previous API call
                specified in the endpoint description.
        */

    public:
        ListFoldersContinueArg(){};

        ListFoldersContinueArg(const QString& arg){ m_cursor = arg; };
        virtual ~ListFoldersContinueArg(){};

    public:
            /**
                The cursor returned by the previous API call specified in the
                endpoint description.
            */
        QString cursor()const{return m_cursor;};
        ListFoldersContinueArg& setCursor(const QString& arg){m_cursor=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListFoldersContinueArg>  create(const QByteArray& data);
            static std::unique_ptr<ListFoldersContinueArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                The cursor returned by the previous API call specified in the
                endpoint description.
            */
        QString m_cursor;

    };//ListFoldersContinueArg

}//sharing
}//dropboxQt
