#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

//ui
    this->setWindowTitle(tr("server:9090"));
    this->setWindowIcon(QPixmap(":/龙.png"));
//mythread
    thread = new Mythread;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::deal_recv_ipandport(QString ip, int port)
{
    ui->textBrowser->append(QString("[new] client connect IP[%1],PORT[%2] ").arg(ip).arg(QString::number(port)));
}


void Widget::on_OpenButton_clicked()
{
    ui->textBrowser->append(QString("--------开启服务器--------"));
    thread->start();

    QObject::connect(thread,SIGNAL(send_ipandport(QString,int)),this,SLOT(deal_recv_ipandport(QString,int)));
}

void Widget::on_CloseButton_clicked()
{
    ui->textBrowser->append(QString("--------关闭服务器--------"));
}
