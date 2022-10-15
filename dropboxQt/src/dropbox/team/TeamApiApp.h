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
    class ApiApp{
        /**
            Information on linked third party applications

            field: app_id: The application unique id
            field: app_name: The application name
            field: publisher: The application publisher name
            field: publisher_url: The publisher's URL
            field: linked: The time this application was linked
            field: is_app_folder: Whether the linked application uses a
                dedicated folder
        */

    public:
        ApiApp(){};

        ApiApp(const QString& arg){ m_app_id = arg; };
        virtual ~ApiApp(){};

    public:
            /**
                The application unique id
            */
        QString appId()const{return m_app_id;};
        ApiApp& setAppid(const QString& arg){m_app_id=arg;return *this;};

            /**
                The application name
            */
        QString appName()const{return m_app_name;};
        ApiApp& setAppname(const QString& arg){m_app_name=arg;return *this;};

            /**
                The application publisher name
            */
        QString publisher()const{return m_publisher;};
        ApiApp& setPublisher(const QString& arg){m_publisher=arg;return *this;};

            /**
                The publisher's URL
            */
        QString publisherUrl()const{return m_publisher_url;};
        ApiApp& setPublisherurl(const QString& arg){m_publisher_url=arg;return *this;};

            /**
                The time this application was linked
            */
        QDateTime linked()const{return m_linked;};
        ApiApp& setLinked(const QDateTime& arg){m_linked=arg;return *this;};

            /**
                Whether the linked application uses a dedicated folder
            */
        bool isAppFolder()const{return m_is_app_folder;};
        ApiApp& setIsappfolder(const bool& arg){m_is_app_folder=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ApiApp>  create(const QByteArray& data);
            static std::unique_ptr<ApiApp>  create(const QJsonObject& js);
        };



    protected:
            /**
                The application unique id
            */
        QString m_app_id;

            /**
                The application name
            */
        QString m_app_name;

            /**
                The application publisher name
            */
        QString m_publisher;

            /**
                The publisher's URL
            */
        QString m_publisher_url;

            /**
                The time this application was linked
            */
        QDateTime m_linked;

            /**
                Whether the linked application uses a dedicated folder
            */
        bool m_is_app_folder;

    };//ApiApp

}//team
}//dropboxQt
