﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "driver.h"
#include <opencv2/highgui/highgui_c.h>
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/videoio/videoio.hpp>

#include <QSettings>
#include <QString>
#include "QInputDialog"
#include "QDir"

QSettings settingsQT("settings.ini", QSettings::IniFormat);

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    labels << ui->label_1;

    for (int i = 0; i < 6; i++) {
        Gesture_panel* panel = new Gesture_panel();
        g_panel_list << panel;
        panel->setLabel(QString::number(i) + " Finger(s) Held Up");
        ui->widget_con->layout()->addWidget(panel);
    }
    this->refresh_profile();
    p_data = Profile_data();
    profiles = QList<QString>();
    MyThread* thread = new MyThread(this);
    thread->win = this;
    thread->start();
    ui->btn_change_driver->setText("Disable Driver");

    driverInitialize();
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000 / 60);
}

void MainWindow::update() {
    pic_window(captureImage(), labels[0]);
    sendReport();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox::information(NULL, QString::fromLocal8Bit("Warning"),
        QString::fromLocal8Bit("Please put this file in XX folder to execute"));
}



void MainWindow::on_btn_ld_clicked()
{
    //setup_windows();
}

void MainWindow::on_pushButton_6_clicked()
{
    this->close();
}

void MainWindow::on_btn_change_driver_clicked()
{
    QString text;
    if (Driver_Enabled) {
        Driver_Enabled = false;
        text = "Enable Driver";
    }
    else {
        Driver_Enabled = true;
        text = "Disable Driver";
    }
    ui->btn_change_driver->setText(text);
}

void MainWindow::on_btn_install_driver_clicked()
{
    Driver_Setting_Window* win = new Driver_Setting_Window();
    win->setWindowTitle("Driver Guider");
    win->show();
}

void MainWindow::pic_window(cv::Mat cvImg, QLabel* lb) {
    QImage qImg;
    if (cvImg.channels() == 3)                             //3 channels color image
    {

        cv::cvtColor(cvImg, cvImg, CV_BGR2RGB);
        qImg = QImage((const unsigned char*)(cvImg.data),
            cvImg.cols, cvImg.rows,
            cvImg.cols * cvImg.channels(),
            QImage::Format_RGB888);
    }
    else if (cvImg.channels() == 1)                    //grayscale image
    {
        qImg = QImage((const unsigned char*)(cvImg.data),
            cvImg.cols, cvImg.rows,
            cvImg.cols * cvImg.channels(),
            QImage::Format_Indexed8);
    }
    else
    {
        qImg = QImage((const unsigned char*)(cvImg.data),
            cvImg.cols, cvImg.rows,
            cvImg.cols * cvImg.channels(),
            QImage::Format_RGB888);
    }
    lb->setPixmap(QPixmap::fromImage(qImg));
}

void MainWindow::put_window(QString src, QWidget* parent) {

}


MyThread::MyThread(QObject* parent) {

}

MyThread::~MyThread() {

}

void MyThread::run()
{

}

void MainWindow::on_btn_pf_new_clicked()
{
    bool isOK = false;
    QString text = QInputDialog::getText(NULL, "New Profile",
        "Please enter a profile name",
        QLineEdit::Normal,
        NULL,
        &isOK);
    if (isOK) {
        Profile_name = text;
        QString fname = QApplication::applicationDirPath() + "/profiles/" + Profile_name + ".profile";
        p_data.save_as_file(fname);
        ui->cbb_profile->addItem(Profile_name);
        ui->cbb_profile->setCurrentText(Profile_name);

        foreach(Gesture_panel * gp, g_panel_list) {
            gp->reset();
        }
    }
}

void MainWindow::update_profile() {

}

void MainWindow::refresh_profile() {
    profiles.clear();
    ui->cbb_profile->clear();
    QString dirpath = QApplication::applicationDirPath() + "/profiles/";
    QDir dir(dirpath);
    if (!dir.exists()) {
        dir.mkpath(dirpath);
    }
    QStringList nameFilters;
    nameFilters << "*.profile";
    QStringList files = dir.entryList(nameFilters, QDir::Files | QDir::Readable, QDir::Name);
    foreach(QString temp, files) {
        QString ar = temp.left(temp.indexOf("."));
        profiles << ar;
    }

    ui->cbb_profile->addItems(profiles);
}

void MainWindow::on_btn_pf_load_clicked()
{
    p_data.g_datas.clear();

    foreach(Gesture_panel * gp, g_panel_list) {
        p_data.g_datas << gp->getValues();
    }
    QString fname = QApplication::applicationDirPath() + "/profiles/" + ui->cbb_profile->currentText() + ".profile";

    settingsQT.setValue("currentProfile/profileName", ui->cbb_profile->currentText());

    for (int i = 0; i <= 5; i++) {

        int but = 0;

        for (int j = 0; j <= 13; j++) {
            if (p_data.g_datas[i].buttons[j] == 1) {
                if (j <= 9)
                    but += pow(2, j);
                else
                    but += pow(2, j + 2);
            }
        }

        settingsQT.setValue(QString::number(i) + "/gestureName", p_data.g_datas[i].gName);
        settingsQT.setValue(QString::number(i) + "/button", but);
        settingsQT.setValue(QString::number(i) + "/leftX", p_data.g_datas[i].LS_X);
        settingsQT.setValue(QString::number(i) + "/leftY", p_data.g_datas[i].LS_Y);
        settingsQT.setValue(QString::number(i) + "/rightX", p_data.g_datas[i].RS_X);
        settingsQT.setValue(QString::number(i) + "/rightY", p_data.g_datas[i].RS_Y);
        settingsQT.setValue(QString::number(i) + "/leftTrig", p_data.g_datas[i].LT);
        settingsQT.setValue(QString::number(i) + "/rightTrig", p_data.g_datas[i].RT);
    }
    loadProfile();
}

void MainWindow::on_btn_pf_save_clicked()
{
    p_data.g_datas.clear();
    QString fname = QApplication::applicationDirPath() + "/profiles/" + ui->cbb_profile->currentText() + ".profile";

    foreach(Gesture_panel * gp, g_panel_list) {
        p_data.g_datas << gp->getValues();
    }
   
    p_data.save_as_file(fname);
}

void MainWindow::on_btn_pf_delete_clicked()
{
    QMessageBox msg(this);
    msg.setWindowTitle("warning");
    msg.setText("Are you sure you want to delete this profile");
    msg.setIcon(QMessageBox::Information);
    msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    if (msg.exec() == QMessageBox::Ok)
    {
        QString fname = QApplication::applicationDirPath() + "/profiles/" + ui->cbb_profile->currentText() + ".profile";
        QFile file(fname);
        file.remove();
        this->refresh_profile();
    }
}

void MainWindow::on_cbb_profile_currentIndexChanged(const QString& arg1)
{
    p_data.g_datas.clear();
    if (arg1 != "") {
        QString fname = QApplication::applicationDirPath() + "/profiles/" + arg1 + ".profile";
        p_data.load_file(fname);
        for (int index = 0; index < 6; index++) {
            g_panel_list[index]->load(p_data.g_datas[index]);
        }
    }
}
