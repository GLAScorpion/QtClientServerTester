#include "setip.h"
#include "ui_setip.h"

SetIp::SetIp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetIp)
{
    ui->setupUi(this);
    ErrorLabel = findChild<QLabel*>("ErrorLabel");
    ConfirmButton = findChild<QPushButton*>("ConfirmButton");
    //ErrorLabel->setStyleSheet("color:black;border:0px;");

}



SetIp::~SetIp()
{
    delete ui;
}
