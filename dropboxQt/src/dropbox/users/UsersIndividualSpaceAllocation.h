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
    class IndividualSpaceAllocation{
        /**
            field: allocated: The total space allocated to the user's account
                (bytes).
        */

    public:
        IndividualSpaceAllocation(){};

        IndividualSpaceAllocation(const int& arg){ m_allocated = arg; };
        virtual ~IndividualSpaceAllocation(){};

    public:
            /**
                The total space allocated to the user's account (bytes).
            */
        int allocated()const{return m_allocated;};
        IndividualSpaceAllocation& setAllocated(const int& arg){m_allocated=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<IndividualSpaceAllocation>  create(const QByteArray& data);
            static std::unique_ptr<IndividualSpaceAllocation>  create(const QJsonObject& js);
        };



    protected:
            /**
                The total space allocated to the user's account (bytes).
            */
        int m_allocated = {0};

    };//IndividualSpaceAllocation

}//users
}//dropboxQt
