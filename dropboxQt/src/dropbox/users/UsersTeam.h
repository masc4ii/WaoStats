/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "users"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"

namespace dropboxQt{
namespace users{
    class Team{
        /**
            Information about a team.

            field: id: The team's unique ID.
            field: name: The name of the team.
        */

    public:
        Team(){};

        Team(const QString& arg){ m_id = arg; };
        virtual ~Team(){};

    public:
            /**
                The team's unique ID.
            */
        QString id()const{return m_id;};
        Team& setId(const QString& arg){m_id=arg;return *this;};

            /**
                The name of the team.
            */
        QString name()const{return m_name;};
        Team& setName(const QString& arg){m_name=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<Team>  create(const QByteArray& data);
            static std::unique_ptr<Team>  create(const QJsonObject& js);
        };



    protected:
            /**
                The team's unique ID.
            */
        QString m_id;

            /**
                The name of the team.
            */
        QString m_name;

    };//Team

}//users
}//dropboxQt
