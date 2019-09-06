/********************************************************************************
** Form generated from reading UI file 'litteriem.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LITTERIEM_H
#define UI_LITTERIEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LitterIem
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *litter_main;
    QHBoxLayout *horizontalLayout;
    QLabel *label_pic;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_name;
    QLabel *label_signal;

    void setupUi(QWidget *LitterIem)
    {
        if (LitterIem->objectName().isEmpty())
            LitterIem->setObjectName(QStringLiteral("LitterIem"));
        LitterIem->resize(225, 54);
        LitterIem->setMinimumSize(QSize(0, 54));
        LitterIem->setMaximumSize(QSize(16777215, 54));
        LitterIem->setStyleSheet(QLatin1String("#litter_main:hover{\n"
"	background-color: rgb(252, 235, 172);\n"
"}\n"
"\n"
"#label_pic{\n"
"	border-radius:4px;\n"
"}\n"
"\n"
"#label_name{\n"
"	font-size:10pt;	\n"
"}\n"
"\n"
"#label_signal{\n"
"	color:rgb(170, 170, 170)\n"
"}\n"
"\n"
""));
        horizontalLayout_2 = new QHBoxLayout(LitterIem);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        litter_main = new QWidget(LitterIem);
        litter_main->setObjectName(QStringLiteral("litter_main"));
        horizontalLayout = new QHBoxLayout(litter_main);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(12, 6, -1, 6);
        label_pic = new QLabel(litter_main);
        label_pic->setObjectName(QStringLiteral("label_pic"));
        label_pic->setMinimumSize(QSize(42, 42));
        label_pic->setMaximumSize(QSize(42, 42));
        label_pic->setPixmap(QPixmap(QString::fromUtf8(":/icon/photo/p1.png")));
        label_pic->setScaledContents(true);

        horizontalLayout->addWidget(label_pic);

        widget = new QWidget(litter_main);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 0, 6);
        label_name = new QLabel(widget);
        label_name->setObjectName(QStringLiteral("label_name"));

        verticalLayout->addWidget(label_name);

        label_signal = new QLabel(widget);
        label_signal->setObjectName(QStringLiteral("label_signal"));

        verticalLayout->addWidget(label_signal);


        horizontalLayout->addWidget(widget);


        horizontalLayout_2->addWidget(litter_main);


        retranslateUi(LitterIem);

        QMetaObject::connectSlotsByName(LitterIem);
    } // setupUi

    void retranslateUi(QWidget *LitterIem)
    {
        LitterIem->setWindowTitle(QApplication::translate("LitterIem", "Form", 0));
        label_pic->setText(QString());
        label_name->setText(QApplication::translate("LitterIem", "\344\270\211\344\270\203", 0));
        label_signal->setText(QApplication::translate("LitterIem", "\347\274\226\350\276\221\344\270\252\346\200\247\347\255\276\345\220\215", 0));
    } // retranslateUi

};

namespace Ui {
    class LitterIem: public Ui_LitterIem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LITTERIEM_H
