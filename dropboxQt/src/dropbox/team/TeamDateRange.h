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
    class DateRange{
        /**
            Input arguments that can be provided for most reports.

            field: start_date: Optional starting date (inclusive)
            field: end_date: Optional ending date (exclusive)
        */

    public:
        DateRange(){};

        DateRange(const QDateTime& arg){ m_start_date = arg; };
        virtual ~DateRange(){};

    public:
            /**
                Optional starting date (inclusive)
            */
        QDateTime startDate()const{return m_start_date;};
        DateRange& setStartdate(const QDateTime& arg){m_start_date=arg;return *this;};

            /**
                Optional ending date (exclusive)
            */
        QDateTime endDate()const{return m_end_date;};
        DateRange& setEnddate(const QDateTime& arg){m_end_date=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<DateRange>  create(const QByteArray& data);
            static std::unique_ptr<DateRange>  create(const QJsonObject& js);
        };



    protected:
            /**
                Optional starting date (inclusive)
            */
        QDateTime m_start_date;

            /**
                Optional ending date (exclusive)
            */
        QDateTime m_end_date;

    };//DateRange

}//team
}//dropboxQt
