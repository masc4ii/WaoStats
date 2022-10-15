#pragma once
#include <QString>

namespace dropboxQt{

    class DropboxWebAuth;

    class DropboxAuthInfo
    {
        friend class DropboxWebAuth;
    public:
        DropboxAuthInfo();

        QString getAccessToken()const {return accessToken;}

        bool readFromFile(QString path);
        bool storeToFile(QString path)const;

    protected:
        QString accessToken;
    };
}//dropboxQt
