#ifndef DIAGNOSTICDATASCREEN_H
#define DIAGNOSTICDATASCREEN_H

#include <QDialog>
#include <QGraphicsColorizeEffect>

#include "application.h"

namespace Ui {
class DiagnosticDataScreen;
}

class DataValidation;

class DiagnosticDataScreen : public QDialog
{
    Q_OBJECT

public:
    explicit DiagnosticDataScreen(QWidget *parent,
                                               DataValidation * dataValidationBackend);
    ~DiagnosticDataScreen();
    void changeEvent(QEvent* e);
    void updateDiagDataProcessBeforeShow(void);
    QGraphicsColorizeEffect * parentEffect;

signals:
    void dialogClose();

    void writeParameterToEeprom(void);

private slots:
    void on_diagDataAccept_released();

    void on_diagDataCancel_released();

    void on_offRadio_pressed();

    void on_onRadio_pressed();

    void showDiagnosticDataScreen();

private:
    Ui::DiagnosticDataScreen *ui;
    DataValidation * dataValidation;

    OnOff diagnosticData;
};

#endif // DIAGNOSTICDATASCREEN_H
