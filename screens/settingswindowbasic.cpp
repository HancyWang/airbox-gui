#include "settingswindowbasic.h"
#include "ui_settingswindowbasic.h"
#include "constants.h"
#include "ex_variables.h"


SettingsWindowBasic::SettingsWindowBasic(QWidget *parent,
                                         HomeWindowBasic * m_HomeWindowBackend,
                                         PruControlClass * m_IpcBackend,
                                         BrightnessControlThread * brightnessBackend,
                                         GoToSleepSettingsBasic * gotoSleepBackend,
                                         RampStartSettingsBasic * rampTimeBackend,
                                         DeviceInfoSettingsBasic * deviceInfoBackend,
                                         SnoozeTimeSettingsBasic * snoozeTimeBackend,
                                         BluetoothSettingsBasic * bluetoothBasicBackend,
                                         DataValidation * dataValidationBackend,
                                         NotificationTray * notificationBackend)
    : QDialog(parent),
    ui(new Ui::SettingsWindow),
    m_Anim(nullptr),
    m_HomeWindow(m_HomeWindowBackend),
    m_IpcManager(m_IpcBackend),
    brightnessControl(brightnessBackend),
    gotoSleepScreen(gotoSleepBackend),
    rampTimeScreen(rampTimeBackend),
    deviceInfoScreen(deviceInfoBackend),
    snoozeTimeScreen(snoozeTimeBackend),
    bluetoothBasicScreen(bluetoothBasicBackend),
    dataValidation(dataValidationBackend),
    notificationScreen(notificationBackend),
    goToSleepButton(nullptr),
    rampButton(nullptr),
    autoTherapyButton(nullptr),
    maskButton(nullptr),
    tubeButton(nullptr),
    airplaneModeButton(nullptr),
    bluetoothButton(nullptr),
    snoozeButton(nullptr),
    powerSavingsButton(nullptr),
    displaySettingsButton(nullptr),
    deviceInfoButton(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setWindowState(Qt::WindowFullScreen);
    setGeometry(0,0,width(),height());

    QFont title("Roboto-Light",12);
    ui->titleSettings->setFont(title);

    m_Anim = new QPropertyAnimation(this,"geometry");
    if(m_HomeWindow)
    {
        connect(m_HomeWindow,SIGNAL(showSettingsWindowBasic()),this,SLOT(showSettingsWindowBasic()));
    }

    if(m_IpcManager)
    {
        connect(this,SIGNAL(beforeStartTherapyProcedure()),
                m_IpcManager,SLOT(beforeStartTherapyProcedure()));
    }

    if(brightnessControl)
    {
        connect(this, SIGNAL(sendBrightnessControlData(bool,int)),
                brightnessControl,SLOT(sendBrightnessControlData(bool,int)));
    }
    if(gotoSleepScreen)
    {
        connect(this,SIGNAL(showGoToSleepScreen()),
                gotoSleepScreen,SLOT(showGoToSleepScreen()));
    }
    if(rampTimeScreen)
    {
        connect(this,SIGNAL(showRampTimeScreen()),
                rampTimeScreen,SLOT(showRampTimeScreen()));
    }
    if(deviceInfoScreen)
    {
        connect(this,SIGNAL(showDeviceInfoScreen(QWidget*)),
                deviceInfoScreen,SLOT(showDeviceInfoScreen(QWidget*)));
    }
    if(snoozeTimeScreen)
    {
        connect(this,SIGNAL(showSnoozeTimeScreen()),
                snoozeTimeScreen,SLOT(showSnoozeTimeScreen()));
    }

    if(bluetoothBasicScreen)
    {
        connect(this,SIGNAL(showBluetoothBasicScreen()),
                bluetoothBasicScreen,SLOT(showBluetoothBasicScreen()));
    }

    if(dataValidation)
    {
        connect(this,SIGNAL(writeParameterToEeprom()),
                dataValidation,SLOT(writeParameterToEeprom()));
    }

    if(notificationScreen)
    {
        connect(this,SIGNAL(updateAirplaneModeStatus(bool)),
                notificationScreen,SLOT(updateAirplaneModeStatus(bool)));
        connect(this,SIGNAL(updateBluetoothStatus(bool)),
                notificationScreen,SLOT(updateBluetoothStatus(bool)));
    }


    setupWindowParameters();

    snoozeButton->hide();

    // Check if we should diplay the engineering data
    if(globalVar.diagnosticData == On)
    {
        ui->pushButton->show();
    }
    else
    {
        ui->pushButton->hide();
    }
}

