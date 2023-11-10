#ifndef MYSERVER_H
#define MYSERVER_H
#include <QTcpServer>
#include <map>
#include <QThread>

class MyServer : public QObject{
    Q_OBJECT
public:

    MyServer(QObject *parent = nullptr);
    ~MyServer();
    QHostAddress serverAddress(){return server->serverAddress();}
    quint16 serverPort(){return server->serverPort();}

private:

    QTcpServer* server = nullptr;
    std::map<QTcpSocket*,std::string> clients;

public slots:
    void updateconn(QHostAddress address, qint16 port);
    void broadcast(std::string message);
    void disconnection_cleanup();
    void add_socket();
    void process_data();
public: Q_SIGNALS:
    void ready_message(std::string message);
};

#endif // MYSERVER_H
