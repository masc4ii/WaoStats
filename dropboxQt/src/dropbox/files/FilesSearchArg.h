/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesSearchMode.h"

namespace dropboxQt{
namespace files{
    class SearchArg{
        /**
            field: path: The path in the user's Dropbox to search. Should
                probably be a folder.
            field: query: The string to search for. The search string is split
                on spaces into multiple tokens. For file name searching, the
                last token is used for prefix matching (i.e. "bat c" matches
                "bat cave" but not "batman car").
            field: start: The starting index within the search results (used for
                paging).
            field: max_results: The maximum number of search results to return.
            field: mode: The search mode (filename, filename_and_content, or
                deleted_filename). Note that searching file content is only
                available for Dropbox Business accounts.
        */

    public:
        SearchArg():
        m_start(0)
        ,m_max_results(100)
        ,m_mode(SearchMode::SearchMode_FILENAME)
        {};

        SearchArg(const QString& arg):
        m_start(0)
        ,m_max_results(100)
        ,m_mode(SearchMode::SearchMode_FILENAME)
        { m_path = arg; };
        virtual ~SearchArg(){};

    public:
            /**
                The path in the user's Dropbox to search. Should probably be a
                folder.
            */
        QString path()const{return m_path;};
        SearchArg& setPath(const QString& arg){m_path=arg;return *this;};

            /**
                The string to search for. The search string is split on spaces
                into multiple tokens. For file name searching, the last token is
                used for prefix matching (i.e. "bat c" matches "bat cave" but
                not "batman car").
            */
        QString query()const{return m_query;};
        SearchArg& setQuery(const QString& arg){m_query=arg;return *this;};

            /**
                The starting index within the search results (used for paging).
            */
        int start()const{return m_start;};
        SearchArg& setStart(const int& arg){m_start=arg;return *this;};

            /**
                The maximum number of search results to return.
            */
        int maxResults()const{return m_max_results;};
        SearchArg& setMaxresults(const int& arg){m_max_results=arg;return *this;};

            /**
                The search mode (filename, filename_and_content, or
                deleted_filename). Note that searching file content is only
                available for Dropbox Business accounts.
            */
        const SearchMode& mode()const{return m_mode;};
        SearchArg& setMode(const SearchMode& arg){m_mode=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<SearchArg>  create(const QByteArray& data);
            static std::unique_ptr<SearchArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                The path in the user's Dropbox to search. Should probably be a
                folder.
            */
        QString m_path;

            /**
                The string to search for. The search string is split on spaces
                into multiple tokens. For file name searching, the last token is
                used for prefix matching (i.e. "bat c" matches "bat cave" but
                not "batman car").
            */
        QString m_query;

            /**
                The starting index within the search results (used for paging).
            */
        int m_start = {0};

            /**
                The maximum number of search results to return.
            */
        int m_max_results = {0};

            /**
                The search mode (filename, filename_and_content, or
                deleted_filename). Note that searching file content is only
                available for Dropbox Business accounts.
            */
        SearchMode m_mode;

    };//SearchArg

}//files
}//dropboxQt
