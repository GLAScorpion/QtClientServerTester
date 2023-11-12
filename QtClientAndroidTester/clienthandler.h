#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

#include <QObject>
#include <QQmlEngine>
#include "myclient.h"
class ClientHandler : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_UNCREATABLE("")
public:
    explicit ClientHandler(QObject *parent = nullptr);
private:
    MyClient* client;
public: Q_SIGNALS:

public slots:

};

#endif // CLIENTHANDLER_H
