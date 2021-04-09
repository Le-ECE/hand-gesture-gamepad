/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btn_change_driver;
    QPushButton *btn_install_driver;
    QCheckBox *cbb_auto_start;
    QPushButton *btn_pf_new;
    QPushButton *btn_pf_save;
    QPushButton *btn_pf_delete;
    QPushButton *btn_pf_load;
    QComboBox *cbb_profile;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QWidget *widget_con;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_1;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1280, 941);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(1280, 900));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(280, 0));
        widget_2->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_4 = new QVBoxLayout(widget_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMinimumSize(QSize(0, 50));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btn_change_driver = new QPushButton(widget_4);
        btn_change_driver->setObjectName(QString::fromUtf8("btn_change_driver"));
        btn_change_driver->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(btn_change_driver);

        btn_install_driver = new QPushButton(widget_4);
        btn_install_driver->setObjectName(QString::fromUtf8("btn_install_driver"));
        btn_install_driver->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(btn_install_driver);

        cbb_auto_start = new QCheckBox(widget_4);
        cbb_auto_start->setObjectName(QString::fromUtf8("cbb_auto_start"));
        cbb_auto_start->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_3->addWidget(cbb_auto_start);

        btn_pf_new = new QPushButton(widget_4);
        btn_pf_new->setObjectName(QString::fromUtf8("btn_pf_new"));
        btn_pf_new->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_3->addWidget(btn_pf_new);

        btn_pf_save = new QPushButton(widget_4);
        btn_pf_save->setObjectName(QString::fromUtf8("btn_pf_save"));
        btn_pf_save->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_3->addWidget(btn_pf_save);

        btn_pf_delete = new QPushButton(widget_4);
        btn_pf_delete->setObjectName(QString::fromUtf8("btn_pf_delete"));
        btn_pf_delete->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(btn_pf_delete);

        btn_pf_load = new QPushButton(widget_4);
        btn_pf_load->setObjectName(QString::fromUtf8("btn_pf_load"));

        horizontalLayout_3->addWidget(btn_pf_load);

        cbb_profile = new QComboBox(widget_4);
        cbb_profile->setObjectName(QString::fromUtf8("cbb_profile"));
        cbb_profile->setMinimumSize(QSize(100, 0));

        horizontalLayout_3->addWidget(cbb_profile);


        verticalLayout_4->addWidget(widget_4);

        scrollArea = new QScrollArea(widget_2);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMinimumSize(QSize(450, 0));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 781, 4395));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget_5 = new QWidget(scrollAreaWidgetContents);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        verticalLayout_2 = new QVBoxLayout(widget_5);
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(widget_5);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 40));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        widget_con = new QWidget(widget_5);
        widget_con->setObjectName(QString::fromUtf8("widget_con"));
        widget_con->setMinimumSize(QSize(380, 4320));
        verticalLayout_5 = new QVBoxLayout(widget_con);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));

        verticalLayout_2->addWidget(widget_con);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout_3->addWidget(widget_5);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_4->addWidget(scrollArea);


        gridLayout_2->addWidget(widget_2, 0, 1, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_1 = new QLabel(groupBox);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setMinimumSize(QSize(400, 400));

        gridLayout->addWidget(label_1, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));

        verticalLayout->addWidget(widget_3);


        gridLayout_2->addWidget(widget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1280, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btn_change_driver->setText(QCoreApplication::translate("MainWindow", "Disable Driver", nullptr));
        btn_install_driver->setText(QCoreApplication::translate("MainWindow", "Install Driver", nullptr));
        cbb_auto_start->setText(QCoreApplication::translate("MainWindow", "Start with Windows", nullptr));
        btn_pf_new->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        btn_pf_save->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        btn_pf_delete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        btn_pf_load->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Gesture Mapping", nullptr));
        groupBox->setTitle(QString());
        label_1->setText(QCoreApplication::translate("MainWindow", "Driver Disabled", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
