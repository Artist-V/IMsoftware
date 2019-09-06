/********************************************************************************
** Form generated from reading UI file 'mainform.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainForm
{
public:
    QGridLayout *gridLayout;
    QWidget *main_widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *main_top;
    QVBoxLayout *verticalLayout_11;
    QWidget *top_title;
    QHBoxLayout *horizontalLayout;
    QLabel *label_logo;
    QLabel *label_logo_name;
    QSpacerItem *horizontalSpacer;
    QPushButton *close_Button;
    QSpacerItem *verticalSpacer;
    QWidget *top_names;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *name_label;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *sign_lineEdit;
    QWidget *wether_widget;
    QVBoxLayout *verticalLayout_5;
    QLabel *weather_label;
    QWidget *top_tools;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *zone_Button;
    QPushButton *mail_Button;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *skin_Button;
    QPushButton *talk_Button;
    QLineEdit *search;
    QWidget *main_center;
    QVBoxLayout *verticalLayout_7;
    QWidget *center_nav;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_p;
    QPushButton *pushButton_q;
    QPushButton *pushButton_t;
    QStackedWidget *center_stack;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_8;
    QWidget *page_5;
    QVBoxLayout *verticalLayout_9;
    QWidget *page_6;
    QVBoxLayout *verticalLayout_10;
    QWidget *main_bottom;

    void setupUi(QWidget *MainForm)
    {
        if (MainForm->objectName().isEmpty())
            MainForm->setObjectName(QStringLiteral("MainForm"));
        MainForm->resize(308, 686);
        gridLayout = new QGridLayout(MainForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        main_widget = new QWidget(MainForm);
        main_widget->setObjectName(QStringLiteral("main_widget"));
        main_widget->setStyleSheet(QString::fromUtf8("*{\n"
"	font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"#main_widget{\n"
"	border-radius:2px;\n"
"	border-image: url(:/sys/back.png) 5;\n"
"}\n"
"\n"
"#centralwidget{\n"
"	border-radius:2px;\n"
"}\n"
"\n"
"/*\344\270\212\351\203\250\347\224\250\346\210\267\344\277\241\346\201\257\345\214\272\345\237\237*/\n"
"#main_top{\n"
"	\n"
"}\n"
"\n"
"#label_logo_name{\n"
"	color:#fff;\n"
"	font-size:9pt;\n"
"}\n"
"\n"
"/*\346\230\265\347\247\260\357\274\214\347\255\211\347\272\247\357\274\214\347\255\276\345\220\215\347\255\211\344\275\215\347\275\256\345\256\232\344\271\211*/\n"
"#top_names *{\n"
"	color:#fff;\n"
"}\n"
"\n"
"#top_names #label_nick{\n"
"	font-size:12pt;\n"
"}\n"
"\n"
"#top_names #label_status{\n"
"	 \n"
"}\n"
"\n"
"#top_names QLineEdit{\n"
"	color:#fff;\n"
"	font-size:10pt;\n"
"	background-color: rgba(255, 255, 255,0);\n"
"	border:none;\n"
"	border-radius:2px;\n"
"	 \n"
"}\n"
"\n"
"#top_names QLineEdit:focus{\n"
"	background-color: rgb(255, 255, 255); \n"
"	color:#000;\n"
""
                        "	border:1px solid rgb(213, 213, 213);\n"
