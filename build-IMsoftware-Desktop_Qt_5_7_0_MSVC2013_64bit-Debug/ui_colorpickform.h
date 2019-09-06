/********************************************************************************
** Form generated from reading UI file 'colorpickform.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORPICKFORM_H
#define UI_COLORPICKFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ColorPickForm
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *color_main_widget;
    QVBoxLayout *verticalLayout_5;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *color_main_top;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QWidget *color_main_con;
    QVBoxLayout *verticalLayout;
    QWidget *widget_tool;
    QWidget *widget_colors;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QWidget *color_items;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *color_panle_pushButton;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_operate;

    void setupUi(QWidget *ColorPickForm)
    {
        if (ColorPickForm->objectName().isEmpty())
            ColorPickForm->setObjectName(QStringLiteral("ColorPickForm"));
        ColorPickForm->resize(774, 566);
        QIcon icon;
        icon.addFile(QStringLiteral(":/sys/qlogo.png"), QSize(), QIcon::Normal, QIcon::Off);
        ColorPickForm->setWindowIcon(icon);
        ColorPickForm->setStyleSheet(QString::fromUtf8("*{\n"
"	font: 75 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"#color_main_widget\n"
"{\n"
"	border-image: url(:/pic/back.png) 5;\n"
"	border-radius:2px;\n"
"}\n"
"\n"
"#centralwidget{\n"
"	border-radius:2px;\n"
"	background-color: rgb(22, 154, 218);\n"
"}\n"
"\n"
"/*\346\240\207\351\242\230\346\240\217*/\n"
"#color_main_top{\n"
"	\n"
"	border-top-left-radius:2px;\n"
"	border-top-right-radius:2px;\n"
"}\n"
"\n"
"#color_main_top *\n"
"{\n"
"	color:#fff;\n"
"	font-size:10pt;\n"
"}\n"
"\n"
"/*\351\241\266\351\203\250\346\214\211\351\222\256\345\256\232\344\271\211*/\n"
"#color_main_top QPushButton{\n"
"	border:none;\n"
"	width:24px;\n"
"	height:20px;\n"
"	border-radius:2px;\n"
"}\n"
"#color_main_top QPushButton:hover{\n"
"   border:1px solid rgb(13, 97, 137);\n"
"	background-color:rgb(212, 64, 39);\n"
"   \n"
"}\n"
"\n"
"#color_main_con{\n"
"	\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-bottom-left-radius:2px;\n"
"	border-bottom-right-radius:2px;\n"
"}\n"
"\n"
"#color_main_co"
                        "n #widget_tool{\n"
