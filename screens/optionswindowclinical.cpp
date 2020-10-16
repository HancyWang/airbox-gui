#include "optionswindowclinical.h"
#include "ui_optionswindowclinical.h"
#include "ex_variables.h"

OptionsWindowClinical::OptionsWindowClinical(QWidget *parent,
                                             SettingsWindowClinical * settingsClinicalBackend,
                                             DataValidation * dataValidationBackend)
    : QDialog(parent),
    ui(new Ui::OptionsWindowClinical),
    settingsClinicalScreen(settingsClinicalBackend),
    dataValidation(dataValidationBackend),
    m_Anim(nullptr),
    sleepReportButton(nullptr),
    autoStartTherapyButton(nullptr),
    sleepTitrationModeButton(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowState(Qt::WindowFullScreen);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setGeometry(0,0,width(),height());

    if(settingsClinicalScreen)
    {
        connect(settingsClinicalScreen,SIGNAL(showOptionsClinicalScreen()),
                this,SLOT(showOptionsClinicalScreen()));
    }

    if(dataValidation)
    {
        connect(this,SIGNAL(writeParameterToEeprom()),
                dataValidation,SLOT(writeParameterToEeprom()));
    }

    QFont title("Roboto-Light",12);
    ui->titleOptions->setFont(title);

    m_Anim = new QPropertyAnimation(this,"geometry");

    addButtons();
}

OptionsWindowClinical::~OptionsWindowClinical()
{
    delete ui;
}

void OptionsWindowClinical::animateSettingsWindow(openCloseStatus state)
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

void OptionsWindowClinical::addButtons(void)
{
    autoStartTherapyButton = new Button2(this);
//    sleepTitrationModeButton = new Button2(this);

    autoStartTherapyButton->setGeometry(QRect(60,63,335,56));
//    sleepTitrationModeButton->setGeometry(QRect(60,124,335,56));

    updateButton2Details(autoStartTherapyButton    ,Providers::getTitleTextString(AUTO_START_THERAPY_STR),Providers::getIconString(AUTO_START_THERAPY_ICON));
//    updateButton2Details(sleepTitrationModeButton  ,Providers::getTitleTextString(SLEEP_LAB_TITRATION_MODE_STR),Providers::getIconString(SLEEP_LAB_TITRATION_MODE_ICON));

//    connect(sleepTitrationModeButton->switchWidget, SIGNAL(toggleSwitchClicked()),SLOT(sleepTitrationModeButtonSwitch_clicked()));
    connect(autoStartTherapyButton->switchWidget, SIGNAL(toggleSwitchClicked()),SLOT(autoStartTherapyButtonSwitch_clicked()));

    updateOptionsWindowClinicalProcessBeforeShow();

    // Not required in build
//    sleepTitrationModeButton->hide();
}

void OptionsWindowClinical::updateButton2Details(Button2 * pButton,const QString &Title,const QString &imageLeft)
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

void OptionsWindowClinical::on_backOptions_released()
{
    animateSettingsWindow(Close);
}

void OptionsWindowClinical::sleepTitrationModeButtonSwitch_clicked()
{
    globalVar.sleepTitrationMode = static_cast<OnOff>(!globalVar.sleepTitrationMode);
    updateSleepLabTitrationText();
    // Update Data to EEPROM
    emit writeParameterToEeprom();
}

void OptionsWindowClinical::autoStartTherapyButtonSwitch_clicked()
{
    globalVar.autoStartTherapy = static_cast<OnOff>(!globalVar.autoStartTherapy);
    updateAutoStartTherapyText();
    // Update Data to EEPROM
    emit writeParameterToEeprom();
}

void OptionsWindowClinical::showOptionsClinicalScreen()
{
    updateOptionsWindowClinicalProcessBeforeShow();
    animateSettingsWindow(Open);
}

void OptionsWindowClinical::updateAutoStartTherapyText(void)
{
    autoStartTherapyButton->updateSubTitleText(Providers::getOnOffStr(globalVar.autoStartTherapy));
}

void OptionsWindowClinical::updateSleepLabTitrationText(void)
{
//    sleepTitrationModeButton->updateSubTitleText(Providers::getOnOffStr(globalVar.sleepTitrationMode));
}

void OptionsWindowClinical::updateOptionsWindowClinicalProcessBeforeShow(void)
{
    autoStartTherapyButton->switchWidget->setSwitchState(globalVar.autoStartTherapy);
    updateAutoStartTherapyText();

//    sleepTitrationModeButton->switchWidget->setSwitchState(globalVar.sleepTitrationMode);
//    updateSleepLabTitrationText();
}

void OptionsWindowClinical::updateText()
{
    updateButton2Details(autoStartTherapyButton    ,Providers::getTitleTextString(AUTO_START_THERAPY_STR),Providers::getIconString(AUTO_START_THERAPY_ICON));
//    updateButton2Details(sleepTitrationModeButton  ,Providers::getTitleTextString(SLEEP_LAB_TITRATION_MODE_STR),Providers::getIconString(SLEEP_LAB_TITRATION_MODE_ICON));
}

void OptionsWindowClinical::changeEvent(QEvent* e)
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
