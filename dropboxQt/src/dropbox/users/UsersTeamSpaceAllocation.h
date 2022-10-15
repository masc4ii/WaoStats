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
    class TeamSpaceAllocation{
        /**
            field: used: The total space currently used by the user's team
                (bytes).
            field: allocated: The total space allocated to the user's team
                (bytes).
        */

    public:
        TeamSpaceAllocation(){};

        TeamSpaceAllocation(const int& arg){ m_used = arg; };
        virtual ~TeamSpaceAllocation(){};

    public:
            /**
                The total space currently used by the user's team (bytes).
            */
        int used()const{return m_used;};
        TeamSpaceAllocation& setUsed(const int& arg){m_used=arg;return *this;};

            /**
                The total space allocated to the user's team (bytes).
            */
        int allocated()const{return m_allocated;};
        TeamSpaceAllocation& setAllocated(const int& arg){m_allocated=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<TeamSpaceAllocation>  create(const QByteArray& data);
            static std::unique_ptr<TeamSpaceAllocation>  create(const QJsonObject& js);
        };



    protected:
            /**
                The total space currently used by the user's team (bytes).
            */
        int m_used = {0};

            /**
                The total space allocated to the user's team (bytes).
            */
        int m_allocated = {0};

    };//TeamSpaceAllocation

}//users
}//dropboxQt
