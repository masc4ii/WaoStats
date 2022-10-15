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
    class FileErrorResult{
        /**
            field: file_not_found_error: File specified by id was not found.
            field: invalid_file_action_error: User does not have permission to
                take the specified action on the file.
            field: permission_denied_error: User does not have permission to
                access file specified by file.Id.
        */
    public:
        enum Tag{

        /*File specified by id was not found.*/
        FileErrorResult_FILE_NOT_FOUND_ERROR,
        /*User does not have permission to take the specified action on the file.*/
        FileErrorResult_INVALID_FILE_ACTION_ERROR,
        /*User does not have permission to access file specified by file.Id.*/
        FileErrorResult_PERMISSION_DENIED_ERROR,
        /*None*/
        FileErrorResult_OTHER
        };

        FileErrorResult(){}
        FileErrorResult(Tag v):m_tag(v){}
        virtual ~FileErrorResult(){}

        Tag tag()const{return m_tag;}
        ///File specified by id was not found.
        QString getFileNotFoundError()const{API_CHECK_STATE((FileErrorResult_FILE_NOT_FOUND_ERROR == m_tag), "expected tag: FileErrorResult_FILE_NOT_FOUND_ERROR", m_tag);return m_file_not_found_error;};

        ///User does not have permission to take the specified action on the file.
        QString getInvalidFileActionError()const{API_CHECK_STATE((FileErrorResult_INVALID_FILE_ACTION_ERROR == m_tag), "expected tag: FileErrorResult_INVALID_FILE_ACTION_ERROR", m_tag);return m_invalid_file_action_error;};

        ///User does not have permission to access file specified by file.Id.
        QString getPermissionDeniedError()const{API_CHECK_STATE((FileErrorResult_PERMISSION_DENIED_ERROR == m_tag), "expected tag: FileErrorResult_PERMISSION_DENIED_ERROR", m_tag);return m_permission_denied_error;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<FileErrorResult>  create(const QByteArray& data);
            static std::unique_ptr<FileErrorResult>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        QString m_file_not_found_error;
        QString m_invalid_file_action_error;
        QString m_permission_denied_error;
    };//FileErrorResult

}//sharing
}//dropboxQt
