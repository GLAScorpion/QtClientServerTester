#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "setip.h"
#include <QPushButton>
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SendMex = findChild<QPushButton*>("SendMex");
    Console = findChild<QPlainTextEdit*>("Console");
    InsMex = findChild<QPlainTextEdit*>("InsMex");
    IpSetter = findChild<QAction*>("actionSet_Ip");
    connect(SendMex,&QPushButton::pressed,this,&MainWindow::broadcast_server);
    connect(IpSetter,&QAction::triggered,this,&MainWindow::setip);

}

void MainWindow::broadcast_server(){
    QString mex ="[Server]: " + InsMex->toPlainText();
    InsMex->setPlainText("");
    broadcast(mex.toStdString());
}

void MainWindow::broadcast(std::string message){
    emit send_message(message);
    write_console(message);
}
void MainWindow::write_console(std::string message)
{
    Console->appendPlainText(QString::fromStdString(message));
}

void MainWindow::setip(){
    SetIp* setip = new SetIp(this);
    connect(setip,&SetIp::newconn,server,&MyServer::updateconn);
    setip->SetIpPort(server->serverAddress().toString(),server->serverPort());
    connect(setip,&QDialog::finished,this,[=]{delete setip;});
    setip->open();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ServerBind(MyServer* server){
    this->server = server;
    connect(this,&MainWindow::send_message,server,&MyServer::broadcast);
    connect(server,&MyServer::ready_message,this,&MainWindow::broadcast);
}
