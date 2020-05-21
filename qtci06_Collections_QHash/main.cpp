#include <QCoreApplication>
#include <QHash>
#include <QDebug>


//QHash --QHash<key, T> is one of Qt's generic container classes
//It stores(key, value) pairs and provides very fast lookup of the value associated with a key.

// Works great with static info that wont change much

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QHash<QString,int>ages;
    //insert value in QHash
    ages.insert("Erm", 28);
    ages.insert("Tammy", 49);
    ages.insert("HEather", 25);
    ages.insert("Chris", 30);
    ages.insert("Rango", 15);

    qInfo() << "Bryan is " << ages["Erm"] << "years old";
    qInfo() << "Keys: " << ages.keys();
    qInfo() << "Collection size : " << ages.size();

    foreach (QString key, ages.keys()) {
       qInfo() << key << " = " << ages[key];
    }

    return a.exec();
}
