#ifndef PROFILE_DATA_H
#define PROFILE_DATA_H
#include "QList"
#include "QString"

class Gesture_data
{
public:
    Gesture_data();
    QString gName;
    int Gesture_type;
    int LS_X,LS_Y,RS_X,RS_Y, LT, RT;
    QList<int> buttons;
};


class Profile_data
{
public:
    Profile_data();
    QList<Gesture_data> g_datas;
    void save_as_file(QString fname);
    void load_file(QString fname);
};

#endif // PROFILE_DATA_H
