/********************************************************************************
** Form generated from reading UI file 'collapseviewitem.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLLAPSEVIEWITEM_H
#define UI_COLLAPSEVIEWITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CollapseViewItem
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *item_main;
    QVBoxLayout *verticalLayout;
    QWidget *item_top;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QPushButton *text_pushButton;
    QWidget *item_con;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QWidget *CollapseViewItem)
    {
        if (CollapseViewItem->objectName().isEmpty())
            CollapseViewItem->setObjectName(QStringLiteral("CollapseViewItem"));
        CollapseViewItem->resize(148, 127);
        CollapseViewItem->setStyleSheet(QLatin1String("#item_top #label[slected=\"false\"]{\n"
"	 \n"
"}\n"
"\n"
"#item_top #label[slected=\"false\"]:hover{\n"
"	\n"
"	 \n"
"}\n"
"\n"
"#item_top #label[slected=\"true\"]{\n"
"	 \n"
"}\n"
"\n"
"#item_top:hover{\n"
"	\n"
"	background-color: rgba(255, 255, 255,80);\n"
"}\n"
"\n"
"#item_top #label{\n"
"	 \n"
"	\n"
"	background-image: url(:/pic/arrow_r.png);\n"
"	background-repeat:no;\n"
"	background-position:center;\n"
"}\n"
"\n"
"\n"
"#item_top QPushButton{\n"
"	 border:none;\n"
"	 text-align:left;\n"
"	 font-size:10pt;\n"
"	 background-repeat:no;\n"
"}\n"
"\n"
""));
        horizontalLayout = new QHBoxLayout(CollapseViewItem);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        item_main = new QWidget(CollapseViewItem);
        item_main->setObjectName(QStringLiteral("item_main"));
        verticalLayout = new QVBoxLayout(item_main);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        item_top = new QWidget(item_main);
        item_top->setObjectName(QStringLiteral("item_top"));
        horizontalLayout_2 = new QHBoxLayout(item_top);
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(6, 5, 0, 5);
        label = new QLabel(item_top);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(20, 20));
        label->setMaximumSize(QSize(20, 20));
        label->setScaledContents(false);

        horizontalLayout_2->addWidget(label);

        text_pushButton = new QPushButton(item_top);
        text_pushButton->setObjectName(QStringLiteral("text_pushButton"));

        horizontalLayout_2->addWidget(text_pushButton);

        horizontalLayout_2->setStretch(1, 1);

        verticalLayout->addWidget(item_top);

        item_con = new QWidget(item_main);
        item_con->setObjectName(QStringLiteral("item_con"));
        verticalLayout_2 = new QVBoxLayout(item_con);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);

        verticalLayout->addWidget(item_con);

        verticalLayout->setStretch(1, 1);

        horizontalLayout->addWidget(item_main);


        retranslateUi(CollapseViewItem);

        QMetaObject::connectSlotsByName(CollapseViewItem);
    } // setupUi

    void retranslateUi(QWidget *CollapseViewItem)
    {
        CollapseViewItem->setWindowTitle(QApplication::translate("CollapseViewItem", "Form", 0));
        label->setText(QString());
        text_pushButton->setText(QApplication::translate("CollapseViewItem", "\346\210\221\347\232\204\345\245\275\345\217\213", 0));
    } // retranslateUi

};

namespace Ui {
    class CollapseViewItem: public Ui_CollapseViewItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLLAPSEVIEWITEM_H
