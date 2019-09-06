#include "litteriem.h"
#include "ui_litteriem.h"

#include <QPixmap>

LitterIem::LitterIem(QString picPath, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LitterIem)
{
    ui->setupUi(this);

    QPixmap pix(picPath);
    ui->label_pic->setPixmap(pix);

}

LitterIem::~LitterIem()
{
    delete ui;
}
