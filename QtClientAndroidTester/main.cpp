#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "clienthandler.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<ClientHandler>("my.handler",1,0,"ClientHandler");
    QScopedPointer<ClientHandler> client(new ClientHandler);
    engine.setInitialProperties(QVariantMap{{"handler", QVariant::fromValue<ClientHandler *>(client.data())}});
    const QUrl url(u"qrc:/QtClientAndroidTester/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {

        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);
    return app.exec();
}
