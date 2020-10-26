#include "constants.h"
#include "therapywindowbasic.h"
#include "ui_therapywindowbasic.h"
#include "ex_variables.h"


int TherapyWindowBasic::goToSleepTimeSeconds = 0;
int TherapyWindowBasic::rampTimeSeconds = 0;

//const QStringList TherapyWindowBasic::therapyStateStr =
//{
//    "Start Therapy",
//    "Stop Therapy"
//};

const QStringList TherapyWindowBasic::iconTherapyStateStr =
{
    ":/icons/start_therapy.png",
    ":/icons/stop_therapy.png"
};


TherapyWindowBasic::TherapyWindowBasic(QWidget *parent,
                                       DataLogging * m_DataBackend,
                                       HomeWindowBasic * m_HomeWindowBackend,
                                       PruControlClass * m_IpcBackend,
                                       GoToSleepSettingsBasic * gotosleepBackend,
                                       RampStartSettingsBasic * rampTimeBackend,
                                       SnoozeExitScreenBasic * snoozeExitBackend,
                                       NotificationTray * notificationBackend)
    : QDialog(parent),
    ui(new Ui::TherapyWindowBasic),
    m_DataManager(m_DataBackend),
    m_HomeWindow(m_HomeWindowBackend),
    m_IpcManager(m_IpcBackend),
    gotosleepScreen(gotosleepBackend),
    rampTimeScreen(rampTimeBackend),
    snoozeExitScreen(snoozeExitBackend),
    notificationScreen(notificationBackend),
    m_Anim(nullptr),
    startStopTherapyButton(nullptr),
    therapyPressure(nullptr),
    secondsTimer(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowState(Qt::WindowFullScreen);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setGeometry(0,0,width(),height());

    if(m_DataManager)
    {
        connect(this,SIGNAL(therapyStartFilesProcess()),m_DataManager,SLOT(therapyStartFilesProcess()));
        connect(this,SIGNAL(therapyStopFilesProcess()),m_DataManager,SLOT(therapyStopFilesProcess()));
    }

    if(m_HomeWindow)
    {
        connect(m_HomeWindow,SIGNAL(showHomeWindowBasic()),this,SLOT(showHomeWindowBasic()));
    }

    if(m_IpcManager)
    {
        connect(this,SIGNAL(beforeStartTherapyProcedure()),
                m_IpcManager,SLOT(beforeStartTherapyProcedure()));
        connect(m_IpcManager,SIGNAL(processGotoSleepRampRuntime()),
                this,SLOT(processGotoSleepRampRuntime()));
        connect(m_IpcManager,SIGNAL(updateStartStopTherapyDetails()),
                this,SLOT(updateStartStopTherapyDetails()));
        connect(m_IpcManager,SIGNAL(updateCurrentWindowParameter(int)),
                this,SLOT(updateCurrentWindowParameter(int)));
        connect(m_IpcManager,SIGNAL(updateReferenceWindowParameter(int)),
                this,SLOT(updateReferenceWindowParameter(int)));
    }

    if(gotosleepScreen)
    {
        connect(gotosleepScreen,SIGNAL(updateTherapyGoToSleepTimeParameter()),
                this,SLOT(updateTherapyGoToSleepTimeParameter()));
    }

    if(rampTimeScreen)
    {
        connect(rampTimeScreen,SIGNAL(updateTherapyRampTimeParameter()),
                this,SLOT(updateTherapyRampTimeParameter()));
    }

    if(snoozeExitScreen)
    {
        connect(snoozeExitScreen,SIGNAL(showHideSnoozeTimeFrame(bool)),
                this,SLOT(showHideSnoozeTimeFrame(bool)));
    }

    if(notificationScreen)
    {
        connect(this,SIGNAL(updateFlowParameter(int)),
                notificationScreen,SLOT(updateFlowParameter(int)));
        connect(this,SIGNAL(updateEventTypeStatus(unsigned int )),
                notificationScreen,SLOT(updateEventTypeStatus(unsigned int )));
        connect(this,SIGNAL(updateStableStatus(unsigned int )),
                notificationScreen,SLOT(updateStableStatus(unsigned int )));
        connect(this,SIGNAL(updateMaskLeakStatus(unsigned int )),
                notificationScreen,SLOT(updateMaskLeakStatus(unsigned int )));
        connect(this,SIGNAL(updateEnableApap(unsigned int )),
                notificationScreen,SLOT(updateEnableApap(unsigned int )));
        connect(this,SIGNAL(updateHypoApneaCount(unsigned int )),
                notificationScreen,SLOT(updateHypoApneaCount(unsigned int )));
        connect(this,SIGNAL(updatebreathCount(int )),
                notificationScreen,SLOT(updatebreathCount(int )));
        connect(this,SIGNAL(updateLeakageCount(int )),
                notificationScreen,SLOT(updateLeakageCount(int )));
    }

    secondsTimer = new QTimer(this);

    m_Anim = new QPropertyAnimation(this,"geometry");

    //181,55,182,150
    therapyPressure = new TherapyWidget(this);
    therapyPressure->setGeometry(QRect(151,52,182,150));
    therapyPressure->setLayoutGeometry(QRect(0,40,182,110));
    therapyPressure->setBarSize(18);
    therapyPressure->setLeftRightAngles(220,260);

    QFont presBarfontTitle("Roboto-Light", 8);
    QFont fontValue("Roboto-Regular", 26);

    therapyPressure->setUnitProperties(tr("cmH<sub>2</sub>O"),presBarfontTitle,QStringLiteral("color:#666666;"));
//    therapyPressure->setPressureValueProps(fontValue,0x1779BA);
    therapyPressure->setValueProperties(fontValue,QStringLiteral("color:#1779BA;"));
    therapyPressure->setTitleProperties(tr("Set Pressure"),presBarfontTitle,QStringLiteral("color:#BDBDBD;"));
    fontValue.setPointSize(14);
    therapyPressure->setSubValueProperties(fontValue,QStringLiteral("color:#BDBDBD;"));
    therapyPressure->setPressure(globalVar.pressure.currentPressure);
//    therapyPressure->setPressure(25);
//    therapyPressure->setmaxPressure(globalVar.pressure.apapMaxPressure);
    therapyPressure->setmaxPressure(globalVar.pressure.apapMaxPressure  * 100);
    therapyPressure->setFillBarVisibleState(true);
    therapyPressure->setFillBarColor(THERAPY_NORMAL_FILL_COLOR);
    therapyPressure->setBlankBarColor(THERAPY_NORMAL_BLANK_COLOR);
    therapyPressure->setSubValue(15);

    QFont fontTitle("Roboto-Light", 8);
    startStopTherapyButton = new Button3(this);
    startStopTherapyButton->setGeometry(QRect(17,207,145,60));
    startStopTherapyButton->setButtonRadius(5);
    startStopTherapyButton->setTitle(tr("Start Therapy"),fontTitle,QColor(0xFFFFFF));
    startStopTherapyButton->setTextSpacing(32);
    startStopTherapyButton->setImage(iconTherapyStateStr.at(0));
    startStopTherapyButton->setBackgroundColor(0x3B3B3B,0x606060);

    connect(startStopTherapyButton, SIGNAL(released()),SLOT(startStopTherapyButton_released()));

    QFont title("Roboto-Light",12);
    ui->therapyTitle->setFont(title);

    ui->goToSleepTitle->setFont(fontTitle);
    ui->rampTimeTitle->setFont(fontTitle);

    title.setPointSize(7);
    ui->goToSleepUnit->setFont(title);
    ui->rampTimeUnit->setFont(title);

    QFont value("Roboto-Thin",22);
    ui->goToSleepTime->setFont(value);
    ui->rampTime->setFont(value);

    value.setPointSize(10);
    ui->goToSleepRemainingTime->setFont(value);
    ui->rampTimeRemainingTime->setFont(value);

//    updateTherapyBasicProcessBeforeShow();

    if(globalVar.therapyState == On){
        startStopTherapyButton->setTitleText(tr("Stop Therapy"));
        startStopTherapyButton->setImage(iconTherapyStateStr.at(1));
    } else {
        startStopTherapyButton->setTitleText(tr("Start Therapy"));
        startStopTherapyButton->setImage(iconTherapyStateStr.at(0));

        globalVar.rampTime.countMinutes = globalVar.rampTime.rampTime;
        globalVar.goToSleep.countMinutes = globalVar.goToSleep.goToSleepTime;
    }

    QFont extraValue("Roboto-Light", 8);
    ui->cTitle->setFont(extraValue);
    ui->rTitle->setFont(extraValue);
    ui->currentWindow->setFont(extraValue);
    ui->referenceWindow->setFont(extraValue);

    updateCurrentWindowParameter(0);
    updateReferenceWindowParameter(0);

    ui->changeParameterButton->hide();
}

