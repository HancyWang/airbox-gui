#include "brightnesscontrolthread.h"
#include "ex_variables.h"


/* Initialize all the class variables to its default values */
bool BrightnessControlThread::brightnessStatus = false;
bool BrightnessControlThread::statusUpdate = false;
int BrightnessControlThread::brightnessIntensity = 0;
int BrightnessControlThread::sampleIndex = 0;
float BrightnessControlThread::brightnessRampStep = 0;
int BrightnessControlThread::brightnessRampIndex = 0;
int BrightnessControlThread::brightnessRampDirection=0;
int BrightnessControlThread::updatedBrightnessValue=0;
int BrightnessControlThread::prevBrightnessIntensity=0;
int BrightnessControlThread::prevSwitchInterrupt = 0;
int BrightnessControlThread::switchInterrupt = 0;
int BrightnessControlThread::touchInterrupt = 0;
int BrightnessControlThread::prevTouchInterrupt = 0;
bool BrightnessControlThread::isLcdOff = false;
float BrightnessControlThread::localLightSensorData = 0;
int BrightnessControlThread::prevOpt3001IrqCount = 0;

/* Class defines */
#define SNOOZE_DETECT_TIME      1000
#define SWITCH_SCAN_INTERVAL    100

BrightnessControlThread::BrightnessControlThread(QObject * parent)
    : QObject(parent),
    brightness(nullptr),
    opt3001(nullptr),
    opt3001IrqFile(nullptr),
    out(nullptr),
    str(nullptr),
    timerBrightness(nullptr),
    brightnessRampTimer(nullptr),
    buttonStateCheckTimer(nullptr),
    snoozeTimeoutTimer(nullptr),
    touchTimeoutTimer(nullptr),
    displayDimTimer(nullptr),
    switchFile(nullptr),
    redLedColor(nullptr),
    greenLedColor(nullptr),
    blueLedColor(nullptr),
    touchFile(nullptr),
    lightSensorSecondsTimer(nullptr),
    rgbLedColorUpdateTimer(nullptr)
{
    this->setObjectName("Brightness Control Thread");

    /* Set default led color as per the indication requirements */
    setRGBLedColorsValues();

    brightness = new QFile("/sys/class/backlight/backlight/brightness");

    /* Create file with path derived from OPT3001 IRQ number */
    QString optStr = "/sys/kernel/irq/" + QString::number(globalVar.paramIrqNo.opt3001IrqNo) + "/per_cpu_count" ;
    QString readIrqStr;
    opt3001IrqFile = new QFile(optStr);
    if(opt3001IrqFile->exists() == true)
    {
        opt3001IrqFile->open(QIODevice::ReadOnly);
        /* Read total interrupts occured
         * untill now
         */
        readIrqStr = opt3001IrqFile->readAll();
        opt3001IrqFile->close();
    }

    /* Convert string to int
     * Update Total IRQ count
     */
    int oprIrqCount = readIrqStr.toInt();
    if(prevOpt3001IrqCount != oprIrqCount)
    {
        prevOpt3001IrqCount = oprIrqCount;
    }

//    opt3001 = new QFile("/dev/iio:device1");
    /* Create file to read Ambient illuminance data */
    opt3001 = new QFile("/sys/bus/iio/devices/iio:device1/in_illuminance_input");

    /* Reset buffer data to 0 */
    memset(sampleAverageBuffer,0,sizeof sampleAverageBuffer);

    /* Modify OPT3001 Integration time to
     * 0.1 Second
     */
    QFile optIntegrationTime("/sys/bus/iio/devices/iio:device1/in_illuminance_integration_time");
    if(optIntegrationTime.exists() == true)
    {
        optIntegrationTime.open(QIODevice::WriteOnly);
        optIntegrationTime.write("0.1",3);
        optIntegrationTime.close();
    }

    redLedColor = new QFile("/sys/class/leds/red_led/brightness");
    greenLedColor = new QFile("/sys/class/leds/green_led/brightness");
    blueLedColor = new QFile("/sys/class/leds/blue_led/brightness");

    /* Create timer to read Ambient light sensor
     * data with specified interval
     */
    timerBrightness = new QTimer(this);
    connect(timerBrightness, SIGNAL(timeout()), this, SLOT(readLightSensorDataIntensity()));
    timerBrightness->start(1000);

    /* Create timer to update RGB led color at every specified interval */
    rgbLedColorUpdateTimer = new QTimer(this);
    connect(rgbLedColorUpdateTimer, SIGNAL(timeout()), this, SLOT(rgbLedColorUpdateTimerTimeOut()));
    rgbLedColorUpdateTimer->start(100);

    /* Process Ambient control Increase/Decrease on this timer slot */
    brightnessRampTimer = new QTimer(this);
    connect(brightnessRampTimer, SIGNAL(timeout()), this, SLOT(brightnessRampTimerSlot()));

    /* Timer to process light sensor data */
    lightSensorSecondsTimer = new QTimer(this);
    connect(lightSensorSecondsTimer, SIGNAL(timeout()), this, SLOT(processLightSensorDataEverySecond()));

    /* Create file with path derived from TOUCH Button number */
    QString switchStr = "/sys/kernel/irq/" + QString::number(globalVar.paramIrqNo.touchButtonIrqNo) + "/per_cpu_count" ;
    switchFile = new QFile(switchStr);
    if(switchFile->exists() == true)
    {
        switchFile->open(QIODevice::ReadOnly);
        QString str = switchFile->readAll();
        switchFile->close();

        /* Convert string to int & update last interrupt count */
        prevSwitchInterrupt = str.toInt();
        switchInterrupt = prevSwitchInterrupt;
        buttonStateCheckTimer = new QTimer(this);
        connect(buttonStateCheckTimer, SIGNAL(timeout()), this, SLOT(buttonStateCheckTimerTimeout()));
        buttonStateCheckTimer->start(SWITCH_SCAN_INTERVAL);

        /* Create timer to detect whether snooze state button pressed or not */
        snoozeTimeoutTimer = new QTimer(this);
        connect(snoozeTimeoutTimer, SIGNAL(timeout()), this, SLOT(snoozeStateTimerTimeout()));
    }

    /* Create file with path derived from TOUCH Screen number */
    QString touchStr = "/sys/kernel/irq/" + QString::number(globalVar.paramIrqNo.touchIrqNo) + "/per_cpu_count" ;
    touchFile = new QFile(touchStr);
    if(touchFile->exists() == true)
    {
        touchFile->open(QIODevice::ReadOnly);
        QString str = touchFile->readAll();
        touchFile->close();

        /* Convert string to int & update last interrupt count */
        prevTouchInterrupt = str.toInt();
        touchInterrupt = prevTouchInterrupt;

        /* Create timer to scan switch interrupt file
         * with specifies interval to detect switch is pressed or not
         */
        touchTimeoutTimer = new QTimer(this);
        connect(touchTimeoutTimer, SIGNAL(timeout()), this, SLOT(touchTimerTimeout()));
        touchTimeoutTimer->start(SWITCH_SCAN_INTERVAL);

        /* Create timer to Dim the display as specified in Display dim in UI Settings
         * will check if the touchTimeoutTimer expires & still no touch event recorded
         */
        displayDimTimer = new QTimer(this);
        connect(displayDimTimer, SIGNAL(timeout()), this, SLOT(displayDimTimerTimeout()));
        displayDimTimer->start(getTimeInSecondsForDisplayDim());
    }
}

