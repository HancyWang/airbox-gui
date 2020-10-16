#include "reminderwindowsettingsclinical.h"
#include "ui_reminderwindowsettingsclinical.h"
#include "ex_variables.h"

ReminderWindowSettingsClinical::ReminderWindowSettingsClinical(QWidget *parent,
                                                               SettingsWindowClinical * settingsClinicalBackend,
                                                               AirFilterWindowReminderClinical * airFilterBackend,
                                                               AirTubeWindowReminderClinical * airtubeBackend,
                                                               MaskWindowReminderClinical * maskReminderBackend,
                                                               DataValidation * dataValidationBackend)
    : QDialog(parent),
    ui(new Ui::ReminderWindowSettingsClinical),
    settingsClinicalScreen(settingsClinicalBackend),
    airFilterScreen(airFilterBackend),
    airtubeScreen(airtubeBackend),
    maskReminderScreen(maskReminderBackend),
    dataValidation(dataValidationBackend),
    m_Anim(nullptr),
    maskButton(nullptr),
    airTubeButton(nullptr),
    airFilterButton(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setWindowState(Qt::WindowFullScreen);
    setGeometry(0,0,width(),height());


    if(dataValidation)
    {
        connect(this,SIGNAL(writeParameterToEeprom()),
                dataValidation,SLOT(writeParameterToEeprom()));
    }

    if(settingsClinicalScreen)
    {
        connect(settingsClinicalScreen,SIGNAL(showReminderClinicalScreen()),
                this,SLOT(showReminderClinicalScreen()));
    }

    if(airtubeScreen)
    {
        connect(this,SIGNAL(showAirTubeReminderScreen()),
                airtubeScreen,SLOT(showAirTubeReminderScreen()));
    }

    if(maskReminderScreen)
    {
        connect(this,SIGNAL(showMaskReminderScreen()),
                maskReminderScreen,SLOT(showMaskReminderScreen()));
    }

    if(airFilterScreen)
    {
        connect(this,SIGNAL(showAirFilterReminderScreen()),
                airFilterScreen,SLOT(showAirFilterReminderScreen()));
    }

    QFont title("Roboto-Light",12);
    ui->titleReminders->setFont(title);

    m_Anim = new QPropertyAnimation(this,"geometry");

    setupWindowParameters();
}

ReminderWindowSettingsClinical::~ReminderWindowSettingsClinical()
{
    delete ui;
}

void ReminderWindowSettingsClinical::animateSettingsWindow(openCloseStatus state)
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

void ReminderWindowSettingsClinical::setupWindowParameters()
{
    maskButton = new Button2(this);
    airTubeButton = new Button2(this);
    airFilterButton = new Button2(this);

    maskButton->setGeometry(QRect(60,63,335,56));
    airTubeButton->setGeometry(QRect(60,124,335,56));
    airFilterButton->setGeometry(QRect(60,185,335,56));

    updateButton2Details(maskButton     ,Providers::getTitleTextString(MASK_STR),Providers::getIconString(MASK_ICON));
    updateButton2Details(airTubeButton  ,Providers::getTitleTextString(AIR_TUBE_STR),Providers::getIconString(AIR_TUBE_ICON));
    updateButton2Details(airFilterButton,Providers::getTitleTextString(AIR_FILTER_STR),Providers::getIconString(AIR_FILTER_ICON));

    //Connect all press or release eventas to their specific slots
    connect(maskButton, SIGNAL(released()),SLOT(maskButton_released()));
    connect(airTubeButton, SIGNAL(released()),SLOT(airTubeButton_released()));
    connect(airFilterButton, SIGNAL(released()),SLOT(airFilterButton_released()));

    connect(maskButton->switchWidget       , SIGNAL(toggleSwitchClicked()),SLOT(maskButtonSwitch_clicked()));
    connect(airTubeButton->switchWidget    , SIGNAL(toggleSwitchClicked()),SLOT(airTubeButtonSwitch_clicked()));
    connect(airFilterButton->switchWidget  , SIGNAL(toggleSwitchClicked()),SLOT(airFilterButtonSwitch_clicked()));

    updateReminderWindowProcessBeforeShow();
}

