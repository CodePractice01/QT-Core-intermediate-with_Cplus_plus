#include "test.h"

test::test(QObject *parent) : QObject(parent)
{
    //use variable in constructor
    number = 0;
    timer.setInterval(1000);
    //the the timer start
    //every time it fires off it's going to fire or should say emit the timeout signal that signal
    //is going to get consumed by our timeout slot whick is  void test::timeout()
    connect(&timer, &QTimer::timeout, this, &test::timeout);
}

void test::timeout()
{
    number++;
    qInfo() << QTime::currentTime().toString(Qt::DateFormat::SystemLocaleLongDate);

    if(number == 5)//seconds
    {
        timer.stop();
        qInfo() << "Complete !";
    }
}

void test::doStuff()
{
    timer.start();
}
