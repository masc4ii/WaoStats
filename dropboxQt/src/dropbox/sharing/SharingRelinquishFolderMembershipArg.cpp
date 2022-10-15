/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingRelinquishFolderMembershipArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///RelinquishFolderMembershipArg

RelinquishFolderMembershipArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void RelinquishFolderMembershipArg::toJson(QJsonObject& js)const{

    if(!m_shared_folder_id.isEmpty())
        js["shared_folder_id"] = QString(m_shared_folder_id);
    js["leave_a_copy"] = m_leave_a_copy;
}

void RelinquishFolderMembershipArg::fromJson(const QJsonObject& js){

    m_shared_folder_id = js["shared_folder_id"].toString();
    m_leave_a_copy = js["leave_a_copy"].toVariant().toBool();
}

QString RelinquishFolderMembershipArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<RelinquishFolderMembershipArg>  RelinquishFolderMembershipArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<RelinquishFolderMembershipArg>  RelinquishFolderMembershipArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<RelinquishFolderMembershipArg> rv;
    rv = std::unique_ptr<RelinquishFolderMembershipArg>(new RelinquishFolderMembershipArg);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