void TherapyWindowBasic::animateTherapyWindow(openCloseStatus state)
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


TherapyWindowBasic::~TherapyWindowBasic()
{
    delete ui;
}

void TherapyWindowBasic::on_homeTherapyButton_released()
{
    if(globalVar.therapyState == On)
    {
        startStopTherapyButton_released();
//        globalVar.therapyState = Off;
//        processStartStopTherapy();
    }
    animateTherapyWindow(Close);
}

void TherapyWindowBasic::updatePressureAsPerMode(void)
{
//    qDebug() << "updatePressureAsPerMode()" << globalVar.therapyMode << globalVar.pressure.targetedPressure << globalVar.pressure.setPressure
//                << globalVar.pressure.apapMaxPressure << globalVar.pressure.apapMinPressure;

    if(globalVar.therapyMode == cpapMode)
    {
        therapyPressure->setmaxPressure(globalVar.pressure.targetedPressure);
        therapyPressure->setSubValue(globalVar.pressure.targetedPressure);
    }
    else
    {
        therapyPressure->setmaxPressure(globalVar.pressure.apapMaxPressure);
        therapyPressure->setSubValue(globalVar.pressure.apapMinPressure);
    }

    therapyPressure->setPressure(globalVar.pressure.setPressure);
}

void TherapyWindowBasic::updateTherapyBasicProcessBeforeShow(void)
{
    updateTherapyGoToSleepTimeParameter();
    updateTherapyRampTimeParameter();
    updatePressureAsPerMode();

    globalVar.therapyPeriod = RampTime;
    updatePressureGraphAsPerMode(globalVar.therapyPeriod);

//    if(globalVar.snooze.snoozePeriod == On){
//        ui->snoozeDisplayFrame->show();
//    } else {
        ui->snoozeDisplayFrame->hide();
//    }

}

