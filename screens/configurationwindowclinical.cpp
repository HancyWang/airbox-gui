#include "configurationwindowclinical.h"
#include "ui_configurationwindowclinical.h"
#include "ex_variables.h"


int ConfigurationWindowClinical::localLanguage = 0;
int ConfigurationWindowClinical::localDate = 0;
int ConfigurationWindowClinical::localHour = 0;
int ConfigurationWindowClinical::localMinute = 0;
int ConfigurationWindowClinical::localMonth = 0;
int ConfigurationWindowClinical::localYear = 0;


ConfigurationWindowClinical::ConfigurationWindowClinical(QWidget *parent,
                                                        SelectLanguageWindowClinical * selectLanguageWindowBackend,
                                                        DateWindowClinical * dateWindowBackend,
                                                        TimeWindowClinical * timeWindowBackend,
                                                        PressureUnitConfigurationClinical * pressureUnitWindowBackend,
                                                        EraseDataConfigurationClinical * eraseDataWindowBackend,
                                                        RestoreDefaultsWindowClinical * restoreDefaultWindowBackend,
                                                        SettingsWindowClinical * settingsClinicalBackend,
                                                        BackgroundWindow * backgroundBackend,
                                                        NotificationTray * notificationBackend)
    : QDialog(parent),
    ui(new Ui::ConfigurationWindowClinical),
    selectLanguageWindowScreen(selectLanguageWindowBackend),
    dateWindowScreen(dateWindowBackend),
    timeWindowScreen(timeWindowBackend),
    pressureUnitWindowScreen(pressureUnitWindowBackend),
    eraseDataWindowScreen(eraseDataWindowBackend),
    restoreDefaultWindowScreen(restoreDefaultWindowBackend),
    settingsClinicalScreen(settingsClinicalBackend),
    backgroundScreen(backgroundBackend),
    notificationScreen(notificationBackend),
    m_Anim(nullptr),
    languageButton(nullptr),
    dateButton(nullptr),
    timeButton(nullptr),
    pressureUnit(nullptr),
    restoreDefault(nullptr),
    eraseData(nullptr),
    timeUpdateTimer(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setWindowState(Qt::WindowFullScreen);
    setGeometry(0,0,width(),height());

    QFont title("Roboto-Light",12);
    ui->titleConfiguration->setFont(title);

    m_Anim = new QPropertyAnimation(this,"geometry");

    if(selectLanguageWindowScreen)
    {
        connect(this,SIGNAL(showSelectLanguageClinicalScreen()),
                selectLanguageWindowScreen,SLOT(showSelectLanguageClinicalScreen()));
    }

    if(dateWindowScreen)
    {
        connect(this,SIGNAL(showDateScreen(QWidget*,int,int,int,bool)),
                dateWindowScreen,SLOT(showDateScreen(QWidget*,int,int,int,bool)));
    }

    if(timeWindowScreen)
    {
        connect(this,SIGNAL(showTimeScreen(QWidget*,int,int,bool)),
                timeWindowScreen,SLOT(showTimeScreen(QWidget*,int,int,bool)));
    }

    if(pressureUnitWindowScreen)
    {
        connect(this,SIGNAL(showPressureUnitScreen()),
                pressureUnitWindowScreen,SLOT(showPressureUnitScreen()));
    }

    if(eraseDataWindowScreen)
    {
        connect(this,SIGNAL(showEraseDataScreen()),
                eraseDataWindowScreen,SLOT(showEraseDataScreen()));
    }

    if(restoreDefaultWindowScreen)
    {
        connect(this,SIGNAL(showRestoreDefaultScreen()),
                restoreDefaultWindowScreen,SLOT(showRestoreDefaultScreen()));
    }

    if(settingsClinicalScreen)
    {
        connect(settingsClinicalScreen,SIGNAL(showConfigurationClinicalScreen()),
                this,SLOT(showConfigurationClinicalScreen()));
    }

    if(notificationScreen)
    {
        connect(this,SIGNAL(updateSystemDate(int,int,int)),
                notificationScreen,SLOT(updateSystemDate(int,int,int)));
        connect(this,SIGNAL(updateSystemTime(int,int,int)),
                notificationScreen,SLOT(updateSystemTime(int,int,int)));
    }

    setupWindowParameters();


    timeUpdateTimer = new QTimer(this);
    connect(timeUpdateTimer, SIGNAL(timeout()), this, SLOT(timeUpdateTimerTimeout()));
    updateText();
}

ConfigurationWindowClinical::~ConfigurationWindowClinical()
{
    delete ui;
}

void ConfigurationWindowClinical::timeUpdateTimerTimeout()
{
    updateDateAndTimeGlobally();
}

void ConfigurationWindowClinical::showConfigurationClinicalScreen()
{
    updateConfigurationClinicalProcessBeforeShow();
    animateSettingsWindow(Open);
}

void ConfigurationWindowClinical::animateSettingsWindow(openCloseStatus state)
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

