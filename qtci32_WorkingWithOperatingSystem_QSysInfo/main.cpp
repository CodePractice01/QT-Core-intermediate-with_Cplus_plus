#include <QCoreApplication>
#include <QDebug>
#include <QSysInfo>



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSysInfo sys;

    qInfo() << "System info";
    qInfo() << "Boot ID: " << sys.bootUniqueId();
    qInfo() << "Build : " << sys.buildAbi();
    qInfo() << "CPU: " << sys.buildCpuArchitecture();
    qInfo() << "Kernel: " << sys.kernelType();
    qInfo() << "Kernel version : " << sys.kernelVersion();
    qInfo() << "mac version: " << sys.macVersion();
    qInfo() << "Windows version: " << sys.windowsVersion();
    qInfo() << "Host name: " << sys.machineHostName();
    qInfo() << "Product: " << sys.prettyProductName();
    qInfo() << "Type: " << sys.productType();
    qInfo() << "Version: " << sys.productVersion();

    #ifdef Q_QS_LINUX
            qInfo() << "Linux code here: ";
        #elif defined(W_OS_WIN32)
            qInfo() << "Windows code here: ;"
        #elif defined(W_OS_MACX)
            qInfo() << "Mac code here: ";
    #else
        qInfo() << "Unknow code here: ";
    #endif

    return a.exec();
}
