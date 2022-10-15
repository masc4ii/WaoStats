/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "auth"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/DropboxRouteBase.h"

namespace dropboxQt{
namespace auth{


    class AuthRoutes: public DropboxRouteBase{
    public:
        AuthRoutes(Endpoint* ep):DropboxRouteBase(ep){};
            /**
            ApiRoute('token/revoke')


            Disables the access token used to authenticate the call.

            */
        void tokenRevoke(void);
        DropboxVoidTask* tokenRevoke_Async();
        void tokenRevoke_AsyncCB(
            std::function<void()> completed_callback = nullptr,
            std::function<void(std::unique_ptr<DropboxException>)> failed_callback = nullptr);

    protected:
    };//AuthRoutes

}//auth
}//dropboxQt
