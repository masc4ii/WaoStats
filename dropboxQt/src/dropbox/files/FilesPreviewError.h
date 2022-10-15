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

namespace dropboxQt{
namespace files{
    class PreviewError{
        /**
            field: path: An error occurs when downloading metadata for the file.
            field: in_progress: This preview generation is still in progress and
                the file is not ready  for preview yet.
            field: unsupported_extension: The file extension is not supported
                preview generation.
            field: unsupported_content: The file content is not supported for
                preview generation.
        */
    public:
        enum Tag{

        /*An error occurs when downloading metadata for the file.*/
        PreviewError_PATH,
        /*This preview generation is still in progress and the file is not ready  for preview yet.*/
        PreviewError_IN_PROGRESS,
        /*The file extension is not supported preview generation.*/
        PreviewError_UNSUPPORTED_EXTENSION,
        /*The file content is not supported for preview generation.*/
        PreviewError_UNSUPPORTED_CONTENT
        };

        PreviewError(){}
        PreviewError(Tag v):m_tag(v){}
        virtual ~PreviewError(){}

        Tag tag()const{return m_tag;}
        ///An error occurs when downloading metadata for the file.
        const LookupError& getPath()const{API_CHECK_STATE((PreviewError_PATH == m_tag), "expected tag: PreviewError_PATH", m_tag);return m_path;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<PreviewError>  create(const QByteArray& data);
            static std::unique_ptr<PreviewError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        LookupError m_path;
    };//PreviewError

}//files
}//dropboxQt
