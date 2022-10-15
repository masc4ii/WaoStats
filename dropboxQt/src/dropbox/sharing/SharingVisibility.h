/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"

namespace dropboxQt{
namespace sharing{
    class Visibility{
        /**
            Who can access a shared link. The most open visibility is
            ``public``. The default depends on many aspects, such as team and
            user preferences and shared folder settings.

            field: public: Anyone who has received the link can access it. No
                login required.
            field: team_only: Only members of the same team can access the link.
                Login is required.
            field: password: A link-specific password is required to access the
                link. Login is not required.
            field: team_and_password: Only members of the same team who have the
                link-specific password can access the link.
            field: shared_folder_only: Only members of the shared folder
                containing the linked file can access the link. Login is
                required.
        */
    public:
        enum Tag{

        /*Anyone who has received the link can access it. No login required.*/
        Visibility_PUBLIC,
        /*Only members of the same team can access the link. Login is required.*/
        Visibility_TEAM_ONLY,
        /*A link-specific password is required to access the link. Login is not required.*/
        Visibility_PASSWORD,
        /*Only members of the same team who have the link-specific password can access the link.*/
        Visibility_TEAM_AND_PASSWORD,
        /*Only members of the shared folder containing the linked file can access the link. Login is required.*/
        Visibility_SHARED_FOLDER_ONLY,
        /*None*/
        Visibility_OTHER
        };

        Visibility(){}
        Visibility(Tag v):m_tag(v){}
        virtual ~Visibility(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<Visibility>  create(const QByteArray& data);
            static std::unique_ptr<Visibility>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//Visibility

}//sharing
}//dropboxQt
