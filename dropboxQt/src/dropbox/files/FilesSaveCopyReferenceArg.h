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
    class SaveCopyReferenceArg{
        /**
            field: copy_reference: A copy reference returned by
                :meth:`copy_reference_get`.
            field: path: Path in the user's Dropbox that is the destination.
        */

    public:
        SaveCopyReferenceArg(){};

        SaveCopyReferenceArg(const QString& arg){ m_copy_reference = arg; };
        virtual ~SaveCopyReferenceArg(){};

    public:
            /**
                A copy reference returned by :meth:`copy_reference_get`.
            */
        QString copyReference()const{return m_copy_reference;};
        SaveCopyReferenceArg& setCopyreference(const QString& arg){m_copy_reference=arg;return *this;};

            /**
                Path in the user's Dropbox that is the destination.
            */
        QString path()const{return m_path;};
        SaveCopyReferenceArg& setPath(const QString& arg){m_path=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<SaveCopyReferenceArg>  create(const QByteArray& data);
            static std::unique_ptr<SaveCopyReferenceArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                A copy reference returned by :meth:`copy_reference_get`.
            */
        QString m_copy_reference;

            /**
                Path in the user's Dropbox that is the destination.
            */
        QString m_path;

    };//SaveCopyReferenceArg

}//files
}//dropboxQt
