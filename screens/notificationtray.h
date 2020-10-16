#ifndef NOTIFICATIONTRAY_H
#define NOTIFICATIONTRAY_H

#include <QDialog>


namespace Ui {
class NotificationTray;
}

class PruControlClass;
class DataLogging;

class NotificationTray : public QDialog
{
    Q_OBJECT

public:
    explicit NotificationTray(QWidget *parent,
                              PruControlClass * ipcBackend,
                              DataLogging * dataLoggingBackend);
    ~NotificationTray();

    bool checkSdcardVisible();
    void changeEvent(QEvent* e);
public slots:
    void updateTime(void);

    void updateAirplaneModeStatus(bool state);
    void updateBluetoothStatus(bool state);
    void updateSdCardStatus(bool state);
    void updateSystemDate(int date,int month,int year);
    void updateSystemTime(int hour,int min,int sec);

    void updateFlowParameter(int flowData);
    void updateEventTypeStatus(unsigned int event);
    void updateStableStatus(unsigned int tStableFlag);
    void updateMaskLeakStatus(unsigned int tLeakState);
    void updateEnableApap(unsigned int tEnFlag);
    void updateHypoApneaCount(unsigned int tCount);
    void updatebreathCount(int count);
    void updateLeakageCount(int count);

    void updateTimeToHWClock();

private:
    Ui::NotificationTray *ui;
    PruControlClass * ipcManager;
    DataLogging * dataLogging;

    QDateTime * dateTime;
    QTimer * timer;
    bool sdcardVisible=false;


    int previousFlowData=0;
    int prevEventType=0;
    int prevStableState=0;
    int prevLeakState=0;
    int prevBreathCount=0;
    int prevApapEn=0;
    int prevHypApneaCount=0;
    int prevLeakageCount=0;


};

#endif // NOTIFICATIONTRAY_H
