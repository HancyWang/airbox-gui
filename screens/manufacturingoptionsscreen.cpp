#include "manufacturingoptionsscreen.h"
#include "ui_manufacturingoptionsscreen.h"
#include "ex_variables.h"

ManufacturingOptionsScreen::ManufacturingOptionsScreen(QWidget *parent,
                                                       PasswordCheckScreen * passwordCheckBackend,
                                                       SettingsWindowClinical * settingsClinicalBackend,
                                                       DiagnosticDataScreen * diagnosticDataWindowBackend)
    : QDialog(parent),
    ui(new Ui::ManufacturingOptionsScreen),
    passwordCheckScreen(passwordCheckBackend),
    settingsClinicalScreen(settingsClinicalBackend),
    diagnosticDataWindowScreen(diagnosticDataWindowBackend),
    m_Anim(nullptr),
    menufacturingDiagButton(nullptr),
    menufacturingSetupButton(nullptr),
    blowerTestButton(nullptr),
    parameterTuneButton(nullptr),
    diagnosticData(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setWindowState(Qt::WindowFullScreen);
    setGeometry(0,0,width(),height());

    m_Anim = new QPropertyAnimation(this,"geometry");

    if(passwordCheckScreen)
    {
        connect(this,SIGNAL(showPasswordEnterScreen(const int*)),
                passwordCheckScreen,SLOT(showPasswordEnterScreen(const int*)));
    }

    if(settingsClinicalScreen)
    {
        connect(settingsClinicalScreen,SIGNAL(showManufacturingOptionsScreen(QWidget*)),
                this,SLOT(showManufacturingOptionsScreen(QWidget*)));
    }

    if(diagnosticDataWindowScreen)
    {
        connect(this,SIGNAL(showDiagnosticDataScreen()),
                diagnosticDataWindowScreen,SLOT(showDiagnosticDataScreen()));
    }

    addButtonsManufacturingOptions();

    updateManufacturingOptionsProcessBeforeShow();

    QFont title("Roboto-Light",12);
    ui->titleManufacturingOptions->setFont(title);
}

ManufacturingOptionsScreen::~ManufacturingOptionsScreen()
{
    delete ui;
}

void ManufacturingOptionsScreen::animateManufacturingOptionsWindow(const openCloseStatus &state)
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

void ManufacturingOptionsScreen::addButtonsManufacturingOptions(void)
{
    menufacturingDiagButton = new Button1(this);
    menufacturingSetupButton = new Button1(this);
//    blowerTestButton = new Button1(this);
    parameterTuneButton = new Button1(this);
    diagnosticData = new Button1(this);
/*
    menufacturingDiagButton->setGeometry(QRect(60,63,330,50));
    menufacturingSetupButton->setGeometry(QRect(60,118,330,50));
    parameterTuneButton->setGeometry(QRect(60,173,330,50));
//    blowerTestButton->setGeometry(QRect(60,173,330,50));
    diagnosticData->setGeometry(QRect(60,228,330,50));
*/
    ui->scrollAreaWidgetContentsConfiguration->setLayout(ui->verticalLayoutConfiguration);
    ui->scrollAreaConfiguration->setStyleSheet(QStringLiteral("border:none;"));

//    updateButton1Details(menufacturingDiagButton    ,"Manufacturing Diagnosis",Providers::getIconString(MANUFACTURING_DIAGNOSIS),Providers::getNavigationIconString());
//    updateButton1Details(menufacturingSetupButton   ,"Manufacturing Setup",Providers::getIconString(MANUFACTURING_SETUP),Providers::getNavigationIconString());
////    updateButton1Details(blowerTestButton    ,"Blower Test Application",Providers::getIconString(MASK_DRY_ICON),Providers::getNavigationIconString());
//    updateButton1Details(parameterTuneButton    ,"Parameter Tune",Providers::getIconString(MASK_DRY_ICON),Providers::getNavigationIconString());
//    updateButton1Details(diagnosticData  ,Providers::getTitleTextString(DIAGNOSTIC_DATA_STR),Providers::getIconString(DIAGNOSTIC_DATA_ICON),Providers::getNavigationIconString());


    updateButton1Details(menufacturingDiagButton    ,Providers::getTitleTextString(MANUFACTURING_DIAGNOSIS_STR),Providers::getIconString(MANUFACTURING_DIAGNOSIS),Providers::getNavigationIconString());
    updateButton1Details(menufacturingSetupButton   ,Providers::getTitleTextString(MANUFACTURING_SETUP_STR),Providers::getIconString(MANUFACTURING_SETUP),Providers::getNavigationIconString());
//    updateButton1Details(blowerTestButton    ,Providers::getTitleTextString(BLOWER_TEST_APPLICATION_STR),Providers::getIconString(MASK_DRY_ICON),Providers::getNavigationIconString());
    updateButton1Details(parameterTuneButton    ,Providers::getTitleTextString(PARAMETER_TUNE_STR),Providers::getIconString(MASK_DRY_ICON),Providers::getNavigationIconString());
    updateButton1Details(diagnosticData  ,Providers::getTitleTextString(DIAGNOSTIC_DATA_STR),Providers::getIconString(DIAGNOSTIC_DATA_ICON),Providers::getNavigationIconString());
    //Enable Scrolling mechanism for scroll area
    QScroller::grabGesture(ui->scrollAreaConfiguration->viewport(),QScroller::LeftMouseButtonGesture);

    connect(menufacturingDiagButton, SIGNAL(released()),SLOT(menufacturingDiagButton_released()));
    connect(menufacturingSetupButton, SIGNAL(released()),SLOT(menufacturingSetupButton_released()));
//    connect(blowerTestButton, SIGNAL(released()),SLOT(blowerTestButton_released()));
    connect(parameterTuneButton, SIGNAL(released()),SLOT(parameterTuneButton_released()));
    connect(diagnosticData, SIGNAL(released()),SLOT(diagnosticData_released()));
}


