#include "Endpoint.h"

using namespace dropboxQt;

Endpoint::Endpoint(ApiClient* c):ApiEndpoint(c)
{

}

QString Endpoint::prepareErrorInfo(int status_code, const QUrl& url, const QByteArray& data)
{
    QString rv = QString("ERROR. Unexpected status %1 %2 ").arg(status_code).arg(url.url());
    rv += data;
    rv += "\n";
    rv += lastRequestInfo();
    return rv;
};

