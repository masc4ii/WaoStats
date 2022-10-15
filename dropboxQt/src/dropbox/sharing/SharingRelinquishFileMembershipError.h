/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingSharingFileAccessError.h"

namespace dropboxQt{
namespace sharing{
    class RelinquishFileMembershipError{
        /**
            field: group_access: The current user has access to the shared file
                via a group.  You can't relinquish membership to a file shared
                via groups.
            field: no_permission: The current user does not have permission to
                perform this action.
        */
    public:
        enum Tag{

        /*None*/
        RelinquishFileMembershipError_ACCESS_ERROR,
        /*The current user has access to the shared file via a group.  You can't relinquish membership to a file shared via groups.*/
        RelinquishFileMembershipError_GROUP_ACCESS,
        /*The current user does not have permission to perform this action.*/
        RelinquishFileMembershipError_NO_PERMISSION,
        /*None*/
        RelinquishFileMembershipError_OTHER
        };

        RelinquishFileMembershipError(){}
        RelinquishFileMembershipError(Tag v):m_tag(v){}
        virtual ~RelinquishFileMembershipError(){}

        Tag tag()const{return m_tag;}
        ///None
        const SharingFileAccessError& getAccessError()const{API_CHECK_STATE((RelinquishFileMembershipError_ACCESS_ERROR == m_tag), "expected tag: RelinquishFileMembershipError_ACCESS_ERROR", m_tag);return m_access_error;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<RelinquishFileMembershipError>  create(const QByteArray& data);
            static std::unique_ptr<RelinquishFileMembershipError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        SharingFileAccessError m_access_error;
    };//RelinquishFileMembershipError

}//sharing
}//dropboxQt
