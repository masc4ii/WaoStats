#pragma once

#include "dropbox/DropboxClient.h"

class BoxCommands: public QObject
{
    Q_OBJECT;
public:
    BoxCommands(dropboxQt::DropboxClient& c);

    /**
       account - get account information
    */

    void account(QString);
    /**
       pwd - current working directory, This is not a Dropbox property,
       but internal variable
    */

    void pwd    (QString);

    /**
       ls - list current folder content 
    */
    void ls     (QString);

    /**
       info - get metadata on a file or folder
    */
    void info   (QString path);
    void info_async(QString path);
    
    /**
       mkdir - create a new directory
    */
    void mkdir  (QString name);

    /**
       cat - print file content on the screen
    */
    void cat    (QString fileName);

    /**
       cd - change current working directory
    */
    void cd     (QString dirName);

    /**
       rm - delete file or folder on dropbox
    */
    void rm     (QString fileName);
    
    /**
       put - upload file
       fileName - local file to upload
    */
    void put    (QString fileName);

    /**
       get - download file
       fileName - dropbox file to download
    */
    void get    (QString fileName);

    QString wd()const{return m_curr_dir;}

    /**
       printLastApiCall - print on the screen last API call if succeded
     */
    void printLastApiCall();
    
protected:    
    void printFileInfo(dropboxQt::files::Metadata* md);
    
protected:
    dropboxQt::DropboxClient&   m_c;
    QString                     m_curr_dir;
};
