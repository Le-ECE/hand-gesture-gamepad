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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Driver_Setting_Window
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *driverLabel1;
    QPushButton *driverButton;
    QLabel *driverLabel2;
    QPushButton *driverButton2;

    void setupUi(QWidget *Driver_Setting_Window)
    {
        if (Driver_Setting_Window->objectName().isEmpty())
            Driver_Setting_Window->setObjectName(QString::fromUtf8("Driver_Setting_Window"));
        Driver_Setting_Window->resize(250, 200);
        Driver_Setting_Window->setMinimumSize(QSize(250, 200));
        Driver_Setting_Window->setMaximumSize(QSize(250, 200));
        verticalLayoutWidget = new QWidget(Driver_Setting_Window);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 251, 161));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        driverLabel1 = new QLabel(verticalLayoutWidget);
        driverLabel1->setObjectName(QString::fromUtf8("driverLabel1"));
        driverLabel1->setMinimumSize(QSize(0, 20));
        driverLabel1->setMaximumSize(QSize(250, 20));
        driverLabel1->setLayoutDirection(Qt::LeftToRight);
        driverLabel1->setWordWrap(true);

        verticalLayout->addWidget(driverLabel1);

        driverButton = new QPushButton(verticalLayoutWidget);
        driverButton->setObjectName(QString::fromUtf8("driverButton"));
        driverButton->setMaximumSize(QSize(250, 40));

        verticalLayout->addWidget(driverButton);

        driverLabel2 = new QLabel(verticalLayoutWidget);
        driverLabel2->setObjectName(QString::fromUtf8("driverLabel2"));
        driverLabel2->setMaximumSize(QSize(250, 20));
        driverLabel2->setWordWrap(true);

        verticalLayout->addWidget(driverLabel2);

        driverButton2 = new QPushButton(verticalLayoutWidget);
        driverButton2->setObjectName(QString::fromUtf8("driverButton2"));
        driverButton2->setMaximumSize(QSize(250, 40));

        verticalLayout->addWidget(driverButton2);


        retranslateUi(Driver_Setting_Window);

        QMetaObject::connectSlotsByName(Driver_Setting_Window);
    } // setupUi

    void retranslateUi(QWidget *Driver_Setting_Window)
    {
        Driver_Setting_Window->setWindowTitle(QCoreApplication::translate("Driver_Setting_Window", "Form", nullptr));
        driverLabel1->setText(QCoreApplication::translate("Driver_Setting_Window", "Please install ViGEmBus before using the program.", nullptr));
        driverButton->setText(QCoreApplication::translate("Driver_Setting_Window", "Install ViGEmBus Driver", nullptr));
        driverLabel2->setText(QCoreApplication::translate("Driver_Setting_Window", "Xbox 360 drivers for Windows 7 and below.", nullptr));
        driverButton2->setText(QCoreApplication::translate("Driver_Setting_Window", "Install Xinput Drivers", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Driver_Setting_Window: public Ui_Driver_Setting_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRIVER_SETTING_WINDOW_H
