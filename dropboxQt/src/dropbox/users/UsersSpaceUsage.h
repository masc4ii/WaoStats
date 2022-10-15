/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "users"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/users/UsersSpaceAllocation.h"

namespace dropboxQt{
namespace users{
    class SpaceUsage{
        /**
            Information about a user's space usage and quota.

            field: used: The user's total space usage (bytes).
            field: allocation: The user's space allocation.
        */

    public:
        SpaceUsage(){};

        SpaceUsage(const int& arg){ m_used = arg; };
        virtual ~SpaceUsage(){};

    public:
            /**
                The user's total space usage (bytes).
            */
        int used()const{return m_used;};
        SpaceUsage& setUsed(const int& arg){m_used=arg;return *this;};

            /**
                The user's space allocation.
            */
        const SpaceAllocation& allocation()const{return m_allocation;};
        SpaceUsage& setAllocation(const SpaceAllocation& arg){m_allocation=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<SpaceUsage>  create(const QByteArray& data);
            static std::unique_ptr<SpaceUsage>  create(const QJsonObject& js);
        };



    protected:
            /**
                The user's total space usage (bytes).
            */
        int m_used = {0};

            /**
                The user's space allocation.
            */
        SpaceAllocation m_allocation;

    };//SpaceUsage

}//users
}//dropboxQt
