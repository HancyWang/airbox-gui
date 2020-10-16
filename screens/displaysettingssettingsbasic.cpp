#include "displaysettingssettingsbasic.h"
#include "ui_displaysettingssettingsbasic.h"
#include "ex_variables.h"



DisplaySettingsSettingsBasic::DisplaySettingsSettingsBasic(QWidget *parent,
                                                           BrightnessAdjustBrightnessSettingsBasic * brightnessAdjustBackend,
                                                           DisplayDimBrightnessSettingsBasic * displaydimBrightnessBackend,
                                                           SettingsWindowBasic * settingsBasicBackend)
    : QDialog(parent),
    ui(new Ui::DisplaySettingsSettingsBasic),
    brightnessAdjustScreen(brightnessAdjustBackend),
    displaydimBrightnessScreen(displaydimBrightnessBackend),
    settingsBasicScreen(settingsBasicBackend),
    m_Anim(nullptr),
    brightnessDisplaySettings(nullptr),
    dimDurationDisplaySettings(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setGeometry(0,0,width(),height());

    if(brightnessAdjustScreen)
    {
        connect(this,SIGNAL(showBrightnessAdjustScreen()),
                brightnessAdjustScreen,SLOT(showBrightnessAdjustScreen()));
    }

    if(displaydimBrightnessScreen)
    {
        connect(this,SIGNAL(showDisplayDimBrightnessScreen()),
                displaydimBrightnessScreen,SLOT(showDisplayDimBrightnessScreen()));
    }

    if(settingsBasicScreen)
    {
        connect(settingsBasicScreen,SIGNAL(showDisplaySettingsScreen()),
                this,SLOT(showDisplaySettingsScreen()));
    }

    m_Anim = new QPropertyAnimation(this,"geometry");

    QFont title("Roboto-Light",12);
    ui->displaySettingsTitle->setFont(title);

    addButtonsToScreen();
}

DisplaySettingsSettingsBasic::~DisplaySettingsSettingsBasic()
{
    delete ui;
}

void DisplaySettingsSettingsBasic::updateButton1Details(Button1 * pButton,const QString &Title,const QString &imageLeft,const QString &imageRight)
{
    QFont fontTitle("Roboto-Light", 9);
    QFont fontSubTitle("Roboto-Thin", 14);
    QFont fontUnit("Roboto-Light",7);

    pButton->setButtonRadius(5);
    pButton->setTitle(Title,fontTitle,QColor(0xBDBDBD));
    pButton->setSubTitle(NULL,fontSubTitle,QColor(0x2196F3));
    pButton->setUnit(NULL,fontUnit,QColor(0x616161));
    pButton->setBackgroundColor(0x606060,0x3e3e3e);
    pButton->setLeftRightSpacing(50,50);
    pButton->setImageLeft(0,5,24,24,imageLeft);
    pButton->setImageRight(50,10,24,24,imageRight);
}

void DisplaySettingsSettingsBasic::addButtonsToScreen(void)
{
    brightnessDisplaySettings = new Button1(this);
    dimDurationDisplaySettings = new Button1(this);

    brightnessDisplaySettings->setGeometry(QRect(72,71,330,50));
    dimDurationDisplaySettings->setGeometry(QRect(72,126,330,50));

    updateButton1Details(brightnessDisplaySettings,Providers::getTitleTextString(BRIGHTNESS_STR),
                         Providers::getIconString(BRIGHTNESS_ICON),Providers::getNavigationIconString());
    updateButton1Details(dimDurationDisplaySettings,Providers::getTitleTextString(DISPLAY_DIM_DURATION_STR),
                         Providers::getIconString(DISPLAY_DIM_DURATION_ICON),Providers::getNavigationIconString());

    connect(brightnessDisplaySettings, SIGNAL(released()),SLOT(brightnessDisplaySettings_released()));
    connect(dimDurationDisplaySettings, SIGNAL(released()),SLOT(dimDurationDisplaySettings_released()));

    brightnessDisplaySettings->updateUnitText(Providers::getUnitTextString(PERCENTAGE_UNIT_STR));

    dimDurationDisplaySettings->updateUnitText(Providers::getUnitTextString(MINUTE_UNIT_STR));
    dimDurationDisplaySettings->setUnitVisibility(true);

    updateDisplaySettingsProcessBeforeShow();
}

void DisplaySettingsSettingsBasic::animateDisplaySettingsWindow(const openCloseStatus &state)
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

void DisplaySettingsSettingsBasic::on_backDisplaySettings_released()
{
    animateDisplaySettingsWindow(Close);
}

void DisplaySettingsSettingsBasic::brightnessDisplaySettings_released()
{
    connect(brightnessAdjustScreen, SIGNAL(dialogClose()),
            this,SLOT(brightnessAdjustClosed()));

    emit showBrightnessAdjustScreen();
}

void DisplaySettingsSettingsBasic::updateBrightnessDisplaySettings()
{
    if(globalVar.displaySettings.autoBrightnessAdjustment == On)
    {

        brightnessDisplaySettings->updateSubTitleText(Providers::getAutoStr());
        brightnessDisplaySettings->setUnitVisibility(false);
    }
    else
    {
        QString str = QString::number(globalVar.displaySettings.brightnessLevel);
        brightnessDisplaySettings->updateSubTitleText(str);
        brightnessDisplaySettings->setUnitVisibility(true);
    }
}

void DisplaySettingsSettingsBasic::brightnessAdjustClosed()
{
    updateBrightnessDisplaySettings();
    disconnect(brightnessAdjustScreen, SIGNAL(dialogClose()),0,0);
}

void DisplaySettingsSettingsBasic::dimDurationDisplaySettings_released()
{
    connect(displaydimBrightnessScreen, SIGNAL(dialogClose()),
            this,SLOT(displayDimClosed()));

    emit showDisplayDimBrightnessScreen();
}

void DisplaySettingsSettingsBasic::updateDisplayDimDurationSettings()
{
    QString str = QString::number(globalVar.displaySettings.displayDimDuration);
    dimDurationDisplaySettings->updateSubTitleText(str);
}

void DisplaySettingsSettingsBasic::displayDimClosed()
{
    updateDisplayDimDurationSettings();
    disconnect(displaydimBrightnessScreen, SIGNAL(dialogClose()),0,0);
}

void DisplaySettingsSettingsBasic::showDisplaySettingsScreen()
{
    updateDisplaySettingsProcessBeforeShow();
    animateDisplaySettingsWindow(Open);
}

void DisplaySettingsSettingsBasic::updateDisplaySettingsProcessBeforeShow(void)
{
    updateBrightnessDisplaySettings();
    updateDisplayDimDurationSettings();
}

void DisplaySettingsSettingsBasic::updateText()
{
    updateButton1Details(brightnessDisplaySettings,Providers::getTitleTextString(BRIGHTNESS_STR),
                         Providers::getIconString(BRIGHTNESS_ICON),Providers::getNavigationIconString());
    updateButton1Details(dimDurationDisplaySettings,Providers::getTitleTextString(DISPLAY_DIM_DURATION_STR),
                         Providers::getIconString(DISPLAY_DIM_DURATION_ICON),Providers::getNavigationIconString());
}

void DisplaySettingsSettingsBasic::changeEvent(QEvent* e)
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
