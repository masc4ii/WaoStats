#include <iostream>
#include <functional>

#include <QtCore/QCoreApplication>
#include <QFile>
#include <QStringList>

#include "dropbox/DropboxClient.h"
#include "dropbox/endpoint/DropboxAppInfo.h"
#include "dropbox/endpoint/DropboxAuthInfo.h"
#include "ApiListener.h"
#include "BoxCommands.h"

using namespace dropboxQt;


void ApiListener::progressUpload(qint64 bytesProcessed, qint64 total)
{
    if(bytesProcessed != total && total != -1)
        std::cout << "upload " << bytesProcessed << " " << total << std::endl;
};

void ApiListener::progressDownload(qint64 bytesProcessed, qint64 total)
{
    if (bytesProcessed != total && total != -1)
        std::cout << "download " << bytesProcessed << " " << total << std::endl;
};


class Terminal
{
public:
    struct Selection
    {
        QString                         name;
        QString                         description;
        std::function<void(QString)>    action;
    };
    typedef std::list<Selection> SELECTION_LIST;
    typedef std::map<QString, Selection> SELECTION_MAP;

    Terminal(BoxCommands& c):m_cmd(c){};

    void addAction(QString name, QString description, std::function<void(QString)> action)
    {
        Selection s;
        s.name = name;
        s.description = description;
        s.action = action;
        m_sel.push_back(s);
        m_sel_map[name.toLower()] = s;
    };

    void start()
    {
        std::string exit_option("exit");

        while(true)
            {
                std::cout << std::endl;
                std::cout << "-----------------------------------------" << std::endl;

                for(SELECTION_LIST::iterator i = m_sel.begin(); i != m_sel.end(); i++){
                    std::cout << " " << pad(i->name.toStdString(), 10) << " " << i->description.toStdString() << std::endl;
                }
                std::cout << " " << pad(exit_option, 10) << " " << "Exit terminal" << std::endl << std::endl;
                std::cout << " WD:" << m_cmd.wd().toStdString() << std::endl;
                std::cout <<" dropbox> ";

                std::string tmp;            
                getline(std::cin, tmp);
                QString str = tmp.c_str();
                QStringList arg_list = str.split(" ", QString::SkipEmptyParts);
                if(!arg_list.empty()){
                    str = arg_list[0];
                    if(str.compare("exit", Qt::CaseInsensitive) == 0)
                        break;

                    arg_list.removeFirst();
                    QString arg = arg_list.join(" ");

                    SELECTION_MAP::iterator i = m_sel_map.find(str);
                    if(i == m_sel_map.end()){
                        std::cout << "invalid command: " << str.toStdString() << std::endl;
                    }
                    else{
                        i->second.action(arg);
                    }
                }
            }
    };

    std::string pad(std::string s, const size_t num, const char paddingChar = ' ')
    {
        std::string str = s;
        if(num > str.size())
            str.insert(str.size(), num - str.size(), paddingChar);
        return str;
    }

protected:
    SELECTION_LIST  m_sel;
    SELECTION_MAP   m_sel_map;
    BoxCommands&    m_cmd;
};

int main(int argc, char *argv[]) 
{
    QCoreApplication app(argc, argv);

    if (argc != 2) {
        std::string  s = QString("\nUsage:   %1 <auth-file>\n"
                                 "Example: %1 ../token.info\n"
                                 "\n"
                                 "<auth-file>: An \"auth file\" that contains the information necessary to make"
                                 "an authorized Dropbox API request.  Generate this file using the \"authorize\"\n"
                                 "example program.\n"
                                 "\n"
                                 " Press ENTER to proceed.").arg(argv[0]).toStdString();

        std::cout << s << std::endl;
        std::cout << std::endl;
        std::cin.ignore();
        return 0;
    }

    QString argAuthFile = argv[1];
    DropboxAuthInfo authInfo;
    if(!authInfo.readFromFile(argAuthFile)){
        std::cout << "Error reading <auth-file>" << std::endl;
        std::cin.ignore();
        return 0;        
    }

    ApiListener lsn;
    DropboxClient c(authInfo.getAccessToken());
    QObject::connect(&c, &DropboxClient::uploadProgress, &lsn, &ApiListener::progressUpload);
    QObject::connect(&c, &DropboxClient::downloadProgress, &lsn, &ApiListener::progressDownload);

    BoxCommands cmd(c);
    Terminal t(cmd);
  
    t.addAction("account","Account info", [&](QString arg) {cmd.account(arg);} );
    t.addAction("pwd",  "Print Working Directory", [&](QString arg) {cmd.pwd(arg);} );
    t.addAction("ls",       "List Directory", [&](QString arg) {cmd.ls(arg);} );
    t.addAction("info",     "Get Info on a File or Directory", [&](QString arg) {cmd.info(arg);} );
    t.addAction("info_async",  "Get Info on a File or Directory [async]", [&](QString arg) {cmd.info_async(arg);} );
    t.addAction("mkdir",    "Create Directory", [&](QString arg) {cmd.mkdir(arg);} );
    t.addAction("cat",  "Print file content on screen", [&](QString arg) {cmd.cat(arg);} );
    t.addAction("cd",       "Change working directory", [&](QString arg) {cmd.cd(arg);} );
    t.addAction("put",  "Upload file", [&](QString arg) {cmd.put(arg);} );
    t.addAction("get",  "Download file", [&](QString arg) {cmd.get(arg);} );
    t.addAction("rm",       "Delete file or folder", [&](QString arg) {cmd.rm(arg);} );
    t.start();

    return 0;
}
