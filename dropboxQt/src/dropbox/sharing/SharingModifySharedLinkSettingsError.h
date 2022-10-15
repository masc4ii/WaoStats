/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingSharedLinkError.h"
#include "dropbox/sharing/SharingSharedLinkSettingsError.h"

namespace dropboxQt{
namespace sharing{
    class ModifySharedLinkSettingsError{
        /**
            field: settings_error: There is an error with the given settings
            field: email_not_verified: The caller's email should be verified
        */
    public:
        enum Tag{

        /*The shared link wasn't found*/
        SharedLinkError_SHARED_LINK_NOT_FOUND,
        /*The caller is not allowed to access this shared link*/
        SharedLinkError_SHARED_LINK_ACCESS_DENIED,
        /*None*/
        SharedLinkError_OTHER,
        /*There is an error with the given settings*/
        ModifySharedLinkSettingsError_SETTINGS_ERROR,
        /*The caller's email should be verified*/
        ModifySharedLinkSettingsError_EMAIL_NOT_VERIFIED
        };

        ModifySharedLinkSettingsError(){}
        ModifySharedLinkSettingsError(Tag v):m_tag(v){}
        virtual ~ModifySharedLinkSettingsError(){}

        Tag tag()const{return m_tag;}
        ///There is an error with the given settings
        const SharedLinkSettingsError& getSettingsError()const{API_CHECK_STATE((ModifySharedLinkSettingsError_SETTINGS_ERROR == m_tag), "expected tag: ModifySharedLinkSettingsError_SETTINGS_ERROR", m_tag);return m_settings_error;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ModifySharedLinkSettingsError>  create(const QByteArray& data);
            static std::unique_ptr<ModifySharedLinkSettingsError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        SharedLinkSettingsError m_settings_error;
    };//ModifySharedLinkSettingsError

}//sharing
}//dropboxQt
