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
    class WriteMode{
        /**
            Your intent when writing a file to some path. This is used to
            determine what constitutes a conflict and what the autorename
            strategy is. In some situations, the conflict behavior is identical:
            (a) If the target path doesn't contain anything, the file is always
            written; no conflict. (b) If the target path contains a folder, it's
            always a conflict. (c) If the target path contains a file with
            identical contents, nothing gets written; no conflict. The conflict
            checking differs in the case where there's a file at the target path
            with contents different from the contents you're trying to write.

            field: add: Never overwrite the existing file. The autorename
                strategy is to append a number to the file name. For example,
                "document.txt" might become "document (2).txt".
            field: overwrite: Always overwrite the existing file. The autorename
                strategy is the same as it is for ``add``.
            field: update: Overwrite if the given "rev" matches the existing
                file's "rev". The autorename strategy is to append the string
                "conflicted copy" to the file name. For example, "document.txt"
                might become "document (conflicted copy).txt" or "document
                (Panda's conflicted copy).txt".
        */
    public:
        enum Tag{

        /*Never overwrite the existing file. The autorename strategy is to append a number to the file name. For example, "document.txt" might become "document (2).txt".*/
        WriteMode_ADD,
        /*Always overwrite the existing file. The autorename strategy is the same as it is for :field:`add`.*/
        WriteMode_OVERWRITE,
        /*Overwrite if the given "rev" matches the existing file's "rev". The autorename strategy is to append the string "conflicted copy" to the file name. For example, "document.txt" might become "document (conflicted copy).txt" or "document (Panda's conflicted copy).txt".*/
        WriteMode_UPDATE
        };

        WriteMode(){}
        WriteMode(Tag v):m_tag(v){}
        virtual ~WriteMode(){}

        Tag tag()const{return m_tag;}
        ///Overwrite if the given "rev" matches the existing file's "rev". The autorename strategy is to append the string "conflicted copy" to the file name. For example, "document.txt" might become "document (conflicted copy).txt" or "document (Panda's conflicted copy).txt".
        QString getUpdate()const{API_CHECK_STATE((WriteMode_UPDATE == m_tag), "expected tag: WriteMode_UPDATE", m_tag);return m_update;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<WriteMode>  create(const QByteArray& data);
            static std::unique_ptr<WriteMode>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        QString m_update;
    };//WriteMode

}//files
}//dropboxQt
