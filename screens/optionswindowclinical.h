#ifndef OPTIONSWINDOWCLINICAL_H
#define OPTIONSWINDOWCLINICAL_H

#include <QDialog>
#include <QPropertyAnimation>

#include "constants.h"
#include "widgets/button1.h"
#include "widgets/button2.h"

namespace Ui {
class OptionsWindowClinical;
}

class SettingsWindowClinical;
class DataValidation;

class OptionsWindowClinical : public QDialog
{
    Q_OBJECT

public:
    explicit OptionsWindowClinical(QWidget *parent,
                                   SettingsWindowClinical * settingsClinicalBackend,
                                   DataValidation * dataValidationBackend);
    ~OptionsWindowClinical();

    void animateSettingsWindow(openCloseStatus state);
    void addButtons(void);
    void updateButton2Details(Button2 * pButton,const QString &Title,const QString &imageLeft);
    void updateOptionsWindowClinicalProcessBeforeShow(void);
    void updateAutoStartTherapyText(void);
    void updateSleepLabTitrationText(void);
    void changeEvent(QEvent* e);
    void updateText();
signals:
    void writeParameterToEeprom(void);

private slots:
    void on_backOptions_released();
    void sleepTitrationModeButtonSwitch_clicked();
    void autoStartTherapyButtonSwitch_clicked();

public slots:
    void showOptionsClinicalScreen();

private:
    Ui::OptionsWindowClinical *ui;
    SettingsWindowClinical * settingsClinicalScreen;
    DataValidation * dataValidation;


    QPropertyAnimation * m_Anim;

    Button1 * sleepReportButton;
    Button2 * autoStartTherapyButton;
    Button2 * sleepTitrationModeButton;

};

#endif // OPTIONSWINDOWCLINICAL_H
