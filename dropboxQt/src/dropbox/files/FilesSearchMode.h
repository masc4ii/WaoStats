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
    class SearchMode{
        /**
            field: filename: Search file and folder names.
            field: filename_and_content: Search file and folder names as well as
                file contents.
            field: deleted_filename: Search for deleted file and folder names.
        */
    public:
        enum Tag{

        /*Search file and folder names.*/
        SearchMode_FILENAME,
        /*Search file and folder names as well as file contents.*/
        SearchMode_FILENAME_AND_CONTENT,
        /*Search for deleted file and folder names.*/
        SearchMode_DELETED_FILENAME
        };

        SearchMode(){}
        SearchMode(Tag v):m_tag(v){}
        virtual ~SearchMode(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<SearchMode>  create(const QByteArray& data);
            static std::unique_ptr<SearchMode>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//SearchMode

}//files
}//dropboxQt
