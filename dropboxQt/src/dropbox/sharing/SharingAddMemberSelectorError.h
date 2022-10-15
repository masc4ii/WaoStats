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
    class AddMemberSelectorError{
        /**
            field: automatic_group: Automatically created groups can only be
                added to team folders.
            field: invalid_dropbox_id: The value is the ID that could not be
                identified.
            field: invalid_email: The value is the e-email address that is
                malformed.
            field: unverified_dropbox_id: The value is the ID of the Dropbox
                user with an unverified e-mail address.  Invite unverified users
                by e-mail address instead of by their Dropbox ID.
            field: group_deleted: At least one of the specified groups in
                ``AddFolderMemberArg.members`` is deleted.
            field: group_not_on_team: Sharing to a group that is not on the
                current user's team.
        */
    public:
        enum Tag{

        /*Automatically created groups can only be added to team folders.*/
        AddMemberSelectorError_AUTOMATIC_GROUP,
        /*The value is the ID that could not be identified.*/
        AddMemberSelectorError_INVALID_DROPBOX_ID,
        /*The value is the e-email address that is malformed.*/
        AddMemberSelectorError_INVALID_EMAIL,
        /*The value is the ID of the Dropbox user with an unverified e-mail address.  Invite unverified users by e-mail address instead of by their Dropbox ID.*/
        AddMemberSelectorError_UNVERIFIED_DROPBOX_ID,
        /*At least one of the specified groups in :field:`AddFolderMemberArg.members` is deleted.*/
        AddMemberSelectorError_GROUP_DELETED,
        /*Sharing to a group that is not on the current user's team.*/
        AddMemberSelectorError_GROUP_NOT_ON_TEAM,
        /*None*/
        AddMemberSelectorError_OTHER
        };

        AddMemberSelectorError(){}
        AddMemberSelectorError(Tag v):m_tag(v){}
        virtual ~AddMemberSelectorError(){}

        Tag tag()const{return m_tag;}
        ///The value is the ID that could not be identified.
        QString getInvalidDropboxId()const{API_CHECK_STATE((AddMemberSelectorError_INVALID_DROPBOX_ID == m_tag), "expected tag: AddMemberSelectorError_INVALID_DROPBOX_ID", m_tag);return m_invalid_dropbox_id;};

        ///The value is the e-email address that is malformed.
        QString getInvalidEmail()const{API_CHECK_STATE((AddMemberSelectorError_INVALID_EMAIL == m_tag), "expected tag: AddMemberSelectorError_INVALID_EMAIL", m_tag);return m_invalid_email;};

        ///The value is the ID of the Dropbox user with an unverified e-mail address.  Invite unverified users by e-mail address instead of by their Dropbox ID.
        QString getUnverifiedDropboxId()const{API_CHECK_STATE((AddMemberSelectorError_UNVERIFIED_DROPBOX_ID == m_tag), "expected tag: AddMemberSelectorError_UNVERIFIED_DROPBOX_ID", m_tag);return m_unverified_dropbox_id;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<AddMemberSelectorError>  create(const QByteArray& data);
            static std::unique_ptr<AddMemberSelectorError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        QString m_invalid_dropbox_id;
        QString m_invalid_email;
        QString m_unverified_dropbox_id;
    };//AddMemberSelectorError

}//sharing
}//dropboxQt
