#include "displaydimbrightnesssettingsbasic.h"
#include "ui_displaydimbrightnesssettingsbasic.h"
#include "ex_variables.h"

DisplayDimBrightnessSettingsBasic::DisplayDimBrightnessSettingsBasic(QWidget *parent,
                                                                     DataValidation * dataValidationBackend)
    : QDialog(parent),
    ui(new Ui::DisplayDimBrightnessSettingsBasic),
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
    ui->displayDimTitle->setFont(title);

    title.setPointSize(8);
    ui->displayDimUnit->setFont(title);

    title.setPointSize(12);
    ui->displayDimDecrement->setFont(title);
    ui->displayDimIncrement->setFont(title);

    title.setPointSize(10);
    ui->displayDimAccept->setFont(title);
    ui->displayDimCancel->setFont(title);

    QFont valueFont("Roboto-Thin",26);
    ui->displayDimValue->setFont(valueFont);

    updateDisplayDimBrightnessProcessBeforeShow();
}

DisplayDimBrightnessSettingsBasic::~DisplayDimBrightnessSettingsBasic()
{
    delete ui;
}

void DisplayDimBrightnessSettingsBasic::on_displayDimIncrement_pressed()
{
    if(displayDimDuration < globalVar.displaySettings.maxDisplayDimDurationLimit){
        displayDimDuration++;
        ui->displayDimSlider->setValue(displayDimDuration);
        updateSliderValue(displayDimDuration);
    }
}

void DisplayDimBrightnessSettingsBasic::on_displayDimDecrement_pressed()
{
    if(displayDimDuration > globalVar.displaySettings.minDisplayDimDurationLimit){
        displayDimDuration--;
        ui->displayDimSlider->setValue(displayDimDuration);
        updateSliderValue(displayDimDuration);
    }
}

void DisplayDimBrightnessSettingsBasic::showDisplayDimBrightnessScreen()
{
    updateDisplayDimBrightnessProcessBeforeShow();
    parentEffect->setEnabled(true);
    setModal(true);
    show();
}

void DisplayDimBrightnessSettingsBasic::on_displayDimAccept_released()
{
    globalVar.displaySettings.displayDimDuration = displayDimDuration;
    parentEffect->setEnabled(false);
    emit dialogClose();

    // Update Data to EEPROM
    emit writeParameterToEeprom();

    hide();
    setModal(false);
}

void DisplayDimBrightnessSettingsBasic::on_displayDimCancel_released()
{
    displayDimDuration = globalVar.displaySettings.displayDimDuration;
    parentEffect->setEnabled(false);
    hide();
    setModal(false);
}

void DisplayDimBrightnessSettingsBasic::on_displayDimSlider_valueChanged(int value)
{
    displayDimDuration = value;
    updateSliderValue(displayDimDuration);
}

void DisplayDimBrightnessSettingsBasic::on_displayDimSlider_sliderPressed()
{
    displayDimDuration = ui->displayDimSlider->value();
    updateSliderValue(displayDimDuration);
}

void DisplayDimBrightnessSettingsBasic::updateSliderValue(int value)
{
    QString str = QString::number(value);
    ui->displayDimValue->setText(str);
}

void DisplayDimBrightnessSettingsBasic::updateDisplayDimBrightnessProcessBeforeShow(void)
{
    ui->displayDimSlider->setRange(globalVar.displaySettings.minDisplayDimDurationLimit,globalVar.displaySettings.maxDisplayDimDurationLimit);
    displayDimDuration = globalVar.displaySettings.displayDimDuration;
    ui->displayDimSlider->setValue(displayDimDuration);
    updateSliderValue(displayDimDuration);
}


void DisplayDimBrightnessSettingsBasic::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
