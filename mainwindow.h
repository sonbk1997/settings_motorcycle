#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <backendinterface.h>
#include <SettingController/SettingController.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
//    void receiveChange(PressId id, SettingType type, int index);
    void receiveChangeSetting(RequestFunc fun);
    void receiveSelectSetting(RequestFunc fun);
    void receiveSelectProperty(Property p, bool value);
    void receiveChangeProperty(Property p, int value);
    void receiveSelectBrightness(Brightness p, bool value);
    void receiveChangeBrightness(Brightness p, int value);
private slots:
    void on_SEL_Press_clicked();
    void on_SEL_Hold_clicked();
    void on_SEL_Release_clicked();
    void on_SET_Press_clicked();
    void on_SET_Hold_clicked();
    void on_SET_Release_clicked();
    void on_SEL_SET_Hold_clicked();
private:
    void show_clock(bool value);

    Ui::MainWindow *ui;
    SettingController controller;
    QFont selecting;
    QFont normal;
};
#endif // MAINWINDOW_H
