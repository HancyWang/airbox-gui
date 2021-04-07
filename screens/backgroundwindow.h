#ifndef BACKGROUNDWINDOW_H
#define BACKGROUNDWINDOW_H


#include <QMainWindow>
#include <QProcess>

#include "screens/accessorieswindowclinical.h"
#include "screens/airfilterwindowclinical.h"
#include "screens/airfilterwindowreminderclinical.h"
#include "screens/airtubewindowreminderclinical.h"
#include "screens/backgroundwindow.h"
#include "screens/blowertestapplication.h"
#include "screens/bluetoothsettingsbasic.h"
#include "screens/brightnessadjustbrightnesssettingsbasic.h"
#include "screens/comfortwindowclinical.h"
#include "screens/configurationwindowclinical.h"
#include "screens/selectlanguagewindowclinical.h"
#include "screens/datewindowclinical.h"
#include "screens/deviceinfosettingsbasic.h"
#include "screens/displaydimbrightnesssettingsbasic.h"
#include "screens/displaysettingssettingsbasic.h"
#include "screens/erasedataconfigurationclinical.h"
#include "screens/exhalepressurecomfortlevel.h"
#include "screens/gotosleepsettingsbasic.h"
#include "screens/homewindowbasic.h"
#include "screens/homewindowclinical.h"
#include "screens/maskoptionstherapywindowclinical.h"
#include "screens/maskdryoptionsbasic.h"
#include "screens/maskfittestoptionsbasic.h"
#include "screens/maskoptionsbasic.h"
#include "screens/maskwindowreminderclinical.h"
#include "screens/modewindowtherapyclinical.h"
#include "screens/notificationtray.h"
#include "screens/optionswindowclinical.h"
#include "screens/pressureunitconfigurationclinical.h"
#include "screens/diagnosticdatascreen.h"
#include "screens/rampstartsettingsbasic.h"
#include "screens/reminderwindowsettingsclinical.h"
#include "screens/restoredefaultswindowclinical.h"
#include "screens/setpressureclinical.h"
#include "screens/setminpressureclinical.h"
#include "screens/setmaxpressureclinical.h"
#include "screens/settingswindowbasic.h"
#include "screens/settingswindowclinical.h"
#include "screens/sleepreportmorewindowbasic.h"
#include "screens/sleepreportwindowbasic.h"
#include "screens/snoozeexitscreenbasic.h"
#include "screens/snoozetimesettingsbasic.h"
#include "screens/therapywindowbasic.h"
#include "screens/therapywindowclinical.h"
#include "screens/timewindowclinical.h"
#include "screens/manufacturingdiagnosisscreen.h"
#include "screens/manufacturingsetupscreen.h"
#include "screens/brightnessoffsetscreen.h"
#include "screens/pressureoffsetscreen.h"
#include "screens/flowslopscreen.h"
#include "screens/parametertunningscreen.h"
#include "screens/enterserialnumber.h"
#include "screens/poweroffoptions.h"
#include "screens/leakageoption.h"
#include "screens/passwordcheckscreen.h"
#include "screens/manufacturingoptionsscreen.h"
#include "screens/bluetoothdebugscreen.h"
#include "screens/activereminderscreen.h"
#include "screens/resetreminderwarning.h"
#include "screens/sdcardformatscreen.h"
#include "screens/warninginfoscreen.h"

#include "application/brightnesscontrolthread.h"
#include "application/peripheralcontrol.h"
#include "application/prucontrolclass.h"
#include "application/datavalidation.h"

#include "ble/bluetoothinit.h"




namespace Ui {
class BackgroundWindow;
}

class BackgroundWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BackgroundWindow(DataValidation *pDataValidationObj, QWidget *parent = 0);
    ~BackgroundWindow();

    void changeEvent(QEvent* e);
    void setTherapyInitTime(int tCount);
    void updateMonitoringParameter(void);

    void updateBlowerPwmControl(void);
    void IPC_sendSetDataToPRU(void);
    void IPC_sendMachineCommandToPRU(void);
    void IPC_sendManufacturingControlCommand(int manuFactMode,int blowerState,int blowerSpeed);
    void createAllScreensOnStartup(void);
    void IPC_sendNeedMachineOffsetToPRU(void);
    void writeToConsole(const QString & printStr);
    void IPC_sendTuneParameterToPRU(unsigned int * param);
    void runShellCommand(const QString & cmd);
    int parseAvailableIrqs(const QString & str);
    void createBrightnessControlThread(void);
    void createInterProcessorCommThread(void);
    void beforeApplicationLaunchChecks(void);
    QGraphicsColorizeEffect * getAndEnableBackgoundColorEffect(void);
    int getAvailablePwmInstances(int * parentChip,const QString & pwmType);
    void hideAllOpenWindow(void);
    void runBluetoothProcess(OnOff bluetoothState);
    void showReminderScreen(void);
    void onShutdownRequiredProcedure(void);

    QString ipcStr;
    QProcess * process;


    DataValidation * dataValidateClass;
    HomeWindowBasic * homeScreen;
    NotificationTray * notificationTray;
    HomeWindowClinical * clinicalHomeScreen;
    BlowerTestApplication * blowerTest;
    AccessoriesWindowClinical * accessoriesWindowClinicalScreen;
    AirFilterWindowClinical * airFilterWindowClinicalScreen;
    AirFilterWindowReminderClinical * airFilterWindowReminderClinicalScreen;
    AirTubeWindowReminderClinical * airTubeWindowReminderClinicalScreen;
    BluetoothSettingsBasic * bluetoothSettingsBasicScreen;
    BrightnessAdjustBrightnessSettingsBasic * brightnessAdjustBrightnessSettingsBasicScreen;
    ComfortWindowClinical * comfortWindowClinicalScreen;
    ConfigurationWindowClinical * configurationWindowClinicalScreen;
    SelectLanguageWindowClinical * selectLanguageWindowClinicalScreen;
    DateWindowClinical * dateWindowClinicalScreen;
    DeviceInfoSettingsBasic * deviceInfoSettingsBasicScreen;
    DisplayDimBrightnessSettingsBasic * displayDimBrightnessSettingsBasicScreen;
    DisplaySettingsSettingsBasic * displaySettingsSettingsBasicScreen;
    EraseDataConfigurationClinical * eraseDataConfigurationClinicalScreen;
    ExhalePressureComfortLevel * exhalePressureComfortLevelScreen;
    GoToSleepSettingsBasic * goToSleepSettingsBasicScreen;
    MaskDryOptionsBasic * maskDryOptionsBasicScreen;
    MaskFitTestOptionsBasic * maskFitTestOptionsBasicScreen;
    MaskOptionsBasic * maskOptionsBasicScreen;
    MaskWindowReminderClinical * maskWindowReminderClinicalScreen;
    MaskOptionsTherapyWindowClinical * maskOptionsWindowTherapyClinicalScreen;
    ModeWindowTherapyClinical * modeWindowTherapyClinicalScreen;
    OptionsWindowClinical * optionsWindowClinicalScreen;
    PressureUnitConfigurationClinical * pressureUnitConfigurationClinicalScreen;
    RampStartSettingsBasic * rampStartSettingsBasicScreen;
    ReminderWindowSettingsClinical * reminderWindowSettingsClinicalScreen;
    RestoreDefaultsWindowClinical * restoreDefaultsWindowClinicalScreen;
    SetPressureClinical * setPressureClinicalScreen;
    SetMinPressureClinical * setMinPressureClinicalScreen;
    SetMaxPressureClinical * setMaxPressureClinicalScreen;
    SettingsWindowBasic * settingsWindowBasicScreen;
    SettingsWindowClinical * settingsWindowClinicalScreen;
    SleepReportMoreWindowBasic * sleepReportMoreWindowBasicScreen;
    SleepReportWindowBasic * sleepReportWindowBasicScreen;
    SnoozeExitScreenBasic * snoozeExitScreenBasicScreen;
    SnoozeTimeSettingsBasic * snoozeTimeSettingsBasicScreen;
    TherapyWindowBasic * therapyWindowBasicScreen;
    TherapyWindowClinical * therapyWindowClinicalScreen;
    TimeWindowClinical * timeWindowClinicalScreen;
    EnterSerialNumber * enterSerialNumberScreen;

    ManufacturingDiagnosisScreen * manuDiagnosisScreen;
    ManufacturingSetupScreen * manuSetupScreen;
    DiagnosticDataScreen * diagDataScreen;
    BrightnessOffsetScreen * brightnessOffScreen;
    PressureOffsetScreen * pressureOffsetScreen;
    FlowSlopScreen * flowSlopScreen;
    ParameterTunningScreen * parameterTuneScreen;
    PowerOffOptions * powerOffScreen;
    LeakageOption*  leakageScreen;
    PasswordCheckScreen * passwordCheckScreen;
    ManufacturingOptionsScreen * manufacturingOptionsScreen;
    BluetoothDebugScreen * bluetoothDebugScreen;
    ActiveReminderScreen * activeReminderScreen;
    ResetReminderWarning * resetReminderScreen;
    SdCardFormatScreen * sdCardFormatScreen;
    WarningInfoScreen * warningInfoScreen;

    //Threads
    BrightnessControlThread * brightnessThread;
    PruControlClass * pruControlClass;

    BluetoothInit * bleInit;
    PeripheralControl * peripheralControl;

    DataLogging * m_DataManager;

    int blowerEnablePinNo=0;
    int shutdownDisablePinNo=0;
    int blowerDriveResetPinNo=0;

    bool tErrorInRTC=false;

signals:
    //IPC Thread Signals
    void startStopStateChanged_toThread(int state,int setRpm,int rampTime);
    void sendSetParameters_toThread(int setRpm);
    void sendBrakeSignal_toThread(int type,int intensity);
    void sendIPCCommunicationData(const QString & str);
    void sendManufacturingModeChanged(bool manufModeState);

    //Brightness Control Signals
    void sendBrightnessControlData(bool control,int level);

    void startSdCardDetectionTimer(void);

public slots:
    void snoozeButtonPressDetected(int state);

    void printOutput();
    void printError();

    void stage1TimerTimeout();
    void handledirectoryChanged(const QString & path);
    void handleFileChanged(const QString & path);

    void manufacturingLightSensorUpdate(float luxParam);
    void powerOffProcedureSlot();
    void showAllWindowSlot();

    void updateEffectPointers();

    void openTherapyWindowOnAutoStartDetected(void);

private:
    Ui::BackgroundWindow *ui;

    QFile * consoleDev;
    QTextStream * consoleOutput;
    QTimer * stage1Timer;
    QTimer * stage2Timer;
    QTimer * stage3Timer;
    QTimer * reminderTimer;
    QGraphicsColorizeEffect * colorizeEffect;

    unsigned int tTimeIndex=0;


};

#endif // BACKGROUNDWINDOW_H
