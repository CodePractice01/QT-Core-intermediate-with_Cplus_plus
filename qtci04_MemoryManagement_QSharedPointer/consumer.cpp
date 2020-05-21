#include "consumer.h"

consumer::consumer(QObject *parent) : QObject(parent)
{
    qInfo() << "Constructed consumer" <<this;
}


consumer::~consumer()
{
     qInfo() << "DEConstructed consumer" <<this;
}
