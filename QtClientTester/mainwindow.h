#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QAction>
#include <QTcpSocket>
#include "myclient.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    MyClient* client = nullptr;
    QAction* IpSetter = nullptr;
    QPlainTextEdit* Console = nullptr;
    QPlainTextEdit* InsMex = nullptr;
    QPushButton* SendMex = nullptr;
    QPushButton* Connect = nullptr;
    Ui::MainWindow *ui = nullptr;
public slots:
    void start_conn();
    void write_console(std::string message);
    void broadcast();
    void setip();
public: Q_SIGNALS:
    void send_message(std::string data);
    //void send_pressed();
};
#endif // MAINWINDOW_H
