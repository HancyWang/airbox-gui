#ifndef PRESSUREUNITCONFIGURATIONCLINICAL_H
#define PRESSUREUNITCONFIGURATIONCLINICAL_H

#include <QDialog>
#include <QGraphicsColorizeEffect>

#include "application.h"

namespace Ui {
class PressureUnitConfigurationClinical;
}

class DataValidation;

class PressureUnitConfigurationClinical : public QDialog
{
    Q_OBJECT

public:
    explicit PressureUnitConfigurationClinical(QWidget *parent,
                                               DataValidation * dataValidationBackend);
    ~PressureUnitConfigurationClinical();

    void updatePressureUnitProcessBeforeShow(void);
    QGraphicsColorizeEffect * parentEffect;
    void changeEvent(QEvent* e);
signals:
    void dialogClose();

    void writeParameterToEeprom(void);

private slots:
    void on_pressureUnitAccept_released();

    void on_pressureUnitCancel_released();

    void on_hpaRadio_pressed();

    void on_cmh2oRadio_pressed();

    void showPressureUnitScreen();

private:
    Ui::PressureUnitConfigurationClinical *ui;
    DataValidation * dataValidation;

    pressureUnitTypeParam pressureUnit;
};

#endif // PRESSUREUNITCONFIGURATIONCLINICAL_H
