#include <iostream>
#include <QtCore/QCoreApplication>
#include "dropbox/DropboxClient.h"
#include "dropbox/AUTOTEST/ApiAutotest.h"

using namespace dropboxQt;

int main(int argc, char *argv[]) {

    QCoreApplication app(argc, argv);

    if (argc != 2) {
        std::string  s = "\nUsage: COMMAND <destination-file>\n"
            "\n"
            "<destination-file>: The file where results of autotest procedure will be generated"
            " Press ENTER to proceed.";

        std::cout << s << std::endl;
        std::cin.ignore();
        return 0;
    }

    QString argResFile = argv[1];
    DropboxClient c("TEST-TOKEN");
    ApiAutotest autotest(c);
    if(!autotest.init(argResFile)){
        std::cout << "Error opening destination file " << argResFile.toStdString() << std::endl;
        std::cin.ignore();
        return 0;               
    }
    std::cout << "Press ENTER to start autotest. The result will be generated: " << argResFile.toStdString() << std::endl;
    std::cin.ignore();
    autotest.generateCalls();
    std::cout << "finished" << std::endl;
    std::cin.ignore();

    return 0;
}
