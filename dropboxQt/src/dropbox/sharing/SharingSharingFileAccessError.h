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
    class SharingFileAccessError{
        /**
            User could not access this file.

            field: no_permission: Current user does not have sufficient
                privileges to perform the desired action.
            field: invalid_file: File specified was not found.
            field: is_folder: A folder can't be shared this way. Use folder
                sharing or a shared link instead.
            field: inside_public_folder: A file inside a public folder can't be
                shared this way. Use a public link instead.
            field: inside_osx_package: A Mac OS X package can't be shared this
                way. Use a shared link instead.
        */
    public:
        enum Tag{

        /*Current user does not have sufficient privileges to perform the desired action.*/
        SharingFileAccessError_NO_PERMISSION,
        /*File specified was not found.*/
        SharingFileAccessError_INVALID_FILE,
        /*A folder can't be shared this way. Use folder sharing or a shared link instead.*/
        SharingFileAccessError_IS_FOLDER,
        /*A file inside a public folder can't be shared this way. Use a public link instead.*/
        SharingFileAccessError_INSIDE_PUBLIC_FOLDER,
        /*A Mac OS X package can't be shared this way. Use a shared link instead.*/
        SharingFileAccessError_INSIDE_OSX_PACKAGE,
        /*None*/
        SharingFileAccessError_OTHER
        };

        SharingFileAccessError(){}
        SharingFileAccessError(Tag v):m_tag(v){}
        virtual ~SharingFileAccessError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<SharingFileAccessError>  create(const QByteArray& data);
            static std::unique_ptr<SharingFileAccessError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//SharingFileAccessError

}//sharing
}//dropboxQt
