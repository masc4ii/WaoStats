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
    class ListRevisionsError{
    public:
        enum Tag{

        /*None*/
        ListRevisionsError_PATH,
        /*None*/
        ListRevisionsError_OTHER
        };

        ListRevisionsError(){}
        ListRevisionsError(Tag v):m_tag(v){}
        virtual ~ListRevisionsError(){}

        Tag tag()const{return m_tag;}
        ///None
        const LookupError& getPath()const{API_CHECK_STATE((ListRevisionsError_PATH == m_tag), "expected tag: ListRevisionsError_PATH", m_tag);return m_path;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListRevisionsError>  create(const QByteArray& data);
            static std::unique_ptr<ListRevisionsError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        LookupError m_path;
    };//ListRevisionsError

}//files
}//dropboxQt
