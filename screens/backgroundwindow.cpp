#include "backgroundwindow.h"
#include "ui_backgroundwindow.h"
#include "widgets/button1.h"
#include "ex_variables.h"


BackgroundWindow::BackgroundWindow(DataValidation *pDataValidationObj, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::BackgroundWindow),
    homeScreen(nullptr),
    notificationTray(nullptr),
    clinicalHomeScreen(nullptr),
    blowerTest(nullptr),
    accessoriesWindowClinicalScreen(nullptr),
    airFilterWindowClinicalScreen(nullptr),
    airFilterWindowReminderClinicalScreen(nullptr),
    airTubeWindowReminderClinicalScreen(nullptr),
    bluetoothSettingsBasicScreen(nullptr),
    brightnessAdjustBrightnessSettingsBasicScreen(nullptr),
    comfortWindowClinicalScreen(nullptr),
    configurationWindowClinicalScreen(nullptr),
    selectLanguageWindowClinicalScreen(nullptr),
    dateWindowClinicalScreen(nullptr),
    deviceInfoSettingsBasicScreen(nullptr),
    displayDimBrightnessSettingsBasicScreen(nullptr),
    displaySettingsSettingsBasicScreen(nullptr),
    eraseDataConfigurationClinicalScreen(nullptr),
    exhalePressureComfortLevelScreen(nullptr),
    goToSleepSettingsBasicScreen(nullptr),
    maskDryOptionsBasicScreen(nullptr),
    maskFitTestOptionsBasicScreen(nullptr),
    maskOptionsBasicScreen(nullptr),
    maskWindowReminderClinicalScreen(nullptr),
    maskOptionsWindowTherapyClinicalScreen(nullptr),
    modeWindowTherapyClinicalScreen(nullptr),
    optionsWindowClinicalScreen(nullptr),
    pressureUnitConfigurationClinicalScreen(nullptr),
    rampStartSettingsBasicScreen(nullptr),
    reminderWindowSettingsClinicalScreen(nullptr),
    restoreDefaultsWindowClinicalScreen(nullptr),
    setPressureClinicalScreen(nullptr),
    setMinPressureClinicalScreen(nullptr),
    setMaxPressureClinicalScreen(nullptr),
    settingsWindowBasicScreen(nullptr),
    settingsWindowClinicalScreen(nullptr),
    sleepReportMoreWindowBasicScreen(nullptr),
    sleepReportWindowBasicScreen(nullptr),
    snoozeExitScreenBasicScreen(nullptr),
    snoozeTimeSettingsBasicScreen(nullptr),
    therapyWindowBasicScreen(nullptr),
    therapyWindowClinicalScreen(nullptr),
    timeWindowClinicalScreen(nullptr),
    enterSerialNumberScreen(nullptr),
    manuDiagnosisScreen(nullptr),
    manuSetupScreen(nullptr),
    diagDataScreen(nullptr),
    brightnessOffScreen(nullptr),
    pressureOffsetScreen(nullptr),
    flowSlopScreen(nullptr),
    parameterTuneScreen(nullptr),
    powerOffScreen(nullptr),
    passwordCheckScreen(nullptr),
    manufacturingOptionsScreen(nullptr),
    bluetoothDebugScreen(nullptr),
    activeReminderScreen(nullptr),
    resetReminderScreen(nullptr),
    sdCardFormatScreen(nullptr),
    warningInfoScreen(nullptr),
    brightnessThread(nullptr),
    pruControlClass(nullptr),
    bleInit(nullptr),
    peripheralControl(nullptr),
    consoleDev(nullptr),
    consoleOutput(nullptr),
    stage1Timer(nullptr),
    stage2Timer(nullptr),
    stage3Timer(nullptr),
    reminderTimer(nullptr),
    colorizeEffect(nullptr),
    process(nullptr),
    m_DataManager(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
//    setWindowState(Qt::WindowFullScreen);
    setFixedSize(480,272);

    globalVar.rgbColorMode = RGB_COLOR_DEVICE_IN_USE;

    /* Print On Serial Terminal */
    consoleDev = new QFile("/dev/console");
    consoleOutput = new QTextStream(consoleDev);

    QString localStr;
    localStr = QString("\n%1 v%2").arg(QApplication::applicationName()).arg(QApplication::applicationVersion());
    writeToConsole(localStr);
    localStr = QString("\nBuild Time : %1 %2").arg(__DATE__).arg(__TIME__);
    writeToConsole(localStr);

    globalVar.paramIrqNo.touchButtonIrqNo = parseAvailableIrqs("button0");
    globalVar.paramIrqNo.touchIrqNo = parseAvailableIrqs("edt-ft5306");
    globalVar.paramIrqNo.opt3001IrqNo = parseAvailableIrqs("opt3001");

    process = new QProcess(this);
    connect(process, SIGNAL(readyReadStandardOutput()), this, SLOT(printOutput()));
    connect(process, SIGNAL(readyReadStandardError()), this, SLOT(printError()));

    colorizeEffect = new QGraphicsColorizeEffect(this);
    colorizeEffect->setEnabled(0);
    setGraphicsEffect(colorizeEffect);
    colorizeEffect->setColor(WINDOW_CHILD_EFFECT_COLOR);
    colorizeEffect->setStrength(0.5);

#ifdef ENABLE_HARDWARE
    peripheralControl = new PeripheralControl(this);

    /* Shutdown disable pin and set as low/output */
    shutdownDisablePinNo = 54;
    peripheralControl->enableGpioToSysfs(shutdownDisablePinNo);
    peripheralControl->setGpioDirection(shutdownDisablePinNo,true);
    peripheralControl->setGpioState(shutdownDisablePinNo,false);

    /* Blower enable pin and set as low/output */
    blowerEnablePinNo = 20;
    peripheralControl->enableGpioToSysfs(blowerEnablePinNo);
    peripheralControl->setGpioDirection(blowerEnablePinNo,true);
    peripheralControl->setGpioState(blowerEnablePinNo,false);

    /* Blower Rest pin and set as low/output */
    blowerDriveResetPinNo = 28;
    peripheralControl->enableGpioToSysfs(blowerDriveResetPinNo);
    peripheralControl->setGpioDirection(blowerDriveResetPinNo,true);
    peripheralControl->setGpioState(blowerDriveResetPinNo,false);
#endif

    // Perform Before Application Launch Operation
    beforeApplicationLaunchChecks();

    //dataValidateClass = new DataValidation(this);
    dataValidateClass = pDataValidationObj;

    m_DataManager = new DataLogging(this,dataValidateClass);

    /* Brightness Control Thread Start */
    createBrightnessControlThread();

#ifdef ENABLE_IPC
    /* Inter processor communication Thread Start */
    createInterProcessorCommThread();
#endif

    /* Create All screen On Startup */
    createAllScreensOnStartup();

    // Default Parameters On Machine Startup
    globalVar.therapyState = Off;
    globalVar.snooze.snoozePeriod = Off;
    globalVar.maskDryState = Off;
    globalVar.maskFitTest.maskFitTestState = Off;
    globalVar.bluetooth.currentPairedDeviceIndex = 0;
    globalVar.pressure.setPressure = 0;
    globalVar.goToSleep.Auto = Off;
    globalVar.rampTime.Auto = Off;
    globalVar.sleepReportDuration = day1;
    globalVar.airplaneMode = Off;
    globalVar.sleepReportType = customSleepReport;
    globalVar.flow.slop = 240;

    globalVar.pressureUnit = cmh2o;


#ifdef _APP_DEVELOPMENT_BUILD
//    globalVar.displaySettings.autoBrightnessAdjustment = Off;
//    globalVar.displaySettings.brightnessLevel = 100;
#elif defined(_APP_PRODUCTION_BUILD)
    if(globalVar.displaySettings.autoBrightnessAdjustment == On)
            globalVar.displaySettings.brightnessLevel = 80;
#endif

//    globalVar.displaySettings.autoBrightnessAdjustment = Off;
//    globalVar.displaySettings.brightnessLevel = 100;
//    globalVar.displaySettings.displayDimDuration = 1000;

    stage1TimerTimeout();

    /* Start sdcard detection timer */
    emit startSdCardDetectionTimer();

#ifdef ENABLE_IPC
    pruControlClass->startPruProcessing();
#endif

#ifdef ENABLE_BLUETOOTH
    bleInit = new BluetoothInit(peripheralControl,shutdownDisablePinNo,bluetoothDebugScreen,m_DataManager,settingsWindowBasicScreen);
#endif

    updateEffectPointers();

    if(pruControlClass)
    {
        connect(pruControlClass,SIGNAL(autoStartDetected()),
                this,SLOT(openTherapyWindowOnAutoStartDetected()));
    }
}