void ConfigurationWindowClinical::setupWindowParameters()
{
    languageButton = new Button1(this);
    dateButton = new Button1(this);
    timeButton = new Button1(this);
    pressureUnit = new Button1(this);
    restoreDefault = new Button1(this);
    eraseData = new Button1(this);

    ui->scrollAreaWidgetContentsConfiguration->setLayout(ui->verticalLayoutConfiguration);
    ui->scrollAreaConfiguration->setStyleSheet(QStringLiteral("border:none;"));

    updateButton1Details(languageButton ,Providers::getTitleTextString(LANGUAGE_STR),Providers::getIconString(LANGUAGE_ICON),Providers::getNavigationIconString());
    updateButton1Details(dateButton     ,Providers::getTitleTextString(DATE_STR),Providers::getIconString(DATE_ICON),Providers::getNavigationIconString());
    updateButton1Details(timeButton     ,Providers::getTitleTextString(TIME_STR),Providers::getIconString(TIME_ICON),Providers::getNavigationIconString());
    updateButton1Details(pressureUnit   ,Providers::getTitleTextString(PRESSURE_UNIT_STR),Providers::getIconString(PRESSURE_UNIT_ICON),Providers::getNavigationIconString());
    updateButton1Details(restoreDefault ,Providers::getTitleTextString(RESTORE_DEFAULTS_STR),Providers::getIconString(RESTORE_DEFAULTS_ICON),Providers::getNavigationIconString());
    updateButton1Details(eraseData      ,Providers::getTitleTextString(ERASE_DATA_STR),Providers::getIconString(ERASE_DATA_ICON),Providers::getNavigationIconString());

    languageButton->updateSubTitleText("English");

    //Enable Scrolling mechanism for scroll area
    QScroller::grabGesture(ui->scrollAreaConfiguration->viewport(),QScroller::LeftMouseButtonGesture);

    //Connect all press or release eventas to their specific slots
    connect(languageButton, SIGNAL(released()),SLOT(languageButton_released()));
    connect(dateButton, SIGNAL(released()),SLOT(dateButton_released()));
    connect(timeButton, SIGNAL(released()),SLOT(timeButton_released()));
    connect(pressureUnit, SIGNAL(released()),SLOT(pressureUnit_released()));
    connect(restoreDefault, SIGNAL(released()),SLOT(restoreDefault_released()));
    connect(eraseData, SIGNAL(released()),SLOT(eraseData_released()));

    updateConfigurationClinicalProcessBeforeShow();
}

void ConfigurationWindowClinical::updateButton1Details(Button1 * pButton,const QString &Title,const QString &imageLeft,const QString &imageRight)
{
    QFont settingsFontTitle("Roboto-Light", 8);
    QFont settingsFontSubTitle("Roboto-Thin", 14);
    QFont fontUnit("Roboto-Light",7);

    pButton->setButtonRadius(5);
    pButton->setTitle(Title,settingsFontTitle,QColor(0xBDBDBD));
    pButton->setSubTitle(NULL,settingsFontSubTitle,QColor(0x2196F3));
    pButton->setUnit(NULL,fontUnit,QColor(0x616161));
    pButton->setBackgroundColor(0x606060,0x3e3e3e);
    pButton->setLeftRightSpacing(50,50);
    pButton->setImageLeft(0,5,24,24,imageLeft);
    pButton->setImageRight(50,10,24,24,imageRight);
    pButton->setFixedHeight(56);
    pButton->setFixedWidth(350);

    ui->verticalLayoutConfiguration->addWidget(pButton);
}
void ConfigurationWindowClinical::on_backConfiguration_released()
{
    animateSettingsWindow(Close);
}

void ConfigurationWindowClinical::languageButton_released()
{
    if(selectLanguageWindowScreen)
    {
        disconnect(selectLanguageWindowScreen, SIGNAL(screenClose()),0,0);
        connect(selectLanguageWindowScreen,SIGNAL(screenClose()),
                this,SLOT(selectLanguageWindowClosed()));

        emit showSelectLanguageClinicalScreen();
    }

}

void ConfigurationWindowClinical::selectLanguageWindowClosed()
{
    //emit updateLanguage(localLanguage);
    updateLanguageInCurrentWindow();

    disconnect(selectLanguageWindowScreen,SIGNAL(screenClose()),0,0);
}

void ConfigurationWindowClinical::dateButton_released()
{
    if(dateWindowScreen)
    {
        disconnect(dateWindowScreen, SIGNAL(screenClose(int,int,int)),0,0);
        connect(dateWindowScreen,SIGNAL(screenClose(int,int,int)),
                this,SLOT(dateWindowClosed(int,int,int)));

        emit showDateScreen(backgroundScreen,
                            globalVar.systemDate.date,
                            globalVar.systemDate.month,
                            globalVar.systemDate.year,true);
    }
}

void ConfigurationWindowClinical::dateWindowClosed(int date, int month, int year)
{
    localDate = date + 1;
    localMonth = month + 1;
    localYear = year;

    emit updateSystemDate(localDate,localMonth,localYear);
    updateDateInCurrentWindow();

    disconnect(dateWindowScreen,SIGNAL(screenClose(int,int,int)),0,0);
}

