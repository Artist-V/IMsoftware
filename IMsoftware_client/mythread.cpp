#include "mythread.h"
#include <QDebug>
#include <QMessageBox>
#include <QHostAddress>

MyThread::MyThread(QObject *parent) : QThread(parent)
{
    Tsocket = new QTcpSocket();
}
void MyThread::run()
{
    Tsocket = new QTcpSocket();

    QString IP = "127.0.0.1";   //服务器IP
    quint16 port = 9090;    //TCP端口

    Tsocket->connectToHost(IP,port);

    connect(Tsocket,SIGNAL(connected()),this,SLOT(deal_connect()));
    connect(Tsocket,SIGNAL(disconnected()),this,SLOT(deal_disconnect()));
    connect(Tsocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(deal_error(QAbstractSocket::SocketError)),Qt::DirectConnection);
    connect(Tsocket,SIGNAL(readyRead()),this,SLOT(deal_read()));

    this->exec();
}

void MyThread::deal_connect()
{
    qDebug() << "connect success!";
    emit send_message(QString("连接服务器成功"));
}

void MyThread::deal_disconnect()
{
    qDebug() << "close connected!";
    emit send_message(QString("连接服务器失败"));
}

void MyThread::deal_error(QAbstractSocket::SocketError error)
{
    qDebug() << error;
    emit connect_error();
}

void MyThread::deal_read()
{

}

