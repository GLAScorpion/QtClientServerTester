#include "argparser.h"
#include "utils.h"
ArgParser::ArgParser(int &argc, char *argv[])
    :argnum(argc),
      arguments{argv}

{
}

QCoreApplication* ArgParser::GUIArg()
{
    for (int i = 1; i < argnum; ++i) {
        if (std::string(arguments[i]) == "--nogui")
            return new QCoreApplication(argnum, arguments);
    }
    return new QApplication(argnum, arguments);
}

QHostAddress ArgParser::AddressArg(){
    for (int i = 1; i < argnum - 1; ++i) {
        if (std::string(arguments[i]) == "--address"){
            QString address(arguments[i+1]);
            if(Utils::IpValidator(address)){
                return QHostAddress(address);
            }
        }
    }
    return QHostAddress::LocalHost;
}

qint16 ArgParser::PortArg(){
    for (int i = 1; i < argnum - 1; ++i) {
        if (std::string(arguments[i]) == "--port"){
            QString port(arguments[i+1]);
            int pos = 0;
            if(Utils::PortValidator.validate(port,pos)==QIntValidator::Acceptable){
                return port.toInt();
            }
        }
    }
    return Utils::kPort;
}
