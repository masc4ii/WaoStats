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
    class UploadSessionOffsetError{
        /**
            field: correct_offset: The offset up to which data has been
                collected.
        */

    public:
        UploadSessionOffsetError(){};

        UploadSessionOffsetError(const int& arg){ m_correct_offset = arg; };
        virtual ~UploadSessionOffsetError(){};

    public:
            /**
                The offset up to which data has been collected.
            */
        int correctOffset()const{return m_correct_offset;};
        UploadSessionOffsetError& setCorrectoffset(const int& arg){m_correct_offset=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<UploadSessionOffsetError>  create(const QByteArray& data);
            static std::unique_ptr<UploadSessionOffsetError>  create(const QJsonObject& js);
        };



    protected:
            /**
                The offset up to which data has been collected.
            */
        int m_correct_offset = {0};

    };//UploadSessionOffsetError

}//files
}//dropboxQt
