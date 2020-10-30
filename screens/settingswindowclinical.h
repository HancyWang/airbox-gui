#ifndef SETTINGSWINDOWCLINICAL_H
#define SETTINGSWINDOWCLINICAL_H

#include <QDialog>
#include <QPropertyAnimation>

#include "widgets/button1.h"
#include "application.h"
#include "constants.h"

namespace Ui {
class SettingsWindowClinical;
}

class HomeWindowClinical;
class DeviceInfoSettingsBasic;
class PasswordCheckScreen;

class SettingsWindowClinical : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsWindowClinical(QWidget *parent,
                                    HomeWindowClinical * homeClinicalBackend,
                                    DeviceInfoSettingsBasic * deviceInfoBackend,
                                    PasswordCheckScreen * passwordCheckBackend);
    ~SettingsWindowClinical();

    void addButtons(void);
    void updateButton1Details(Button1 * pButton,const QString &Title,const QString &imageLeft,const QString &imageRight);
    void animateSettingsWindow(openCloseStatus state);
    void updateSettingsWindowClinicalBeforeShow(void);
    void changeEvent(QEvent* e);
    void updateText();

private slots:
    void therapyButton_released();
//    void therapyButton_clicked();
    void comfortButton_released();
    void accessoriesButton_released();
    void optionsButton_released();
    void remindersButton_released();
    void configurationButton_released();
    void deviceInfoButton_released();
    void menufacturingOptionsButton_released();

    void on_homeSettings_released();

    void passwordCheckWindowClosed();

signals:
    void showDeviceInfoScreen(QWidget *parent);

    void showTherapyClinicalScreen();

    void showComfortClinicalScreen();

    void showAccesoriesClinicalScreen();

    void showOptionsClinicalScreen();

    void showReminderClinicalScreen();

    void showConfigurationClinicalScreen();

    void showPasswordEnterScreen(const int *password);

    void showManufacturingOptionsScreen(QWidget *parent);

public slots:
    void showSettingsClinicalScreen();

private:
    Ui::SettingsWindowClinical *ui;
    HomeWindowClinical * homeClinicalScreen;
    DeviceInfoSettingsBasic * deviceInfoScreen;
    PasswordCheckScreen * passwordCheckScreen;

    QPropertyAnimation * m_Anim;

    Button1 * therapyButton;
    Button1 * comfortButton;
    Button1 * accessoriesButton;
    Button1 * optionsButton;
    Button1 * remindersButton;
    Button1 * configurationButton;
    Button1 * deviceInfoButton;
    Button1 * menufacturingOptionsButton;

    static const int manufacturingPassword[9];
};

#endif // SETTINGSWINDOWCLINICAL_H
