#include "pressureunitconfigurationclinical.h"
#include "ui_pressureunitconfigurationclinical.h"
#include "ex_variables.h"

PressureUnitConfigurationClinical::PressureUnitConfigurationClinical(QWidget *parent,
                                                                     DataValidation * dataValidationBackend)
    : QDialog(parent),
    ui(new Ui::PressureUnitConfigurationClinical),
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
    ui->pressureUnitTitle->setFont(title);

    title.setPointSize(10);
    ui->pressureUnitAccept->setFont(title);
    ui->pressureUnitCancel->setFont(title);

    // Not required
    ui->hpaRadio->hide();

    updatePressureUnitProcessBeforeShow();
}

PressureUnitConfigurationClinical::~PressureUnitConfigurationClinical()
{
    delete ui;
}

void PressureUnitConfigurationClinical::updatePressureUnitProcessBeforeShow(void)
{
    pressureUnit = globalVar.pressureUnit;
    if(pressureUnit == cmh2o){
        ui->cmh2oRadio->setChecked(true);
    } else {
        ui->hpaRadio->setChecked(true);
    }
}

void PressureUnitConfigurationClinical::on_pressureUnitAccept_released()
{
    globalVar.pressureUnit = pressureUnit;
    emit dialogClose();
    parentEffect->setEnabled(false);

    // Update Data to EEPROM
    emit writeParameterToEeprom();

    hide();
    setModal(false);
}

void PressureUnitConfigurationClinical::on_pressureUnitCancel_released()
{
    parentEffect->setEnabled(false);
    hide();
    setModal(false);
}

void PressureUnitConfigurationClinical::on_hpaRadio_pressed()
{
    pressureUnit = hpa;
}

void PressureUnitConfigurationClinical::on_cmh2oRadio_pressed()
{
    pressureUnit = cmh2o;
}

void PressureUnitConfigurationClinical::showPressureUnitScreen()
{
    updatePressureUnitProcessBeforeShow();
    parentEffect->setEnabled(true);
    setModal(true);
    show();
}

void PressureUnitConfigurationClinical::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
