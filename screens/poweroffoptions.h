#ifndef POWEROFFOPTIONS_H
#define POWEROFFOPTIONS_H

#include <QDialog>
#include <QGraphicsColorizeEffect>

#include <widgets/button1.h>

namespace Ui {
class PowerOffOptions;
}

class BrightnessControlThread;
class PruControlClass;
class WarningInfoScreen;

class PowerOffOptions : public QDialog
{
    Q_OBJECT

public:
    explicit PowerOffOptions(QWidget *parent,
                             BrightnessControlThread * brightnessBackend,
                             PruControlClass * ipcBackend,
                             WarningInfoScreen * warningBackend);
    ~PowerOffOptions();

    QGraphicsColorizeEffect * parentEffect;
    void updateButton1Details(Button1 * pButton,const QString &Title,const QString &imageLeft,const QString &imageRight);
    void addButtons(void);
    void changeEvent(QEvent* e);
    void updateText();
signals:
    void dialogClose();

    void sendBrightnessControlData(bool control,int level);

    void pruProcessorStartStopProcess(int pruNo,const QString & programmFileStr,bool processorState);

private slots:
    void on_powerOffCancel_released();
    void powerOffButton_released();
    void powerOffTimerTimeout(void);

public slots:
    void startPowerOffProcedure(void);

private:
    Ui::PowerOffOptions *ui;
    BrightnessControlThread * brightnessControl;
    PruControlClass * ipcManager;
    WarningInfoScreen * warningScreen;

    Button1 * powerOffButton;
    QTimer * powerOffTimer;

    int powerOffIndex=2;

};

#endif // POWEROFFOPTIONS_H
