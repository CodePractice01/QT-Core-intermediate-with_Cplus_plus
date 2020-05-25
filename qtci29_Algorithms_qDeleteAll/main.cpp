#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include <QtAlgorithms>
#include "test.h"

//qDeleteAll



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //create a Q list of pointers to test class

    QList<test*> list;


    for(int i =0; i<10;i++)
    {
        test *t = new test(); // notice no parent!
        t->setObjectName(QString::number(i));
        list.append(t);
    }

    qInfo() << list.at(0);

    //Delete them all
    qDeleteAll(list);

    //will crash!
   // qInfo() << list.at(0);

    //Objects are still in the list but invalid pointers - clears the list
    list.clear();

    return a.exec();
}
