#ifndef MYCLIENT_H
#define MYCLIENT_H
#include <QTcpSocket>

class MyClient : public QTcpSocket{
    Q_OBJECT
public:
    MyClient(QObject* parent = nullptr);
public slots:
    void process_message();
    void send_message(std::string message);
public: Q_SIGNALS:
    void ready_message(std::string message);
};


#endif // MYCLIENT_H
