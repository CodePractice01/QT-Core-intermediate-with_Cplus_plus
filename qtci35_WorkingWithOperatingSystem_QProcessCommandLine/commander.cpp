#include "commander.h"

//constructor
commander::commander(QObject *parent) : QObject(parent)
{
#ifdef Q_QS_WIN
    //windows
    app = "cmd";
    endl = "\r\n";
#else
    //not windows
    app = "bash";
    endl = "\n";
    qInfo() << "Bash";

#endif


        proc.setProgram(app);
        //start process
        proc.start();
        proc.setReadChannelMode(QProcess::MergedChannels);
        connect(&proc, &QProcess::readyRead, this, &commander::readyRead);
        connect(&proc, &QProcess::readyReadStandardOutput, this, &commander::readyRead);
        connect(&proc, &QProcess::readyReadStandardError, this, &commander::readyRead);
}

//deconstructor
commander::~commander()
{
    if(proc.isOpen()) proc.close();

}

void commander::readyRead()
{
    qint64 value = 0;

    do{
        QByteArray line = proc.readAll();
        qInfo() << line.trimmed();
        value = line.length();

    }while(value >0 );
}

void commander::action(QByteArray data)
{
    if(data.endsWith(endl.toLatin1() )) data.append(endl);
    proc.write(data);
    proc.waitForBytesWritten(1000);


}
