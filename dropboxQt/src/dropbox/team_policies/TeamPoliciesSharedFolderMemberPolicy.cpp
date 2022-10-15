/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team_policies"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team_policies/TeamPoliciesSharedFolderMemberPolicy.h"

namespace dropboxQt{

namespace team_policies{
///SharedFolderMemberPolicy

SharedFolderMemberPolicy::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void SharedFolderMemberPolicy::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case SharedFolderMemberPolicy_TEAM:{
            if(!name.isEmpty())
                js[name] = QString("team");
        }break;
        case SharedFolderMemberPolicy_ANYONE:{
            if(!name.isEmpty())
                js[name] = QString("anyone");
        }break;
        case SharedFolderMemberPolicy_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void SharedFolderMemberPolicy::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("team") == 0){
        m_tag = SharedFolderMemberPolicy_TEAM;

    }
    else if(s.compare("anyone") == 0){
        m_tag = SharedFolderMemberPolicy_ANYONE;

    }
    else if(s.compare("other") == 0){
        m_tag = SharedFolderMemberPolicy_OTHER;

    }
}

QString SharedFolderMemberPolicy::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "SharedFolderMemberPolicy");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<SharedFolderMemberPolicy>  SharedFolderMemberPolicy::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<SharedFolderMemberPolicy> rv = std::unique_ptr<SharedFolderMemberPolicy>(new SharedFolderMemberPolicy);
    rv->fromJson(js);
    return rv;
}

}//team_policies
}//dropboxQt
