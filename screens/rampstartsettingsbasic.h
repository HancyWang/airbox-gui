#ifndef RAMPSTARTSETTINGSBASIC_H
#define RAMPSTARTSETTINGSBASIC_H

#include <QDialog>
#include <QGraphicsColorizeEffect>

#include "widgets/switch.h"
#include "application.h"

namespace Ui {
class RampStartSettingsBasic;
}

class DataValidation;

class RampStartSettingsBasic : public QDialog
{
    Q_OBJECT

public:
    explicit RampStartSettingsBasic(QWidget *parent,
                                    DataValidation * dataValidationBackend);
    ~RampStartSettingsBasic();

    void updateRampTimeProcessBeforeShow(void);
    void rampSmartStartShowHide(OnOff status);

    QGraphicsColorizeEffect * parentEffect;
    int rampTimeSet;
    OnOff rampState;
    OnOff rampAuto;
    void updateSliderValue(int value);
    void changeEvent(QEvent* e);
signals:
    void dialogClose();

    void updateTherapyRampTimeParameter(void);

    void writeParameterToEeprom(void);

private slots:
    void on_rampTimeAccept_released();

    void on_rampTimeCancel_released();

    void on_rampTimeSlider_valueChanged(int value);

    void smartStartSwitch_clicked();

    void on_rampTimeSlider_sliderPressed();

    void on_rampTimeIncrement_pressed();

    void on_rampTimeDecrement_pressed();

    void showRampTimeScreen();

private:
    Ui::RampStartSettingsBasic *ui;
    DataValidation * dataValidation;

    Switch * smartStartSwitch;

};

#endif // RAMPSTARTSETTINGSBASIC_H
