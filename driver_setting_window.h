#ifndef DRIVER_SETTING_WINDOW_H
#define DRIVER_SETTING_WINDOW_H

#include <QWidget>

namespace Ui {
class Driver_Setting_Window;
}

class Driver_Setting_Window : public QWidget
{
    Q_OBJECT

public:
    explicit Driver_Setting_Window(QWidget *parent = nullptr);
    ~Driver_Setting_Window();

private:
    Ui::Driver_Setting_Window *ui;
};

#endif // DRIVER_SETTING_WINDOW_H
