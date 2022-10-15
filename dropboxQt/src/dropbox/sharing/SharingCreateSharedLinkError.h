/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesLookupError.h"

namespace dropboxQt{
namespace sharing{
    class CreateSharedLinkError{
    public:
        enum Tag{

        /*None*/
        CreateSharedLinkError_PATH,
        /*None*/
        CreateSharedLinkError_OTHER
        };

        CreateSharedLinkError(){}
        CreateSharedLinkError(Tag v):m_tag(v){}
        virtual ~CreateSharedLinkError(){}

        Tag tag()const{return m_tag;}
        ///None
        const files::LookupError& getPath()const{API_CHECK_STATE((CreateSharedLinkError_PATH == m_tag), "expected tag: CreateSharedLinkError_PATH", m_tag);return m_path;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<CreateSharedLinkError>  create(const QByteArray& data);
            static std::unique_ptr<CreateSharedLinkError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        files::LookupError m_path;
    };//CreateSharedLinkError

}//sharing
}//dropboxQt
