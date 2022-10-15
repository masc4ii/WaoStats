#include <iostream>
#include <QtCore/QCoreApplication>
#include "dropbox/DropboxClient.h"
#include "dropbox/users/UsersRoutes.h"
#include "dropbox/endpoint/DropboxAppInfo.h"
#include "dropbox/endpoint/DropboxAuthInfo.h"

using namespace dropboxQt;

int main(int argc, char *argv[]) 
{
    QCoreApplication app(argc, argv);

    if (argc != 2) {
        std::string  s = QString("\nUsage:   %1 <auth-file>\n"
            "Example: %1 ../token.info\n"
            "\n"
            "<auth-file>: An \"auth file\" that contains the information necessary to make\n"
            "an authorized Dropbox API request.  Generate this file using the \"authorize\"\n"
            "example program.{\n"
            "\n"
            " Press ENTER to proceed.").arg(argv[0]).toStdString();

        std::cout << s << std::endl;
        std::cout << std::endl;
        std::cin.ignore();
        return 0;
    }

    QString argAuthFile = argv[1];
    DropboxAuthInfo authInfo;
    // Read auth info file.
    if(!authInfo.readFromFile(argAuthFile)){
        std::cout << "Error reading <auth-file>" << std::endl;
        std::cin.ignore();
        return 0;        
    }
    
    dropboxQt::DropboxClient c(authInfo.getAccessToken());
    try
        {
            std::unique_ptr<users::FullAccount> accountInfo = c.getUsers()->getCurrentAccount();
            std::cout << accountInfo->toString().toStdString() << std::endl;
        }
    catch(DropboxException& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    std::cout << "Finished, press ENTER to exit " << std::endl;
    std::cin.ignore();

    return 0;
}
