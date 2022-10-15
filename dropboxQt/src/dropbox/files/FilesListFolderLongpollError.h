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
    class ListFolderLongpollError{
        /**
            field: reset: Indicates that the cursor has been invalidated. Call
                :meth:`list_folder` to obtain a new cursor.
        */
    public:
        enum Tag{

        /*Indicates that the cursor has been invalidated. Call :route:`list_folder` to obtain a new cursor.*/
        ListFolderLongpollError_RESET,
        /*None*/
        ListFolderLongpollError_OTHER
        };

        ListFolderLongpollError(){}
        ListFolderLongpollError(Tag v):m_tag(v){}
        virtual ~ListFolderLongpollError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListFolderLongpollError>  create(const QByteArray& data);
            static std::unique_ptr<ListFolderLongpollError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//ListFolderLongpollError

}//files
}//dropboxQt
