/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamGetActivityReport.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///GetActivityReport

GetActivityReport::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void GetActivityReport::toJson(QJsonObject& js)const{

    BaseDfbReport::toJson(js);
    js["adds"] = ingrl_list2jsonarray(m_adds);
    js["edits"] = ingrl_list2jsonarray(m_edits);
    js["deletes"] = ingrl_list2jsonarray(m_deletes);
    js["active_users_28_day"] = ingrl_list2jsonarray(m_active_users_28_day);
    js["active_users_7_day"] = ingrl_list2jsonarray(m_active_users_7_day);
    js["active_users_1_day"] = ingrl_list2jsonarray(m_active_users_1_day);
    js["active_shared_folders_28_day"] = ingrl_list2jsonarray(m_active_shared_folders_28_day);
    js["active_shared_folders_7_day"] = ingrl_list2jsonarray(m_active_shared_folders_7_day);
    js["active_shared_folders_1_day"] = ingrl_list2jsonarray(m_active_shared_folders_1_day);
    js["shared_links_created"] = ingrl_list2jsonarray(m_shared_links_created);
    js["shared_links_viewed_by_team"] = ingrl_list2jsonarray(m_shared_links_viewed_by_team);
    js["shared_links_viewed_by_outside_user"] = ingrl_list2jsonarray(m_shared_links_viewed_by_outside_user);
    js["shared_links_viewed_by_not_logged_in"] = ingrl_list2jsonarray(m_shared_links_viewed_by_not_logged_in);
    js["shared_links_viewed_total"] = ingrl_list2jsonarray(m_shared_links_viewed_total);
}

void GetActivityReport::fromJson(const QJsonObject& js){

    BaseDfbReport::fromJson(js);
    jsonarray2ingrl_list(js["adds"].toArray(), m_adds);
    jsonarray2ingrl_list(js["edits"].toArray(), m_edits);
    jsonarray2ingrl_list(js["deletes"].toArray(), m_deletes);
    jsonarray2ingrl_list(js["active_users_28_day"].toArray(), m_active_users_28_day);
    jsonarray2ingrl_list(js["active_users_7_day"].toArray(), m_active_users_7_day);
    jsonarray2ingrl_list(js["active_users_1_day"].toArray(), m_active_users_1_day);
    jsonarray2ingrl_list(js["active_shared_folders_28_day"].toArray(), m_active_shared_folders_28_day);
    jsonarray2ingrl_list(js["active_shared_folders_7_day"].toArray(), m_active_shared_folders_7_day);
    jsonarray2ingrl_list(js["active_shared_folders_1_day"].toArray(), m_active_shared_folders_1_day);
    jsonarray2ingrl_list(js["shared_links_created"].toArray(), m_shared_links_created);
    jsonarray2ingrl_list(js["shared_links_viewed_by_team"].toArray(), m_shared_links_viewed_by_team);
    jsonarray2ingrl_list(js["shared_links_viewed_by_outside_user"].toArray(), m_shared_links_viewed_by_outside_user);
    jsonarray2ingrl_list(js["shared_links_viewed_by_not_logged_in"].toArray(), m_shared_links_viewed_by_not_logged_in);
    jsonarray2ingrl_list(js["shared_links_viewed_total"].toArray(), m_shared_links_viewed_total);
}

QString GetActivityReport::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<GetActivityReport>  GetActivityReport::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<GetActivityReport>  GetActivityReport::factory::create(const QJsonObject& js)
{
    std::unique_ptr<GetActivityReport> rv;
    rv = std::unique_ptr<GetActivityReport>(new GetActivityReport);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
