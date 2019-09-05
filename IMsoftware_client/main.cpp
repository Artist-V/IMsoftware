#include "logwidget.h"
#include <QApplication>
#include "mythread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LogWidget w;
    w.show();

    MyThread *thread = new MyThread;
    thread->start();

    QObject::connect(thread,SIGNAL(send_message(QString)),&w,SLOT(deal_recv_message(QString)));
    QObject::connect(&w,SIGNAL(send_ipandport(QString,QString)),thread,SLOT(deal_recv_ipandport(QString,QString)));

    return a.exec();
}
