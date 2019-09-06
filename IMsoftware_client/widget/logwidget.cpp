#include "logwidget.h"
#include "ui_logwidget.h"
#include <QMessageBox>

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
    //ui->textBrowser->append(s);
}

void LogWidget::deal_connect_error()
{
    QMessageBox::warning(this,"异常","与服务器连接异常!",QMessageBox::Ok);
}

void LogWidget::deal_reg_check()
{
    this->show();
}

void LogWidget::deal_reg_cancel()
{
    this->show();
}

void LogWidget::deal_close_mainform()
{
    this->show();
}

void LogWidget::on_reg_pushButton_clicked()
{
    RegWidget *reg = new RegWidget();
    reg->show();
    this->hide();

    connect(reg,SIGNAL(do_reg_cancel()),this,SLOT(deal_reg_cancel()));
    connect(reg,SIGNAL(do_reg_check()),this,SLOT(deal_reg_check()));
}
void LogWidget::on_login_Button_clicked()
{
    MainForm *mainform = new MainForm();
    mainform->show();
    this->hide();

    connect(mainform,SIGNAL(do_close_mainform()),this,SLOT(deal_close_mainform()));
}


void LogWidget::on_Exit_pushButton_clicked()
{
    emit do_CloseClient();
    this->close();
}
