#include <QCoreApplication>
#include <QVector>
#include <QDebug>
#include <QList>


//template

template<class T>

//call template and pass by reference

void fill(T &container)
{
    for(int i =0; i< 5;i++)
    {
        container.append(i);
    }
}


template<class T>

//&container - & prove that we're qorking with the same object,we-re not making a copy
void display(T &container)
{
    for(int i =0;i<container.length(); i++)
    {
        if(i > 0){
            //auto automatically interpete the type
            auto current = reinterpret_cast<std::uintptr_t>(&container.at(i));
            auto previous = reinterpret_cast<std::uintptr_t>(&container.at(i-1));

            auto distance = current-previous;

            qInfo() << i <<"At: "<< current << "  Previous: "<<previous << " Distance: "<< distance;
        }
        else
        {
            qInfo() << i << &container.at(i) << "Distance: 0";

            }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //blanck Qvector
    QVector<int> vect = QVector<int>();


    QList<int> list = QList<int>();

    fill(vect);
    fill(list);


    qInfo() << "Int takes" << sizeof(int) << " bytes of ram";
    qInfo() << " Qvector uses continous locations in memory ";


    display(vect);
    qInfo("");

    //

    qInfo() << " QList uses what ever it can find  in memory";

    display(list);
    qInfo("");

    return a.exec();
}
