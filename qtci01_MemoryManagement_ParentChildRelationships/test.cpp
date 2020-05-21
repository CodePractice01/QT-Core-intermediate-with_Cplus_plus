#include "test.h"

test::test(QObject *parent) : QObject(parent)
{
    qInfo() << this << "Constructed";

}

test::~test()
{
    qInfo() << this << "DEConstructed";
}

void test::makeChild(QString name)
{
    test *child = new test(this);
    child->setObjectName(name);

}
