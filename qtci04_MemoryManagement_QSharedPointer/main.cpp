#include <QCoreApplication>

#include <QSharedPointer>
#include "test.h"
#include "consumer.h"



//QSharedPointer will delete the pointer it is holding when it goes out of scope
//provide no other QSharedPointer objects are referencing it


void doDeleteLAter(test *obj)
{
    qInfo() << "Deleting:" << obj;
    obj->deleteLater();
}
QSharedPointer<test> createPointer()
{
    //pointer out on the heap
    test *t =  new test(); // the bad qay!!
    t->setObjectName("Test Object");

    //taking that pointer and putting it into a non pointer
    QSharedPointer<test> p(t, doDeleteLAter);

    //and then we-re just returning that
    return p;

}
//QSharedPointer<consumer>  --> for consumet classes
void doStuff(QSharedPointer<consumer> ptr)
{
      qInfo() << "In function : "<< ptr.data()->tester;

      ptr.clear();//does not actually delete!, just removes the reference
}


QSharedPointer<consumer> makeConsumer()
{
    //create a new consumer
    QSharedPointer<consumer> c(new consumer, &QObject::deleteLater);
    //create a pointer
    QSharedPointer<test> t = createPointer();

    c.data()->tester.swap(t);

    doStuff(c);

    return c;
}
int main(int argc, char *argv[])

{
    QCoreApplication a(argc, argv);

    QSharedPointer<consumer> consum = makeConsumer();
    qInfo() << "In main: " << consum.data()->tester;

    consum.clear();

    return a.exec();
}
