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
    class SearchMatchType{
        /**
            Indicates what type of match was found for a given item.

            field: filename: This item was matched on its file or folder name.
            field: content: This item was matched based on its file contents.
            field: both: This item was matched based on both its contents and
                its file name.
        */
    public:
        enum Tag{

        /*This item was matched on its file or folder name.*/
        SearchMatchType_FILENAME,
        /*This item was matched based on its file contents.*/
        SearchMatchType_CONTENT,
        /*This item was matched based on both its contents and its file name.*/
        SearchMatchType_BOTH
        };

        SearchMatchType(){}
        SearchMatchType(Tag v):m_tag(v){}
        virtual ~SearchMatchType(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<SearchMatchType>  create(const QByteArray& data);
            static std::unique_ptr<SearchMatchType>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//SearchMatchType

}//files
}//dropboxQt
