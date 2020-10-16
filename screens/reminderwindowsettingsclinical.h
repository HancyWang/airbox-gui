#ifndef REMINDERWINDOWSETTINGSCLINICAL_H
#define REMINDERWINDOWSETTINGSCLINICAL_H

#include <QDialog>
#include <QPropertyAnimation>

#include "constants.h"
#include "widgets/button2.h"

namespace Ui {
class ReminderWindowSettingsClinical;
}

class SettingsWindowClinical;
class AirFilterWindowReminderClinical;
class AirTubeWindowReminderClinical;
class MaskWindowReminderClinical;
class DataValidation;

class ReminderWindowSettingsClinical : public QDialog
{
    Q_OBJECT

public:
    explicit ReminderWindowSettingsClinical(QWidget *parent,
                                            SettingsWindowClinical * settingsClinicalBackend,
                                            AirFilterWindowReminderClinical * airFilterBackend,
                                            AirTubeWindowReminderClinical * airtubeBackend,
                                            MaskWindowReminderClinical * maskReminderBackend,
                                            DataValidation * dataValidationBackend);
    ~ReminderWindowSettingsClinical();

    void setupWindowParameters();
    void updateReminderWindowProcessBeforeShow(void);
    void updateButton2Details(Button2 * pButton,const QString &Title,const QString &imageLeft);
    void animateSettingsWindow(openCloseStatus state);
    void updateMaskStatus(void);
    void updateAirFilterStatus(void);
    void updateAirTubeStatus(void);
    void changeEvent(QEvent* e);
    void updateText();
private slots:
    void on_backReminders_released();
    void maskButton_released();
    void airTubeButton_released();
    void airFilterButton_released();
    void maskButtonSwitch_clicked();
    void airTubeButtonSwitch_clicked();
    void airFilterButtonSwitch_clicked();

signals:
    void showMaskReminderScreen();

    void showAirFilterReminderScreen();

    void showAirTubeReminderScreen();

    void writeParameterToEeprom(void);

public slots:
    void showReminderClinicalScreen();

private:
    Ui::ReminderWindowSettingsClinical *ui;
    SettingsWindowClinical * settingsClinicalScreen;
    AirFilterWindowReminderClinical * airFilterScreen;
    AirTubeWindowReminderClinical * airtubeScreen;
    MaskWindowReminderClinical * maskReminderScreen;
    DataValidation * dataValidation;

    QPropertyAnimation * m_Anim;

    Button2 * maskButton;
    Button2 * airTubeButton;
    Button2 * airFilterButton;

};

#endif // REMINDERWINDOWSETTINGSCLINICAL_H
