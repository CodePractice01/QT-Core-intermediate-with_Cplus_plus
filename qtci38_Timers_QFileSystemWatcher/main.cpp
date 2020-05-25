#include <QCoreApplication>
#include "watcher.h"

//when you want to see when something changed use
//#include <QFileSystemWatcher>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Watcher w;

    return a.exec();
}
