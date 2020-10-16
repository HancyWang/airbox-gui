#include "brightnessadjustbrightnesssettingsbasic.h"
#include "ui_brightnessadjustbrightnesssettingsbasic.h"
#include "ex_variables.h"



BrightnessAdjustBrightnessSettingsBasic::BrightnessAdjustBrightnessSettingsBasic(QWidget *parent,
                                                                                 BrightnessControlThread * brightnessBackend,
                                                                                 DataValidation * dataValidationBackend)
    : QDialog(parent),
    ui(new Ui::BrightnessAdjustBrightnessSettingsBasic),
    brightnessControl(brightnessBackend),
    dataValidation(dataValidationBackend),
    parentEffect(nullptr),
    brightnessControlSwitch(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setAttribute(Qt::WA_TranslucentBackground,true);
    move(60,56);

    if(brightnessControl)
    {
        connect(this, SIGNAL(sendBrightnessControlData(bool,int)),
                brightnessControl,SLOT(sendBrightnessControlData(bool,int)));
    }

    if(dataValidation)
    {
        connect(this,SIGNAL(writeParameterToEeprom()),
                dataValidation,SLOT(writeParameterToEeprom()));
    }

    brightnessControlSwitch = new Switch(this);
    brightnessControlSwitch->setGeometry(QRect(276,20,60,30));
    connect(brightnessControlSwitch, SIGNAL(toggleSwitchClicked()),
                     this,SLOT(brightnessControlSwitch_clicked()));

    QFont title("Roboto-Light",9);
    ui->brightnessLevelTitle->setFont(title);

    title.setPointSize(7);
    ui->brightnessLevelSetTitle->setFont(title);

    title.setPointSize(9);
    ui->brightnessLevelAccept->setFont(title);
    ui->brightnessLevelCancel->setFont(title);

    updateBrightnessSettingsBasicBeforeShow();
}

BrightnessAdjustBrightnessSettingsBasic::~BrightnessAdjustBrightnessSettingsBasic()
{
    delete ui;
}

void BrightnessAdjustBrightnessSettingsBasic::updateBrightnessSettingsBasicBeforeShow(void)
{
    brightnessAuto = globalVar.displaySettings.autoBrightnessAdjustment;
    brightnessLevel = globalVar.displaySettings.brightnessLevel;

    updateBrightnessControl();
    brightnessControlSwitch->setSwitchState(brightnessAuto);
    brightnessAutoProcessShowHide(brightnessAuto);
}

void BrightnessAdjustBrightnessSettingsBasic::brightnessAutoProcessShowHide(OnOff autoStatus)
{
    if(autoStatus == On)
    {
        ui->brightnessLevelSetTitle->hide();
        ui->brightnessSlider->hide();
        ui->brightnessAdjustDecrement->hide();
        ui->brightnessAdjustIncrement->hide();
    }
    else
    {
        ui->brightnessLevelSetTitle->show();
        ui->brightnessSlider->show();
        ui->brightnessAdjustDecrement->show();
        ui->brightnessAdjustIncrement->show();
    }
}

void BrightnessAdjustBrightnessSettingsBasic::on_brightnessLevelAccept_released()
{
    parentEffect->setEnabled(false);
    globalVar.displaySettings.brightnessLevel = brightnessLevel;
    globalVar.displaySettings.autoBrightnessAdjustment = brightnessAuto;
    emit dialogClose();

    emit sendBrightnessControlData(globalVar.displaySettings.autoBrightnessAdjustment,
                                          globalVar.displaySettings.brightnessLevel);

    // Update Data to EEPROM
    emit writeParameterToEeprom();

    hide();
    setModal(false);
}

void BrightnessAdjustBrightnessSettingsBasic::on_brightnessLevelCancel_released()
{
    emit sendBrightnessControlData(globalVar.displaySettings.autoBrightnessAdjustment,
                                          globalVar.displaySettings.brightnessLevel);
    parentEffect->setEnabled(false);
    hide();
    setModal(false);
}

void BrightnessAdjustBrightnessSettingsBasic::brightnessControlSwitch_clicked()
{
    brightnessAuto = static_cast<OnOff>(brightnessControlSwitch->getSwitchState());

    brightnessAutoProcessShowHide(brightnessAuto);

    emit sendBrightnessControlData(brightnessAuto,brightnessLevel);
}

void BrightnessAdjustBrightnessSettingsBasic::on_brightnessSlider_sliderPressed()
{
    brightnessLevel = ui->brightnessSlider->value();
    emit sendBrightnessControlData(brightnessAuto,brightnessLevel);
}

void BrightnessAdjustBrightnessSettingsBasic::on_brightnessSlider_valueChanged(int value)
{
    brightnessLevel = value;
    emit sendBrightnessControlData(brightnessAuto,brightnessLevel);
}

void BrightnessAdjustBrightnessSettingsBasic::updateBrightnessControl(void)
{
    ui->brightnessSlider->setValue(brightnessLevel);
}

void BrightnessAdjustBrightnessSettingsBasic::on_brightnessAdjustIncrement_pressed()
{
    if(brightnessLevel < BRIGHTNESS_LEVEL_MAX)      brightnessLevel++;
    updateBrightnessControl();
}

void BrightnessAdjustBrightnessSettingsBasic::on_brightnessAdjustDecrement_pressed()
{
    if(brightnessLevel > BRIGHTNESS_LEVEL_MIN)      brightnessLevel--;
    updateBrightnessControl();
}

void BrightnessAdjustBrightnessSettingsBasic::showBrightnessAdjustScreen()
{
    updateBrightnessSettingsBasicBeforeShow();
    parentEffect->setEnabled(true);
    setModal(true);
    show();
}

void BrightnessAdjustBrightnessSettingsBasic::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
