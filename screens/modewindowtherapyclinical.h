#ifndef MODEWINDOWTHERAPYCLINICAL_H
#define MODEWINDOWTHERAPYCLINICAL_H

#include <QDialog>
#include <QGraphicsColorizeEffect>

#include "application.h"

namespace Ui {
class ModeWindowTherapyClinical;
}

class DataValidation;

class ModeWindowTherapyClinical : public QDialog
{
    Q_OBJECT

public:
    explicit ModeWindowTherapyClinical(QWidget *parent,
                                       DataValidation * dataValidationBackend);
    ~ModeWindowTherapyClinical();

    void updateModeInModeSelectWindowProcessBeforeShow(void);

    QGraphicsColorizeEffect * parentEffect;
    void changeEvent(QEvent* e);
signals:
    void dialogClose();
    void writeParameterToEeprom(void);

private slots:
    void on_modeAccept_released();

    void on_modeCancel_released();

    void on_modeCpap_pressed();

    void on_modeApap_pressed();

public slots:
    void showModeScreen();

private:
    Ui::ModeWindowTherapyClinical *ui;
    DataValidation * dataValidation;

    therapyModeParam localMode;
};

#endif // MODEWINDOWTHERAPYCLINICAL_H
