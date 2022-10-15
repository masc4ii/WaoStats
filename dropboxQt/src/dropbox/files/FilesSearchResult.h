/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesSearchMatch.h"

namespace dropboxQt{
namespace files{
    class SearchResult{
        /**
            field: matches: A list (possibly empty) of matches for the query.
            field: more: Used for paging. If true, indicates there is another
                page of results available that can be fetched by calling
                :meth:`search` again.
            field: start: Used for paging. Value to set the start argument to
                when calling :meth:`search` to fetch the next page of results.
        */

    public:
        SearchResult(){};

        SearchResult(const std::list <SearchMatch>& arg){ m_matches = arg; };
        virtual ~SearchResult(){};

    public:
            /**
                A list (possibly empty) of matches for the query.
            */
        const std::list <SearchMatch>& matches()const{return m_matches;};

            /**
                Used for paging. If true, indicates there is another page of
                results available that can be fetched by calling :meth:`search`
                again.
            */
        bool more()const{return m_more;};

            /**
                Used for paging. Value to set the start argument to when calling
                :meth:`search` to fetch the next page of results.
            */
        int start()const{return m_start;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<SearchResult>  create(const QByteArray& data);
            static std::unique_ptr<SearchResult>  create(const QJsonObject& js);
        };



    protected:
            /**
                A list (possibly empty) of matches for the query.
            */
        std::list <SearchMatch> m_matches;

            /**
                Used for paging. If true, indicates there is another page of
                results available that can be fetched by calling :meth:`search`
                again.
            */
        bool m_more;

            /**
                Used for paging. Value to set the start argument to when calling
                :meth:`search` to fetch the next page of results.
            */
        int m_start = {0};

    };//SearchResult

}//files
}//dropboxQt
