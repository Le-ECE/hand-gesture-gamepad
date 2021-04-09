#include "gesture_panel.h"
#include "ui_gesture_panel.h"

Gesture_panel::Gesture_panel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gesture_panel)
{
    ui->setupUi(this);
    boxes << ui->Up;
    boxes << ui->Down;
    boxes << ui->Left;
    boxes << ui->Right;
    boxes << ui->Start;
    boxes << ui->Select;
    boxes << ui->L3;
    boxes << ui->R3;
    boxes << ui->LB;
    boxes << ui->RB;
    boxes << ui->A;
    boxes << ui->B;
    boxes << ui->X;
    boxes << ui->Y;
}

Gesture_panel::~Gesture_panel()
{
    delete ui;
}

Gesture_data Gesture_panel::getValues(){
    Gesture_data gd=Gesture_data();

    gd.gName = ui->nameBox->text();
    gd.LS_X=ui->slider_1->value();
    gd.LS_Y=ui->slider_2->value();
    gd.RS_X=ui->slider_3->value();
    gd.RS_Y=ui->slider_4->value();
    gd.LT = ui->slider_5->value();
    gd.RT = ui->slider_6->value();

    for(int i = 0; i <= 13; i++){
        if(boxes[i]->isChecked())
            gd.buttons << 1;
        else
            gd.buttons << 0;
    }

    return gd;
}

void Gesture_panel::reset() {
        ui->nameBox->setText("default");
        ui->slider_1->setValue(0);
        ui->slider_2->setValue(0);
        ui->slider_3->setValue(0);
        ui->slider_4->setValue(0);
        ui->slider_5->setValue(0);
        ui->slider_6->setValue(0);
        ui->Down->setChecked(false);
        ui->Up->setChecked(false);
        ui->Left->setChecked(false);
        ui->Right->setChecked(false);
        ui->Start->setChecked(false);
        ui->Select->setChecked(false);
        ui->L3->setChecked(false);
        ui->R3->setChecked(false);
        ui->LB->setChecked(false);
        ui->RB->setChecked(false);
        ui->A->setChecked(false);
        ui->B->setChecked(false);
        ui->X->setChecked(false);
        ui->Y->setChecked(false);
}

void Gesture_panel::load(Gesture_data gd){
    ui->nameBox->setText(gd.gName);
    ui->slider_1->setValue(gd.LS_X);
    ui->slider_2->setValue(gd.LS_Y);
    ui->slider_3->setValue(gd.RS_X);
    ui->slider_4->setValue(gd.RS_Y);
    ui->slider_5->setValue(gd.LT);
    ui->slider_6->setValue(gd.RT);

    for(int i = 0; i = 13; i++){
        if(gd.buttons[i] == 1)
            boxes[i]->setChecked(true);
        else
            boxes[i]->setChecked(false);
    }
}


void Gesture_panel::setLabel(QString name){
    ui->groupBox->setTitle(name);
}

void Gesture_panel::on_slider_1_sliderMoved(int position)
{
    ui->lb_slider_1->setText("Left Thumbstick X: " + QString::number(ui->slider_1->value()));
}

void Gesture_panel::on_slider_2_sliderMoved(int position)
{
    ui->lb_slider_2->setText("Left Thumbstick Y: " + QString::number(ui->slider_2->value()));
}

void Gesture_panel::on_slider_3_sliderMoved(int position)
{
    ui->lb_slider_3->setText("Right Thumbstick X: " + QString::number(ui->slider_3->value()));
}

void Gesture_panel::on_slider_4_sliderMoved(int position)
{
    ui->lb_slider_4->setText("Right Thumbstick Y: " + QString::number(ui->slider_4->value()));
}

void Gesture_panel::on_slider_5_sliderMoved(int position)
{
    ui->lb_slider_4->setText("Left Trigger: " + QString::number(ui->slider_5->value()));
}

void Gesture_panel::on_slider_6_sliderMoved(int position)
{
    ui->lb_slider_4->setText("Right Trigger" + QString::number(ui->slider_6->value()));
}
