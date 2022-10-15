/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesWriteError.h"

namespace dropboxQt{
namespace files{
    class SaveUrlError{
        /**
            field: download_failed: Failed downloading the given URL.
            field: invalid_url: The given URL is invalid.
            field: not_found: The file where the URL is saved to no longer
                exists.
        */
    public:
        enum Tag{

        /*None*/
        SaveUrlError_PATH,
        /*Failed downloading the given URL.*/
        SaveUrlError_DOWNLOAD_FAILED,
        /*The given URL is invalid.*/
        SaveUrlError_INVALID_URL,
        /*The file where the URL is saved to no longer exists.*/
        SaveUrlError_NOT_FOUND,
        /*None*/
        SaveUrlError_OTHER
        };

        SaveUrlError(){}
        SaveUrlError(Tag v):m_tag(v){}
        virtual ~SaveUrlError(){}

        Tag tag()const{return m_tag;}
        ///None
        const WriteError& getPath()const{API_CHECK_STATE((SaveUrlError_PATH == m_tag), "expected tag: SaveUrlError_PATH", m_tag);return m_path;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<SaveUrlError>  create(const QByteArray& data);
            static std::unique_ptr<SaveUrlError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        WriteError m_path;
    };//SaveUrlError

}//files
}//dropboxQt