int BrightnessControlThread::getTimeInSecondsForDisplayDim()
{
    /* displayDimDuration will have duration in minutes
     * Convert it in to seconds and return the value
     */
    return globalVar.displaySettings.displayDimDuration * 60 * 1000;
}

void BrightnessControlThread::sendBrightnessControlData(bool control,int level)
{
    /* Update Brightness details like AUTO/MANUAL
     * If its manual then brightness level would be required to update
     * also updates brightness level
     */
    brightnessStatus = control;
    brightnessIntensity = level;
    updateBrightnessIntensity(brightnessIntensity);

    /* If brightness control AUTO is selected
     * start Ambient light sensor reading timer
     */
    if(brightnessStatus == true)
        lightSensorSecondsTimer->start(1000);
    else
        lightSensorSecondsTimer->stop();
}

void BrightnessControlThread::updateBrightnessIntensity(int bIntensity)
{
    if(tBrightnessIntensity != bIntensity)
    {
        tBrightnessIntensity = bIntensity;

        /* at value 1 display is purely off */
//        if(tBrightnessIntensity == 0)   tBrightnessIntensity = 1;

        // Set backlight intensity between 25 - 100 %
        if(tBrightnessIntensity < BRIGHTNESS_LEVEL_MIN)
        {
            tBrightnessIntensity = BRIGHTNESS_LEVEL_MIN;
            brightnessIntensity = BRIGHTNESS_LEVEL_MIN;
            prevBrightnessIntensity = BRIGHTNESS_LEVEL_MIN;
        }

        if(tBrightnessIntensity > BRIGHTNESS_LEVEL_MAX)
        {
            tBrightnessIntensity = BRIGHTNESS_LEVEL_MAX;
            brightnessIntensity = BRIGHTNESS_LEVEL_MAX;
            prevBrightnessIntensity = BRIGHTNESS_LEVEL_MAX;
        }

//        qDebug() << Q_FUNC_INFO << tBrightnessIntensity << brightnessIntensity;
        /* Update brightness intensity as per the value
         * to brightness file
         */
        if(brightness->exists() == true)
        {
            brightness->open(QIODevice::WriteOnly);
            QTextStream out(brightness);
            QString str = QString::number(tBrightnessIntensity);
            out << str;
            brightness->close();
        }
    }
}

