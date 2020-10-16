#include "maskdryoptionsbasic.h"
#include "ui_maskdryoptionsbasic.h"
#include "ex_variables.h"


MaskDryOptionsBasic::MaskDryOptionsBasic(QWidget *parent,PruControlClass * m_IpcBackend)
    : QDialog(parent),
    ui(new Ui::MaskDryOptionsBasic),
    m_IpcManager(m_IpcBackend),
    parentEffect(nullptr),
    spinner(nullptr),
    m_Timer(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setAttribute(Qt::WA_TranslucentBackground,true);
    move(60,56);

    if(m_IpcManager)
    {
        connect(this,SIGNAL(beforeStartTherapyProcedure()),
                m_IpcManager,SLOT(beforeStartTherapyProcedure()));
    }

    QFont title("Roboto-Light",9);
    ui->maskDryTitle->setFont(title);
    ui->maskDryTestStartStop->setFont(title);

    title.setPointSize(10);
    ui->maskDryCancel->setFont(title);

    m_Timer = new QTimer(this);
    m_Timer->setSingleShot(true);
    m_Timer->stop();
    connect(m_Timer,SIGNAL(timeout()),this,SLOT(maskDryTimerTimeout()));

//    spinner = new WaitingSpinnerWidget(ui->spinnerParent);
//    spinner->setRoundness(70.0);
//    spinner->setMinimumTrailOpacity(15.0);
//    spinner->setTrailFadePercentage(70.0);
//    spinner->setNumberOfLines(12);
//    spinner->setLineLength(10);
//    spinner->setLineWidth(5);
//    spinner->setInnerRadius(10);
//    spinner->setRevolutionsPerSecond(1);
//    spinner->setColor(QColor(255,255,255));
//    spinner->hide();

//    updateMaskDryOptionsProcessBeforeShow();
}

MaskDryOptionsBasic::~MaskDryOptionsBasic()
{
    delete ui;
}

void MaskDryOptionsBasic::updateMaskDryOptionsProcessBeforeShow(void)
{
    m_TimerSeconds = 0;
    maskDryStatus = false;
    globalVar.maskDryState = Off;
    globalVar.therapyState = Off;
    emit beforeStartTherapyProcedure();
    ui->maskDryProgressBar->hide();
    ui->maskDryProgressBar->setValue(0);
    updateStartStopButton();
}

void MaskDryOptionsBasic::maskDryTimerTimeout()
{
    m_TimerSeconds++;
    updateProgressBarAsPerSeconds(m_TimerSeconds);
}

void MaskDryOptionsBasic::on_maskDryCancel_released()
{
    m_TimerSeconds = 0;
    maskDryStatus = Off;
    globalVar.maskDryState = Off;
    globalVar.therapyState = Off;
    updateStartStopButton();

    emit beforeStartTherapyProcedure();

    parentEffect->setEnabled(false);
    hide();
    setModal(false);
}

void MaskDryOptionsBasic::updateStartStopButton(void)
{
    if(maskDryStatus == true)
    {
        ui->maskDryTestStartStop->setText("Stop");
        ui->maskDryProgressBar->setValue(0);
        ui->maskDryProgressBar->show();
        globalVar.therapyState = On;
        globalVar.maskDryState = On;
        m_TimerSeconds = 0;
        m_Timer->start(1000);
    }
    else
    {
        ui->maskDryTestStartStop->setText("Start");
        ui->maskDryProgressBar->hide();
        globalVar.maskDryState = Off;
        globalVar.therapyState = Off;
        m_TimerSeconds = 0;
        m_Timer->stop();
    }

    emit beforeStartTherapyProcedure();
}
void MaskDryOptionsBasic::on_maskDryTestStartStop_released()
{
    if((globalVar.therapyState == Off) | (globalVar.maskDryState == On))
    {
        maskDryStatus = !maskDryStatus;
        updateStartStopButton();
    }
}

void MaskDryOptionsBasic::showMaskDryOptionScreen()
{
    updateMaskDryOptionsProcessBeforeShow();
    parentEffect->setEnabled(true);
    setModal(true);
    show();
}

#define MAX_MASK_DRY_TIME      (15 * 60)
void MaskDryOptionsBasic::updateProgressBarAsPerSeconds(int seconds)
{
float step=0;
float percent=0;

    if(seconds < MAX_MASK_DRY_TIME)
    {
        step = static_cast<float>(100)/MAX_MASK_DRY_TIME;
        percent = static_cast<float>(seconds) * step;
        if(static_cast<int>(percent))
        {
            ui->maskDryProgressBar->setValue(static_cast<int>(percent));
        }
        m_Timer->start(1000);
    }
    else
    {
        ui->maskDryProgressBar->setValue(100);
        globalVar.maskDryState = Off;
        maskDryStatus = Off;
        updateStartStopButton();
    }
}

void MaskDryOptionsBasic::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