BackgroundWindow::~BackgroundWindow()
{
    qDebug() << "Shutting down";
    hideAllOpenWindow();

    delete homeScreen;
    delete notificationTray;
    delete clinicalHomeScreen;
    delete blowerTest;
    delete accessoriesWindowClinicalScreen;
    delete airFilterWindowClinicalScreen;
    delete airFilterWindowReminderClinicalScreen;
    delete airTubeWindowReminderClinicalScreen;
    delete bluetoothSettingsBasicScreen;
    delete brightnessAdjustBrightnessSettingsBasicScreen;
    delete comfortWindowClinicalScreen;
    delete configurationWindowClinicalScreen;
    delete selectLanguageWindowClinicalScreen;
    delete dateWindowClinicalScreen;
    delete deviceInfoSettingsBasicScreen;
    delete displayDimBrightnessSettingsBasicScreen;
    delete displaySettingsSettingsBasicScreen;
    delete eraseDataConfigurationClinicalScreen;
    delete exhalePressureComfortLevelScreen;
    delete goToSleepSettingsBasicScreen;
    delete maskDryOptionsBasicScreen;
    delete maskFitTestOptionsBasicScreen;
    delete maskOptionsBasicScreen;
    delete maskWindowReminderClinicalScreen;
    delete maskOptionsWindowTherapyClinicalScreen;
    delete modeWindowTherapyClinicalScreen;
    delete optionsWindowClinicalScreen;
    delete pressureUnitConfigurationClinicalScreen;
    delete rampStartSettingsBasicScreen;
    delete reminderWindowSettingsClinicalScreen;
    delete restoreDefaultsWindowClinicalScreen;
    delete setPressureClinicalScreen;
    delete setMinPressureClinicalScreen;
    delete setMaxPressureClinicalScreen;
    delete settingsWindowBasicScreen;
    delete settingsWindowClinicalScreen;
    delete sleepReportMoreWindowBasicScreen;
    delete sleepReportWindowBasicScreen;
    delete snoozeExitScreenBasicScreen;
    delete snoozeTimeSettingsBasicScreen;
    delete therapyWindowBasicScreen;
    delete therapyWindowClinicalScreen;
    delete timeWindowClinicalScreen;
    delete enterSerialNumberScreen;
    delete manuDiagnosisScreen;
    delete manuSetupScreen;
    delete diagDataScreen;
    delete brightnessOffScreen;
    delete pressureOffsetScreen;
    delete flowSlopScreen;
    delete parameterTuneScreen;
    delete powerOffScreen;
    delete passwordCheckScreen;
    delete manufacturingOptionsScreen;
    delete bluetoothDebugScreen;
    delete activeReminderScreen;
    delete resetReminderScreen;
    delete sdCardFormatScreen;
    delete warningInfoScreen;
    delete brightnessThread;
    delete pruControlClass;
    delete bleInit;
    delete peripheralControl;
    delete consoleDev;
    delete consoleOutput;
    delete stage1Timer;
    delete stage2Timer;
    delete stage3Timer;
    delete reminderTimer;
    delete colorizeEffect;
    delete process;

    delete ui;
}

