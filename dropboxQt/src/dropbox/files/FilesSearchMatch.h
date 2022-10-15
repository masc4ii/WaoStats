/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesSearchMatchType.h"
#include "dropbox/files/FilesMetadata.h"

namespace dropboxQt{
namespace files{
    class SearchMatch{
        /**
            field: match_type: The type of the match.
            field: metadata: The metadata for the matched file or folder.
        */

    public:
        SearchMatch(){};

        SearchMatch(const SearchMatchType& arg){ m_match_type = arg; };
        virtual ~SearchMatch(){};

    public:
            /**
                The type of the match.
            */
        const SearchMatchType& matchType()const{return m_match_type;};
        SearchMatch& setMatchtype(const SearchMatchType& arg){m_match_type=arg;return *this;};

            /**
                The metadata for the matched file or folder.
            */
        const Metadata& metadata()const{return m_metadata;};
        SearchMatch& setMetadata(const Metadata& arg){m_metadata=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<SearchMatch>  create(const QByteArray& data);
            static std::unique_ptr<SearchMatch>  create(const QJsonObject& js);
        };



    protected:
            /**
                The type of the match.
            */
        SearchMatchType m_match_type;

            /**
                The metadata for the matched file or folder.
            */
        Metadata m_metadata;

    };//SearchMatch

}//files
}//dropboxQt
