/********************************************************************************
** Form generated from reading UI file 'gesture_panel.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTURE_PANEL_H
#define UI_GESTURE_PANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Gesture_panel
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *name;
    QLineEdit *nameBox;
    QWidget *widget_6;
    QGridLayout *gridLayout_3;
    QCheckBox *B;
    QCheckBox *Left;
    QCheckBox *A;
    QCheckBox *Up;
    QCheckBox *X;
    QCheckBox *R3;
    QCheckBox *Select;
    QCheckBox *Down;
    QCheckBox *Start;
    QCheckBox *LB;
    QCheckBox *Y;
    QCheckBox *L3;
    QCheckBox *Right;
    QCheckBox *RB;
    QLabel *lb_slider_1;
    QSlider *slider_1;
    QLabel *lb_slider_2;
    QSlider *slider_2;
    QLabel *lb_slider_3;
    QSlider *slider_3;
    QLabel *lb_slider_4;
    QSlider *slider_4;
    QLabel *lb_slider_5;
    QSlider *slider_5;
    QLabel *lb_slider_6;
    QSlider *slider_6;

    void setupUi(QWidget *Gesture_panel)
    {
        if (Gesture_panel->objectName().isEmpty())
            Gesture_panel->setObjectName(QString::fromUtf8("Gesture_panel"));
        Gesture_panel->resize(399, 734);
        Gesture_panel->setMinimumSize(QSize(360, 600));
        verticalLayout_2 = new QVBoxLayout(Gesture_panel);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(Gesture_panel);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(380, 720));
        QFont font;
        font.setPointSize(9);
        groupBox->setFont(font);
        groupBox->setAlignment(Qt::AlignCenter);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        name = new QLabel(groupBox);
        name->setObjectName(QString::fromUtf8("name"));
        name->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(name);

        nameBox = new QLineEdit(groupBox);
        nameBox->setObjectName(QString::fromUtf8("nameBox"));

        verticalLayout->addWidget(nameBox);

        widget_6 = new QWidget(groupBox);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setMinimumSize(QSize(300, 100));
        gridLayout_3 = new QGridLayout(widget_6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        B = new QCheckBox(widget_6);
        B->setObjectName(QString::fromUtf8("B"));
        B->setMinimumSize(QSize(0, 0));

        gridLayout_3->addWidget(B, 1, 1, 1, 1);

        Left = new QCheckBox(widget_6);
        Left->setObjectName(QString::fromUtf8("Left"));
        Left->setIconSize(QSize(200, 16));

        gridLayout_3->addWidget(Left, 4, 2, 1, 1);

        A = new QCheckBox(widget_6);
        A->setObjectName(QString::fromUtf8("A"));
        A->setMinimumSize(QSize(0, 0));
        A->setAutoFillBackground(false);

        gridLayout_3->addWidget(A, 1, 0, 1, 1);

        Up = new QCheckBox(widget_6);
        Up->setObjectName(QString::fromUtf8("Up"));

        gridLayout_3->addWidget(Up, 4, 0, 1, 1);

        X = new QCheckBox(widget_6);
        X->setObjectName(QString::fromUtf8("X"));

        gridLayout_3->addWidget(X, 1, 2, 1, 1);

        R3 = new QCheckBox(widget_6);
        R3->setObjectName(QString::fromUtf8("R3"));

        gridLayout_3->addWidget(R3, 3, 1, 1, 1);

        Select = new QCheckBox(widget_6);
        Select->setObjectName(QString::fromUtf8("Select"));

        gridLayout_3->addWidget(Select, 2, 2, 1, 1);

        Down = new QCheckBox(widget_6);
        Down->setObjectName(QString::fromUtf8("Down"));
        Down->setMinimumSize(QSize(0, 0));

        gridLayout_3->addWidget(Down, 4, 1, 1, 1);

        Start = new QCheckBox(widget_6);
        Start->setObjectName(QString::fromUtf8("Start"));

        gridLayout_3->addWidget(Start, 2, 3, 1, 1);

        LB = new QCheckBox(widget_6);
        LB->setObjectName(QString::fromUtf8("LB"));
        LB->setMinimumSize(QSize(0, 0));

        gridLayout_3->addWidget(LB, 2, 0, 1, 1);

        Y = new QCheckBox(widget_6);
        Y->setObjectName(QString::fromUtf8("Y"));

        gridLayout_3->addWidget(Y, 1, 3, 1, 1);

        L3 = new QCheckBox(widget_6);
        L3->setObjectName(QString::fromUtf8("L3"));
        L3->setMinimumSize(QSize(0, 0));

        gridLayout_3->addWidget(L3, 3, 0, 1, 1);

        Right = new QCheckBox(widget_6);
        Right->setObjectName(QString::fromUtf8("Right"));

        gridLayout_3->addWidget(Right, 4, 3, 1, 1);

        RB = new QCheckBox(widget_6);
        RB->setObjectName(QString::fromUtf8("RB"));

        gridLayout_3->addWidget(RB, 2, 1, 1, 1);


        verticalLayout->addWidget(widget_6);

        lb_slider_1 = new QLabel(groupBox);
        lb_slider_1->setObjectName(QString::fromUtf8("lb_slider_1"));
        lb_slider_1->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(lb_slider_1);

        slider_1 = new QSlider(groupBox);
        slider_1->setObjectName(QString::fromUtf8("slider_1"));
        slider_1->setMinimum(-32768);
        slider_1->setMaximum(32767);
        slider_1->setValue(0);
        slider_1->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(slider_1);

        lb_slider_2 = new QLabel(groupBox);
        lb_slider_2->setObjectName(QString::fromUtf8("lb_slider_2"));
        lb_slider_2->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(lb_slider_2);

        slider_2 = new QSlider(groupBox);
        slider_2->setObjectName(QString::fromUtf8("slider_2"));
        slider_2->setMinimum(-32768);
        slider_2->setMaximum(32767);
        slider_2->setValue(0);
        slider_2->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(slider_2);

        lb_slider_3 = new QLabel(groupBox);
        lb_slider_3->setObjectName(QString::fromUtf8("lb_slider_3"));
        lb_slider_3->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(lb_slider_3);

        slider_3 = new QSlider(groupBox);
        slider_3->setObjectName(QString::fromUtf8("slider_3"));
        slider_3->setMinimum(-32768);
        slider_3->setMaximum(32767);
        slider_3->setValue(0);
        slider_3->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(slider_3);

        lb_slider_4 = new QLabel(groupBox);
        lb_slider_4->setObjectName(QString::fromUtf8("lb_slider_4"));
        lb_slider_4->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(lb_slider_4);

        slider_4 = new QSlider(groupBox);
        slider_4->setObjectName(QString::fromUtf8("slider_4"));
        slider_4->setMinimum(-32768);
        slider_4->setMaximum(32767);
        slider_4->setValue(0);
        slider_4->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(slider_4);

        lb_slider_5 = new QLabel(groupBox);
        lb_slider_5->setObjectName(QString::fromUtf8("lb_slider_5"));
        lb_slider_5->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(lb_slider_5);

        slider_5 = new QSlider(groupBox);
        slider_5->setObjectName(QString::fromUtf8("slider_5"));
        slider_5->setMaximum(255);
        slider_5->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(slider_5);

        lb_slider_6 = new QLabel(groupBox);
        lb_slider_6->setObjectName(QString::fromUtf8("lb_slider_6"));
        lb_slider_6->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(lb_slider_6);

        slider_6 = new QSlider(groupBox);
        slider_6->setObjectName(QString::fromUtf8("slider_6"));
        slider_6->setMaximum(255);
        slider_6->setValue(0);
        slider_6->setSliderPosition(0);
        slider_6->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(slider_6);


        verticalLayout_2->addWidget(groupBox);


        retranslateUi(Gesture_panel);

        QMetaObject::connectSlotsByName(Gesture_panel);
    } // setupUi

    void retranslateUi(QWidget *Gesture_panel)
    {
        Gesture_panel->setWindowTitle(QCoreApplication::translate("Gesture_panel", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Gesture_panel", "GroupBox", nullptr));
        name->setText(QCoreApplication::translate("Gesture_panel", "Gesture Name:", nullptr));
        nameBox->setInputMask(QString());
        nameBox->setText(QCoreApplication::translate("Gesture_panel", "default", nullptr));
        B->setText(QCoreApplication::translate("Gesture_panel", "B", nullptr));
        Left->setText(QCoreApplication::translate("Gesture_panel", "Left", nullptr));
        A->setText(QCoreApplication::translate("Gesture_panel", "A", nullptr));
        Up->setText(QCoreApplication::translate("Gesture_panel", "Up", nullptr));
        X->setText(QCoreApplication::translate("Gesture_panel", "X", nullptr));
        R3->setText(QCoreApplication::translate("Gesture_panel", "R3", nullptr));
        Select->setText(QCoreApplication::translate("Gesture_panel", "Select", nullptr));
        Down->setText(QCoreApplication::translate("Gesture_panel", "Down", nullptr));
        Start->setText(QCoreApplication::translate("Gesture_panel", "Start", nullptr));
        LB->setText(QCoreApplication::translate("Gesture_panel", "LB", nullptr));
        Y->setText(QCoreApplication::translate("Gesture_panel", "Y", nullptr));
        L3->setText(QCoreApplication::translate("Gesture_panel", "L3", nullptr));
        Right->setText(QCoreApplication::translate("Gesture_panel", "Right", nullptr));
        RB->setText(QCoreApplication::translate("Gesture_panel", "RB", nullptr));
        lb_slider_1->setText(QCoreApplication::translate("Gesture_panel", "Left Thumbstick X", nullptr));
        lb_slider_2->setText(QCoreApplication::translate("Gesture_panel", "Left Thumbstick Y", nullptr));
        lb_slider_3->setText(QCoreApplication::translate("Gesture_panel", "Right Thumbstick X", nullptr));
        lb_slider_4->setText(QCoreApplication::translate("Gesture_panel", "Right Thumbstick Y", nullptr));
        lb_slider_5->setText(QCoreApplication::translate("Gesture_panel", "Left Trigger", nullptr));
        lb_slider_6->setText(QCoreApplication::translate("Gesture_panel", "Right Trigger", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Gesture_panel: public Ui_Gesture_panel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTURE_PANEL_H
