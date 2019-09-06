/********************************************************************************
** Form generated from reading UI file 'logwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGWIDGET_H
#define UI_LOGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *img_label;
    QGridLayout *gridLayout_2;
    QPushButton *fpwd_pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *reg_pushButton;
    QLabel *pwd_label;
    QLabel *name_label;
    QCheckBox *auto_login_checkBox;
    QCheckBox *remem_pwd_checkBox;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *name_lineEdit;
    QLineEdit *pwd_lineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *login_Button;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *Exit_pushButton;

    void setupUi(QWidget *LogWidget)
    {
        if (LogWidget->objectName().isEmpty())
            LogWidget->setObjectName(QStringLiteral("LogWidget"));
        LogWidget->resize(445, 391);
        LogWidget->setStyleSheet(QString::fromUtf8("/*\345\244\215\351\200\211\346\241\206\346\226\271\346\241\206\351\203\250\345\210\206\345\237\272\346\234\254\346\240\267\345\274\217*/\n"
"QCheckBox:indicator {\n"
"	border:1px solid #B2B2B2;\n"
"}\n"
"\n"
"/*\345\244\215\351\200\211\346\241\206\346\226\271\346\241\206\351\203\250\345\210\206\351\200\211\344\270\255\346\240\267\345\274\217*/\n"
"QCheckBox:indicator:checked {\n"
"	border:1px solid #278CDE;\n"
"	background-image: url(:/pic/img/check.png);\n"
"}\n"
"\n"
"/*\345\244\215\351\200\211\346\241\206\346\226\271\346\241\206\351\203\250\345\210\206\346\202\254\345\201\234*/\n"
"QCheckBox:indicator:hover {\n"
"	 border:1px solid #278CDE;\n"
"}"));
        verticalLayout = new QVBoxLayout(LogWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        img_label = new QLabel(LogWidget);
        img_label->setObjectName(QStringLiteral("img_label"));
        img_label->setMinimumSize(QSize(0, 150));
        img_label->setMaximumSize(QSize(16777215, 150));
        img_label->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/img/top2.png);\n"
"font: 75 24pt \"\346\226\271\346\255\243\345\247\232\344\275\223\";"));
        img_label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(img_label);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        fpwd_pushButton = new QPushButton(LogWidget);
        fpwd_pushButton->setObjectName(QStringLiteral("fpwd_pushButton"));
        fpwd_pushButton->setMinimumSize(QSize(70, 0));
        fpwd_pushButton->setMaximumSize(QSize(16777215, 20));
        fpwd_pushButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	font: 11pt \"Agency FB\";\n"
