#include "DropboxHost.h"

using namespace dropboxQt;

DropboxHost default_dbx_host;

DropboxHost::DropboxHost():
    api("api.dropboxapi.com"),
    content("content.dropboxapi.com"),
    web("www.dropbox.com"),
    notify("notify.dropboxapi.com")
{
};

DropboxHost& DropboxHost::DEFAULT()
{
    return default_dbx_host;
};

void DropboxHost::toJson(QJsonObject& js)const
{
    js["api"] = api;
    js["content"] = content;
    js["web"] = web;
    js["notify"] = notify;
};

void DropboxHost::fromJson(const QJsonObject& js)
{
    api = js["api"].toString();
    content = js["content"].toString();
    web = js["web"].toString();
    notify = js["notify"].toString();
};
