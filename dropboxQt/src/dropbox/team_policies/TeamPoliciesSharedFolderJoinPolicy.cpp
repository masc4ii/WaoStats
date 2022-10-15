/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team_policies"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team_policies/TeamPoliciesSharedFolderJoinPolicy.h"

namespace dropboxQt{

namespace team_policies{
///SharedFolderJoinPolicy

SharedFolderJoinPolicy::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void SharedFolderJoinPolicy::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case SharedFolderJoinPolicy_FROM_TEAM_ONLY:{
            if(!name.isEmpty())
                js[name] = QString("from_team_only");
        }break;
        case SharedFolderJoinPolicy_FROM_ANYONE:{
            if(!name.isEmpty())
                js[name] = QString("from_anyone");
        }break;
        case SharedFolderJoinPolicy_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void SharedFolderJoinPolicy::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("from_team_only") == 0){
        m_tag = SharedFolderJoinPolicy_FROM_TEAM_ONLY;

    }
    else if(s.compare("from_anyone") == 0){
        m_tag = SharedFolderJoinPolicy_FROM_ANYONE;

    }
    else if(s.compare("other") == 0){
        m_tag = SharedFolderJoinPolicy_OTHER;

    }
}

QString SharedFolderJoinPolicy::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "SharedFolderJoinPolicy");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<SharedFolderJoinPolicy>  SharedFolderJoinPolicy::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<SharedFolderJoinPolicy> rv = std::unique_ptr<SharedFolderJoinPolicy>(new SharedFolderJoinPolicy);
    rv->fromJson(js);
    return rv;
}

}//team_policies
}//dropboxQt
