#ifndef COMMANDER_H
#define COMMANDER_H


#include <QObject>
#include <QDebug>
#include <QProcess>


class commander : public QObject
{
    Q_OBJECT
public:
    explicit commander(QObject *parent = nullptr);
    ~commander();
signals:

public slots:
    //read back from qPRocess
    void readyRead();

    //send data
    void action(QByteArray data);

private:
    QProcess proc;
    QString app;
    QString endl;

};

#endif // COMMANDER_H
