#include <QCoreApplication>
#include <QDebug>
#include <QDataStream>
#include <QFile>

/*


*/
bool saveFile(QString path)
{
    QFile file(path);
//open file
    if(!file.open(QIODevice::WriteOnly)) return false;

    QDataStream out(&file); //reference to file

    //set the version
    out.setVersion(QDataStream::Qt_5_14);

    QString title = "The answer is 42";

    qint64 num = 42;

    //shift information out into the data stream which is going to put
    //it out the file
    out << title;
    out << num;
    //serialized integer and string




    file.flush();
    file.close();

    return true;
}

bool readFile(QString path)
{
    QFile file(path);

    if(!file.open(QIODevice::ReadOnly)) return false;

    QDataStream in(&file);

    if(in.version() != QDataStream::Qt_5_14)
    {
        qCritical()<< "Boda version";
        file.close();

        return false;
    }

    QString title;
    qint64 num;

    in >> title;
    in >> num;

    qInfo() << title;
    qInfo() << num;

    return true;

}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString fileName = "test.txt";
    if(saveFile(fileName)){
        qInfo() << "Saved!";

        //read the file

        readFile(fileName);
    }
    return a.exec();
}
