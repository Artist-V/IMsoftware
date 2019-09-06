#include "collapseviewitem.h"
#include "ui_collapseviewitem.h"
#pragma execution_character_set("utf-8")
#include "litteriem.h"

#include <QDebug>
#include <QTime>

int MAX_PERSON_PIC_NUM = 9;

CollapseViewItem::CollapseViewItem(QString titleText/*好友数量*/, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CollapseViewItem)
{
    ui->setupUi(this);
    ui->label->setProperty("slected",!ui->item_con->isVisible());


//添加自己进好友列表
    QString picPath = QString(":/icon/photo/p1.png");
    addSubItem(new LitterIem(picPath,this));

//未上线好友
    titleText=QString("%1 (0/1)").arg(titleText)/*.arg(QString::number(offlinPerson)).arg(QString::number(personNumber))*/;

    //连接信号与槽
    connect(ui->text_pushButton,SIGNAL(clicked()),this,SLOT(onCollapseButClick()));

}

CollapseViewItem::~CollapseViewItem()
{
    delete ui;
}

void CollapseViewItem::setTitleText(QString titleText)
{
    ui->text_pushButton->setText(titleText);
}

void CollapseViewItem::addSubItems(QList<QWidget *> widgets)
{
    foreach (QWidget *var, widgets)
    {
        addSubItem(var);
    }
}

void CollapseViewItem::addSubItem(QWidget *widget)
{
    ui->item_con->layout()->addWidget(widget);
}

void CollapseViewItem::onCollapseButClick()
{
    //设置为相反的显示状态
    ui->item_con->setVisible(!ui->item_con->isVisible());

    ui->label->setProperty("slected",ui->item_con->isVisible());

    ui->label->update();
}
