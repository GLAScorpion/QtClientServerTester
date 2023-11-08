#ifndef SETIP_H
#define SETIP_H

#include <QDialog>
#include <QLabel>
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
};

#endif // SETIP_H