void BackgroundWindow::beforeApplicationLaunchChecks()
{
    //Detect Rtc HwClock
    QFile rtcDetect0("/sys/class/rtc/rtc0/name");
    if(rtcDetect0.exists())
    {
        rtcDetect0.open(QIODevice::ReadOnly);
        QString rtcSystem;
        rtcSystem = rtcDetect0.readLine();

//        writeToConsole(QString("\n%1 %2").arg(rtcSystem).arg(rtcSystem.simplified()));

        int result = QString::compare(rtcSystem.simplified(),"rtc-pcf85263",Qt::CaseInsensitive);
        if(!result)         globalVar.rtcHwClock = 0;
        else                globalVar.rtcHwClock = 1;

//        writeToConsole(QString("\nHWCLOCK : %1").arg(globalVar.rtcHwClock));
        rtcDetect0.close();
    }

}

void BackgroundWindow::showReminderScreen(void)
{
    /* Derive dates from set date & compare the date with today
     * If it is greather than 1 than display the reminder on screen
     */

    bool airFilterReminderActive=false;
    bool airTubeReminderActive=false;
    bool maskReminderActive=false;

    int expiredAirFilterDays;
    int expiredAirTubeDays;
    int expiredMaskDays;

    QDate today(QDate::currentDate());

    if(globalVar.reminder.airFilter.state == On){
        /* Derive airfilter dates */
        QDate airfilterDate(globalVar.reminder.airFilter.setStartDate.year,
                            globalVar.reminder.airFilter.setStartDate.month,
                            globalVar.reminder.airFilter.setStartDate.date);
//        QDate airfilterReminderDate = airfilterDate.addMonths(globalVar.reminder.airFilter.changeDuration);

        // For Airfilter we are checking in weeks
        QDate airfilterReminderDate = airfilterDate.addDays(globalVar.reminder.airFilter.changeDuration * 7);

        expiredAirFilterDays = airfilterReminderDate.daysTo(today);
        qDebug() << "showReminderScreen 0" << airfilterReminderDate << expiredAirFilterDays << today;
        if(expiredAirFilterDays > 0){
            /* Show Air filter expired Warning */
            airFilterReminderActive = true;
            qDebug() << "Expired Day " << expiredAirFilterDays
                     << "Set" << airfilterDate
                     << "New" << airfilterReminderDate
                     << "Today" << QDate::currentDate()
                     << "Duration" <<globalVar.reminder.airFilter.changeDuration;
        }
    }

    if(globalVar.reminder.airTube.state == On){
        /* Derive air tube dates */
        QDate airTubeDate(globalVar.reminder.airTube.setStartDate.year,
                          globalVar.reminder.airTube.setStartDate.month,
                          globalVar.reminder.airTube.setStartDate.date);
        QDate airTubeReminderDate = airTubeDate.addMonths(globalVar.reminder.airTube.changeDuration);
        expiredAirTubeDays = airTubeReminderDate.daysTo(today);
        if(expiredAirTubeDays > 0){
            /* Show Air filter expired Warning */
            airTubeReminderActive = true;
            qDebug() << "Expired Day " << expiredAirTubeDays
                     << "Set" << airTubeDate
                     << "New" << airTubeReminderDate
                     << "Today" << QDate::currentDate()
                     << "Duration" <<globalVar.reminder.airTube.changeDuration;
        }
    }

    if(globalVar.reminder.mask.state == On){
        /* Derive Mask dates */
        QDate maskDate(globalVar.reminder.mask.setStartDate.year,
                       globalVar.reminder.mask.setStartDate.month,
                       globalVar.reminder.mask.setStartDate.date);
        QDate maskReminderDate = maskDate.addMonths(globalVar.reminder.mask.changeDuration);
        expiredMaskDays = maskReminderDate.daysTo(today);
        if(expiredMaskDays > 0){
            /* Show Air filter expired Warning */
            maskReminderActive = true;
            qDebug() << "Expired Day " << expiredMaskDays
                     << "Set" << maskDate
                     << "New" << maskReminderDate
                     << "Today" << QDate::currentDate()
                     << "Duration" <<globalVar.reminder.mask.changeDuration;
        }
    }

    int totalReminders=0;
    /* Check if reminder is enabled */
    if((globalVar.reminder.mask.state == On)
            | (globalVar.reminder.airTube.state == On)
            | (globalVar.reminder.airFilter.state == On))
    {
        /* Check if any of reminder active */
        if((airFilterReminderActive == true)
                | (airTubeReminderActive == true)
                | (maskReminderActive == true))
        {
            /* Hide all text before displaying */
            activeReminderScreen->updateActiveReminderBeforeShow();

            if(airFilterReminderActive == true){
                activeReminderScreen->showAirFilterAtIndex(totalReminders);
                totalReminders++;
            }
            if(airTubeReminderActive == true){
                activeReminderScreen->showAirTubeAtIndex(totalReminders);
                totalReminders++;
            }
            if(maskReminderActive == true){
                activeReminderScreen->showMaskAtIndex(totalReminders);
                totalReminders++;
            }
            activeReminderScreen->parentEffect = getAndEnableBackgoundColorEffect();
            activeReminderScreen->setModal(true);
            activeReminderScreen->show();
        }
    }
}

