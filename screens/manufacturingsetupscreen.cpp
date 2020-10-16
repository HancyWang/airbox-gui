#include "manufacturingsetupscreen.h"
#include "ui_manufacturingsetupscreen.h"
#include <ex_variables.h>

ManufacturingSetupScreen::ManufacturingSetupScreen(QWidget *parent,
                                                   BrightnessOffsetScreen * brightnessBackend,
                                                   PressureOffsetScreen * pressureBackend,
                                                   FlowSlopScreen * flowBackend,
                                                   EnterSerialNumber * serialNumberBackend,
                                                   DateWindowClinical * dateBackend,
                                                   TimeWindowClinical * timeBackend,
                                                   ManufacturingOptionsScreen * manufacturingOptionsBackend,
                                                   NotificationTray * notificationBackend)
    : QDialog(parent),
    ui(new Ui::ManufacturingSetupScreen),
    brightnessScreen(brightnessBackend),
    pressureScreen(pressureBackend),
    flowScreen(flowBackend),
    serialNumberScreen(serialNumberBackend),
    dateScreen(dateBackend),
    timeScreen(timeBackend),
    manufacturingOptionsScreen(manufacturingOptionsBackend),
    notificationScreen(notificationBackend),
    brightnessOffsetButton(nullptr),
    pressureSensorOffsetButton(nullptr),
    flowSensorSlopButton(nullptr),
    serialNumberButton(nullptr),
    dateButton(nullptr),
    timeButton(nullptr),
    timeUpdateTimer(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setWindowState(Qt::WindowFullScreen);
    setGeometry(0,0,width(),height());

    if(brightnessScreen)
    {
        connect(this,SIGNAL(showBrightnessOffsetScreen()),
                brightnessScreen,SLOT(showBrightnessOffsetScreen()));
    }

    if(pressureScreen)
    {
        connect(this,SIGNAL(showPressureOffsetScreen()),
                pressureScreen,SLOT(showPressureOffsetScreen()));
    }

    if(flowScreen)
    {
        connect(this,SIGNAL(showFlowSlopScreen()),
                flowScreen,SLOT(showFlowSlopScreen()));
    }

    if(serialNumberScreen)
    {
        connect(this,SIGNAL(showEnterSerialNumberScreen()),
                serialNumberScreen,SLOT(showEnterSerialNumberScreen()));
    }

    if(dateScreen)
    {
        connect(this,SIGNAL(showDateScreen(QWidget*,int,int,int,bool)),
                dateScreen,SLOT(showDateScreen(QWidget*,int,int,int,bool)));
    }

    if(timeScreen)
    {
        connect(this,SIGNAL(showTimeScreen(QWidget*,int,int,bool)),
                timeScreen,SLOT(showTimeScreen(QWidget*,int,int,bool)));
    }

    if(manufacturingOptionsScreen)
    {
        connect(manufacturingOptionsScreen,SIGNAL(showManufacturingSetupScreen()),
                this,SLOT(showManufacturingSetupScreen()));
    }

    if(notificationScreen)
    {
        connect(this,SIGNAL(updateSystemDate(int,int,int)),
                notificationScreen,SLOT(updateSystemDate(int,int,int)));
        connect(this,SIGNAL(updateSystemTime(int,int,int)),
                notificationScreen,SLOT(updateSystemTime(int,int,int)));
    }

    QFont title("Roboto-Light",12);
    ui->titleManufacturingSetup->setFont(title);

    setupWindowParameters();

    timeUpdateTimer = new QTimer(this);
    connect(timeUpdateTimer, SIGNAL(timeout()), this, SLOT(timeUpdateTimerTimeout()));
}

ManufacturingSetupScreen::~ManufacturingSetupScreen()
{
    delete ui;
}

void ManufacturingSetupScreen::timeUpdateTimerTimeout()
{
    updateTimeInLocalWindow();
    updateDateInLocalWindow();
}

void ManufacturingSetupScreen::showManufacturingSetupScreen()
{
    updateManufacturingSetupProcessBeforeShow();
    show();
}

