#include "ApiException.h"

using namespace dropboxQt;


std::unique_ptr<DropboxException> DropboxException::create(const QByteArray& data, int status_code, const std::string& message)
{
    std::string summary;
    if (!data.isEmpty())
    {
            QJsonDocument doc = QJsonDocument::fromJson(data);
            QJsonObject js_in = doc.object();           
            summary = js_in["error_summary"].toString().toStdString();
    }
    return std::unique_ptr<DropboxException>(new DropboxException(summary, status_code, message));
};

void DropboxException::build(std::string err)
{
    m_what = m_msg;
    m_what += "\n";
    if(!m_error_summary.empty())m_what += "SUMMARY:" + m_error_summary;
    m_what += "\n";
    if(!err.empty())
        {
            m_what += "ERROR:\n";
            m_what += err;
        }
}
