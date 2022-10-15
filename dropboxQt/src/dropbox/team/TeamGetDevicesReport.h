/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamBaseDfbReport.h"
#include "dropbox/team/TeamDevicesActive.h"

namespace dropboxQt{
namespace team{
    class GetDevicesReport : public BaseDfbReport{
        /**
            Devices Report Result. Contains subsections for different time
            ranges of activity. Each of the items in each subsection of the
            storage report is an array of values, one value per day. If there is
            no data for a day, then the value will be None.

            field: active_1_day: Report of the number of devices active in the
                last day.
            field: active_7_day: Report of the number of devices active in the
                last 7 days.
            field: active_28_day: Report of the number of devices active in the
                last 28 days.
        */

    public:
        GetDevicesReport(){};

        GetDevicesReport(const DevicesActive& arg){ m_active_1_day = arg; };
        virtual ~GetDevicesReport(){};

    public:
            /**
                Report of the number of devices active in the last day.
            */
        const DevicesActive& active1Day()const{return m_active_1_day;};
        GetDevicesReport& setActive1Day(const DevicesActive& arg){m_active_1_day=arg;return *this;};

            /**
                Report of the number of devices active in the last 7 days.
            */
        const DevicesActive& active7Day()const{return m_active_7_day;};
        GetDevicesReport& setActive7Day(const DevicesActive& arg){m_active_7_day=arg;return *this;};

            /**
                Report of the number of devices active in the last 28 days.
            */
        const DevicesActive& active28Day()const{return m_active_28_day;};
        GetDevicesReport& setActive28Day(const DevicesActive& arg){m_active_28_day=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GetDevicesReport>  create(const QByteArray& data);
            static std::unique_ptr<GetDevicesReport>  create(const QJsonObject& js);
        };



    protected:
            /**
                Report of the number of devices active in the last day.
            */
        DevicesActive m_active_1_day;

            /**
                Report of the number of devices active in the last 7 days.
            */
        DevicesActive m_active_7_day;

            /**
                Report of the number of devices active in the last 28 days.
            */
        DevicesActive m_active_28_day;

    };//GetDevicesReport

}//team
}//dropboxQt
