#include "mythread.h"


Mythread::Mythread(QObject *parent) : QThread(parent)
{
    Tsocket = new QTcpSocket;
}

void Mythread::run()
{
    qDebug() << "run";

    Tserver = new QTcpServer();

    quint16 port = 9090;
    Tserver->listen(QHostAddress::Any,port);

    connect(Tserver,SIGNAL(newConnection()),this,SLOT(deal_connect()));

    this->exec();
}

void Mythread::deal_connect()
{
    Tsocket = Tserver->nextPendingConnection();

    QString ip = Tsocket->peerAddress().toString();
    int port = Tsocket->peerPort();

    emit send_ipandport(ip,port);
}
