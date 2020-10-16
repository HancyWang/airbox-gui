#include "snoozeexitscreenbasic.h"
#include "ui_snoozeexitscreenbasic.h"
#include "ex_variables.h"

SnoozeExitScreenBasic::SnoozeExitScreenBasic(QWidget *parent,
                                             PruControlClass * m_IpcBackend)
    : QDialog(parent),
    parentEffect(nullptr),
    ui(new Ui::SnoozeExitScreenBasic),
    m_IpcManager(m_IpcBackend)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setAttribute(Qt::WA_TranslucentBackground,true);
    move(60,56);

    if(m_IpcManager)
    {
        connect(this,SIGNAL(beforeSnoozeProcedure(int)),
                m_IpcManager,SLOT(beforeSnoozeProcedure(int)));
    }

    QFont title("Roboto-Light",9);
    ui->snoozeExitTitle->setFont(title);
    ui->snoozeExitWarning->setFont(title);

    title.setPointSize(10);
    ui->snoozeExitNo->setFont(title);
    ui->snoozeExitYes->setFont(title);
}

SnoozeExitScreenBasic::~SnoozeExitScreenBasic()
{
    delete ui;
}

void SnoozeExitScreenBasic::on_snoozeExitYes_released()
{
    globalVar.snooze.snoozePeriod = Off;
    emit showHideSnoozeTimeFrame(false);

    // Disable snooze time
    emit beforeSnoozeProcedure(0);

    if(parentEffect->isEnabled() == true)
        parentEffect->setEnabled(false);

    globalVar.goToSleep.countMinutes = 0;
    globalVar.goToSleep.countSeconds = 0;
    globalVar.rampTime.countMinutes = 0;
    globalVar.rampTime.countSeconds = 0;
    globalVar.therapyPeriod = Therapy;


    hide();
    setModal(false);
}

void SnoozeExitScreenBasic::on_snoozeExitNo_released()
{
    if(parentEffect->isEnabled() == true)
        parentEffect->setEnabled(false);

    hide();
    setModal(false);
}

void SnoozeExitScreenBasic::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