void ReminderWindowSettingsClinical::updateButton2Details(Button2 * pButton,const QString &Title,const QString &imageLeft)
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

void ReminderWindowSettingsClinical::on_backReminders_released()
{
    animateSettingsWindow(Close);
}

void ReminderWindowSettingsClinical::updateReminderWindowProcessBeforeShow(void)
{
    maskButton->switchWidget->setSwitchState(globalVar.reminder.mask.state);
    airTubeButton->switchWidget->setSwitchState(globalVar.reminder.airTube.state);
    airFilterButton->switchWidget->setSwitchState(globalVar.reminder.airFilter.state);

    updateMaskStatus();
    updateAirFilterStatus();
    updateAirTubeStatus();
}

void ReminderWindowSettingsClinical::maskButton_released()
{
    if(globalVar.reminder.mask.state == On)
    {
        emit showMaskReminderScreen();
    }
}

void ReminderWindowSettingsClinical::airTubeButton_released()
{
    if(globalVar.reminder.airTube.state == On)
    {
        emit showAirTubeReminderScreen();
    }
}

void ReminderWindowSettingsClinical::airFilterButton_released()
{
    if(globalVar.reminder.airFilter.state == On)
    {
        emit showAirFilterReminderScreen();
    }
}

void ReminderWindowSettingsClinical::maskButtonSwitch_clicked()
{
    globalVar.reminder.mask.state = static_cast<OnOff>(!globalVar.reminder.mask.state);
    updateMaskStatus();

    // Update Data to EEPROM
    emit writeParameterToEeprom();
}

void ReminderWindowSettingsClinical::airTubeButtonSwitch_clicked()
{
    globalVar.reminder.airTube.state = static_cast<OnOff>(!globalVar.reminder.airTube.state);
    updateAirTubeStatus();

    // Update Data to EEPROM
    emit writeParameterToEeprom();
}

void ReminderWindowSettingsClinical::airFilterButtonSwitch_clicked()
{
    globalVar.reminder.airFilter.state = static_cast<OnOff>(!globalVar.reminder.airFilter.state);
    updateAirFilterStatus();

    // Update Data to EEPROM
    emit writeParameterToEeprom();
}

void ReminderWindowSettingsClinical::showReminderClinicalScreen()
{
    updateReminderWindowProcessBeforeShow();
    animateSettingsWindow(Open);
}

void ReminderWindowSettingsClinical::updateMaskStatus(void)
{
    maskButton->updateSubTitleText(Providers::getOnOffStr(globalVar.reminder.mask.state));
}

void ReminderWindowSettingsClinical::updateAirFilterStatus(void)
{
    airFilterButton->updateSubTitleText(Providers::getOnOffStr(globalVar.reminder.airFilter.state));
}

void ReminderWindowSettingsClinical::updateAirTubeStatus(void)
{
    airTubeButton->updateSubTitleText(Providers::getOnOffStr(globalVar.reminder.airTube.state));
}

void ReminderWindowSettingsClinical::updateText()
{
//    updateButton2Details(maskButton     ,Providers::getTitleTextString(MASK_STR),Providers::getIconString(MASK_ICON));
//    updateButton2Details(airTubeButton  ,Providers::getTitleTextString(AIR_TUBE_STR),Providers::getIconString(AIR_TUBE_ICON));
//    updateButton2Details(airFilterButton,Providers::getTitleTextString(AIR_FILTER_STR),Providers::getIconString(AIR_FILTER_ICON));

    QFont settingsFontTitle("Roboto-Light", 8);

    maskButton->setTitle(Providers::getTitleTextString(MASK_STR),settingsFontTitle,QColor(0xBDBDBD));
    airTubeButton->setTitle(Providers::getTitleTextString(AIR_TUBE_STR),settingsFontTitle,QColor(0xBDBDBD));
    airFilterButton->setTitle(Providers::getTitleTextString(AIR_FILTER_STR),settingsFontTitle,QColor(0xBDBDBD));
}

void ReminderWindowSettingsClinical::changeEvent(QEvent* e)
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
