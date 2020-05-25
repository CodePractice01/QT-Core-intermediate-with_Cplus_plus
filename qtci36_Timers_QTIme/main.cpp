#include <QCoreApplication>
#include <QTimer>
#include <QDebug>

void test()
{
    qInfo() << "Thanks you for waiting";
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Please wait..";

    QTimer::singleShot(3000, &test); //time set to 3seconds  and call function

    return a.exec();
}
