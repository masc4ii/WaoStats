#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/endpoint/DropboxAuthInfo.h"
#include "dropbox/endpoint/ApiException.h"
#include "dropbox/endpoint/ApiClient.h"

namespace dropboxQt{

    namespace auth      { class AuthRoutes; };
    namespace files     { class FilesRoutes; };
    namespace sharing   { class SharingRoutes; };
    namespace team      { class TeamRoutes; };
    namespace users     { class UsersRoutes; };
    class Endpoint;

    /**
       @brief DropboxClient - v2 Dropbox API Client for Qt/C++11
       Usage sample
    
       using namespace dropboxQt;
       DropboxClient dbox("ACCESS_TOKEN");
       files::CreateFolderArg arg("path_to_new_folder");
    
       //1---- async call, no exceptions, callback on completed ----
       dbox.getFiles()->createFolder_Async(arg, [](std::unique_ptr<files::FolderMetadata> res)
       {
       qDebug() << "folder created, id=" << res->id();
       });
    
       //---- also callback on completed and error ----
       dbox.getFiles()->createFolder_Async(arg, [](std::unique_ptr<files::FolderMetadata> res)
       {
       qDebug() << "folder created, id=" << res->id();
       },
       [](std::unique_ptr<DropboxException> e) 
       {
       qDebug() << "Exception: " << e->what();
       });
    
       //2---- blocking call, no callbacks, exception checking ---
       try
       {
       std::unique_ptr<files::FolderMetadata> res = dbox.getFiles()->createFolder(arg);
       qDebug() << "folder created, id=" << res->id();
       }
       catch (DropboxException& e)
       {
       qDebug() << "Exception: " << e.what();
       }
    
       //3---- blocking call, no callbacks, no exception, returns boolean
       if(dbox.createFolder("path_to_new_folder")){
       qDebug() << "folder created";
       }
       else{
       qDebug() << "failed to create folder";
       }       
    */

    class DropboxClient: public ApiClient{
        Q_OBJECT
    public:
        DropboxClient();
        DropboxClient(const QString& access_token);
        ~DropboxClient();

        /// "auth" namespace API endpoint
        auth::AuthRoutes*           getAuth();

        /// "files" namespace API endpoint
        files::FilesRoutes*         getFiles();

        /// "sharing" namespace API endpoint
        sharing::SharingRoutes*     getSharing();

        /// "team" namespace API endpoint
        team::TeamRoutes*           getTeam();

        /// "users" namespace API endpoint
        users::UsersRoutes*         getUsers();

        /*
          Below are some 'shortcut' functions for those who don't
          want to deal with exceptions and don't need rich data response
        */

        /// download file from Dropbox
        bool downloadFile(QString dropboxFilePath, QString localDestinationPath);

        /// upload file to Dropbox
        bool uploadFile(QString localFilePath, QString dropboxDestinationPath, bool overwriteIfExists = false);

        /// upload file to Dropbox in steps, if file exists upload to a tmp file then in upload succeded rename the file
        /// to the final destination file, by using this function there is less chance to generate corrupted (incomplete) file on the cloud
        /// it'a slower than regular upload and should be applied to critical files, only (database maybe)
        bool upgradeDropboxFile(QString localFilePath, QString dropboxDestinationPath);

        /// return true if file exist on given path
        bool fileExists(QString dropboxPath);

        /// return true if folder exist on given path
        bool folderExists(QString dropboxPath);

        /// create a new folder
        bool createFolder(QString dropboxPath);

        /// create a new folder if it doesn't exists
        bool ensureFolder(QString dropboxPath);

        /// move a file or folder
        bool moveFile(QString moveFrom, QString moveTo);

        /// delete a file or folder
        bool deleteFile(QString dropboxPath);

        /// return list of the files in a folder
        std::list<QString> listFolder(QString dropboxPath);

        /// HTTP calls debug function
        QString lastApiCall();

        /// cancell all current pending Dropbox requests
        void cancellAll();
        
    protected:
        std::unique_ptr<auth::AuthRoutes>           m_AuthRoutes;
        std::unique_ptr<files::FilesRoutes>         m_FilesRoutes;
        std::unique_ptr<sharing::SharingRoutes>     m_SharingRoutes;
        std::unique_ptr<team::TeamRoutes>           m_TeamRoutes;
        std::unique_ptr<users::UsersRoutes>         m_UsersRoutes;
        std::unique_ptr<Endpoint>                   m_endpoint;
    };//DropboxClient


    namespace files
    {
        class Metadata;
    };

    typedef std::list <std::unique_ptr<files::Metadata>> FOLDER_ENTRIES;
}//dropboxQt
