/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingModifySharedLinkSettingsArgs.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///ModifySharedLinkSettingsArgs

ModifySharedLinkSettingsArgs::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ModifySharedLinkSettingsArgs::toJson(QJsonObject& js)const{

    if(!m_url.isEmpty())
        js["url"] = QString(m_url);
    js["settings"] = (QJsonObject)m_settings;
    js["remove_expiration"] = m_remove_expiration;
}

void ModifySharedLinkSettingsArgs::fromJson(const QJsonObject& js){

    m_url = js["url"].toString();
    m_settings.fromJson(js["settings"].toObject());
    m_remove_expiration = js["remove_expiration"].toVariant().toBool();
}

QString ModifySharedLinkSettingsArgs::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ModifySharedLinkSettingsArgs>  ModifySharedLinkSettingsArgs::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ModifySharedLinkSettingsArgs>  ModifySharedLinkSettingsArgs::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ModifySharedLinkSettingsArgs> rv;
    rv = std::unique_ptr<ModifySharedLinkSettingsArgs>(new ModifySharedLinkSettingsArgs);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
