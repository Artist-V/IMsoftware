#ifndef COLORPICKFORM_H
#define COLORPICKFORM_H

#pragma execution_character_set("utf-8")
#include "moveableframelesswindow.h"
#include "src/singleton.h"


#include <QPushButton>
#include <QWidget>


namespace Ui {
class ColorPickForm;
}

/*主题颜色选择窗口*/

class ColorPickForm : public MoveableFramelessWindow, public Singleton<ColorPickForm>
{
    Q_OBJECT
public:
    ~ColorPickForm();

signals:
    void themColorChanged(QString colorStr);    //主题颜色改变

protected:
      friend class Singleton<ColorPickForm>;
      ColorPickForm(QWidget *parent = 0);
      QWidget*getDragnWidget();//主题改变

private slots:
      void onColorButClick(QPushButton *pub);
      bool eventFilter(QObject *sender, QEvent *e);//定义事件过滤，用来扑捉主题颜色点击事件
      void onThemeColorChange(QString colorStr);
      void onColorPanleClick();//调色盘按钮点击

      void on_pushButton_clicked();

private:
    Ui::ColorPickForm *ui;
};

#define MY_COLOR_PICK_FORM ColorPickForm::getInstance()

#endif // COLORPICKFORM_H