void BackgroundWindow::handledirectoryChanged(const QString &path)
{
    qDebug() << "D" << path;
}
void BackgroundWindow::handleFileChanged(const QString &path)
{
    qDebug() << "F" << path;
}

void BackgroundWindow::createBrightnessControlThread(void)
{
    brightnessThread = new BrightnessControlThread;
    connect(this, SIGNAL(sendBrightnessControlData(bool,int)),
            brightnessThread,SLOT(sendBrightnessControlData(bool,int)));
    connect(brightnessThread, SIGNAL(snoozeButtonPressedDetected(int)),
            this,SLOT(snoozeButtonPressDetected(int)));
    connect(brightnessThread, SIGNAL(sendAmbientLightSensorData(float)),
            this,SLOT(manufacturingLightSensorUpdate(float)));
    connect(brightnessThread, SIGNAL(powerOffProcedureSignal()),
            this,SLOT(powerOffProcedureSlot()));
    connect(brightnessThread, SIGNAL(showHomeWindow()),
            this,SLOT(showAllWindowSlot()));
}


void BackgroundWindow::createInterProcessorCommThread(void)
{
    pruControlClass = new PruControlClass(this,m_DataManager);
    updateBlowerPwmControl();
}

int BackgroundWindow::parseAvailableIrqs(const QString & str)
{
int irqNo=0;
int localIndex=0;
    QFile parseInterrupt("/proc/interrupts");
    if(parseInterrupt.exists())
    {
        parseInterrupt.open(QIODevice::ReadOnly);
        QString availableIrqs = parseInterrupt.readAll();
        QStringList totalIrqsList = availableIrqs.split("\n");
        for(int i=0 ; i<totalIrqsList.count() ; i++)
        {
            QString currentStr = totalIrqsList.at(i);
            bool isStrContains = currentStr.contains(str);
            if(isStrContains)
            {
//                qDebug() << currentStr;
                QStringList irqListColums = currentStr.split(" ");
                if(irqListColums.at(0).isEmpty())           localIndex = 1;
                else                                        localIndex = 0;
                QString irqStr = irqListColums.at(localIndex);
                QStringList irqNoStr = irqStr.split(":");
                QString irqCode = irqNoStr.at(0);
                irqNo = irqCode.toInt();
            }
        }
        parseInterrupt.close();
    }
return irqNo;
}

void BackgroundWindow::writeToConsole(const QString & printStr)
{
//    qDebug() << printStr;

    if(consoleDev)
    {
        if(consoleDev->exists())
        {
            if(!consoleDev->isOpen())
            {
                consoleDev->open(QIODevice::WriteOnly);
                *consoleOutput << printStr;
                consoleDev->close();
            }
        }
    }
}


void BackgroundWindow::createAllScreensOnStartup(void)
{

    timeWindowClinicalScreen = new TimeWindowClinical(this);
    selectLanguageWindowClinicalScreen = new SelectLanguageWindowClinical(this,settingsWindowBasicScreen,dataValidateClass);
    dateWindowClinicalScreen = new DateWindowClinical(this);

    passwordCheckScreen = new PasswordCheckScreen(this);

    goToSleepSettingsBasicScreen = new GoToSleepSettingsBasic(this,dataValidateClass);
    rampStartSettingsBasicScreen = new RampStartSettingsBasic(this,dataValidateClass);
    exhalePressureComfortLevelScreen = new ExhalePressureComfortLevel(this,dataValidateClass);

    homeScreen = new HomeWindowBasic(this,passwordCheckScreen);

    // Create Notification Screen And update all related parameters
    notificationTray = new NotificationTray(this,pruControlClass,m_DataManager);
    notificationTray->updateAirplaneModeStatus(globalVar.airplaneMode);
    notificationTray->updateBluetoothStatus(globalVar.bluetooth.state);

    homeScreen->show();
    notificationTray->show();

    activeReminderScreen = new ActiveReminderScreen(this);
    resetReminderScreen = new ResetReminderWarning(activeReminderScreen,activeReminderScreen,dataValidateClass);
    sdCardFormatScreen = new SdCardFormatScreen(this);
}

