/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "async"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/async/AsyncPollEmptyResult.h"

namespace dropboxQt{

namespace async{
///PollEmptyResult

PollEmptyResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void PollEmptyResult::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case PollResultBase_IN_PROGRESS:{
            if(!name.isEmpty())
                js[name] = QString("in_progress");
        }break;
        case PollEmptyResult_COMPLETE:{
            if(!name.isEmpty())
                js[name] = QString("complete");
        }break;
    }//switch
}

void PollEmptyResult::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("in_progress") == 0){
        m_tag = PollResultBase_IN_PROGRESS;

    }
    if(s.compare("complete") == 0){
        m_tag = PollEmptyResult_COMPLETE;

    }
}

QString PollEmptyResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "PollEmptyResult");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<PollEmptyResult>  PollEmptyResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<PollEmptyResult> rv = std::unique_ptr<PollEmptyResult>(new PollEmptyResult);
    rv->fromJson(js);
    return rv;
}

}//async
}//dropboxQt
