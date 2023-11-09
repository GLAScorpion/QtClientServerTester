#include "myclient.h"

MyClient::MyClient(QObject* parent)
:QTcpSocket(parent)
{
    connect(this,&QTcpSocket::readyRead,this,&MyClient::process_message);
}

void MyClient::process_message(){
    emit ready_message(QString(readAll()).toStdString());
}

void MyClient::send_message(std::string message){
    write(message.data());
}
