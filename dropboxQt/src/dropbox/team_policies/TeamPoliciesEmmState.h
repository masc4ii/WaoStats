/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team_policies"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"

namespace dropboxQt{
namespace team_policies{
    class EmmState{
        /**
            field: disabled: Emm token is disabled
            field: optional: Emm token is optional
            field: required: Emm token is required
        */
    public:
        enum Tag{

        /*Emm token is disabled*/
        EmmState_DISABLED,
        /*Emm token is optional*/
        EmmState_OPTIONAL,
        /*Emm token is required*/
        EmmState_REQUIRED,
        /*None*/
        EmmState_OTHER
        };

        EmmState(){}
        EmmState(Tag v):m_tag(v){}
        virtual ~EmmState(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<EmmState>  create(const QByteArray& data);
            static std::unique_ptr<EmmState>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//EmmState

}//team_policies
}//dropboxQt
