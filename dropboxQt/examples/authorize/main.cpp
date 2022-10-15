#include <iostream>
#include <QtCore/QCoreApplication>
#include "dropbox/endpoint/DropboxAppInfo.h"
#include "dropbox/endpoint/DropboxWebAuth.h"
#include "dropbox/DropboxClient.h"

using namespace dropboxQt;

int main(int argc, char *argv[]) 
{
    QCoreApplication app(argc, argv);

    if (argc != 3) {
        std::string  s = QString("Usage:   %1 <app-info-file> <auth-file-output>\n"
            "Example: %1 ../app.info ../token.info\n"
            "\n"
            "<app-info-file>: a JSON file with information about your API app.  Example:\n"
            "\n"
            "  {\n"
            "    \"key\": \"Your Dropbox API app key...\",\n"
            "    \"secret\": \"Your Dropbox API app secret...\"\n"
            "  }\n"
            "\n"
            "  Get an API app key by registering with Dropbox:\n"
            "    https://dropbox.com/developers/apps \n"
            "\n"
            "<auth-file-output>: If authorization is successful, the resulting API \n"
            "  access token will be saved to this file, which can then be used with\n"
            "  other example programs, such as the one in \"examples/account-info\". \n"
            "\n"
                                 " Press ENTER to proceed.").arg(argv[0]).toStdString();

        std::cout << s << std::endl;
        std::cout << std::endl;
        std::cin.ignore();
        return 0;
    }

    QString argAppInfoFile = argv[1];
    QString argAuthFileOutput = argv[2];

    DropboxAppInfo appInfo;
    if(!appInfo.readFromFile(argAppInfoFile)){
        std::cerr << "Error reading <app-info-file>" << std::endl;
        return 0;
    };

    QString url = DropboxWebAuth::getCodeAuthorizeUrl(appInfo);
    std::cout << "1. Go to " << url.toStdString() << std::endl;
    std::cout << "2. Click \"Allow\" (you might have to log in first)." << std::endl;
    std::cout << "3. Copy the authorization code." << std::endl;
    std::cout << "Enter the authorization code here: " << std::endl;
    std::cout << ">";
    
    std::string auth_code;
    std::cin >> auth_code;

    try
        {
            DropboxAuthInfo authInfo = DropboxWebAuth::getTokenFromCode(appInfo, QString::fromStdString(auth_code));
            if(!authInfo.storeToFile(argAuthFileOutput)){
                std::cout << "Error, failed to store access token to file: " << argAuthFileOutput.toStdString() << std::endl;
            }
            std::cout << "finished, token stored in file " << argAuthFileOutput.toStdString() << std::endl;
        }
    catch(DropboxException& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }

    std::cin.ignore();
    return 0;
}
