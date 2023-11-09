#include "utils.h"
#include <QRegularExpression>

bool Utils::IpValidator(QString ip)
{
    static QRegularExpression ipPattern("^((25[0-5]|2[0-4][0-9]|[01]?[0-9]{1,2})\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9]{1,2})$");
    QRegularExpressionMatch match = ipPattern.match(ip);
    if(!match.hasMatch())
        return false;

    QStringList parts = ip.split('.');

    for (int i = 0; i < parts.size(); ++i)
    {
        const QString &part = parts.at(i);
        bool ok;
        int num = part.toInt(&ok);
        if (!ok || num < 0 || num > 255 || (part.length() > 1 && part.startsWith("0") && !part.startsWith("0.")))
            return false;
    }

    //if you wish, you could end immediately simply here
    return true;
}