"}\n"
"\n"
"#top_names QLineEdit:hover{\n"
"	 border:1px solid rgba(0,0,0,100);\n"
"}\n"
"\n"
"\n"
"/*\351\241\266\351\203\250\346\214\211\351\222\256\345\256\232\344\271\211*/\n"
"#top_title QPushButton{\n"
"	border:none;\n"
"	width:24px;\n"
"	height:20px;\n"
"	border-radius:2px;\n"
"}\n"
"\n"
"#top_title QPushButton:hover{\n"
"   border:1px solid rgb(13, 97, 137);\n"
"   \n"
"}\n"
"/*\345\267\245\345\205\267\346\240\217\345\233\276\346\240\207\345\256\232\344\271\211*/\n"
"#top_tools QPushButton{\n"
"	border:none;\n"
"	width:24px;\n"
"	height:20px;\n"
"	border-radius:2px;\n"
"}\n"
"\n"
"#top_tools QPushButton:hover{\n"
"   border:1px solid rgb(13, 97, 137);\n"
"   \n"
"}\n"
"\n"
"/*\346\220\234\347\264\242\346\241\206*/\n"
"QLineEdit#search{\n"
"	padding:6px;\n"
"	border:none;\n"
"	background-color: rgba(0,0,0,60);\n"
"	color: rgb(229, 229, 229);\n"
"	background-image: url(:/sys/search.png);\n"
"	background-repeat:no;\n"
"	background-position:right center;\n"
"	backgr"
                        "ound-origin: content;\n"
"	\n"
"}\n"
"\n"
"#search:focus{\n"
"	background-color: #fff;\n"
"	color: #000;\n"
"	border-bottom:1px solid #ccc;\n"
"}\n"
"\n"
"#center_stack QWidget{\n"
"	/*background-color: #E8F5FC;*/\n"
"	background-color: rgba(255, 255, 255,230);\n"
"}\n"
"\n"
"#center_stack QWidget>QWidget{\n"
"	/*background-color: #E8F5FC;*/\n"
"	background-color: rgba(255, 255, 255,0);\n"
"}\n"
"\n"
"\n"
"#center_nav{\n"
"	min-height:38px;\n"
"	border-bottom:1px solid rgb(211, 225, 226);\n"
"	background-color: rgba(255, 255, 255,230);\n"
"}\n"
"\n"
"#center_nav QPushButton{\n"
"	border:none;\n"
"	background-repeat:none;\n"
"	background-position:center;\n"
"	height:38px;\n"
"\n"
"}\n"
"\n"
"/*\350\201\224\347\263\273\344\272\272\345\210\227\350\241\250\345\233\276\346\240\207\345\256\232\344\271\211---------\345\274\200\345\247\213*/\n"
"#center_nav QPushButton#pushButton_p{\n"
"	background-image: url(:/pic/qqicon_p_gray.png);\n"
"}\n"
"\n"
"#center_nav QPushButton#pushButton_p:hover{\n"
"	background-image: ur"
                        "l(:/pic/qqicon_p_blue.png);\n"