SettingsWindowBasic::~SettingsWindowBasic()
{
    delete ui;
}

void SettingsWindowBasic::showSettingsWindowBasic(void)
{
    updateSettingsBasicProcessBeforeShow();
    animateSettingsWindow(Open);
}

void SettingsWindowBasic::updateButton1Details(Button1 * pButton,const QString &Title,const QString &imageLeft,const QString &imageRight)
{
    QFont settingsFontTitle("Roboto-Light", 8);
    QFont settingsFontSubTitle("Roboto-Thin", 14);
    QFont setingsFontUnit("Roboto-Light",7);

    pButton->setButtonRadius(5);
    pButton->setTitle(Title,settingsFontTitle,QColor(0xBDBDBD));
    pButton->setSubTitle(NULL,settingsFontSubTitle,QColor(0x2196F3));
    pButton->setUnit(NULL,setingsFontUnit,QColor(0x616161));
    pButton->setBackgroundColor(0x606060,0x3e3e3e);
    pButton->setLeftRightSpacing(50,50);
    pButton->setImageLeft(0,5,24,24,imageLeft);
    pButton->setImageRight(50,10,24,24,imageRight);
    pButton->setFixedHeight(56);
    pButton->setFixedWidth(350);

    ui->verticalLayoutSettings->addWidget(pButton);
}

void SettingsWindowBasic::updateButton2Details(Button2 * pButton,const QString &Title,const QString &imageLeft)
{
    QFont settingsFontTitle("Roboto-Light", 8);
    QFont settingsFontSubTitle("Roboto-Thin", 14);
    QFont fontUnit("Roboto-Light",7);

    ui->verticalLayoutSettings->addWidget(pButton);
    pButton->setButtonRadius(5);
    pButton->setFixedHeight(56);
    pButton->setFixedWidth(350);
    pButton->setTitle(Title,settingsFontTitle,QColor(0xBDBDBD));
    pButton->setSubTitle(NULL,settingsFontSubTitle,QColor(0x2196F3));
    pButton->setUnit(NULL,fontUnit,QColor(0x616161));
    pButton->setBackgroundColor(0x606060,0x3e3e3e);
    pButton->setLeftRightSpacing(50,80);
    pButton->setSwitchHeightWidth(60,30);
    pButton->setImageLeft(0,5,24,24,imageLeft);
}

