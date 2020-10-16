#include "poweroffoptions.h"
#include "ui_poweroffoptions.h"
#include "ex_variables.h"


PowerOffOptions::PowerOffOptions(QWidget *parent,
                                 BrightnessControlThread * brightnessBackend,
                                 PruControlClass * ipcBackend,
                                 WarningInfoScreen * warningBackend)
    : QDialog(parent),
    ui(new Ui::PowerOffOptions),
    brightnessControl(brightnessBackend),
    ipcManager(ipcBackend),
    warningScreen(warningBackend),
    parentEffect(nullptr),
    powerOffButton(nullptr),
    powerOffTimer(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setAttribute(Qt::WA_TranslucentBackground,true);
    move(60,56);

    if(brightnessControl)
    {
        connect(this, SIGNAL(sendBrightnessControlData(bool,int)),
                brightnessControl,SLOT(sendBrightnessControlData(bool,int)));
    }
    if(ipcManager)
    {
        connect(this,SIGNAL(pruProcessorStartStopProcess(int,QString,bool)),
                ipcManager,SLOT(pruProcessorStartStopProcess(int,QString,bool)));
    }
    if(warningScreen)
    {
        connect(warningScreen,SIGNAL(startPowerOffProcedure()),
                this,SLOT(startPowerOffProcedure()));
    }

    addButtons();

    powerOffTimer = new QTimer(this);
    connect(powerOffTimer, SIGNAL(timeout()), this, SLOT(powerOffTimerTimeout()));
}

PowerOffOptions::~PowerOffOptions()
{
    delete ui;
}

void PowerOffOptions::addButtons(void)
{
    powerOffButton        = new Button1(this);
    powerOffButton->setGeometry(QRect(74,50,200,50));

    updateButton1Details(powerOffButton       ,Providers::getTitleTextString(POWER_OFF_STR),
                         Providers::getIconString(POWER_OFF_ICON),NULL);

    connect(powerOffButton, SIGNAL(released()),SLOT(powerOffButton_released()));
}

void PowerOffOptions::updateButton1Details(Button1 * pButton,const QString &Title,const QString &imageLeft,const QString &imageRight)
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
    pButton->setFixedHeight(50);
    pButton->setFixedWidth(200);
}

void PowerOffOptions::on_powerOffCancel_released()
{
    parentEffect->setEnabled(false);
//    emit dialogClose();
    hide();
    setModal(false);
}

void PowerOffOptions::startPowerOffProcedure(void)
{
    powerOffTimer->start(1000);

    globalVar.therapyState = Off;
    globalVar.snooze.snoozePeriod = Off;
    globalVar.maskFitTest.maskFitTestState = Off;
    globalVar.maskDryState = Off;

    ui->powerOffCancel->hide();
}

void PowerOffOptions::powerOffButton_released()
{
    startPowerOffProcedure();
}

void PowerOffOptions::powerOffTimerTimeout(void)
{
    powerOffIndex--;
    qDebug() << powerOffIndex;
    if(!powerOffIndex)
    {
        emit sendBrightnessControlData(false,0);
        /* shutdown -hP now */
        /* poweroff */
        system("shutdown -hP now");
        powerOffTimer->stop();
    }
    else
    {
        emit pruProcessorStartStopProcess(2,"BLOWER_PRU1.out",false);
        emit pruProcessorStartStopProcess(1,"BLOWER_PRU0.out",false);
    }
}

void PowerOffOptions::updateText()
{
    updateButton1Details(powerOffButton       ,Providers::getTitleTextString(POWER_OFF_STR),
                         Providers::getIconString(POWER_OFF_ICON),NULL);
}

void PowerOffOptions::changeEvent(QEvent* e)
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
