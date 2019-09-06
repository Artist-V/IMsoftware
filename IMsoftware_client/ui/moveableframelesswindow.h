#ifndef MOVEABLEFRAMELESSWINDOW_H
#define MOVEABLEFRAMELESSWINDOW_H
#pragma execution_character_set("utf-8")
#include <QObject>
#include <QWidget>
#include <QPoint>
/**
 * @brief 无边框窗体
 */
class MoveableFramelessWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MoveableFramelessWindow(QWidget *parent);

protected:
    void mousePressEvent(QMouseEvent *event); //鼠标按下:准备拖动窗体
    void mouseMoveEvent(QMouseEvent *event); //鼠标移动:处理窗体拖动
    void mouseReleaseEvent(QMouseEvent *event); //鼠标释放

    virtual QWidget*getDragnWidget() = 0; //获取可拖动控件，必须由子类指定
    bool isPointInDragnWidget(const QWidget*widget,const QPoint &point); //判断鼠标点击的位置是否进入可拖动区域

    bool isMove;//标志是否移动窗体

    QPoint pressedPoint; //鼠标按下去的点

protected slots:
     virtual void onThemeColorChange(QString colorStr){} //主题改变

signals:

public slots:

};

#endif // MOVEABLEFRAMELESSWINDOW_H
