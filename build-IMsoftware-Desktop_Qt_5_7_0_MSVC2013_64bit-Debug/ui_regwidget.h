/********************************************************************************
** Form generated from reading UI file 'regwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGWIDGET_H
#define UI_REGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *img_label;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QComboBox *comboBox;
    QLineEdit *cpwd_lineEdit;
    QLabel *que_label;
    QSpacerItem *horizontalSpacer;
    QLabel *name_label;
    QLineEdit *pwd_lineEdit;
    QLabel *label;
    QLineEdit *name_lineEdit;
    QLineEdit *ans_lineEdit;
    QLabel *cpwd_label;
    QLabel *pwd_label;
    QPushButton *eye_Button;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *confirm_pushButton;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *exit_pushButton;
    QSpacerItem *horizontalSpacer_8;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *RegWidget)
    {
        if (RegWidget->objectName().isEmpty())
            RegWidget->setObjectName(QStringLiteral("RegWidget"));
        RegWidget->resize(451, 624);
        RegWidget->setStyleSheet(QString::fromUtf8("/*\345\244\215\351\200\211\346\241\206\346\226\271\346\241\206\351\203\250\345\210\206\345\237\272\346\234\254\346\240\267\345\274\217*/\n"
"QRadioButton:indicator {\n"
"	border:1px solid #B2B2B2;\n"
"}\n"
"\n"
"/*\345\244\215\351\200\211\346\241\206\346\226\271\346\241\206\351\203\250\345\210\206\351\200\211\344\270\255\346\240\267\345\274\217*/\n"
"QRadioButton:indicator:checked {\n"
"	border:1px solid #278CDE;\n"
"	background-image: url(:/pic/img/check.png);\n"
"}\n"
"\n"
"/*\345\244\215\351\200\211\346\241\206\346\226\271\346\241\206\351\203\250\345\210\206\346\202\254\345\201\234*/\n"
"QRadioButton:indicator:hover {\n"
"	 border:1px solid #278CDE;\n"
"}"));
        verticalLayout = new QVBoxLayout(RegWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        img_label = new QLabel(RegWidget);
        img_label->setObjectName(QStringLiteral("img_label"));
        img_label->setMinimumSize(QSize(0, 150));
        img_label->setMaximumSize(QSize(423, 150));
        img_label->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/img/top2.png);\n"
