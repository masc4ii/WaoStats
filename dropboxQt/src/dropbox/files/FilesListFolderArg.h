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
    class ListFolderArg{
        /**
            field: path: The path to the folder you want to see the contents of.
            field: recursive: If true, the list folder operation will be applied
                recursively to all subfolders and the response will contain
                contents of all subfolders.
            field: include_media_info: If true, ``FileMetadata.media_info`` is
                set for photo and video.
            field: include_deleted: If true, the results will include entries
                for files and folders that used to exist but were deleted.
            field: include_has_explicit_shared_members: If true, the results
                will include a flag for each file indicating whether or not
                that file has any explicit members.
        */

    public:
        ListFolderArg():
        m_recursive(false)
        ,m_include_media_info(false)
        ,m_include_deleted(false)
        ,m_include_has_explicit_shared_members(false)
        {};

        ListFolderArg(const QString& arg):
        m_recursive(false)
        ,m_include_media_info(false)
        ,m_include_deleted(false)
        ,m_include_has_explicit_shared_members(false)
        { m_path = arg; };
        virtual ~ListFolderArg(){};

    public:
            /**
                The path to the folder you want to see the contents of.
            */
        QString path()const{return m_path;};
        ListFolderArg& setPath(const QString& arg){m_path=arg;return *this;};

            /**
                If true, the list folder operation will be applied recursively
                to all subfolders and the response will contain contents of all
                subfolders.
            */
        bool recursive()const{return m_recursive;};
        ListFolderArg& setRecursive(const bool& arg){m_recursive=arg;return *this;};

            /**
                If true, ``FileMetadata.media_info`` is set for photo and video.
            */
        bool includeMediaInfo()const{return m_include_media_info;};
        ListFolderArg& setIncludemediainfo(const bool& arg){m_include_media_info=arg;return *this;};

            /**
                If true, the results will include entries for files and folders
                that used to exist but were deleted.
            */
        bool includeDeleted()const{return m_include_deleted;};
        ListFolderArg& setIncludedeleted(const bool& arg){m_include_deleted=arg;return *this;};

            /**
                If true, the results will include a flag for each file
                indicating whether or not  that file has any explicit members.
            */
        bool includeHasExplicitSharedMembers()const{return m_include_has_explicit_shared_members;};
        ListFolderArg& setIncludehasexplicitsharedmembers(const bool& arg){m_include_has_explicit_shared_members=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListFolderArg>  create(const QByteArray& data);
            static std::unique_ptr<ListFolderArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                The path to the folder you want to see the contents of.
            */
        QString m_path;

            /**
                If true, the list folder operation will be applied recursively
                to all subfolders and the response will contain contents of all
                subfolders.
            */
        bool m_recursive;

            /**
                If true, ``FileMetadata.media_info`` is set for photo and video.
            */
        bool m_include_media_info;

            /**
                If true, the results will include entries for files and folders
                that used to exist but were deleted.
            */
        bool m_include_deleted;

            /**
                If true, the results will include a flag for each file
                indicating whether or not  that file has any explicit members.
            */
        bool m_include_has_explicit_shared_members;

    };//ListFolderArg

}//files
}//dropboxQt
