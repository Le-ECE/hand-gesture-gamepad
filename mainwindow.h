#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QTimer>
#include "driver_setting_window.h"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/highgui/highgui.hpp>
#include "QLabel"
#include "profile_data.h"
#include "gesture_panel.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool Driver_Enabled = false;
    void pic_window(cv::Mat pic,QLabel* lb);
    void put_window(QString src,QWidget* parent);
    void update_profile();
    QList<QLabel*> labels;

public slots:
    void update();

private slots:
    void on_pushButton_5_clicked();
    void on_btn_ld_clicked();
    void on_pushButton_6_clicked();
    void on_btn_change_driver_clicked();
    void on_btn_install_driver_clicked();
    void on_btn_pf_new_clicked();
    void on_btn_pf_save_clicked();
    void on_btn_pf_delete_clicked();
    void on_btn_pf_load_clicked();
    void on_driverButton_clicked();
    void on_driverButton2_clicked();
    void on_cbb_profile_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QString Profile_name;
    Profile_data p_data;
    void refresh_profile();
    QList<QString> profiles;
    QList<Gesture_panel*> g_panel_list;
    QTimer* timer;
};
#endif // MAINWINDOW_H
