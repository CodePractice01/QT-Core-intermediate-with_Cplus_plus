#include <QCoreApplication>
#include<QIODevice>
#include <QBuffer>
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QBuffer buffer;

    if(buffer.open(QIODevice::ReadWrite))
    {
        qInfo() << "Buffer opened! ";
        QByteArray data("HElloooo");

        for(int i=0;i<5;i++)
        {
            buffer.write(data);
            buffer.write("\r\n");
        }
        //File and device access you may need to flush the data to the device
        //buffer.flush()
        buffer.seek(0);

        qInfo() << buffer.readAll(); //return all the key buffer into array
        qInfo() << "closing the buffer";

        //always close your device!
        buffer.close();

    }else {
     qInfo() << "Could not open buffer!!";
    }
    return a.exec();
}
