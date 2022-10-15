/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingListFoldersContinueArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///ListFoldersContinueArg

ListFoldersContinueArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ListFoldersContinueArg::toJson(QJsonObject& js)const{

    if(!m_cursor.isEmpty())
        js["cursor"] = QString(m_cursor);
}

void ListFoldersContinueArg::fromJson(const QJsonObject& js){

    m_cursor = js["cursor"].toString();
}

QString ListFoldersContinueArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ListFoldersContinueArg>  ListFoldersContinueArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ListFoldersContinueArg>  ListFoldersContinueArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ListFoldersContinueArg> rv;
    rv = std::unique_ptr<ListFoldersContinueArg>(new ListFoldersContinueArg);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
