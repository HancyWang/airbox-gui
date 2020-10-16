#ifndef RESTOREDEFAULTSWINDOWCLINICAL_H
#define RESTOREDEFAULTSWINDOWCLINICAL_H

#include <QDialog>
#include <QGraphicsColorizeEffect>


namespace Ui {
class RestoreDefaultsWindowClinical;
}

class DataValidation;

class RestoreDefaultsWindowClinical : public QDialog
{
    Q_OBJECT

public:
    explicit RestoreDefaultsWindowClinical(QWidget *parent,
                                           DataValidation * dataValidationBackend);
    ~RestoreDefaultsWindowClinical();

    QGraphicsColorizeEffect * parentEffect;
    void changeEvent(QEvent* e);
signals:
    void restoreDefaultTunningParameters(void);

    void writeParameterToEeprom(void);
    void factoryDefaultVariables(void);


private slots:
    void on_restoreFactoryYes_released();

    void on_restoreFactoryNo_released();

    void showRestoreDefaultScreen();

private:
    Ui::RestoreDefaultsWindowClinical *ui;
    DataValidation * dataValidation;
};

#endif // RESTOREDEFAULTSWINDOWCLINICAL_H
