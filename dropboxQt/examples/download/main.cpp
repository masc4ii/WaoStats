#include <iostream>
#include <QtCore/QCoreApplication>
#include <QFile>
#include "dropbox/DropboxClient.h"
#include "dropbox/files/FilesRoutes.h"
#include "dropbox/endpoint/DropboxAppInfo.h"
#include "dropbox/endpoint/DropboxAuthInfo.h"
#include "ApiListener.h"

using namespace dropboxQt;

void ApiListener::progressDownload(qint64 bytesProcessed, qint64 total)
{
    if(bytesProcessed != total && total != -1)
        std::cout << "progress " << bytesProcessed << " " << total << std::endl;
};

int main(int argc, char *argv[]) 
{
    QCoreApplication app(argc, argv);

    if (argc != 4) {
        std::string  s = QString("\nUsage:    %1 <auth-file> <dropbox-file-2-download> <local-download-destination-file>\n"
            "Example:  %1 ../token.info /mydata.txt mydata.txt\n"
            "<auth-file>: An \"auth file\" that contains the information necessary to make\n"
            "an authorized Dropbox API request.  Generate this file using the \"authorize\"\n"
            "example program.\n"
            "\n"
            "<dropbox-file-2-download>: file in dropbox repository to be downloaded"
            "<local-download-destination-file>: location where the file should be stored"
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
    // Read auth info file.
    if(!authInfo.readFromFile(argAuthFile)){
        std::cout << "Error reading <auth-file>" << std::endl;
        std::cin.ignore();
        return 0;        
    }

    QFile out(argDestFile);
    if(!out.open(QFile::WriteOnly|QIODevice::Truncate)){
        std::cout << "Error opening file: " << argDestFile.toStdString() << std::endl;
        return 0;
    }
    
    ApiListener lsn;
    DropboxClient c(authInfo.getAccessToken());
    QObject::connect(&c, &DropboxClient::downloadProgress, &lsn, &ApiListener::progressDownload);
    try
        {
            files::DownloadArg arg(argSourceFile);
            std::unique_ptr<files::Metadata> res = c.getFiles()->download(arg, &out);
            std::cout << "file downloaded" << std::endl;
            std::cout << res->toString().toStdString() << std::endl;
        }
    catch(DropboxException& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }

    out.close();
    std::cin.ignore();

    return 0;
}
