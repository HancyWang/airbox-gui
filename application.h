#ifndef APPLICATION_H
#define APPLICATION_H

#include <QString>
#include <QTranslator>
#include <QApplication>

enum OnOff{
    Off=0,
    On
};
struct bluetoothParam {
   OnOff state;
   int totalPairedDevices;
   int currentPairedDeviceIndex;
   char pairedDeviceNames[5][20];
};
struct goToSleepParam {
    bool isRunning;
   OnOff state;
   OnOff Auto;
   int goToSleepTime;
   int changeInterval;
   int minLimit;
   int maxLimit;
   int countMinutes;
   int countSeconds;
};
struct rampTimeParam {
    bool isRunning;
   OnOff state;
   OnOff Auto;
   int rampTime;
   int changeInterval;
   int minLimit;
   int maxLimit;
   int countMinutes;
   int countSeconds;
};
struct displaySettingsParam {
   OnOff autoBrightnessAdjustment;
   int displayDimDuration;
   int changeDisplayDimDurationInterval;
   int minDisplayDimDurationLimit;
   int maxDisplayDimDurationLimit;
   int brightnessLevel;
   int minBrightnessLevel;
   int maxBrightnessLevel;
};

enum comfortLevelType{
    COMFORT_LEVEL_1=1,
    COMFORT_LEVEL_2,
    COMFORT_LEVEL_3
};

enum sendSleepReportParam {
    day1=1,
    week1,
    month1,
    month3,
    month6,
    year1
};
struct comfortLevelParam {
    OnOff state;
    comfortLevelType comfortLevelSet;
    int minComfortLevelLimit;
    int maxComfortLevelLimit;
};
struct snoozeParam{
    bool isRunning;
    OnOff snoozePeriod;
    OnOff state;
    int snoozeTime;
    int snoozeInterval;
    int minSnoozeTime;
    int maxSnoozeTime;
    int countMinutes;
    int countSeconds;
};
enum therapyPeriodParam {
    GoToSleep=1,
    RampTime,
    Snooze,
    Therapy
};
struct pressureParam {
    int pressureOffset;
    float setPressure;
    int currentPressure;
    float pressureStep;
    int targetedPressure;
    int apapMaxPressure;
    int apapMinPressure;
    int globalMaxPressure;
    int globalMinPressure;
};
enum airFilterParam {
    standardFilter=0,
    hepaFilter
};
enum sleepReportTypeParam {
    customSleepReport=0,
    defaultSleepReport
};
enum pressureUnitTypeParam {
    cmh2o=0,
    hpa
};

enum eventTypeParam {
    apnoeaEvent=0,
    hypoApnoeaEvent
};

enum languageParam {
    //language_english=0,
    //language_chinese,
    //language_spanish

    language_chinese=0,
    language_english,
    language_japanese,
    language_spanish
};

struct dateParam {
    int date;
    int month;
    int year;
};
struct reminderParamStruct {
    OnOff state;
    int changeDuration;
    dateParam setStartDate;
    int maxDuration;
    int minDuration;
};

struct reminderParam {
    reminderParamStruct mask;
    reminderParamStruct airTube;
    reminderParamStruct airFilter;
};
struct timeParam {
    int hour;
    int minute;
};

enum maskFitParam {
    badMaskFit = 1,
    intermediateMaskFit,
    goodMaskFit
};

struct maskFitTestParam {
    maskFitParam maskFitTestStatus;
    OnOff maskFitTestState;
};

struct therapyTimingParam {
    dateParam date;
    timeParam time;
};
struct usageParam {
    bool active;
    int hours;
    int minutes;
};

struct sessionDeviceUsageParam {
    int ahiEvents;
    int apneaEvents;
    int hypoApneaEvents;
    float percentilePressure;
    float percentileLeakage;
    float averagePressure;
    float averageLeakage;
    usageParam flowGeneration;
    usageParam patientUse;
    therapyTimingParam therapyStartTime;
    therapyTimingParam therapyStopTime;
};
struct deviceLifeRelatedParam {
    float totalHoursFlowGeneration;
    unsigned int totalMinutesOfFlowGeneration;
};

enum therapyModeParam {
    cpapMode=0,
    apapMode
};

enum maskTypeParam {
    nasalPillow=1,
    nasalMask
};

struct irqNoParam {
    int remoteProce2IrqNo;
    int remoteProce1IrqNo;
    int touchIrqNo;
    int touchButtonIrqNo;
    int opt3001IrqNo;
};
enum rgbLedColorType{
    RGB_COLOR_STANDBY=1,
    RGB_COLOR_DEVICE_IN_USE,
    RGB_COLOR_BLOWER_RUNNING,
    RGB_COLOR_FAULT_LOW_PRIORITY,
    RGB_COLOR_FAULT_HIGH_PRIORITY,
    RGB_LED_ON,
    RGB_LED_OFF
};

struct colorCodeRgb {
    int redColor;
    int greenColor;
    int blueColor;
};

struct rgbColorCodeList{
    colorCodeRgb standByStatus;
    colorCodeRgb deviceInUse;
    colorCodeRgb blowerRunning;
    colorCodeRgb faultLowPriority;
    colorCodeRgb faultHighPriority;
    colorCodeRgb ledOff;
};

struct flowSensorDara {
//    long long int serialNumber;
    int productId;
    int offset;
    int slop;
    int threshold;
};

struct ApplicationVariables {
    //QApplication* app;
    QStringList titleTextList_choose;
    bool b_enable_compile_airbox_arm_code;
    QTranslator* nTranslator;
    pressureParam pressure;
    flowSensorDara flow;
    rgbLedColorType rgbColorMode;
    therapyModeParam therapyMode;
    OnOff clinicalMode;
    OnOff therapyState;
    OnOff diagnosticData;
    languageParam language;
    dateParam systemDate;
    timeParam systemTime;
//    pressureParam pressure;
//    flowSensorDara flow;
    airFilterParam airFilter;
    reminderParam reminder;
    pressureUnitTypeParam pressureUnit;
    sleepReportTypeParam sleepReportType;
    therapyPeriodParam therapyPeriod;
    bluetoothParam bluetooth;
    goToSleepParam goToSleep;
    rampTimeParam rampTime;
    displaySettingsParam displaySettings;
    OnOff airplaneMode;
    OnOff autoTherapy;
    OnOff sleepTitrationMode;
    OnOff powerSavings;
    OnOff autoStartTherapy;
    snoozeParam snooze;
    sendSleepReportParam sendSleepReportDuration;
    sendSleepReportParam sleepReportDuration;
    comfortLevelParam comfortLevel;
    maskFitTestParam maskFitTest;
    OnOff maskDryState;
    sessionDeviceUsageParam sessionDeviceUsage;
    deviceLifeRelatedParam deviceLifeData;
    maskTypeParam maskType;
    irqNoParam paramIrqNo;
    int rtcHwClock;
    bool isManuFacturingModeEnabled;

    QString serialNumberStr;
};















#endif // APPLICATION_H