"	background-color: rgb(237, 238, 238);\n"
"	border-bottom:1px solid rgb(220,220,220);\n"
"}\n"
"\n"
"#color_main_con #color_items QPushButton,#color_panle_pushButton\n"
"{\n"
"	background-color: rgb(22, 154, 218);\n"
"	border:none;\n"
"}\n"
"\n"
"#color_main_con #color_items QPushButton:hover,\n"
"#color_panle_pushButton:hover\n"
"{\n"
"	border:3px solid rgb(39,140,222);\n"
"}\n"
"\n"
"#color_panle_pushButton\n"
"{\n"
"	background-image: url(:/pic/color_panle.png);\n"
"	\n"
"}\n"
""));
        verticalLayout_3 = new QVBoxLayout(ColorPickForm);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        color_main_widget = new QWidget(ColorPickForm);
        color_main_widget->setObjectName(QStringLiteral("color_main_widget"));
        color_main_widget->setMinimumSize(QSize(752, 544));
        color_main_widget->setStyleSheet(QStringLiteral(""));
        verticalLayout_5 = new QVBoxLayout(color_main_widget);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(3, 3, 3, 3);
        centralwidget = new QWidget(color_main_widget);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("/*\351\241\266\351\203\250\346\214\211\351\222\256\345\256\232\344\271\211*/\n"
"#color_main_top QPushButton{\n"
"	border:none;\n"
"	width:24px;\n"
"	height:20px;\n"
"	border-radius:2px;\n"
"}\n"
"\n"
"#color_main_top QPushButton:hover{\n"
"   border:1px solid rgb(13, 97, 137);\n"
"   \n"
"}"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        color_main_top = new QWidget(centralwidget);
        color_main_top->setObjectName(QStringLiteral("color_main_top"));
        color_main_top->setMinimumSize(QSize(0, 30));
        color_main_top->setMaximumSize(QSize(16777215, 30));
        color_main_top->setStyleSheet(QStringLiteral(""));
        horizontalLayout_3 = new QHBoxLayout(color_main_top);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(6, 6, 6, 6);
        label_2 = new QLabel(color_main_top);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(20, 20));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/sys/qlogo.png")));
        label_2->setScaledContents(true);

        horizontalLayout_3->addWidget(label_2);

        label = new QLabel(color_main_top);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(color_main_top);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/pic/close1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout_2->addWidget(color_main_top);

        color_main_con = new QWidget(centralwidget);
        color_main_con->setObjectName(QStringLiteral("color_main_con"));
        verticalLayout = new QVBoxLayout(color_main_con);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_tool = new QWidget(color_main_con);
        widget_tool->setObjectName(QStringLiteral("widget_tool"));
        widget_tool->setMinimumSize(QSize(0, 40));
        widget_tool->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(widget_tool);

        widget_colors = new QWidget(color_main_con);
        widget_colors->setObjectName(QStringLiteral("widget_colors"));
        verticalLayout_4 = new QVBoxLayout(widget_colors);
        verticalLayout_4->setSpacing(1);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(6, 6, 6, 6);
        widget = new QWidget(widget_colors);
        widget->setObjectName(QStringLiteral("widget"));

        verticalLayout_4->addWidget(widget);

        widget_2 = new QWidget(widget_colors);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        color_items = new QWidget(widget_2);
        color_items->setObjectName(QStringLiteral("color_items"));
        color_items->setMinimumSize(QSize(100, 40));
        horizontalLayout_2 = new QHBoxLayout(color_items);
        horizontalLayout_2->setSpacing(1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);

        horizontalLayout->addWidget(color_items);

        color_panle_pushButton = new QPushButton(widget_2);
        color_panle_pushButton->setObjectName(QStringLiteral("color_panle_pushButton"));
        color_panle_pushButton->setMinimumSize(QSize(40, 40));
        color_panle_pushButton->setMaximumSize(QSize(40, 40));

        horizontalLayout->addWidget(color_panle_pushButton);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalLayout->setStretch(2, 1);

        verticalLayout_4->addWidget(widget_2);

        verticalLayout_4->setStretch(0, 1);

        verticalLayout->addWidget(widget_colors);

        widget_operate = new QWidget(color_main_con);
        widget_operate->setObjectName(QStringLiteral("widget_operate"));
        widget_operate->setMinimumSize(QSize(0, 40));
        widget_operate->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(widget_operate);


        verticalLayout_2->addWidget(color_main_con);


        verticalLayout_5->addWidget(centralwidget);


        verticalLayout_3->addWidget(color_main_widget);


        retranslateUi(ColorPickForm);

        QMetaObject::connectSlotsByName(ColorPickForm);
    } // setupUi

    void retranslateUi(QWidget *ColorPickForm)
    {
        ColorPickForm->setWindowTitle(QApplication::translate("ColorPickForm", "\351\200\211\346\213\251\347\232\256\350\202\244", 0));
        label_2->setText(QString());
        label->setText(QApplication::translate("ColorPickForm", "\346\233\264\346\224\271\345\244\226\350\247\202", 0));
        pushButton->setText(QString());
        color_panle_pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ColorPickForm: public Ui_ColorPickForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORPICKFORM_H
