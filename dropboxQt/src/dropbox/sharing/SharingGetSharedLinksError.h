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
    class GetSharedLinksError{
    public:
        enum Tag{

        /*None*/
        GetSharedLinksError_PATH,
        /*None*/
        GetSharedLinksError_OTHER
        };

        GetSharedLinksError(){}
        GetSharedLinksError(Tag v):m_tag(v){}
        virtual ~GetSharedLinksError(){}

        Tag tag()const{return m_tag;}
        ///None
        QString getPath()const{API_CHECK_STATE((GetSharedLinksError_PATH == m_tag), "expected tag: GetSharedLinksError_PATH", m_tag);return m_path;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GetSharedLinksError>  create(const QByteArray& data);
            static std::unique_ptr<GetSharedLinksError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        QString m_path;
    };//GetSharedLinksError

}//sharing
}//dropboxQt
