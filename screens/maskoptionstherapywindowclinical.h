#ifndef MASKOPTIONSTHERAPYWINDOWCLINICAL_H
#define MASKOPTIONSTHERAPYWINDOWCLINICAL_H

#include <QDialog>
#include <QGraphicsColorizeEffect>

#include "application.h"


namespace Ui {
class MaskOptionsTherapyWindowClinical;
}

class SettingsWindowBasic;
class DataValidation;

class MaskOptionsTherapyWindowClinical : public QDialog
{
    Q_OBJECT

public:
    explicit MaskOptionsTherapyWindowClinical(QWidget *parent,
                                              SettingsWindowBasic * settingsBasicBackend,
                                              DataValidation * dataValidationBackend);
    ~MaskOptionsTherapyWindowClinical();

    void updateMaskInMaskSelectProcessBeforeShow(void);

    QGraphicsColorizeEffect * parentEffect;
    void changeEvent(QEvent* e);
signals:
    void dialogClose();
    void writeParameterToEeprom(void);

public slots:
    void showMaskOptionClinicalScreen();

private slots:
    void on_maskAccept_released();

    void on_maskCancel_released();

    void on_nasalPillow_pressed();

    void on_nasalMask_pressed();


private:
    Ui::MaskOptionsTherapyWindowClinical *ui;
    SettingsWindowBasic * settingsBasicScreen;
    DataValidation * dataValidation;

    maskTypeParam localMaskType;
};

#endif // MASKOPTIONSTHERAPYWINDOWCLINICAL_H