void ManufacturingSetupScreen::setupWindowParameters(void)
{
    brightnessOffsetButton      = new Button1(this);
    pressureSensorOffsetButton  = new Button1(this);
    flowSensorSlopButton      = new Button1(this);
    serialNumberButton          = new Button1(this);
    dateButton                  = new Button1(this);
    timeButton                  = new Button1(this);

    ui->scrollAreaWidgetContentsManufacturingSetup->setLayout(ui->verticalLayoutManufacturingSetup);
    ui->scrollAreaManufacturingSetup->setStyleSheet(QStringLiteral("border:none;"));

    updateButton1Details(brightnessOffsetButton,"Brightness Offset",Providers::getNavigationIconString());
    updateButton1Details(pressureSensorOffsetButton,"Pressure Sensor Offset",Providers::getNavigationIconString());
    updateButton1Details(flowSensorSlopButton,"Flow Threshold",Providers::getNavigationIconString());
//    updateButton1Details(flowSensorSlopButton,"Flow Sensor Slop",Providers::getNavigationIconString());
    updateButton1Details(serialNumberButton,"Serial Number",Providers::getNavigationIconString());
    updateButton1Details(dateButton,"Date",Providers::getNavigationIconString());
    updateButton1Details(timeButton,"Time",Providers::getNavigationIconString());

    //Enable Scrolling mechanism for scroll area
    QScroller::grabGesture(ui->scrollAreaManufacturingSetup->viewport(),QScroller::LeftMouseButtonGesture);

    //Connect all press or release eventas to their specific slots
    connect(brightnessOffsetButton, SIGNAL(released()),SLOT(brightnessOffsetButton_released()));
    connect(pressureSensorOffsetButton, SIGNAL(released()),SLOT(pressureSensorOffsetButton_released()));
    connect(flowSensorSlopButton, SIGNAL(released()),SLOT(flowSensorSlopButton_released()));
    connect(serialNumberButton, SIGNAL(released()),SLOT(serialNumberButton_released()));
    connect(dateButton, SIGNAL(released()),SLOT(dateButton_released()));
    connect(timeButton, SIGNAL(released()),SLOT(timeButton_released()));
}

void ManufacturingSetupScreen::updateButton1Details(Button1 * pButton,const QString &Title,const QString &imageRight)
{
    QFont settingsFontTitle("Roboto-Light", 8);
    QFont settingsFontSubTitle("Roboto-Thin", 14);
    QFont setingsFontUnit("Roboto-Light",7);

    pButton->setButtonRadius(5);
    pButton->setTitle(Title,settingsFontTitle,QColor(0xBDBDBD));
    pButton->setSubTitle(NULL,settingsFontSubTitle,QColor(0x2196F3));
    pButton->setUnit(NULL,setingsFontUnit,QColor(0x616161));
    pButton->setBackgroundColor(0x606060,0x3e3e3e);
    pButton->setLeftRightSpacing(20,50);
    pButton->setImageRight(50,10,24,24,imageRight);
    pButton->setFixedHeight(56);
    pButton->setFixedWidth(350);

    ui->verticalLayoutManufacturingSetup->addWidget(pButton);
}

void ManufacturingSetupScreen::updateManufacturingSetupProcessBeforeShow(void)
{
    updateTimeInLocalWindow();
    updateDateInLocalWindow();
    updateSerialNumberInLocalWindow();
    updatePressureSensorInLocalWindow();
    updateFlowSensorInLocalWindow();
    timeUpdateTimer->start(1000);

    QScrollBar * tScrollBar = ui->scrollAreaManufacturingSetup->verticalScrollBar();
    tScrollBar->setValue(0);
}

void ManufacturingSetupScreen::brightnessOffsetButton_released()
{
    emit showBrightnessOffsetScreen();
}

void ManufacturingSetupScreen::updatePressureSensorInLocalWindow(void)
{
    pressureSensorOffsetButton->updateSubTitleText(QString::number(globalVar.pressure.pressureOffset));
}

void ManufacturingSetupScreen::pressureSensorOffsetButton_released()
{
    connect(pressureScreen, SIGNAL(dialogClose()),
            this,SLOT(pressureSensorOffsetWindowClosed()));

    emit showPressureOffsetScreen();
}

