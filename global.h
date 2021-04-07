#ifndef GLOBAL_H
#define GLOBAL_H


#include "screens/notificationtray.h"
#include "screens/backgroundwindow.h"
#include "application/datavalidation.h"


class Providers
{
public:
    Providers();

    static const QString & getAutoStr();
    static const QString & getNavigationIconString();
    static const QString & getOnOffStr(int index);
    static const QString & getTitleTextString(int index);
    static const QString & getIconString(int index);
    static const QString & getPressureUnitTextString(int index);
    static const QString & getUnitTextString(int index);
    static const QString & getlevelStr(int index);
    static const QString & getAirFilterTypeString(int index);
    static const QString & getEmojiIconString(int index);
    static const QString & getMonthsTextString(int index);
    static const QStringList & getMonthStringList(void);
    static const QString & getDateTextString(int index);
    static const QStringList & getDateStringList(void);
    static const QString & getYearTextString(int index);
    static const QStringList & getYearStringList(void);
    static const QString & getMinuteTextString(int index);
    static const QStringList & getMinuteStringList(void);
    static const QString & getHourTextString(int index);
    static const QStringList & getHourStringList(void);
    static const QString & getLanguageString(int index);
    static const QString & getMaskTypeString(int index);
    static const QString & getDeviceInformationString(int index);
    static const QString & getLocalLogFilesPath();
    static const QString & getEdfLogFilesPath(void);
    static const QString & getsoftwareUpdateFilesPath(void);
    static const QString & getSdcardEdfLogFilesPath(void);
    static const QString & getErrorLogFilesPath(void);

    double getFlowEngineeringValues(int rawData);
    double getPressureEngineeringValues(int rawData);
    double getPressureRawToEngineeringWithSlopValues(int rawData);
    double getMotorTempratureEngineeringValues(int rawData);
    double getBlowerSpeedEngineeringValues(int rawData);
    double getVoltageInEngineeringValues(int rawData);
    double getCurrentInEngineeringValues(int rawData);

    void getGoToSleepTime(int * tMinutes,int * tSeconds);
    void getRampTime(int * tMinutes,int * tSeconds);

//    BackgroundWindow * pBackgroundScreen;

    QString serialNumberStr;

    static const QStringList onOffText;
    static const QString autoStrText;
    static const QStringList levelStrText;
    static const QStringList titleTextList_EN;
    //QStringList titleTextList_choose;
    static const QStringList titleTextList_ZH;
    static const QStringList titleTextList_JP;
    static const QStringList iconString;
    static const QString navigationIconStr;
    static const QStringList unitTextStr;
    static const QStringList pressureUnitTextStr;
    static const QStringList airFilterTypeStr;
    static const QStringList emojiIconString;
    static const QStringList monthStr;
    static const QStringList dateStr;
    static const QStringList yearStr;
    static const QStringList hourStr;
    static const QStringList minuteStr;
    static const QStringList languageString;
    static const QStringList maskString;
    static const QStringList deviceInformation;
    static const QString basePath;
    static const QString localLogFiles;
    static const QString edfLogFiles;
    static const QString sdcardEdfLogFiles;
    static const QString softwareUpdateFiles;
    static const QString errorLogFiles;
    static void LANGUAGE_SOURCE_AUTO_CHOOSE();
};


