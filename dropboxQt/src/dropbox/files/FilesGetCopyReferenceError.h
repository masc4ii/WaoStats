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
    class GetCopyReferenceError{
    public:
        enum Tag{

        /*None*/
        GetCopyReferenceError_PATH,
        /*None*/
        GetCopyReferenceError_OTHER
        };

        GetCopyReferenceError(){}
        GetCopyReferenceError(Tag v):m_tag(v){}
        virtual ~GetCopyReferenceError(){}

        Tag tag()const{return m_tag;}
        ///None
        const LookupError& getPath()const{API_CHECK_STATE((GetCopyReferenceError_PATH == m_tag), "expected tag: GetCopyReferenceError_PATH", m_tag);return m_path;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GetCopyReferenceError>  create(const QByteArray& data);
            static std::unique_ptr<GetCopyReferenceError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        LookupError m_path;
    };//GetCopyReferenceError

}//files
}//dropboxQt
