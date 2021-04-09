#ifndef GESTURE_PANEL_H
#define GESTURE_PANEL_H

#include <QWidget>
#include "profile_data.h"
#include "QCheckBox"
namespace Ui {
class Gesture_panel;
}

class Gesture_panel : public QWidget
{
    Q_OBJECT

public:
    explicit Gesture_panel(QWidget *parent = nullptr);
    ~Gesture_panel();
    Gesture_data getValues();
    void reset();
    void load(Gesture_data gd);
    QList<QCheckBox*> boxes;
    void setLabel(QString name);
    void on_slider_1_sliderMoved(int position);
    void on_slider_2_sliderMoved(int position);
    void on_slider_3_sliderMoved(int position);
    void on_slider_4_sliderMoved(int position);
    void on_slider_5_sliderMoved(int position);
    void on_slider_6_sliderMoved(int position);


private:
    Ui::Gesture_panel *ui;
};

#endif // GESTURE_PANEL_H
