/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesListFolderLongpollArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///ListFolderLongpollArg

ListFolderLongpollArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ListFolderLongpollArg::toJson(QJsonObject& js)const{

    if(!m_cursor.isEmpty())
        js["cursor"] = QString(m_cursor);
    js["timeout"] = QString("%1").arg(m_timeout);
}

void ListFolderLongpollArg::fromJson(const QJsonObject& js){

    m_cursor = js["cursor"].toString();
    m_timeout = js["timeout"].toVariant().toString().toULongLong();
}

QString ListFolderLongpollArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ListFolderLongpollArg>  ListFolderLongpollArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ListFolderLongpollArg>  ListFolderLongpollArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ListFolderLongpollArg> rv;
    rv = std::unique_ptr<ListFolderLongpollArg>(new ListFolderLongpollArg);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
