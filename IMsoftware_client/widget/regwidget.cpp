#include "regwidget.h"
#include "ui_regwidget.h"

RegWidget::RegWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegWidget)
{
    ui->setupUi(this);
//ui
    this->setWindowTitle(tr("IM 即时通讯软件"));
    this->setWindowIcon(QPixmap(":/icon/龙.png"));
}

RegWidget::~RegWidget()
{
    delete ui;
}

void RegWidget::on_confirm_pushButton_clicked()
{
    emit do_reg_check();
}

void RegWidget::on_exit_pushButton_clicked()
{
    emit do_reg_cancel();
    this->close();
}
