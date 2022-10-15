/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesDimensions.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///Dimensions

Dimensions::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void Dimensions::toJson(QJsonObject& js)const{

    js["height"] = QString("%1").arg(m_height);
    js["width"] = QString("%1").arg(m_width);
}

void Dimensions::fromJson(const QJsonObject& js){

    m_height = js["height"].toVariant().toString().toULongLong();
    m_width = js["width"].toVariant().toString().toULongLong();
}

QString Dimensions::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<Dimensions>  Dimensions::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<Dimensions>  Dimensions::factory::create(const QJsonObject& js)
{
    std::unique_ptr<Dimensions> rv;
    rv = std::unique_ptr<Dimensions>(new Dimensions);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