void ManufacturingSetupScreen::pressureSensorOffsetWindowClosed()
{
    updatePressureSensorInLocalWindow();
    disconnect(pressureScreen, SIGNAL(dialogClose()),0,0);
}

void ManufacturingSetupScreen::updateFlowSensorInLocalWindow(void)
{
    flowSensorSlopButton->updateSubTitleText(QString::number(globalVar.flow.threshold));
}

void ManufacturingSetupScreen::flowSensorSlopButton_released()
{
    connect(flowScreen, SIGNAL(dialogClose()),
            this,SLOT(flowSensorSlopWindowClosed()));

    emit showFlowSlopScreen();
}

void ManufacturingSetupScreen::flowSensorSlopWindowClosed()
{
    updateFlowSensorInLocalWindow();
    disconnect(flowScreen, SIGNAL(dialogClose()),0,0);
}

void ManufacturingSetupScreen::serialNumberButton_released()
{
    connect(serialNumberScreen, SIGNAL(dialogClose()),
            this,SLOT(serialNumberWindowClosed()));

    emit showEnterSerialNumberScreen();
}

void ManufacturingSetupScreen::dateButton_released()
{
    if(dateScreen)
    {
        disconnect(dateScreen, SIGNAL(screenClose(int,int,int)),0,0);
        connect(dateScreen,SIGNAL(screenClose(int,int,int)),
                this,SLOT(dateWindowClosed(int,int,int)));

        emit showDateScreen(this,globalVar.systemDate.date,
                            globalVar.systemDate.month,
                            globalVar.systemDate.year,true);
    }
}

void ManufacturingSetupScreen::dateWindowClosed(int date, int month, int year)
{
    globalVar.systemDate.date = date + 1;
    globalVar.systemDate.month = month + 1;
    globalVar.systemDate.year = year;

    emit updateSystemDate(globalVar.systemDate.date,globalVar.systemDate.month,globalVar.systemDate.year);
    updateDateInLocalWindow();
    disconnect(dateScreen,SIGNAL(screenClose(int,int,int)),0,0);
}

void ManufacturingSetupScreen::timeButton_released()
{
    if(timeScreen)
    {
        disconnect(timeScreen, SIGNAL(screenClose(int,int)),0,0);
        connect(timeScreen,SIGNAL(screenClose(int,int)),
                this,SLOT(timeWindowClosed(int,int)));

        emit showTimeScreen(this->parentWidget(),
                            globalVar.systemTime.hour,
                            globalVar.systemTime.minute,true);
    }
}

void ManufacturingSetupScreen::timeWindowClosed(int hour, int minute)
{
    globalVar.systemTime.hour = hour;
    globalVar.systemTime.minute = minute;

    emit updateSystemTime(globalVar.systemTime.hour,globalVar.systemTime.minute,0);
    updateTimeInLocalWindow();
    disconnect(timeScreen, SIGNAL(screenClose(int,int)),0,0);

}

void ManufacturingSetupScreen::serialNumberWindowClosed()
{
    updateSerialNumberInLocalWindow();
    disconnect(serialNumberScreen, SIGNAL(dialogClose()),0,0);
}

void ManufacturingSetupScreen::updateTimeInLocalWindow(void)
{
    QString timeStr = QString("%1:%2").arg(globalVar.systemTime.hour,2,10,QChar('0')).arg(globalVar.systemTime.minute,2,10,QChar('0'));
    timeButton->updateSubTitleText(timeStr);
}

void ManufacturingSetupScreen::updateDateInLocalWindow(void)
{
    QString dateStr = QString("%1 %2 %3").arg(globalVar.systemDate.date).arg(Providers::getMonthsTextString(globalVar.systemDate.month - 1)).arg(globalVar.systemDate.year);
    dateButton->updateSubTitleText(dateStr);
}

void ManufacturingSetupScreen::updateSerialNumberInLocalWindow(void)
{
    serialNumberButton->updateSubTitleText(globalVar.serialNumberStr);
}

void ManufacturingSetupScreen::on_backManufacturingSetup_released()
{
    timeUpdateTimer->stop();
    hide();
}


void ManufacturingSetupScreen::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
