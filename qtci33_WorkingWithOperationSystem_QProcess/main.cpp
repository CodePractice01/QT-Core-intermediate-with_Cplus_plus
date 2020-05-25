#include <QCoreApplication>
#include <QDebug>
#include <QProcess>
#include <QDir>

//QProcess

bool test()
{

    QProcess gzip;
    //start the process and give and argument "-c"
    gzip.start("gzip", QStringList() << "-c");

    if(!gzip.waitForStarted()) return false;

    gzip.write("Qt rocks!");
    gzip.closeWriteChannel();

    if(!gzip.waitForFinished()) return false;
    QByteArray result = gzip.readAll();
    qInfo() << "Result: " << result;

    return true;

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(test())
    {
        qInfo() << "Compressed with gzip";
    } else{
        qInfo() << "Failed to use gzip";
    }


    return a.exec();
}
