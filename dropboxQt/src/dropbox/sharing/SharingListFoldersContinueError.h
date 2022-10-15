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
    class ListFoldersContinueError{
        /**
            field: invalid_cursor: ``ListFoldersContinueArg.cursor`` is invalid.
        */
    public:
        enum Tag{

        /*:field:`ListFoldersContinueArg.cursor` is invalid.*/
        ListFoldersContinueError_INVALID_CURSOR,
        /*None*/
        ListFoldersContinueError_OTHER
        };

        ListFoldersContinueError(){}
        ListFoldersContinueError(Tag v):m_tag(v){}
        virtual ~ListFoldersContinueError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListFoldersContinueError>  create(const QByteArray& data);
            static std::unique_ptr<ListFoldersContinueError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//ListFoldersContinueError

}//sharing
}//dropboxQt