void ConfigurationWindowClinical::timeButton_released()
{
    if(timeWindowScreen)
    {
        disconnect(timeWindowScreen, SIGNAL(screenClose(int,int)),0,0);
        connect(timeWindowScreen,SIGNAL(screenClose(int,int)),
                this,SLOT(timeWindowClosed(int,int)));

        emit showTimeScreen(backgroundScreen,
                            globalVar.systemTime.hour,
                            globalVar.systemTime.minute,true);
    }
}

void ConfigurationWindowClinical::timeWindowClosed(int hour, int minute)
{
    localHour = hour;
    localMinute = minute;

    emit updateSystemTime(localHour,localMinute,0);
    updateTimeInCurrentWindow();

    disconnect(timeWindowScreen, SIGNAL(screenClose(int,int)),0,0);
}

void ConfigurationWindowClinical::updateLanguageInCurrentWindow(void)
{
    languageButton->updateSubTitleText(Providers::getLanguageString(globalVar.language));
}

void ConfigurationWindowClinical::updateDateInCurrentWindow(void)
{
    QString dateStr = QString("%1 %2 %3").arg(globalVar.systemDate.date).arg(Providers::getMonthsTextString(globalVar.systemDate.month - 1)).arg(globalVar.systemDate.year);
    dateButton->updateSubTitleText(dateStr);
}

void ConfigurationWindowClinical::updateTimeInCurrentWindow(void)
{
    QString timeStr = QString("%1:%2").arg(globalVar.systemTime.hour, 2, 10, QChar('0')).arg(globalVar.systemTime.minute, 2, 10, QChar('0'));
    timeButton->updateSubTitleText(timeStr);
}

void ConfigurationWindowClinical::pressureUnit_released()
{
    if(pressureUnitWindowScreen)
    {
        connect(pressureUnitWindowScreen,SIGNAL(dialogClose()),
                this,SLOT(pressureUnitClosed()));

        emit showPressureUnitScreen();
    }
}

void ConfigurationWindowClinical::updatePressureUnitLocal(void)
{
    pressureUnit->updateSubTitleText(Providers::getPressureUnitTextString(globalVar.pressureUnit));
}

void ConfigurationWindowClinical::pressureUnitClosed()
{
    updatePressureUnitLocal();
    disconnect(pressureUnitWindowScreen, SIGNAL(dialogClose()),0,0);
}

void ConfigurationWindowClinical::restoreDefault_released()
{
    if(restoreDefaultWindowScreen)
    {
        emit showRestoreDefaultScreen();
    }
}

void ConfigurationWindowClinical::eraseData_released()
{
    if(eraseDataWindowScreen)
    {
        emit showEraseDataScreen();
    }
}

void ConfigurationWindowClinical::updateDateAndTimeGlobally(void)
{
    updateTimeInCurrentWindow();
    updateDateInCurrentWindow();
}

void ConfigurationWindowClinical::updateConfigurationClinicalProcessBeforeShow(void)
{
    updateDateAndTimeGlobally();
    updatePressureUnitLocal();

    QScrollBar * tScrollBar = ui->scrollAreaConfiguration->verticalScrollBar();
    tScrollBar->setValue(0);

}

void ConfigurationWindowClinical::updateText()
{
    updateButton1Details(languageButton ,Providers::getTitleTextString(LANGUAGE_STR),Providers::getIconString(LANGUAGE_ICON),Providers::getNavigationIconString());
    updateButton1Details(dateButton     ,Providers::getTitleTextString(DATE_STR),Providers::getIconString(DATE_ICON),Providers::getNavigationIconString());
    updateButton1Details(timeButton     ,Providers::getTitleTextString(TIME_STR),Providers::getIconString(TIME_ICON),Providers::getNavigationIconString());
    updateButton1Details(pressureUnit   ,Providers::getTitleTextString(PRESSURE_UNIT_STR),Providers::getIconString(PRESSURE_UNIT_ICON),Providers::getNavigationIconString());
    updateButton1Details(restoreDefault ,Providers::getTitleTextString(RESTORE_DEFAULTS_STR),Providers::getIconString(RESTORE_DEFAULTS_ICON),Providers::getNavigationIconString());
    updateButton1Details(eraseData      ,Providers::getTitleTextString(ERASE_DATA_STR),Providers::getIconString(ERASE_DATA_ICON),Providers::getNavigationIconString());

    if(globalVar.language==language_chinese)
    {
        languageButton->updateSubTitleText(Providers::getTitleTextString(CHINESE_STR));
    }
    else if(globalVar.language==language_japanese)
    {
        languageButton->updateSubTitleText(Providers::getTitleTextString(JAPANESE_STR));
    }
    else
    {
        languageButton->updateSubTitleText(Providers::getTitleTextString(ENGLISH_STR));
    }

    updateDateAndTimeGlobally();
    updatePressureUnitLocal();
}

void ConfigurationWindowClinical::changeEvent(QEvent* e)
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
