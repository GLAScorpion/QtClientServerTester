#ifndef MYCLIENT_H
#define MYCLIENT_H
#include <QTcpSocket>

class MyClient : public QTcpSocket{
    Q_OBJECT
public:
    MyClient(QObject* parent = nullptr);
};


#endif // MYCLIENT_H
