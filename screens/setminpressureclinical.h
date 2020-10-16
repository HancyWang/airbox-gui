#ifndef SETMINPRESSURECLINICAL_H
#define SETMINPRESSURECLINICAL_H


#include <QDialog>
#include <QGraphicsColorizeEffect>

namespace Ui {
class SetMinPressureClinical;
}

class DataValidation;

class SetMinPressureClinical : public QDialog
{
    Q_OBJECT

public:
    explicit SetMinPressureClinical(QWidget *parent,
                                    DataValidation * dataValidationBackend);
    ~SetMinPressureClinical();

    void updateMinPressureProcessBeforeShow(void);
    void processWarningShowHide(void);
    void updateValueText(int value);

    QGraphicsColorizeEffect * parentEffect;
    void changeEvent(QEvent* e);
signals:
    void dialogClose();

    void writeParameterToEeprom(void);

public slots:
    void showMinPressureScreen();


private slots:
    void on_setMinPressureAccept_released();

    void on_setMinPressureCancel_released();

    void on_setMinPressureIncrement_pressed();

    void on_setMinPressureDecrement_pressed();

    void on_setMinPressureSlider_sliderPressed();

    void on_setMinPressureSlider_valueChanged(int value);

private:
    Ui::SetMinPressureClinical *ui;
    DataValidation * dataValidation;

    int setPres;
    int validMaxPressure;

};

#endif // SETMINPRESSURECLINICAL_H