void BackgroundWindow::stage1TimerTimeout()
{
    /* Set flag to show if any reminder needs to be displayed */
    showReminderScreen();

    snoozeExitScreenBasicScreen = new SnoozeExitScreenBasic(this,pruControlClass);
    snoozeTimeSettingsBasicScreen = new SnoozeTimeSettingsBasic(this,dataValidateClass);
    bluetoothSettingsBasicScreen = new BluetoothSettingsBasic(this);
    clinicalHomeScreen = new HomeWindowClinical(homeScreen,homeScreen);

    therapyWindowBasicScreen = new TherapyWindowBasic(homeScreen,m_DataManager,homeScreen,pruControlClass,
                                                      goToSleepSettingsBasicScreen,rampStartSettingsBasicScreen,
                                                      snoozeExitScreenBasicScreen,notificationTray);

    sleepReportWindowBasicScreen = new SleepReportWindowBasic(homeScreen,m_DataManager,homeScreen,clinicalHomeScreen);
    sleepReportMoreWindowBasicScreen = new SleepReportMoreWindowBasic(sleepReportWindowBasicScreen,m_DataManager,sleepReportWindowBasicScreen);

    // Home screen Mask options related screens
    maskDryOptionsBasicScreen = new MaskDryOptionsBasic(this,pruControlClass);
    maskFitTestOptionsBasicScreen = new MaskFitTestOptionsBasic(this);
    maskOptionsBasicScreen = new MaskOptionsBasic(homeScreen,homeScreen,maskFitTestOptionsBasicScreen,maskDryOptionsBasicScreen);

    deviceInfoSettingsBasicScreen = new DeviceInfoSettingsBasic(this);
    settingsWindowBasicScreen = new SettingsWindowBasic(homeScreen,homeScreen,pruControlClass,brightnessThread,
                                                        goToSleepSettingsBasicScreen,rampStartSettingsBasicScreen,
                                                        deviceInfoSettingsBasicScreen,snoozeTimeSettingsBasicScreen,
                                                        bluetoothSettingsBasicScreen,dataValidateClass,
                                                        notificationTray);
    bluetoothDebugScreen = new BluetoothDebugScreen(settingsWindowBasicScreen,settingsWindowBasicScreen);

    // Create brightness handling screens
    brightnessAdjustBrightnessSettingsBasicScreen = new BrightnessAdjustBrightnessSettingsBasic(this,brightnessThread,dataValidateClass);
    displayDimBrightnessSettingsBasicScreen = new DisplayDimBrightnessSettingsBasic(this,dataValidateClass);
    displaySettingsSettingsBasicScreen = new DisplaySettingsSettingsBasic(settingsWindowBasicScreen,
                                                                          brightnessAdjustBrightnessSettingsBasicScreen,
                                                                          displayDimBrightnessSettingsBasicScreen,
                                                                          settingsWindowBasicScreen);

    warningInfoScreen = new WarningInfoScreen(this,pruControlClass,therapyWindowBasicScreen);

    settingsWindowClinicalScreen = new SettingsWindowClinical(clinicalHomeScreen,clinicalHomeScreen,
                                                              deviceInfoSettingsBasicScreen,passwordCheckScreen);

    setPressureClinicalScreen = new SetPressureClinical(this,dataValidateClass);
    modeWindowTherapyClinicalScreen = new ModeWindowTherapyClinical(this,dataValidateClass);
    maskOptionsWindowTherapyClinicalScreen = new MaskOptionsTherapyWindowClinical(this,settingsWindowBasicScreen,dataValidateClass);
    setMinPressureClinicalScreen = new SetMinPressureClinical(this,dataValidateClass);
    setMaxPressureClinicalScreen = new SetMaxPressureClinical(this,dataValidateClass);
    therapyWindowClinicalScreen = new TherapyWindowClinical(settingsWindowClinicalScreen,settingsWindowClinicalScreen,
                                                            setPressureClinicalScreen,modeWindowTherapyClinicalScreen,
                                                            maskOptionsWindowTherapyClinicalScreen,setMinPressureClinicalScreen,
                                                            setMaxPressureClinicalScreen);

    comfortWindowClinicalScreen = new ComfortWindowClinical(settingsWindowClinicalScreen,goToSleepSettingsBasicScreen,
                                                            rampStartSettingsBasicScreen,exhalePressureComfortLevelScreen,
                                                            settingsWindowClinicalScreen,dataValidateClass);

    accessoriesWindowClinicalScreen = new AccessoriesWindowClinical(settingsWindowClinicalScreen,settingsWindowClinicalScreen);
    airFilterWindowClinicalScreen = new AirFilterWindowClinical(this,accessoriesWindowClinicalScreen,dataValidateClass);

    optionsWindowClinicalScreen = new OptionsWindowClinical(settingsWindowClinicalScreen,settingsWindowClinicalScreen,dataValidateClass);

    airFilterWindowReminderClinicalScreen = new AirFilterWindowReminderClinical(this,dateWindowClinicalScreen,dataValidateClass);
    airTubeWindowReminderClinicalScreen = new AirTubeWindowReminderClinical(this,dateWindowClinicalScreen,dataValidateClass);
    maskWindowReminderClinicalScreen = new MaskWindowReminderClinical(this,dateWindowClinicalScreen,dataValidateClass);
    reminderWindowSettingsClinicalScreen = new ReminderWindowSettingsClinical(settingsWindowClinicalScreen,
                                                                              settingsWindowClinicalScreen,
                                                                              airFilterWindowReminderClinicalScreen,
                                                                              airTubeWindowReminderClinicalScreen,
                                                                              maskWindowReminderClinicalScreen,dataValidateClass);

    pressureUnitConfigurationClinicalScreen = new PressureUnitConfigurationClinical(this,dataValidateClass);
    eraseDataConfigurationClinicalScreen = new EraseDataConfigurationClinical(this);
    restoreDefaultsWindowClinicalScreen = new RestoreDefaultsWindowClinical(this,dataValidateClass);
    configurationWindowClinicalScreen = new ConfigurationWindowClinical(settingsWindowClinicalScreen,selectLanguageWindowClinicalScreen,dateWindowClinicalScreen,
                                                                        timeWindowClinicalScreen,pressureUnitConfigurationClinicalScreen,
                                                                        eraseDataConfigurationClinicalScreen,restoreDefaultsWindowClinicalScreen,
                                                                        settingsWindowClinicalScreen,this,
                                                                        notificationTray);


    powerOffScreen = new PowerOffOptions(this,brightnessThread,pruControlClass,warningInfoScreen);


    diagDataScreen = new DiagnosticDataScreen(this,dataValidateClass);
    manufacturingOptionsScreen = new ManufacturingOptionsScreen(settingsWindowClinicalScreen,passwordCheckScreen,settingsWindowClinicalScreen,diagDataScreen);
    blowerTest = new BlowerTestApplication(manufacturingOptionsScreen,manufacturingOptionsScreen);
    manuDiagnosisScreen = new ManufacturingDiagnosisScreen(manufacturingOptionsScreen,pruControlClass,
                                                           manufacturingOptionsScreen);

    brightnessOffScreen = new BrightnessOffsetScreen(this);
    pressureOffsetScreen = new PressureOffsetScreen(this,pruControlClass,dataValidateClass);
    flowSlopScreen = new FlowSlopScreen(this,dataValidateClass);
    enterSerialNumberScreen = new EnterSerialNumber(this,dataValidateClass);
    manuSetupScreen = new ManufacturingSetupScreen(manufacturingOptionsScreen,brightnessOffScreen,
                                                   pressureOffsetScreen,flowSlopScreen,
                                                   enterSerialNumberScreen,
                                                   dateWindowClinicalScreen,timeWindowClinicalScreen,
                                                   manufacturingOptionsScreen,
                                                   notificationTray);
    parameterTuneScreen = new ParameterTunningScreen(manufacturingOptionsScreen,
                                                     pruControlClass,therapyWindowBasicScreen,
                                                     restoreDefaultsWindowClinicalScreen,
                                                     dataValidateClass,
                                                     manufacturingOptionsScreen);


    if(tErrorInRTC == true){
        unsigned int tLocalArry[1];
        int tIndex=1;
        tLocalArry[0] = RTC_FAULTY_ERROR;
        warningInfoScreen->processError(tLocalArry,tIndex);
    }

}

