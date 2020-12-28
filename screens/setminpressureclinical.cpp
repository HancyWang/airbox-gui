#include "setminpressureclinical.h"
#include "ui_setminpressureclinical.h"
#include "ex_variables.h"

SetMinPressureClinical::SetMinPressureClinical(QWidget *parent,
                                               DataValidation * dataValidationBackend)
    : QDialog(parent),
    ui(new Ui::SetMinPressureClinical),
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
    ui->setMinPressureTitle->setFont(title);

    title.setPointSize(10);
    ui->setMinPressureCancel->setFont(title);
    ui->setMinPressureAccept->setFont(title);

    title.setPointSize(8);
    ui->setMinPressureUnit->setFont(title);
    ui->setMaxPressure->setFont(title);

    title.setPointSize(12);
    ui->setMinPressureDecrement->setFont(title);
    ui->setMinPressureIncrement->setFont(title);

    QFont valueFont("Roboto-Thin",26);
    ui->setMinPressureValue->setFont(valueFont);

    updateMinPressureProcessBeforeShow();
}

SetMinPressureClinical::~SetMinPressureClinical()
{
    delete ui;
}

void SetMinPressureClinical::updateMinPressureProcessBeforeShow(void)
{
    setPres = globalVar.pressure.apapMinPressure;
#ifdef CHANGE_PRESSURE_STEP_TO_05
    validMaxPressure = globalVar.pressure.apapMaxPressure - 50;
    ui->setMinPressureSlider->setRange(PRESSURE_VALUE_2_SLIDER_VALUE(TARGET_PRESSURE_MIN),PRESSURE_VALUE_2_SLIDER_VALUE(validMaxPressure));
    ui->setMinPressureSlider->setValue(PRESSURE_VALUE_2_SLIDER_VALUE(setPres));
#else
    validMaxPressure = globalVar.pressure.apapMaxPressure - 1;
    ui->setMinPressureSlider->setRange(TARGET_PRESSURE_MIN,validMaxPressure);
    ui->setMinPressureSlider->setValue(setPres);
#endif


#ifdef CHANGE_PRESSURE_STEP_TO_05
    QString str_integer=QString::number(globalVar.pressure.apapMaxPressure/100);
    QString str_decimals=QString::number(globalVar.pressure.apapMaxPressure%100/10);
    QString maxStr=str_integer+"."+str_decimals;
#else
    QString maxStr = QString::number(globalVar.pressure.apapMaxPressure);
#endif
    ui->setMaxPressure->setText(maxStr);

    updateValueText(setPres);
    processWarningShowHide();
}

void SetMinPressureClinical::on_setMinPressureAccept_released()
{
    globalVar.pressure.apapMinPressure = setPres;
    globalVar.pressure.targetedPressure = globalVar.pressure.apapMinPressure;
    parentEffect->setEnabled(false);
    emit dialogClose();

    // Update Data to EEPROM
    emit writeParameterToEeprom();

    hide();
    setModal(false);
}

void SetMinPressureClinical::on_setMinPressureCancel_released()
{
    parentEffect->setEnabled(false);
    hide();
    setModal(false);
}

void SetMinPressureClinical::on_setMinPressureIncrement_pressed()
{
    if(setPres < validMaxPressure){
#ifdef CHANGE_PRESSURE_STEP_TO_05
        setPres+=PRESSURE_SET_STEP;
        ui->setMinPressureSlider->setValue(PRESSURE_VALUE_2_SLIDER_VALUE(setPres));
#else
        setPres++;
        ui->setMinPressureSlider->setValue(setPres);
#endif


        updateValueText(setPres);
    }
    processWarningShowHide();
}

void SetMinPressureClinical::on_setMinPressureDecrement_pressed()
{
    if(setPres > TARGET_PRESSURE_MIN){
#ifdef CHANGE_PRESSURE_STEP_TO_05
        setPres-=PRESSURE_SET_STEP;
        ui->setMinPressureSlider->setValue(PRESSURE_VALUE_2_SLIDER_VALUE(setPres));
#else
        setPres--;
        ui->setMinPressureSlider->setValue(setPres);
#endif


        updateValueText(setPres);
    }
}

void SetMinPressureClinical::on_setMinPressureSlider_sliderPressed()
{
    setPres = SLIDER_VALUE_2_PRESSURE_VAL(ui->setMinPressureSlider->value());
    updateValueText(setPres);
    processWarningShowHide();
}

void SetMinPressureClinical::on_setMinPressureSlider_valueChanged(int value)
{
#ifdef CHANGE_PRESSURE_STEP_TO_05
    setPres = SLIDER_VALUE_2_PRESSURE_VAL(value);
#else
    setPres = value;
#endif

    updateValueText(setPres);
    processWarningShowHide();
}

void SetMinPressureClinical::processWarningShowHide(void)
{
    if(setPres == validMaxPressure)
        ui->warningSetMaxPressureTitle->show();
    else
        ui->warningSetMaxPressureTitle->hide();
}

void SetMinPressureClinical::updateValueText(int value)
{
#ifdef CHANGE_PRESSURE_STEP_TO_05
    QString str_integer=QString::number(value/100);
    QString str_decimals=QString::number(value%100/10);
    QString str=str_integer+"."+str_decimals;
#else
    QString str = QString::number(value);
#endif
    ui->setMinPressureValue->setText(str);
}

void SetMinPressureClinical::showMinPressureScreen()
{
    updateMinPressureProcessBeforeShow();
    parentEffect->setEnabled(true);
    setModal(true);
    show();
}

void SetMinPressureClinical::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
