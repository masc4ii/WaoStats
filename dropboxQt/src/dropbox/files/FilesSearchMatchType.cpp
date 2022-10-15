/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesSearchMatchType.h"

namespace dropboxQt{

namespace files{
///SearchMatchType

SearchMatchType::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void SearchMatchType::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case SearchMatchType_FILENAME:{
            if(!name.isEmpty())
                js[name] = QString("filename");
        }break;
        case SearchMatchType_CONTENT:{
            if(!name.isEmpty())
                js[name] = QString("content");
        }break;
        case SearchMatchType_BOTH:{
            if(!name.isEmpty())
                js[name] = QString("both");
        }break;
    }//switch
}

void SearchMatchType::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("filename") == 0){
        m_tag = SearchMatchType_FILENAME;

    }
    else if(s.compare("content") == 0){
        m_tag = SearchMatchType_CONTENT;

    }
    else if(s.compare("both") == 0){
        m_tag = SearchMatchType_BOTH;

    }
}

QString SearchMatchType::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "SearchMatchType");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<SearchMatchType>  SearchMatchType::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<SearchMatchType> rv = std::unique_ptr<SearchMatchType>(new SearchMatchType);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
