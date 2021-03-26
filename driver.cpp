/* Air Wheel Driver.cpp
Nhat Vu Le
Majed Qarmout
Haoran Zhou
Yu Zhang
*/

// Windows Imports
#include "framework.h"
#include "Windows.h"
#include "Xinput.h"

// OpenCV Imports
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/video/background_segm.hpp"

// ViGEm Imports
#include "ViGEm/Client.h"
#include "ViGEm/Util.h"
#include "ViGEm/Common.h"

// C/C++ Imports
#include "iostream"
#include "fstream"
#include "string"
#include "stdio.h"
#include "stdlib.h"

// Additional Libraries
#pragma comment(lib, "setupapi.lib")
#pragma comment(lib,"XInput.lib")
#pragma comment(lib,"Xinput9_1_0.lib")

// QT Imports
#include <QSettings>
#include <QString>
#include <QApplication>

// Constants and Definitions
#define WIN32_LEAN_AND_MEAN
#define MAX_LOADSTRING 100
#define TRIGGER_MIN 0
#define TRIGGER_MAX 255
#define THUMBSTICK_MIN -32768
#define THUMBSTICK_MAX 32767
#define PI 3.14159265358979323846

// Namespaces
using namespace cv;
using namespace std;

// Struct Declarations
typedef struct _GESTURE {
    std::string gestureName;
    USHORT button;
    SHORT leftX, leftY, rightX, rightY;
    BYTE leftTrig, rightTrig;
} GESTURE, * PGESTURE;

typedef struct _PROFILE {
    std::string profileName;
    GESTURE list[6];

} PROFILE, * PPROFILE;

typedef struct _SETTINGS {
    PROFILE currentProfile;

} SETTINGS, * PSETTINGS;

// Settings Variables
PROFILE currentProfile;
//QString path = ":/settings.ini";
//QSettings settings(path, QSettings::IniFormat);
QSettings settings("settings.ini", QSettings::IniFormat);

// Gesture Variables
int indexOfBiggestContour, sizeOfBiggestContour, fingerCount, ind, i, k;
Mat img, img_threshold, img_gray, img_roi;
VideoCapture cam(0);                            // Initializes webcam capture
GESTURE currentGesture; 						// Current gesture to be determined by hand tracking
XUSB_REPORT report;

// Spawn Virtual Controller
const auto client = vigem_alloc();              // Initializes ViGEm API
const auto retval = vigem_connect(client);      // Establishes connection to driver
const auto pad = vigem_target_x360_alloc();     // Allocates handle for gamepad
const auto pir = vigem_target_add(client, pad); // Adds client to bus (Plugs in controller)

// Forward declarations of functions 
Mat gray_image(Mat img_gray, Mat img_roi);
Mat threshold_image(Mat img_gray, Mat img_roi);
Mat captureImage(void);
int driverInitialize(void);
void sendReport(void);

// Used to quickly assign action values
GESTURE configGesture(
    std::string gestureName,
    USHORT button,
    SHORT leftX,
    SHORT leftY,
    SHORT rightX,
    SHORT rightY,
    BYTE leftTrig,
    BYTE rightTrig
) {
    GESTURE assign;

    assign.gestureName = gestureName;
    assign.button = button;
    assign.leftX = leftX;
    assign.leftY = leftY;
    assign.rightX = rightX;
    assign.rightY = rightY;
    assign.leftTrig = leftTrig;
    assign.rightTrig = rightTrig;

    return assign;
}

PROFILE configProfile() {
    PROFILE assign;

    std::string gestureName;
    USHORT button;
    SHORT leftX;
    SHORT leftY;
    SHORT rightX;
    SHORT rightY;
    BYTE leftTrig;
    BYTE rightTrig;

    assign.profileName = settings.value("currentProfile/profileName", "default").toString().toLocal8Bit().constData();
    
    for (int i = 0; i <= 5; i++) {
        gestureName = settings.value(QString::number(i) +"/gestureName", "null").toString().toLocal8Bit().constData();
        button = settings.value(QString::number(i) + "/button", 0x0000).toInt();
        leftX = settings.value(QString::number(i) + "/leftX", 0).toInt();
        leftY = settings.value(QString::number(i) + "/leftY", 0).toInt();
        rightX = settings.value(QString::number(i) + "/rightX", 0).toInt();
        rightY = settings.value(QString::number(i) + "/rightY", 0).toInt();
        leftTrig = settings.value(QString::number(i) + "/leftTrig", 0).toInt();
        rightTrig = settings.value(QString::number(i) + "/rightTrig", 0).toInt();

        assign.list[i] = configGesture(gestureName, button, leftX, leftY, rightX, rightY, leftTrig, rightTrig);
    }



    return assign;
}

