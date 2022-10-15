/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"

namespace dropboxQt{
namespace files{
    class WriteConflictError{
        /**
            field: file: There's a file in the way.
            field: folder: There's a folder in the way.
            field: file_ancestor: There's a file at an ancestor path, so we
                couldn't create the required parent folders.
        */
    public:
        enum Tag{

        /*There's a file in the way.*/
        WriteConflictError_FILE,
        /*There's a folder in the way.*/
        WriteConflictError_FOLDER,
        /*There's a file at an ancestor path, so we couldn't create the required parent folders.*/
        WriteConflictError_FILE_ANCESTOR,
        /*None*/
        WriteConflictError_OTHER
        };

        WriteConflictError(){}
        WriteConflictError(Tag v):m_tag(v){}
        virtual ~WriteConflictError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<WriteConflictError>  create(const QByteArray& data);
            static std::unique_ptr<WriteConflictError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//WriteConflictError

}//files
}//dropboxQt
