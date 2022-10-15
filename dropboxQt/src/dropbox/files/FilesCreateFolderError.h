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
    class CreateFolderError{
    public:
        enum Tag{

        /*None*/
        CreateFolderError_PATH
        };

        CreateFolderError(){}
        CreateFolderError(Tag v):m_tag(v){}
        virtual ~CreateFolderError(){}

        Tag tag()const{return m_tag;}
        ///None
        const WriteError& getPath()const{API_CHECK_STATE((CreateFolderError_PATH == m_tag), "expected tag: CreateFolderError_PATH", m_tag);return m_path;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<CreateFolderError>  create(const QByteArray& data);
            static std::unique_ptr<CreateFolderError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        WriteError m_path;
    };//CreateFolderError

}//files
}//dropboxQt
