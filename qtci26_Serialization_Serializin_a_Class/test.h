#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>
#include <QMap>
#include <QDataStream>


class test : public QObject
{
    Q_OBJECT
public:
    explicit test(QObject *parent = nullptr);

    //functions
    void fill();
    QString name();
    void setName(QString value);
    QMap<QString, QString> map();

//call overloading operator
    //   <<which operator to overload
    friend QDataStream& operator << (QDataStream &stream, const test &t)
    {
        qInfo() << "Overload <<< ";

        //"tell" what to do
        //acces private variables
        //the order is very specific

        stream << t.m_name;
        stream << t.m_map;

        return stream;


    }


    friend QDataStream& operator >> (QDataStream &stream, test &t)
    {
        qInfo() << "Overload <<< ";

        stream >> t.m_name;
        stream >> t.m_map;

        return stream;

    }

signals:

public slots:

private:
    QString m_name;

    QMap<QString, QString> m_map;
};

#endif // TEST_H
