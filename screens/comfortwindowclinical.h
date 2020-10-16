#ifndef COMFORTWINDOWCLINICAL_H
#define COMFORTWINDOWCLINICAL_H


#include <QDialog>
#include <QGraphicsColorizeEffect>

#include "constants.h"
#include "widgets/button1.h"
#include "widgets/button2.h"



namespace Ui {
class ComfortWindowClinical;
}

class GoToSleepSettingsBasic;
class RampStartSettingsBasic;
class ExhalePressureComfortLevel;
class SettingsWindowClinical;
class DataValidation;

class ComfortWindowClinical : public QDialog
{
    Q_OBJECT

public:
    explicit ComfortWindowClinical(QWidget *parent,
                                   GoToSleepSettingsBasic * gotosleepBackend,
                                   RampStartSettingsBasic * rampTimeBackend,
                                   ExhalePressureComfortLevel * exhaleComfortBackend,
                                   SettingsWindowClinical * settingsClinicalBackend,
                                   DataValidation * dataValidationBackend);
    ~ComfortWindowClinical();

    void animateSettingsWindow(openCloseStatus state);
    void addButtons(void);
    void updateButton1Details(Button1 * pButton,const QString &Title,const QString &imageLeft,const QString &imageRight);
    void updateButton2Details(Button2 * pButton,const QString &Title,const QString &imageLeft);
    void updateGoToSleepSettings();
    void updateRampTimeSettings();
    void updateComfortWindowClinicalProcessBeforeShow(void);
    void updateExhalePressureComfort(void);

    void changeEvent(QEvent* e);
    void updateText();
signals:
    void showGoToSleepScreen();
    void showRampTimeScreen();
    void showExhaleComfortScreen();
    void writeParameterToEeprom(void);

private slots:
    void on_backComfort_released();
    void goToSleepButton_released();
    void rampButton_released();
    void exhaleComfortButton_released();
    void goToSleepButtonSwitch_clicked();
    void exhaleComfortButtonSwitch_clicked();
    void rampButtonSwitch_clicked();
    void goToSleepClosed();
    void rampClosed();
    void exhaleWindowClosed();

public slots:
    void showComfortClinicalScreen();

private:
    Ui::ComfortWindowClinical *ui;
    GoToSleepSettingsBasic * gotosleepScreen;
    RampStartSettingsBasic * rampTimeScreen;
    ExhalePressureComfortLevel * exhaleComfortScreen;
    SettingsWindowClinical * settingsClinicalScreen;
    DataValidation * dataValidation;

    QPropertyAnimation * m_Anim;

    Button2 * goToSleepButton;
    Button2 * rampButton;
    Button2 * exhaleComfortButton;

    static const QStringList exhaleLevel;
};

#endif // COMFORTWINDOWCLINICAL_H
