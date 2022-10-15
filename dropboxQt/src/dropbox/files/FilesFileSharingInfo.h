/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesSharingInfo.h"

namespace dropboxQt{
namespace files{
    class FileSharingInfo : public SharingInfo{
        /**
            Sharing info for a file which is contained by a shared folder.

            field: parent_shared_folder_id: ID of shared folder that holds this
                file.
            field: modified_by: The last user who modified the file. This field
                will be null if the user's account has been deleted.
        */

    public:
        FileSharingInfo(){};

        FileSharingInfo(const QString& arg){ m_parent_shared_folder_id = arg; };
        virtual ~FileSharingInfo(){};

    public:
            /**
                ID of shared folder that holds this file.
            */
        QString parentSharedFolderId()const{return m_parent_shared_folder_id;};
        FileSharingInfo& setParentsharedfolderid(const QString& arg){m_parent_shared_folder_id=arg;return *this;};

            /**
                The last user who modified the file. This field will be null if
                the user's account has been deleted.
            */
        QString modifiedBy()const{return m_modified_by;};
        FileSharingInfo& setModifiedby(const QString& arg){m_modified_by=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<FileSharingInfo>  create(const QByteArray& data);
            static std::unique_ptr<FileSharingInfo>  create(const QJsonObject& js);
        };



    protected:
            /**
                ID of shared folder that holds this file.
            */
        QString m_parent_shared_folder_id;

            /**
                The last user who modified the file. This field will be null if
                the user's account has been deleted.
            */
        QString m_modified_by;

    };//FileSharingInfo

}//files
}//dropboxQt
