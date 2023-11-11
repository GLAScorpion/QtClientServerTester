#include "mainwindow.h"
#include "myserver.h"
#include <QApplication>
#include <QThread>
#include <QTextStream>
#include <iostream>
#include "argparser.h"

int main(int argc, char* argv[])
{
    ArgParser parser(argc,argv);
    QScopedPointer<QCoreApplication> app(parser.GUIArg());
    MyServer server;
    server.updateconn(parser.AddressArg(),parser.PortArg());
    if (qobject_cast<QApplication *>(app.data())) {
        // start GUI version...
        MainWindow w;
        w.ServerBind(&server);
        w.show();
        return app->exec();
    } else {
        // start non-GUI version...
        QObject::connect(&server,&MyServer::ready_message,&server,[&](std::string message){std::cout<<message<<"\n";});
        return app->exec();
    }

}
