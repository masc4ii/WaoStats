#include <QFile>
#include <QJsonObject>
#include "DropboxAppInfo.h"
#include "DropboxHost.h"
#include "ApiUtil.h"

using namespace dropboxQt;

DropboxAppInfo::DropboxAppInfo():
    m_key(""),
    m_secret("")
{
    
};

void DropboxAppInfo::setKeySecret(QString key_val, QString secret_val)
{
    m_key = key_val;
    m_secret = secret_val;
};

bool DropboxAppInfo::readFromFile(QString path)
{
    QJsonObject js;
    if(!loadJsonFromFile(path, js))
        return false;
    m_key = js["key"].toString();
    m_secret = js["secret"].toString();
    return true;
};

bool DropboxAppInfo::storeToFile(QString path)
{
    QJsonObject js;
    js["key"] = m_key;
    js["secret"] = m_secret;

    if(!storeJsonToFile(path, js))
        return false;
    return true;
};
