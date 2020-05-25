#include <QCoreApplication>
#include <QtDebug>

//Custom macro

#define add(a,b) a+b


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Easy...but dangerouse
    qInfo() << add(1,2);


    //let's break it
    qInfo() << add("Test",22);
    qInfo() << add(true,true);
    qInfo() << add(false,true);
    qInfo() << add(false,false);
    qInfo() << add("test",'\n');
    qInfo() << add("test",'/n');

    return a.exec();
}
