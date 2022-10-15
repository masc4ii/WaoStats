/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamDateRangeError.h"

namespace dropboxQt{

namespace team{
///DateRangeError

DateRangeError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void DateRangeError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case DateRangeError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void DateRangeError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("other") == 0){
        m_tag = DateRangeError_OTHER;

    }
}

QString DateRangeError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "DateRangeError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<DateRangeError>  DateRangeError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<DateRangeError> rv = std::unique_ptr<DateRangeError>(new DateRangeError);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