enum TITLE_TEXT_STR_NO {
    THERAPY_STR=0,
    SLEEP_REPORT_STR,
    MASK_OPTION_STR,
    SETTINGS_STR,
    MASK_FIT_TEST_STR,
    MASK_DRY_STR,
    GO_TO_SLEEP_STR,
    RAMP_STR,
    COMFORT_LEVEL_STR,
    AUTO_THERAPY_STR,
    MASK_STR,
    TUBE_STR,
    AIRPLANE_MODE_STR,
    BLUETOOTH_STR,
    SNOOZE_STR,
    POWER_SAVINGS_STR,
    DISPLAY_SETTINGS_STR,
    DEVICE_INFO_STR,
    BRIGHTNESS_STR,
    DISPLAY_DIM_DURATION_STR,
    COMFORT_STR,
    ACCESSORIES_STR,
    OPTIONS_STR,
    REMINDERS_STR,
    CONFIGURATION_STR,
    MODE_STR,
    SET_PRESSURE_STR,
    SET_MIN_PRESSURE_STR,
    SET_MAX_PRESSURE_STR,
    EXHALE_PRESSURE_COMFORT_STR,
    AIR_TUBE_STR,
    AIR_FILTER_STR,
    AUTO_START_THERAPY_STR,
    SLEEP_LAB_TITRATION_MODE_STR,
    LANGUAGE_STR,
    DATE_STR,
    TIME_STR,
    PRESSURE_UNIT_STR,
    DIAGNOSTIC_DATA_STR,
    RESTORE_DEFAULTS_STR,
    ERASE_DATA_STR,
    POWER_OFF_STR,
    MANUFACTURING_OPTION_STR,
    MANUFACTURING_DIAGNOSIS_STR,
    MANUFACTURING_SETUP_STR,
    BLOWER_TEST_APPLICATION_STR,
    PARAMETER_TUNE_STR,
    ENGLISH_STR,
    CHINESE_STR,
    JAPANESE_STR,
    NASAL_PILLOW_STR,
    NASAL_MASK_STR,
    ON_STR,
    OFF_STR,
    LEVEL_1_STR,
    LEVEL_2_STR,
    LEVEL_3_STR,
    STANDART_STR,
    HEPA_STR,
    LEAK_1_STR,
    LEAK_2_STR,
//    JAN_STR,
//    FEB_STR,
//    MAR_STR,
//    APR_STR,
//    MAY_STR,
//    JUN_STR,
//    JUL_STR,
//    AUG_STR,
//    SEP_STR,
//    OCT_STR,
//    NOV_STR,
//    DEC_STR
    START_STR,
    STOP_STR
};


enum ICON_IDX_NO {
    THERAPY_ICON=0,
    SLEEP_REPORT_ICON,
    MASK_OPTION_ICON,
    SETTINGS_ICON,
    MASK_FIT_TEST_ICON,
    MASK_DRY_ICON,
    GO_TO_SLEEP_ICON,
    RAMP_ICON,
    COMFORT_LEVEL_ICON,
    AUTO_THERAPY_ICON,
    MASK_ICON,
    TUBE_ICON,
    AIRPLANE_MODE_ICON,
    BLUETOOTH_ICON,
    SNOOZE_ICON,
    POWER_SAVINGS_ICON,
    DISPLAY_SETTINGS_ICON,
    DEVICE_INFO_ICON,
    BRIGHTNESS_ICON,
    DISPLAY_DIM_DURATION_ICON,
    COMFORT_ICON,
    ACCESSORIES_ICON,
    OPTIONS_ICON,
    REMINDERS_ICON,
    CONFIGURATION_ICON,
    MODE_ICON,
    SET_PRESSURE_ICON,
    EXHALE_PRESSURE_COMFORT_ICON,
    AIR_TUBE_ICON,
    AIR_FILTER_ICON,
    AUTO_START_THERAPY_ICON,
    SLEEP_LAB_TITRATION_MODE_ICON,
    LANGUAGE_ICON,
    DATE_ICON,
    TIME_ICON,
    PRESSURE_UNIT_ICON,
    DIAGNOSTIC_DATA_ICON,
    RESTORE_DEFAULTS_ICON,
    ERASE_DATA_ICON,
    THERAPY_CLINICAL_ICON,
    OPTIONS_SLEEP_REPORT_ICON,
    MANUFACTURING_DIAGNOSIS,
    MANUFACTURING_SETUP,
    POWER_OFF_ICON
};

enum PRESSURE_UNIT_TEXT_STR {
    CMH2O_STR,
    HPA_STR
};
enum UNIT_TEXT_STR{
    MINUTE_UNIT_STR=0,
    PERCENTAGE_UNIT_STR,
};

enum DEVICE_INFO_STR {
    DEVICE_NAME=0,
    DEVICE_SERIAL_NUMBER,
    FIRMWARE_VERSION,
    SOFTWARE_VERSION,
    MANUFACTURER_NAME,
    HARDWARE_VERSION
};
#endif // GLOBAL_H
