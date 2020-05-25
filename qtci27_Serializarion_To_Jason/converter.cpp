#include "converter.h"

converter::converter(QObject *parent) : QObject(parent)
{

}

void converter::writeJson(test *obj, QString path)
{
    QVariantMap map;
    QVariantMap items;
 //--------------
    //single key value pair caller name with the 'object's name'
    map["name"] = obj->name();

 //--------------
    //say for each keys then to items -which is also a Q variant map
    foreach(QString key, obj->map().keys() )
    {
        //insert the key and maps variant
        //and filling that out qith the map from test class
        items.insert(key, QVariant(obj->map().value(key)) );
    }

    //--------------
    //build the document, in the documents in memory we need to pump that document down into the hard drive
   //and filling from the map
    QJsonDocument document = QJsonDocument::fromVariant(map);

    QFile file(path);

    if(!file.open(QIODevice::WriteOnly))
    {
        qCritical() << "could not write file!";
         qCritical() <<file.errorString();
         return;
        //QString reason = file.errorString();
      //  qFatal(reason.toLatin1());

    }

    map["items"] = QVariant(items);

    file.write(document.toJson());
    file.close();
}

test *converter::readJson(QString path)
{
//read all the content file
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
        {
            qCritical() << "could not read file!";
             qCritical() <<file.errorString();


        }
    QByteArray data = file.readAll();
    file.close();

    //conveert document to json
    QJsonDocument document = QJsonDocument::fromJson(data);

    test *t = new test();
    t->setName(document["name"].toString());
    QVariantMap vmap= qvariant_cast<QVariantMap>(document["items"]);

    //fill the class test
    QMap<QString, QString> map;

    foreach(QString key, vmap.keys())
    {
        map.insert(key,vmap[key].toString());
    }

    t->setMap(map);

    return t;
}