void ManufacturingOptionsScreen::updateButton1Details(Button1 * pButton,const QString &Title,const QString &imageLeft,const QString &imageRight)
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

void ManufacturingOptionsScreen::on_backManufacturingOptions_released()
{
    animateManufacturingOptionsWindow(Close);
}

void ManufacturingOptionsScreen::menufacturingDiagButton_released(void)
{
    emit showManufacturingDiagnosisScreen();
}

void ManufacturingOptionsScreen::menufacturingSetupButton_released(void)
{
    emit showManufacturingSetupScreen();
}

void ManufacturingOptionsScreen::blowerTestButton_released()
{
    emit showBlowerTestScreen();
}

const int ManufacturingOptionsScreen::tuneParameterPassword[9] = {1,2,9,1,1,2,9,1,0};

void ManufacturingOptionsScreen::parameterTuneButton_released()
{
    /* Open Password screen to verify password for Manufacturing menu
     */
#ifdef ENABLE_PASSWORD
        connect(passwordCheckScreen, SIGNAL(dialogClose()),
                this,SLOT(passwordCheckWindowClosed()));

        emit showPasswordEnterScreen(tuneParameterPassword);
#else
        passwordCheckWindowClosed();
#endif
}


void ManufacturingOptionsScreen::passwordCheckWindowClosed()
{
    /* If entered password is correct show Manufacturing Options screen */
    emit showParameterTunningScreen();
}

void ManufacturingOptionsScreen::showManufacturingOptionsScreen(QWidget * parent)
{
    setParent(parent);
    updateManufacturingOptionsProcessBeforeShow();
    animateManufacturingOptionsWindow(Open);
}

void ManufacturingOptionsScreen::diagnosticData_released()
{
    if(diagnosticDataWindowScreen)
    {
        connect(diagnosticDataWindowScreen,SIGNAL(dialogClose()),
                this,SLOT(diagnosticDataClosed()));

        emit showDiagnosticDataScreen();
    }
}

void ManufacturingOptionsScreen::diagnosticDataClosed()
{
    disconnect(diagnosticDataWindowScreen, SIGNAL(dialogClose()),0,0);
}

void ManufacturingOptionsScreen::updateManufacturingOptionsProcessBeforeShow(void)
{
    QScrollBar * tScrollBar = ui->scrollAreaConfiguration->verticalScrollBar();
    tScrollBar->setValue(0);
}

void ManufacturingOptionsScreen::updateText()
{
    updateButton1Details(menufacturingSetupButton   ,Providers::getTitleTextString(MANUFACTURING_SETUP_STR),Providers::getIconString(MANUFACTURING_SETUP),Providers::getNavigationIconString());
//    updateButton1Details(blowerTestButton    ,Providers::getTitleTextString(BLOWER_TEST_APPLICATION_STR),Providers::getIconString(MASK_DRY_ICON),Providers::getNavigationIconString());
    updateButton1Details(parameterTuneButton    ,Providers::getTitleTextString(PARAMETER_TUNE_STR),Providers::getIconString(MASK_DRY_ICON),Providers::getNavigationIconString());
    updateButton1Details(diagnosticData  ,Providers::getTitleTextString(DIAGNOSTIC_DATA_STR),Providers::getIconString(DIAGNOSTIC_DATA_ICON),Providers::getNavigationIconString());
}

void ManufacturingOptionsScreen::changeEvent(QEvent* e)
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
