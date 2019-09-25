/********************************************************************************
** Form generated from reading UI file 'makewindows.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAKEWINDOWS_H
#define UI_MAKEWINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_makewindows
{
public:
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QLabel *label;

    void setupUi(QDialog *makewindows)
    {
        if (makewindows->objectName().isEmpty())
            makewindows->setObjectName(QStringLiteral("makewindows"));
        makewindows->resize(621, 555);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img/yocto-project-176x176.png"), QSize(), QIcon::Normal, QIcon::Off);
        makewindows->setWindowIcon(icon);
        gridLayoutWidget_2 = new QWidget(makewindows);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(20, 60, 581, 481));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textBrowser_2 = new QTextBrowser(gridLayoutWidget_2);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));

        gridLayout->addWidget(textBrowser_2, 1, 0, 1, 2);

        pushButton = new QPushButton(gridLayoutWidget_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        label = new QLabel(gridLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(makewindows);

        QMetaObject::connectSlotsByName(makewindows);
    } // setupUi

    void retranslateUi(QDialog *makewindows)
    {
        makewindows->setWindowTitle(QApplication::translate("makewindows", "Make Info", Q_NULLPTR));
        pushButton->setText(QApplication::translate("makewindows", "close", Q_NULLPTR));
        label->setText(QApplication::translate("makewindows", "Make Information", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class makewindows: public Ui_makewindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAKEWINDOWS_H
