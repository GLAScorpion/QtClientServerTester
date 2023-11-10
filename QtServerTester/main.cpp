#include "mainwindow.h"
#include "myserver.h"
#include <QApplication>
#include <QThread>
#include <QTextStream>
#include <iostream>
#include <Windows.h>
QCoreApplication* createApplication(int &argc, char *argv[])
{
    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "-nogui")
            return new QCoreApplication(argc, argv);
    }
    return new QApplication(argc, argv);
}

int main(int argc, char* argv[])
{
    QScopedPointer<QCoreApplication> app(createApplication(argc, argv));
    MyServer server;
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