void TherapyWindowBasic::updateTherapyGoToSleepTimeParameter(void)
{
    int tGoToSleepMinutes=0,tGoToSleepSeconds=0;
    Providers providers;
    providers.getGoToSleepTime(&tGoToSleepMinutes,&tGoToSleepSeconds);

    QString gtsStr = QString::number(tGoToSleepMinutes);
    ui->goToSleepTime->setText(gtsStr);
    if(globalVar.therapyState == false)
    {
        globalVar.goToSleep.countMinutes = tGoToSleepMinutes;
        globalVar.goToSleep.countSeconds = tGoToSleepSeconds;
        updateGoToSleepTime();
    }
}

void TherapyWindowBasic::updateTherapyRampTimeParameter(void)
{
    int tRampMinutes=0,tRampSeconds=0;
    Providers providers;
    providers.getRampTime(&tRampMinutes,&tRampSeconds);

    QString rampStr = QString::number(tRampMinutes);
    ui->rampTime->setText(rampStr);
    if(globalVar.therapyState == false)
    {
        globalVar.rampTime.countMinutes = tRampMinutes;
        globalVar.rampTime.countSeconds = tRampSeconds;
        updateRampTime();
    }
}

void TherapyWindowBasic::updateStartStopTherapyDetails(void)
{
    if(globalVar.therapyState == On)
    {
        startStopTherapyButton->setTitleText(tr("Stop Therapy"));
        startStopTherapyButton->setImage(iconTherapyStateStr.at(1));
        startTherapyProcedure();
    }
    else
    {
        startStopTherapyButton->setTitleText(tr("Start Therapy"));
        startStopTherapyButton->setImage(iconTherapyStateStr.at(0));
        stopTherapyProcedure();

        globalVar.goToSleep.isRunning = false;
        globalVar.rampTime.isRunning = false;
    }


    updateTherapyBasicProcessBeforeShow();
//    updateRemainingTimeOnStartStop();

    //TODO Remove in production
    emit updateEventTypeStatus(EVENT_TYPE_NONE);
    emit updateStableStatus(EVENT_TYPE_NONE);
    emit updateMaskLeakStatus(EVENT_TYPE_NONE);
    emit updateEnableApap(0);
    emit updateHypoApneaCount(0);
    emit updatebreathCount(0);
    emit updateFlowParameter(0);
    emit updateLeakageCount(0);

    updateCurrentWindowParameter(0);
    updateReferenceWindowParameter(0);
}

