/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingSharedLinkMetadata.h"

namespace dropboxQt{
namespace sharing{
    class ListSharedLinksResult{
        /**
            field: links: Shared links applicable to the path argument.
            field: has_more: Is true if there are additional shared links that
                have not been returned yet. Pass the cursor into
                :meth:`list_shared_links` to retrieve them.
            field: cursor: Pass the cursor into :meth:`list_shared_links` to
                obtain the additional links. Cursor is returned only if no path
                is given or the path is empty.
        */

    public:
        ListSharedLinksResult(){};

        ListSharedLinksResult(const std::list <SharedLinkMetadata>& arg){ m_links = arg; };
        virtual ~ListSharedLinksResult(){};

    public:
            /**
                Shared links applicable to the path argument.
            */
        const std::list <SharedLinkMetadata>& links()const{return m_links;};

            /**
                Is true if there are additional shared links that have not been
                returned yet. Pass the cursor into :meth:`list_shared_links` to
                retrieve them.
            */
        bool hasMore()const{return m_has_more;};

            /**
                Pass the cursor into :meth:`list_shared_links` to obtain the
                additional links. Cursor is returned only if no path is given or
                the path is empty.
            */
        QString cursor()const{return m_cursor;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListSharedLinksResult>  create(const QByteArray& data);
            static std::unique_ptr<ListSharedLinksResult>  create(const QJsonObject& js);
        };



    protected:
            /**
                Shared links applicable to the path argument.
            */
        std::list <SharedLinkMetadata> m_links;

            /**
                Is true if there are additional shared links that have not been
                returned yet. Pass the cursor into :meth:`list_shared_links` to
                retrieve them.
            */
        bool m_has_more;

            /**
                Pass the cursor into :meth:`list_shared_links` to obtain the
                additional links. Cursor is returned only if no path is given or
                the path is empty.
            */
        QString m_cursor;

    };//ListSharedLinksResult

}//sharing
}//dropboxQt
