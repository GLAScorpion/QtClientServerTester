#ifndef SETIP_H
#define SETIP_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QHostAddress>
#include <QLineEdit>
namespace Ui {
class SetIp;
}

class SetIp : public QDialog
{
    Q_OBJECT

public:
    explicit SetIp(QWidget *parent = nullptr);
    void SetIpPort(QString address, qint16 port);
    ~SetIp();

private:
    Ui::SetIp *ui = nullptr;
    QLabel* ErrorLabel = nullptr;
    QPushButton* ConfirmButton = nullptr;
    QLineEdit* IpAddress = nullptr;
    QLineEdit* Port = nullptr;
public slots:
    void confirm();
public: Q_SIGNALS:
    void newconn(QHostAddress address, qint16 port);

};

#endif // SETIP_H
