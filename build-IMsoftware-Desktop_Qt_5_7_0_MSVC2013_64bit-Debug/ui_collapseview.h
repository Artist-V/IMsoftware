/********************************************************************************
** Form generated from reading UI file 'collapseview.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLLAPSEVIEW_H
#define UI_COLLAPSEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CollapseView
{
public:
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *CollapseView)
    {
        if (CollapseView->objectName().isEmpty())
            CollapseView->setObjectName(QStringLiteral("CollapseView"));
        CollapseView->resize(192, 282);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CollapseView->sizePolicy().hasHeightForWidth());
        CollapseView->setSizePolicy(sizePolicy);
        CollapseView->setStyleSheet(QLatin1String("#scrollArea{\n"
"	border:none;\n"
"}\n"
"\n"
"#scrollAreaWidgetContents{\n"
"	\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(CollapseView);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(CollapseView);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 192, 282));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        verticalLayout_3->addWidget(widget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        verticalLayout_3->setStretch(1, 1);
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);


        retranslateUi(CollapseView);

        QMetaObject::connectSlotsByName(CollapseView);
    } // setupUi

    void retranslateUi(QWidget *CollapseView)
    {
        CollapseView->setWindowTitle(QApplication::translate("CollapseView", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class CollapseView: public Ui_CollapseView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLLAPSEVIEW_H
