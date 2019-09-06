#ifndef LOGWIDGET_H
#define LOGWIDGET_H
#pragma execution_character_set("utf-8")
#include <QWidget>
#include "regwidget.h"
#include "mainform.h"

namespace Ui {
class LogWidget;
}

class LogWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LogWidget(QWidget *parent = 0);
    ~LogWidget();

private:
    Ui::LogWidget *ui;

signals:
    void do_CloseClient();
private slots:
    void on_login_Button_clicked();
    void on_reg_pushButton_clicked();
    void on_Exit_pushButton_clicked();

//mythread
    void deal_recv_message(QString s);  //处理连接情况
    void deal_connect_error();  //处理异常情况
//reg
    void deal_reg_check();  //处理注册确认
    void deal_reg_cancel(); //处理取消注册
//mainform
    void deal_close_mainform();
};

#endif // LOGWIDGET_H
