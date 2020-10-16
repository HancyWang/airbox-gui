#ifndef BRIGHTNESSADJUSTBRIGHTNESSSETTINGSBASIC_H
#define BRIGHTNESSADJUSTBRIGHTNESSSETTINGSBASIC_H

#include <QDialog>
#include <QGraphicsColorizeEffect>

#include "widgets/switch.h"
#include "application.h"

namespace Ui {
class BrightnessAdjustBrightnessSettingsBasic;
}

class BrightnessControlThread;
class DataValidation;

class BrightnessAdjustBrightnessSettingsBasic : public QDialog
{
    Q_OBJECT

public:
    explicit BrightnessAdjustBrightnessSettingsBasic(QWidget *parent,
                                                     BrightnessControlThread * brightnessBackend,
                                                     DataValidation * dataValidationBackend);
    ~BrightnessAdjustBrightnessSettingsBasic();

    void updateBrightnessSettingsBasicBeforeShow(void);
    void brightnessAutoProcessShowHide(OnOff autoStatus);
    QGraphicsColorizeEffect * parentEffect;
    void changeEvent(QEvent* e);
signals:
    void dialogClose();

    void sendBrightnessControlData(bool control,int level);

    void writeParameterToEeprom(void);

private slots:
    void on_brightnessLevelAccept_released();
    void on_brightnessLevelCancel_released();
    void brightnessControlSwitch_clicked();

    void on_brightnessSlider_sliderPressed();

    void on_brightnessSlider_valueChanged(int value);

    void on_brightnessAdjustIncrement_pressed();

    void on_brightnessAdjustDecrement_pressed();

    void showBrightnessAdjustScreen();

private:
    Ui::BrightnessAdjustBrightnessSettingsBasic *ui;
    BrightnessControlThread * brightnessControl;
    DataValidation * dataValidation;

    void updateBrightnessControl(void);

    Switch * brightnessControlSwitch;
    int brightnessLevel;
    OnOff brightnessAuto;
};


#endif // BRIGHTNESSADJUSTBRIGHTNESSSETTINGSBASIC_H
