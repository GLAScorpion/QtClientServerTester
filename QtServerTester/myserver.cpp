#include "myserver.h"
#include "utils.h"
#include <QTcpSocket>

MyServer::MyServer(QObject *parent)
:QObject(parent)
{
    server = new QTcpServer(this);
    updateconn(QHostAddress::LocalHost, Utils::kPort);
    connect(server,&QTcpServer::pendingConnectionAvailable,this,&MyServer::add_socket);

}

void MyServer::updateconn(QHostAddress address, qint16 port){
    if(server->serverAddress()==address && server->serverPort()==port) return;
    if(server->isListening()) server->close();
    server->listen(address,port);
}

void MyServer::broadcast(std::string message){
    char* data = message.data();
    for (unsigned long long i=0;i<clients.size();i++) {
        clients[i]->write(data);
    }
}

void MyServer::add_socket(){
    if(server->hasPendingConnections()){
        QTcpSocket* socket = server->nextPendingConnection();
        clients.push_back(socket);
        connect(socket,&QTcpSocket::readyRead,this,&MyServer::process_data);
    }
}

void MyServer::process_data(){
    QTcpSocket* socket = dynamic_cast<QTcpSocket*>(sender());
    std::string message = QString(socket->readAll()).toStdString();
    emit ready_message(message);
}

MyServer::~MyServer(){
    for(unsigned long long i=0; i < clients.size();i++ ){
        clients[i]->disconnectFromHost();
    }
}
