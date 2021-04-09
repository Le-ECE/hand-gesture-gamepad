/********************************************************************************
** Form generated from reading UI file 'driver_setting_window.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRIVER_SETTING_WINDOW_H
#define UI_DRIVER_SETTING_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Driver_Setting_Window
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Driver_Setting_Window)
    {
        if (Driver_Setting_Window->objectName().isEmpty())
            Driver_Setting_Window->setObjectName(QString::fromUtf8("Driver_Setting_Window"));
        Driver_Setting_Window->resize(369, 315);
        label = new QLabel(Driver_Setting_Window);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 40, 271, 51));
        label->setWordWrap(true);
        label_2 = new QLabel(Driver_Setting_Window);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 170, 271, 41));
        label_2->setWordWrap(true);
        pushButton = new QPushButton(Driver_Setting_Window);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(110, 100, 151, 20));
        pushButton_2 = new QPushButton(Driver_Setting_Window);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 220, 141, 20));

        retranslateUi(Driver_Setting_Window);

        QMetaObject::connectSlotsByName(Driver_Setting_Window);
    } // setupUi

    void retranslateUi(QWidget *Driver_Setting_Window)
    {
        Driver_Setting_Window->setWindowTitle(QCoreApplication::translate("Driver_Setting_Window", "Form", nullptr));
        label->setText(QCoreApplication::translate("Driver_Setting_Window", "lf not already installed, please installthe ViGEmBus driver prior to using the program.", nullptr));
        label_2->setText(QCoreApplication::translate("Driver_Setting_Window", "On Windows 7 and prior, you may need to install the Xbox 360 controller drivers.", nullptr));
        pushButton->setText(QCoreApplication::translate("Driver_Setting_Window", "Install ViGEmBus Driver", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Driver_Setting_Window", "Install Xinput Drivers", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Driver_Setting_Window: public Ui_Driver_Setting_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRIVER_SETTING_WINDOW_H
