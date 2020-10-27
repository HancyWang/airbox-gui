#include "notificationtray.h"
#include "ui_notificationtray.h"
#include "ex_variables.h"


//layout stretch 5,5,3,0,0,1,1,1,1
NotificationTray::NotificationTray(QWidget *parent,
                                   PruControlClass * ipcBackend,
                                   DataLogging * dataLoggingBackend)
    : QDialog(parent),
    ui(new Ui::NotificationTray),
    ipcManager(ipcBackend),
    dataLogging(dataLoggingBackend),
    dateTime(nullptr),
    timer(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    move(0,0);

    system("timedatectl set-ntp false");

    if(ipcManager)
    {
        connect(ipcManager,SIGNAL(updateFlowParameter(int)),
                this,SLOT(updateFlowParameter(int)));
        connect(ipcManager,SIGNAL(updateEventTypeStatus(unsigned int )),
                this,SLOT(updateEventTypeStatus(unsigned int )));
        connect(ipcManager,SIGNAL(updateStableStatus(unsigned int )),
                this,SLOT(updateStableStatus(unsigned int )));
        connect(ipcManager,SIGNAL(updateMaskLeakStatus(unsigned int )),
                this,SLOT(updateMaskLeakStatus(unsigned int )));
        connect(ipcManager,SIGNAL(updateEnableApap(unsigned int )),
                this,SLOT(updateEnableApap(unsigned int )));
        connect(ipcManager,SIGNAL(updateHypoApneaCount(unsigned int )),
                this,SLOT(updateHypoApneaCount(unsigned int )));
        connect(ipcManager,SIGNAL(updatebreathCount(int )),
                this,SLOT(updatebreathCount(int )));
        connect(ipcManager,SIGNAL(updateLeakageCount(int )),
                this,SLOT(updateLeakageCount(int )));
    }

    if(dataLogging)
    {
        connect(dataLogging,SIGNAL(updateSdCardStatus(bool)),
                this,SLOT(updateSdCardStatus(bool)));
    }

    QFont fontValue("Roboto-Light", 8);

    QString timeStr= QTime::currentTime().toString("hh : mm");
    ui->time->setFont(fontValue);
    ui->time->setText(timeStr);

    QString dateStr = QDate::currentDate().toString("d MMM yyyy");
    ui->date->setFont(fontValue);
    ui->date->setText(dateStr);

    ui->flow->setFont(fontValue);
    ui->eventDetected->setFont(fontValue);
    ui->maskOffLeak->setFont(fontValue);
    ui->en->setFont(fontValue);
    ui->eventCountHypoApnea->setFont(fontValue);
    ui->stableUnstable->setFont(fontValue);
    ui->breathCount->setFont(fontValue);
    ui->leakageCount->setFont(fontValue);


    // Check if we should diplay the engineering data
    if(globalVar.diagnosticData == On)
    {
        ui->flow->show();
        ui->eventDetected->show();
        ui->maskOffLeak->show();
        ui->en->show();
        ui->eventCountHypoApnea->show();
        ui->stableUnstable->show();
        ui->breathCount->show();
        ui->leakageCount->show();

    }
    else
    {
        ui->flow->hide();
        ui->eventDetected->hide();
        ui->maskOffLeak->hide();
        ui->en->hide();
        ui->eventCountHypoApnea->hide();
        ui->stableUnstable->hide();
        ui->breathCount->hide();
        ui->leakageCount->hide();
    }


//    ui->flow->hide();
//    ui->eventDetected->hide();
//    ui->maskOffLeak->hide();
//    ui->en->hide();
//    ui->eventCountHypoApnea->hide();
//    ui->stableUnstable->hide();
//    ui->breathCount->hide();
//    ui->leakageCount->hide();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer->start(1000);
}

NotificationTray::~NotificationTray()
{
    delete ui;
}

void NotificationTray::updateTime(void)
{
    QString timeStr= QTime::currentTime().toString("hh : mm");
    ui->time->setText(timeStr);

//    QString dateStr = QDate::currentDate().toString("d MMM yyyy");
    QString dateStr = QDate::currentDate().toString("yyyy/MM/dd");
    ui->date->setText(dateStr);

    globalVar.systemDate.month = QDate::currentDate().month();
    globalVar.systemDate.date = QDate::currentDate().day();
    globalVar.systemDate.year = QDate::currentDate().year();

    globalVar.systemTime.hour = QTime::currentTime().hour();
    globalVar.systemTime.minute = QTime::currentTime().minute();
}

void NotificationTray::updateAirplaneModeStatus(bool state)
{
    if(state) {
        ui->airplaneModeIcon->setStyleSheet(QStringLiteral("image: url(:/icons/notification_airplane.png);"));
    } else {
        ui->airplaneModeIcon->setStyleSheet(NULL);
    }
}

void NotificationTray::updateBluetoothStatus(bool state)
{
    if(state) {
        ui->bluetoothIcon->setStyleSheet(QStringLiteral("image: url(:/icons/notification_bluetooth.png);"));
    } else {
        ui->bluetoothIcon->setStyleSheet(NULL);
    }
}

bool NotificationTray::checkSdcardVisible()
{
    return sdcardVisible;
}

void NotificationTray::updateSdCardStatus(bool state)
{
    if(state) {
        ui->sdcardIcon->setStyleSheet(QStringLiteral("image: url(:/icons/notification_sdcard.png);"));
        sdcardVisible = true;
    } else {
        ui->sdcardIcon->setStyleSheet(NULL);
        sdcardVisible = false;
    }
}

