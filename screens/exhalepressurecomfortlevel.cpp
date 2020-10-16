#include "exhalepressurecomfortlevel.h"
#include "ui_exhalepressurecomfortlevel.h"
#include "ex_variables.h"


ExhalePressureComfortLevel::ExhalePressureComfortLevel(QWidget *parent,
                                                       DataValidation * dataValidationBackend)
    : QDialog(parent),
    ui(new Ui::ExhalePressureComfortLevel),
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

    updateExhalePressureComfortProcessBeforeShow();
}

ExhalePressureComfortLevel::~ExhalePressureComfortLevel()
{
    delete ui;
}

void ExhalePressureComfortLevel::on_exhaleComfortAccept_released()
{
    globalVar.comfortLevel.comfortLevelSet = level;
    emit dialogClose();
    parentEffect->setEnabled(false);

    // Update Data to EEPROM
    emit writeParameterToEeprom();

    hide();
    setModal(false);
}

void ExhalePressureComfortLevel::updateExhalePressureComfortProcessBeforeShow(void)
{
    level = globalVar.comfortLevel.comfortLevelSet;
    if(level == COMFORT_LEVEL_1) {
        ui->level1Radio->setChecked(true);
    } else if(level == COMFORT_LEVEL_2) {
        ui->level2Radio->setChecked(true);
    } else {
        ui->level3Radio->setChecked(true);
    }
}

void ExhalePressureComfortLevel::on_exhaleComfortCancel_released()
{
    parentEffect->setEnabled(false);
    hide();
    setModal(false);
}

void ExhalePressureComfortLevel::on_level1Radio_pressed()
{
    level = COMFORT_LEVEL_1;
}

void ExhalePressureComfortLevel::on_level2Radio_pressed()
{
    level = COMFORT_LEVEL_2;
}

void ExhalePressureComfortLevel::on_level3Radio_pressed()
{
    level = COMFORT_LEVEL_3;
}

void ExhalePressureComfortLevel::showExhaleComfortScreen()
{
    updateExhalePressureComfortProcessBeforeShow();
    parentEffect->setEnabled(true);
    setModal(true);
    show();
}

void ExhalePressureComfortLevel::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
