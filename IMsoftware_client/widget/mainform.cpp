#include "mainform.h"
#include "ui_mainform.h"

MainForm::MainForm(QWidget *parent) :
    MoveableFramelessWindow(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
//ui
    this->setWindowTitle(tr("IM 即时通讯软件"));
    this->setWindowIcon(QPixmap(":/icon/龙.png"));

//加入联系人列表
    ui->page_4->layout()->addWidget(new CollapseView());

}

MainForm::~MainForm()
{
    delete ui;
}

void MainForm::onThemeColorChange(QString colorStr)
{
    //组合成qcc样式表
    QString style=QString("#%1{background-color:%2;}").arg(ui->centralwidget->objectName(),colorStr);
    //定义样式
    ui->centralwidget->setStyleSheet(style);

}
QWidget* MainForm::getDragnWidget()
{
    return ui->main_top;
}



void MainForm::on_skin_Button_clicked()
{
    MY_COLOR_PICK_FORM.show();
    MY_COLOR_PICK_FORM.raise();
    MY_COLOR_PICK_FORM.setFocus();

    ColorPickForm* color = &(MY_COLOR_PICK_FORM);

    connect(color,SIGNAL(themColorChanged(QString)),this,SLOT(onThemeColorChange(QString)));

}

void MainForm::on_close_Button_clicked()
{
    this->close();
    emit do_close_mainform();
}
