#ifndef BACKENDINTERFACE_H
#define BACKENDINTERFACE_H

#include <QObject>

enum class Property {
    // int
    DEFAULT,
    HOUR,
    MINUTE,
    DAY,
    MONTH,
    YEAR
};

enum class Brightness {
    // int
    DEFAULT,
    ADJUST
};

enum class RequestFunc {
    MAIN_SETTING,
    CLOCK,
    BRIGHTNESS,
    LANGUAGE
};

class BackendInterface : public QObject
{
    Q_OBJECT
public:
    explicit BackendInterface(QObject *parent = nullptr);

    static BackendInterface *getInstance();
    void setProperty(Property property, bool value);
    void setProperty(Property property, int value);
    void setBrightness(Brightness property, bool value);
    void setBrightness(Brightness property, int value);
    void changeSetting(RequestFunc func);
    void selectSetting(RequestFunc func);
signals:
    void sendSelectProperty(Property property, bool value);
    void sendChangeProperty(Property property, int value);
    void sendSelectBrightness(Brightness property, bool value);
    void sendChangeBrightness(Brightness property, int value);
    void sendChangeSetting(RequestFunc fun);
    void sendSelectSetting(RequestFunc fun);
private:
    static BackendInterface *instance;
};

#endif // BACKENDINTERFACE_H
