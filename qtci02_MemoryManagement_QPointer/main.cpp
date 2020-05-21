#include <QCoreApplication>

//The QPointer class is a template class that provides guarded pointers to QObject
//remember we might not controll the pointer in the consumer class

#include <QDebug>
#include <QPointer>
#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QObject * obj = new QObject(nullptr);
    obj->setObjectName("My object");

    QPointer<QObject> p(obj);

    test t;
    t.widget = p;
    t.useWidget();

    if(p.data()) qInfo() <<p.data();

    delete obj;

    t.useWidget();

    return a.exec();
}
