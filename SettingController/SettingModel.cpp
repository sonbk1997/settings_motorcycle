#include "SettingModel.h"
#include <QDebug>

void SettingModel::nextMainOption() {
    switch(mainOption) {
    case MainOption::Default: mainOption = MainOption::SettingClock; break;
    case MainOption::SettingClock: mainOption = MainOption::SettingBrightness; break;
    case MainOption::SettingBrightness: mainOption = MainOption::SettingLanguage; break;
    case MainOption::SettingLanguage: mainOption = MainOption::Default; break;
    default: break;
    }
}

void SettingModel::nextClockOption() {
    switch(clockOption) {
    case ClockOption::Default: clockOption = ClockOption::Hours; break;
    case ClockOption::Hours: clockOption = ClockOption::Minutes; break;
    case ClockOption::Minutes: clockOption = ClockOption::Days; break;
    case ClockOption::Days: clockOption = ClockOption::Months; break;
    case ClockOption::Months: clockOption = ClockOption::Years; break;
    case ClockOption::Years: clockOption = ClockOption::Default; break;
    default: break;
    }
}

void SettingModel::increaseClockField() {
    switch(clockOption) {
    case ClockOption::Hours:   settings.clock.hour = wrap(settings.clock.hour + 1, 0, 23); break;
    case ClockOption::Minutes: settings.clock.minute = wrap(settings.clock.minute + 1, 0, 59); break;
    case ClockOption::Days:    settings.clock.day = wrap(settings.clock.day + 1, 1, 31); break;
    case ClockOption::Months:  settings.clock.month = wrap(settings.clock.month + 1, 1, 12); break;
    case ClockOption::Years:   settings.clock.year = wrap(settings.clock.year + 1, 2020, 2030); break;
    default: break;
    }
}

void SettingModel::nextBrightnessOption()
{
    switch(brightnessOption) {
    case BrightnessOption::Default:     brightnessOption = BrightnessOption::Adjust; break;
    case BrightnessOption::Adjust:      brightnessOption = BrightnessOption::Default; break;
    default: break;
    }
}

void SettingModel::increaseBrightness() {
    switch(brightnessOption) {
    case BrightnessOption::Adjust:   settings.brightness = wrap(settings.brightness + 1, 0, 100); break;
    default:
        break;
    }
}

void SettingModel::increaseMainSetting(int step) {
//    switch(mainState) {
//    case MainState::SettingBrightness:
//        settings.brightness = wrap(settings.brightness + step, 0, 10);
//        break;
//    default:
//        break;
//    }
}

int SettingModel::wrap(int value, int min, int max) {
    if (value > max) value = min;
    return value;
}
