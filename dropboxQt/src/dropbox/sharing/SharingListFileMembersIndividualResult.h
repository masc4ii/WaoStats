/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingListFileMembersCountResult.h"
#include "dropbox/sharing/SharingSharingFileAccessError.h"

namespace dropboxQt{
namespace sharing{
    class ListFileMembersIndividualResult{
        /**
            field: result: The results of the query for this file if it was
                successful
            field: access_error: The result of the query for this file if it was
                an error.
        */
    public:
        enum Tag{

        /*The results of the query for this file if it was successful*/
        ListFileMembersIndividualResult_RESULT,
        /*The result of the query for this file if it was an error.*/
        ListFileMembersIndividualResult_ACCESS_ERROR,
        /*None*/
        ListFileMembersIndividualResult_OTHER
        };

        ListFileMembersIndividualResult(){}
        ListFileMembersIndividualResult(Tag v):m_tag(v){}
        virtual ~ListFileMembersIndividualResult(){}

        Tag tag()const{return m_tag;}
        ///The results of the query for this file if it was successful
        const ListFileMembersCountResult& getResult()const{API_CHECK_STATE((ListFileMembersIndividualResult_RESULT == m_tag), "expected tag: ListFileMembersIndividualResult_RESULT", m_tag);return m_result;};

        ///The result of the query for this file if it was an error.
        const SharingFileAccessError& getAccessError()const{API_CHECK_STATE((ListFileMembersIndividualResult_ACCESS_ERROR == m_tag), "expected tag: ListFileMembersIndividualResult_ACCESS_ERROR", m_tag);return m_access_error;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListFileMembersIndividualResult>  create(const QByteArray& data);
            static std::unique_ptr<ListFileMembersIndividualResult>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        ListFileMembersCountResult m_result;
        SharingFileAccessError m_access_error;
    };//ListFileMembersIndividualResult

}//sharing
}//dropboxQt
