/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamDeviceSessionArg.h"

namespace dropboxQt{
namespace team{
    class RevokeDesktopClientArg : public DeviceSessionArg{
        /**
            field: delete_on_unlink: Whether to delete all files of the account
                (this is possible only if supported by the desktop client and
                will be made the next time the client access the account)
        */

    public:
        RevokeDesktopClientArg():
        m_delete_on_unlink(false)
        {};

        RevokeDesktopClientArg(const bool& arg):
        m_delete_on_unlink(false)
        { m_delete_on_unlink = arg; };
        virtual ~RevokeDesktopClientArg(){};

    public:
            /**
                Whether to delete all files of the account (this is possible
                only if supported by the desktop client and  will be made the
                next time the client access the account)
            */
        bool deleteOnUnlink()const{return m_delete_on_unlink;};
        RevokeDesktopClientArg& setDeleteonunlink(const bool& arg){m_delete_on_unlink=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<RevokeDesktopClientArg>  create(const QByteArray& data);
            static std::unique_ptr<RevokeDesktopClientArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                Whether to delete all files of the account (this is possible
                only if supported by the desktop client and  will be made the
                next time the client access the account)
            */
        bool m_delete_on_unlink;

    };//RevokeDesktopClientArg

}//team
}//dropboxQt
