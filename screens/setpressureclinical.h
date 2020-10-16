#ifndef SETPRESSURECLINICAL_H
#define SETPRESSURECLINICAL_H


#include <QDialog>
#include <QGraphicsColorizeEffect>

namespace Ui {
class SetPressureClinical;
}

class DataValidation;

class SetPressureClinical : public QDialog
{
    Q_OBJECT

public:
    explicit SetPressureClinical(QWidget *parent,
                                 DataValidation * dataValidationBackend);
    ~SetPressureClinical();

    void updatePressureProcessBeforeShow(void);
    void updatePressureValueText(int value);

    QGraphicsColorizeEffect * parentEffect;
    void changeEvent(QEvent* e);
signals:
    void dialogClose();
    void writeParameterToEeprom(void);

private slots:
    void on_setPressureAccept_released();

    void on_setPressureCancel_released();

    void on_setPressureSlider_sliderPressed();

    void on_setPressureSlider_valueChanged(int value);

    void on_setPressureIncrement_pressed();

    void on_setPressureDecrement_pressed();

public slots:
    void showSetPressureScreen();

private:
    Ui::SetPressureClinical *ui;
    DataValidation * dataValidation;

    int setPres;
};

#endif // SETPRESSURECLINICAL_H