"font: 75 24pt \"\346\226\271\346\255\243\345\247\232\344\275\223\";"));
        img_label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(img_label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        comboBox = new QComboBox(RegWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setStyleSheet(QString::fromUtf8("font: 11pt \"\346\226\260\345\256\213\344\275\223\";\n"
""));

        gridLayout->addWidget(comboBox, 3, 2, 1, 1);

        cpwd_lineEdit = new QLineEdit(RegWidget);
        cpwd_lineEdit->setObjectName(QStringLiteral("cpwd_lineEdit"));
        cpwd_lineEdit->setStyleSheet(QString::fromUtf8("font: 11pt \"\346\226\260\345\256\213\344\275\223\";"));

        gridLayout->addWidget(cpwd_lineEdit, 2, 2, 1, 1);

        que_label = new QLabel(RegWidget);
        que_label->setObjectName(QStringLiteral("que_label"));
        que_label->setMinimumSize(QSize(0, 35));
        que_label->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\256\213\344\275\223\";"));
        que_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(que_label, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(30, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        name_label = new QLabel(RegWidget);
        name_label->setObjectName(QStringLiteral("name_label"));
        name_label->setMinimumSize(QSize(100, 35));
        name_label->setMaximumSize(QSize(16777215, 35));
        name_label->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\256\213\344\275\223\";"));
        name_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(name_label, 0, 1, 1, 1);

        pwd_lineEdit = new QLineEdit(RegWidget);
        pwd_lineEdit->setObjectName(QStringLiteral("pwd_lineEdit"));
        pwd_lineEdit->setStyleSheet(QString::fromUtf8("font: 11pt \"\346\226\260\345\256\213\344\275\223\";"));

        gridLayout->addWidget(pwd_lineEdit, 1, 2, 1, 1);

        label = new QLabel(RegWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 35));
        label->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\256\213\344\275\223\";"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 4, 1, 1, 1);

        name_lineEdit = new QLineEdit(RegWidget);
        name_lineEdit->setObjectName(QStringLiteral("name_lineEdit"));
        name_lineEdit->setMinimumSize(QSize(0, 0));
        name_lineEdit->setMaximumSize(QSize(16777215, 16777215));
        name_lineEdit->setStyleSheet(QString::fromUtf8("font: 11pt \"\346\226\260\345\256\213\344\275\223\";"));

        gridLayout->addWidget(name_lineEdit, 0, 2, 1, 1);

        ans_lineEdit = new QLineEdit(RegWidget);
        ans_lineEdit->setObjectName(QStringLiteral("ans_lineEdit"));
        ans_lineEdit->setStyleSheet(QString::fromUtf8("font: 11pt \"\346\226\260\345\256\213\344\275\223\";"));

        gridLayout->addWidget(ans_lineEdit, 4, 2, 1, 1);

        cpwd_label = new QLabel(RegWidget);
        cpwd_label->setObjectName(QStringLiteral("cpwd_label"));
        cpwd_label->setMinimumSize(QSize(0, 35));
        cpwd_label->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\256\213\344\275\223\";"));
        cpwd_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(cpwd_label, 2, 1, 1, 1);

        pwd_label = new QLabel(RegWidget);
        pwd_label->setObjectName(QStringLiteral("pwd_label"));
        pwd_label->setMinimumSize(QSize(100, 0));
        pwd_label->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\256\213\344\275\223\";"));
        pwd_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(pwd_label, 1, 1, 1, 1);

        eye_Button = new QPushButton(RegWidget);
        eye_Button->setObjectName(QStringLiteral("eye_Button"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/eye2.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        eye_Button->setIcon(icon);
        eye_Button->setIconSize(QSize(25, 25));
        eye_Button->setFlat(true);

        gridLayout->addWidget(eye_Button, 1, 3, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(7, -1, 7, -1);
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        confirm_pushButton = new QPushButton(RegWidget);
        confirm_pushButton->setObjectName(QStringLiteral("confirm_pushButton"));
        confirm_pushButton->setMinimumSize(QSize(105, 0));
        confirm_pushButton->setMaximumSize(QSize(16777215, 20));
        confirm_pushButton->setStyleSheet(QString::fromUtf8("/*\347\231\273\345\275\225\346\214\211\351\222\256\346\240\267\345\274\217*/\n"
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

        horizontalLayout_2->addWidget(confirm_pushButton);

        horizontalSpacer_9 = new QSpacerItem(80, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_9);

        exit_pushButton = new QPushButton(RegWidget);
        exit_pushButton->setObjectName(QStringLiteral("exit_pushButton"));
        exit_pushButton->setMinimumSize(QSize(105, 0));
        exit_pushButton->setMaximumSize(QSize(16777215, 20));
        exit_pushButton->setStyleSheet(QString::fromUtf8("/*\347\231\273\345\275\225\346\214\211\351\222\256\346\240\267\345\274\217*/\n"
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

        horizontalLayout_2->addWidget(exit_pushButton);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_2);

        groupBox = new QGroupBox(RegWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(7, 7, 7, 7);
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(radioButton->sizePolicy().hasHeightForWidth());
        radioButton->setSizePolicy(sizePolicy);
        radioButton->setMinimumSize(QSize(70, 70));
        radioButton->setMaximumSize(QSize(16777215, 16777215));
        radioButton->setLayoutDirection(Qt::LeftToRight);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icon/photo/p1.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioButton->setIcon(icon1);
        radioButton->setIconSize(QSize(60, 60));
        radioButton->setChecked(true);

        gridLayout_2->addWidget(radioButton, 0, 0, 1, 1);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setMinimumSize(QSize(70, 70));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icon/photo/p2.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioButton_2->setIcon(icon2);
        radioButton_2->setIconSize(QSize(70, 70));

        gridLayout_2->addWidget(radioButton_2, 0, 1, 1, 1);

        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setMinimumSize(QSize(70, 70));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icon/photo/p3.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioButton_3->setIcon(icon3);
        radioButton_3->setIconSize(QSize(60, 60));

        gridLayout_2->addWidget(radioButton_3, 0, 2, 1, 1);

        radioButton_4 = new QRadioButton(groupBox);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setMinimumSize(QSize(70, 70));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icon/photo/p4.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioButton_4->setIcon(icon4);
        radioButton_4->setIconSize(QSize(60, 60));

        gridLayout_2->addWidget(radioButton_4, 1, 0, 1, 1);

        radioButton_5 = new QRadioButton(groupBox);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        radioButton_5->setMinimumSize(QSize(70, 70));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icon/photo/p5.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioButton_5->setIcon(icon5);
        radioButton_5->setIconSize(QSize(70, 70));

        gridLayout_2->addWidget(radioButton_5, 1, 1, 1, 1);

        radioButton_6 = new QRadioButton(groupBox);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icon/photo/p6.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioButton_6->setIcon(icon6);
        radioButton_6->setIconSize(QSize(65, 65));

        gridLayout_2->addWidget(radioButton_6, 1, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        groupBox->raise();
        img_label->raise();

        retranslateUi(RegWidget);

        QMetaObject::connectSlotsByName(RegWidget);
    } // setupUi

    void retranslateUi(QWidget *RegWidget)
    {
        RegWidget->setWindowTitle(QApplication::translate("RegWidget", "Form", 0));
        img_label->setText(QString());
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("RegWidget", "\346\202\250\347\210\266\344\272\262\347\232\204\345\220\215\345\255\227\346\230\257\357\274\237", 0)
         << QApplication::translate("RegWidget", "\346\202\250\346\257\215\344\272\262\347\232\204\345\220\215\345\255\227\346\230\257\357\274\237", 0)
        );
        que_label->setText(QApplication::translate("RegWidget", "\345\257\206 \344\277\235 \351\227\256 \351\242\230\357\274\232", 0));
        name_label->setText(QApplication::translate("RegWidget", " \347\224\250  \346\210\267   \345\220\215\357\274\232", 0));
        label->setText(QApplication::translate("RegWidget", "\345\257\206 \344\277\235 \347\255\224 \346\241\210\357\274\232", 0));
        cpwd_label->setText(QApplication::translate("RegWidget", "\347\241\256 \350\256\244 \345\257\206 \347\240\201\357\274\232", 0));
        pwd_label->setText(QApplication::translate("RegWidget", "\345\257\206       \347\240\201\357\274\232", 0));
        eye_Button->setText(QString());
        confirm_pushButton->setText(QApplication::translate("RegWidget", "\346\263\250\345\206\214", 0));
        exit_pushButton->setText(QApplication::translate("RegWidget", "\345\217\226\346\266\210", 0));
        groupBox->setTitle(QApplication::translate("RegWidget", "\345\244\264\345\203\217", 0));
        radioButton->setText(QString());
        radioButton_2->setText(QString());
        radioButton_3->setText(QString());
        radioButton_4->setText(QString());
        radioButton_5->setText(QString());
        radioButton_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RegWidget: public Ui_RegWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGWIDGET_H
