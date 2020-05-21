#include <QCoreApplication>
#include <QDebug>
#include <QSettings>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setOrganizationName("Erm");
    QCoreApplication::setOrganizationDomain("Erm.com");
    QCoreApplication::setApplicationName("Teste");

    QSettings settings(QCoreApplication::organizationName(),QCoreApplication::applicationName());

    //save the settings
    settings.setValue("test",120);

    //read the setting back
    qInfo() << settings.value("test").toString();
    qInfo() << settings.value("test").toInt();

    return a.exec();
}
