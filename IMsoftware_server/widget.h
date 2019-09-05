#ifndef WIDGET_H
#define WIDGET_H
#pragma execution_character_set("utf-8")
#include <QWidget>
#include "mythread.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    Mythread *thread;

private slots:
    void deal_recv_ipandport(QString ip,int port);

    void on_OpenButton_clicked();
    void on_CloseButton_clicked();
};

#endif // WIDGET_H