int BackgroundWindow::getAvailablePwmInstances(int * parentChip,const QString & pwmType)
{
//    QString pwmString;
//    QString detectStr;
//    pwmString =
//    QFile detectPwmChip("/sys/class/pwm/pwmchip0/device/of_node/pwm-names");
//    if(detectPwmChip.exists())
//    {
//        detectPwmChip.open(QIODevice::ReadOnly);
//        detectStr = detectPwmChip.readLine();
//        detectPwmChip.close();
//    }

//    int compareStatus = QString::compare(detectStr,"blower_control");
    return 0;
}

void BackgroundWindow::updateEffectPointers()
{
    airFilterWindowClinicalScreen->parentEffect = colorizeEffect;
    activeReminderScreen->parentEffect = colorizeEffect;
    airFilterWindowReminderClinicalScreen->parentEffect = colorizeEffect;
    airTubeWindowReminderClinicalScreen->parentEffect = colorizeEffect;
    bluetoothSettingsBasicScreen->parentEffect = colorizeEffect;
    brightnessAdjustBrightnessSettingsBasicScreen->parentEffect = colorizeEffect;
    brightnessOffScreen->parentEffect = colorizeEffect;
    selectLanguageWindowClinicalScreen->parentEffect = colorizeEffect;
    dateWindowClinicalScreen->parentEffect = colorizeEffect;
    displayDimBrightnessSettingsBasicScreen->parentEffect = colorizeEffect;
    enterSerialNumberScreen->parentEffect = colorizeEffect;
    eraseDataConfigurationClinicalScreen->parentEffect = colorizeEffect;
    exhalePressureComfortLevelScreen->parentEffect = colorizeEffect;
    flowSlopScreen->parentEffect = colorizeEffect;
    diagDataScreen->parentEffect = colorizeEffect;
    goToSleepSettingsBasicScreen->parentEffect = colorizeEffect;
    maskDryOptionsBasicScreen->parentEffect = colorizeEffect;
    maskFitTestOptionsBasicScreen->parentEffect = colorizeEffect;
    maskOptionsWindowTherapyClinicalScreen->parentEffect = colorizeEffect;
    maskWindowReminderClinicalScreen->parentEffect = colorizeEffect;
    modeWindowTherapyClinicalScreen->parentEffect = colorizeEffect;
    passwordCheckScreen->parentEffect = colorizeEffect;
    powerOffScreen->parentEffect = colorizeEffect;
    pressureOffsetScreen->parentEffect = colorizeEffect;
    pressureUnitConfigurationClinicalScreen->parentEffect = colorizeEffect;
    rampStartSettingsBasicScreen->parentEffect = colorizeEffect;
    restoreDefaultsWindowClinicalScreen->parentEffect = colorizeEffect;
    sdCardFormatScreen->parentEffect = colorizeEffect;
    setMaxPressureClinicalScreen->parentEffect = colorizeEffect;
    setMinPressureClinicalScreen->parentEffect = colorizeEffect;
    setPressureClinicalScreen->parentEffect = colorizeEffect;
    snoozeExitScreenBasicScreen->parentEffect = colorizeEffect;
    snoozeTimeSettingsBasicScreen->parentEffect = colorizeEffect;
    timeWindowClinicalScreen->parentEffect = colorizeEffect;
    warningInfoScreen->parentEffect = colorizeEffect;
}

