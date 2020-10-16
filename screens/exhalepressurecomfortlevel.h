#ifndef EXHALEPRESSURECOMFORTLEVEL_H
#define EXHALEPRESSURECOMFORTLEVEL_H

#include <QDialog>
#include <QGraphicsColorizeEffect>

#include "application.h"

namespace Ui {
class ExhalePressureComfortLevel;
}

class DataValidation;

class ExhalePressureComfortLevel : public QDialog
{
    Q_OBJECT

public:
    explicit ExhalePressureComfortLevel(QWidget *parent,
                                        DataValidation * dataValidationBackend);
    ~ExhalePressureComfortLevel();

    void updateExhalePressureComfortProcessBeforeShow(void);

    QGraphicsColorizeEffect * parentEffect;
    void changeEvent(QEvent* e);
signals:
    void dialogClose();

    void writeParameterToEeprom(void);

private slots:
    void on_exhaleComfortAccept_released();

    void on_exhaleComfortCancel_released();

    void on_level1Radio_pressed();

    void on_level2Radio_pressed();

    void on_level3Radio_pressed();

    void showExhaleComfortScreen();

private:
    Ui::ExhalePressureComfortLevel *ui;
    DataValidation * dataValidation;

    comfortLevelType level;
};

#endif // EXHALEPRESSURECOMFORTLEVEL_H
