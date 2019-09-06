#ifndef COLLAPSEVIEWITEM_H
#define COLLAPSEVIEWITEM_H

#include <QWidget>
#include <QList>

namespace Ui {
class CollapseViewItem;
}

class CollapseViewItem : public QWidget
{
    Q_OBJECT

public:
    explicit CollapseViewItem(QString titleText,QWidget *parent = 0);
    ~CollapseViewItem();

    void setTitleText(QString titleText);//设置名字
    void addSubItems(QList<QWidget *> widgets);//展开抽屉后的内容项目列表
    void addSubItem(QWidget*widget);//展开抽屉后的内容项目内容

private slots:
    void onCollapseButClick();//项目折叠

private:
    Ui::CollapseViewItem *ui;

};

#endif // COLLAPSEVIEWITEM_H
