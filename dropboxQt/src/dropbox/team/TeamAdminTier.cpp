/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamAdminTier.h"

namespace dropboxQt{

namespace team{
///AdminTier

AdminTier::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void AdminTier::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case AdminTier_TEAM_ADMIN:{
            if(!name.isEmpty())
                js[name] = QString("team_admin");
        }break;
        case AdminTier_USER_MANAGEMENT_ADMIN:{
            if(!name.isEmpty())
                js[name] = QString("user_management_admin");
        }break;
        case AdminTier_SUPPORT_ADMIN:{
            if(!name.isEmpty())
                js[name] = QString("support_admin");
        }break;
        case AdminTier_MEMBER_ONLY:{
            if(!name.isEmpty())
                js[name] = QString("member_only");
        }break;
    }//switch
}

void AdminTier::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("team_admin") == 0){
        m_tag = AdminTier_TEAM_ADMIN;

    }
    else if(s.compare("user_management_admin") == 0){
        m_tag = AdminTier_USER_MANAGEMENT_ADMIN;

    }
    else if(s.compare("support_admin") == 0){
        m_tag = AdminTier_SUPPORT_ADMIN;

    }
    else if(s.compare("member_only") == 0){
        m_tag = AdminTier_MEMBER_ONLY;

    }
}

QString AdminTier::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "AdminTier");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<AdminTier>  AdminTier::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<AdminTier> rv = std::unique_ptr<AdminTier>(new AdminTier);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