//void TherapyWindowBasic::processGotoSleepRampRuntime(unsigned int therapy_period,unsigned int count)
void TherapyWindowBasic::processGotoSleepRampRuntime(void)
{
    updateGoToSleepTime();
    updateRampTime();
    updateSnoozeTime();

    if((globalVar.snooze.countMinutes == 0) & (globalVar.snooze.countSeconds == 0))
        showHideSnoozeTimeFrame(false);

    updatePressureGraphAsPerMode(globalVar.therapyPeriod);

    updatePressureAsPerMode();
}

void TherapyWindowBasic::processStartStopTherapy(void)
{
    updateStartStopTherapyDetails();
}

void TherapyWindowBasic::startStopTherapyButton_released()
{
    globalVar.therapyState = static_cast<OnOff>(!globalVar.therapyState);
    processStartStopTherapy();

    emit beforeStartTherapyProcedure();
}

void TherapyWindowBasic::startTherapyProcedure(void)
{
    globalVar.therapyState = On;

    if(goToSleepTimeSeconds)          globalVar.therapyPeriod = GoToSleep;
    else if(rampTimeSeconds)          globalVar.therapyPeriod = RampTime;
    else                              globalVar.therapyPeriod = Therapy;

    emit therapyStartFilesProcess();
}

void TherapyWindowBasic::updateRemainingTimeOnStartStop(void)
{

    qDebug() << "updateRemainingTimeOnStartStop()";
    globalVar.goToSleep.countMinutes = globalVar.goToSleep.goToSleepTime;
    globalVar.goToSleep.countSeconds = 0;

    goToSleepTimeSeconds = (globalVar.goToSleep.goToSleepTime * 60);
    updateTherapyGoToSleepTimeParameter();

    globalVar.rampTime.countMinutes = globalVar.rampTime.rampTime;
    globalVar.rampTime.countSeconds = 0;
    rampTimeSeconds = (globalVar.rampTime.rampTime * 60);
    updateTherapyRampTimeParameter();

    globalVar.snooze.countMinutes = globalVar.snooze.snoozeTime;
    globalVar.snooze.countSeconds = 0;

    updateRemainingTime();
}

void TherapyWindowBasic::stopTherapyProcedure(void)
{
    globalVar.pressure.setPressure = 0;
    emit therapyStopFilesProcess();
}

void TherapyWindowBasic::updatePressureGraphAsPerMode(therapyPeriodParam mode)
{
        switch(mode)
        {
            case GoToSleep:
                therapyPressure->setBlankBarColor(THERAPY_GO_TO_SLEEP_COLOR);
                therapyPressure->setFillBarVisibleState(false);
                break;
            case RampTime:
                therapyPressure->setBlankBarColor(THERAPY_NORMAL_BLANK_COLOR);
                therapyPressure->setFillBarVisibleState(true);
                break;
            case Therapy:
//                therapyPressure->setBlankBarColor(THERAPY_NORMAL_FILL_COLOR);
                therapyPressure->setBlankBarColor(THERAPY_NORMAL_BLANK_COLOR);
                therapyPressure->setFillBarVisibleState(true);
//                therapyPressure->setFillBarVisibleState(false);
                break;
            case Snooze:
                therapyPressure->setBlankBarColor(THERAPY_SNOOZE_FILL_COLOR);
                therapyPressure->setFillBarVisibleState(false);
                break;
        }
}


void TherapyWindowBasic::showHideSnoozeTimeFrame(bool showFrame)
{
    if(showFrame == true)
    {
        if(ui->snoozeDisplayFrame->isHidden())        ui->snoozeDisplayFrame->show();
    }
    else
    {
        if(ui->snoozeDisplayFrame->isVisible())        ui->snoozeDisplayFrame->hide();
    }
}

