#include "maskwindowreminderclinical.h"
#include "ui_maskwindowreminderclinical.h"
#include "ex_variables.h"


int MaskWindowReminderClinical::localDate=0;
int MaskWindowReminderClinical::localMonth=0;
int MaskWindowReminderClinical::localYear=0;


MaskWindowReminderClinical::MaskWindowReminderClinical(QWidget *parent,
                                                       DateWindowClinical * dateScreenBackend,
                                                       DataValidation * dataValidationBackend)
    : QDialog(parent),
    ui(new Ui::MaskWindowReminderClinical),
    dataValidation(dataValidationBackend),
    dateScreen(dateScreenBackend),
    parentEffect(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground,true);
    setAttribute(Qt::WA_DeleteOnClose,true);
    move(60,56);

    QFont title("Roboto-Light",12);
    ui->maskTitle->setFont(title);
    ui->maskSetDate->setFont(title);

    title.setPointSize(16);
    ui->maskDuration->setFont(title);

    title.setPointSize(9);
    ui->maskSetStartDateTitle->setFont(title);
    ui->maskSetDurationTitle->setFont(title);

    title.setPointSize(8);
    ui->maskDurationUnit->setFont(title);

    if(dateScreen)
    {
        connect(this,SIGNAL(showDateScreen(QWidget*,int,int,int,bool)),
                dateScreen,SLOT(showDateScreen(QWidget*,int,int,int,bool)));
    }

    if(dataValidation)
    {
        connect(this,SIGNAL(writeParameterToEeprom()),
                dataValidation,SLOT(writeParameterToEeprom()));
    }

    updateMaskWindowReminderProcessBeforeShow();
}

MaskWindowReminderClinical::~MaskWindowReminderClinical()
{
    delete ui;
}

void MaskWindowReminderClinical::updateMaskDuration(int duration)
{
    QString str = QString::number(duration);
    ui->maskDuration->setText(str);
}

void MaskWindowReminderClinical::updateMaskSetStartDate(int mDate,int mMonth,int mYear)
{
    QString dateStr = QString("%1 %2 %3").arg(mDate).arg(Providers::getMonthsTextString(mMonth)).arg(mYear);
    ui->maskSetDate->setText(dateStr);
}

void MaskWindowReminderClinical::showMaskReminderScreen()
{
    updateMaskWindowReminderProcessBeforeShow();
    parentEffect->setEnabled(true);
    setModal(true);
    show();
}

void MaskWindowReminderClinical::updateMaskWindowReminderProcessBeforeShow(void)
{
    maskDuration = globalVar.reminder.mask.changeDuration;
    localDate = globalVar.reminder.mask.setStartDate.date;
    localMonth = globalVar.reminder.mask.setStartDate.month;
    localYear = globalVar.reminder.mask.setStartDate.year;
    updateMaskDuration(maskDuration);
    updateMaskSetStartDate(localDate,localMonth,localYear);
}

void MaskWindowReminderClinical::on_maskAccept_released()
{
    globalVar.reminder.mask.changeDuration = maskDuration;
    globalVar.reminder.mask.setStartDate.date = localDate;
    globalVar.reminder.mask.setStartDate.month = localMonth;
    globalVar.reminder.mask.setStartDate.year = localYear;
    parentEffect->setEnabled(false);

    // Update Data to EEPROM
    emit writeParameterToEeprom();

    hide();
    setModal(false);
}

void MaskWindowReminderClinical::on_maskCancel_released()
{
    parentEffect->setEnabled(false);
    hide();
    setModal(false);
}

void MaskWindowReminderClinical::on_maskIncrement_pressed()
{
    if(maskDuration < globalVar.reminder.mask.maxDuration) {
        maskDuration++;
        updateMaskDuration(maskDuration);
    }
}

void MaskWindowReminderClinical::on_maskDecrement_pressed()
{
    if(maskDuration > globalVar.reminder.mask.minDuration) {
        maskDuration--;
        updateMaskDuration(maskDuration);
    }
}

void MaskWindowReminderClinical::on_maskSetDate_released()
{
    if(dateScreen)
    {
        disconnect(dateScreen, SIGNAL(screenClose(int,int,int)),0,0);
        connect(dateScreen,SIGNAL(screenClose(int,int,int)),
                this,SLOT(dateWindowClosed(int,int,int)));
        emit showDateScreen(this,localDate,localMonth + 1,localYear,false);
    }
}

void MaskWindowReminderClinical::dateWindowClosed(int date, int month, int year)
{
    localDate = date + 1;
    localMonth = month;
    localYear = year;

    updateMaskSetStartDate(localDate,localMonth,localYear);

    disconnect(dateScreen,SIGNAL(screenClose(int,int,int)),0,0);
}


void MaskWindowReminderClinical::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