void BrightnessControlThread::touchTimerTimeout(void)
{
    if(touchFile->exists() == true)
    {
        touchFile->open(QIODevice::ReadOnly);
        QString str = touchFile->readAll();
        touchFile->close();
        prevTouchInterrupt = str.toInt();
        if(touchInterrupt != prevTouchInterrupt)
        {
            touchInterrupt = prevTouchInterrupt;
            if(displayDimTimer->isActive() == true)
                displayDimTimer->stop();

            displayDimTimer->start(getTimeInSecondsForDisplayDim());
        }
    }
}

void BrightnessControlThread::displayDimTimerTimeout(void)
{
float changeBrightness=0;

    displayDimTimer->stop();
    if(isLcdOff == false)       isLcdOff = true;
    processBrightnessOutputChange(changeBrightness);
}

void BrightnessControlThread::processBrightnessOutputChange(float newValue)
{
    /* Check if Brightness newValue and old value are not same
     * If they are same do nothing
     */
    if(brightnessIntensity != static_cast<int>(newValue))
    {
        /* Compare Brightness Old & New value */
        if(brightnessIntensity > static_cast<int>(newValue))
        {
            /* New value is higher than previous
             * than we need to increase TFT brightness
             */
            brightnessRampDirection = 1;
            brightnessRampStep = (static_cast<float>(brightnessIntensity - static_cast<int>(newValue))/BRIGHTNESS_MAX_RAMP_COUNT);
        }
        else
        {
            /* New value is lower than previous
             * than we need to decrease TFT brightness
             */
            brightnessRampDirection = 0;
            brightnessRampStep = (static_cast<float>(static_cast<int>(newValue) - brightnessIntensity)/BRIGHTNESS_MAX_RAMP_COUNT);
        }
        updatedBrightnessValue = static_cast<int>(newValue);

        /* Start Brightness RAMP timer to incrementing/decrementing
         * values at specified interval in specified time frame
         */
        brightnessRampTimer->start(BRIGHTNESS_RAMP_TIME);
        prevBrightnessIntensity = brightnessIntensity;
    }
}

void BrightnessControlThread::readLightSensorDataIntensity(void)
{
//    QString readIrqStr;
//    if(opt3001IrqFile->exists())
//    {
//        opt3001IrqFile->open(QIODevice::ReadOnly);
//        readIrqStr = opt3001IrqFile->readAll();
//        opt3001IrqFile->close();

//        int oprIrqCount = readIrqStr.toInt();
//        qDebug() << "OPT:" << oprIrqCount;
//        if(prevOpt3001IrqCount != oprIrqCount)
//        {
//            prevOpt3001IrqCount = oprIrqCount;
            if(opt3001->exists() == true)
            {
//                QElapsedTimer qElpTimer;
//                qElpTimer.start();
                opt3001->open(QIODevice::ReadWrite);
                QString str;
//                char buff[20];
//                opt3001->read(buff,1);
//                QString bufStr;
//                bufStr = buff;

                str = opt3001->readAll();
                opt3001->close();
                localLightSensorData = str.toFloat();
//                qDebug() << qElpTimer.nsecsElapsed() << str << localLightSensorData << bufStr << bufStr.toInt();

                if(globalVar.isManuFacturingModeEnabled == true)
                    emit sendAmbientLightSensorData(localLightSensorData);
            }
//        }
//    }
}

void BrightnessControlThread::processLightSensorDataEverySecond(void)
{
float temp=0;

    if(brightnessStatus == true)
    {
        sampleAverageBuffer[sampleIndex] = localLightSensorData;

        if(sampleIndex < SAMPLING_AVERAGE_TIME)     sampleIndex++;
        else
        {
            sampleIndex = 0;
            if(brightnessStatus == true)
            {
                for(int i=0 ; i<SAMPLING_AVERAGE_TIME ; i++ )
                {
                    temp += sampleAverageBuffer[i];
                }
                temp = temp/SAMPLING_AVERAGE_TIME;

                // Scaling lux to pwm intensity
                if(temp < 2)        temp=1;
                else if(temp > 100) temp=100;
                else{
    //                    qDebug() << "OPT3001 Scaling Error:" << temp;
                }

                if(isLcdOff == false)                processBrightnessOutputChange(temp);
            }
        }
    }
}

