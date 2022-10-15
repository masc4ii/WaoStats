/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesLookupError.h"

namespace dropboxQt{
namespace files{
    class ListFolderError{
    public:
        enum Tag{

        /*None*/
        ListFolderError_PATH,
        /*None*/
        ListFolderError_OTHER
        };

        ListFolderError(){}
        ListFolderError(Tag v):m_tag(v){}
        virtual ~ListFolderError(){}

        Tag tag()const{return m_tag;}
        ///None
        const LookupError& getPath()const{API_CHECK_STATE((ListFolderError_PATH == m_tag), "expected tag: ListFolderError_PATH", m_tag);return m_path;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListFolderError>  create(const QByteArray& data);
            static std::unique_ptr<ListFolderError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        LookupError m_path;
    };//ListFolderError

}//files
}//dropboxQt
