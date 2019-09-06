#ifndef LITTERIEM_H
#define LITTERIEM_H
#pragma execution_character_set("utf-8")

#include <QWidget>

namespace Ui {
class LitterIem;
}

class LitterIem : public QWidget
{
    Q_OBJECT

public:
    explicit LitterIem(QString picPath/*头像的文件路径*/,QWidget *parent = 0);
    ~LitterIem();

private:
    Ui::LitterIem *ui;
};

#endif // LITTERIEM_H
