#include <functional>
#include <QFile>
#include "DropboxClient.h"
#include "dropbox/auth/AuthRoutes.h"
#include "dropbox/files/FilesRoutes.h"
#include "dropbox/sharing/SharingRoutes.h"
#include "dropbox/team/TeamRoutes.h"
#include "dropbox/users/UsersRoutes.h"
#include "dropbox/endpoint/Endpoint.h"

using namespace dropboxQt;

DropboxClient::DropboxClient()
{
    m_endpoint.reset(new Endpoint(this));
};

DropboxClient::DropboxClient(const QString& access_token)
:ApiClient(access_token)
{
    m_endpoint.reset(new Endpoint(this));
};

DropboxClient::~DropboxClient(){

};

QString DropboxClient::lastApiCall(){return m_endpoint->lastRequestInfo();}


auth::AuthRoutes* DropboxClient::getAuth(){
    if(!m_AuthRoutes){
        m_AuthRoutes.reset(new auth::AuthRoutes(m_endpoint.get()));
    };
    return m_AuthRoutes.get();
};


files::FilesRoutes* DropboxClient::getFiles(){
    if(!m_FilesRoutes){
        m_FilesRoutes.reset(new files::FilesRoutes(m_endpoint.get()));
    };
    return m_FilesRoutes.get();
};


sharing::SharingRoutes* DropboxClient::getSharing(){
    if(!m_SharingRoutes){
        m_SharingRoutes.reset(new sharing::SharingRoutes(m_endpoint.get()));
    };
    return m_SharingRoutes.get();
};

team::TeamRoutes* DropboxClient::getTeam(){
    if(!m_TeamRoutes){
        m_TeamRoutes.reset(new team::TeamRoutes(m_endpoint.get()));
    };
    return m_TeamRoutes.get();
};



users::UsersRoutes* DropboxClient::getUsers(){
    if(!m_UsersRoutes){
        m_UsersRoutes.reset(new users::UsersRoutes(m_endpoint.get()));
    };
    return m_UsersRoutes.get();
};

#ifdef DROPBOX_QT_AUTOTEST
Endpoint* DropboxClient::getEndpoint(){return m_endpoint.get();}
#endif //DROPBOX_QT_AUTOTEST


bool DropboxClient::downloadFile(QString dropboxFilePath, QString localDestinationPath)
{
    bool rv = false;

    QFile out(localDestinationPath);
    if (!out.open(QFile::WriteOnly | QIODevice::Truncate)){
        qWarning() << "Error opening file: " << localDestinationPath;
        return false;
    }
    
    try
        {
            files::DownloadArg arg(dropboxFilePath);
            std::unique_ptr<files::Metadata> res = getFiles()->download(arg, &out);
            rv = true;
        }
    catch (DropboxException& e)
        {
            qWarning() << "DropboxClient::downloadFile Exception: " << e.what();
        }

    out.close();
    return rv;
};

bool DropboxClient::uploadFile(QString localFilePath, QString dropboxDestinationPath, bool overwriteIfExists)
{
    bool rv = false;

    QFile file_in(localFilePath);
    if(!file_in.open(QFile::ReadOnly)){
        qWarning() << "Error opening file: " << localFilePath;
        return false;
    }
    
    try
        {
            files::CommitInfo arg(dropboxDestinationPath);
            if(overwriteIfExists){
                arg.setMode(files::WriteMode::WriteMode_OVERWRITE);
            }
            getFiles()->upload(arg, &file_in);
            rv = true;
        }
    catch(DropboxException& e)
        {
            qWarning() << "DropboxClient::uploadFile Exception: " << e.what();
        }
    file_in.close();
    return rv;
};

bool DropboxClient::upgradeDropboxFile(QString localFilePath, QString dropboxDestinationPath)
{
    QString dropboxTmpFile = dropboxDestinationPath + "._tmp";
    if(!uploadFile(localFilePath, dropboxTmpFile)){
        return false;
    }

    if(fileExists(dropboxDestinationPath)){
        if(!deleteFile(dropboxDestinationPath)){
            qWarning() << "DropboxClient::upgradeDropboxFile failed to delete file:" << dropboxDestinationPath;
            return false;
        }
    }

    if(!moveFile(dropboxTmpFile, dropboxDestinationPath)){
        qWarning() << "DropboxClient::upgradeDropboxFile failed to move file:" << dropboxTmpFile << dropboxDestinationPath;
        return false;
    }

    return true;
};

