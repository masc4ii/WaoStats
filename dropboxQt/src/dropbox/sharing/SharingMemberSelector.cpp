/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingMemberSelector.h"

namespace dropboxQt{

namespace sharing{
///MemberSelector

MemberSelector::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void MemberSelector::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case MemberSelector_DROPBOX_ID:{
            if(!name.isEmpty())
                js[name] = QString("dropbox_id");
            if(!m_dropbox_id.isEmpty())
                js["dropbox_id"] = QString(m_dropbox_id);
        }break;
        case MemberSelector_EMAIL:{
            if(!name.isEmpty())
                js[name] = QString("email");
            if(!m_email.isEmpty())
                js["email"] = QString(m_email);
        }break;
        case MemberSelector_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void MemberSelector::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("dropbox_id") == 0){
        m_tag = MemberSelector_DROPBOX_ID;
        m_dropbox_id = js["dropbox_id"].toString();
    }
    else if(s.compare("email") == 0){
        m_tag = MemberSelector_EMAIL;
        m_email = js["email"].toString();
    }
    else if(s.compare("other") == 0){
        m_tag = MemberSelector_OTHER;

    }
}

QString MemberSelector::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "MemberSelector");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<MemberSelector>  MemberSelector::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<MemberSelector> rv = std::unique_ptr<MemberSelector>(new MemberSelector);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
