#include <QCoreApplication>
#include <QDebug>
#include <QSettings>
#include <QStringList>
#include <QRandomGenerator>
#include <QString>

//set the value in the group
void saveAge(QSettings *setting, QString group, QString name, int age)
{
    setting->beginGroup(group);
    setting->setValue(name,age);
    setting->endGroup();

}

int getAge(QSettings *setting, QString group, QString name)
{

    setting->beginGroup(group);

    //make sure that the key actually exists before we try to read it

    if(!setting->contains(name))
    {
           qInfo() << "Does not contain" << name << "in " << group;

           setting->endGroup();
           return 0;
    }

    bool ok;
     //then if it exists we're going to read it back as an integer and we;re going to actually
    //double check to make sure it converts
    int value = setting->value(name).toInt(&ok);
    setting->endGroup();

    if(!ok)
    {
        qInfo() << "failed to convert to int!!";

        return 0;
    }

    return value;


}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setOrganizationName("Erm");
    QCoreApplication::setOrganizationDomain("Erm.com");
    QCoreApplication::setApplicationName("Teste");

    QSettings settings(QCoreApplication::organizationName(),QCoreApplication::applicationName());



    saveAge(&settings, "people","Bryan",44);
    saveAge(&settings, "beer","twoheart",1);
    saveAge(&settings, "beer", "Bryand",1);

   /* qInfo() << "TwoHeart" << getAge(&settings,"beer","twoheart");
    qInfo() << "Bryan (people)" << getAge(&settings,"people","Bryan");
    qInfo() << "Bryan(bear)" << getAge(&settings,"beer","Bryan");*/


    QStringList people;
    people << "Bryan" << "Tamy" << "Heather" << "Chris";
    foreach (QString person, people) {
        int value = QRandomGenerator::global()->bounded(100);
        saveAge(&settings,"test",person,value);

    }

    //ensure it saved
    settings.sync();
    //it's saved in a hidden file
    qInfo()<<settings.fileName();

    foreach(QString group, settings.childGroups())
    {
        settings.beginGroup(group);
        qInfo() << "Group: " << group;


        foreach(QString key, settings.childKeys())
        {
            qInfo() << "....key* " << key << "= " << settings.value(key).toString();
        }

        settings.endGroup();
    }



    return a.exec();
}
