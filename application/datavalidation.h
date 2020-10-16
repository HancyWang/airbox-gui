#ifndef DATAVALIDATION_H
#define DATAVALIDATION_H



#define DEVICE_INFORMATION              0
#define DEVICE_INFORMATION_LENGTH       16

#define DEVICE_DATA_OFFSET              (DEVICE_INFORMATION + DEVICE_INFORMATION_LENGTH + 4)
#define EEPROM_PARAMETER_LENGTH         150

#define TUNE_PARAMETER_OFFSET           (DEVICE_DATA_OFFSET + EEPROM_PARAMETER_LENGTH + 4)
#define TUNE_PARAMETER_LENGTH           150

#define DEVICE_LIFE_DATA_OFFSET         (TUNE_PARAMETER_OFFSET + TUNE_PARAMETER_LENGTH + 4)
#define DEVICE_LIFE_DATA_LENGTH         50

enum {
    TARGET_PRESSURE=0,
    AIR_FILTER_TYPE,
    PRESSURE_UNIT,
    PRESSURE_OFFSET,
    FLOW_SLOP,
    GO_TO_SLEEP_TIME,
    GO_TO_SLEEP_STATE,
    GO_TO_SLEEP_AUTO,
    RAMP_TIME,
    RAMP_STATE,
    RAMP_TIME_AUTO,
    BRIGTNESS_CONTROL_STATE,
    DISPLAY_DIM_DURATION,
    BRIGHTNESS_LEVEL,
    AUTO_THERAPY,
    AUTO_START_THERAPY,
    BLUETOOTH_STATE,//SLEEP_TITRATION_MODE,
    POWER_SAVINGS,
    SNOOZE_STATE,
    SNOOZE_TIME,
    SEND_SLEEP_REPORT_DURATION,
    COMFORT_LEVEL_STATE,
    COMFORT_LEVEL,
    MASK_FIT_TEST,
//    HOURS_OF_FLOW_GENERATION,
    THERAPY_MODE,
    MASK_TYPE,
    SET_MIN_PRESSURE,
    SET_MAX_PRESSURE,
    AIRFILTER_CHANGE_YEAR,
    AIRFILTER_CHANGE_MONTH,
    AIRFILTER_CHANGE_DATE,
    AIRFILTER_CHANGE_DURATION,
    AIRFILTER_CHANGE_STATE,
    AIRTUBE_CHANGE_YEAR,
    AIRTUBE_CHANGE_MONTH,
    AIRTUBE_CHANGE_DATE,
    AIRTUBE_CHANGE_DURATION,
    AIRTUBE_CHANGE_STATE,
    MASK_CHANGE_YEAR,
    MASK_CHANGE_MONTH,
    MASK_CHANGE_DATE,
    MASK_CHANGE_DURATION,
    MASK_CHANGE_STATE,
    DIAGNOSTIC_DATA,
    LANGUAGE,
    CRC_CHECKSUM_CALCULATED
};

#include <QObject>
#include <QStringList>
#include <QFile>

class DataValidation : public QObject
{
    Q_OBJECT

public:
    DataValidation(QObject * parent = 0);
    ~DataValidation();

//    Q_ENUM(DATA_VALIDATION_ENUMS);

    void readParameterFromEeprom(void);
    void parseUpdateEepromData(const QString & str);
    bool validateDataRead(void);
    void updateMinMaxOtherVariables(void);
    void eraseParameterBlock(void);
    void readDeviceInformationFromEeprom(void);
    void updateParameters(void);

    void eraseTunningParameterBlock(void);
    void parseUpdateTunningEepromData(const QString & str);

    void readDeviceLifeDataFromEeprom(void);
    void eraseDeviceInformationBlock(void);
    void eraseDeviceLifeDataBlock(void);

    QFile * eeprom;
    QStringList parameterList;
    int listItems;
    bool isDataValid=false;

    int eepromData[256];
    unsigned int readChecksum=0;

signals:
    void updateTunningParametersFromEeprom(QStringList & listTuneData);

    void restoreDefaultTunningParameters(void);

public slots:
    void writeDeviceInformationToEeprom(void);

    void writeDeviceLifeDataToEeprom(void);

    void writeTuneParameterToEeprom(int * tuneParam);

    void writeParameterToEeprom(void);

    void factoryDefaultVariables(void);

    void readTunningParameterFromEeprom(void);

};

#endif // DATAVALIDATION_H
