/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesLookupError.h"
#include "dropbox/sharing/SharingSharedLinkSettingsError.h"

namespace dropboxQt{
namespace sharing{
    class CreateSharedLinkWithSettingsError{
        /**
            field: email_not_verified: User's email should be verified
            field: shared_link_already_exists: The shared link already exists
            field: settings_error: There is an error with the given settings
            field: access_denied: Access to the requested path is forbidden
        */
    public:
        enum Tag{

        /*None*/
        CreateSharedLinkWithSettingsError_PATH,
        /*User's email should be verified*/
        CreateSharedLinkWithSettingsError_EMAIL_NOT_VERIFIED,
        /*The shared link already exists*/
        CreateSharedLinkWithSettingsError_SHARED_LINK_ALREADY_EXISTS,
        /*There is an error with the given settings*/
        CreateSharedLinkWithSettingsError_SETTINGS_ERROR,
        /*Access to the requested path is forbidden*/
        CreateSharedLinkWithSettingsError_ACCESS_DENIED
        };

        CreateSharedLinkWithSettingsError(){}
        CreateSharedLinkWithSettingsError(Tag v):m_tag(v){}
        virtual ~CreateSharedLinkWithSettingsError(){}

        Tag tag()const{return m_tag;}
        ///None
        const files::LookupError& getPath()const{API_CHECK_STATE((CreateSharedLinkWithSettingsError_PATH == m_tag), "expected tag: CreateSharedLinkWithSettingsError_PATH", m_tag);return m_path;};

        ///There is an error with the given settings
        const SharedLinkSettingsError& getSettingsError()const{API_CHECK_STATE((CreateSharedLinkWithSettingsError_SETTINGS_ERROR == m_tag), "expected tag: CreateSharedLinkWithSettingsError_SETTINGS_ERROR", m_tag);return m_settings_error;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<CreateSharedLinkWithSettingsError>  create(const QByteArray& data);
            static std::unique_ptr<CreateSharedLinkWithSettingsError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        files::LookupError m_path;
        SharedLinkSettingsError m_settings_error;
    };//CreateSharedLinkWithSettingsError

}//sharing
}//dropboxQt
