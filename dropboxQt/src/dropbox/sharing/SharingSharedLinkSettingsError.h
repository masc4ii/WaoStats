/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"

namespace dropboxQt{
namespace sharing{
    class SharedLinkSettingsError{
        /**
            field: invalid_settings: The given settings are invalid (for
                example, all attributes of the :class:`SharedLinkSettings` are
                empty, the requested visibility is
                ``RequestedVisibility.password`` but the
                ``SharedLinkSettings.link_password`` is missing,
                ``SharedLinkSettings.expires`` is set to the past, etc.)
            field: not_authorized: User is not allowed to modify the settings of
                this link. Note that basic users can only set
                ``RequestedVisibility.public`` as the
                ``SharedLinkSettings.requested_visibility`` and cannot set
                ``SharedLinkSettings.expires``
        */
    public:
        enum Tag{

        /*The given settings are invalid (for example, all attributes of the :type:`SharedLinkSettings` are empty, the requested visibility is :field:`RequestedVisibility.password` but the :field:`SharedLinkSettings.link_password` is missing, :field:`SharedLinkSettings.expires` is set to the past, etc.)*/
        SharedLinkSettingsError_INVALID_SETTINGS,
        /*User is not allowed to modify the settings of this link. Note that basic users can only set :field:`RequestedVisibility.public` as the :field:`SharedLinkSettings.requested_visibility` and cannot set :field:`SharedLinkSettings.expires`*/
        SharedLinkSettingsError_NOT_AUTHORIZED
        };

        SharedLinkSettingsError(){}
        SharedLinkSettingsError(Tag v):m_tag(v){}
        virtual ~SharedLinkSettingsError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<SharedLinkSettingsError>  create(const QByteArray& data);
            static std::unique_ptr<SharedLinkSettingsError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//SharedLinkSettingsError

}//sharing
}//dropboxQt