void SettingsWindowBasic::setupWindowParameters(void)
{
    goToSleepButton         = new Button2(this);
    rampButton              = new Button2(this);
    autoTherapyButton       = new Button2(this);
    maskButton              = new Button1(this);
    tubeButton              = new Button1(this);
    airplaneModeButton      = new Button2(this);
    bluetoothButton         = new Button2(this);
    snoozeButton            = new Button2(this);
    powerSavingsButton      = new Button2(this);
    displaySettingsButton   = new Button1(this);
    deviceInfoButton        = new Button1(this);

    ui->scrollAreaWidgetContentsSettings->setLayout(ui->verticalLayoutSettings);
    ui->scrollAreaSettings->setStyleSheet(QStringLiteral("border:none;"));

    updateButton2Details(goToSleepButton        ,Providers::getTitleTextString(GO_TO_SLEEP_STR),
                         Providers::getIconString(GO_TO_SLEEP_ICON));
    updateButton2Details(rampButton             ,Providers::getTitleTextString(RAMP_STR),
                         Providers::getIconString(RAMP_ICON));
    updateButton2Details(autoTherapyButton      ,Providers::getTitleTextString(AUTO_START_THERAPY_STR),
                         Providers::getIconString(AUTO_START_THERAPY_ICON));
    updateButton1Details(maskButton             ,Providers::getTitleTextString(MASK_STR),
                         Providers::getIconString(MASK_ICON),Providers::getNavigationIconString());
    updateButton1Details(tubeButton             ,Providers::getTitleTextString(TUBE_STR),
                         Providers::getIconString(TUBE_ICON),NULL);
    updateButton2Details(airplaneModeButton     ,Providers::getTitleTextString(AIRPLANE_MODE_STR),
                         Providers::getIconString(AIRPLANE_MODE_ICON));
    updateButton2Details(bluetoothButton        ,Providers::getTitleTextString(BLUETOOTH_STR),
                         Providers::getIconString(BLUETOOTH_ICON));
    updateButton2Details(snoozeButton           ,Providers::getTitleTextString(SNOOZE_STR),
                         Providers::getIconString(SNOOZE_ICON));
    updateButton2Details(powerSavingsButton     ,Providers::getTitleTextString(POWER_SAVINGS_STR),
                         Providers::getIconString(POWER_SAVINGS_ICON));
    updateButton1Details(displaySettingsButton  ,Providers::getTitleTextString(DISPLAY_SETTINGS_STR),
                         Providers::getIconString(DISPLAY_SETTINGS_ICON),Providers::getNavigationIconString());
    updateButton1Details(deviceInfoButton       ,Providers::getTitleTextString(DEVICE_INFO_STR),
                         Providers::getIconString(DEVICE_INFO_ICON),Providers::getNavigationIconString());


    //Enable Scrolling mechanism for scroll area
    QScroller::grabGesture(ui->scrollAreaSettings->viewport(),QScroller::LeftMouseButtonGesture);

    //Connect all press or release eventas to their specific slots
    connect(goToSleepButton, SIGNAL(released()),SLOT(goToSleepButton_released()));
    connect(rampButton, SIGNAL(released()),SLOT(rampButton_released()));
    connect(bluetoothButton, SIGNAL(released()),SLOT(bluetoothButton_released()));
    connect(displaySettingsButton, SIGNAL(released()),SLOT(displaySettingsButton_released()));
    connect(deviceInfoButton, SIGNAL(released()),SLOT(deviceInfoButton_released()));
    connect(snoozeButton, SIGNAL(released()),SLOT(snoozeButton_released()));
    connect(maskButton, SIGNAL(released()),SLOT(maskButton_released()));

    connect(goToSleepButton->switchWidget, SIGNAL(toggleSwitchClicked()),SLOT(goToSleepButtonSwitch_clicked()));
    connect(rampButton->switchWidget, SIGNAL(toggleSwitchClicked()),SLOT(rampButtonSwitch_clicked()));
    connect(autoTherapyButton->switchWidget, SIGNAL(toggleSwitchClicked()),SLOT(autoTherapyButtonSwitch_clicked()));
    connect(airplaneModeButton->switchWidget, SIGNAL(toggleSwitchClicked()),SLOT(airplaneModeButtonSwitch_clicked()));
    connect(bluetoothButton->switchWidget, SIGNAL(toggleSwitchClicked()),SLOT(bluetoothButtonSwitch_clicked()));
    connect(snoozeButton->switchWidget, SIGNAL(toggleSwitchClicked()),SLOT(snoozeButtonSwitch_clicked()));
    connect(powerSavingsButton->switchWidget, SIGNAL(toggleSwitchClicked()),SLOT(powerSavingsButtonSwitch_clicked()));

    tubeButton->updateSubTitleText(QString("%1 mm").arg(HOSE_SIZE_MM));

    snoozeButton->updateUnitText(Providers::getUnitTextString(MINUTE_UNIT_STR));
    goToSleepButton->updateUnitText(Providers::getUnitTextString(MINUTE_UNIT_STR));
    rampButton->updateUnitText(Providers::getUnitTextString(MINUTE_UNIT_STR));

    updateSettingsBasicProcessBeforeShow();
}
void SettingsWindowBasic::updateSnoozeSettings()
{
    if(globalVar.snooze.state == On){
        QString snzStr = QString::number(globalVar.snooze.snoozeTime);
        snoozeButton->updateSubTitleText(snzStr);
        snoozeButton->setUnitVisibility(true);
    } else {
        snoozeButton->updateSubTitleText(Providers::getOnOffStr(globalVar.snooze.state));
        snoozeButton->setUnitVisibility(false);
    }
}
void SettingsWindowBasic::updateGoToSleepSettings()
{
    if(globalVar.goToSleep.state == On){
        if(globalVar.goToSleep.Auto == On){
            goToSleepButton->updateSubTitleText(Providers::getAutoStr());
            goToSleepButton->setUnitVisibility(false);
        } else {
            QString gtsStr = QString::number(globalVar.goToSleep.goToSleepTime);
            goToSleepButton->updateSubTitleText(gtsStr);
            goToSleepButton->setUnitVisibility(true);
        }
    } else {
        goToSleepButton->updateSubTitleText(Providers::getOnOffStr(globalVar.goToSleep.state));
        goToSleepButton->setUnitVisibility(false);
    }
}
void SettingsWindowBasic::updateRampTimeSettings()
{
    if(globalVar.rampTime.state == On){
        if(globalVar.rampTime.Auto == On){
            rampButton->updateSubTitleText(Providers::getAutoStr());
            rampButton->setUnitVisibility(false);
        } else {
            QString gtsStr = QString::number(globalVar.rampTime.rampTime);
            rampButton->updateSubTitleText(gtsStr);
            rampButton->setUnitVisibility(true);
        }
    } else {
        rampButton->updateSubTitleText(Providers::getOnOffStr(globalVar.rampTime.state));
        rampButton->setUnitVisibility(false);
    }
}
void SettingsWindowBasic::updateSettingsBasicProcessBeforeShow(void)
{
    updateSnoozeSettings();
    updateGoToSleepSettings();
    updateRampTimeSettings();
    updateMaskButton();

    powerSavingsButton->switchWidget->setSwitchState(globalVar.powerSavings);
    airplaneModeButton->switchWidget->setSwitchState(globalVar.airplaneMode);
    autoTherapyButton->switchWidget->setSwitchState(globalVar.autoStartTherapy);

    updatePowerSavingSwitch(globalVar.powerSavings);
    updateAeroplaneModeSwitch(globalVar.airplaneMode);
    updateAuToStartTherapySwitch(globalVar.autoStartTherapy);

//    bluetoothButton->switchWidget->setSwitchState(globalVar.bluetooth.state);
//    updateBluetoothSwitch(globalVar.bluetooth.state);

    snoozeButton->switchWidget->setSwitchState(globalVar.snooze.state);
    goToSleepButton->switchWidget->setSwitchState(globalVar.goToSleep.state);
    rampButton->switchWidget->setSwitchState(globalVar.rampTime.state);

    QScrollBar * tScrollBar = ui->scrollAreaSettings->verticalScrollBar();
    tScrollBar->setValue(0);

    handleAirplaneMode();
}

