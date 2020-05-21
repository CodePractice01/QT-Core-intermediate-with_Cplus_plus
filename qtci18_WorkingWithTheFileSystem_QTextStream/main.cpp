#include <QCoreApplication>

#include <QDebug>
#include <QTextStream>
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QRandomGenerator>


//4-8---QTextStream



bool createFile(QString path)
{
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly)){
        qWarning() << file.errorString();
        return false;
    }

    //Qdata stream - allow to stream data into the file insteand of writing it in blocks
    QTextStream stream(&file);
    int max = 1000;
    //writing a stream
    QString banner = "Random number: \r\n";
    qInfo() << "Writing " << banner;
    stream << banner;

    for(int i = 0;i<5;i++){
        //calling a singleton pattern of the Q random generator meaning we'te getting
        //the global instance of that class
        //and bounded meaning it's going to take a minimum or a maximum

        qint32 num =QRandomGenerator::global()->bounded(max); //writing a number
        qInfo() << "Writing: " << num;
        stream << num << "\r\n";

    }

    file.close();
    return true;
}

void readFile(QString path){
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        qWarning() << file.errorString();
        return;
    }

    QTextStream stream(&file);

    QString banner;
    stream >> banner;
    qInfo() << "Banner: " << banner ;

    for(int i = 0;i<5;i++){
      // qint32 num;
        QString num;
       stream >> num;
       qInfo()<< "Random " << num;

    }

    file.close();
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path = QDir::currentPath() + QDir::separator() + "TEST.txt";

    qInfo() << "PAth " << path;

    if(createFile(path)){
        readFile(path);
    }

    return a.exec();
}
