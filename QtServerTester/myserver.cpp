#include "myserver.h"
#include "utils.h"
#include <QTcpSocket>

MyServer::MyServer(QObject *parent)
:QObject(parent)
{
    server = new QTcpServer(this);
    updateconn(QHostAddress::LocalHost, Utils::kPort);
    connect(server,&QTcpServer::pendingConnectionAvailable,this,&MyServer::add_socket);
    connect(this,&MyServer::ready_message,this,&MyServer::broadcast);
}

void MyServer::updateconn(QHostAddress address, qint16 port){
    if(server->serverAddress()==address && server->serverPort()==port) return;
    if(server->isListening()){
        broadcast("Server is disconnecting");
        server->close();
        for(auto i = clients.cbegin();i!=clients.cend();i++){
            auto node = clients.extract(i->first);
            disconnect(node.key(),&QTcpSocket::readyRead,this,&MyServer::process_data);
            disconnect(node.key(),&QTcpSocket::disconnected,this,&MyServer::disconnection_cleanup);
            node.key()->deleteLater();
        }
    }
    server->listen(address,port);
}

void MyServer::broadcast(std::string message){
    char* data = message.data();
    for (auto i = clients.cbegin();i!=clients.cend();i++) {
        i->first->write(data);
    }
}

void MyServer::add_socket(){
    if(server->hasPendingConnections()){
        QTcpSocket* socket = server->nextPendingConnection();
        socket->waitForReadyRead();
        std::string nick = socket->readLine().toStdString();
        for(auto i = clients.cbegin();i!=clients.cend();i++){
            if(i->second == nick){
                socket->write("Username already in use, connection refused");
                socket->abort();
                return;
            }
        }
        clients[socket] = nick;
        connect(socket,&QTcpSocket::readyRead,this,&MyServer::process_data);
        emit ready_message("[" + nick + "] joined the lobby");
        connect(socket,&QTcpSocket::disconnected,this,&MyServer::disconnection_cleanup);
    }
}

void MyServer::disconnection_cleanup(){
    auto node = clients.extract(dynamic_cast<QTcpSocket*>(sender()));
    disconnect(node.key(),&QTcpSocket::readyRead,this,&MyServer::process_data);
    disconnect(node.key(),&QTcpSocket::disconnected,this,&MyServer::disconnection_cleanup);
    node.key()->deleteLater();
    emit ready_message("[" + node.mapped() + "] left the lobby");
}
void MyServer::process_data(){
    QTcpSocket* socket = dynamic_cast<QTcpSocket*>(sender());
    std::string message = "[" + clients[socket] + "]: " + QString(socket->readAll()).toStdString();
    emit ready_message(message);
}

MyServer::~MyServer(){
    broadcast("!!Server is shutting down!!");
    for(auto i = clients.cbegin();i!=clients.cend();i++){
        i->first->abort();
    }
}
