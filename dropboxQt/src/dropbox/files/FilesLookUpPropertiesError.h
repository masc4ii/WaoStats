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
    class LookUpPropertiesError{
        /**
            field: property_group_not_found: This property group does not exist
                for this file.
        */
    public:
        enum Tag{

        /*This property group does not exist for this file.*/
        LookUpPropertiesError_PROPERTY_GROUP_NOT_FOUND
        };

        LookUpPropertiesError(){}
        LookUpPropertiesError(Tag v):m_tag(v){}
        virtual ~LookUpPropertiesError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<LookUpPropertiesError>  create(const QByteArray& data);
            static std::unique_ptr<LookUpPropertiesError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//LookUpPropertiesError

}//files
}//dropboxQt