int driverInitialize(void) {
    XUSB_REPORT_INIT(&report);						// Allocates memory for and initializes gamepad report

    // Checks for Webcam and Driver Initialization Errors   
    if (!cam.isOpened())
        return -1;
    else if (!cam.read(img)) {
        cout << "Cannot read from camera." << std::endl;
        return -1;
    }
    else if (client == nullptr) {
        std::cerr << "Not enough memory for driver." << std::endl;
        return -1;
    }
    else if (!VIGEM_SUCCESS(retval)) {
        std::cerr << "ViGEm Bus connection failed with error code: 0x" << std::hex << retval << std::endl;
        return -1;
    }
    else if (!VIGEM_SUCCESS(pir)) {
        std::cerr << "Target plugin failed with error code: 0x" << std::hex << pir << std::endl;
        return -1;
    }
        
  //  int tester = settings.value("Controls/stick", 0).toInt();

    // LOAD LAST USED PROFILE VIA SETTINGS.INI
        // GUI will read from profileName.ini and overwrite settings file, and currentProfile is set to that
        // Visual Studio Debugger reads settings.ini from root folder, running exe directly reads settings file in same folder as exe
    currentProfile = configProfile();
    currentGesture = currentProfile.list[0]; // Default Gesture (This line must be run after assigning gestures)

    // Gesture List Initialization (TEST)
    //currentProfile.name = "Profile 1";
    //currentProfile.list[0] = configGesture("None", 0, 0, 0, 0, 0, 0, 0);
    //currentProfile.list[1] = configGesture("1 Finger", XUSB_GAMEPAD_A, 0, 0, tester, tester, 0, 0);
    //currentProfile.list[2] = configGesture("2 Fingers", XUSB_GAMEPAD_B, tester, tester, 0, 0, 0, 0);
    //currentProfile.list[3] = configGesture("3 Fingers", XUSB_GAMEPAD_Y, 0, 0, tester, tester, 0, 0);
    //currentProfile.list[4] = configGesture("4 Fingers", XUSB_GAMEPAD_X, tester, tester, 0, 0, 0, 0);
    //currentProfile.list[5] = configGesture("5 Fingers", 0xF000, 0, 0, tester, tester, 0, 0);

    return 0;
}

Mat gray_image(Mat img_gray, Mat img_roi)
{
    cvtColor(img_roi, img_gray, COLOR_BGR2GRAY);
    GaussianBlur(img_gray, img_gray, Size(19, 19), 0.0, 0);
    return img_gray;
}

Mat threshold_image(Mat img_gray, Mat img_threshold)
{
    threshold(img_gray, img_threshold, 0, 255, THRESH_BINARY_INV + THRESH_OTSU);
    return img_threshold;
}

float innerAngle(float px1, float py1, float px2, float py2, float cx1, float cy1)
{
    float dist1 = sqrt((px1 - cx1) * (px1 - cx1) + (py1 - cy1) * (py1 - cy1));
    float dist2 = sqrt((px2 - cx1) * (px2 - cx1) + (py2 - cy1) * (py2 - cy1));

    float Ax, Ay;
    float Bx, By;
    float Cx, Cy;

    Cx = cx1;
    Cy = cy1;
    if (dist1 < dist2)
    {
        Bx = px1;
        By = py1;
        Ax = px2;
        Ay = py2;
    }
    else {
        Bx = px2;
        By = py2;
        Ax = px1;
        Ay = py1;
    }

    float Q1 = Cx - Ax;
    float Q2 = Cy - Ay;
    float P1 = Bx - Ax;
    float P2 = By - Ay;

    float A = acos((P1 * Q1 + P2 * Q2) / (sqrt(P1 * P1 + P2 * P2) * sqrt(Q1 * Q1 + Q2 * Q2)));

    A = A * 180 / PI;

    return A;
}

