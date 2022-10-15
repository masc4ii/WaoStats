#include <iostream>
#include <functional>
#include <QBuffer>
#include <QFile>
#include <QFileInfo>
#include "BoxCommands.h"
#include "dropbox/DropboxClient.h"
#include "dropbox/files/FilesRoutes.h"
#include "dropbox/users/UsersRoutes.h"

using namespace dropboxQt;

BoxCommands::BoxCommands(DropboxClient& c):m_c(c)
{
    m_curr_dir = "/";
};

void BoxCommands::printLastApiCall()
{
    //uncomment to see HTTP request
    /*
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "API call" << std::endl;
    std::cout << m_c.lastApiCall().toStdString() << std::endl;
    */
};

void BoxCommands::account(QString)
{
    try
        {
            std::unique_ptr<users::FullAccount> accountInfo  = m_c.getUsers()->getCurrentAccount();
            std::cout << accountInfo->toString().toStdString() << std::endl;
            printLastApiCall();
        }
    catch(DropboxException& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
};

void BoxCommands::printFileInfo(files::Metadata* md)
{
    files::FileMetadata* asFile = dynamic_cast<files::FileMetadata*>(md);
    if(asFile != NULL){
        std::cout << "FILE id=" << asFile->id().toStdString() << " size=" << asFile->size() << std::endl;
    }
    else{
        files::FolderMetadata* asFolder = dynamic_cast<files::FolderMetadata*>(md);
        if(asFolder != NULL){
            std::cout << "FOLDER id=" << asFolder->id().toStdString() << std::endl;
        }
    }
    std::cout << md->toString().toStdString() << std::endl;
};

void BoxCommands::info(QString fileName)
{
    try
        {
            std::unique_ptr<files::Metadata> md  = m_c.getFiles()->getMetadata(m_curr_dir + fileName);
            printFileInfo(md.get());
            printLastApiCall();
        }
    catch(DropboxException& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
};

void BoxCommands::info_async(QString fileName)
{
    DropboxTask<files::Metadata>* t = m_c.getFiles()->getMetadata_Async(m_curr_dir + fileName);
    try
        {    
            std::unique_ptr<files::Metadata> md  = t->waitForResultAndRelease();
            std::cout << "async-result" << std::endl;
            printFileInfo(md.get());
            printLastApiCall();
        }
    catch(DropboxException& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }            
};

void BoxCommands::pwd(QString)
{
    std::cout << m_curr_dir.toStdString() << std::endl;
};

void BoxCommands::ls(QString)
{
    try
        {
            QString path = m_curr_dir;
            if(path.compare("/") == 0)
                {
                    path = "";
                }
            files::ListFolderArg arg(path);
            std::unique_ptr<files::ListFolderResult> r = m_c.getFiles()->listFolder(arg);
        
            std::function<void(const std::unique_ptr<files::ListFolderResult>& r)> print_folder_entries = [&](const std::unique_ptr<files::ListFolderResult>& r)
                {
                    const std::list<std::unique_ptr<files::Metadata>>& entries = r->entries();
                    for(std::list<std::unique_ptr<files::Metadata>>::const_iterator i = entries.cbegin(); i != entries.cend(); i++)
                        {
                            const std::unique_ptr<files::Metadata>& m = *i;
                            std::cout << m->name().toStdString() << std::endl;
                            // std::cout << m->toString().toStdString() << std::endl;
                        }       
                    
                };

            print_folder_entries(r);
        
            while(r->hasMore())
                {
                    files::ListFolderContinueArg continue_arg(r->cursor());
                    r = m_c.getFiles()->listFolderContinue(continue_arg);
                    print_folder_entries(r);
                }
            printLastApiCall();
        }
    catch(DropboxException& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
};

void BoxCommands::mkdir(QString path)
{
    if(path.isEmpty()){
        std::cout << "ERROR argument reguired" << std::endl;
        return;
    }

    try
        {
            files::CreateFolderArg arg(m_curr_dir + path);
            std::unique_ptr<files::FolderMetadata> res = m_c.getFiles()->createFolder(arg);
            std::cout << "created: " << path.toStdString() << " id=" << res->id().toStdString() << std::endl;
            printLastApiCall();
        }
    catch(DropboxException& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
};

void BoxCommands::cat(QString fileName)
{
    if(fileName.isEmpty()){
        std::cout << "ERROR argument reguired" << std::endl;
        return;
    }

    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);

    try
        {
            files::DownloadArg d(m_curr_dir + fileName);
            std::unique_ptr<files::FileMetadata> md = m_c.getFiles()->download(d, &buffer);
            std::cout << byteArray.constData();
            printLastApiCall();
        }
    catch(DropboxException& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
  

    buffer.close();
};

void BoxCommands::cd(QString dirName)
{
    if(dirName.isEmpty()){
        std::cout << "ERROR argument reguired" << std::endl;
        return;
    }

    try
        {
            QString newPath = m_curr_dir + dirName;
            if(dirName[0] == '/')
                {
                    //absolute path
                    newPath = dirName;
                }
            else
                {
                    if(dirName == "..")
                        {
                            if(m_curr_dir != "/")
                                {
                                    int idx = newPath.lastIndexOf("/", -4);
                                    if(idx != -1)
                                        {
                                            newPath.remove(idx, newPath.size());
                                        }                            
                                }
                            else
                                {
                                    std::cout << "root folder" << std::endl;
                                    return;
                                }
                        }
                }

            m_curr_dir = newPath;
            if(m_curr_dir.length() == 0 || m_curr_dir[m_curr_dir.length() - 1] != '/')
                m_curr_dir += "/";
            printLastApiCall();
            ls("");
        }
    catch(DropboxException& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
};

void BoxCommands::put(QString fileName)
{
    if(fileName.isEmpty()){
        std::cout << "ERROR argument reguired" << std::endl;
        return;
    }

    QFile file_in(fileName);
    if(!file_in.open(QFile::ReadOnly)){
        std::cout << "Error opening file: " << fileName.toStdString() << std::endl;
        return;
    }

    QFileInfo fi(fileName);
    QString doxFileName = fi.fileName();
    
    try
        {
            files::CommitInfo arg(m_curr_dir + doxFileName);
            std::unique_ptr<files::Metadata> res = m_c.getFiles()->upload(arg, &file_in);
            std::cout << "file uploaded" << std::endl;
            std::cout << res->toString().toStdString() << std::endl;
            printLastApiCall();
        }
    catch(DropboxException& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    file_in.close();
};

void BoxCommands::get(QString fileName)
{
    if (fileName.isEmpty()){
        std::cout << "ERROR argument reguired" << std::endl;
        return;
    }

    QFile out(fileName);
    if (!out.open(QFile::WriteOnly | QIODevice::Truncate)){
        std::cout << "Error opening file: " << fileName.toStdString() << std::endl;
        return;
    }

    try
        {
            files::DownloadArg arg(m_curr_dir + fileName);
            std::unique_ptr<files::Metadata> res = m_c.getFiles()->download(arg, &out);
            std::cout << "file downloaded" << std::endl;
            std::cout << res->toString().toStdString() << std::endl;
            printLastApiCall();
        }
    catch (DropboxException& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }

    out.close();
};

void BoxCommands::rm(QString fileName)
{
    if(fileName.isEmpty()){
        std::cout << "ERROR argument reguired" << std::endl;
        return;
    }
    
    std::string confirm_str;
    std::cout << "Please type 'yes' to confirm deleting " << fileName.toStdString() << " >";
    std::cin >> confirm_str;
    if(confirm_str != "yes")
        return;

    try
        {
            files::DeleteArg d(m_curr_dir + fileName);
            std::unique_ptr<files::Metadata> md = m_c.getFiles()->deleteOperation(d);
            std::cout << "deleted";
            std::cout << md->toString().toStdString();
            printLastApiCall();
        }
    catch(DropboxException& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    
};
