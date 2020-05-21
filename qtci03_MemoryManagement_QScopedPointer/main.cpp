#include <QCoreApplication>
#include <QDebug>
#include <QScopedPointer>
#include "test.h"

//The QscopePointer cclass stores a pointer to a dynamically allocated object,
//and deletes it upon destruction!!

//create scope


void myTest(QScopedPointer<test> &myPointer)
{
    qInfo() << myPointer.data();
}
void useit(test* obj)
{
    if(obj) return;

         qInfo() << "Using" << obj;
}


void doStuff()
{
    //test *t = new test();//dangling pointer!!!    -- old sintax just for reference

    QScopedPointer<test> myPointer(new test());
    //useit(myPointer.data());

    myTest(myPointer);

    //pointer is automacally deleted !!
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

   /* for(int i = 0; i< 100;i++)
    {
        doStuff();
    }*/

    doStuff();

    return a.exec();
}
