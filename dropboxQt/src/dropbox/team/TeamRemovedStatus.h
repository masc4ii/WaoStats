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
    class RemovedStatus{
        /**
            field: is_recoverable: True if the removed team member is
                recoverable
        */

    public:
        RemovedStatus(){};

        RemovedStatus(const bool& arg){ m_is_recoverable = arg; };
        virtual ~RemovedStatus(){};

    public:
            /**
                True if the removed team member is recoverable
            */
        bool isRecoverable()const{return m_is_recoverable;};
        RemovedStatus& setIsrecoverable(const bool& arg){m_is_recoverable=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<RemovedStatus>  create(const QByteArray& data);
            static std::unique_ptr<RemovedStatus>  create(const QJsonObject& js);
        };



    protected:
            /**
                True if the removed team member is recoverable
            */
        bool m_is_recoverable;

    };//RemovedStatus

}//team
}//dropboxQt
