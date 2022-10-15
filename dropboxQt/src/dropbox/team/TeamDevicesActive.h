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
    class DevicesActive{
        /**
            Each of the items is an array of values, one value per day. The
            value is the number of devices active within a time window, ending
            with that day. If there is no data for a day, then the value will be
            None.

            field: windows: Array of number of linked windows (desktop) clients
                with activity.
            field: macos: Array of number of linked mac (desktop) clients with
                activity.
            field: linux: Array of number of linked linus (desktop) clients with
                activity.
            field: ios: Array of number of linked ios devices with activity.
            field: android: Array of number of linked android devices with
                activity.
            field: other: Array of number of other linked devices (blackberry,
                windows phone, etc)  with activity.
            field: total: Array of total number of linked clients with activity.
        */

    public:
        DevicesActive(){};

        DevicesActive(const std::list <int>& arg){ m_windows = arg; };
        virtual ~DevicesActive(){};

    public:
            /**
                Array of number of linked windows (desktop) clients with
                activity.
            */
        const std::list <int>& windows()const{return m_windows;};
        DevicesActive& setWindows(const std::list <int>& arg){m_windows=arg;return *this;};

            /**
                Array of number of linked mac (desktop) clients with activity.
            */
        const std::list <int>& macos()const{return m_macos;};
        DevicesActive& setMacos(const std::list <int>& arg){m_macos=arg;return *this;};

            /**
                Array of number of linked linus (desktop) clients with activity.
            */
        const std::list <int>& Linux()const{return m_linux;};
        DevicesActive& setLinux(const std::list <int>& arg){m_linux=arg;return *this;};

            /**
                Array of number of linked ios devices with activity.
            */
        const std::list <int>& ios()const{return m_ios;};
        DevicesActive& setIos(const std::list <int>& arg){m_ios=arg;return *this;};

            /**
                Array of number of linked android devices with activity.
            */
        const std::list <int>& android()const{return m_android;};
        DevicesActive& setAndroid(const std::list <int>& arg){m_android=arg;return *this;};

            /**
                Array of number of other linked devices (blackberry, windows
                phone, etc)  with activity.
            */
        const std::list <int>& other()const{return m_other;};
        DevicesActive& setOther(const std::list <int>& arg){m_other=arg;return *this;};

            /**
                Array of total number of linked clients with activity.
            */
        const std::list <int>& total()const{return m_total;};
        DevicesActive& setTotal(const std::list <int>& arg){m_total=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<DevicesActive>  create(const QByteArray& data);
            static std::unique_ptr<DevicesActive>  create(const QJsonObject& js);
        };



    protected:
            /**
                Array of number of linked windows (desktop) clients with
                activity.
            */
        std::list <int> m_windows;

            /**
                Array of number of linked mac (desktop) clients with activity.
            */
        std::list <int> m_macos;

            /**
                Array of number of linked linus (desktop) clients with activity.
            */
        std::list <int> m_linux;

            /**
                Array of number of linked ios devices with activity.
            */
        std::list <int> m_ios;

            /**
                Array of number of linked android devices with activity.
            */
        std::list <int> m_android;

            /**
                Array of number of other linked devices (blackberry, windows
                phone, etc)  with activity.
            */
        std::list <int> m_other;

            /**
                Array of total number of linked clients with activity.
            */
        std::list <int> m_total;

    };//DevicesActive

}//team
}//dropboxQt
