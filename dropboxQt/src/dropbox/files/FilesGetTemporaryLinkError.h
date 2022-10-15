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
    class GetTemporaryLinkError{
    public:
        enum Tag{

        /*None*/
        GetTemporaryLinkError_PATH,
        /*None*/
        GetTemporaryLinkError_OTHER
        };

        GetTemporaryLinkError(){}
        GetTemporaryLinkError(Tag v):m_tag(v){}
        virtual ~GetTemporaryLinkError(){}

        Tag tag()const{return m_tag;}
        ///None
        const LookupError& getPath()const{API_CHECK_STATE((GetTemporaryLinkError_PATH == m_tag), "expected tag: GetTemporaryLinkError_PATH", m_tag);return m_path;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GetTemporaryLinkError>  create(const QByteArray& data);
            static std::unique_ptr<GetTemporaryLinkError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        LookupError m_path;
    };//GetTemporaryLinkError

}//files
}//dropboxQt
