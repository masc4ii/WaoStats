/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesWriteMode.h"

namespace dropboxQt{
namespace files{
    class CommitInfo{
        /**
            field: path: Path in the user's Dropbox to save the file.
            field: mode: Selects what to do if the file already exists.
            field: autorename: If there's a conflict, as determined by ``mode``,
                have the Dropbox server try to autorename the file to avoid
                conflict.
            field: client_modified: The value to store as the
                ``client_modified`` timestamp. Dropbox automatically records the
                time at which the file was written to the Dropbox servers. It
                can also record an additional timestamp, provided by Dropbox
                desktop clients, mobile clients, and API apps of when the file
                was actually created or modified.
            field: mute: Normally, users are made aware of any file
                modifications in their Dropbox account via notifications in the
                client software. If ``True``, this tells the clients that this
                modification shouldn't result in a user notification.
        */

    public:
        CommitInfo():
        m_mode(WriteMode::WriteMode_ADD)
        ,m_autorename(false)
        ,m_mute(false)
        {};

        CommitInfo(const QString& arg):
        m_mode(WriteMode::WriteMode_ADD)
        ,m_autorename(false)
        ,m_mute(false)
        { m_path = arg; };
        virtual ~CommitInfo(){};

    public:
            /**
                Path in the user's Dropbox to save the file.
            */
        QString path()const{return m_path;};
        CommitInfo& setPath(const QString& arg){m_path=arg;return *this;};

            /**
                Selects what to do if the file already exists.
            */
        const WriteMode& mode()const{return m_mode;};
        CommitInfo& setMode(const WriteMode& arg){m_mode=arg;return *this;};

            /**
                If there's a conflict, as determined by ``mode``, have the
                Dropbox server try to autorename the file to avoid conflict.
            */
        bool autorename()const{return m_autorename;};
        CommitInfo& setAutorename(const bool& arg){m_autorename=arg;return *this;};

            /**
                The value to store as the ``client_modified`` timestamp. Dropbox
                automatically records the time at which the file was written to
                the Dropbox servers. It can also record an additional timestamp,
                provided by Dropbox desktop clients, mobile clients, and API
                apps of when the file was actually created or modified.
            */
        QDateTime clientModified()const{return m_client_modified;};
        CommitInfo& setClientmodified(const QDateTime& arg){m_client_modified=arg;return *this;};

            /**
                Normally, users are made aware of any file modifications in
                their Dropbox account via notifications in the client software.
                If ``True``, this tells the clients that this modification
                shouldn't result in a user notification.
            */
        bool mute()const{return m_mute;};
        CommitInfo& setMute(const bool& arg){m_mute=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<CommitInfo>  create(const QByteArray& data);
            static std::unique_ptr<CommitInfo>  create(const QJsonObject& js);
        };



    protected:
            /**
                Path in the user's Dropbox to save the file.
            */
        QString m_path;

            /**
                Selects what to do if the file already exists.
            */
        WriteMode m_mode;

            /**
                If there's a conflict, as determined by ``mode``, have the
                Dropbox server try to autorename the file to avoid conflict.
            */
        bool m_autorename;

            /**
                The value to store as the ``client_modified`` timestamp. Dropbox
                automatically records the time at which the file was written to
                the Dropbox servers. It can also record an additional timestamp,
                provided by Dropbox desktop clients, mobile clients, and API
                apps of when the file was actually created or modified.
            */
        QDateTime m_client_modified;

            /**
                Normally, users are made aware of any file modifications in
                their Dropbox account via notifications in the client software.
                If ``True``, this tells the clients that this modification
                shouldn't result in a user notification.
            */
        bool m_mute;

    };//CommitInfo

}//files
}//dropboxQt
