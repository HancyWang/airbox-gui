#include "comfortwindowclinical.h"
#include "ui_comfortwindowclinical.h"
#include "ex_variables.h"



const QStringList ComfortWindowClinical::exhaleLevel =
{
    "Wrong Level" ,
    "Level 1" ,
    "Level 2" ,
    "Level 3"
};

ComfortWindowClinical::ComfortWindowClinical(QWidget *parent,
                                             GoToSleepSettingsBasic * gotosleepBackend,
                                             RampStartSettingsBasic * rampTimeBackend,
                                             ExhalePressureComfortLevel * exhaleComfortBackend,
                                             SettingsWindowClinical * settingsClinicalBackend,
                                             DataValidation * dataValidationBackend)
    : QDialog(parent),
    ui(new Ui::ComfortWindowClinical),
    gotosleepScreen(gotosleepBackend),
    rampTimeScreen(rampTimeBackend),
    exhaleComfortScreen(exhaleComfortBackend),
    settingsClinicalScreen(settingsClinicalBackend),
    dataValidation(dataValidationBackend),
    m_Anim(nullptr),
    goToSleepButton(nullptr),
    rampButton(nullptr),
    exhaleComfortButton(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setWindowState(Qt::WindowFullScreen);
    setGeometry(0,0,width(),height());

    if(gotosleepScreen)
    {
        connect(this,SIGNAL(showGoToSleepScreen()),
                gotosleepScreen,SLOT(showGoToSleepScreen()));
    }

    if(rampTimeScreen)
    {
        connect(this,SIGNAL(showRampTimeScreen()),
                rampTimeScreen,SLOT(showRampTimeScreen()));
    }

    if(exhaleComfortScreen)
    {
        connect(this,SIGNAL(showExhaleComfortScreen()),
                exhaleComfortScreen,SLOT(showExhaleComfortScreen()));
    }

    if(settingsClinicalScreen)
    {
        connect(settingsClinicalScreen,SIGNAL(showComfortClinicalScreen()),
                this,SLOT(showComfortClinicalScreen()));
    }

    if(dataValidation)
    {
        connect(this,SIGNAL(writeParameterToEeprom()),
                dataValidation,SLOT(writeParameterToEeprom()));
    }

    QFont title("Roboto-Light",12);
    ui->titleComfort->setFont(title);

    m_Anim = new QPropertyAnimation(this,"geometry");

    addButtons();
}

ComfortWindowClinical::~ComfortWindowClinical()
{
    delete ui;
}

void ComfortWindowClinical::animateSettingsWindow(openCloseStatus state)
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

void ComfortWindowClinical::addButtons(void)
{
    goToSleepButton = new Button2(this);
    rampButton = new Button2(this);
    exhaleComfortButton = new Button2(this);

    goToSleepButton->setGeometry(QRect(60,63,335,56));
    rampButton->setGeometry(QRect(60,124,335,56));
    exhaleComfortButton->setGeometry(QRect(60,185,335,56));

    updateButton2Details(goToSleepButton        ,Providers::getTitleTextString(GO_TO_SLEEP_STR),Providers::getIconString(GO_TO_SLEEP_ICON));
    updateButton2Details(rampButton             ,Providers::getTitleTextString(RAMP_STR),Providers::getIconString(RAMP_ICON));
    updateButton2Details(exhaleComfortButton    ,Providers::getTitleTextString(EXHALE_PRESSURE_COMFORT_STR),Providers::getIconString(EXHALE_PRESSURE_COMFORT_ICON));

    goToSleepButton->updateUnitText(Providers::getUnitTextString(MINUTE_UNIT_STR));
    rampButton->updateUnitText(Providers::getUnitTextString(MINUTE_UNIT_STR));

    //Connect all press or release eventas to their specific slots
    connect(goToSleepButton, SIGNAL(clicked()),SLOT(goToSleepButton_released()));
    connect(rampButton, SIGNAL(clicked()),SLOT(rampButton_released()));
    connect(exhaleComfortButton, SIGNAL(clicked()),SLOT(exhaleComfortButton_released()));

    connect(goToSleepButton->switchWidget, SIGNAL(toggleSwitchClicked()),SLOT(goToSleepButtonSwitch_clicked()));
    connect(rampButton->switchWidget, SIGNAL(toggleSwitchClicked()),SLOT(rampButtonSwitch_clicked()));
    connect(exhaleComfortButton->switchWidget, SIGNAL(toggleSwitchClicked()),SLOT(exhaleComfortButtonSwitch_clicked()));

    updateGoToSleepSettings();
    updateRampTimeSettings();
    updateExhalePressureComfort();
}

