/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesWriteError.h"

namespace dropboxQt{
namespace files{
    class SaveCopyReferenceError{
        /**
            field: invalid_copy_reference: The copy reference is invalid.
            field: no_permission: You don't have permission to save the given
                copy reference. Please make sure this app is same app which
                created the copy reference and the source user is still linked
                to the app.
            field: not_found: The file referenced by the copy reference cannot
                be found.
            field: too_many_files: The operation would involve more than 10,000
                files and folders.
        */
    public:
        enum Tag{

        /*None*/
        SaveCopyReferenceError_PATH,
        /*The copy reference is invalid.*/
        SaveCopyReferenceError_INVALID_COPY_REFERENCE,
        /*You don't have permission to save the given copy reference. Please make sure this app is same app which created the copy reference and the source user is still linked to the app.*/
        SaveCopyReferenceError_NO_PERMISSION,
        /*The file referenced by the copy reference cannot be found.*/
        SaveCopyReferenceError_NOT_FOUND,
        /*The operation would involve more than 10,000 files and folders.*/
        SaveCopyReferenceError_TOO_MANY_FILES,
        /*None*/
        SaveCopyReferenceError_OTHER
        };

        SaveCopyReferenceError(){}
        SaveCopyReferenceError(Tag v):m_tag(v){}
        virtual ~SaveCopyReferenceError(){}

        Tag tag()const{return m_tag;}
        ///None
        const WriteError& getPath()const{API_CHECK_STATE((SaveCopyReferenceError_PATH == m_tag), "expected tag: SaveCopyReferenceError_PATH", m_tag);return m_path;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<SaveCopyReferenceError>  create(const QByteArray& data);
            static std::unique_ptr<SaveCopyReferenceError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        WriteError m_path;
    };//SaveCopyReferenceError

}//files
}//dropboxQt
