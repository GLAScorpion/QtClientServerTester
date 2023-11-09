#include "setip.h"
#include "ui_setip.h"
#include "utils.h"

SetIp::SetIp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetIp)
{
    ui->setupUi(this);
    ErrorLabel = findChild<QLabel*>("ErrorLabel");
    ConfirmButton = findChild<QPushButton*>("ConfirmButton");
    ErrorLabel->setStyleSheet("color:black;border:0px;");
    IpAddress = findChild<QLineEdit*>("IpSetter");
    Port = findChild<QLineEdit*>("PortSetter");
    connect(ConfirmButton,&QPushButton::pressed,this,&SetIp::confirm);
}

void SetIp::confirm(){
    QString address = IpAddress->text();
    QString port = Port->text();
    int pos = 0;
    if(Utils::IpValidator(address)&&Utils::kValidPort.validate(port,pos)==QIntValidator::Acceptable){
        emit newconn(QHostAddress(address),port.toInt());
        accept();
    }else{
        ErrorLabel->setStyleSheet("color:red;border:0px;font:15px bold;");
    }
}

void SetIp::SetIpPort(QString address, qint16 port){
    IpAddress->setText(address);
    Port->setText(QString::number(port));
}

SetIp::~SetIp()
{
    delete ui;
}
