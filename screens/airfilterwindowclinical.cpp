#include "airfilterwindowclinical.h"
#include "ui_airfilterwindowclinical.h"
#include "ex_variables.h"

AirFilterWindowClinical::AirFilterWindowClinical(QWidget *parent,
                                                 AccessoriesWindowClinical * accesoriesBackend,
                                                 DataValidation * dataValidationBackend)
    : QDialog(parent),
    ui(new Ui::AirFilterWindowClinical),
    accesoriesScreenClinical(accesoriesBackend),
    dataValidation(dataValidationBackend),
    parentEffect(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setAttribute(Qt::WA_TranslucentBackground,true);
    move(60,56);

    if(accesoriesScreenClinical)
    {
        connect(accesoriesScreenClinical,SIGNAL(showAirFilterWindowClinical()),
                this,SLOT(showAirFilterWindowClinical()));
        connect(this, SIGNAL(dialogClose()),
                accesoriesScreenClinical,SLOT(airFilterWindowClosed()));
    }


    if(dataValidation)
    {
        connect(this,SIGNAL(writeParameterToEeprom()),
                dataValidation,SLOT(writeParameterToEeprom()));
    }

    updateAirFilterWindowClinical();
}

AirFilterWindowClinical::~AirFilterWindowClinical()
{
    delete ui;
}

void AirFilterWindowClinical::updateAirFilterWindowClinical(void)
{
    airFilterType = globalVar.airFilter;
    if(airFilterType == standardFilter){
        ui->standardRadio->setChecked(true);
    } else {
        ui->hepaRadio->setChecked(true);
    }
}

void AirFilterWindowClinical::on_airFilterAccept_released()
{
    globalVar.airFilter = airFilterType;
    emit dialogClose();
    parentEffect->setEnabled(false);

    // Update Data to EEPROM
    emit writeParameterToEeprom();
    hide();
    setModal(false);

    disconnect(this, SIGNAL(dialogClose()),0,0);
}

void AirFilterWindowClinical::on_airFilterCancel_released()
{
    parentEffect->setEnabled(false);
    hide();
    setModal(false);
}

void AirFilterWindowClinical::on_hepaRadio_pressed()
{
    airFilterType = hepaFilter;
}

void AirFilterWindowClinical::on_standardRadio_pressed()
{
    airFilterType = standardFilter;
}

void AirFilterWindowClinical::showAirFilterWindowClinical()
{
    updateAirFilterWindowClinical();
    parentEffect->setEnabled(true);
    setModal(true);
    show();
}

void AirFilterWindowClinical::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
