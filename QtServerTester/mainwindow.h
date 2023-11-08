#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QAction>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void ServerBind();

private:
    QAction* IpSetter;
    QPlainTextEdit* Console;
    QPlainTextEdit* InsMex;
    QPushButton* SendMex;
    Ui::MainWindow *ui;
public slots:
    void send_console();
    void setip();
};
#endif // MAINWINDOW_H
