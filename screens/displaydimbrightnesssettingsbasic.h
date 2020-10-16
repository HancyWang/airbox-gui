#ifndef DISPLAYDIMBRIGHTNESSSETTINGSBASIC_H
#define DISPLAYDIMBRIGHTNESSSETTINGSBASIC_H


#include <QDialog>
#include <QGraphicsColorizeEffect>

namespace Ui {
class DisplayDimBrightnessSettingsBasic;
}

class DataValidation;

class DisplayDimBrightnessSettingsBasic : public QDialog
{
    Q_OBJECT

public:
    explicit DisplayDimBrightnessSettingsBasic(QWidget *parent,
                                               DataValidation * dataValidationBackend);
    ~DisplayDimBrightnessSettingsBasic();

    void changeEvent(QEvent* e);
    QGraphicsColorizeEffect * parentEffect;
    void updateSliderValue(int value);
    void updateDisplayDimBrightnessProcessBeforeShow(void);

signals:
    void dialogClose();

    void writeParameterToEeprom(void);

private slots:
    void on_displayDimAccept_released();

    void on_displayDimCancel_released();

    void on_displayDimSlider_valueChanged(int value);

    void on_displayDimSlider_sliderPressed();

    void on_displayDimIncrement_pressed();

    void on_displayDimDecrement_pressed();

    void showDisplayDimBrightnessScreen();

private:
    Ui::DisplayDimBrightnessSettingsBasic *ui;
    DataValidation * dataValidation;

    int displayDimDuration;
};

#endif // DISPLAYDIMBRIGHTNESSSETTINGSBASIC_H
