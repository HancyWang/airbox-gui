#include "ex_variables.h"
#include "ui_resetreminderwarning.h"
#include <QDate>

ResetReminderWarning::ResetReminderWarning(QWidget *parent,
                                           ActiveReminderScreen * activeReminderBackend,
                                           DataValidation * dataValidationBackend)
    : QDialog(parent),
    ui(new Ui::ResetReminderWarning),
    activeReminderScreen(activeReminderBackend),
    dataValidation(dataValidationBackend)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground,true);
    move(60,56);

    if(dataValidation)
    {
        connect(this,SIGNAL(writeParameterToEeprom()),
                dataValidation,SLOT(writeParameterToEeprom()));
    }

    if(activeReminderScreen)
    {
        connect(activeReminderScreen,SIGNAL(showAirFilterAtIndexResetReminder(int)),
                this,SLOT(showAirFilterAtIndex(int)));
        connect(activeReminderScreen,SIGNAL(showAirTubeAtIndexResetReminder(int)),
                this,SLOT(showAirTubeAtIndex(int)));
        connect(activeReminderScreen,SIGNAL(showMaskAtIndexResetReminder(int)),
                this,SLOT(showMaskAtIndex(int)));
        connect(this,SIGNAL(closeScreen()),
                activeReminderScreen,SLOT(closeScreen()));
        connect(activeReminderScreen,SIGNAL(showResetReminderScreen()),
                this,SLOT(showResetReminderScreen()));
    }
}

ResetReminderWarning::~ResetReminderWarning()
{
    delete ui;
}

void ResetReminderWarning::updateResetReminderBeforeShow(void)
{
    ui->airFilterText->hide();
    ui->airTubeText->hide();
    ui->maskText->hide();
}

void ResetReminderWarning::showAirFilterAtIndex(int index)
{
    ui->airFilterText->move(30,widgetYOffset + (index * widgetSize));
    ui->airFilterText->show();
}

void ResetReminderWarning::showAirTubeAtIndex(int index)
{
    ui->airTubeText->move(30,widgetYOffset + (index * widgetSize));
    ui->airTubeText->show();
}

void ResetReminderWarning::showMaskAtIndex(int index)
{
    ui->maskText->move(30,widgetYOffset + (index * widgetSize));
    ui->maskText->show();
}

void ResetReminderWarning::on_yesButton_clicked()
{
    /* Reset reminder date to today's date */
    if(ui->airTubeText->isVisible()){
        globalVar.reminder.airTube.setStartDate.date = QDate::currentDate().day();
        globalVar.reminder.airTube.setStartDate.month = QDate::currentDate().month();
        globalVar.reminder.airTube.setStartDate.year = QDate::currentDate().year();
    }
    if(ui->airFilterText->isVisible()){
        globalVar.reminder.airFilter.setStartDate.date = QDate::currentDate().day();
        globalVar.reminder.airFilter.setStartDate.month = QDate::currentDate().month();
        globalVar.reminder.airFilter.setStartDate.year = QDate::currentDate().year();
    }
    if(ui->maskText->isVisible()){
        globalVar.reminder.mask.setStartDate.date = QDate::currentDate().day();
        globalVar.reminder.mask.setStartDate.month = QDate::currentDate().month();
        globalVar.reminder.mask.setStartDate.year = QDate::currentDate().year();
    }

    // Update Data to EEPROM
    emit writeParameterToEeprom();
    hide();
    emit closeScreen();
}

void ResetReminderWarning::on_noButton_clicked()
{
    hide();
    emit closeScreen();
}

void ResetReminderWarning::showResetReminderScreen()
{
    updateResetReminderBeforeShow();
    show();
}

void ResetReminderWarning::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
