#ifndef NETHANDLER_H
#define NETHANDLER_H
#include <QTcpServer>
#include <vector>
#include <memory>
class MyServer : public QTcpServer{
    Q_OBJECT
public:
    MyServer(QObject *parent = nullptr);
private:
    std::vector<std::unique_ptr<QTcpSocket*>> clients;
public slots:
    void updateconn(QHostAddress address, qint16 port);
};

#endif // NETHANDLER_H
