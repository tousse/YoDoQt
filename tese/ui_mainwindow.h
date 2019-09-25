/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_6;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_5;
    QComboBox *Pack_Format_ComboBox;
    QSpacerItem *horizontalSpacer_10;
    QComboBox *Output_combobox;
    QLabel *label;
    QGridLayout *gridLayout_5;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QCheckBox *Wifi_checkbox;
    QSpacerItem *horizontalSpacer_5;
    QCheckBox *i2c_checkbox;
    QCheckBox *ChangePass_checkbox;
    QCheckBox *USB_CheckBox;
    QCheckBox *SSH_CheckBox;
    QCheckBox *UART_CheckBox;
    QCheckBox *u_boot_checkbox;
    QLabel *label_3;
    QCheckBox *No_password_checkbox;
    QCheckBox *RPI_Logo_CheckBox;
    QCheckBox *SPI_Checkbox;
    QSpacerItem *verticalSpacer_4;
    QGridLayout *gridLayout_2;
    QComboBox *Machine_combobox;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout_7;
    QLabel *label_7;
    QSpinBox *GPU_Spinbox;
    QSpacerItem *horizontalSpacer_12;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menuBar;
    QMenu *menuHelp;
    QMenu *menuAbout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(574, 677);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/yocto-project-176x176.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayoutWidget_4 = new QWidget(centralWidget);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(10, 10, 554, 601));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        horizontalSpacer_11 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_11, 4, 3, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_6->addWidget(label_5, 3, 1, 1, 2);

        Pack_Format_ComboBox = new QComboBox(gridLayoutWidget_4);
        Pack_Format_ComboBox->setObjectName(QString::fromUtf8("Pack_Format_ComboBox"));
        Pack_Format_ComboBox->setEditable(false);

        gridLayout_6->addWidget(Pack_Format_ComboBox, 4, 1, 1, 2);

        horizontalSpacer_10 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_10, 4, 0, 1, 1);

        Output_combobox = new QComboBox(gridLayoutWidget_4);
        Output_combobox->setObjectName(QString::fromUtf8("Output_combobox"));
        Output_combobox->setEditable(false);

        gridLayout_6->addWidget(Output_combobox, 2, 1, 1, 2);

        label = new QLabel(gridLayoutWidget_4);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_6->addWidget(label, 1, 1, 1, 2);


        gridLayout_4->addLayout(gridLayout_6, 1, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        horizontalSpacer_7 = new QSpacerItem(160, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_7, 2, 2, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_9, 2, 5, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_8, 2, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_5->addItem(verticalSpacer_5, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget_4);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout_5->addWidget(pushButton_3, 2, 4, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget_4);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(false);

        gridLayout_5->addWidget(pushButton_2, 2, 3, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget_4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_5->addWidget(pushButton, 2, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_5, 6, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(gridLayoutWidget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setEnabled(true);
        label_4->setLineWidth(1);
        label_4->setTextFormat(Qt::AutoText);
        label_4->setScaledContents(false);
        label_4->setAlignment(Qt::AlignCenter);
        label_4->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout->addWidget(label_4, 1, 1, 1, 3);

        horizontalSpacer = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 4, 5, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setEnabled(true);

        gridLayout->addWidget(label_6, 4, 1, 1, 1);

        lineEdit = new QLineEdit(gridLayoutWidget_4);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);

        gridLayout->addWidget(lineEdit, 4, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSpacer_6 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 3, 3, 1, 1);

        Wifi_checkbox = new QCheckBox(gridLayoutWidget_4);
        Wifi_checkbox->setObjectName(QString::fromUtf8("Wifi_checkbox"));

        gridLayout_3->addWidget(Wifi_checkbox, 4, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        i2c_checkbox = new QCheckBox(gridLayoutWidget_4);
        i2c_checkbox->setObjectName(QString::fromUtf8("i2c_checkbox"));

        gridLayout_3->addWidget(i2c_checkbox, 5, 1, 1, 1);

        ChangePass_checkbox = new QCheckBox(gridLayoutWidget_4);
        ChangePass_checkbox->setObjectName(QString::fromUtf8("ChangePass_checkbox"));

        gridLayout_3->addWidget(ChangePass_checkbox, 3, 2, 1, 1);

        USB_CheckBox = new QCheckBox(gridLayoutWidget_4);
        USB_CheckBox->setObjectName(QString::fromUtf8("USB_CheckBox"));

        gridLayout_3->addWidget(USB_CheckBox, 5, 2, 1, 1);

        SSH_CheckBox = new QCheckBox(gridLayoutWidget_4);
        SSH_CheckBox->setObjectName(QString::fromUtf8("SSH_CheckBox"));

        gridLayout_3->addWidget(SSH_CheckBox, 2, 1, 1, 1);

        UART_CheckBox = new QCheckBox(gridLayoutWidget_4);
        UART_CheckBox->setObjectName(QString::fromUtf8("UART_CheckBox"));

        gridLayout_3->addWidget(UART_CheckBox, 6, 1, 1, 1);

        u_boot_checkbox = new QCheckBox(gridLayoutWidget_4);
        u_boot_checkbox->setObjectName(QString::fromUtf8("u_boot_checkbox"));
        u_boot_checkbox->setEnabled(true);

        gridLayout_3->addWidget(u_boot_checkbox, 2, 2, 1, 1);

        label_3 = new QLabel(gridLayoutWidget_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 0, 1, 2, 1);

        No_password_checkbox = new QCheckBox(gridLayoutWidget_4);
        No_password_checkbox->setObjectName(QString::fromUtf8("No_password_checkbox"));
        No_password_checkbox->setChecked(true);

        gridLayout_3->addWidget(No_password_checkbox, 3, 1, 1, 1);

        RPI_Logo_CheckBox = new QCheckBox(gridLayoutWidget_4);
        RPI_Logo_CheckBox->setObjectName(QString::fromUtf8("RPI_Logo_CheckBox"));

        gridLayout_3->addWidget(RPI_Logo_CheckBox, 6, 2, 1, 1);

        SPI_Checkbox = new QCheckBox(gridLayoutWidget_4);
        SPI_Checkbox->setObjectName(QString::fromUtf8("SPI_Checkbox"));

        gridLayout_3->addWidget(SPI_Checkbox, 4, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 4, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_4->addItem(verticalSpacer_4, 5, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        Machine_combobox = new QComboBox(gridLayoutWidget_4);
        Machine_combobox->setObjectName(QString::fromUtf8("Machine_combobox"));
        Machine_combobox->setEditable(false);

        gridLayout_2->addWidget(Machine_combobox, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 5, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 5, 2, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_7 = new QLabel(gridLayoutWidget_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_7->addWidget(label_7, 0, 0, 1, 1);

        GPU_Spinbox = new QSpinBox(gridLayoutWidget_4);
        GPU_Spinbox->setObjectName(QString::fromUtf8("GPU_Spinbox"));

        gridLayout_7->addWidget(GPU_Spinbox, 0, 1, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_12, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout_7, 5, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(5, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer, 2, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(5, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_4->addItem(verticalSpacer_2, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 574, 22));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuHelp->menuAction());
        menuBar->addAction(menuAbout->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Make your own SO", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Packaging format:", nullptr));
        label->setText(QApplication::translate("MainWindow", "Output Format:", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "Path", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Make", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Make your own OS", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Username:", nullptr));
        Wifi_checkbox->setText(QApplication::translate("MainWindow", "Black border", nullptr));
        i2c_checkbox->setText(QApplication::translate("MainWindow", "I2C", nullptr));
        ChangePass_checkbox->setText(QApplication::translate("MainWindow", "Change the pass in first login", nullptr));
        USB_CheckBox->setText(QApplication::translate("MainWindow", "USB Peripheral", nullptr));
        SSH_CheckBox->setText(QApplication::translate("MainWindow", "SSH", nullptr));
        UART_CheckBox->setText(QApplication::translate("MainWindow", "UART", nullptr));
        u_boot_checkbox->setText(QApplication::translate("MainWindow", "U_boot", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Features:", nullptr));
        No_password_checkbox->setText(QApplication::translate("MainWindow", "No Password/user", nullptr));
        RPI_Logo_CheckBox->setText(QApplication::translate("MainWindow", "RPI_logo", nullptr));
        SPI_Checkbox->setText(QApplication::translate("MainWindow", "SPI", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Memory for GPU:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Choose your machine:", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
