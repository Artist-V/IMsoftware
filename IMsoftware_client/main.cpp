#include "widget/logwidget.h"
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
    QObject::connect(thread,SIGNAL(connect_error()),&w,SLOT(deal_connect_error()));
    QObject::connect(&w,SIGNAL(do_CloseClient()),thread,SLOT(CloseClient()));

    return a.exec();
}
