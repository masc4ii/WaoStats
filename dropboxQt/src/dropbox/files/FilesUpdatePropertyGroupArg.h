/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesPropertyGroupUpdate.h"

namespace dropboxQt{
namespace files{
    class UpdatePropertyGroupArg{
        /**
            field: path: A unique identifier for the file.
            field: update_property_groups: Filled custom property templates
                associated with a file.
        */

    public:
        UpdatePropertyGroupArg(){};

        UpdatePropertyGroupArg(const QString& arg){ m_path = arg; };
        virtual ~UpdatePropertyGroupArg(){};

    public:
            /**
                A unique identifier for the file.
            */
        QString path()const{return m_path;};
        UpdatePropertyGroupArg& setPath(const QString& arg){m_path=arg;return *this;};

            /**
                Filled custom property templates associated with a file.
            */
        const std::list <PropertyGroupUpdate>& updatePropertyGroups()const{return m_update_property_groups;};
        UpdatePropertyGroupArg& setUpdatepropertygroups(const std::list <PropertyGroupUpdate>& arg){m_update_property_groups=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<UpdatePropertyGroupArg>  create(const QByteArray& data);
            static std::unique_ptr<UpdatePropertyGroupArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                A unique identifier for the file.
            */
        QString m_path;

            /**
                Filled custom property templates associated with a file.
            */
        std::list <PropertyGroupUpdate> m_update_property_groups;

    };//UpdatePropertyGroupArg

}//files
}//dropboxQt
