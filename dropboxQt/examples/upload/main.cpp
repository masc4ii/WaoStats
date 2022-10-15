#include <iostream>
#include <QtCore/QCoreApplication>
#include <QFile>
#include "dropbox/DropboxClient.h"
#include "dropbox/files/FilesRoutes.h"
#include "dropbox/endpoint/DropboxAppInfo.h"
#include "dropbox/endpoint/DropboxAuthInfo.h"
#include "ApiListener.h"

using namespace dropboxQt;

void ApiListener::progressUpload(qint64 bytesProcessed, qint64 total)
{
    if(bytesProcessed != total && total != -1)
        std::cout << "progress " << bytesProcessed << " " << total << std::endl;
};

int main(int argc, char *argv[]) 
{
    QCoreApplication app(argc, argv);

    if (argc != 4) {
        std::string  s = QString("\nUsage:   %1 <auth-file> <local-file-to-upload> <dropbox-file-destination> \n"
            "Example: %1 ../token.info mydata.txt /mydata.txt\n"
            "<auth-file>: An \"auth file\" that contains the information necessary to make"
            "    an authorized Dropbox API request.  Generate this file using the \"authorize\"\n"
            "    example program.{\n"
            "\n"
            "<local-file-to-upload>: the local file that should be uploaded"
            "<dropbox-file-destination>: file in dropbox repository where the file should be stored"
                                 " Press ENTER to proceed.").arg(argv[0]).toStdString();

        std::cout << s << std::endl;
        std::cout << std::endl;
        std::cin.ignore();
        return 0;
    }

    QString argAuthFile = argv[1];
    QString argSourceFile = argv[2];
    QString argDestFile = argv[3];
    DropboxAuthInfo authInfo;
    if(!authInfo.readFromFile(argAuthFile)){
        std::cout << "Error reading <auth-file>" << std::endl;
        std::cin.ignore();
        return 0;        
    }

    QFile file_in(argSourceFile);
    if(!file_in.open(QFile::ReadOnly)){
        std::cout << "Error opening file: " << argSourceFile.toStdString() << std::endl;
        return 0;
    }
    
    ApiListener lsn;
    DropboxClient c(authInfo.getAccessToken());
    QObject::connect(&c, &DropboxClient::uploadProgress, &lsn, &ApiListener::progressUpload);
    try
        {
            files::CommitInfo arg(argDestFile);
            std::unique_ptr<files::Metadata> res = c.getFiles()->upload(arg, &file_in);
            std::cout << "file uploaded" << std::endl;
            std::cout << res->toString().toStdString() << std::endl;
        }
    catch(DropboxException& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }

    file_in.close();
    std::cin.ignore();

    return 0;
}
