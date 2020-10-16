#ifndef SNOOZETIMESETTINGSBASIC_H
#define SNOOZETIMESETTINGSBASIC_H

#include <QDialog>
#include <QGraphicsColorizeEffect>

namespace Ui {
class SnoozeTimeSettingsBasic;
}

class DataValidation;

class SnoozeTimeSettingsBasic : public QDialog
{
    Q_OBJECT

public:
    explicit SnoozeTimeSettingsBasic(QWidget *parent,
                                     DataValidation * dataValidationBackend);
    ~SnoozeTimeSettingsBasic();

    QGraphicsColorizeEffect * parentEffect;
    void updateSliderValue(int value);
    void updateSnoozeTimeProcessBeforeShow(void);
    void changeEvent(QEvent* e);
signals:
    void dialogClose();

    void writeParameterToEeprom(void);

private slots:
    void on_snoozeTimeSlider_valueChanged(int value);

    void on_snoozeTimeCancel_released();

    void on_snoozeTimeAccept_released();

    void on_snoozeTimeSlider_sliderPressed();

    void on_snoozeTimeIncrement_pressed();

    void on_snoozeTimeDecrement_pressed();

    void showSnoozeTimeScreen();

private:
    Ui::SnoozeTimeSettingsBasic *ui;
    DataValidation * dataValidation;

    int snoozeTime;
};

#endif // SNOOZETIMESETTINGSBASIC_H
