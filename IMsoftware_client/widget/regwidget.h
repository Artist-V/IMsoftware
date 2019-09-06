#ifndef REGWIDGET_H
#define REGWIDGET_H
#pragma execution_character_set("utf-8")
#include <QWidget>

namespace Ui {
class RegWidget;
}

class RegWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RegWidget(QWidget *parent = 0);
    ~RegWidget();

private:
    Ui::RegWidget *ui;

signals:
    void do_reg_check();
    void do_reg_cancel();

private slots:
    void on_confirm_pushButton_clicked();
    void on_exit_pushButton_clicked();
};

#endif // REGWIDGET_H
