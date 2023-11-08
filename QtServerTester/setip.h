#ifndef SETIP_H
#define SETIP_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QHostAddress>
namespace Ui {
class SetIp;
}

class SetIp : public QDialog
{
    Q_OBJECT

public:
    explicit SetIp(QWidget *parent = nullptr);
    ~SetIp();

private:
    Ui::SetIp *ui;
    QLabel* ErrorLabel;
    QPushButton* ConfirmButton;
public slots:
    //void confirm();
public: Q_SIGNALS:
    void newconn(QHostAddress address, qint16 port);

};

#endif // SETIP_H
