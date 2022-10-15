/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "auth"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/auth/AuthRoutes.h"
#include "dropbox/endpoint/Endpoint.h"
using namespace dropboxQt;
using namespace auth;

void AuthRoutes::tokenRevoke(){
    tokenRevoke_Async()->waitForResultAndRelease();
}

DropboxVoidTask* AuthRoutes::tokenRevoke_Async()
{
    DropboxVoidTask* t = m_end_point->produceVoidTask();
    m_end_point->rpcStyle<
        DropboxException>
        ("2/auth/token/revoke",
        t);
    return t;
}

void AuthRoutes::tokenRevoke_AsyncCB(
    std::function<void()> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        DropboxException>
        ("2/auth/token/revoke",
        completed_callback,
        failed_callback);
}