void BrightnessControlThread::buttonStateCheckTimerTimeout(void)
{
    switchFile->open(QIODevice::ReadOnly);
    QString str = switchFile->readAll();
    switchFile->close();
    prevSwitchInterrupt = str.toInt();
    if(prevSwitchInterrupt != switchInterrupt)
    {
        if(!snoozeTimeoutTimer->isActive())
        {
            if(isLcdOff == true)
                snoozeTimeoutTimer->start(500);
            else
                snoozeTimeoutTimer->start(SNOOZE_DETECT_TIME);
        }
//        proceedButtonPressedEvents();
    }
}

//void BrightnessControlThread::proceedButtonPressedEvents(void)
//{
//    if(switchInterrupt != prevSwitchInterrupt)
//    {
//        if(globalVar.therapyState == On)
//        {
//            if(prevSwitchInterrupt >= (switchInterrupt + 4))
//            {
//                if(globalVar.snooze.state == On)            emit snoozeButtonPressedDetected(prevSwitchInterrupt);
//            }
//        }
//        else if(isLcdOff == true)
//        {
//            if(prevSwitchInterrupt >= (switchInterrupt + 2))
//            {
//                isLcdOff = false;
//                int backlighInt=0;
//                if(globalVar.displaySettings.autoBrightnessAdjustment == On)
//                    backlighInt = 75;
//                else
//                    backlighInt = globalVar.displaySettings.brightnessLevel;

//                processBrightnessOutputChange(backlighInt);
//                displayDimTimer->start(getTimeInSecondsForDisplayDim());
//            }
//        }
//        else
//        {
//            if(prevSwitchInterrupt == (switchInterrupt + 1))
//                    emit powerOffProcedureSignal();
//        }
//        switchInterrupt = prevSwitchInterrupt;
//    }
//}

void BrightnessControlThread::snoozeStateTimerTimeout(void)
{
    snoozeTimeoutTimer->stop();
    if(switchInterrupt != prevSwitchInterrupt)
    {
        if(isLcdOff == true)
        {
            if(prevSwitchInterrupt >= (switchInterrupt + 2))
            {
                isLcdOff = false;
                int backlighInt=0;
                if(globalVar.displaySettings.autoBrightnessAdjustment == On)
                    backlighInt = 75;
                else
                    backlighInt = globalVar.displaySettings.brightnessLevel;

                processBrightnessOutputChange(backlighInt);
                displayDimTimer->start(getTimeInSecondsForDisplayDim());
            }
        }
//        else if(globalVar.therapyState == On)
//        {
//            if(prevSwitchInterrupt >= (switchInterrupt + 4))
//            {
//                if(globalVar.snooze.state == On){
//                    Providers::pBackgroundScreen->writeToConsole("Snooze Detected");
//                    emit snoozeButtonPressedDetected(prevSwitchInterrupt);
//                }
//            }
//        }
        else
        {
            if(prevSwitchInterrupt == (switchInterrupt + 1))
            {
                emit powerOffProcedureSignal();
            }
            else
            {
                emit showHomeWindow();
            }
        }
        switchInterrupt = prevSwitchInterrupt;
    }
}

void BrightnessControlThread::brightnessRampTimerSlot(void)
{
    if(brightnessRampDirection == 1)
        brightnessIntensity = prevBrightnessIntensity - static_cast<int>(brightnessRampStep * brightnessRampIndex);
    else
        brightnessIntensity = prevBrightnessIntensity + static_cast<int>(brightnessRampStep * brightnessRampIndex);

    if(brightnessRampIndex < BRIGHTNESS_MAX_RAMP_COUNT)
    {
        brightnessRampIndex++;
        brightnessRampTimer->start(BRIGHTNESS_RAMP_TIME);
    }
    else
    {
        brightnessIntensity = updatedBrightnessValue;
        brightnessRampIndex = 0;
        brightnessRampTimer->stop();
        if(!brightnessIntensity)        globalVar.rgbColorMode = RGB_COLOR_STANDBY;
        else
        {
            if(globalVar.therapyState == On)        globalVar.rgbColorMode = RGB_COLOR_BLOWER_RUNNING;
            else                                    globalVar.rgbColorMode = RGB_COLOR_DEVICE_IN_USE;
        }
    }

    updateBrightnessIntensity(brightnessIntensity);
}

