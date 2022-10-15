/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingPendingUploadMode.h"

namespace dropboxQt{
namespace sharing{
    class CreateSharedLinkArg{
        /**
            field: path: The path to share.
            field: short_url: Whether to return a shortened URL.
            field: pending_upload: If it's okay to share a path that does not
                yet exist, set this to either ``PendingUploadMode.file`` or
                ``PendingUploadMode.folder`` to indicate whether to assume it's
                a file or folder.
        */

    public:
        CreateSharedLinkArg():
        m_short_url(false)
        {};

        CreateSharedLinkArg(const QString& arg):
        m_short_url(false)
        { m_path = arg; };
        virtual ~CreateSharedLinkArg(){};

    public:
            /**
                The path to share.
            */
        QString path()const{return m_path;};
        CreateSharedLinkArg& setPath(const QString& arg){m_path=arg;return *this;};

            /**
                Whether to return a shortened URL.
            */
        bool shortUrl()const{return m_short_url;};
        CreateSharedLinkArg& setShorturl(const bool& arg){m_short_url=arg;return *this;};

            /**
                If it's okay to share a path that does not yet exist, set this
                to either ``PendingUploadMode.file`` or
                ``PendingUploadMode.folder`` to indicate whether to assume it's
                a file or folder.
            */
        const PendingUploadMode& pendingUpload()const{return m_pending_upload;};
        CreateSharedLinkArg& setPendingupload(const PendingUploadMode& arg){m_pending_upload=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<CreateSharedLinkArg>  create(const QByteArray& data);
            static std::unique_ptr<CreateSharedLinkArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                The path to share.
            */
        QString m_path;

            /**
                Whether to return a shortened URL.
            */
        bool m_short_url;

            /**
                If it's okay to share a path that does not yet exist, set this
                to either ``PendingUploadMode.file`` or
                ``PendingUploadMode.folder`` to indicate whether to assume it's
                a file or folder.
            */
        PendingUploadMode m_pending_upload;

    };//CreateSharedLinkArg

}//sharing
}//dropboxQt
