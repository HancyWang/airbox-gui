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

#ifdef CHANGE_PRESSURE_STEP_TO_05
    ui->setPressureSlider->setRange(PRESSURE_VALUE_2_SLIDER_VALUE(globalVar.pressure.globalMinPressure),
                                    PRESSURE_VALUE_2_SLIDER_VALUE(globalVar.pressure.globalMaxPressure));
#else
    ui->setPressureSlider->setRange(globalVar.pressure.globalMinPressure,globalVar.pressure.globalMaxPressure);
#endif

    updatePressureProcessBeforeShow();
}

SetPressureClinical::~SetPressureClinical()
{
    delete ui;
}

void SetPressureClinical::updatePressureProcessBeforeShow(void)
{
    setPres = globalVar.pressure.targetedPressure;
#ifdef CHANGE_PRESSURE_STEP_TO_05
    ui->setPressureSlider->setValue(PRESSURE_VALUE_2_SLIDER_VALUE(setPres));
#else
    ui->setPressureSlider->setValue(setPres);
#endif


    updatePressureValueText(setPres);
}

void SetPressureClinical::on_setPressureDecrement_pressed()
{
    if(setPres > globalVar.pressure.globalMinPressure){
#ifdef CHANGE_PRESSURE_STEP_TO_05
        setPres-=PRESSURE_SET_STEP;
        ui->setPressureSlider->setValue(PRESSURE_VALUE_2_SLIDER_VALUE(setPres));
#else
        setPres--;
        ui->setPressureSlider->setValue(setPres);
#endif

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
#ifdef CHANGE_PRESSURE_STEP_TO_05
        setPres+=PRESSURE_SET_STEP;
        ui->setPressureSlider->setValue(PRESSURE_VALUE_2_SLIDER_VALUE(setPres));
#else
        setPres++;
        ui->setPressureSlider->setValue(setPres);
#endif

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
#ifdef CHANGE_PRESSURE_STEP_TO_05
    setPres = SLIDER_VALUE_2_PRESSURE_VAL(ui->setPressureSlider->value());
#else
    setPres = ui->setPressureSlider->value();
#endif

    updatePressureValueText(setPres);
}


void SetPressureClinical::on_setPressureSlider_valueChanged(int value)
{
#ifdef CHANGE_PRESSURE_STEP_TO_05
    setPres = SLIDER_VALUE_2_PRESSURE_VAL(value);
#else
    setPres = value;
#endif

    updatePressureValueText(setPres);
}

void SetPressureClinical::updatePressureValueText(int value)
{
#ifdef CHANGE_PRESSURE_STEP_TO_05
    QString str_integer=QString::number(value/100);
    QString str_decimals=QString::number(value%100/10);
    QString str=str_integer+"."+str_decimals;
#else
    QString str = QString::number(value);
#endif
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
