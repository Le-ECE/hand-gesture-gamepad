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

// Constants and Definitions
#define WIN32_LEAN_AND_MEAN
#define MAX_LOADSTRING 100
#define TRIGGER_MIN 0
#define TRIGGER_MAX 255
#define THUMBSTICK_MIN -32768
#define THUMBSTICK_MAX 32767

// Namespaces
using namespace cv;
using namespace std;

// Struct Declarations
typedef struct _GESTURE {
    std::string name;
    USHORT button;
    SHORT leftX, leftY, rightX, rightY;
    BYTE leftTrig, rightTrig;
} GESTURE, * PGESTURE;

typedef struct _PROFILE {
    std::string name;
    GESTURE list[10];

} PROFILE, * PPROFILE;

typedef struct _SETTINGS {
    PROFILE currentProfile;

} SETTINGS, * PSETTINGS;

// Forward declarations of functions 
Mat gray_image(Mat img_gray, Mat img_roi);
Mat threshold_image(Mat img_gray, Mat img_roi);
Mat captureImage(void);
float innerAngle(float px1, float py1, float px2, float py2, float cx1, float cy1);
int driverInitialize(void);
void sendReport(void);

GESTURE configGesture(std::string name,
    USHORT button,
    SHORT leftX,
    SHORT leftY,
    SHORT rightX,
    SHORT rightY,
    BYTE leftTrig,
    BYTE rightTrig);