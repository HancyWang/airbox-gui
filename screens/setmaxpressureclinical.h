#ifndef SETMAXPRESSURECLINICAL_H
#define SETMAXPRESSURECLINICAL_H

#include <QDialog>
#include <QGraphicsColorizeEffect>

namespace Ui {
class SetMaxPressureClinical;
}

class DataValidation;

class SetMaxPressureClinical : public QDialog
{
    Q_OBJECT

public:
    explicit SetMaxPressureClinical(QWidget *parent,
                                    DataValidation * dataValidationBackend);
    ~SetMaxPressureClinical();

    void updateMaxPressureProcessBeforeShow(void);
    void processWarningShowHide(void);
    void updateValueText(int value);

    QGraphicsColorizeEffect * parentEffect;
    void changeEvent(QEvent* e);
signals:
    void dialogClose();

    void writeParameterToEeprom(void);

public slots:
    void showMaxPressureScreen();

private slots:
    void on_setMaxPressureIncrement_pressed();

    void on_setMaxPressureDecrement_pressed();

    void on_setMaxPressureAccept_released();

    void on_setMaxPressureCancel_released();

    void on_setMaxPressureSlider_sliderPressed();

    void on_setMaxPressureSlider_valueChanged(int value);

private:
    Ui::SetMaxPressureClinical *ui;
    DataValidation * dataValidation;

    int setPres;
    int validMinPressure;
};

#endif // SETMAXPRESSURECLINICAL_H
