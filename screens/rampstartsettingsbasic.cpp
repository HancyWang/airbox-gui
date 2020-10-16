#include "rampstartsettingsbasic.h"
#include "ui_rampstartsettingsbasic.h"
#include "ex_variables.h"



RampStartSettingsBasic::RampStartSettingsBasic(QWidget *parent,
                                               DataValidation * dataValidationBackend)
    : QDialog(parent),
    ui(new Ui::RampStartSettingsBasic),
    dataValidation(dataValidationBackend),
    parentEffect(nullptr),
    smartStartSwitch(nullptr)
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

    smartStartSwitch = new Switch(this);
    smartStartSwitch->setGeometry(QRect(276,20,60,30));
    connect(smartStartSwitch, SIGNAL(toggleSwitchClicked()),SLOT(smartStartSwitch_clicked()));

    //TODO If not required in future remove its objects from code
    smartStartSwitch->hide();
    ui->rampSmartStartTitle->hide();

    QFont title("Roboto-Light",9);
    ui->rampTimeTitle->setFont(title);

    title.setPointSize(8);
    ui->rampTimeUnit->setFont(title);
    ui->rampSmartStartTitle->setFont(title);

    title.setPointSize(12);
    ui->rampTimeDecrement->setFont(title);
    ui->rampTimeIncrement->setFont(title);

    title.setPointSize(10);
    ui->rampTimeAccept->setFont(title);
    ui->rampTimeCancel->setFont(title);

    QFont valueFont("Roboto-Thin",26);
    ui->rampTimeValue->setFont(valueFont);

    ui->rampTimeSlider->setRange(globalVar.rampTime.minLimit,globalVar.rampTime.maxLimit);
    ui->rampTimeSlider->setSingleStep(RAMP_CHANGE_INTERVAL);
    updateRampTimeProcessBeforeShow();
}

RampStartSettingsBasic::~RampStartSettingsBasic()
{
    delete ui;
}

void RampStartSettingsBasic::on_rampTimeIncrement_pressed()
{
    if(rampTimeSet < globalVar.rampTime.maxLimit){
        rampTimeSet += RAMP_CHANGE_INTERVAL;
        ui->rampTimeSlider->setValue(rampTimeSet);
        updateSliderValue(rampTimeSet);
    }
}

void RampStartSettingsBasic::on_rampTimeDecrement_pressed()
{
    if(rampTimeSet > globalVar.rampTime.minLimit){
        rampTimeSet -= RAMP_CHANGE_INTERVAL;
        ui->rampTimeSlider->setValue(rampTimeSet);
        updateSliderValue(rampTimeSet);
    }
}

void RampStartSettingsBasic::showRampTimeScreen()
{
    updateRampTimeProcessBeforeShow();
    parentEffect->setEnabled(true);
    setModal(true);
    show();
}

void RampStartSettingsBasic::on_rampTimeAccept_released()
{
    globalVar.rampTime.rampTime = rampTimeSet;
    globalVar.rampTime.state = rampState;
    globalVar.rampTime.Auto = rampAuto;
    parentEffect->setEnabled(false);
    emit dialogClose();

    // Update Data to EEPROM
    emit writeParameterToEeprom();

    emit updateTherapyRampTimeParameter();

    hide();
    setModal(false);
}

void RampStartSettingsBasic::on_rampTimeCancel_released()
{
    rampTimeSet = globalVar.rampTime.rampTime;
    rampState = globalVar.rampTime.state;
    rampAuto = globalVar.rampTime.Auto;
    parentEffect->setEnabled(false);
    hide();
    setModal(false);
}

void RampStartSettingsBasic::updateRampTimeProcessBeforeShow(void)
{
    ui->rampTimeSlider->setValue(rampTimeSet);
    updateSliderValue(rampTimeSet);

    rampAuto = globalVar.rampTime.Auto;
    rampTimeSet = globalVar.rampTime.rampTime;
    rampState = globalVar.rampTime.state;

    if(rampAuto == On) {
        smartStartSwitch->setSwitchState(true);
    } else {
        smartStartSwitch->setSwitchState(false);
    }
    rampSmartStartShowHide(rampAuto);
}
void RampStartSettingsBasic::rampSmartStartShowHide(OnOff status)
{
    if(status){
        ui->rampTimeDecrement->hide();
        ui->rampTimeIncrement->hide();
        ui->rampTimeSlider->hide();
        ui->rampTimeUnit->hide();
        ui->rampTimeValue->hide();
    } else {
        ui->rampTimeDecrement->show();
        ui->rampTimeIncrement->show();
        ui->rampTimeSlider->show();
        ui->rampTimeUnit->show();
        ui->rampTimeValue->show();
    }
}
void RampStartSettingsBasic::on_rampTimeSlider_valueChanged(int value)
{
    rampTimeSet = value;
    updateSliderValue(rampTimeSet);
}

void RampStartSettingsBasic::on_rampTimeSlider_sliderPressed()
{
    rampTimeSet = ui->rampTimeSlider->value();
    updateSliderValue(rampTimeSet);
}

void RampStartSettingsBasic::updateSliderValue(int value)
{
    QString str = QString::number(value);
    ui->rampTimeValue->setText(str);
}

void RampStartSettingsBasic::smartStartSwitch_clicked()
{
    rampAuto = static_cast<OnOff>(smartStartSwitch->getSwitchState());
    rampSmartStartShowHide(rampAuto);
}

void RampStartSettingsBasic::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
