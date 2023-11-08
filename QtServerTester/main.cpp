#include "mainwindow.h"
#include "nethandler.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyServer server;
    MainWindow w;
    w.show();
    return a.exec();
}
