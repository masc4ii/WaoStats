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
    class ListSharedLinksError{
        /**
            field: reset: Indicates that the cursor has been invalidated. Call
                :meth:`list_shared_links` to obtain a new cursor.
        */
    public:
        enum Tag{

        /*None*/
        ListSharedLinksError_PATH,
        /*Indicates that the cursor has been invalidated. Call :route:`list_shared_links` to obtain a new cursor.*/
        ListSharedLinksError_RESET,
        /*None*/
        ListSharedLinksError_OTHER
        };

        ListSharedLinksError(){}
        ListSharedLinksError(Tag v):m_tag(v){}
        virtual ~ListSharedLinksError(){}

        Tag tag()const{return m_tag;}
        ///None
        const files::LookupError& getPath()const{API_CHECK_STATE((ListSharedLinksError_PATH == m_tag), "expected tag: ListSharedLinksError_PATH", m_tag);return m_path;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListSharedLinksError>  create(const QByteArray& data);
            static std::unique_ptr<ListSharedLinksError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        files::LookupError m_path;
    };//ListSharedLinksError

}//sharing
}//dropboxQt