void SettingsWindowBasic::animateSettingsWindow(openCloseStatus state)
{
    if (state) {
        this->show();
        m_Anim->setStartValue(QRect(480, 0, 480, 272));
        m_Anim->setEndValue(QRect(0, 0, 480, 272));
        m_Anim->setDuration(WINDOW_ANIMATION_OPEN_DURATION);
        m_Anim->setEasingCurve(WINDOW_OPEN_TRANSITION);
        connect(m_Anim, SIGNAL(finished()),SLOT(show()));
    } else {
        m_Anim->setStartValue(QRect(0, 0, 480, 272));
        m_Anim->setEndValue(QRect(480, 0, 480, 272));
        m_Anim->setDuration(WINDOW_ANIMATION_CLOSE_DURATION);
        m_Anim->setEasingCurve(WINDOW_CLOSE_TRANSITION);
        connect(m_Anim, SIGNAL(finished()),SLOT(hide()));
    }
    m_Anim->start();
}

void SettingsWindowBasic::goToSleepButton_released()
{
    if(globalVar.goToSleep.state == On)
    {
        connect(gotoSleepScreen, SIGNAL(dialogClose()),
                this,SLOT(goToSleepClosed()));

        emit showGoToSleepScreen();
    }
}

void SettingsWindowBasic::goToSleepClosed()
{
    updateGoToSleepSettings();
    disconnect(gotoSleepScreen, SIGNAL(dialogClose()),0,0);
}

