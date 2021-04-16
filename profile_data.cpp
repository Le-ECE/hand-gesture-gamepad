#include "profile_data.h"
#include "QFile"
#include "QTextStream"
Gesture_data::Gesture_data(){

}

Profile_data::Profile_data()
{

}


void Profile_data::save_as_file(QString fname){
    QFile file;
    file.setFileName(fname);
    bool isOK = file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text);
    int but;

    if (isOK == true){
        QTextStream out(&file);

        foreach(Gesture_data gd, this->g_datas){
            but = 0;
            out << gd.gName.simplified().toStdString().data() << endl;
            out <<QString::number(gd.LS_X).toStdString().data()<< endl;
            out <<QString::number(gd.LS_Y).toStdString().data()<< endl;
            out <<QString::number(gd.RS_X).toStdString().data()<< endl;
            out <<QString::number(gd.RS_Y).toStdString().data()<< endl;
            out <<QString::number(gd.LT).toStdString().data() << endl;
            out <<QString::number(gd.RT).toStdString().data() << endl;

            for (int i = 0; i <= 13; i++) {
                if (gd.buttons[i] == 1) {
                    if (i <= 9)
                        but += pow(2, i);
                    else
                        but += pow(2, i + 2);
                }
            }

            out <<QString::number(but).toStdString().data() << endl;
        }
    }
    file.close();
}

void Profile_data::load_file(QString fname) {
    QFile file(fname);
    this->g_datas.clear();
    bool isOK = file.open(QIODevice::ReadOnly);
    int but = 0;

    if (isOK == true) {
        for (int index = 0; index < 6; index++) {
            Gesture_data gd = Gesture_data();
            QList<int> buttonsReversed;

            gd.gName = file.readLine().simplified();
            gd.LS_X = file.readLine().toInt();
            gd.LS_Y = file.readLine().toInt();
            gd.RS_X = file.readLine().toInt();
            gd.RS_Y = file.readLine().toInt();
            gd.LT = file.readLine().toInt();
            gd.RT = file.readLine().toInt();
            but = file.readLine().toInt();

            for (int i = 13; i >= 0; i--) {
                if (i > 9) {
                    if (but - pow(2, i + 2) >= 0) {
                        buttonsReversed << 1;
                        but -= pow(2, i + 2);
                    }
                    else
                        buttonsReversed << 0;
                }
                else {
                    if (but - pow(2, i) >= 0) {
                        buttonsReversed << 1;
                        but -= pow(2, i);
                    }
                    else
                        buttonsReversed << 0;
                }
            }

            for (int j = 0; j <= 13; j++) {
                gd.buttons << buttonsReversed[13 - j];
            }

            this->g_datas << gd;
        }
    }

    file.close();
}