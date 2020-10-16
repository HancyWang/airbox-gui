#include "settingswindowclinical.h"
#include "ui_settingswindowclinical.h"
#include "ex_variables.h"

SettingsWindowClinical::SettingsWindowClinical(QWidget *parent,
                                               HomeWindowClinical * homeClinicalBackend,
                                               DeviceInfoSettingsBasic * deviceInfoBackend,
                                               PasswordCheckScreen * passwordCheckBackend)
    : QDialog(parent),
    ui(new Ui::SettingsWindowClinical),
    homeClinicalScreen(homeClinicalBackend),
    deviceInfoScreen(deviceInfoBackend),
    passwordCheckScreen(passwordCheckBackend),
    m_Anim(nullptr),
    therapyButton(nullptr),
    comfortButton(nullptr),
    accessoriesButton(nullptr),
    optionsButton(nullptr),
    remindersButton(nullptr),
    configurationButton(nullptr),
    deviceInfoButton(nullptr),
    menufacturingOptionsButton(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setWindowState(Qt::WindowFullScreen);
    setGeometry(0,0,width(),height());

    QFont title("Roboto-Light",12);
    ui->titleSettings->setFont(title);

    if(deviceInfoScreen)
    {
        connect(this,SIGNAL(showDeviceInfoScreen(QWidget*)),
                deviceInfoScreen,SLOT(showDeviceInfoScreen(QWidget*)));
    }

    if(passwordCheckScreen)
    {
        connect(this,SIGNAL(showPasswordEnterScreen(const int*)),
                passwordCheckScreen,SLOT(showPasswordEnterScreen(const int*)));
    }

    m_Anim = new QPropertyAnimation(this,"geometry");

    if(homeClinicalScreen)
    {
        connect(homeClinicalScreen,SIGNAL(showSettingsClinicalScreen()),
                this,SLOT(showSettingsClinicalScreen()));
    }

    addButtons();
}

SettingsWindowClinical::~SettingsWindowClinical()
{
    delete ui;
}

void SettingsWindowClinical::addButtons(void)
{
    therapyButton = new Button1(this);
    comfortButton = new Button1(this);
    accessoriesButton = new Button1(this);
    optionsButton = new Button1(this);
    remindersButton = new Button1(this);
    configurationButton = new Button1(this);
    deviceInfoButton = new Button1(this);
    menufacturingOptionsButton = new Button1(this);

    ui->scrollAreaWidgetContentsSettings->setLayout(ui->verticalLayoutSettings);
    ui->scrollAreaSettings->setStyleSheet(QStringLiteral("border:none;"));

    updateButton1Details(therapyButton       ,Providers::getTitleTextString(THERAPY_STR),Providers::getIconString(THERAPY_CLINICAL_ICON),Providers::getNavigationIconString());
    updateButton1Details(comfortButton       ,Providers::getTitleTextString(COMFORT_STR),Providers::getIconString(COMFORT_ICON),Providers::getNavigationIconString());
    updateButton1Details(accessoriesButton   ,Providers::getTitleTextString(ACCESSORIES_STR),Providers::getIconString(ACCESSORIES_ICON),Providers::getNavigationIconString());
    updateButton1Details(optionsButton       ,Providers::getTitleTextString(OPTIONS_STR),Providers::getIconString(OPTIONS_ICON),Providers::getNavigationIconString());
    updateButton1Details(remindersButton     ,Providers::getTitleTextString(REMINDERS_STR),Providers::getIconString(REMINDERS_ICON),Providers::getNavigationIconString());
    updateButton1Details(configurationButton ,Providers::getTitleTextString(CONFIGURATION_STR),Providers::getIconString(CONFIGURATION_ICON),Providers::getNavigationIconString());
    updateButton1Details(deviceInfoButton    ,Providers::getTitleTextString(DEVICE_INFO_STR),Providers::getIconString(DEVICE_INFO_ICON),Providers::getNavigationIconString());
    updateButton1Details(menufacturingOptionsButton    ,"Manufacturing Options",Providers::getIconString(MANUFACTURING_DIAGNOSIS),Providers::getNavigationIconString());

    //Enable Scrolling mechanism for scroll area
    QScroller::grabGesture(ui->scrollAreaSettings->viewport(),QScroller::LeftMouseButtonGesture);

    //Connect all press or release eventas to their specific slots
    connect(therapyButton, SIGNAL(released()),SLOT(therapyButton_released()));
    connect(comfortButton, SIGNAL(released()),SLOT(comfortButton_released()));
    connect(accessoriesButton, SIGNAL(released()),SLOT(accessoriesButton_released()));
    connect(optionsButton, SIGNAL(released()),SLOT(optionsButton_released()));
    connect(remindersButton, SIGNAL(released()),SLOT(remindersButton_released()));
    connect(configurationButton, SIGNAL(released()),SLOT(configurationButton_released()));
    connect(deviceInfoButton, SIGNAL(released()),SLOT(deviceInfoButton_released()));
    connect(menufacturingOptionsButton, SIGNAL(released()),SLOT(menufacturingOptionsButton_released()));
}

