/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamGroupSelectorError.h"

namespace dropboxQt{
namespace team{
    class GroupUpdateError{
        /**
            field: external_id_already_in_use: The new external ID is already
                being used by another group.
        */
    public:
        enum Tag{

        /*No matching group found. No groups match the specified group ID.*/
        GroupSelectorError_GROUP_NOT_FOUND,
        /*None*/
        GroupSelectorError_OTHER,
        /*The new external ID is already being used by another group.*/
        GroupUpdateError_EXTERNAL_ID_ALREADY_IN_USE
        };

        GroupUpdateError(){}
        GroupUpdateError(Tag v):m_tag(v){}
        virtual ~GroupUpdateError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GroupUpdateError>  create(const QByteArray& data);
            static std::unique_ptr<GroupUpdateError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//GroupUpdateError

}//team
}//dropboxQt
