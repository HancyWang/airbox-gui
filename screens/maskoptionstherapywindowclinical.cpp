#include "maskoptionstherapywindowclinical.h"
#include "ui_maskoptionstherapywindowclinical.h"
#include "ex_variables.h"

MaskOptionsTherapyWindowClinical::MaskOptionsTherapyWindowClinical(QWidget *parent,
                                                                   SettingsWindowBasic * settingsBasicBackend,
                                                                   DataValidation * dataValidationBackend)
    : QDialog(parent),
    ui(new Ui::MaskOptionsTherapyWindowClinical),
    settingsBasicScreen(settingsBasicBackend),
    dataValidation(dataValidationBackend),
    parentEffect(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setAttribute(Qt::WA_TranslucentBackground,true);
    move(60,56);

    if(settingsBasicScreen)
    {
        connect(settingsBasicBackend,SIGNAL(showMaskOptionClinicalScreen()),
                this,SLOT(showMaskOptionClinicalScreen()));
    }

    if(dataValidation)
    {
        connect(this,SIGNAL(writeParameterToEeprom()),
                dataValidation,SLOT(writeParameterToEeprom()));
    }

    QFont title("Roboto-Light",9);
    ui->maskTitle->setFont(title);

    title.setPointSize(10);
    ui->maskAccept->setFont(title);
    ui->maskCancel->setFont(title);

    updateMaskInMaskSelectProcessBeforeShow();
}

MaskOptionsTherapyWindowClinical::~MaskOptionsTherapyWindowClinical()
{
    delete ui;
}

void MaskOptionsTherapyWindowClinical::on_maskAccept_released()
{
    globalVar.maskType = localMaskType;
    emit dialogClose();
    parentEffect->setEnabled(false);

    // Update Data to EEPROM
    emit writeParameterToEeprom();

    hide();
    setModal(false);
    disconnect(this, SIGNAL(dialogClose()),0,0);
}

void MaskOptionsTherapyWindowClinical::on_maskCancel_released()
{
    parentEffect->setEnabled(false);
    hide();
    setModal(false);
    disconnect(this, SIGNAL(dialogClose()),0,0);
}

void MaskOptionsTherapyWindowClinical::on_nasalPillow_pressed()
{
    localMaskType = nasalPillow;
}

void MaskOptionsTherapyWindowClinical::on_nasalMask_pressed()
{
    localMaskType = nasalMask;
}

void MaskOptionsTherapyWindowClinical::showMaskOptionClinicalScreen()
{
    connect(this, SIGNAL(dialogClose()),settingsBasicScreen,SLOT(maskButtonClosed()));
    updateMaskInMaskSelectProcessBeforeShow();
    parentEffect->setEnabled(true);
    setModal(true);
    show();
}

void MaskOptionsTherapyWindowClinical::updateMaskInMaskSelectProcessBeforeShow(void)
{
    localMaskType = globalVar.maskType;
    if(localMaskType == nasalMask){
        ui->nasalMask->setChecked(true);
    } else {
        ui->nasalPillow->setChecked(true);
    }
}

void MaskOptionsTherapyWindowClinical::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
