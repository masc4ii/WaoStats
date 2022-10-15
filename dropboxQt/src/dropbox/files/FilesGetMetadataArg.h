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
    class GetMetadataArg{
        /**
            field: path: The path of a file or folder on Dropbox.
            field: include_media_info: If true, ``FileMetadata.media_info`` is
                set for photo and video.
            field: include_deleted: If true, :class:`DeletedMetadata` will be
                returned for deleted file or folder, otherwise
                ``LookupError.not_found`` will be returned.
            field: include_has_explicit_shared_members: If true, the results
                will include a flag for each file indicating whether or not
                that file has any explicit members.
        */

    public:
        GetMetadataArg():
        m_include_media_info(false)
        ,m_include_deleted(false)
        ,m_include_has_explicit_shared_members(false)
        {};

        GetMetadataArg(const QString& arg):
        m_include_media_info(false)
        ,m_include_deleted(false)
        ,m_include_has_explicit_shared_members(false)
        { m_path = arg; };
        virtual ~GetMetadataArg(){};

    public:
            /**
                The path of a file or folder on Dropbox.
            */
        QString path()const{return m_path;};
        GetMetadataArg& setPath(const QString& arg){m_path=arg;return *this;};

            /**
                If true, ``FileMetadata.media_info`` is set for photo and video.
            */
        bool includeMediaInfo()const{return m_include_media_info;};
        GetMetadataArg& setIncludemediainfo(const bool& arg){m_include_media_info=arg;return *this;};

            /**
                If true, :class:`DeletedMetadata` will be returned for deleted
                file or folder, otherwise ``LookupError.not_found`` will be
                returned.
            */
        bool includeDeleted()const{return m_include_deleted;};
        GetMetadataArg& setIncludedeleted(const bool& arg){m_include_deleted=arg;return *this;};

            /**
                If true, the results will include a flag for each file
                indicating whether or not  that file has any explicit members.
            */
        bool includeHasExplicitSharedMembers()const{return m_include_has_explicit_shared_members;};
        GetMetadataArg& setIncludehasexplicitsharedmembers(const bool& arg){m_include_has_explicit_shared_members=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GetMetadataArg>  create(const QByteArray& data);
            static std::unique_ptr<GetMetadataArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                The path of a file or folder on Dropbox.
            */
        QString m_path;

            /**
                If true, ``FileMetadata.media_info`` is set for photo and video.
            */
        bool m_include_media_info;

            /**
                If true, :class:`DeletedMetadata` will be returned for deleted
                file or folder, otherwise ``LookupError.not_found`` will be
                returned.
            */
        bool m_include_deleted;

            /**
                If true, the results will include a flag for each file
                indicating whether or not  that file has any explicit members.
            */
        bool m_include_has_explicit_shared_members;

    };//GetMetadataArg

}//files
}//dropboxQt