void ComfortWindowClinical::updateButton2Details(Button2 * pButton,const QString &Title,const QString &imageLeft)
{
    QFont settingsFontTitle("Roboto-Light", 8);
    QFont settingsFontSubTitle("Roboto-Thin", 14);
    QFont fontUnit("Roboto-Light",7);

    pButton->setButtonRadius(5);
    pButton->setTitle(Title,settingsFontTitle,QColor(0xBDBDBD));
    pButton->setSubTitle(NULL,settingsFontSubTitle,QColor(0x2196F3));
    pButton->setUnit(NULL,fontUnit,QColor(0x616161));
    pButton->setBackgroundColor(0x606060,0x3e3e3e);
    pButton->setLeftRightSpacing(50,80);
    pButton->setSwitchHeightWidth(60,30);
    pButton->setImageLeft(0,5,24,24,imageLeft);
}

void ComfortWindowClinical::on_backComfort_released()
{
    animateSettingsWindow(Close);
}

void ComfortWindowClinical::goToSleepButton_released()
{
    if(globalVar.goToSleep.state == On)
    {
        connect(gotosleepScreen, SIGNAL(dialogClose()),
                this,SLOT(goToSleepClosed()));

        emit showGoToSleepScreen();
    }
}

void ComfortWindowClinical::goToSleepClosed()
{
    updateGoToSleepSettings();
    disconnect(gotosleepScreen, SIGNAL(dialogClose()),0,0);
}

void ComfortWindowClinical::rampButton_released()
{
    if(globalVar.rampTime.state == On)
    {
        connect(rampTimeScreen, SIGNAL(dialogClose()),
                this,SLOT(rampClosed()));

        emit showRampTimeScreen();
    }
}

void ComfortWindowClinical::rampClosed()
{
    updateRampTimeSettings();
    disconnect(rampTimeScreen, SIGNAL(dialogClose()),0,0);
}

void ComfortWindowClinical::goToSleepButtonSwitch_clicked()
{
    globalVar.goToSleep.state = static_cast<OnOff>(goToSleepButton->switchWidget->getSwitchState());
    updateGoToSleepSettings();

    // Update Data to EEPROM
    emit writeParameterToEeprom();
}

void ComfortWindowClinical::rampButtonSwitch_clicked()
{
    globalVar.rampTime.state = static_cast<OnOff>(rampButton->switchWidget->getSwitchState());
    updateRampTimeSettings();
    // Update Data to EEPROM
    emit writeParameterToEeprom();
}

void ComfortWindowClinical::exhaleComfortButtonSwitch_clicked()
{
    globalVar.comfortLevel.state = static_cast<OnOff>(exhaleComfortButton->switchWidget->getSwitchState());
    updateExhalePressureComfort();
    // Update Data to EEPROM
    emit writeParameterToEeprom();
}

void ComfortWindowClinical::updateGoToSleepSettings()
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
    goToSleepButton->switchWidget->setSwitchState(globalVar.goToSleep.state);
}

void ComfortWindowClinical::updateRampTimeSettings()
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
    rampButton->switchWidget->setSwitchState(globalVar.rampTime.state);
}

void ComfortWindowClinical::exhaleComfortButton_released()
{
    if(globalVar.comfortLevel.state == On)
    {
        connect(exhaleComfortScreen, SIGNAL(dialogClose()),
                this,SLOT(exhaleWindowClosed()));

        emit showExhaleComfortScreen();
    }
}

void ComfortWindowClinical::updateExhalePressureComfort(void)
{
    if(globalVar.comfortLevel.state == On)
        exhaleComfortButton->updateSubTitleText(exhaleLevel.at(globalVar.comfortLevel.comfortLevelSet));
    else
        exhaleComfortButton->updateSubTitleText(Providers::getOnOffStr(globalVar.comfortLevel.state));

    exhaleComfortButton->switchWidget->setSwitchState(globalVar.comfortLevel.state);
}

void ComfortWindowClinical::exhaleWindowClosed()
{
    updateExhalePressureComfort();
    disconnect(exhaleComfortScreen, SIGNAL(dialogClose()),0,0);
}

void ComfortWindowClinical::showComfortClinicalScreen()
{
    updateComfortWindowClinicalProcessBeforeShow();
    animateSettingsWindow(Open);
}

void ComfortWindowClinical::updateComfortWindowClinicalProcessBeforeShow(void)
{
    updateGoToSleepSettings();
    updateRampTimeSettings();
    updateExhalePressureComfort();
}

void ComfortWindowClinical::updateText()
{
    QFont settingsFontTitle("Roboto-Light", 8);

    goToSleepButton->setTitle(Providers::getTitleTextString(GO_TO_SLEEP_STR),settingsFontTitle,QColor(0xBDBDBD));
    rampButton->setTitle(Providers::getTitleTextString(RAMP_STR),settingsFontTitle,QColor(0xBDBDBD));
    exhaleComfortButton->setTitle(Providers::getTitleTextString(EXHALE_PRESSURE_COMFORT_STR),settingsFontTitle,QColor(0xBDBDBD));

//    updateGoToSleepSettings();
//    updateRampTimeSettings();
//    updateExhalePressureComfort();
}

void ComfortWindowClinical::changeEvent(QEvent* e)
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
