/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingLinkMetadata.h"

namespace dropboxQt{
namespace sharing{
    class GetSharedLinksResult{
        /**
            field: links: Shared links applicable to the path argument.
        */

    public:
        GetSharedLinksResult(){};

        GetSharedLinksResult(const std::list <LinkMetadata>& arg){ m_links = arg; };
        virtual ~GetSharedLinksResult(){};

    public:
            /**
                Shared links applicable to the path argument.
            */
        const std::list <LinkMetadata>& links()const{return m_links;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GetSharedLinksResult>  create(const QByteArray& data);
            static std::unique_ptr<GetSharedLinksResult>  create(const QJsonObject& js);
        };



    protected:
            /**
                Shared links applicable to the path argument.
            */
        std::list <LinkMetadata> m_links;

    };//GetSharedLinksResult

}//sharing
}//dropboxQt