Mat captureImage(void) {
    cam.read(img);
    Rect roi(0, 0, 300, 300);
    img_roi = img(roi);

    img_gray = gray_image(img_gray, img_roi);
    img_threshold = threshold_image(img_gray, img_threshold);

    vector<vector<Point> >contours;
    vector<Vec4i>hierarchy;
    findContours(img_threshold, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point());
    fingerCount = 0;
    if (contours.size() > 0) {
        int indexOfBiggestContour = -1;
        int sizeOfBiggestContour = 0;

        vector<vector<int> >hull(contours.size());
        vector<vector<Vec4i> >defects(contours.size());
        vector<vector<Point> >defectPoint(contours.size());
        vector<vector<Point> >hullPoint(contours.size());

        for (int i = 0; i < contours.size(); i++)
        {
            if (contourArea(contours[i]) > 5000)
            {
                convexHull(contours[i], hull[i], false);
                convexityDefects(contours[i], hull[i], defects[i]);

                for (int k = 0; k < defects[i].size(); k++)
                {
                    if (defects[i][k][3] > 15 * 256) // filter defects by depth
                    {
                        int ind_0 = defects[i][k][0];
                        int ind_1 = defects[i][k][1];
                        int ind_2 = defects[i][k][2];
                        defectPoint[i].push_back(contours[i][ind_2]);
                        hullPoint[i].push_back(contours[i][ind_0]);

                        // get rid of
                        cv::circle(img_roi, contours[i][ind_0], 5, Scalar(0, 255, 0), -1);
                        // hull points including top (arm) point
                        cv::circle(img_roi, contours[i][ind_1], 5, Scalar(0, 255, 0), -1);
                        // hull points including bottom (arm) point
                        cv::circle(img_roi, contours[i][ind_2], 5, Scalar(0, 0, 255), -1);
                        // null points
                        cv::line(img_roi, contours[i][ind_2], contours[i][ind_0], Scalar(0, 0, 255), 1);
                        cv::line(img_roi, contours[i][ind_2], contours[i][ind_1], Scalar(0, 0, 255), 1);
                    }
                }
                for (int k = 1; k <= hullPoint[i].size(); k++)
                {
                    Point p1 = defectPoint[i][k - 1];
                    Point p2 = defectPoint[i][k];
                    Point c1 = hullPoint[i][k];
                    float angle = innerAngle(p1.x, p1.y, p2.x, p2.y, c1.x, c1.y);
                    if (round(angle) < 90)
                        fingerCount++;
                }

                drawContours(img_roi, contours, i, Scalar(0, 255, 0), 1, 8, vector<Vec4i>(), 0, Point());

                if (fingerCount == 6)
                    fingerCount = 5;
            }
        }
    }

    putText(img, "Count: " + std::to_string(fingerCount), Point(20, 40), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 0, 0), 2, 8, false);
    putText(img, "Gesture: " + currentGesture.gestureName, Point(20, 80), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 0, 0), 2, 8, false);
    //putText(img, "Profile: " + currentProfile.profileName, Point(20, 120), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 0, 0), 2, 8, false);
    //imshow("Original_image", img);
    //imshow("Gray_image", img_gray);
    //imshow("Thresholded_image", img_threshold);
    imshow("ROI", img_roi);
    return(img);
}

void sendReport(void) {
    if (fingerCount >= 0 && fingerCount <= 5)
        currentGesture = currentProfile.list[fingerCount];
    else
        currentGesture = currentProfile.list[0];


    // Button Press
    report.wButtons = currentGesture.button;
    report.sThumbLX = currentGesture.leftX;
    report.sThumbLY = currentGesture.leftY;
    report.sThumbRX = currentGesture.rightX;
    report.sThumbRY = currentGesture.rightY;
    report.bLeftTrigger = currentGesture.leftTrig;
    report.bRightTrigger = currentGesture.rightTrig;
    vigem_target_x360_update(client, pad, report);
}
    
   