#pragma once

#include <QString>
#include "DropboxAuthInfo.h"

namespace dropboxQt{
    class DropboxAppInfo;

    class DropboxWebAuth
    {
    public:
        /**
            getCodeAuthorizeUrl - format string that should be opened to enable
            Dropbox access and request for access token, which will be used in all
            API interactions.
            appInfo - information about application, that represends cliend side API,
            includes client id, secret key.
            redirectUrl - URI that will be used by Dropbox to deliver code, if empty
            it will appear on user browser page
            antiCSRFstate - up to 500 bytes of arbitrary data that will be delivered along
            with code to the redirect URI. CSRF stands for "cross-site request forgery"
        */
        static QString getCodeAuthorizeUrl(const DropboxAppInfo& appInfo, QString redirectUrl = "", QString antiCSRFstate = "");

        /**
           getTokenFromCode - makes http call to Dropbox to retrive
           access token by providing authorize code
         */
        static DropboxAuthInfo getTokenFromCode(const DropboxAppInfo& appInfo, QString code);

        /**
           getCodeFromRedirectServer - this is not a Dropbox utility, it queries client maintained web server that will keep temporary
           assigned code (after Dropbox redirects to URL provided in getCodeAuthorizeUrl)
           antiCSRFstate is the same string, used in getCodeAuthorizeUrl

           The requirements for redirect server are simple:
           1.store 'code' and antiCSRFstate string after dropbox request to redirectUrl in local DB
           2.reply to the POST-request for 'code' (compare request parameter with antiCSRFstate) with json string: {"code":"code-value"}
           3.delete temporary code-record (code is valid only for a short time )
         */
        static QString getCodeFromRedirectServer(QString httpsRedirectUrl, QString antiCSRFstate);
    };
};
