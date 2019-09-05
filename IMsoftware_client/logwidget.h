#ifndef LOGWIDGET_H
#define LOGWIDGET_H
#pragma execution_character_set("utf-8")
#include <QWidget>

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

private slots:
    void deal_recv_message(QString s);  //处理连接情况
    void deal_connect_error();  //处理异常情况
};

#endif // LOGWIDGET_H