void TherapyWindowBasic::updateRemainingTime(void)
{
    updateSnoozeTime();
    updateGoToSleepTime();
    updateRampTime();
}

void TherapyWindowBasic::updateSnoozeTime(void)
{
    if((tSnoozeTimeMinutes != globalVar.snooze.countMinutes) | (tSnoozeTimeSeconds != globalVar.snooze.countSeconds))
    {
        tSnoozeTimeMinutes = globalVar.snooze.countMinutes;
        tSnoozeTimeSeconds = globalVar.snooze.countSeconds;
        QString snzRemStr = QString("%1:%2").arg(globalVar.snooze.countMinutes,2,10,QChar('0')).arg(globalVar.snooze.countSeconds,2,10,QChar('0'));
        ui->snoozeTime->setText(snzRemStr);
    }
}

void TherapyWindowBasic::updateGoToSleepTime(void)
{
    if((tGoToSleepMinutes != globalVar.goToSleep.countMinutes) | (tGoToSleepSeconds != globalVar.goToSleep.countSeconds))
    {
        tGoToSleepMinutes = globalVar.goToSleep.countMinutes;
        tGoToSleepSeconds = globalVar.goToSleep.countSeconds;
        QString gtsRemStr = QString("%1:%2").arg(globalVar.goToSleep.countMinutes,2,10,QChar('0')).arg(globalVar.goToSleep.countSeconds,2,10,QChar('0'));
        ui->goToSleepRemainingTime->setText(gtsRemStr);
    }
}

void TherapyWindowBasic::updateRampTime(void)
{
    if((tRampMinutes != globalVar.rampTime.countMinutes) | (tRampSeconds != globalVar.rampTime.countSeconds))
    {
        tRampMinutes = globalVar.rampTime.countMinutes;
        tRampSeconds = globalVar.rampTime.countSeconds;
        QString rampRemStr = QString("%1:%2").arg(globalVar.rampTime.countMinutes,2,10,QChar('0')).arg(globalVar.rampTime.countSeconds,2,10,QChar('0'));
        ui->rampTimeRemainingTime->setText(rampRemStr);
    }
}

void TherapyWindowBasic::on_changeParameterButton_released()
{
    emit showParameterTunningScreen();
}

void TherapyWindowBasic::updateCurrentWindowParameter(int currentWindowData)
{
    if(prevCurrentWindow != currentWindowData)
    {
        prevCurrentWindow = currentWindowData;
        QString currentWindowStr = QString("%1").arg(prevCurrentWindow);
        ui->currentWindow->setText(currentWindowStr);
    }
}

void TherapyWindowBasic::showHomeWindowBasic()
{
    // Check if we should diplay the engineering data
    if(globalVar.diagnosticData == On)
    {
        // Get setting if we are supposed to show engineering data
        ui->rTitle->show();
        ui->referenceWindow->show();
        ui->cTitle->show();
        ui->currentWindow->show();

    }
    else
    {
        // Get setting if we are supposed to show engineering data
        ui->rTitle->hide();
        ui->referenceWindow->hide();
        ui->cTitle->hide();
        ui->currentWindow->hide();
    }

    updateTherapyBasicProcessBeforeShow();
    animateTherapyWindow(Open);
}

void TherapyWindowBasic::updateReferenceWindowParameter(int referenceWindowData)
{
    if(prevReferenceWindow != referenceWindowData)
    {
        prevReferenceWindow = referenceWindowData;
        QString referenceWindowStr = QString("%1").arg(prevReferenceWindow);
        ui->referenceWindow->setText(referenceWindowStr);
    }
}

void TherapyWindowBasic::updateText()
{
    QFont fontTitle("Roboto-Light", 8);
    startStopTherapyButton->setTitle(tr("Start Therapy"),fontTitle,QColor(0xFFFFFF));

    QFont presBarfontTitle("Roboto-Light", 8);
    therapyPressure->setTitleProperties(tr("Set Pressure"),presBarfontTitle,QStringLiteral("color:#BDBDBD;"));
    //startStopTherapyButton->setText(tr("Start Therapy"));
}

void TherapyWindowBasic::changeEvent(QEvent* e)
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
