#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utils.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    IpSetter = findChild<QLineEdit*>("IpSetter");
    PortSetter = findChild<QLineEdit*>("PortSetter");
    SendMex = findChild<QPushButton*>("SendMex");
    Connect = findChild<QPushButton*>("Connect");
    Console = findChild<QPlainTextEdit*>("Console");
    InsMex = findChild<QPlainTextEdit*>("InsMex");
    Nickname = findChild<QLineEdit*>("NickName");
    connect(Connect,&QPushButton::pressed,this,&MainWindow::start_conn);
    connect(SendMex,&QPushButton::pressed,this,&MainWindow::send_message);
}

void MainWindow::start_conn(){
    QString address = IpSetter->text();
    QString port = PortSetter->text();
    int pos = 0;
    if(!Utils::IpValidator(address)||Utils::kValidPort.validate(port,pos)!=QIntValidator::Acceptable){
        write_console("Invalid IP/Port");
        return;
    }
    if(client&&client->state()==QTcpSocket::ConnectedState) {
        client->abort();
        client->deleteLater();
    }
    client = new MyClient(this);
    client->connectToHost(QHostAddress(address),port.toInt());
    connect(this,&MainWindow::message_ready,client,&MyClient::send_message);
    connect(client,&MyClient::ready_message,this,&MainWindow::write_console);
}

void MainWindow::send_message(){
    QString nick = Nickname->text();
    if(nick.isEmpty()){
        write_console("Insert a nickname");
        return;
    }
    if(!client||client->state()!=QTcpSocket::ConnectedState){
        write_console("Socket isn't connected");
        return;
    }
    QString mex ="[" + nick + "]: " + InsMex->toPlainText();
    InsMex->setPlainText("");
    emit message_ready(mex.toStdString());
    //write_console(mex.toStdString());
}

void MainWindow::write_console(std::string message)
{
    Console->appendPlainText(QString::fromStdString(message));
}

MainWindow::~MainWindow()
{
    delete ui;
}