"}\n"
"\n"
"\n"
"#center_nav QPushButton#pushButton_q{\n"
"	background-image: url(:/pic/qqicon_q_gray.png);\n"
"}\n"
"\n"
"#center_nav QPushButton#pushButton_q:hover{\n"
"	background-image: url(:/pic/qqicon_q_blue.png);\n"
"}\n"
"\n"
"\n"
"\n"
"#center_nav QPushButton#pushButton_t{\n"
"	background-image: url(:/pic/qqicon_t_gray.png);\n"
"}\n"
"\n"
"#center_nav QPushButton#pushButton_t:hover{\n"
"	background-image: url(:/pic/qqicon_t_blue.png);\n"
"}\n"
"\n"
"/*\350\201\224\347\263\273\344\272\272\345\210\227\350\241\250\345\233\276\346\240\207\345\256\232\344\271\211-----------\347\273\223\346\235\237*/\n"
"\n"
"\n"
"\n"
"#main_bottom{\n"
"	border-bottom-left-radius:2px;\n"
"	border-bottom-right-radius:2px;\n"
"	border-top:1px solid rgba(0,0,0,40);\n"
"	background-color: rgba(255,255,255,190);\n"
"}\n"
""));
        verticalLayout_2 = new QVBoxLayout(main_widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(3, 3, 3, 3);
        centralwidget = new QWidget(main_widget);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setMinimumSize(QSize(280, 0));
        centralwidget->setStyleSheet(QLatin1String("#centralwidget{\n"
"	background-color: rgb(22, 154, 218);\n"
"}"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        main_top = new QWidget(centralwidget);
        main_top->setObjectName(QStringLiteral("main_top"));
        main_top->setMinimumSize(QSize(0, 170));
        main_top->setMaximumSize(QSize(16777215, 170));
        verticalLayout_11 = new QVBoxLayout(main_top);
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        top_title = new QWidget(main_top);
        top_title->setObjectName(QStringLiteral("top_title"));
        horizontalLayout = new QHBoxLayout(top_title);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_logo = new QLabel(top_title);
        label_logo->setObjectName(QStringLiteral("label_logo"));
        label_logo->setMaximumSize(QSize(16, 16));
        label_logo->setPixmap(QPixmap(QString::fromUtf8(":/icon/\351\276\231.png")));
        label_logo->setScaledContents(true);

        horizontalLayout->addWidget(label_logo);

        label_logo_name = new QLabel(top_title);
        label_logo_name->setObjectName(QStringLiteral("label_logo_name"));

        horizontalLayout->addWidget(label_logo_name);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        close_Button = new QPushButton(top_title);
        close_Button->setObjectName(QStringLiteral("close_Button"));
        close_Button->setMinimumSize(QSize(20, 24));
        close_Button->setMaximumSize(QSize(20, 24));
        QIcon icon;
        icon.addFile(QStringLiteral(":/pic/close1.png"), QSize(), QIcon::Normal, QIcon::Off);
        close_Button->setIcon(icon);

        horizontalLayout->addWidget(close_Button);


        verticalLayout_11->addWidget(top_title);

        verticalSpacer = new QSpacerItem(20, 136, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer);

        top_names = new QWidget(main_top);
        top_names->setObjectName(QStringLiteral("top_names"));
        top_names->setMinimumSize(QSize(0, 0));
        horizontalLayout_4 = new QHBoxLayout(top_names);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(9, 0, 0, 0);
        widget_2 = new QWidget(top_names);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_4 = new QVBoxLayout(widget_2);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        name_label = new QLabel(widget_2);
        name_label->setObjectName(QStringLiteral("name_label"));

        horizontalLayout_5->addWidget(name_label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_4->addLayout(horizontalLayout_5);

        sign_lineEdit = new QLineEdit(widget_2);
        sign_lineEdit->setObjectName(QStringLiteral("sign_lineEdit"));
        sign_lineEdit->setFocusPolicy(Qt::ClickFocus);

        verticalLayout_4->addWidget(sign_lineEdit);


        horizontalLayout_4->addWidget(widget_2);

        wether_widget = new QWidget(top_names);
        wether_widget->setObjectName(QStringLiteral("wether_widget"));
        wether_widget->setMinimumSize(QSize(55, 55));
        verticalLayout_5 = new QVBoxLayout(wether_widget);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        weather_label = new QLabel(wether_widget);
        weather_label->setObjectName(QStringLiteral("weather_label"));
        weather_label->setPixmap(QPixmap(QString::fromUtf8(":/pic/wether/3.png")));
        weather_label->setScaledContents(true);

        verticalLayout_5->addWidget(weather_label);


        horizontalLayout_4->addWidget(wether_widget);

        horizontalLayout_4->setStretch(0, 1);

        verticalLayout_11->addWidget(top_names);

        top_tools = new QWidget(main_top);
        top_tools->setObjectName(QStringLiteral("top_tools"));
        horizontalLayout_3 = new QHBoxLayout(top_tools);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(9, 4, -1, 4);
        zone_Button = new QPushButton(top_tools);
        zone_Button->setObjectName(QStringLiteral("zone_Button"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/pic/qq_tool_zone.png"), QSize(), QIcon::Normal, QIcon::Off);
        zone_Button->setIcon(icon1);

        horizontalLayout_3->addWidget(zone_Button);

        mail_Button = new QPushButton(top_tools);
        mail_Button->setObjectName(QStringLiteral("mail_Button"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/pic/qq_tool_mail.png"), QSize(), QIcon::Normal, QIcon::Off);
        mail_Button->setIcon(icon2);

        horizontalLayout_3->addWidget(mail_Button);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        skin_Button = new QPushButton(top_tools);
        skin_Button->setObjectName(QStringLiteral("skin_Button"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/pic/qq_tool_skin.png"), QSize(), QIcon::Normal, QIcon::Off);
        skin_Button->setIcon(icon3);
        skin_Button->setAutoDefault(false);
        skin_Button->setFlat(false);

        horizontalLayout_3->addWidget(skin_Button);

        talk_Button = new QPushButton(top_tools);
        talk_Button->setObjectName(QStringLiteral("talk_Button"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/pic/qq_tool_talk.png"), QSize(), QIcon::Normal, QIcon::Off);
        talk_Button->setIcon(icon4);

        horizontalLayout_3->addWidget(talk_Button);


        verticalLayout_11->addWidget(top_tools);

        search = new QLineEdit(main_top);
        search->setObjectName(QStringLiteral("search"));
        search->setFocusPolicy(Qt::ClickFocus);

        verticalLayout_11->addWidget(search);


        verticalLayout->addWidget(main_top);

        main_center = new QWidget(centralwidget);
        main_center->setObjectName(QStringLiteral("main_center"));
        verticalLayout_7 = new QVBoxLayout(main_center);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        center_nav = new QWidget(main_center);
        center_nav->setObjectName(QStringLiteral("center_nav"));
        horizontalLayout_2 = new QHBoxLayout(center_nav);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_p = new QPushButton(center_nav);
        pushButton_p->setObjectName(QStringLiteral("pushButton_p"));

        horizontalLayout_2->addWidget(pushButton_p);

        pushButton_q = new QPushButton(center_nav);
        pushButton_q->setObjectName(QStringLiteral("pushButton_q"));

        horizontalLayout_2->addWidget(pushButton_q);

        pushButton_t = new QPushButton(center_nav);
        pushButton_t->setObjectName(QStringLiteral("pushButton_t"));

        horizontalLayout_2->addWidget(pushButton_t);


        verticalLayout_7->addWidget(center_nav);

        center_stack = new QStackedWidget(main_center);
        center_stack->setObjectName(QStringLiteral("center_stack"));
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        verticalLayout_8 = new QVBoxLayout(page_4);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        center_stack->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        verticalLayout_9 = new QVBoxLayout(page_5);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        center_stack->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        verticalLayout_10 = new QVBoxLayout(page_6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        center_stack->addWidget(page_6);

        verticalLayout_7->addWidget(center_stack);


        verticalLayout->addWidget(main_center);

        main_bottom = new QWidget(centralwidget);
        main_bottom->setObjectName(QStringLiteral("main_bottom"));
        main_bottom->setMinimumSize(QSize(0, 30));
        main_bottom->setMaximumSize(QSize(16777215, 60));

        verticalLayout->addWidget(main_bottom);


        verticalLayout_2->addWidget(centralwidget);


        gridLayout->addWidget(main_widget, 0, 0, 1, 1);


        retranslateUi(MainForm);

        skin_Button->setDefault(false);
        center_stack->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainForm);
    } // setupUi

    void retranslateUi(QWidget *MainForm)
    {
        MainForm->setWindowTitle(QApplication::translate("MainForm", "Form", 0));
        label_logo->setText(QString());
        label_logo_name->setText(QApplication::translate("MainForm", "IM", 0));
        close_Button->setText(QString());
        name_label->setText(QApplication::translate("MainForm", "\344\270\211\344\270\203", 0));
        sign_lineEdit->setText(QApplication::translate("MainForm", "\347\274\226\350\276\221\344\270\252\346\200\247\347\255\276\345\220\215", 0));
        weather_label->setText(QString());
        zone_Button->setText(QString());
        mail_Button->setText(QString());
        skin_Button->setText(QString());
        talk_Button->setText(QString());
        search->setText(QApplication::translate("MainForm", "\346\220\234\347\264\242", 0));
        pushButton_p->setText(QString());
        pushButton_q->setText(QString());
        pushButton_t->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainForm: public Ui_MainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
