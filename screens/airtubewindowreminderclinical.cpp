#include "airtubewindowreminderclinical.h"
#include "ui_airtubewindowreminderclinical.h"
#include "ex_variables.h"


int AirTubeWindowReminderClinical::localDate=0;
int AirTubeWindowReminderClinical::localMonth=0;
int AirTubeWindowReminderClinical::localYear=0;


AirTubeWindowReminderClinical::AirTubeWindowReminderClinical(QWidget *parent,
                                                             DateWindowClinical * dateScreenBackend,
                                                             DataValidation * dataValidationBackend)
    : QDialog(parent),
    ui(new Ui::AirTubeWindowReminderClinical),
    dateScreen(dateScreenBackend),
    dataValidation(dataValidationBackend),
    parentEffect(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground,true);
    setAttribute(Qt::WA_DeleteOnClose,true);
    move(60,56);

    QFont title("Roboto-Light",11);
    ui->airTubeTitle->setFont(title);
    ui->airTubeSetDate->setFont(title);

    title.setPointSize(15);
    ui->airTubeDuration->setFont(title);

    title.setPointSize(8);
    ui->airTubeSetStartDateTitle->setFont(title);
    ui->airTubeSetDurationTitle->setFont(title);

    title.setPointSize(8);
    ui->airTubeDurationUnit->setFont(title);

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

    updateAirTubeReminderBeforeShowProcess();
}

AirTubeWindowReminderClinical::~AirTubeWindowReminderClinical()
{
    delete ui;
}

void AirTubeWindowReminderClinical::updateAirTubeDuration(int duration)
{
    QString str = QString::number(duration);
    ui->airTubeDuration->setText(str);
}

void AirTubeWindowReminderClinical::updateAirTubeSetStartDate(int mDate,int mMonth,int mYear)
{
    QString dateStr = QString("%1 %2 %3").arg(mDate).arg(Providers::getMonthsTextString(mMonth)).arg(mYear);
    ui->airTubeSetDate->setText(dateStr);
}

void AirTubeWindowReminderClinical::showAirTubeReminderScreen()
{
    updateAirTubeReminderBeforeShowProcess();
    parentEffect->setEnabled(true);
    setModal(true);
    show();
}

void AirTubeWindowReminderClinical::updateAirTubeReminderBeforeShowProcess(void)
{
    airTubeDuration = globalVar.reminder.airTube.changeDuration;
    localDate = globalVar.reminder.airTube.setStartDate.date;
    localMonth = globalVar.reminder.airTube.setStartDate.month;
    localYear = globalVar.reminder.airTube.setStartDate.year;
    updateAirTubeDuration(airTubeDuration);
    updateAirTubeSetStartDate(localDate,localMonth,localYear);
}

void AirTubeWindowReminderClinical::on_airTubeSetDate_released()
{
    if(dateScreen)
    {
        disconnect(dateScreen, SIGNAL(screenClose(int,int,int)),0,0);
        connect(dateScreen,SIGNAL(screenClose(int,int,int)),
                this,SLOT(dateWindowClosed(int,int,int)));
        emit showDateScreen(this,localDate,localMonth + 1,localYear,false);
    }
}

void AirTubeWindowReminderClinical::dateWindowClosed(int date, int month, int year)
{
    localDate = date + 1;
    localMonth = month;
    localYear = year;

    updateAirTubeSetStartDate(localDate,localMonth,localYear);

    disconnect(dateScreen,SIGNAL(screenClose(int,int,int)),0,0);
}

void AirTubeWindowReminderClinical::on_airTubeIncrement_pressed()
{
    if(airTubeDuration < globalVar.reminder.airTube.maxDuration) {
        airTubeDuration++;
        updateAirTubeDuration(airTubeDuration);
    }
}

void AirTubeWindowReminderClinical::on_airTubeDecrement_pressed()
{
    if(airTubeDuration > globalVar.reminder.airTube.minDuration) {
        airTubeDuration--;
        updateAirTubeDuration(airTubeDuration);
    }
}

void AirTubeWindowReminderClinical::on_airTubeAccept_released()
{
    globalVar.reminder.airTube.changeDuration = airTubeDuration;
    globalVar.reminder.airTube.setStartDate.date = localDate;
    globalVar.reminder.airTube.setStartDate.month = localMonth;
    globalVar.reminder.airTube.setStartDate.year = localYear;

    parentEffect->setEnabled(false);

    // Update Data to EEPROM
    emit writeParameterToEeprom();

    hide();
    setModal(false);
}

void AirTubeWindowReminderClinical::on_airTubeCancel_released()
{
    parentEffect->setEnabled(false);
    hide();
    setModal(false);
}

void AirTubeWindowReminderClinical::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
