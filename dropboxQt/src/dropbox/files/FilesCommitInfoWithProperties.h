/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesCommitInfo.h"
#include "dropbox/properties/PropertiesPropertyGroup.h"

namespace dropboxQt{
namespace files{
    class CommitInfoWithProperties : public CommitInfo{
        /**
            field: property_groups: List of custom properties to add to file.
        */

    public:
        CommitInfoWithProperties(){};

        CommitInfoWithProperties(const std::list <properties::PropertyGroup>& arg){ m_property_groups = arg; };
        virtual ~CommitInfoWithProperties(){};

    public:
            /**
                List of custom properties to add to file.
            */
        const std::list <properties::PropertyGroup>& propertyGroups()const{return m_property_groups;};
        CommitInfoWithProperties& setPropertygroups(const std::list <properties::PropertyGroup>& arg){m_property_groups=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<CommitInfoWithProperties>  create(const QByteArray& data);
            static std::unique_ptr<CommitInfoWithProperties>  create(const QJsonObject& js);
        };



    protected:
            /**
                List of custom properties to add to file.
            */
        std::list <properties::PropertyGroup> m_property_groups;

    };//CommitInfoWithProperties

}//files
}//dropboxQt
