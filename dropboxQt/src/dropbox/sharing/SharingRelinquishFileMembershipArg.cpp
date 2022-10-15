/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingRelinquishFileMembershipArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///RelinquishFileMembershipArg

RelinquishFileMembershipArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void RelinquishFileMembershipArg::toJson(QJsonObject& js)const{

    if(!m_file.isEmpty())
        js["file"] = QString(m_file);
}

void RelinquishFileMembershipArg::fromJson(const QJsonObject& js){

    m_file = js["file"].toString();
}

QString RelinquishFileMembershipArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<RelinquishFileMembershipArg>  RelinquishFileMembershipArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<RelinquishFileMembershipArg>  RelinquishFileMembershipArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<RelinquishFileMembershipArg> rv;
    rv = std::unique_ptr<RelinquishFileMembershipArg>(new RelinquishFileMembershipArg);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
