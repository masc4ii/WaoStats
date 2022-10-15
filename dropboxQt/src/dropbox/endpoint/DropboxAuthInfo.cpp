#include <QJsonObject>
#include "DropboxAuthInfo.h"
#include "ApiUtil.h"

using namespace dropboxQt;

DropboxAuthInfo::DropboxAuthInfo()
{
};

bool DropboxAuthInfo::readFromFile(QString path)
{
    QJsonObject js;
    if(!loadJsonFromFile(path, js))
        return false;
    accessToken = js["access_token"].toString();
    return true;
};

bool DropboxAuthInfo::storeToFile(QString path)const
{
    QJsonObject js;
    js["access_token"] = accessToken;

    if(!storeJsonToFile(path, js))
        return false;
    return true;

};
