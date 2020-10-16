#ifndef BLOWERTESTAPPLICATION_H
#define BLOWERTESTAPPLICATION_H


#include <QDialog>

namespace Ui {
class BlowerTestApplication;
}

class ManufacturingOptionsScreen;

class BlowerTestApplication : public QDialog
{
    Q_OBJECT

public:
    explicit BlowerTestApplication(QWidget *parent,
                                   ManufacturingOptionsScreen * manufacturingOptionsBackend);
    ~BlowerTestApplication();
    void changeEvent(QEvent* e);
public slots:
    void onProgressChanged(QString info);

signals:
    void startStopStateChanged_toThread(int state,int setRpm,int rampTime);
    void sendSetParameters_toThread(int setRpm);
    void sendBrakeSignal_toThread(int type,int intensity);

private slots:
    void on_startStopButton_released();
    void on_incrementButton_released();
    void on_decrementButton_released();
    void setMonitoringStatus(int status);
    void updateBlowerPwmControl(void);
    void on_exitButton_clicked();

    void on_brakeDecrementButton_released();

    void on_brakeIncrementButton_released();

    void on_resBrakeButton_clicked();

    void on_plugBrakeButton_clicked();

    void on_noBrakeButton_clicked();

private:
    Ui::BlowerTestApplication *ui;
    ManufacturingOptionsScreen * manufacturingOptionsScreen;

    static int count;
    static int blowerState;
    static int brakeType;
    static int brakePercent;

};

#endif // BLOWERTESTAPPLICATION_H
