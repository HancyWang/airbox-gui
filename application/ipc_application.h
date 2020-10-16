/*
 * application.h
 *
 *  Created on: 26-Mar-2018
 *      Author: jigar
 */

#ifndef IPC_APPLICATION_H_
#define IPC_APPLICATION_H_


//enum {
//    EVENT_TYPE_MASK_OFF=1,
//    EVENT_TYPE_LEAK,
//    EVENT_TYPE_LEAK2,
//};


/* Shared PID data structure - ensure both shared stucts match PRU 0 */
struct pid_data {
    /* PID tunings */
    int kp, ki, ki_neg, ki_pos;

    /* PID controls */
    int control_pressure;
    int pressure_offset;
    int int_err;
    int input, output, last_output;
    int min_output, max_output;
    int prop_part, integral_part;
    int integral_buffer;
    int flowFilterThreshold;
    char flowPercent;
    int flowDetectThrInsp,flowDetectThrExp;
};

/* Shared Therapy Parameters */
struct therapyParameters {
    char ieState;
    char parameterUpdated;
    char manufacturingMode;
    int blowerSpeed;
    char enableBlower;
    char comfortLevelState;
    char therapyState, runningMode ,snoozeState ,therapyMode ,maskFitTestState ,autoStartTherapy ,maskDryState;
    unsigned int goToSleepTimeMinute,rampTimeMinute,exhalePressureComfort,targetPressure,snoozeTimeMinute;
    unsigned int goToSleepTimeSeconds,rampTimeSeconds,snoozeTimeSeconds,pressureStepSize;
    unsigned int apapMinPressure,apapMaxPressure,apapControlPressure;
    unsigned int secondsCount;
};

struct measureParameters {
    char updateToArm, updateToArmCommand;
    char updateType;
    char eventTypeDetected[3];
    int airPressureEng ,airPressureRaw;
    int flowEng, flowRaw;
    int flowEngMax;
    int flowEngMin;
    int prevFlowEng, prevFlowRaw;
    char maskFitTestStatus ,autoStartTherapyDetected ,maskDryStatus;
    int volageInputRaw,voltageInputEng;
    int blowerCurrentRaw,blowerCurrentEng;
    int motorTempRaw,motorTempEng;
    int blowerSpeedFeedback;
};

struct fault_mem {
    char faultCode;
    char faultStatus;
    char prevFaultStatus;

    char BLOWER_IC_FAULTY_ERROR;
    char MCP3204_MEASUREMENT_INVALID_ERROR;
    char MCP3202_MEASUREMENT_INVALID_ERROR;
    char FLOW_SENSOR_FAULT_ERROR;
    char I2C1_BUS_FAULT_ERROR;
//    char MOTOR_OVERCURRENT_ERROR;
//    char CHARGE_PUMP_OVERCURRENT_ERROR;
//    char OVERTEMP_SHUTDOWN_ERROR;
//    char VM_UNDERVOLTAGE_ERROR;
//    char CHARGEPUMP_UNDERVOLTAGE_ERROR;
//    char VM_OVERVOLTAGE_ERROR;
//    char ROTOR_LOCK_CONDITION_ERROR;
//    char HIGH_MOTOR_TEMPERATURE_ERROR;
//    char INPUT_VOLTAGE_HIGH_ERROR;
//    char INPUT_VOLTAGE_LOW_ERROR;
//    char PRESSURE_SENSOR_FAULTY_ERROR;
//    char BLOWER_OVER_CURRENT_ERROR;
//    char SPI_BUS_FAULT_ERROR;
//    char RTC_FAULTY_ERROR;
//    char EEPROM_FAULTY_ERROR;
//    char TOUCHSCREEN_FAULTY_ERROR;
//    char AMBIENT_SENSOR_FAULTY_ERROR;
//    char I2C0_BUS_FAULTY_ERROR;
};
struct serialPrintType {
    char printEnable;
    char printType;
    char totalCount;
    int arrayParam[5];
};

struct dataLoggingType {
    int leak;
    int flow;
    int pressure;
    int mControlPressure;
};

//#define APAP_AMPLITUDE_BUFFER   16
//#define APAP_PERIOD_BUFFER      APAP_AMPLITUDE_BUFFER
struct apap_variables {
//    int w1;
//    int w2;
//    char variable1;
//    char variable2;
//    char variable3;
    char mNewBreathStart;
    unsigned int mBreathTimeCount;
    unsigned int mBreathAmplitudeCurrent;
//    unsigned int mBreathPeriodCurrent;
//    unsigned int mBreathAmplitude[APAP_AMPLITUDE_BUFFER];
//    unsigned int mBreathPeriod[APAP_PERIOD_BUFFER];
    unsigned int mBreathCount;
//    unsigned int mPrevAverage;
    char mStableBreaths;
    char mMaskState;
};

struct sensor_data {
    char mSensorDataUpdated;
    unsigned int mFlowSensorProductNumber;
    unsigned int mFlowSensorSerialNo;
};

struct manufacturing_mode {
    int volageInputRaw;
    int blowerCurrentRaw;
    int motorTempRaw;
    int airPressureRaw;
    int flowRaw;
    uint8_t count;
};

struct timing_data {
    unsigned int mMillisecondCount;
    uint8_t mSecondsFlag;
};

/* Shared memory block struct */
//struct shared_mem {
typedef struct {
    char init_flag;
    volatile char isBlowerRunning;
    volatile char updatePressureOffset;
    volatile struct sensor_data sensorDetails;
    volatile struct dataLoggingType dataLogParam;
    volatile struct therapyParameters therapyData;
    volatile struct measureParameters measuredValues;
    volatile struct pid_data pid;
    volatile struct fault_mem faultDetails;
    volatile struct serialPrintType serialPrint;
    volatile struct apap_variables apapVariables;
    volatile struct manufacturing_mode manufacMode;
    volatile struct timing_data timingControl;
} shared_mem ;

// PRU-ICSS 0x4A300000 -> 0x4A3FFFFF
// PRU-ICSS Global map Shared ram at 0x00010000
// Shared memory 0x4A300000 + 0x00010000 = 0x4A310000
#define PRU_SHARED_MEMORY   0x4A310000

#define pru_data                   ((shared_mem              *) PRU_SHARED_MEMORY)

enum {
    BAD_MASK_FIT=1,
    INTERMEDIATE_MASK_FIT,
    GOOD_MASK_FIT
};

//enum {
//    ALL_PARAMETERS=1,
//    GOTOSLEEP_TIME,
//    RAMP_TIME,
//    EPRESSURE_COMFORT,
//    THERAPY_MODE,
//    TARGET_PRESSURE,
//    SNOOZE_TIME,
//    AUTO_START_THERAPY
//};

//enum {
//    START_STOP_STATE=1,
//    SNOOZE_STATE
//};


enum {
    THERAPY_PERIOD_GOTOSLEEP=1,
    THERAPY_PERIOD_RAMPTIME,
    THERAPY_PERIOD_THERAPY,
    THERAPY_PERIOD_SNOOZE_TIME
};


enum {
    STATE_MACHINE_INIT_INSP=1,
    STATE_MACHINE_INSPIRATION,
    STATE_MACHINE_IE_TRANSITION,
    STATE_MACHINE_EXPIRATION,
    STATE_MACHINE_EI_TRANSITION
};

//enum {
//    COMFORT_LEVEL_1=1,
//    COMFORT_LEVEL_2,
//    COMFORT_LEVEL_3
//};

//enum {
//    cpapMode=0,
//    apapMode
//};




#endif /* APPLICATION_H_ */
