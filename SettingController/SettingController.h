#ifndef SETTINGCONTROLLER_H
#define SETTINGCONTROLLER_H

#include "SettingModel.h"
#include "backendinterface.h"
#include <QDebug>
#include <iostream>
#include <QTimer>
#include <QObject>

class SettingController : public QObject {
    Q_OBJECT
public:
    SettingController();

    void onSetPress();

    void onSelPress();

    void onSelHold();

    void onSelRelease();

private:
    SettingModel model;

    void increaseWithTimer();

    QTimer myTimer;
//    xTimerHandle myTimer;
};

#endif // SETTINGCONTROLLER_H
