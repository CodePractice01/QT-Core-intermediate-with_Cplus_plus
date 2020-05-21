#include <QCoreApplication>
#include <QDebug>
#include <QMap>
#include <QString>

//The QMa class is a template class that provides a red-black-tree-based discotnary

//QMap<key, T> is one of Qt's generic container classes
// IT stores (key, values) pairs and provides fast lookup of the value associated qith a key


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<QString, int> ages;
    ages.insert("Bryan", 44);
    ages.insert("Erm", 28);
    ages.insert("Tammy", 30);

    qInfo() << "Erm is  " << ages["Erm"] << "years old";
    qInfo() << "Keys " << ages.keys();


    //Order - a lite slower
    foreach (QString key,  ages.keys()) {
        qInfo() << key << " = " << ages[key];

    }



            return a.exec();
}
