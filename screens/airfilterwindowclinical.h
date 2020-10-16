#ifndef AIRFILTERWINDOWCLINICAL_H
#define AIRFILTERWINDOWCLINICAL_H

#include <QDialog>
#include <QGraphicsColorizeEffect>

#include "constants.h"
#include "application.h"

namespace Ui {
class AirFilterWindowClinical;
}

class AccessoriesWindowClinical;
class DataValidation;

class AirFilterWindowClinical : public QDialog
{
    Q_OBJECT

public:
    explicit AirFilterWindowClinical(QWidget *parent,
                                     AccessoriesWindowClinical * accesoriesBackend,
                                     DataValidation * dataValidationBackend);
    ~AirFilterWindowClinical();

    void updateAirFilterWindowClinical(void);

    QGraphicsColorizeEffect * parentEffect;

    void changeEvent(QEvent* e);
signals:
    void dialogClose();

    void writeParameterToEeprom(void);

private slots:
    void on_airFilterAccept_released();

    void on_airFilterCancel_released();

    void on_hepaRadio_pressed();

    void on_standardRadio_pressed();

    void showAirFilterWindowClinical();

private:
    Ui::AirFilterWindowClinical *ui;
    AccessoriesWindowClinical * accesoriesScreenClinical;
    DataValidation * dataValidation;

    airFilterParam airFilterType;
};

#endif // AIRFILTERWINDOWCLINICAL_H
