/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesSearchMode.h"

namespace dropboxQt{

namespace files{
///SearchMode

SearchMode::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void SearchMode::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case SearchMode_FILENAME:{
            if(!name.isEmpty())
                js[name] = QString("filename");
        }break;
        case SearchMode_FILENAME_AND_CONTENT:{
            if(!name.isEmpty())
                js[name] = QString("filename_and_content");
        }break;
        case SearchMode_DELETED_FILENAME:{
            if(!name.isEmpty())
                js[name] = QString("deleted_filename");
        }break;
    }//switch
}

void SearchMode::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("filename") == 0){
        m_tag = SearchMode_FILENAME;

    }
    else if(s.compare("filename_and_content") == 0){
        m_tag = SearchMode_FILENAME_AND_CONTENT;

    }
    else if(s.compare("deleted_filename") == 0){
        m_tag = SearchMode_DELETED_FILENAME;

    }
}

QString SearchMode::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "SearchMode");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<SearchMode>  SearchMode::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<SearchMode> rv = std::unique_ptr<SearchMode>(new SearchMode);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
