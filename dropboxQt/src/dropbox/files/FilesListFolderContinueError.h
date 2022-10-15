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
    class ListFolderContinueError{
        /**
            field: reset: Indicates that the cursor has been invalidated. Call
                :meth:`list_folder` to obtain a new cursor.
        */
    public:
        enum Tag{

        /*None*/
        ListFolderContinueError_PATH,
        /*Indicates that the cursor has been invalidated. Call :route:`list_folder` to obtain a new cursor.*/
        ListFolderContinueError_RESET,
        /*None*/
        ListFolderContinueError_OTHER
        };

        ListFolderContinueError(){}
        ListFolderContinueError(Tag v):m_tag(v){}
        virtual ~ListFolderContinueError(){}

        Tag tag()const{return m_tag;}
        ///None
        const LookupError& getPath()const{API_CHECK_STATE((ListFolderContinueError_PATH == m_tag), "expected tag: ListFolderContinueError_PATH", m_tag);return m_path;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListFolderContinueError>  create(const QByteArray& data);
            static std::unique_ptr<ListFolderContinueError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        LookupError m_path;
    };//ListFolderContinueError

}//files
}//dropboxQt
