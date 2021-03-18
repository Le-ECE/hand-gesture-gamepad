#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_pushButton_5_clicked(){
    QMessageBox::information(NULL, QString::fromLocal8Bit("Warning"),
                            QString::fromLocal8Bit("Please put this file in XX folder to execute"));
}

void MainWindow::on_horizontalSlider_sliderMoved(int position){
    ui->lb_slider->setText("text value:"+QString::number(position));
}


void MainWindow::on_btn_ld_clicked(){

}

void MainWindow::on_pushButton_6_clicked(){
    this->close();
}