void SettingsWindowBasic::rampButton_released()
{
    if(globalVar.rampTime.state == On)
    {
        connect(rampTimeScreen, SIGNAL(dialogClose()),
                this,SLOT(rampClosed()));

        emit showRampTimeScreen();
    }
}

void SettingsWindowBasic::rampClosed()
{
    updateRampTimeSettings();
    disconnect(rampTimeScreen, SIGNAL(dialogClose()),0,0);
}


void SettingsWindowBasic::bluetoothButton_released()
{
    if(globalVar.bluetooth.state == On)
    {
//        emit showBluetoothBasicScreen();
    }
}

void SettingsWindowBasic::displaySettingsButton_released()
{
    emit showDisplaySettingsScreen();
}

void SettingsWindowBasic::deviceInfoButton_released()
{
    emit showDeviceInfoScreen(this);
}
void SettingsWindowBasic::autoTherapyButtonSwitch_clicked()
{

    globalVar.autoStartTherapy = static_cast<OnOff>(!globalVar.autoStartTherapy);
    updateAuToStartTherapySwitch(globalVar.autoStartTherapy);

    // Update Data to EEPROM
    emit writeParameterToEeprom();
    emit beforeStartTherapyProcedure();
}

void SettingsWindowBasic::airplaneModeButtonSwitch_clicked()
{
    globalVar.airplaneMode = static_cast<OnOff>(airplaneModeButton->switchWidget->getSwitchState());
    updateAeroplaneModeSwitch(globalVar.airplaneMode);
    emit updateAirplaneModeStatus(globalVar.airplaneMode);

    handleAirplaneMode();
}

void SettingsWindowBasic::handleAirplaneMode(void)
{
    if(globalVar.airplaneMode == On)
    {
        globalVar.bluetooth.state = Off;
    }

    bluetoothButton->switchWidget->setSwitchState(globalVar.bluetooth.state);
    updateBlueToothState();
}

void SettingsWindowBasic::updateBlueToothState()
{
    emit handleBlePowerOnOff(globalVar.bluetooth.state);

    updateBluetoothSwitch(globalVar.bluetooth.state);
    emit updateBluetoothStatus(globalVar.bluetooth.state);
}

void SettingsWindowBasic::bluetoothButtonSwitch_clicked()
{
    globalVar.bluetooth.state = static_cast<OnOff>(bluetoothButton->switchWidget->getSwitchState());

    handleAirplaneMode();

    // Update Data to EEPROM
    emit writeParameterToEeprom();
}

void SettingsWindowBasic::snoozeButton_released()
{
    if(globalVar.snooze.state == On)
    {
        connect(snoozeTimeScreen, SIGNAL(dialogClose()),
                this,SLOT(snoozeClosed()));

        emit showSnoozeTimeScreen();
    }
}

void SettingsWindowBasic::snoozeClosed()
{
    updateSnoozeSettings();
    disconnect(snoozeTimeScreen, SIGNAL(dialogClose()),0,0);
}

void SettingsWindowBasic::snoozeButtonSwitch_clicked()
{
    globalVar.snooze.state = static_cast<OnOff>(snoozeButton->switchWidget->getSwitchState());
    updateSnoozeSettings();
    // Update Data to EEPROM
    emit writeParameterToEeprom();
}

void SettingsWindowBasic::on_homeSettings_released()
{
    animateSettingsWindow(Close);
}

void SettingsWindowBasic::goToSleepButtonSwitch_clicked()
{
    globalVar.goToSleep.state = static_cast<OnOff>(goToSleepButton->switchWidget->getSwitchState());
    updateGoToSleepSettings();
    // Update Data to EEPROM
    emit writeParameterToEeprom();
}

void SettingsWindowBasic::rampButtonSwitch_clicked()
{
    globalVar.rampTime.state = static_cast<OnOff>(rampButton->switchWidget->getSwitchState());
    updateRampTimeSettings();
    // Update Data to EEPROM
    emit writeParameterToEeprom();
}

