/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "users"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/users/UsersName.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace users{
///Name

Name::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void Name::toJson(QJsonObject& js)const{

    if(!m_given_name.isEmpty())
        js["given_name"] = QString(m_given_name);
    if(!m_surname.isEmpty())
        js["surname"] = QString(m_surname);
    if(!m_familiar_name.isEmpty())
        js["familiar_name"] = QString(m_familiar_name);
    if(!m_display_name.isEmpty())
        js["display_name"] = QString(m_display_name);
    if(!m_abbreviated_name.isEmpty())
        js["abbreviated_name"] = QString(m_abbreviated_name);
}

void Name::fromJson(const QJsonObject& js){

    m_given_name = js["given_name"].toString();
    m_surname = js["surname"].toString();
    m_familiar_name = js["familiar_name"].toString();
    m_display_name = js["display_name"].toString();
    m_abbreviated_name = js["abbreviated_name"].toString();
}

QString Name::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<Name>  Name::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<Name>  Name::factory::create(const QJsonObject& js)
{
    std::unique_ptr<Name> rv;
    rv = std::unique_ptr<Name>(new Name);
    rv->fromJson(js);
    return rv;
}

}//users
}//dropboxQt
