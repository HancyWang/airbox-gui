#ifndef BRIGHTNESSCONTROLTHREAD_H
#define BRIGHTNESSCONTROLTHREAD_H


#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QTimer>


#define SAMPLING_AVERAGE_TIME    5

#define BRIGHTNESS_RAMP_TIME        10
#define BRIGHTNESS_MAX_RAMP_TIME    500
#define BRIGHTNESS_MAX_RAMP_COUNT    50

#include "application.h"
class BrightnessControlThread : public QObject
{
    Q_OBJECT

public:
    BrightnessControlThread(QObject * parent = nullptr);

    void updateBrightnessIntensity(int bIntensity);
    void updateRGBLedColorAsPerRequiment(int color);
    void setColorForRGB(colorCodeRgb * colorCode);
    void setRGBLedColorsValues(void);
    void processBrightnessOutputChange(float newValue);
    int getTimeInSecondsForDisplayDim(void);
    void onShutdownRequiredProcedure(void);

    static bool statusUpdate;
    static bool brightnessStatus;
    static int brightnessIntensity;
    static int prevBrightnessIntensity;

    QFile * brightness;
    QFile * opt3001;
    QFile * opt3001IrqFile;
    QTextStream * out;
    QString * str;
    QTimer * timerBrightness;
    QTimer * brightnessRampTimer;
    QTimer * buttonStateCheckTimer;
    QTimer * snoozeTimeoutTimer;
    QTimer * touchTimeoutTimer;
    QTimer * displayDimTimer;
    QFile * switchFile;
    QFile * redLedColor;
    QFile * greenLedColor;
    QFile * blueLedColor;
    QFile * touchFile;
    QTimer * lightSensorSecondsTimer;
    QTimer * rgbLedColorUpdateTimer;


    float sampleAverageBuffer[SAMPLING_AVERAGE_TIME];
    static int sampleIndex;
    static float brightnessRampStep;
    static int brightnessRampIndex;
    static int brightnessRampDirection;
    static int updatedBrightnessValue;
    static int switchInterrupt;
    static int prevSwitchInterrupt;
    static int touchInterrupt;
    static int prevTouchInterrupt;
    static bool isLcdOff;
    static float localLightSensorData;
    static int prevOpt3001IrqCount;
    int tCurrentRGBColorMode=0;
    int tBrightnessIntensity=0;

signals:
    void snoozeButtonPressedDetected(int state);
    void sendAmbientLightSensorData(float luxParam);
    void powerOffProcedureSignal();
    void showHomeWindow();

public slots:
    void sendBrightnessControlData(bool control,int level);
    void readLightSensorDataIntensity(void);
    void brightnessRampTimerSlot(void);
    void buttonStateCheckTimerTimeout(void);
    void snoozeStateTimerTimeout(void);
    void touchTimerTimeout(void);
    void displayDimTimerTimeout(void);
    void processLightSensorDataEverySecond(void);
    void rgbLedColorUpdateTimerTimeOut(void);

private:
    rgbColorCodeList colorCodeList;

};

#endif // BRIGHTNESSCONTROLTHREAD_H
