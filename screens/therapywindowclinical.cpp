#include "therapywindowclinical.h"
#include "ui_therapywindowclinical.h"
#include "ex_variables.h"



const QStringList TherapyWindowClinical::modeString =
{
    "PAP",
    "APAP"
};


TherapyWindowClinical::TherapyWindowClinical(QWidget *parent,
                                             SettingsWindowClinical * settingsClinicalBackend,
                                             SetPressureClinical * setPressureBackend,
                                             ModeWindowTherapyClinical * modeBackend,
                                             MaskOptionsTherapyWindowClinical * maskClinicalBackend,
                                             SetMinPressureClinical * minPressureBackend,
                                             SetMaxPressureClinical * maxPressureBackend)
    : QDialog(parent),
    ui(new Ui::TherapyWindowClinical),
    settingsClinicalScreen(settingsClinicalBackend),
    setPressureScreen(setPressureBackend),
    modeScreen(modeBackend),
    maskClinicalScreen(maskClinicalBackend),
    minPressureScreen(minPressureBackend),
    maxPressureScreen(maxPressureBackend),
    m_Anim(nullptr),
    modeButton(nullptr),
    setPressureButton(nullptr),
    maskButton(nullptr),
    minPressureButton(nullptr),
    maxPressureButton(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setWindowState(Qt::WindowFullScreen);
    setGeometry(0,0,width(),height());

    if(settingsClinicalScreen)
    {
        connect(settingsClinicalScreen,SIGNAL(showTherapyClinicalScreen()),
                this,SLOT(showTherapyClinicalScreen()));
    }

    if(setPressureScreen)
    {
        connect(this, SIGNAL(showSetPressureScreen()),
                setPressureScreen,SLOT(showSetPressureScreen()));
    }

    if(modeScreen)
    {
        connect(this, SIGNAL(showModeScreen()),
                modeScreen,SLOT(showModeScreen()));
    }

    if(maskClinicalScreen)
    {
        connect(this, SIGNAL(showMaskOptionClinicalScreen()),
                maskClinicalScreen,SLOT(showMaskOptionClinicalScreen()));
    }

    if(minPressureScreen)
    {
        connect(this, SIGNAL(showMinPressureScreen()),
                minPressureScreen,SLOT(showMinPressureScreen()));
    }

    if(maxPressureScreen)
    {
        connect(this, SIGNAL(showMaxPressureScreen()),
                maxPressureScreen,SLOT(showMaxPressureScreen()));
    }

    QFont title("Roboto-Light",12);
    ui->titleTherapy->setFont(title);

    m_Anim = new QPropertyAnimation(this,"geometry");

    addButtons();
}

TherapyWindowClinical::~TherapyWindowClinical()
{
    delete ui;
}

void TherapyWindowClinical::addButtons(void)
{
    modeButton = new Button1(this);
    setPressureButton = new Button1(this);
    maskButton = new Button1(this);
    minPressureButton = new Button1(this);
    maxPressureButton = new Button1(this);

    ui->scrollAreaWidgetContentsSettings->setLayout(ui->verticalLayoutSettings);
    ui->scrollAreaSettings->setStyleSheet(QStringLiteral("border:none;"));

    updateButton1Details(modeButton        ,Providers::getTitleTextString(MODE_STR),Providers::getIconString(MODE_ICON),Providers::getNavigationIconString());
    updateButton1Details(setPressureButton ,Providers::getTitleTextString(SET_PRESSURE_STR),Providers::getIconString(SET_PRESSURE_ICON),Providers::getNavigationIconString());
    updateButton1Details(minPressureButton ,Providers::getTitleTextString(SET_MIN_PRESSURE_STR),Providers::getIconString(SET_PRESSURE_ICON),Providers::getNavigationIconString());
    updateButton1Details(maxPressureButton ,Providers::getTitleTextString(SET_MAX_PRESSURE_STR),Providers::getIconString(SET_PRESSURE_ICON),Providers::getNavigationIconString());
    updateButton1Details(maskButton        ,Providers::getTitleTextString(MASK_STR),Providers::getIconString(MASK_ICON),Providers::getNavigationIconString());

    setPressureButton->updateUnitText(Providers::getPressureUnitTextString(globalVar.pressureUnit));
    setPressureButton->setUnitVisibility(true);

    minPressureButton->updateUnitText(Providers::getPressureUnitTextString(globalVar.pressureUnit));
    minPressureButton->setUnitVisibility(true);

    maxPressureButton->updateUnitText(Providers::getPressureUnitTextString(globalVar.pressureUnit));
    maxPressureButton->setUnitVisibility(true);

    //Enable Scrolling mechanism for scroll area
    QScroller::grabGesture(ui->scrollAreaSettings->viewport(),QScroller::LeftMouseButtonGesture);

    //Connect all press or release eventas to their specific slots
    connect(setPressureButton, SIGNAL(clicked()),SLOT(setPressureButton_released()));
    connect(modeButton, SIGNAL(clicked()),SLOT(modeButton_released()));
    connect(maskButton, SIGNAL(clicked()),SLOT(maskButton_released()));
    connect(minPressureButton, SIGNAL(clicked()),SLOT(minPressureButton_released()));
    connect(maxPressureButton, SIGNAL(clicked()),SLOT(maxPressureButton_released()));

    updateTherapyWindowProcessBeforeShow();
}

void TherapyWindowClinical::updateButton1Details(Button1 * pButton,const QString &Title,const QString &imageLeft,const QString &imageRight)
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
void TherapyWindowClinical::animateSettingsWindow(openCloseStatus state)
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

