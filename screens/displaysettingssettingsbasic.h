#ifndef DISPLAYSETTINGSSETTINGSBASIC_H
#define DISPLAYSETTINGSSETTINGSBASIC_H

#include <QDialog>
#include <QPropertyAnimation>

#include "widgets/button1.h"
#include "constants.h"

namespace Ui {
class DisplaySettingsSettingsBasic;
}

class DisplayDimBrightnessSettingsBasic;
class BrightnessAdjustBrightnessSettingsBasic;
class SettingsWindowBasic;

class DisplaySettingsSettingsBasic : public QDialog
{
    Q_OBJECT

public:
    explicit DisplaySettingsSettingsBasic(QWidget *parent,
                                          BrightnessAdjustBrightnessSettingsBasic * brightnessAdjustBackend,
                                          DisplayDimBrightnessSettingsBasic * displaydimBrightnessBackend,
                                          SettingsWindowBasic * settingsBasicBackend);
    ~DisplaySettingsSettingsBasic();

    void changeEvent(QEvent* e);
    void updateButton1Details(Button1 * pButton,const QString &Title,const QString &imageLeft,const QString &imageRight);
    void addButtonsToScreen(void);
    void animateDisplaySettingsWindow(const openCloseStatus &state);
    void updateBrightnessDisplaySettings();
    void updateDisplayDimDurationSettings();
    void updateDisplaySettingsProcessBeforeShow(void);
    void updateText();
signals:
    void showBrightnessAdjustScreen();
    void showDisplayDimBrightnessScreen();

private slots:
    void on_backDisplaySettings_released();
    void brightnessDisplaySettings_released();
    void dimDurationDisplaySettings_released();
    void brightnessAdjustClosed();
    void displayDimClosed();

public slots:
    void showDisplaySettingsScreen();

private:
    Ui::DisplaySettingsSettingsBasic *ui;
    BrightnessAdjustBrightnessSettingsBasic * brightnessAdjustScreen;
    DisplayDimBrightnessSettingsBasic * displaydimBrightnessScreen;
    SettingsWindowBasic * settingsBasicScreen;

    QPropertyAnimation * m_Anim;

    Button1 * brightnessDisplaySettings;
    Button1 * dimDurationDisplaySettings;

};

#endif // DISPLAYSETTINGSSETTINGSBASIC_H