void NotificationTray::updateEventTypeStatus(unsigned int event)
{
    if(prevEventType == event)      return;
    prevEventType = event;
    switch(event)
    {
        case EVENT_TYPE_APNEA2:
            ui->eventDetected->setText("A2");
            break;
        case EVENT_TYPE_APNEA:
            ui->eventDetected->setText("A1");
            break;
        case EVENT_TYPE_HYPOAPNEA:
            ui->eventDetected->setText("H");
            break;
        case EVENT_TYPE_PRECURSOR:
            ui->eventDetected->setText("P");    //M
            break;
        case EVENT_TYPE_NONE:
            ui->eventDetected->setText(" ");
            break;
    }
}

void NotificationTray::updateEnableApap(unsigned int tEnFlag)
{
    if(prevApapEn == tEnFlag)      return;
    prevApapEn = tEnFlag;
    if(tEnFlag)     ui->en->setText("E");
    else            ui->en->setText(" ");
}

void NotificationTray::updateHypoApneaCount(unsigned int tCount)
{
    if(prevHypApneaCount == tCount)      return;
    prevHypApneaCount = tCount;
    if(!tCount)
        ui->eventCountHypoApnea->setText(" ");
    else
        ui->eventCountHypoApnea->setText(QString("%1").arg(tCount));
}

void NotificationTray::updateStableStatus(unsigned int tStableFlag)
{
    if(prevStableState == tStableFlag)      return;
    prevStableState = tStableFlag;
    switch(tStableFlag)
    {
        case EVENT_TYPE_STABLE:
            ui->stableUnstable->setText("S");
            break;
        case EVENT_TYPE_UNSTABLE:
            ui->stableUnstable->setText("U");
            break;
        case EVENT_TYPE_NONE:
            ui->stableUnstable->setText(" ");
            break;
    }
}

void NotificationTray::updateMaskLeakStatus(unsigned int tLeakState)
{
    if(prevLeakState == tLeakState)      return;
    prevLeakState = tLeakState;
    switch(tLeakState)
    {
//        case EVENT_TYPE_MASK_OFF:
//            ui->maskOffLeak->setText("M");
//            break;
        case EVENT_TYPE_LEAK:
            ui->maskOffLeak->setText("L1");
            break;
        case EVENT_TYPE_LEAK2:
            ui->maskOffLeak->setText("L2");
            break;
        case EVENT_TYPE_NONE:
            ui->maskOffLeak->setText(" ");
            break;
    }
}

void NotificationTray::updatebreathCount(int count)
{
    if(prevBreathCount == count)      return;
    prevBreathCount = count;
    if(count)   ui->breathCount->setText(QString("%1").arg(count));
    else        ui->breathCount->setText(" ");
}

void NotificationTray::updateLeakageCount(int count)
{
    if(prevLeakageCount == count)      return;
    prevLeakageCount = count;

    if(count)   ui->leakageCount->setText(QString("%1").arg(count));
    else        ui->leakageCount->setText(" ");
}

void NotificationTray::updateSystemDate(int date,int month,int year)
{
    globalVar.systemDate.month = month;
    globalVar.systemDate.date = date;
    globalVar.systemDate.year = year;

    //Old way timedatectl set-time "2018-04-27 22:51:34"
    //New way date -s "2018-04-27 22:51"
    QString timeStr= QTime::currentTime().toString("hh:mm");
//    QString timeStr= QTime::currentTime().toString("hh:mm:ss");
    QString currentDateStr = QString("\"%1-%2-%3 %4\"").arg(year).arg(month,2,10,QChar('0')).arg(date,2,10,QChar('0')).arg(timeStr);
//    QString cmdStr = "timedatectl";
//    QString shellCmd;
//    shellCmd = cmdStr + " set-time " + currentDateStr;
    QString cmdStr = "date";
    QString shellCmd;
    shellCmd = cmdStr + " -s " + currentDateStr;
    qDebug() << Q_FUNC_INFO << shellCmd.toLocal8Bit();
    system(shellCmd.toLocal8Bit());

    updateTimeToHWClock();
 }

void NotificationTray::updateSystemTime(int hour,int min,int sec)
{
    globalVar.systemTime.hour = hour;
    globalVar.systemTime.minute = min;
    Q_UNUSED(sec);

    //timedatectl set-time "2018-04-27 22:51:34"
    QString dateStr = QDate::currentDate().toString("yyyy-MM-dd");
    QString currentDateStr = QString("\"%1 %2:%3\"").arg(dateStr).arg(hour,2,10,QChar('0')).arg(min,2,10,QChar('0'));
//    QString currentDateStr = QString("\"%1 %2:%3:%4\"").arg(dateStr).arg(hour,2,10,QChar('0')).arg(min,2,10,QChar('0')).arg(sec,2,10,QChar('0'));
//    QString cmdStr = "timedatectl";
//    QString shellCmd;
//    shellCmd = cmdStr + " set-time " + currentDateStr;
    QString cmdStr = "date";
    QString shellCmd;
    shellCmd = cmdStr + " -s " + currentDateStr;
    qDebug() << Q_FUNC_INFO << shellCmd.toLocal8Bit();
    system(shellCmd.toLocal8Bit());

    updateTimeToHWClock();
}

void NotificationTray::updateTimeToHWClock()
{
    //hwclock -w -f /dev/rtc1
    QString clockStr = "hwclock";
    QString argument;
    QString finaleStr;
    argument = QString("/dev/rtc%1").arg(globalVar.rtcHwClock);
    finaleStr = clockStr + " -w -f " + argument;
    qDebug() << Q_FUNC_INFO << finaleStr.toLocal8Bit();
    system(finaleStr.toLocal8Bit());
}

void NotificationTray::updateFlowParameter(int flowData)
{
    if(previousFlowData != flowData)
    {
        previousFlowData = flowData;
        QString flowStr = QString("%1").arg(previousFlowData);
        ui->flow->setText(flowStr);
    }
}

void NotificationTray::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
