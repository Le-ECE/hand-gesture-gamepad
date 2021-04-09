#include "driver_setting_window.h"
#include "ui_driver_setting_window.h"

Driver_Setting_Window::Driver_Setting_Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Driver_Setting_Window)
{
    ui->setupUi(this);
}

Driver_Setting_Window::~Driver_Setting_Window()
{
    delete ui;
}
