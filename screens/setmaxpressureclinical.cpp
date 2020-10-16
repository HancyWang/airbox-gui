#include "setmaxpressureclinical.h"
#include "ui_setmaxpressureclinical.h"
#include "ex_variables.h"

SetMaxPressureClinical::SetMaxPressureClinical(QWidget *parent,
                                               DataValidation * dataValidationBackend)
    : QDialog(parent),
    ui(new Ui::SetMaxPressureClinical),
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
    ui->setMaxPressureTitle->setFont(title);

    title.setPointSize(10);
    ui->setMaxPressureCancel->setFont(title);
    ui->setMaxPressureAccept->setFont(title);

    title.setPointSize(8);
    ui->setMaxPressureUnit->setFont(title);
    ui->setMinPressure->setFont(title);

    title.setPointSize(12);
    ui->setMaxPressureDecrement->setFont(title);
    ui->setMaxPressureIncrement->setFont(title);

    QFont valueFont("Roboto-Thin",26);
    ui->setMaxPressureValue->setFont(valueFont);

    updateMaxPressureProcessBeforeShow();
}

SetMaxPressureClinical::~SetMaxPressureClinical()
{
    delete ui;
}


void SetMaxPressureClinical::updateMaxPressureProcessBeforeShow(void)
{
    setPres = globalVar.pressure.apapMaxPressure;
    validMinPressure = globalVar.pressure.apapMinPressure + 1;
    ui->setMaxPressureSlider->setRange(validMinPressure,TARGET_PRESSURE_MAX);
    ui->setMaxPressureSlider->setValue(setPres);

    processWarningShowHide();
    updateValueText(setPres);

    QString maxStr = QString::number(globalVar.pressure.apapMinPressure);
    ui->setMinPressure->setText(maxStr);
}

void SetMaxPressureClinical::on_setMaxPressureIncrement_pressed()
{
    if(setPres < TARGET_PRESSURE_MAX){
        setPres++;
        ui->setMaxPressureSlider->setValue(setPres);
        updateValueText(setPres);
    }
}

void SetMaxPressureClinical::on_setMaxPressureDecrement_pressed()
{
    if(setPres > validMinPressure){
        setPres--;
        ui->setMaxPressureSlider->setValue(setPres);
        updateValueText(setPres);
    }

    processWarningShowHide();
}

void SetMaxPressureClinical::on_setMaxPressureAccept_released()
{
    globalVar.pressure.apapMaxPressure = setPres;
    parentEffect->setEnabled(false);
    emit dialogClose();

    // Update Data to EEPROM
    emit writeParameterToEeprom();

    hide();
    setModal(false);
}

void SetMaxPressureClinical::on_setMaxPressureCancel_released()
{
    parentEffect->setEnabled(false);
    hide();
    setModal(false);
}

void SetMaxPressureClinical::on_setMaxPressureSlider_sliderPressed()
{
    setPres = ui->setMaxPressureSlider->value();
    updateValueText(setPres);
    processWarningShowHide();
}

void SetMaxPressureClinical::on_setMaxPressureSlider_valueChanged(int value)
{
    setPres = value;
    updateValueText(setPres);
    processWarningShowHide();
}

void SetMaxPressureClinical::processWarningShowHide(void)
{
    if(setPres == validMinPressure)
        ui->warningSetMinPressureTitle->show();
    else
        ui->warningSetMinPressureTitle->hide();
}

void SetMaxPressureClinical::updateValueText(int value)
{
    QString str = QString::number(value);
    ui->setMaxPressureValue->setText(str);
}

void SetMaxPressureClinical::showMaxPressureScreen()
{
    updateMaxPressureProcessBeforeShow();
    parentEffect->setEnabled(true);
    setModal(true);
    show();
}

void SetMaxPressureClinical::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