void TherapyWindowClinical::setPressureButton_released()
{
    connect(setPressureScreen, SIGNAL(dialogClose()),
            this,SLOT(setPressureClosed()));

    emit showSetPressureScreen();
}

void TherapyWindowClinical::modeButton_released()
{
    connect(modeScreen, SIGNAL(dialogClose()),
            this,SLOT(modeWindowClosed()));

    emit showModeScreen();
}

void TherapyWindowClinical::modeWindowClosed()
{
    updateModeInTherapyWindow();
    disconnect(modeScreen, SIGNAL(dialogClose()),0,0);
}

void TherapyWindowClinical::setPressureClosed()
{
    updateSetPressureInTherapyWindow();
    disconnect(setPressureScreen, SIGNAL(dialogClose()),0,0);
}

void TherapyWindowClinical::maskButton_released()
{
    connect(maskClinicalScreen, SIGNAL(dialogClose()),
            this,SLOT(maskButtonClosed()));

    emit showMaskOptionClinicalScreen();
}

void TherapyWindowClinical::maskButtonClosed()
{
    updateMaskInTherapyWindow();
    disconnect(maskClinicalScreen, SIGNAL(dialogClose()),0,0);
}

void TherapyWindowClinical::minPressureButton_released()
{
    connect(minPressureScreen, SIGNAL(dialogClose()),
            this,SLOT(minPressureClosed()));

    emit showMinPressureScreen();
}

void TherapyWindowClinical::minPressureClosed()
{
    updateSetMinPressureInTherapyWindow();
    disconnect(minPressureScreen, SIGNAL(dialogClose()),0,0);
}

void TherapyWindowClinical::maxPressureButton_released()
{
    connect(maxPressureScreen, SIGNAL(dialogClose()),
            this,SLOT(maxPressureClosed()));
    emit showMaxPressureScreen();
}

void TherapyWindowClinical::maxPressureClosed()
{
    updateSetMaxPressureInTherapyWindow();
    disconnect(maxPressureScreen, SIGNAL(dialogClose()),0,0);
}

void TherapyWindowClinical::on_backTherapy_released()
{
    animateSettingsWindow(Close);
}
void TherapyWindowClinical::updateSetPressureInTherapyWindow(void)
{
    QString str = QString::number(globalVar.pressure.targetedPressure);
    setPressureButton->updateSubTitleText(str);
}
void TherapyWindowClinical::updateSetMinPressureInTherapyWindow(void)
{
    QString str = QString::number(globalVar.pressure.apapMinPressure);
    minPressureButton->updateSubTitleText(str);
}
void TherapyWindowClinical::updateSetMaxPressureInTherapyWindow(void)
{
    QString str = QString::number(globalVar.pressure.apapMaxPressure);
    maxPressureButton->updateSubTitleText(str);
}
void TherapyWindowClinical::updateModeInTherapyWindow(void)
{
    updateScrollbarView();
    modeButton->updateSubTitleText(modeString.at(globalVar.therapyMode));
    if(globalVar.therapyMode == cpapMode){
        setPressureButton->show();
        maxPressureButton->hide();
        minPressureButton->hide();
    } else {
        setPressureButton->hide();
        maxPressureButton->show();
        minPressureButton->show();
    }
}
void TherapyWindowClinical::updateMaskInTherapyWindow(void)
{
    maskButton->updateSubTitleText(Providers::getMaskTypeString(globalVar.maskType));
}

void TherapyWindowClinical::updateScrollbarView(void)
{
    QScrollBar * tScrollArea;
    tScrollArea = ui->scrollAreaSettings->verticalScrollBar();
    if(globalVar.therapyMode == cpapMode){
        /* Hide Scrollbar */
        tScrollArea->hide();
    } else if(globalVar.therapyMode == apapMode){
        /* Show Scrollbar */
        tScrollArea->show();
    }
}

void TherapyWindowClinical::showTherapyClinicalScreen()
{
    updateTherapyWindowProcessBeforeShow();
    animateSettingsWindow(Open);
}

void TherapyWindowClinical::updateTherapyWindowProcessBeforeShow(void)
{
    updateSetPressureInTherapyWindow();
    updateSetMinPressureInTherapyWindow();
    updateSetMaxPressureInTherapyWindow();
    updateModeInTherapyWindow();
    updateMaskInTherapyWindow();

    QScrollBar * tScrollBar = ui->scrollAreaSettings->verticalScrollBar();
    tScrollBar->setValue(0);
}

void TherapyWindowClinical::updateText()
{
    updateButton1Details(modeButton        ,Providers::getTitleTextString(MODE_STR),Providers::getIconString(MODE_ICON),Providers::getNavigationIconString());
    updateButton1Details(setPressureButton ,Providers::getTitleTextString(SET_PRESSURE_STR),Providers::getIconString(SET_PRESSURE_ICON),Providers::getNavigationIconString());
    updateButton1Details(minPressureButton ,Providers::getTitleTextString(SET_MIN_PRESSURE_STR),Providers::getIconString(SET_PRESSURE_ICON),Providers::getNavigationIconString());
    updateButton1Details(maxPressureButton ,Providers::getTitleTextString(SET_MAX_PRESSURE_STR),Providers::getIconString(SET_PRESSURE_ICON),Providers::getNavigationIconString());
    updateButton1Details(maskButton        ,Providers::getTitleTextString(MASK_STR),Providers::getIconString(MASK_ICON),Providers::getNavigationIconString());
}

void TherapyWindowClinical::changeEvent(QEvent* e)
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