"	border: solid 1px #b7b7b7;\n"
"	\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	border: solid 1px #b7b7b7;\n"
"	color: #09A3DC;\n"
"}\n"
"\n"
""));

        gridLayout_2->addWidget(fpwd_pushButton, 2, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(60, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);

        reg_pushButton = new QPushButton(LogWidget);
        reg_pushButton->setObjectName(QStringLiteral("reg_pushButton"));
        reg_pushButton->setMinimumSize(QSize(70, 0));
        reg_pushButton->setMaximumSize(QSize(16777215, 20));
        reg_pushButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	font: 11pt \"Agency FB\";\n"
"	border: solid 1px #b7b7b7;\n"
"	\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	border: solid 1px #b7b7b7;\n"
"	color: #09A3DC;\n"
"}\n"
"\n"
""));

        gridLayout_2->addWidget(reg_pushButton, 0, 3, 1, 1);

        pwd_label = new QLabel(LogWidget);
        pwd_label->setObjectName(QStringLiteral("pwd_label"));
        pwd_label->setMinimumSize(QSize(105, 0));
        pwd_label->setMaximumSize(QSize(70, 16777215));
        pwd_label->setStyleSheet(QStringLiteral("font: 11pt \"Agency FB\";"));
        pwd_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(pwd_label, 2, 1, 1, 1);

        name_label = new QLabel(LogWidget);
        name_label->setObjectName(QStringLiteral("name_label"));
        name_label->setMinimumSize(QSize(105, 0));
        name_label->setMaximumSize(QSize(80, 16777215));
        name_label->setStyleSheet(QStringLiteral("font: 11pt \"Agency FB\";"));
        name_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(name_label, 0, 1, 1, 1);

        auto_login_checkBox = new QCheckBox(LogWidget);
        auto_login_checkBox->setObjectName(QStringLiteral("auto_login_checkBox"));
        auto_login_checkBox->setStyleSheet(QStringLiteral("font: 11pt \"Agency FB\";"));

        gridLayout_2->addWidget(auto_login_checkBox, 4, 1, 1, 1);

        remem_pwd_checkBox = new QCheckBox(LogWidget);
        remem_pwd_checkBox->setObjectName(QStringLiteral("remem_pwd_checkBox"));
        remem_pwd_checkBox->setStyleSheet(QStringLiteral("font: 11pt \"Agency FB\";"));

        gridLayout_2->addWidget(remem_pwd_checkBox, 4, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(60, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 4, 1, 1);

        name_lineEdit = new QLineEdit(LogWidget);
        name_lineEdit->setObjectName(QStringLiteral("name_lineEdit"));
        name_lineEdit->setMinimumSize(QSize(150, 0));
        name_lineEdit->setMaximumSize(QSize(16777215, 16777215));
        name_lineEdit->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\256\213\344\275\223\";"));

        gridLayout_2->addWidget(name_lineEdit, 0, 2, 1, 1);

        pwd_lineEdit = new QLineEdit(LogWidget);
        pwd_lineEdit->setObjectName(QStringLiteral("pwd_lineEdit"));
        pwd_lineEdit->setMinimumSize(QSize(150, 0));
        pwd_lineEdit->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\256\213\344\275\223\";"));

        gridLayout_2->addWidget(pwd_lineEdit, 2, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(50, -1, 50, -1);
        login_Button = new QPushButton(LogWidget);
        login_Button->setObjectName(QStringLiteral("login_Button"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(login_Button->sizePolicy().hasHeightForWidth());
        login_Button->setSizePolicy(sizePolicy);
        login_Button->setMinimumSize(QSize(80, 20));
        login_Button->setMaximumSize(QSize(16777215, 20));
        login_Button->setStyleSheet(QString::fromUtf8("/*\347\231\273\345\275\225\346\214\211\351\222\256\346\240\267\345\274\217*/\n"
"QPushButton{\n"
"	border-radius:4px;\n"
"	border:none;\n"
"	background-color: #09A3DC;\n"
"	color:#fff;\n"
"}\n"
"\n"
"/*\347\231\273\345\275\225\346\214\211\351\222\256\351\274\240\346\240\207\346\202\254\345\201\234\346\240\267\345\274\217*/\n"
"QPushButton:hover{\n"
"	background-color:rgb(60,195,245);\n"
"}"));

        horizontalLayout->addWidget(login_Button);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        Exit_pushButton = new QPushButton(LogWidget);
        Exit_pushButton->setObjectName(QStringLiteral("Exit_pushButton"));
        Exit_pushButton->setMinimumSize(QSize(80, 20));
        Exit_pushButton->setMaximumSize(QSize(16777215, 20));
        Exit_pushButton->setStyleSheet(QString::fromUtf8("/*\347\231\273\345\275\225\346\214\211\351\222\256\346\240\267\345\274\217*/\n"
"QPushButton{\n"
"	border-radius:4px;\n"
"	border:none;\n"
"	background-color: #09A3DC;\n"
"	color:#fff;\n"
"}\n"
"\n"
"/*\347\231\273\345\275\225\346\214\211\351\222\256\351\274\240\346\240\207\346\202\254\345\201\234\346\240\267\345\274\217*/\n"
"QPushButton:hover{\n"
"	background-color:rgb(60,195,245);\n"
"}"));

        horizontalLayout->addWidget(Exit_pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(LogWidget);

        QMetaObject::connectSlotsByName(LogWidget);
    } // setupUi

    void retranslateUi(QWidget *LogWidget)
    {
        LogWidget->setWindowTitle(QApplication::translate("LogWidget", "Form", 0));
        img_label->setText(QString());
        fpwd_pushButton->setText(QApplication::translate("LogWidget", "\346\211\276\345\233\236\345\257\206\347\240\201", 0));
        reg_pushButton->setText(QApplication::translate("LogWidget", "\346\263\250\345\206\214\350\264\246\345\217\267", 0));
        pwd_label->setText(QApplication::translate("LogWidget", "\345\257\206           \347\240\201\357\274\232", 0));
        name_label->setText(QApplication::translate("LogWidget", "\347\224\250   \346\210\267   \345\220\215\357\274\232", 0));
        auto_login_checkBox->setText(QApplication::translate("LogWidget", "\350\207\252\345\212\250\347\231\273\345\275\225", 0));
        remem_pwd_checkBox->setText(QApplication::translate("LogWidget", "\350\256\260\344\275\217\345\257\206\347\240\201", 0));
        login_Button->setText(QApplication::translate("LogWidget", "\347\231\273\345\275\225", 0));
        Exit_pushButton->setText(QApplication::translate("LogWidget", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class LogWidget: public Ui_LogWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGWIDGET_H
