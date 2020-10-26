#include "airfilterwindowreminderclinical.h"
#include "ui_airfilterwindowreminderclinical.h"
#include "ex_variables.h"
#include "screens/datewindowclinical.h"


int AirFilterWindowReminderClinical::localDate=0;
int AirFilterWindowReminderClinical::localMonth=0;
int AirFilterWindowReminderClinical::localYear=0;


AirFilterWindowReminderClinical::AirFilterWindowReminderClinical(QWidget *parent,
                                                                 DateWindowClinical * dateScreenBackend,
                                                                 DataValidation * dataValidationBackend)
    : QDialog(parent),
    ui(new Ui::AirFilterWindowReminderClinical),
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

    QFont title("Roboto-Light",11);
    ui->airFilterTitle->setFont(title);
    ui->airFilterSetDate->setFont(title);

    title.setPointSize(15);
    ui->airFilterDuration->setFont(title);

    title.setPointSize(8);
    ui->airFilterSetStartDateTitle->setFont(title);
    ui->airFilterSetDurationTitle->setFont(title);

    title.setPointSize(8);
    ui->airFilterDurationUnit->setFont(title);

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

    updateAirFilterRemindersBeforeShowProcess();
}

AirFilterWindowReminderClinical::~AirFilterWindowReminderClinical()
{
    delete ui;
}

void AirFilterWindowReminderClinical::updateAirFilterDuration(int duration)
{
    QString str = QString::number(duration);
    ui->airFilterDuration->setText(str);
}

void AirFilterWindowReminderClinical::updateAirFilterSetStartDate(int mDate,int mMonth,int mYear)
{
    QString dateStr = QString("%1 %2 %3").arg(mDate).arg(Providers::getMonthsTextString(mMonth)).arg(mYear);
    ui->airFilterSetDate->setText(dateStr);
}

void AirFilterWindowReminderClinical::updateAirFilterRemindersBeforeShowProcess(void)
{
    airFilterDuration = globalVar.reminder.airFilter.changeDuration;
    localDate = globalVar.reminder.airFilter.setStartDate.date;
    localMonth = globalVar.reminder.airFilter.setStartDate.month;
    localYear = globalVar.reminder.airFilter.setStartDate.year;
    updateAirFilterDuration(airFilterDuration);
    updateAirFilterSetStartDate(localDate,localMonth,localYear);
}

void AirFilterWindowReminderClinical::on_airFilterIncrement_pressed()
{
    if(airFilterDuration < globalVar.reminder.airFilter.maxDuration) {
        airFilterDuration++;
        updateAirFilterDuration(airFilterDuration);
    }
}

void AirFilterWindowReminderClinical::on_airFilterDecrement_pressed()
{
    if(airFilterDuration > globalVar.reminder.airFilter.minDuration) {
        airFilterDuration--;
        updateAirFilterDuration(airFilterDuration);
    }
}

void AirFilterWindowReminderClinical::showAirFilterReminderScreen()
{
    updateAirFilterRemindersBeforeShowProcess();
    parentEffect->setEnabled(true);
    setModal(true);
    show();
}

void AirFilterWindowReminderClinical::on_airFilterSetDate_released()
{
    if(dateScreen)
    {
        disconnect(dateScreen, SIGNAL(screenClose(int,int,int)),0,0);
        connect(dateScreen,SIGNAL(screenClose(int,int,int)),
                this,SLOT(dateWindowClosed(int,int,int)));
        emit showDateScreen(this,localDate,localMonth + 1,localYear,false);
    }
}

void AirFilterWindowReminderClinical::dateWindowClosed(int date, int month, int year)
{
    localDate = date + 1;
    localMonth = month;
    localYear = year;

    updateAirFilterSetStartDate(localDate,localMonth,localYear);

    disconnect(dateScreen,SIGNAL(screenClose(int,int,int)),0,0);
}

void AirFilterWindowReminderClinical::on_airFilterAccept_released()
{
    globalVar.reminder.airFilter.changeDuration = airFilterDuration;
    globalVar.reminder.airFilter.setStartDate.date = localDate;
    globalVar.reminder.airFilter.setStartDate.month = localMonth;
    globalVar.reminder.airFilter.setStartDate.year = localYear;

    parentEffect->setEnabled(false);

    // Update Data to EEPROM
    emit writeParameterToEeprom();

    hide();
    setModal(false);
}

void AirFilterWindowReminderClinical::on_airFilterCancel_released()
{
    parentEffect->setEnabled(false);
    hide();
    setModal(false);
}

void AirFilterWindowReminderClinical::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        updateAirFilterRemindersBeforeShowProcess();
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
