/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"

namespace dropboxQt{
namespace team{
    class StorageBucket{
        /**
            Describes the number of users in a specific storage bucket.

            field: bucket: The name of the storage bucket. For example, '1G' is
                a bucket of users with storage size up to 1 Giga.
            field: users: The number of people whose storage is in the range of
                this storage bucket.
        */

    public:
        StorageBucket(){};

        StorageBucket(const QString& arg){ m_bucket = arg; };
        virtual ~StorageBucket(){};

    public:
            /**
                The name of the storage bucket. For example, '1G' is a bucket of
                users with storage size up to 1 Giga.
            */
        QString bucket()const{return m_bucket;};
        StorageBucket& setBucket(const QString& arg){m_bucket=arg;return *this;};

            /**
                The number of people whose storage is in the range of this
                storage bucket.
            */
        int users()const{return m_users;};
        StorageBucket& setUsers(const int& arg){m_users=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<StorageBucket>  create(const QByteArray& data);
            static std::unique_ptr<StorageBucket>  create(const QJsonObject& js);
        };



    protected:
            /**
                The name of the storage bucket. For example, '1G' is a bucket of
                users with storage size up to 1 Giga.
            */
        QString m_bucket;

            /**
                The number of people whose storage is in the range of this
                storage bucket.
            */
        int m_users = {0};

    };//StorageBucket

}//team
}//dropboxQt
