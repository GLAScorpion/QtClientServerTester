#include "mainwindow.h"
#include "myserver.h"
#include <QApplication>
#include <QThread>
#include <iostream>
int main(int argc, char *argv[])
{   

    QApplication a(argc, argv);
    MyServer server;
    MainWindow w;
    w.ServerBind(&server);
    w.show();
    return a.exec();
}
QCoreApplication* createApplication(int &argc, char *argv[])
{
    for (int i = 1; i < argc; ++i) {
        if (!qstrcmp(argv[i], "-no-gui"))
            return new QCoreApplication(argc, argv);
    }
    return new QApplication(argc, argv);
}

int main(int argc, char* argv[])
{
    QScopedPointer<QCoreApplication> app(createApplication(argc, argv));

    if (qobject_cast<QApplication *>(app.data())) {
        // start GUI version...
        MyServer server;
        MainWindow w;
        w.ServerBind(&server);
        w.show();
    } else {
        // start non-GUI version...
    }

    return app->exec();
}