bool DropboxClient::createFolder(QString dropboxPath)
{
    bool rv = false;
    try
        {
            files::CreateFolderArg arg(dropboxPath);
            std::unique_ptr<files::FolderMetadata> res = getFiles()->createFolder(arg);
            rv = true;
        }
    catch(DropboxException& e)
        {
            qWarning() << "DropboxClient::createFolder Exception: " << e.what();
        }
    return rv;
};

bool DropboxClient::ensureFolder(QString dropboxPath)
{
    bool rv = false;

    if(folderExists(dropboxPath))
        return true;

    try
        {

            files::CreateFolderArg arg(dropboxPath);
            std::unique_ptr<files::FolderMetadata> res = getFiles()->createFolder(arg);
            rv = true;
        }
    catch(DropboxException& e)
        {
            qWarning() << "DropboxClient::createFolder Exception: " << e.what();
        }
    return rv;
};

std::list<QString> DropboxClient::listFolder(QString dropboxPath)
{
    std::list<QString> rv;
    
    try
        {       
            std::function<void(const std::unique_ptr<files::ListFolderResult>& r)> add_folder_entries = [&](const std::unique_ptr<files::ListFolderResult>& r)
            {
                const FOLDER_ENTRIES& entries = r->entries();
                for(FOLDER_ENTRIES::const_iterator i = entries.cbegin(); i != entries.cend(); i++)
                    {
                        const std::unique_ptr<files::Metadata>& m = *i;
                        rv.push_back(m->name());
                    }       
            };

            files::ListFolderArg arg(dropboxPath);
            std::unique_ptr<files::ListFolderResult> r = getFiles()->listFolder(arg);
            add_folder_entries(r);
            while(r->hasMore())
                {
                    files::ListFolderContinueArg continue_arg(r->cursor());
                    r = getFiles()->listFolderContinue(continue_arg);
                    add_folder_entries(r);
                }
        }
    catch(DropboxException& e)
        {
            qWarning() << "DropboxClient::lsFolder Exception: " << e.what();
        }
    return rv;
};

bool DropboxClient::deleteFile(QString dropboxPath)
{
    bool rv = false;
    try
        {
            files::DeleteArg d(dropboxPath);
            getFiles()->deleteOperation(d);
            rv = true;
        }
    catch(DropboxException& e)
        {
            qWarning() << "DropboxClient::deleteFile Exception: " << e.what();
        }
    return rv;
};

bool DropboxClient::moveFile(QString moveFrom, QString moveTo)
{
    bool rv = false;
    try
        {
            files::RelocationArg r_arg;
            r_arg.setFrompath(moveFrom).setTopath(moveTo);
            getFiles()->move(r_arg);
            rv = true;
        }
    catch(DropboxException& e)
        {
            qWarning() << "DropboxClient::deleteFile Exception: " << e.what();
        }
    return rv;
};

bool DropboxClient::fileExists(QString dropboxPath)
{
    bool rv = false;
    try
        {
            std::unique_ptr<files::Metadata> md  = getFiles()->getMetadata(dropboxPath);
            files::FileMetadata* asFile = dynamic_cast<files::FileMetadata*>(md.get());
            if(asFile != NULL){
                rv = true;
            }
        }
    catch(DropboxException& e)
        {
            qWarning() << "DropboxClient::fileExists Exception: " << e.what();
        }
    return rv;
};

bool DropboxClient::folderExists(QString dropboxPath)
{
    bool rv = false;
    try
        {
            std::unique_ptr<files::Metadata> md  = getFiles()->getMetadata(dropboxPath);
            files::FolderMetadata* asFolder = dynamic_cast<files::FolderMetadata*>(md.get());
            if(asFolder != NULL){
                rv = true;
            }
        }
    catch(DropboxException& e)
        {
            qWarning() << "DropboxClient::folderExists Exception: " << e.what();
        }
    return rv;

};

void DropboxClient::cancellAll()
{
    m_endpoint->cancelAll();
};
