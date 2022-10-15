/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamApiApp.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///ApiApp

ApiApp::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ApiApp::toJson(QJsonObject& js)const{

    if(!m_app_id.isEmpty())
        js["app_id"] = QString(m_app_id);
    if(!m_app_name.isEmpty())
        js["app_name"] = QString(m_app_name);
    if(!m_publisher.isEmpty())
        js["publisher"] = QString(m_publisher);
    if(!m_publisher_url.isEmpty())
        js["publisher_url"] = QString(m_publisher_url);
    if(m_linked.isValid())
        js["linked"] = m_linked.toString("yyyy-MM-ddThh:mm:ssZ");
    js["is_app_folder"] = m_is_app_folder;
}

void ApiApp::fromJson(const QJsonObject& js){

    m_app_id = js["app_id"].toString();
    m_app_name = js["app_name"].toString();
    m_publisher = js["publisher"].toString();
    m_publisher_url = js["publisher_url"].toString();
    m_linked = QDateTime::fromString(js["linked"].toString(), "yyyy-MM-ddThh:mm:ssZ");
    m_is_app_folder = js["is_app_folder"].toVariant().toBool();
}

QString ApiApp::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ApiApp>  ApiApp::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ApiApp>  ApiApp::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ApiApp> rv;
    rv = std::unique_ptr<ApiApp>(new ApiApp);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
