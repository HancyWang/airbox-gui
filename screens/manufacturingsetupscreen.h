#ifndef MANUFACTURINGSETUPSCREEN_H
#define MANUFACTURINGSETUPSCREEN_H

#include <QDialog>

#include "widgets/button1.h"

namespace Ui {
class ManufacturingSetupScreen;
}

class BrightnessOffsetScreen;
class PressureOffsetScreen;
class FlowSlopScreen;
class EnterSerialNumber;
class DateWindowClinical;
class TimeWindowClinical;
class ManufacturingOptionsScreen;
class NotificationTray;



class ManufacturingSetupScreen : public QDialog
{
    Q_OBJECT

public:
    explicit ManufacturingSetupScreen(QWidget *parent,
                                      BrightnessOffsetScreen * brightnessBackend,
                                      PressureOffsetScreen * pressureBackend,
                                      FlowSlopScreen * flowBackend,
                                      EnterSerialNumber * serialNumberBackend,
                                      DateWindowClinical * dateBackend,
                                      TimeWindowClinical * timeBackend,
                                      ManufacturingOptionsScreen * manufacturingOptionsBackend,
                                      NotificationTray * notificationBackend);
    ~ManufacturingSetupScreen();

    void setupWindowParameters(void);
    void updateButton1Details(Button1 * pButton,const QString &Title,const QString &imageRight);
    void updateManufacturingSetupProcessBeforeShow(void);
    void updateTimeInLocalWindow(void);
    void updateDateInLocalWindow(void);
    void updateSerialNumberInLocalWindow(void);
    void updatePressureSensorInLocalWindow(void);
    void updateFlowSensorInLocalWindow(void);
    void changeEvent(QEvent* e);
signals:
    void showBrightnessOffsetScreen();

    void showPressureOffsetScreen();

    void showFlowSlopScreen();

    void showEnterSerialNumberScreen();

    void showDateScreen(QWidget *parent, int date, int month, int year, bool colorEffect);

    void showTimeScreen(QWidget *parent, int hour, int minute, bool colorEffect);

    void updateSystemDate(int date,int month,int year);
    void updateSystemTime(int hour,int min,int sec);

private slots:
    void brightnessOffsetButton_released();
    void pressureSensorOffsetButton_released();
    void flowSensorSlopButton_released();
    void serialNumberButton_released();
    void dateButton_released();
    void timeButton_released();

    void on_backManufacturingSetup_released();

    void dateWindowClosed(int date, int month, int year);
    void timeWindowClosed(int hour, int minute);
    void serialNumberWindowClosed();
    void pressureSensorOffsetWindowClosed();
    void flowSensorSlopWindowClosed();
    void timeUpdateTimerTimeout();

public slots:
    void showManufacturingSetupScreen();

private:
    Ui::ManufacturingSetupScreen *ui;
    BrightnessOffsetScreen * brightnessScreen;
    PressureOffsetScreen * pressureScreen;
    FlowSlopScreen * flowScreen;
    EnterSerialNumber * serialNumberScreen;
    DateWindowClinical * dateScreen;
    TimeWindowClinical * timeScreen;
    ManufacturingOptionsScreen * manufacturingOptionsScreen;
    NotificationTray * notificationScreen;

    Button1 * brightnessOffsetButton;
    Button1 * pressureSensorOffsetButton;
    Button1 * flowSensorSlopButton;
    Button1 * serialNumberButton;
    Button1 * dateButton;
    Button1 * timeButton;
    QTimer * timeUpdateTimer;

};

#endif // MANUFACTURINGSETUPSCREEN_H
