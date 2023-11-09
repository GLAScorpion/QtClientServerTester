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
