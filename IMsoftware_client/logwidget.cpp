#include "logwidget.h"
#include "ui_logwidget.h"

LogWidget::LogWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogWidget)
{
    ui->setupUi(this);

//ui
    this->setWindowTitle(tr("IM 即时通讯软件"));
    this->setWindowIcon(QPixmap(":/icon/龙.png"));
}

LogWidget::~LogWidget()
{
    delete ui;
}

void LogWidget::deal_recv_message(QString s)
{
    ui->textBrowser->append(s);
}


void LogWidget::on_pushButton_clicked()
{
    emit send_ipandport(ui->IP_lineEdit->text(),ui->PORT_lineEdit->text());
}
