#ifndef MAINFORM_H
#define MAINFORM_H
#pragma execution_character_set("utf-8")
#include <QWidget>
#include "ui/moveableframelesswindow.h"
#include "ui/collapseview.h"
#include "ui/colorpickform.h"

namespace Ui {
class MainForm;
}

class MainForm : public MoveableFramelessWindow
{
    Q_OBJECT

public:
    explicit MainForm(QWidget *parent = 0);
    ~MainForm();

private:
    Ui::MainForm *ui;
signals:
    void do_close_mainform();

private slots:
    void onThemeColorChange(QString colorStr);
    void on_skin_Button_clicked();
    void on_close_Button_clicked();

protected:
      QWidget*getDragnWidget();
};

#endif // MAINFORM_H