void BackgroundWindow::updateBlowerPwmControl(void)
{
    QString detectStr;
    QFile detectPwmChip("/sys/class/pwm/pwmchip0/device/of_node/pwm-names");
    if(detectPwmChip.exists())
    {
        detectPwmChip.open(QIODevice::ReadOnly);
        detectStr = detectPwmChip.readLine();
        detectPwmChip.close();
    }

    int compareStatus = QString::compare(detectStr,"blower_control");
//    qDebug() << detectStr << compareStatus;

    if(!compareStatus)
    {
        QFile pwmChip1("/sys/class/pwm/pwmchip0/export");
        if(pwmChip1.exists()) {
            pwmChip1.open(QIODevice::WriteOnly);
            pwmChip1.write("0");
            pwmChip1.close();
        }

        QFile pwmChipPeriod("/sys/class/pwm/pwmchip0/pwm0/period");
        if(pwmChipPeriod.exists()) {
            pwmChipPeriod.open(QIODevice::WriteOnly);
            pwmChipPeriod.write("6250");
            pwmChipPeriod.close();
        }

        QFile pwmChipDutyCycle("/sys/class/pwm/pwmchip0/pwm0/duty_cycle");
        if(pwmChipDutyCycle.exists()) {
            pwmChipDutyCycle.open(QIODevice::WriteOnly);
            pwmChipDutyCycle.write("3125");
            pwmChipDutyCycle.close();
        }

        QFile pwmChipStart("/sys/class/pwm/pwmchip0/pwm0/enable");
        if(pwmChipStart.exists()) {
            pwmChipStart.open(QIODevice::WriteOnly);
            pwmChipStart.write("1");
            pwmChipStart.close();
        }
    }
}


void BackgroundWindow::IPC_sendMachineCommandToPRU(void)
{
    if(globalVar.therapyState)          globalVar.rgbColorMode = RGB_COLOR_BLOWER_RUNNING;
    else if(!globalVar.therapyState)    globalVar.rgbColorMode = RGB_COLOR_DEVICE_IN_USE;

//    ipcStr = "{" + QString::number(IPC_MACHINE_COMMAND) + "/" + QString::number(globalVar.therapyState) + "/" + QString::number(globalVar.snooze.snoozePeriod) +
//            "/" + QString::number(globalVar.maskFitTest.maskFitTestState) + "/" + QString::number(globalVar.maskDryState) + "/" + QString::number(globalVar.comfortLevel.state) + "}";
//    qDebug() << "IPC Command:" << ipcStr;

//    emit sendIPCCommunicationData(ipcStr);
}


void BackgroundWindow::snoozeButtonPressDetected(int state)
{
    (void)state;

    qDebug() << "Snooze";

    if(globalVar.therapyState == On)
    {
        if((globalVar.therapyPeriod != GoToSleep)
                & (globalVar.maskFitTest.maskFitTestState != true)
                & (globalVar.maskDryState != On)
                & (globalVar.snooze.snoozePeriod == Off))
        {
            globalVar.snooze.snoozePeriod = On;
            globalVar.snooze.isRunning = true;
            globalVar.goToSleep.isRunning = false;
            globalVar.rampTime.isRunning = false;

            globalVar.rampTime.countMinutes = 0;
            globalVar.rampTime.countSeconds = 0;
            globalVar.goToSleep.countMinutes = 0;
            globalVar.goToSleep.countSeconds = 0;

            therapyWindowBasicScreen->showHideSnoozeTimeFrame(true);
            IPC_sendMachineCommandToPRU();
            qDebug() << "Snooze Activated";

            // Enable snooze time
            pruControlClass->beforeSnoozeProcedure(1);

            /* Update snooze time required to update in therapy window */
            int tCount=0;
            tCount = globalVar.snooze.snoozeTime * 60;
//            setTherapyInitTime(tCount);
        }
        else if(globalVar.snooze.snoozePeriod == On)
        {
            qDebug() << "Snooze Exit";
            snoozeExitScreenBasicScreen->parentEffect = getAndEnableBackgoundColorEffect();
            snoozeExitScreenBasicScreen->setModal(true);
            snoozeExitScreenBasicScreen->show();
        }
    }
}

QGraphicsColorizeEffect * BackgroundWindow::getAndEnableBackgoundColorEffect(void)
{
    colorizeEffect->setEnabled(1);

return colorizeEffect;
}

void BackgroundWindow::powerOffProcedureSlot()
{
    if(globalVar.therapyState == Off)
    {
        if(powerOffScreen->isHidden())
        {
            powerOffScreen->parentEffect = getAndEnableBackgoundColorEffect();
            powerOffScreen->setModal(true);
            powerOffScreen->show();
        }
    }
}

void BackgroundWindow::manufacturingLightSensorUpdate(float luxParam)
{
    manuDiagnosisScreen->updateManufacturingScreenLuxParam(luxParam);
}