void BrightnessControlThread::setRGBLedColorsValues(void)
{
    /* White: Standby/Display Dimmed */
    colorCodeList.standByStatus.redColor    = 2;
    colorCodeList.standByStatus.greenColor  = 2;
    colorCodeList.standByStatus.blueColor   = 2;

    /* Blue: when device is in use */
    colorCodeList.deviceInUse.redColor      = 255;
    colorCodeList.deviceInUse.greenColor    = 255;
    colorCodeList.deviceInUse.blueColor     = 2;

    /* Green: when blower running */
    colorCodeList.blowerRunning.redColor    = 255;
    colorCodeList.blowerRunning.greenColor  = 2;
    colorCodeList.blowerRunning.blueColor   = 255;

    /* Yellow: Fault condition Low Priority. */
    colorCodeList.faultLowPriority.redColor     = 2;
    colorCodeList.faultLowPriority.greenColor   = 2;
    colorCodeList.faultLowPriority.blueColor    = 255;

    /* Red: Fault condition High Priority. */
    colorCodeList.faultHighPriority.redColor    = 2;
    colorCodeList.faultHighPriority.greenColor  = 255;
    colorCodeList.faultHighPriority.blueColor   = 255;

    /* No Color : Off LED */
    colorCodeList.ledOff.redColor    = 255;
    colorCodeList.ledOff.greenColor  = 255;
    colorCodeList.ledOff.blueColor   = 255;
}

void BrightnessControlThread::updateRGBLedColorAsPerRequiment(int color)
{
    if(tCurrentRGBColorMode != color)
    {
        tCurrentRGBColorMode = color;

        /* Update RGB LED Color as per indication */
        switch(color)
        {
            case RGB_COLOR_STANDBY:
                setColorForRGB(&colorCodeList.standByStatus);
                break;
            case RGB_COLOR_DEVICE_IN_USE:
                setColorForRGB(&colorCodeList.deviceInUse);
                break;
            case RGB_COLOR_BLOWER_RUNNING:
                setColorForRGB(&colorCodeList.blowerRunning);
                break;
            case RGB_COLOR_FAULT_LOW_PRIORITY:
                setColorForRGB(&colorCodeList.faultLowPriority);
                break;
            case RGB_COLOR_FAULT_HIGH_PRIORITY:
                setColorForRGB(&colorCodeList.faultHighPriority);
                break;
            case RGB_LED_OFF:
                setColorForRGB(&colorCodeList.ledOff);
                break;
        }
    }
}

void BrightnessControlThread::setColorForRGB(colorCodeRgb * colorCode)
{

    /* Update RED LED color */
    if(redLedColor->exists() == true) {
        redLedColor->open(QIODevice::WriteOnly);
        QString redColorCode = QString::number(colorCode->redColor);
        redLedColor->write(redColorCode.toLocal8Bit());
        redLedColor->close();
    }

    /* Update GREEN LED color */
    if(greenLedColor->exists() == true) {
        greenLedColor->open(QIODevice::WriteOnly);
        QString greenColorCode = QString::number(colorCode->greenColor);
        greenLedColor->write(greenColorCode.toLocal8Bit());
        greenLedColor->close();
    }

    /* Update BLUE LED color */
    if(blueLedColor->exists() == true) {
        blueLedColor->open(QIODevice::WriteOnly);
        QString blueColorCode = QString::number(colorCode->blueColor);
        blueLedColor->write(blueColorCode.toLocal8Bit());
        blueLedColor->close();
    }
}

void BrightnessControlThread::rgbLedColorUpdateTimerTimeOut(void)
{
    /* Update RGB LED color runs at every timer timeout */
    updateRGBLedColorAsPerRequiment(globalVar.rgbColorMode);
}

void BrightnessControlThread::onShutdownRequiredProcedure(void)
{
    if(timerBrightness->isActive() == true)             timerBrightness->stop();
    if(buttonStateCheckTimer->isActive() == true)       buttonStateCheckTimer->stop();
    if(snoozeTimeoutTimer->isActive() == true)          snoozeTimeoutTimer->stop();
    if(touchTimeoutTimer->isActive() == true)           touchTimeoutTimer->stop();
    if(displayDimTimer->isActive() == true)             displayDimTimer->stop();
    if(lightSensorSecondsTimer->isActive() == true)     lightSensorSecondsTimer->stop();
    if(rgbLedColorUpdateTimer->isActive() == true)      rgbLedColorUpdateTimer->stop();
}
