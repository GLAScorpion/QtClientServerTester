#ifndef MYCLIENT_H
#define MYCLIENT_H
#include <QTcpSocket>

class MyClient : public QTcpSocket{
    Q_OBJECT
public:
    MyClient(QObject* parent = nullptr);
    //void SetNickname(std::string Nickname){nickname = Nickname;}
    std::string GetNickname(){return nickname;}
    bool connect(QString address, QString port, QString nick);
private:
    std::string nickname;
public slots:
    void process_message();
    void send_message(std::string message);
public: Q_SIGNALS:
    void ready_message(std::string message);
    void error_occurred(std::string error);
};


#endif // MYCLIENT_H
