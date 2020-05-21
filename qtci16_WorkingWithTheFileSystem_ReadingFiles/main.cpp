#include <QCoreApplication>

#include <QIODevice>
#include <QDir>
#include <QFile>
#include <QString>
#include <QByteArray>
#include <QDebug>
#include <QTextStream>




bool write(QString path, QByteArray data)
{
        QFile file(path);
        if(!file.open(QIODevice::WriteOnly))
        {
            qWarning() << file.errorString();
            return false;
        }

        qint64 bytes = file.write(data);
        file.close();

        if(bytes) return true;

        return false;
}

bool createFile(QString path)
{
    QByteArray data;

//generate date
    for(int i = 0;i<5;i++)
    {
        data.append(QString::number(i));
        data.append(" Hello Lumme \r\n+");
    }

    return write(path,data);

}

void readFile(QString path)
{
  QFile file(path);

    if(!file.exists())
    {
        qWarning() << "File not found";
        return;
    }
    //open file
    if(!file.open(QIODevice::ReadOnly))
    {
        qWarning() << file.errorString();
        return;
    }

    qInfo() << " *********Reading file ";
     //return array-and it's kind of dangerous   ...it;s good for small files!
    qInfo() << file.readAll();

    qInfo() << " *********Done ";

    file.close();

}

void readLines(QString path){

    QFile file(path);

      if(!file.exists())
      {
          qWarning() << "File not found";
          return;
      }
      //open file
      if(!file.open(QIODevice::ReadOnly))
      {
          qWarning() << file.errorString();
          return;
      }

      qInfo() << " *********Reading file ";
        while(!file.atEnd()){
            QString line(file.readLine());
            qInfo() << "Read: " << line.trimmed(); //best with text files!
        }
      qInfo() << " *********Done ";

      file.close();

}

void readBytes(QString path){

    QFile file(path);

      if(!file.exists())
      {
          qWarning() << "File not found";
          return;
      }
      //open file
      if(!file.open(QIODevice::ReadOnly))
      {
          qWarning() << file.errorString();
          return;
      }

      qInfo() << " *********Reading file ";
        while(!file.atEnd()){
            //grab specific number of bytes and it just moving forward in the buffer
            qInfo() << "Read: " <<file.read(5); //best with larger file or structs
        }
      qInfo() << " *********Done ";

      file.close();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path = QDir::currentPath() + QDir::separator() + "Test.txt";
    qInfo() << "Path  " << path;

    if(createFile(path))
    {
        readFile(path);
        readLines(path); //return result on each line
        readBytes(path);
    }



    return a.exec();
}
