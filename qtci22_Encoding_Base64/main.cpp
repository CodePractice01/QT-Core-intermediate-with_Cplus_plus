#include <QCoreApplication>
#include <QDebug>

/*
Base64 is a group of similar binary-to-text encoding chemes that represent binary data in an ASCII
string format by

The term Base64 orginiates from a specific MIME content transfer encoding
Each Based64 digit representa eaxctly 6 bits of data.Three 8-bit bytes(_

*/

QString makeData()
{
    QString data;
    for(int i =0 ;i< 10;i++)
    {
        data.append("Hello \r\n");
    }

    return data;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString data = makeData();
    QByteArray bytes(data.toLatin1());
    QByteArray encoded = bytes.toBase64();
    QByteArray decoded = QByteArray::fromBase64(encoded);

    qInfo() << "Encoded: " << encoded;
    qInfo("-----------------------------");
    qInfo() << "Decoded: " << decoded;

    return a.exec();
}
