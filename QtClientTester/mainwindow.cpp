#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      client(new MyClient),
      ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    IpSetter = findChild<QLineEdit*>("IpSetter");
    PortSetter = findChild<QLineEdit*>("PortSetter");
    SendMex = findChild<QPushButton*>("SendMex");
    Connect = findChild<QPushButton*>("Connect");
    Console = findChild<QPlainTextEdit*>("Console");
    InsMex = findChild<QLineEdit*>("InsMex");
    Nickname = findChild<QLineEdit*>("NickName");
    connect(Connect,&QPushButton::pressed,this,&MainWindow::start_conn);
    connect(SendMex,&QPushButton::pressed,this,&MainWindow::send_message);
    connect(InsMex,&QLineEdit::returnPressed,this,&MainWindow::send_message);
    connect(client,&MyClient::error_occurred,this,&MainWindow::write_console);
    connect(this,&MainWindow::message_ready,client,&MyClient::send_message);
    connect(client,&MyClient::ready_message,this,&MainWindow::write_console);
}

void MainWindow::start_conn(){
    QString address = IpSetter->text();
    QString port = PortSetter->text();
    QString nick = Nickname->text();
    client->connect(address,port,nick);
}

void MainWindow::send_message(){
    if(!client||client->state()!=QTcpSocket::ConnectedState){
        write_console("Socket isn't connected");
        return;
    }
    QString mex = InsMex->text();
    InsMex->setText("");
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

