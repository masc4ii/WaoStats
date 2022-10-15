/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"

namespace dropboxQt{
namespace sharing{
    class PendingUploadMode{
        /**
            Flag to indicate pending upload default (for linking to
            not-yet-existing paths).

            field: file: Assume pending uploads are files.
            field: folder: Assume pending uploads are folders.
        */
    public:
        enum Tag{

        /*Assume pending uploads are files.*/
        PendingUploadMode_FILE,
        /*Assume pending uploads are folders.*/
        PendingUploadMode_FOLDER
        };

        PendingUploadMode(){}
        PendingUploadMode(Tag v):m_tag(v){}
        virtual ~PendingUploadMode(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<PendingUploadMode>  create(const QByteArray& data);
            static std::unique_ptr<PendingUploadMode>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//PendingUploadMode

}//sharing
}//dropboxQt
