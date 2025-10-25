#ifndef SETTINGMODEL_H
#define SETTINGMODEL_H

/*
 * Main setting options
*/
enum class MainOption {
    Default,
    SettingClock,
    SettingBrightness,
    SettingLanguage
};

/*
 * Clock setting options
*/
enum class ClockOption {
    Default,
    Hours,
    Minutes,
    Days,
    Months,
    Years
};

enum class BrightnessOption {
    Default,
    Adjust
};

/*
 * Language setting options
*/
enum class LanguageOption {
    VN,
    EN
};

/*
 * Struct for clock data
*/
struct ClockData {
    int year = 2025;
    int month = 10;
    int day = 24;
    int minute = 53;
    int hour = 15;
};

struct Settings {
    ClockData clock;
    int brightness = 5;
    int language = 0;
};

class SettingModel {
public:
    MainOption mainOption = MainOption::Default;
    MainOption mainOptionSelected = MainOption::Default;

    ClockOption clockOption = ClockOption::Default;
    BrightnessOption brightnessOption = BrightnessOption::Default;
    LanguageOption languageOption = LanguageOption::VN;
    Settings settings;

    void nextMainOption();                      // Next main option

    // for Clock
    void nextClockOption();                      // Next clock option
    void increaseClockField();

    // for Brightness
    void nextBrightnessOption();                 // Next clock option
    void increaseBrightness();

    void increaseMainSetting(int step);

private:
    int wrap(int value, int min, int max);
};
#endif // SETTINGMODEL_H

