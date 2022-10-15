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
    class BaseDfbReport{
        /**
            Base report structure.

            field: start_date: First date present in the results as 'YYYY-MM-DD'
                or None.
        */

    public:
        BaseDfbReport(){};

        BaseDfbReport(const QString& arg){ m_start_date = arg; };
        virtual ~BaseDfbReport(){};

    public:
            /**
                First date present in the results as 'YYYY-MM-DD' or None.
            */
        QString startDate()const{return m_start_date;};
        BaseDfbReport& setStartdate(const QString& arg){m_start_date=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<BaseDfbReport>  create(const QByteArray& data);
            static std::unique_ptr<BaseDfbReport>  create(const QJsonObject& js);
        };



    protected:
            /**
                First date present in the results as 'YYYY-MM-DD' or None.
            */
        QString m_start_date;

    };//BaseDfbReport

}//team
}//dropboxQt