void SettingsWindowClinical::updateButton1Details(Button1 * pButton,const QString &Title,const QString &imageLeft,const QString &imageRight)
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

    ui->verticalLayoutSettings->addWidget(pButton);
}




void SettingsWindowClinical::animateSettingsWindow(openCloseStatus state)
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

void SettingsWindowClinical::updateSettingsWindowClinicalBeforeShow(void)
{
    QScrollBar * tScrollBar = ui->scrollAreaSettings->verticalScrollBar();
    tScrollBar->setValue(0);
}

void SettingsWindowClinical::therapyButton_released()
{
    emit showTherapyClinicalScreen();
}

void SettingsWindowClinical::comfortButton_released()
{
    emit showComfortClinicalScreen();
}

void SettingsWindowClinical::accessoriesButton_released()
{
    emit showAccesoriesClinicalScreen();
}

void SettingsWindowClinical::optionsButton_released()
{
    emit showOptionsClinicalScreen();
}

void SettingsWindowClinical::remindersButton_released()
{
    emit showReminderClinicalScreen();
}

void SettingsWindowClinical::configurationButton_released()
{
    emit showConfigurationClinicalScreen();
}

void SettingsWindowClinical::deviceInfoButton_released()
{
    emit showDeviceInfoScreen(this);
}


void SettingsWindowClinical::on_homeSettings_released()
{
    animateSettingsWindow(Close);
}

const int SettingsWindowClinical::manufacturingPassword[9] = {1,9,1,0,2,0,1,8,0};

void SettingsWindowClinical::menufacturingOptionsButton_released()
{
    /* Open Password screen to verify password for Manufacturing menu
     */
#ifdef ENABLE_PASSWORD
        connect(passwordCheckScreen, SIGNAL(dialogClose()),
                this,SLOT(passwordCheckWindowClosed()));

        emit showPasswordEnterScreen(manufacturingPassword);
#else
        passwordCheckWindowClosed();
#endif
}

void SettingsWindowClinical::passwordCheckWindowClosed()
{
    /* If entered password is correct show Manufacturing Options screen */
    emit showManufacturingOptionsScreen(this);
}

void SettingsWindowClinical::showSettingsClinicalScreen()
{
    updateSettingsWindowClinicalBeforeShow();
    animateSettingsWindow(Open);
}

void SettingsWindowClinical::updateText()
{
    updateButton1Details(therapyButton       ,Providers::getTitleTextString(THERAPY_STR),Providers::getIconString(THERAPY_CLINICAL_ICON),Providers::getNavigationIconString());
    updateButton1Details(comfortButton       ,Providers::getTitleTextString(COMFORT_STR),Providers::getIconString(COMFORT_ICON),Providers::getNavigationIconString());
    updateButton1Details(accessoriesButton   ,Providers::getTitleTextString(ACCESSORIES_STR),Providers::getIconString(ACCESSORIES_ICON),Providers::getNavigationIconString());
    updateButton1Details(optionsButton       ,Providers::getTitleTextString(OPTIONS_STR),Providers::getIconString(OPTIONS_ICON),Providers::getNavigationIconString());
    updateButton1Details(remindersButton     ,Providers::getTitleTextString(REMINDERS_STR),Providers::getIconString(REMINDERS_ICON),Providers::getNavigationIconString());
    updateButton1Details(configurationButton ,Providers::getTitleTextString(CONFIGURATION_STR),Providers::getIconString(CONFIGURATION_ICON),Providers::getNavigationIconString());
    updateButton1Details(deviceInfoButton    ,Providers::getTitleTextString(DEVICE_INFO_STR),Providers::getIconString(DEVICE_INFO_ICON),Providers::getNavigationIconString());
    updateButton1Details(menufacturingOptionsButton    ,Providers::getTitleTextString(MANUFACTURING_OPTION_STR),Providers::getIconString(MANUFACTURING_DIAGNOSIS),Providers::getNavigationIconString());
}
void SettingsWindowClinical::changeEvent(QEvent* e)
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


