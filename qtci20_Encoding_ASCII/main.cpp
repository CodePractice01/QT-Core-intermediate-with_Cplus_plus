#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>

/*
 * Encoding
 * ASCII is a 7-bit character set containing 128 characters
 * It contains the number from 0-9, the upper and lower case English letters from A to Z, and some special characters
 * The Character sets used in modern computers, in HML, and on the Internet, are all vased on ASCII



*/

QByteArray makeData()
{
    QByteArray data;

    for(int i =0;i< 10;i++)
    {
        data.append(72);//H
        data.append(101);//E
        data.append(108);//L
        data.append(108);//L
        data.append(111);//O
        data.append(33);// !
        data.append(13);// \r
        data.append(10);//  \n

    }
    return data;

}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray data = makeData();
    QString path = QDir::currentPath()+ QDir::separator() +"data";

    QFile file(path);

    if(file.open(QIODevice::WriteOnly)){
        file.write(data);
        file.close();
    }

    qInfo() <<"done";

    return a.exec();
}
