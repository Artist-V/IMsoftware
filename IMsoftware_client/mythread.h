#ifndef MYTHREAD_H
#define MYTHREAD_H
#pragma execution_character_set("utf-8")
#include <QThread>
#include <QTcpSocket>


class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = 0);
    void run();

signals:
    void send_message(QString);
    void connect_error();

public slots:
    void deal_connect();    //处理连接成功
    void deal_disconnect(); //处理连接失败
    void deal_error(QAbstractSocket::SocketError error);    //处理连接异常
    void deal_read();   //处理通信数据
    void CloseClient(); //处理客户端关闭

private:
    QTcpSocket *Tsocket;
};

#endif // MYTHREAD_H
