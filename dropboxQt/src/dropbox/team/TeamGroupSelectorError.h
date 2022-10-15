/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"

namespace dropboxQt{
namespace team{
    class GroupSelectorError{
        /**
            Error that can be raised when :class:`GroupSelector` is used.

            field: group_not_found: No matching group found. No groups match the
                specified group ID.
        */
    public:
        enum Tag{

        /*No matching group found. No groups match the specified group ID.*/
        GroupSelectorError_GROUP_NOT_FOUND,
        /*None*/
        GroupSelectorError_OTHER
        };

        GroupSelectorError(){}
        GroupSelectorError(Tag v):m_tag(v){}
        virtual ~GroupSelectorError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GroupSelectorError>  create(const QByteArray& data);
            static std::unique_ptr<GroupSelectorError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//GroupSelectorError

}//team
}//dropboxQt
