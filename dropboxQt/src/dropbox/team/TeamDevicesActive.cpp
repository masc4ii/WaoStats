/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamDevicesActive.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///DevicesActive

DevicesActive::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void DevicesActive::toJson(QJsonObject& js)const{

    js["windows"] = ingrl_list2jsonarray(m_windows);
    js["macos"] = ingrl_list2jsonarray(m_macos);
    js["linux"] = ingrl_list2jsonarray(m_linux);
    js["ios"] = ingrl_list2jsonarray(m_ios);
    js["android"] = ingrl_list2jsonarray(m_android);
    js["other"] = ingrl_list2jsonarray(m_other);
    js["total"] = ingrl_list2jsonarray(m_total);
}

void DevicesActive::fromJson(const QJsonObject& js){

    jsonarray2ingrl_list(js["windows"].toArray(), m_windows);
    jsonarray2ingrl_list(js["macos"].toArray(), m_macos);
    jsonarray2ingrl_list(js["linux"].toArray(), m_linux);
    jsonarray2ingrl_list(js["ios"].toArray(), m_ios);
    jsonarray2ingrl_list(js["android"].toArray(), m_android);
    jsonarray2ingrl_list(js["other"].toArray(), m_other);
    jsonarray2ingrl_list(js["total"].toArray(), m_total);
}

QString DevicesActive::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<DevicesActive>  DevicesActive::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<DevicesActive>  DevicesActive::factory::create(const QJsonObject& js)
{
    std::unique_ptr<DevicesActive> rv;
    rv = std::unique_ptr<DevicesActive>(new DevicesActive);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
