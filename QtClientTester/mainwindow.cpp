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
    Connect = findChild<QPushButton*>("Connect");
    Console = findChild<QPlainTextEdit*>("Console");
    InsMex = findChild<QPlainTextEdit*>("InsMex");
    IpSetter = findChild<QAction*>("actionSet_Ip");

    connect(IpSetter,&QAction::triggered,this,&MainWindow::setip);
    connect(Connect,&QPushButton::pressed,this,&MainWindow::start_conn);

}

void MainWindow::start_conn(){
    connect(SendMex,&QPushButton::pressed,this,&MainWindow::broadcast);
    client = new MyClient;
}

void MainWindow::broadcast(){
    QString mex ="[Server]: " + InsMex->toPlainText();
    InsMex->setPlainText("");
    emit send_message(mex.toStdString());
    write_console(mex.toStdString());
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

