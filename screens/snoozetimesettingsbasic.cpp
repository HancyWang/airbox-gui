#include "snoozetimesettingsbasic.h"
#include "ui_snoozetimesettingsbasic.h"
#include "ex_variables.h"

SnoozeTimeSettingsBasic::SnoozeTimeSettingsBasic(QWidget *parent,
                                                 DataValidation * dataValidationBackend)
    : QDialog(parent),
    ui(new Ui::SnoozeTimeSettingsBasic),
    dataValidation(dataValidationBackend),
    parentEffect(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setAttribute(Qt::WA_TranslucentBackground,true);
    move(60,56);

    if(dataValidation)
    {
        connect(this,SIGNAL(writeParameterToEeprom()),
                dataValidation,SLOT(writeParameterToEeprom()));
    }

    QFont title("Roboto-Light",9);
    ui->snoozeTimeTitle->setFont(title);

    title.setPointSize(8);
    ui->snoozeTimeUnit->setFont(title);

    title.setPointSize(12);
    ui->snoozeTimeDecrement->setFont(title);
    ui->snoozeTimeIncrement->setFont(title);

    title.setPointSize(10);
    ui->snoozeTimeAccept->setFont(title);
    ui->snoozeTimeCancel->setFont(title);

    QFont valueFont("Roboto-Thin",26);
    ui->snoozeTimeValue->setFont(valueFont);

    ui->snoozeTimeSlider->setRange(globalVar.snooze.minSnoozeTime,globalVar.snooze.maxSnoozeTime);

    updateSnoozeTimeProcessBeforeShow();
}

SnoozeTimeSettingsBasic::~SnoozeTimeSettingsBasic()
{
    delete ui;
}

void SnoozeTimeSettingsBasic::updateSnoozeTimeProcessBeforeShow(void)
{
    snoozeTime = globalVar.snooze.snoozeTime;
    ui->snoozeTimeSlider->setValue(snoozeTime);
    QString str = QString::number(snoozeTime);
    ui->snoozeTimeValue->setText(str);
}

void SnoozeTimeSettingsBasic::on_snoozeTimeSlider_valueChanged(int value)
{
    snoozeTime = value;
    updateSliderValue(snoozeTime);
}

void SnoozeTimeSettingsBasic::on_snoozeTimeSlider_sliderPressed()
{
    snoozeTime = ui->snoozeTimeSlider->value();
    updateSliderValue(snoozeTime);
}

void SnoozeTimeSettingsBasic::updateSliderValue(int value)
{
    QString str = QString::number(value);
    ui->snoozeTimeValue->setText(str);
}

void SnoozeTimeSettingsBasic::on_snoozeTimeIncrement_pressed()
{
    if(snoozeTime < globalVar.snooze.maxSnoozeTime){
        snoozeTime += globalVar.snooze.snoozeInterval;
        ui->snoozeTimeSlider->setValue(snoozeTime);
        QString str = QString::number(snoozeTime);
        ui->snoozeTimeValue->setText(str);
    }
}

void SnoozeTimeSettingsBasic::on_snoozeTimeDecrement_pressed()
{
    if(snoozeTime > globalVar.snooze.minSnoozeTime){
        snoozeTime -= globalVar.snooze.snoozeInterval;
        ui->snoozeTimeSlider->setValue(snoozeTime);
        QString str = QString::number(snoozeTime);
        ui->snoozeTimeValue->setText(str);
    }
}

void SnoozeTimeSettingsBasic::showSnoozeTimeScreen()
{
    updateSnoozeTimeProcessBeforeShow();
    parentEffect->setEnabled(true);
    setModal(true);
    show();
}

void SnoozeTimeSettingsBasic::on_snoozeTimeCancel_released()
{
    snoozeTime = globalVar.snooze.snoozeTime;
    parentEffect->setEnabled(false);
    hide();
    setModal(false);
}

void SnoozeTimeSettingsBasic::on_snoozeTimeAccept_released()
{
    globalVar.snooze.snoozeTime = snoozeTime;
    emit dialogClose();
    parentEffect->setEnabled(false);

    // Update Data to EEPROM
    emit writeParameterToEeprom();

    hide();
    setModal(false);
}

void SnoozeTimeSettingsBasic::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
