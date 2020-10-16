#ifndef GOTOSLEEPSETTINGSBASIC_H
#define GOTOSLEEPSETTINGSBASIC_H

#include <QDialog>
#include <QGraphicsColorizeEffect>

#include "widgets/switch.h"
#include "application.h"

namespace Ui {
class GoToSleepSettingsBasic;
}

class DataValidation;

class GoToSleepSettingsBasic : public QDialog
{
    Q_OBJECT

public:
    explicit GoToSleepSettingsBasic(QWidget *parent,
                                    DataValidation * dataValidationBackend);
    ~GoToSleepSettingsBasic();

    void updateGoToSleepProcessBeforeShow(void);
    void goToSleepShowHideLocal(OnOff state);

    QGraphicsColorizeEffect * parentEffect;
    void updateSliderValue(int value);
    void changeEvent(QEvent* e);
public slots:
    void showGoToSleepScreen();

signals:
    void dialogClose();

    void updateTherapyGoToSleepTimeParameter(void);

    void writeParameterToEeprom(void);

private slots:
    void on_goToSleepTimeAccept_released();

    void on_goToSleepTimeCancel_released();

    void on_goToSleepTimeSlider_valueChanged(int value);

    void smartStartSwitch_clicked();

    void on_goToSleepTimeSlider_sliderPressed();

    void on_goToSleepTimeIncrement_pressed();


    void on_goToSleepTimeDecrement_pressed();

private:
    Ui::GoToSleepSettingsBasic *ui;
    DataValidation * dataValidation;

    Switch * smartStartSwitch;
    int goToSleepTimeSet;
    OnOff goToSleepAutoState;
    OnOff goToSleepAuto;
};

#endif // GOTOSLEEPSETTINGSBASIC_H
