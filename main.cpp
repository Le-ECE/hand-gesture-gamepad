#include "mainwindow.h"
#include <QApplication>
#include <QThread.h>
#include "driver.h"
#include "qpixmap.h"
#include "qtimer.h"
#include "qobject.h"
#include "QtCore"
#include "MyTimer.h"
#include "QLabel"

QImage Mat2QImage(const cv::Mat3b& src) {
    QImage dest(src.cols, src.rows, QImage::Format_ARGB32);
    for (int y = 0; y < src.rows; ++y) {
        const cv::Vec3b* srcrow = src[y];
        QRgb* destrow = (QRgb*)dest.scanLine(y);
        for (int x = 0; x < src.cols; ++x) {
            destrow[x] = qRgba(srcrow[x][2], srcrow[x][1], srcrow[x][0], 255);
        }
    }
    return dest;
}

MyTimer::MyTimer(int refresh) {
    driverInitialize();
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(MySlot()));
    timer->start(1000 / refresh); // Polls webcam (refresh) times per second
}

void MyTimer::MySlot() {
    //Mat2QImage(captureImage());
    captureImage();
    sendReport();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MyTimer* mTimer = new MyTimer(60);
    w.show();

    return a.exec();
}


