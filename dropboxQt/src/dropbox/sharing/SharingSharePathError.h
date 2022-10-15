/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingSharedFolderMetadata.h"

namespace dropboxQt{
namespace sharing{
    class SharePathError{
        /**
            field: is_file: A file is at the specified path.
            field: inside_shared_folder: We do not support sharing a folder
                inside a shared folder.
            field: contains_shared_folder: We do not support shared folders that
                contain shared folders.
            field: is_app_folder: We do not support sharing an app folder.
            field: inside_app_folder: We do not support sharing a folder inside
                an app folder.
            field: is_public_folder: A public folder can't be shared this way.
                Use a public link instead.
            field: inside_public_folder: A folder inside a public folder can't
                be shared this way. Use a public link instead.
            field: already_shared: Folder is already shared. Contains metadata
                about the existing shared folder.
            field: invalid_path: Path is not valid.
            field: is_osx_package: We do not support sharing a Mac OS X package.
            field: inside_osx_package: We do not support sharing a folder inside
                a Mac OS X package.
        */
    public:
        enum Tag{

        /*A file is at the specified path.*/
        SharePathError_IS_FILE,
        /*We do not support sharing a folder inside a shared folder.*/
        SharePathError_INSIDE_SHARED_FOLDER,
        /*We do not support shared folders that contain shared folders.*/
        SharePathError_CONTAINS_SHARED_FOLDER,
        /*We do not support sharing an app folder.*/
        SharePathError_IS_APP_FOLDER,
        /*We do not support sharing a folder inside an app folder.*/
        SharePathError_INSIDE_APP_FOLDER,
        /*A public folder can't be shared this way. Use a public link instead.*/
        SharePathError_IS_PUBLIC_FOLDER,
        /*A folder inside a public folder can't be shared this way. Use a public link instead.*/
        SharePathError_INSIDE_PUBLIC_FOLDER,
        /*Folder is already shared. Contains metadata about the existing shared folder.*/
        SharePathError_ALREADY_SHARED,
        /*Path is not valid.*/
        SharePathError_INVALID_PATH,
        /*We do not support sharing a Mac OS X package.*/
        SharePathError_IS_OSX_PACKAGE,
        /*We do not support sharing a folder inside a Mac OS X package.*/
        SharePathError_INSIDE_OSX_PACKAGE,
        /*None*/
        SharePathError_OTHER
        };

        SharePathError(){}
        SharePathError(Tag v):m_tag(v){}
        virtual ~SharePathError(){}

        Tag tag()const{return m_tag;}
        ///Folder is already shared. Contains metadata about the existing shared folder.
        const SharedFolderMetadata& getAlreadyShared()const{API_CHECK_STATE((SharePathError_ALREADY_SHARED == m_tag), "expected tag: SharePathError_ALREADY_SHARED", m_tag);return m_already_shared;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<SharePathError>  create(const QByteArray& data);
            static std::unique_ptr<SharePathError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        SharedFolderMetadata m_already_shared;
    };//SharePathError

}//sharing
}//dropboxQt
