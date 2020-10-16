#include "modewindowtherapyclinical.h"
#include "ui_modewindowtherapyclinical.h"
#include "ex_variables.h"

ModeWindowTherapyClinical::ModeWindowTherapyClinical(QWidget *parent,
                                                     DataValidation * dataValidationBackend)
    : QDialog(parent),
    ui(new Ui::ModeWindowTherapyClinical),
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
    ui->modeTitle->setFont(title);

    title.setPointSize(10);
    ui->modeAccept->setFont(title);
    ui->modeCancel->setFont(title);

    updateModeInModeSelectWindowProcessBeforeShow();
}

ModeWindowTherapyClinical::~ModeWindowTherapyClinical()
{
    delete ui;
}

void ModeWindowTherapyClinical::on_modeAccept_released()
{
    globalVar.therapyMode = localMode;
    emit dialogClose();
    parentEffect->setEnabled(false);

    if(globalVar.therapyMode == apapMode)
    {
        if(globalVar.pressure.targetedPressure > globalVar.pressure.apapMaxPressure)
        {
            globalVar.pressure.targetedPressure = globalVar.pressure.apapMaxPressure - 1;
            globalVar.pressure.apapMinPressure = globalVar.pressure.targetedPressure;

            if(globalVar.pressure.apapMinPressure < TARGET_PRESSURE_MIN)
            {
                globalVar.pressure.targetedPressure = TARGET_PRESSURE_MIN;
                globalVar.pressure.apapMinPressure = TARGET_PRESSURE_MIN;
                globalVar.pressure.apapMaxPressure = globalVar.pressure.apapMinPressure;
            }
        }
    }

    // Update Data to EEPROM
    emit writeParameterToEeprom();

    hide();
    setModal(false);
}

void ModeWindowTherapyClinical::on_modeCancel_released()
{
    parentEffect->setEnabled(false);
    hide();
    setModal(false);
}

void ModeWindowTherapyClinical::updateModeInModeSelectWindowProcessBeforeShow(void)
{
    localMode = globalVar.therapyMode;
    if(localMode == cpapMode){
        ui->modeCpap->setChecked(true);
    }else{
        ui->modeApap->setChecked(true);
    }
}

void ModeWindowTherapyClinical::on_modeCpap_pressed()
{
    localMode = cpapMode;
}

void ModeWindowTherapyClinical::on_modeApap_pressed()
{
    localMode = apapMode;
}

void ModeWindowTherapyClinical::showModeScreen()
{
    updateModeInModeSelectWindowProcessBeforeShow();
    parentEffect->setEnabled(true);
    setModal(true);
    show();
}

void ModeWindowTherapyClinical::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
