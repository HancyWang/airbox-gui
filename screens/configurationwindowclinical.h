#ifndef CONFIGURATIONWINDOWCLINICAL_H
#define CONFIGURATIONWINDOWCLINICAL_H

#include <QDialog>
#include <QGraphicsColorizeEffect>
#include <QPropertyAnimation>

#include "constants.h"
#include "widgets/button1.h"


namespace Ui {
class ConfigurationWindowClinical;
}

class SelectLanguageWindowClinical;
class DateWindowClinical;
class TimeWindowClinical;
class PressureUnitConfigurationClinical;
class EraseDataConfigurationClinical;
class RestoreDefaultsWindowClinical;
class SettingsWindowClinical;
class BackgroundWindow;
class NotificationTray;

class ConfigurationWindowClinical : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigurationWindowClinical(QWidget *parent,
                                         SelectLanguageWindowClinical * selectLanguageWindowBackend,
                                         DateWindowClinical * dateWindowBackend,
                                         TimeWindowClinical * timeWindowBackend,
                                         PressureUnitConfigurationClinical * pressureUnitWindowBackend,
                                         EraseDataConfigurationClinical * eraseDataWindowBackend,
                                         RestoreDefaultsWindowClinical * restoreDefaultWindowBackend,
                                         SettingsWindowClinical * settingsClinicalBackend,
                                         BackgroundWindow * backgroundBackend,
                                         NotificationTray * notificationBackend);
    ~ConfigurationWindowClinical();

    void changeEvent(QEvent* e);
    void animateSettingsWindow(openCloseStatus state);
    void setupWindowParameters();
    void updateButton1Details(Button1 * pButton,const QString &Title,const QString &imageLeft,const QString &imageRight);
    void updateLanguageInCurrentWindow(void);
    void updateDateInCurrentWindow(void);
    void updateTimeInCurrentWindow(void);
    void updateConfigurationClinicalProcessBeforeShow(void);
    void updatePressureUnitLocal(void);
    void updateDateAndTimeGlobally(void);
    void updateText();
private slots:
    void on_backConfiguration_released();
    void languageButton_released();
    void dateButton_released();
    void timeButton_released();
    void pressureUnit_released();
    void restoreDefault_released();
    void eraseData_released();
    void pressureUnitClosed();
    void selectLanguageWindowClosed();
    void dateWindowClosed(int date, int month, int year);
    void timeWindowClosed(int hour, int minute);
    void timeUpdateTimerTimeout();

public slots:
    void showConfigurationClinicalScreen();

signals:
    void showSelectLanguageClinicalScreen();
    void showDateScreen(QWidget *parent, int date, int month, int year, bool colorEffect);
    void showTimeScreen(QWidget *parent, int hour, int minute, bool colorEffect);
    void showPressureUnitScreen();
    void showRestoreDefaultScreen();
    void showEraseDataScreen();

    void updateSystemDate(int date,int month,int year);
    void updateSystemTime(int hour,int min,int sec);

private:
    Ui::ConfigurationWindowClinical *ui;
    SelectLanguageWindowClinical * selectLanguageWindowScreen;
    DateWindowClinical * dateWindowScreen;
    TimeWindowClinical * timeWindowScreen;
    PressureUnitConfigurationClinical * pressureUnitWindowScreen;
    EraseDataConfigurationClinical * eraseDataWindowScreen;
    RestoreDefaultsWindowClinical * restoreDefaultWindowScreen;
    SettingsWindowClinical * settingsClinicalScreen;
    BackgroundWindow * backgroundScreen;
    NotificationTray * notificationScreen;


    QPropertyAnimation * m_Anim;

    Button1 * languageButton;
    Button1 * dateButton;
    Button1 * timeButton;
    Button1 * pressureUnit;
    Button1 * restoreDefault;
    Button1 * eraseData;
    QTimer * timeUpdateTimer;

    static int localLanguage;
    static int localDate;
    static int localMonth;
    static int localYear;
    static int localHour;
    static int localMinute;

};

#endif // CONFIGURATIONWINDOWCLINICAL_H
