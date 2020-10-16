#include "setpressureclinical.h"
#include "ui_setpressureclinical.h"
#include "ex_variables.h"


SetPressureClinical::SetPressureClinical(QWidget *parent,
                                         DataValidation * dataValidationBackend)
    : QDialog(parent),
    ui(new Ui::SetPressureClinical),
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
    ui->setPressureTitle->setFont(title);

    title.setPointSize(10);
    ui->setPressureCancel->setFont(title);
    ui->setPressureAccept->setFont(title);

    title.setPointSize(9);
    ui->setPressureUnit->setFont(title);

    title.setPointSize(12);
    ui->setPressureDecrement->setFont(title);
    ui->setPressureIncrement->setFont(title);

    QFont valueFont("Roboto-Thin",26);
    ui->setPressureValue->setFont(valueFont);

    ui->setPressureSlider->setRange(globalVar.pressure.globalMinPressure,globalVar.pressure.globalMaxPressure);
    updatePressureProcessBeforeShow();
}

SetPressureClinical::~SetPressureClinical()
{
    delete ui;
}

void SetPressureClinical::updatePressureProcessBeforeShow(void)
{
    setPres = globalVar.pressure.targetedPressure;
    ui->setPressureSlider->setValue(setPres);

    updatePressureValueText(setPres);
}

void SetPressureClinical::on_setPressureDecrement_pressed()
{
    if(setPres > globalVar.pressure.globalMinPressure){
        setPres--;
        ui->setPressureSlider->setValue(setPres);
        updatePressureValueText(setPres);
    }
}

void SetPressureClinical::showSetPressureScreen()
{
    updatePressureProcessBeforeShow();
    parentEffect->setEnabled(true);
    setModal(true);
    show();
}

void SetPressureClinical::on_setPressureIncrement_pressed()
{
    if(setPres < globalVar.pressure.globalMaxPressure){
        setPres++;
        ui->setPressureSlider->setValue(setPres);
        updatePressureValueText(setPres);
    }
}

void SetPressureClinical::on_setPressureAccept_released()
{
    globalVar.pressure.targetedPressure = setPres;
    globalVar.pressure.apapMinPressure = globalVar.pressure.targetedPressure;
    parentEffect->setEnabled(false);
    emit dialogClose();

    // Update Data to EEPROM
    emit writeParameterToEeprom();

    hide();
    setModal(false);
}

void SetPressureClinical::on_setPressureCancel_released()
{
    parentEffect->setEnabled(false);
    hide();
    setModal(false);
}

void SetPressureClinical::on_setPressureSlider_sliderPressed()
{
    setPres = ui->setPressureSlider->value();
    updatePressureValueText(setPres);
}


void SetPressureClinical::on_setPressureSlider_valueChanged(int value)
{
    setPres = value;
    updatePressureValueText(setPres);
}

void SetPressureClinical::updatePressureValueText(int value)
{
    QString str = QString::number(value);
    ui->setPressureValue->setText(str);
}

void SetPressureClinical::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
