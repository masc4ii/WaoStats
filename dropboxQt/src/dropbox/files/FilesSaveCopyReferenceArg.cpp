/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesSaveCopyReferenceArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///SaveCopyReferenceArg

SaveCopyReferenceArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void SaveCopyReferenceArg::toJson(QJsonObject& js)const{

    if(!m_copy_reference.isEmpty())
        js["copy_reference"] = QString(m_copy_reference);
    if(!m_path.isEmpty())
        js["path"] = QString(m_path);
}

void SaveCopyReferenceArg::fromJson(const QJsonObject& js){

    m_copy_reference = js["copy_reference"].toString();
    m_path = js["path"].toString();
}

QString SaveCopyReferenceArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<SaveCopyReferenceArg>  SaveCopyReferenceArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<SaveCopyReferenceArg>  SaveCopyReferenceArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<SaveCopyReferenceArg> rv;
    rv = std::unique_ptr<SaveCopyReferenceArg>(new SaveCopyReferenceArg);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
