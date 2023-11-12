#ifndef UTILS_H
#define UTILS_H
#include <QString>
#include <QIntValidator>
namespace Utils {
    bool IpValidator(QString ip);
    const qint16 kPort = 22222;
    const QIntValidator kValidPort(0,65535);
}

#endif // UTILS_H
