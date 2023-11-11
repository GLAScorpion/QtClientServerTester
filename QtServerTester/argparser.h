#ifndef ARGPARSER_H
#define ARGPARSER_H
#include <QApplication>
#include <QHostAddress>
class ArgParser {
public:
    ArgParser(int &argc, char *argv[]);
    QCoreApplication* GUIArg();
    QHostAddress AddressArg();
    qint16 PortArg();
private:
    int argnum = 0;
    char **arguments;

};

#endif // ARGPARSER_H
