#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(BackendInterface::getInstance(), &BackendInterface::sendSelectSetting, this, &MainWindow::receiveSelectSetting);
    connect(BackendInterface::getInstance(), &BackendInterface::sendChangeSetting, this, &MainWindow::receiveChangeSetting);
    connect(BackendInterface::getInstance(), &BackendInterface::sendSelectProperty, this, &MainWindow::receiveSelectProperty);
    connect(BackendInterface::getInstance(), &BackendInterface::sendChangeProperty, this, &MainWindow::receiveChangeProperty);
    connect(BackendInterface::getInstance(), &BackendInterface::sendSelectBrightness, this, &MainWindow::receiveSelectBrightness);
    connect(BackendInterface::getInstance(), &BackendInterface::sendChangeBrightness, this, &MainWindow::receiveChangeBrightness);
    selecting.setBold(true);
    ui->levelBrightness->setRange(0, 100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receiveChangeSetting(RequestFunc fun)
{
    switch (fun) {
    case RequestFunc::MAIN_SETTING:
        ui->cb_IsSettingClock->setFont(normal);
        ui->cb_IsSettingBrightness->setFont(normal);
        ui->cb_IsSettingLanguage->setFont(normal);
        break;
    case RequestFunc::CLOCK:
        ui->cb_IsSettingClock->setFont(selecting);
        ui->cb_IsSettingBrightness->setFont(normal);
        ui->cb_IsSettingLanguage->setFont(normal);
        break;
    case RequestFunc::BRIGHTNESS:
        ui->cb_IsSettingClock->setFont(normal);
        ui->cb_IsSettingBrightness->setFont(selecting);
        ui->cb_IsSettingLanguage->setFont(normal);
        break;
    case RequestFunc::LANGUAGE:
        ui->cb_IsSettingClock->setFont(normal);
        ui->cb_IsSettingBrightness->setFont(normal);
        ui->cb_IsSettingLanguage->setFont(selecting);
        break;
    default:
        break;
    }
}

void MainWindow::receiveSelectSetting(RequestFunc fun)
{
    switch (fun) {
    case RequestFunc::MAIN_SETTING:
        ui->cb_IsSettingClock->setChecked(false);
        show_clock(false);

        ui->cb_IsSettingBrightness->setChecked(false);
        ui->cb_IsSettingLanguage->setChecked(false);
        break;
    case RequestFunc::CLOCK:
        ui->cb_IsSettingClock->setChecked(true);
        show_clock(true);

        ui->cb_IsSettingBrightness->setChecked(false);
        ui->cb_IsSettingLanguage->setChecked(false);
        break;
    case RequestFunc::BRIGHTNESS:
        ui->cb_IsSettingClock->setChecked(false);
        show_clock(false);

        ui->cb_IsSettingBrightness->setChecked(true);
        ui->cb_IsSettingLanguage->setChecked(false);
        break;
    case RequestFunc::LANGUAGE:
        ui->cb_IsSettingClock->setChecked(false);
        show_clock(false);

        ui->cb_IsSettingBrightness->setChecked(false);
        ui->cb_IsSettingLanguage->setChecked(true);
        break;
    default:
        break;
    }
}

void MainWindow::receiveSelectProperty(Property p, bool value)
{
    switch (p) {
    case Property::DEFAULT:
        ui->lb_Clock_Hour->setFont(normal);
        ui->lb_Clock_Minute->setFont(normal);
        ui->lb_Clock_Day->setFont(normal);
        ui->lb_Clock_Month->setFont(normal);
        ui->lb_Clock_Year->setFont(normal);
        break;
    case Property::HOUR:
        ui->lb_Clock_Hour->setFont(selecting);
        ui->lb_Clock_Minute->setFont(normal);
        ui->lb_Clock_Day->setFont(normal);
        ui->lb_Clock_Month->setFont(normal);
        ui->lb_Clock_Year->setFont(normal);
        break;
    case Property::MINUTE:
        ui->lb_Clock_Hour->setFont(normal);
        ui->lb_Clock_Minute->setFont(selecting);
        ui->lb_Clock_Day->setFont(normal);
        ui->lb_Clock_Month->setFont(normal);
        ui->lb_Clock_Year->setFont(normal);
        break;
    case Property::DAY:
        ui->lb_Clock_Hour->setFont(normal);
        ui->lb_Clock_Minute->setFont(normal);
        ui->lb_Clock_Day->setFont(selecting);
        ui->lb_Clock_Month->setFont(normal);
        ui->lb_Clock_Year->setFont(normal);
        break;
    case Property::MONTH:
        ui->lb_Clock_Hour->setFont(normal);
        ui->lb_Clock_Minute->setFont(normal);
        ui->lb_Clock_Day->setFont(normal);
        ui->lb_Clock_Month->setFont(selecting);
        ui->lb_Clock_Year->setFont(normal);
        break;
    case Property::YEAR:
        ui->lb_Clock_Hour->setFont(normal);
        ui->lb_Clock_Minute->setFont(normal);
        ui->lb_Clock_Day->setFont(normal);
        ui->lb_Clock_Month->setFont(normal);
        ui->lb_Clock_Year->setFont(selecting);
        break;
    default:
        break;
    }
}

void MainWindow::receiveChangeProperty(Property p, int value)
{
    switch (p) {
    case Property::HOUR:
        ui->lb_Clock_Hour->setText(QString::number(value));
        break;
    case Property::MINUTE:
        ui->lb_Clock_Minute->setText(QString::number(value));
        break;
    case Property::DAY:
        ui->lb_Clock_Day->setText(QString::number(value));
        break;
    case Property::MONTH:
        ui->lb_Clock_Month->setText(QString::number(value));
        break;
    case Property::YEAR:
        ui->lb_Clock_Year->setText(QString::number(value));
        break;
    default:
        break;
    }
}

void MainWindow::receiveSelectBrightness(Brightness p, bool value)
{
    switch (p) {
    case Brightness::ADJUST:
        ui->levelBrightness->setEnabled(value);
        break;
    default:
        ui->levelBrightness->setEnabled(false);
        break;
    }
}

void MainWindow::receiveChangeBrightness(Brightness p, int value)
{
    switch (p) {
    case Brightness::ADJUST:
        ui->levelBrightness->setValue(value);
        break;
    }
}

void MainWindow::on_SEL_Press_clicked()
{
    controller.onSelPress();
}

void MainWindow::on_SEL_Hold_clicked()
{
    controller.onSelHold();
}

void MainWindow::on_SEL_Release_clicked()
{
    controller.onSelRelease();
}

void MainWindow::on_SET_Press_clicked()
{
    controller.onSetPress();
}

void MainWindow::on_SET_Hold_clicked()
{

}

void MainWindow::on_SET_Release_clicked()
{

}

void MainWindow::on_SEL_SET_Hold_clicked()
{

}
void MainWindow::show_clock(bool value) {
    ui->lb_Clock_Hour->setEnabled(value);
    ui->lb_Clock_Minute->setEnabled(value);
    ui->lb_Clock_Day->setEnabled(value);
    ui->lb_Clock_Month->setEnabled(value);
    ui->lb_Clock_Year->setEnabled(value);
}