void SettingsWindowBasic::powerSavingsButtonSwitch_clicked()
{
    globalVar.powerSavings = static_cast<OnOff>(powerSavingsButton->switchWidget->getSwitchState());
    updatePowerSavingSwitch(globalVar.powerSavings);

    // Update Data to EEPROM
    emit writeParameterToEeprom();
}

void SettingsWindowBasic::updatePowerSavingSwitch(OnOff state)
{
    powerSavingsButton->updateSubTitleText(Providers::getOnOffStr(state));
    if(globalVar.powerSavings == On)
    {
//        globalVar.displaySettings.autoBrightnessAdjustment = Off;
//        globalVar.displaySettings.brightnessLevel = BRIGHTNESS_LEVEL_MIN;
        emit sendBrightnessControlData(Off,BRIGHTNESS_LEVEL_MIN);
        displaySettingsButton->setVisible(false);
    }
    else
    {
        emit sendBrightnessControlData(globalVar.displaySettings.autoBrightnessAdjustment,
                                          globalVar.displaySettings.brightnessLevel);
        displaySettingsButton->setVisible(true);
    }
}

void SettingsWindowBasic::updateBluetoothSwitch(OnOff state)
{
    bluetoothButton->updateSubTitleText(Providers::getOnOffStr(state));
}

void SettingsWindowBasic::updateAeroplaneModeSwitch(OnOff state)
{
    airplaneModeButton->updateSubTitleText(Providers::getOnOffStr(state));
}

void SettingsWindowBasic::updateAuToStartTherapySwitch(OnOff state)
{
    autoTherapyButton->updateSubTitleText(Providers::getOnOffStr(state));
}

void SettingsWindowBasic::maskButton_released()
{
    emit showMaskOptionClinicalScreen();
}

void SettingsWindowBasic::maskButtonClosed()
{
    updateMaskButton();
}

void SettingsWindowBasic::updateMaskButton(void)
{
    maskButton->updateSubTitleText(Providers::getMaskTypeString(globalVar.maskType));
}

void SettingsWindowBasic::on_pushButton_pressed()
{
    //TODO Open Bluetooth debug screen
    emit showBluetoothDebugScreen();
}

void SettingsWindowBasic::updateText()
{

    updateSnoozeSettings();
    updateGoToSleepSettings();
    updateRampTimeSettings();
    updateMaskButton();


    QFont settingsFontTitle("Roboto-Light", 8);

    goToSleepButton->setTitle(Providers::getTitleTextString(GO_TO_SLEEP_STR),settingsFontTitle,QColor(0xBDBDBD));
    rampButton->setTitle(Providers::getTitleTextString(RAMP_STR),settingsFontTitle,QColor(0xBDBDBD));
    autoTherapyButton->setTitle(Providers::getTitleTextString(AUTO_START_THERAPY_STR),settingsFontTitle,QColor(0xBDBDBD));
    maskButton->setTitle(Providers::getTitleTextString(MASK_STR),settingsFontTitle,QColor(0xBDBDBD));
    tubeButton->setTitle(Providers::getTitleTextString(TUBE_STR),settingsFontTitle,QColor(0xBDBDBD));
    airplaneModeButton->setTitle(Providers::getTitleTextString(AIRPLANE_MODE_STR),settingsFontTitle,QColor(0xBDBDBD));
    bluetoothButton->setTitle(Providers::getTitleTextString(BLUETOOTH_STR),settingsFontTitle,QColor(0xBDBDBD));
    snoozeButton->setTitle(Providers::getTitleTextString(SNOOZE_STR),settingsFontTitle,QColor(0xBDBDBD));
    powerSavingsButton->setTitle(Providers::getTitleTextString(POWER_SAVINGS_STR),settingsFontTitle,QColor(0xBDBDBD));
    displaySettingsButton->setTitle(Providers::getTitleTextString(DISPLAY_SETTINGS_STR),settingsFontTitle,QColor(0xBDBDBD));
    deviceInfoButton->setTitle(Providers::getTitleTextString(DEVICE_INFO_STR),settingsFontTitle,QColor(0xBDBDBD));
}

void SettingsWindowBasic::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        updateText();
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
