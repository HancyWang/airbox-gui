#ifndef THERAPYWINDOWBASIC_H
#define THERAPYWINDOWBASIC_H

#include <QDialog>
#include <QPropertyAnimation>

#include "widgets/button3.h"
#include "widgets/therapy_widget.h"
#include "constants.h"
#include "application.h"

#include "application/datalogging.h"

namespace Ui {
class TherapyWindowBasic;
}

class HomeWindowBasic;
class PruControlClass;
class GoToSleepSettingsBasic;
class RampStartSettingsBasic;
class SnoozeExitScreenBasic;
class NotificationTray;

class TherapyWindowBasic : public QDialog
{
    Q_OBJECT

public:
    explicit TherapyWindowBasic(QWidget *parent,
                                DataLogging * m_DataBackend,
                                HomeWindowBasic * m_HomeWindowBackend,
                                PruControlClass * m_IpcBackend,
                                GoToSleepSettingsBasic * gotosleepBackend,
                                RampStartSettingsBasic * rampTimeBackend,
                                SnoozeExitScreenBasic * snoozeExitBackend,
                                NotificationTray * notificationBackend);
    ~TherapyWindowBasic();

    void updateTherapyStatus(bool status);
    void animateTherapyWindow(openCloseStatus state);
    void startTherapyProcedure(void);
    void stopTherapyProcedure(void);
    void updatePressureGraphAsPerMode(therapyPeriodParam mode);
    void updateRemainingTime(void);
    void updateRemainingTimeOnStartStop(void);
    void updateTherapyBasicProcessBeforeShow(void);
    void updateSnoozeTime(void);
    void updateGoToSleepTime(void);
    void updateRampTime(void);
    void processStartStopTherapy(void);

    void updatePressureAsPerMode(void);
    void changeEvent(QEvent* e);
    void updateText();
public slots:
    void showHomeWindowBasic(void);

    void showHideSnoozeTimeFrame(bool showFrame);

    void processGotoSleepRampRuntime(void);

    void updateReferenceWindowParameter(int referenceWindowData);

    void updateCurrentWindowParameter(int currentWindowData);

signals:
    void therapyStartFilesProcess(void);
    void therapyStopFilesProcess(void);

    void beforeStartTherapyProcedure(void);

    void showParameterTunningScreen();

    void updateFlowParameter(int flowData);
    void updateEventTypeStatus(unsigned int event);
    void updateStableStatus(unsigned int tStableFlag);
    void updateMaskLeakStatus(unsigned int tLeakState);
    void updateEnableApap(unsigned int tEnFlag);
    void updateHypoApneaCount(unsigned int tCount);
    void updatebreathCount(int count);
    void updateLeakageCount(int count);

private slots:
    void on_homeTherapyButton_released();
    void startStopTherapyButton_released();

    void on_changeParameterButton_released();

    void updateTherapyGoToSleepTimeParameter(void);

    void updateTherapyRampTimeParameter(void);

    void updateStartStopTherapyDetails(void);

private:
    Ui::TherapyWindowBasic *ui;

    DataLogging * m_DataManager;
    HomeWindowBasic * m_HomeWindow;
    PruControlClass * m_IpcManager;
    GoToSleepSettingsBasic * gotosleepScreen;
    RampStartSettingsBasic * rampTimeScreen;
    SnoozeExitScreenBasic * snoozeExitScreen;
    NotificationTray * notificationScreen;

    QPropertyAnimation * m_Anim;

    Button3 * startStopTherapyButton;
    TherapyWidget * therapyPressure;
    QTimer * secondsTimer;

    static int goToSleepTimeSeconds;
    static int rampTimeSeconds;

    int tSnoozeTimeMinutes=-1;
    int tSnoozeTimeSeconds=-1;
    int tGoToSleepMinutes=-1;
    int tGoToSleepSeconds=-1;
    int tRampMinutes=-1;
    int tRampSeconds=-1;

    therapyPeriodParam tRunningMode;

    int prevCurrentWindow=-1;
    int prevReferenceWindow=-1;

    static const QStringList iconTherapyStateStr;
    static const QStringList therapyStateStr;

};

#endif // THERAPYWINDOWBASIC_H
