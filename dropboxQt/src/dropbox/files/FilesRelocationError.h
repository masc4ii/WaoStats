/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesLookupError.h"
#include "dropbox/files/FilesWriteError.h"

namespace dropboxQt{
namespace files{
    class RelocationError{
        /**
            field: cant_copy_shared_folder: Shared folders can't be copied.
            field: cant_nest_shared_folder: Your move operation would result in
                nested shared folders.  This is not allowed.
            field: cant_move_folder_into_itself: You cannot move a folder into
                itself.
            field: too_many_files: The operation would involve more than 10,000
                files and folders.
        */
    public:
        enum Tag{

        /*None*/
        RelocationError_FROM_LOOKUP,
        /*None*/
        RelocationError_FROM_WRITE,
        /*None*/
        RelocationError_TO,
        /*Shared folders can't be copied.*/
        RelocationError_CANT_COPY_SHARED_FOLDER,
        /*Your move operation would result in nested shared folders.  This is not allowed.*/
        RelocationError_CANT_NEST_SHARED_FOLDER,
        /*You cannot move a folder into itself.*/
        RelocationError_CANT_MOVE_FOLDER_INTO_ITSELF,
        /*The operation would involve more than 10,000 files and folders.*/
        RelocationError_TOO_MANY_FILES,
        /*None*/
        RelocationError_OTHER
        };

        RelocationError(){}
        RelocationError(Tag v):m_tag(v){}
        virtual ~RelocationError(){}

        Tag tag()const{return m_tag;}
        ///None
        const LookupError& getFromLookup()const{API_CHECK_STATE((RelocationError_FROM_LOOKUP == m_tag), "expected tag: RelocationError_FROM_LOOKUP", m_tag);return m_from_lookup;};

        ///None
        const WriteError& getFromWrite()const{API_CHECK_STATE((RelocationError_FROM_WRITE == m_tag), "expected tag: RelocationError_FROM_WRITE", m_tag);return m_from_write;};

        ///None
        const WriteError& getTo()const{API_CHECK_STATE((RelocationError_TO == m_tag), "expected tag: RelocationError_TO", m_tag);return m_to;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<RelocationError>  create(const QByteArray& data);
            static std::unique_ptr<RelocationError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        LookupError m_from_lookup;
        WriteError m_from_write;
        WriteError m_to;
    };//RelocationError

}//files
}//dropboxQt
