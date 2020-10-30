#include "accessorieswindowclinical.h"
#include "ui_accessorieswindowclinical.h"
#include "ex_variables.h"

AccessoriesWindowClinical::AccessoriesWindowClinical(QWidget *parent,
                                                     SettingsWindowClinical * settingsClinicalBackend)
    : QDialog(parent),
    ui(new Ui::AccessoriesWindowClinical),
    settingsClinicalScreen(settingsClinicalBackend),
    m_Anim(nullptr),
    airTubeButton(nullptr),
    airFilterButton(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowState(Qt::WindowFullScreen);
    setAttribute(Qt::WA_DeleteOnClose,true);

    if(settingsClinicalScreen)
    {
        connect(settingsClinicalScreen,SIGNAL(showAccesoriesClinicalScreen()),
                this,SLOT(showAccesoriesClinicalScreen()));
    }

    QFont title("Roboto-Light",11);
    ui->titleAccessories->setFont(title);

    m_Anim = new QPropertyAnimation(this,"geometry");

    addButtons();
}

AccessoriesWindowClinical::~AccessoriesWindowClinical()
{
    delete ui;
}

void AccessoriesWindowClinical::animateSettingsWindow(openCloseStatus state)
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

void AccessoriesWindowClinical::addButtons(void)
{
    airTubeButton = new Button1(this);
    airFilterButton = new Button1(this);

    airTubeButton->setGeometry(QRect(60,63,335,56));
    airFilterButton->setGeometry(QRect(60,124,335,56));

    updateButton1Details(airTubeButton    ,Providers::getTitleTextString(AIR_TUBE_STR),Providers::getIconString(AIR_TUBE_ICON),NULL);
    updateButton1Details(airFilterButton    ,Providers::getTitleTextString(AIR_FILTER_STR),Providers::getIconString(AIR_FILTER_ICON),Providers::getNavigationIconString());

    airTubeButton->updateSubTitleText(QString("%1 mm").arg(HOSE_SIZE_MM));

    airFilterButton->updateSubTitleText(Providers::getAirFilterTypeString(globalVar.airFilter));

    //Connect all press or release eventas to their specific slots
    connect(airFilterButton, SIGNAL(clicked()),SLOT(airFilterButton_released()));
}

void AccessoriesWindowClinical::updateButton1Details(Button1 * pButton,const QString &Title,const QString &imageLeft,const QString &imageRight)
{
    QFont settingsFontTitle("Roboto-Light", 8);
    QFont settingsFontSubTitle("Roboto-Thin", 13);
    QFont fontUnit("Roboto-Light",6);

    pButton->setButtonRadius(5);
    pButton->setTitle(Title,settingsFontTitle,QColor(0xBDBDBD));
    pButton->setSubTitle(NULL,settingsFontSubTitle,QColor(0x2196F3));
    pButton->setUnit(NULL,fontUnit,QColor(0x616161));
    pButton->setBackgroundColor(0x606060,0x3e3e3e);
    pButton->setLeftRightSpacing(50,50);
    pButton->setImageLeft(0,5,24,24,imageLeft);
    pButton->setImageRight(50,10,24,24,imageRight);
}

void AccessoriesWindowClinical::on_backAccessories_released()
{
    animateSettingsWindow(Close);
}

void AccessoriesWindowClinical::airTubeButton_released()
{

}

void AccessoriesWindowClinical::airFilterButton_released()
{
    emit showAirFilterWindowClinical();
}

void AccessoriesWindowClinical::airFilterWindowClosed()
{
    updateAccessoriesWindowClinicalProcessBeforeShow();
}

void AccessoriesWindowClinical::updateAccessoriesWindowClinicalProcessBeforeShow(void)
{
    airFilterButton->updateSubTitleText(Providers::getAirFilterTypeString(globalVar.airFilter));
}

void AccessoriesWindowClinical::showAccesoriesClinicalScreen()
{
    updateAccessoriesWindowClinicalProcessBeforeShow();
    animateSettingsWindow(Open);
}

void AccessoriesWindowClinical::updateText()
{
    updateButton1Details(airTubeButton    ,Providers::getTitleTextString(AIR_TUBE_STR),Providers::getIconString(AIR_TUBE_ICON),NULL);
    updateButton1Details(airFilterButton    ,Providers::getTitleTextString(AIR_FILTER_STR),Providers::getIconString(AIR_FILTER_ICON),Providers::getNavigationIconString());

    airFilterButton->updateSubTitleText(Providers::getAirFilterTypeString(globalVar.airFilter));
}

void AccessoriesWindowClinical::changeEvent(QEvent* e)
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


