#ifndef MYTHREAD_H
#define MYTHREAD_H
#pragma execution_character_set("utf-8")
#include <QThread>
#include <QTcpServer>
#include <QTcpSocket>


class Mythread : public QThread
{
    Q_OBJECT
public:
    explicit Mythread(QObject *parent = 0);
    void run();

signals:
    void send_ipandport(QString,int);
public slots:
    void deal_connect();

private:
    QTcpServer *Tserver;
    QTcpSocket *Tsocket;
};

#endif // MYTHREAD_H
