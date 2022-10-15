/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesListFolderContinueArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///ListFolderContinueArg

ListFolderContinueArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ListFolderContinueArg::toJson(QJsonObject& js)const{

    if(!m_cursor.isEmpty())
        js["cursor"] = QString(m_cursor);
}

void ListFolderContinueArg::fromJson(const QJsonObject& js){

    m_cursor = js["cursor"].toString();
}

QString ListFolderContinueArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ListFolderContinueArg>  ListFolderContinueArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ListFolderContinueArg>  ListFolderContinueArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ListFolderContinueArg> rv;
    rv = std::unique_ptr<ListFolderContinueArg>(new ListFolderContinueArg);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
