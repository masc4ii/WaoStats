/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesCommitInfo.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///CommitInfo

CommitInfo::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void CommitInfo::toJson(QJsonObject& js)const{

    if(!m_path.isEmpty())
        js["path"] = QString(m_path);
    m_mode.toJson(js, "mode");
    js["autorename"] = m_autorename;
    if(m_client_modified.isValid())
        js["client_modified"] = m_client_modified.toString("yyyy-MM-ddThh:mm:ssZ");
    js["mute"] = m_mute;
}

void CommitInfo::fromJson(const QJsonObject& js){

    m_path = js["path"].toString();
    m_mode.fromJson(js["mode"].toObject());
    m_autorename = js["autorename"].toVariant().toBool();
    m_client_modified = QDateTime::fromString(js["client_modified"].toString(), "yyyy-MM-ddThh:mm:ssZ");
    m_mute = js["mute"].toVariant().toBool();
}

QString CommitInfo::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<CommitInfo>  CommitInfo::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<CommitInfo>  CommitInfo::factory::create(const QJsonObject& js)
{
    std::unique_ptr<CommitInfo> rv;
    rv = std::unique_ptr<CommitInfo>(new CommitInfo);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