void BackgroundWindow::hideAllOpenWindow(void)
{
    if(!clinicalHomeScreen->isHidden())
        clinicalHomeScreen->hide();
    if(!blowerTest->isHidden())
        blowerTest->hide();
    if(!accessoriesWindowClinicalScreen->isHidden())
        accessoriesWindowClinicalScreen->hide();
    if(!airFilterWindowClinicalScreen->isHidden())
        airFilterWindowClinicalScreen->hide();
    if(!airFilterWindowReminderClinicalScreen->isHidden())
       airFilterWindowReminderClinicalScreen->hide();
    if(!airTubeWindowReminderClinicalScreen->isHidden())
       airTubeWindowReminderClinicalScreen->hide();
    if(!bluetoothSettingsBasicScreen->isHidden())
       bluetoothSettingsBasicScreen->hide();
    if(!brightnessAdjustBrightnessSettingsBasicScreen->isHidden())
       brightnessAdjustBrightnessSettingsBasicScreen->hide();
    if(!comfortWindowClinicalScreen->isHidden())
       comfortWindowClinicalScreen->hide();
    if(!configurationWindowClinicalScreen->isHidden())
       configurationWindowClinicalScreen->hide();
    if(!selectLanguageWindowClinicalScreen->isHidden())
       selectLanguageWindowClinicalScreen->hide();
    if(!dateWindowClinicalScreen->isHidden())
       dateWindowClinicalScreen->hide();
    if(!deviceInfoSettingsBasicScreen->isHidden())
       deviceInfoSettingsBasicScreen->hide();
    if(!displayDimBrightnessSettingsBasicScreen->isHidden())
       displayDimBrightnessSettingsBasicScreen->hide();
    if(!displaySettingsSettingsBasicScreen->isHidden())
       displaySettingsSettingsBasicScreen->hide();
    if(!eraseDataConfigurationClinicalScreen->isHidden())
       eraseDataConfigurationClinicalScreen->hide();
    if(!exhalePressureComfortLevelScreen->isHidden())
       exhalePressureComfortLevelScreen->hide();
    if(!goToSleepSettingsBasicScreen->isHidden())
       goToSleepSettingsBasicScreen->hide();
    if(!maskDryOptionsBasicScreen->isHidden())
       maskDryOptionsBasicScreen->hide();
    if(!maskFitTestOptionsBasicScreen->isHidden())
       maskFitTestOptionsBasicScreen->hide();
    if(!maskOptionsBasicScreen->isHidden())
       maskOptionsBasicScreen->hide();
    if(!maskWindowReminderClinicalScreen->isHidden())
       maskWindowReminderClinicalScreen->hide();
    if(!maskOptionsWindowTherapyClinicalScreen->isHidden())
       maskOptionsWindowTherapyClinicalScreen->hide();
    if(!modeWindowTherapyClinicalScreen->isHidden())
       modeWindowTherapyClinicalScreen->hide();
    if(!optionsWindowClinicalScreen->isHidden())
       optionsWindowClinicalScreen->hide();
    if(!pressureUnitConfigurationClinicalScreen->isHidden())
       pressureUnitConfigurationClinicalScreen->hide();
    if(!rampStartSettingsBasicScreen->isHidden())
       rampStartSettingsBasicScreen->hide();
    if(!reminderWindowSettingsClinicalScreen->isHidden())
       reminderWindowSettingsClinicalScreen->hide();
    if(!restoreDefaultsWindowClinicalScreen->isHidden())
       restoreDefaultsWindowClinicalScreen->hide();
    if(!setPressureClinicalScreen->isHidden())
       setPressureClinicalScreen->hide();
    if(!setMinPressureClinicalScreen->isHidden())
       setMinPressureClinicalScreen->hide();
    if(!setMaxPressureClinicalScreen->isHidden())
       setMaxPressureClinicalScreen->hide();
    if(!settingsWindowBasicScreen->isHidden())
       settingsWindowBasicScreen->hide();
    if(!settingsWindowClinicalScreen->isHidden())
       settingsWindowClinicalScreen->hide();
    if(!sleepReportMoreWindowBasicScreen->isHidden())
       sleepReportMoreWindowBasicScreen->hide();
    if(!sleepReportWindowBasicScreen->isHidden())
       sleepReportWindowBasicScreen->hide();
    if(!snoozeExitScreenBasicScreen->isHidden())
       snoozeExitScreenBasicScreen->hide();
    if(!snoozeTimeSettingsBasicScreen->isHidden())
       snoozeTimeSettingsBasicScreen->hide();
    if(!therapyWindowClinicalScreen->isHidden())
       therapyWindowClinicalScreen->hide();
    if(!timeWindowClinicalScreen->isHidden())
       timeWindowClinicalScreen->hide();
    if(!enterSerialNumberScreen->isHidden())
        enterSerialNumberScreen->hide();
    if(!manuDiagnosisScreen->isHidden())
       manuDiagnosisScreen->hide();
    if(!manuSetupScreen->isHidden())
       manuSetupScreen->hide();
    if(!diagDataScreen->isHidden())
       diagDataScreen->hide();
    if(!brightnessOffScreen->isHidden())
       brightnessOffScreen->hide();
    if(!parameterTuneScreen->isHidden())
       parameterTuneScreen->hide();
}

void BackgroundWindow::showAllWindowSlot()
{
    if(!therapyWindowBasicScreen->isVisible())
    {
        hideAllOpenWindow();
        homeScreen->show();
    }
}

void BackgroundWindow::openTherapyWindowOnAutoStartDetected(void)
{
    if(therapyWindowBasicScreen->isHidden())
    {
        hideAllOpenWindow();
        therapyWindowBasicScreen->animateTherapyWindow(Open);
    }
}

void BackgroundWindow::printOutput()
{
    qDebug() << "Output";
    QByteArray byteArray = process->readAllStandardOutput();
    QStringList strLines = QString(byteArray).split("\n");

    foreach (QString line, strLines){
        qDebug() << line;
    }
}

void BackgroundWindow::printError()
{
    qDebug() << "Error";
    QByteArray byteArray = process->readAllStandardError();
    QStringList strLines = QString(byteArray).split("\n");

    foreach (QString line, strLines){
        qDebug() << line;
    }
}

void BackgroundWindow::runBluetoothProcess(OnOff bluetoothState)
{
//    if(bluetoothState){
//        // Ble On
//        bleInit = new BluetoothInit;
//    } else {
//        // Ble Off
//        if(bleInit)        delete bleInit;
//    }

//    // If Bluetooth unable to start remove all of its class
//    if(bleInit->bleInitializeSuccess == false){
//        globalVar.bluetooth.state = Off;
//        delete bleInit;
//    }
}

void BackgroundWindow::runShellCommand(const QString & cmd)
{
//    process->start(cmd,argument);
    writeToConsole(QString("\n%1").arg(cmd));
    process->start(cmd);
//    process->start("echo",QStringList() << "Hello");
    process->waitForFinished();
}

void BackgroundWindow::onShutdownRequiredProcedure(void)
{
    brightnessThread->onShutdownRequiredProcedure();
}

void BackgroundWindow::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
