#include "myclient.h"
#include "utils.h"
#include <QHostInfo>
MyClient::MyClient(QObject* parent)
:QTcpSocket(parent)
{
    QObject::connect(this,&QTcpSocket::readyRead,this,&MyClient::process_message);
}

bool MyClient::connect(QString address, QString port, QString nick){
    int pos = 0;
    if(nick.isEmpty()){
        emit error_occurred("Insert a nickname");
        return false;
    }
    QHostInfo info = QHostInfo::fromName(address);
    if((info.error()!=QHostInfo::NoError&&!Utils::IpValidator(address))||Utils::kValidPort.validate(port,pos)!=QIntValidator::Acceptable){
        emit error_occurred("Invalid IP/Port");
        return false;
    }
    if(info.error()==QHostInfo::NoError){
        address = info.addresses()[0].toString();
    }
    if(state()==QTcpSocket::ConnectedState) {
        abort();
    }
    nickname = nick.toStdString();
    connectToHost(QHostAddress(address),port.toInt());
    waitForConnected(5000);
    if(state()!=QTcpSocket::ConnectedState){
        emit error_occurred("An error occurred in the connection");
        return false;
    }
    write(nick.toStdString().data());
    return true;
}

void MyClient::process_message(){
    emit ready_message(QString(readAll()).toStdString());
}

void MyClient::send_message(std::string message){
    write(message.data());
}
