#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "setip.h"
#include <QPushButton>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SendMex = findChild<QPushButton*>("SendMex");
    Console = findChild<QPlainTextEdit*>("Console");
    InsMex = findChild<QPlainTextEdit*>("InsMex");
    IpSetter = findChild<QAction*>("actionSet_Ip");
    connect(SendMex,&QPushButton::pressed,this,&MainWindow::send_console);
    connect(IpSetter,&QAction::triggered,this,&MainWindow::setip);
}

void MainWindow::send_console()
{
    QString mex = InsMex->toPlainText();
    //QString log = Console->text() + "\n" + mex;
    Console->appendPlainText(mex);
    InsMex->setPlainText("");
}

void MainWindow::setip(){
    SetIp setip;
    setip.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}

