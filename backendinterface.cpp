#include "backendinterface.h"
#include <QDebug>
BackendInterface *BackendInterface::instance = nullptr;
BackendInterface::BackendInterface(QObject *parent) : QObject(parent)
{

}

BackendInterface *BackendInterface::getInstance() {
    if(instance ==nullptr) {
        instance = new BackendInterface();
    }
    return instance;
}

void BackendInterface::setProperty(Property property, bool value)
{
    emit sendSelectProperty(property, value);
}

void BackendInterface::setProperty(Property property, int value)
{
    emit sendChangeProperty(property, value);
}

void BackendInterface::setBrightness(Brightness property, bool value)
{
    emit sendSelectBrightness(property, value);
}

void BackendInterface::setBrightness(Brightness property, int value)
{
    emit sendChangeBrightness(property, value);
}

void BackendInterface::selectSetting(RequestFunc func)
{
    emit sendSelectSetting(func);
}

void BackendInterface::changeSetting(RequestFunc func)
{
    emit sendChangeSetting(func);
}
