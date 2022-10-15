/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "properties"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/properties/PropertiesPropertyType.h"

namespace dropboxQt{

namespace properties{
///PropertyType

PropertyType::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void PropertyType::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case PropertyType_STRING:{
            if(!name.isEmpty())
                js[name] = QString("string");
        }break;
        case PropertyType_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void PropertyType::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("string") == 0){
        m_tag = PropertyType_STRING;

    }
    else if(s.compare("other") == 0){
        m_tag = PropertyType_OTHER;

    }
}

QString PropertyType::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "PropertyType");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<PropertyType>  PropertyType::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<PropertyType> rv = std::unique_ptr<PropertyType>(new PropertyType);
    rv->fromJson(js);
    return rv;
}

}//properties
}//dropboxQt
