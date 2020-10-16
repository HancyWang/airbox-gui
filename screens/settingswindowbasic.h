#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QDialog>
#include <QPropertyAnimation>
#include <QScroller>
#include <QScrollBar>

#include "widgets/button1.h"
#include "widgets/button2.h"
#include "application.h"
#include "constants.h"

namespace Ui {
class SettingsWindow;
}

class HomeWindowBasic;
class PruControlClass;
class BrightnessControlThread;
class GoToSleepSettingsBasic;
class RampStartSettingsBasic;
class DeviceInfoSettingsBasic;
class SnoozeTimeSettingsBasic;
class BluetoothSettingsBasic;
class DataValidation;
class NotificationTray;

class SettingsWindowBasic : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsWindowBasic(QWidget *parent,
                                 HomeWindowBasic * m_HomeWindowBackend,
                                 PruControlClass * m_IpcBackend,
                                 BrightnessControlThread * brightnessBackend,
                                 GoToSleepSettingsBasic * gotoSleepBackend,
                                 RampStartSettingsBasic * rampTimeBackend,
                                 DeviceInfoSettingsBasic * deviceInfoBackend,
                                 SnoozeTimeSettingsBasic * snoozeTimeBackend,
                                 BluetoothSettingsBasic * bluetoothBasicBackend,
                                 DataValidation * dataValidationBackend,
                                 NotificationTray * notificationBackend);
    ~SettingsWindowBasic();

    void setupWindowParameters(void);
    void updateButton1Details(Button1 * pButton,const QString &Title,const QString &imageLeft,const QString &imageRight);
    void updateButton2Details(Button2 * pButton,const QString &Title,const QString &imageLeft);
    void animateSettingsWindow(openCloseStatus state);
    void updateSnoozeSettings();
    void updateGoToSleepSettings();
    void updateRampTimeSettings();
    void updateSettingsBasicProcessBeforeShow(void);
    void updatePowerSavingSwitch(OnOff state);
    void updateBluetoothSwitch(OnOff state);
    void updateAeroplaneModeSwitch(OnOff state);
    void updateAuToStartTherapySwitch(OnOff state);
    void updateMaskButton(void);

    void updateBlueToothState();
    void changeEvent(QEvent* e);
    void updateText();
signals:
    void beforeStartTherapyProcedure(void);

    void sendBrightnessControlData(bool control,int level);

    void showGoToSleepScreen();

    void showRampTimeScreen();

    void showSnoozeTimeScreen();

    void showDeviceInfoScreen(QWidget *parent);

    void showBluetoothDebugScreen();

    void showBluetoothBasicScreen();

    void showDisplaySettingsScreen();

    void showMaskOptionClinicalScreen();

    void handleBlePowerOnOff(bool tState);

    void writeParameterToEeprom(void);

    void updateAirplaneModeStatus(bool state);
    void updateBluetoothStatus(bool state);

public slots:
    void goToSleepButton_released();
    void rampButton_released();
    void bluetoothButton_released();
    void displaySettingsButton_released();
    void deviceInfoButton_released();
    void autoTherapyButtonSwitch_clicked();
    void airplaneModeButtonSwitch_clicked();
    void bluetoothButtonSwitch_clicked();
    void snoozeButtonSwitch_clicked();
    void goToSleepButtonSwitch_clicked();
    void rampButtonSwitch_clicked();
    void snoozeButton_released();
    void powerSavingsButtonSwitch_clicked();
    void on_homeSettings_released();
    void maskButton_released();

    void showSettingsWindowBasic();
private slots:
    void goToSleepClosed();
    void rampClosed();
    void snoozeClosed();
    void maskButtonClosed();

    void on_pushButton_pressed();

private:
    Ui::SettingsWindow *ui;

    QPropertyAnimation * m_Anim;
    HomeWindowBasic * m_HomeWindow;
    PruControlClass * m_IpcManager;
    BrightnessControlThread * brightnessControl;
    GoToSleepSettingsBasic * gotoSleepScreen;
    RampStartSettingsBasic * rampTimeScreen;
    DeviceInfoSettingsBasic * deviceInfoScreen;
    SnoozeTimeSettingsBasic * snoozeTimeScreen;
    BluetoothSettingsBasic * bluetoothBasicScreen;
    DataValidation * dataValidation;
    NotificationTray * notificationScreen;

    Button2 * goToSleepButton;
    Button2 * rampButton;
    Button2 * autoTherapyButton;
    Button1 * maskButton;
    Button1 * tubeButton;
    Button2 * airplaneModeButton;
    Button2 * bluetoothButton;
    Button2 * snoozeButton;
    Button2 * powerSavingsButton;
    Button1 * displaySettingsButton;
    Button1 * deviceInfoButton;

    void handleAirplaneMode();
};

#endif // SETTINGSWINDOW_H
