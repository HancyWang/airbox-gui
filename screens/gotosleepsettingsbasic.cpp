#include "gotosleepsettingsbasic.h"
#include "ui_gotosleepsettingsbasic.h"
#include "ex_variables.h"


//int GoToSleepSettingsBasic::goToSleepTimeSet = 0;


GoToSleepSettingsBasic::GoToSleepSettingsBasic(QWidget *parent,
                                               DataValidation * dataValidationBackend)
    : QDialog(parent),
    ui(new Ui::GoToSleepSettingsBasic),
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
    ui->smartStartTitle->hide();

    QFont title("Roboto-Light",9);
    ui->goToSleepTitle->setFont(title);

    title.setPointSize(8);
    ui->goToSleepTimeUnit->setFont(title);
    ui->smartStartTitle->setFont(title);

    title.setPointSize(12);
    ui->goToSleepTimeDecrement->setFont(title);
    ui->goToSleepTimeIncrement->setFont(title);

    title.setPointSize(10);
    ui->goToSleepTimeAccept->setFont(title);
    ui->goToSleepTimeCancel->setFont(title);

    QFont valueFont("Roboto-Thin",26);
    ui->goToSleepTimeValue->setFont(valueFont);

    ui->goToSleepTimeSlider->setRange(globalVar.goToSleep.minLimit,globalVar.goToSleep.maxLimit);
//    ui->goToSleepTimeSlider->setTickInterval(GO_TO_SLEEP_TIME_CHANGE_INTERVAL);
    ui->goToSleepTimeSlider->setSingleStep(GO_TO_SLEEP_TIME_CHANGE_INTERVAL);

    updateGoToSleepProcessBeforeShow();
}

GoToSleepSettingsBasic::~GoToSleepSettingsBasic()
{
    delete ui;
}

void GoToSleepSettingsBasic::on_goToSleepTimeAccept_released()
{
    globalVar.goToSleep.goToSleepTime = goToSleepTimeSet;
    globalVar.goToSleep.Auto = goToSleepAutoState;

    parentEffect->setEnabled(false);
    emit dialogClose();

    // Update Data to EEPROM
    emit writeParameterToEeprom();

    emit updateTherapyGoToSleepTimeParameter();

    hide();
    setModal(false);
}

void GoToSleepSettingsBasic::on_goToSleepTimeCancel_released()
{
    goToSleepTimeSet = globalVar.goToSleep.goToSleepTime;
    goToSleepAutoState = globalVar.goToSleep.Auto;

    parentEffect->setEnabled(false);
    hide();
    setModal(false);
}

void GoToSleepSettingsBasic::on_goToSleepTimeDecrement_pressed()
{
    if(goToSleepTimeSet > globalVar.goToSleep.minLimit){
        goToSleepTimeSet -= GO_TO_SLEEP_TIME_CHANGE_INTERVAL;
        ui->goToSleepTimeSlider->setValue(goToSleepTimeSet);
        QString str = QString::number(goToSleepTimeSet);
        ui->goToSleepTimeValue->setText(str);
    }
}

void GoToSleepSettingsBasic::on_goToSleepTimeIncrement_pressed()
{
    if(goToSleepTimeSet < globalVar.goToSleep.maxLimit){
        goToSleepTimeSet += GO_TO_SLEEP_TIME_CHANGE_INTERVAL;
        ui->goToSleepTimeSlider->setValue(goToSleepTimeSet);
        QString str = QString::number(goToSleepTimeSet);
        ui->goToSleepTimeValue->setText(str);
    }
}

void GoToSleepSettingsBasic::on_goToSleepTimeSlider_valueChanged(int value)
{
    goToSleepTimeSet = value;
    updateSliderValue(goToSleepTimeSet);
}
void GoToSleepSettingsBasic::on_goToSleepTimeSlider_sliderPressed()
{
    goToSleepTimeSet = ui->goToSleepTimeSlider->value();
    updateSliderValue(goToSleepTimeSet);
}

void GoToSleepSettingsBasic::updateSliderValue(int value)
{
    QString str = QString::number(value);
    ui->goToSleepTimeValue->setText(str);
}

void GoToSleepSettingsBasic::updateGoToSleepProcessBeforeShow(void)
{
    goToSleepTimeSet = globalVar.goToSleep.goToSleepTime;
    goToSleepAutoState = globalVar.goToSleep.Auto;

    if(goToSleepAutoState == On) {
        smartStartSwitch->setSwitchState(true);
    } else {
        smartStartSwitch->setSwitchState(false);
    }
    ui->goToSleepTimeSlider->setValue(goToSleepTimeSet);
    updateSliderValue(goToSleepTimeSet);
    goToSleepShowHideLocal(goToSleepAutoState);
}

void GoToSleepSettingsBasic::goToSleepShowHideLocal(OnOff state)
{
    if(state == true) {
        ui->goToSleepTimeDecrement->hide();
        ui->goToSleepTimeIncrement->hide();
        ui->goToSleepTimeSlider->hide();
        ui->goToSleepTimeUnit->hide();
        ui->goToSleepTimeValue->hide();
    } else {
        ui->goToSleepTimeDecrement->show();
        ui->goToSleepTimeIncrement->show();
        ui->goToSleepTimeSlider->show();
        ui->goToSleepTimeUnit->show();
        ui->goToSleepTimeValue->show();
    }
}

void GoToSleepSettingsBasic::smartStartSwitch_clicked()
{
    goToSleepAutoState = static_cast<OnOff>(smartStartSwitch->getSwitchState());
    goToSleepShowHideLocal(goToSleepAutoState);
}

void GoToSleepSettingsBasic::showGoToSleepScreen()
{
    updateGoToSleepProcessBeforeShow();
    parentEffect->setEnabled(true);
    setModal(true);
    show();
}

void GoToSleepSettingsBasic::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
