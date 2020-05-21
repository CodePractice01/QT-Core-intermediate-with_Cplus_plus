#include "test.h"

test::test(QObject *parent) : QObject(parent)
{

}

void test::useWidget()
{
    //se if there is a pointer

    if(!widget.data())
    {
        qInfo()<<" no pointer!!";

        return;
    }

    qInfo() << "Widget = " << widget.data();
    //Access the pointer
    widget.data() ->setObjectName("used widget!");

}
