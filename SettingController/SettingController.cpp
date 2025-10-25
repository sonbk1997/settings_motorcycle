#include "SettingController.h"

SettingController::SettingController()
{
//    myTimer = xTimerCreate("myTimer", pdMS_TO_TICKS(500), pdTRUE, (void*)0, increaseWithTimer);   // for FreeRTOS
    connect(&myTimer, &QTimer::timeout, this, &SettingController::increaseWithTimer);               // for QtTimer
}

void SettingController::onSetPress()
{
    switch (model.mainOptionSelected) {
    case MainOption::Default:
        model.nextMainOption();
        qDebug() << "Main option: " << static_cast<int>(model.mainOption);
        BackendInterface::getInstance()->changeSetting(static_cast<RequestFunc>(static_cast<int>(model.mainOption)));
        break;
    case MainOption::SettingClock:
        model.nextClockOption();
        qDebug() << "Clock option: " << static_cast<int>(model.clockOption);
        BackendInterface::getInstance()->setProperty(static_cast<Property>(static_cast<int>(model.clockOption)), true);
        if(model.clockOption == ClockOption::Default) {
            // send value to CM4
            qDebug() << "Send value to CM4";
            model.nextMainOption();
            BackendInterface::getInstance()->changeSetting(static_cast<RequestFunc>(static_cast<int>(model.mainOption)));
            model.mainOptionSelected = MainOption::Default;
            BackendInterface::getInstance()->selectSetting(static_cast<RequestFunc>(static_cast<int>(model.mainOptionSelected)));
        }
        break;
    case MainOption::SettingBrightness:
        model.nextBrightnessOption();
        qDebug() << "Clock option: " << static_cast<int>(model.brightnessOption);
        BackendInterface::getInstance()->setBrightness(static_cast<Brightness>(static_cast<int>(model.brightnessOption)), true);
        if(model.brightnessOption == BrightnessOption::Default) {
            qDebug() << "Send value to Brightness driver, save data to EPPROM";
            model.nextMainOption();
            BackendInterface::getInstance()->changeSetting(static_cast<RequestFunc>(static_cast<int>(model.mainOption)));
            model.mainOptionSelected = MainOption::Default;
            BackendInterface::getInstance()->selectSetting(static_cast<RequestFunc>(static_cast<int>(model.mainOptionSelected)));
        }
        break;
    case MainOption::SettingLanguage:
//        model.nextClockOption();
//        BackendInterface::getInstance()->changeSet(SettingType::CLOCK, static_cast<int>(model.clockOption));
//        break;
    default:
        break;
    }
}

void SettingController::onSelPress()
{
    switch (model.mainOptionSelected) {
    case MainOption::Default:
        model.mainOptionSelected = model.mainOption;
        BackendInterface::getInstance()->selectSetting(static_cast<RequestFunc>(static_cast<int>(model.mainOptionSelected)));
        break;
    case MainOption::SettingClock:
        model.increaseClockField();
        switch (model.clockOption) {
        case ClockOption::Hours:
            BackendInterface::getInstance()->setProperty(static_cast<Property>(static_cast<int>(ClockOption::Hours)), model.settings.clock.hour);
            break;

        case ClockOption::Minutes:
            BackendInterface::getInstance()->setProperty(static_cast<Property>(static_cast<int>(ClockOption::Minutes)), model.settings.clock.minute);
            break;

        case ClockOption::Days:
            BackendInterface::getInstance()->setProperty(static_cast<Property>(static_cast<int>(ClockOption::Days)), model.settings.clock.day);
            break;

        case ClockOption::Months:
            BackendInterface::getInstance()->setProperty(static_cast<Property>(static_cast<int>(ClockOption::Months)), model.settings.clock.month);
            break;

        case ClockOption::Years:
            BackendInterface::getInstance()->setProperty(static_cast<Property>(static_cast<int>(ClockOption::Years)), model.settings.clock.year);
            break;
        default:
            break;
        }
    case MainOption::SettingBrightness:
        model.increaseBrightness();
        BackendInterface::getInstance()->setBrightness(static_cast<Brightness>(static_cast<int>(BrightnessOption::Adjust)), model.settings.brightness);
    case MainOption::SettingLanguage:
    default:
        break;
    }
}

void SettingController::onSelHold()
{
//    xTimerStart(myTimer, 0);
    myTimer.start(300);
}

void SettingController::onSelRelease()
{
//    xTimerStop(myTimer, 0);
    myTimer.stop();
}

void SettingController::increaseWithTimer()
{
    switch (model.mainOptionSelected) {
    case MainOption::SettingClock:
        model.increaseClockField();
        switch (model.clockOption) {
        case ClockOption::Hours:
            BackendInterface::getInstance()->setProperty(static_cast<Property>(static_cast<int>(ClockOption::Hours)), model.settings.clock.hour);
            break;

        case ClockOption::Minutes:
            BackendInterface::getInstance()->setProperty(static_cast<Property>(static_cast<int>(ClockOption::Minutes)), model.settings.clock.minute);
            break;

        case ClockOption::Days:
            BackendInterface::getInstance()->setProperty(static_cast<Property>(static_cast<int>(ClockOption::Days)), model.settings.clock.day);
            break;

        case ClockOption::Months:
            BackendInterface::getInstance()->setProperty(static_cast<Property>(static_cast<int>(ClockOption::Months)), model.settings.clock.month);
            break;

        case ClockOption::Years:
            BackendInterface::getInstance()->setProperty(static_cast<Property>(static_cast<int>(ClockOption::Years)), model.settings.clock.year);
            break;
        default:
            break;
        }
    case MainOption::SettingBrightness:
        model.increaseBrightness();
        BackendInterface::getInstance()->setBrightness(static_cast<Brightness>(static_cast<int>(BrightnessOption::Adjust)), model.settings.brightness);
    case MainOption::SettingLanguage:
    case MainOption::Default:
    default:
        break;
    }
}
