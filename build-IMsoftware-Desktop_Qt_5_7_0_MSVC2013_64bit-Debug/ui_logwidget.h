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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *IP_lineEdit;
    QLabel *label_2;
    QLineEdit *PORT_lineEdit;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;

    void setupUi(QWidget *LogWidget)
    {
        if (LogWidget->objectName().isEmpty())
            LogWidget->setObjectName(QStringLiteral("LogWidget"));
        LogWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(LogWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(LogWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        IP_lineEdit = new QLineEdit(LogWidget);
        IP_lineEdit->setObjectName(QStringLiteral("IP_lineEdit"));

        horizontalLayout->addWidget(IP_lineEdit);

        label_2 = new QLabel(LogWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        PORT_lineEdit = new QLineEdit(LogWidget);
        PORT_lineEdit->setObjectName(QStringLiteral("PORT_lineEdit"));

        horizontalLayout->addWidget(PORT_lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        textBrowser = new QTextBrowser(LogWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        pushButton = new QPushButton(LogWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(LogWidget);

        QMetaObject::connectSlotsByName(LogWidget);
    } // setupUi

    void retranslateUi(QWidget *LogWidget)
    {
        LogWidget->setWindowTitle(QApplication::translate("LogWidget", "Form", 0));
        label->setText(QApplication::translate("LogWidget", "IP:", 0));
        label_2->setText(QApplication::translate("LogWidget", "PORT:", 0));
        pushButton->setText(QApplication::translate("LogWidget", "\350\277\236\346\216\245", 0));
    } // retranslateUi

};

namespace Ui {
    class LogWidget: public Ui_LogWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGWIDGET_H
