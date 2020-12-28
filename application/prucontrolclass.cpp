#include "prucontrolclass.h"
#include <QDebug>
#include <ex_variables.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#define IPC_READ_TIMER_COUNT        40//500

#include "application/datalogging.h"

PruControlClass::PruControlClass(QObject *parent,DataLogging * m_DataBackend)
    : QObject(),
      m_DataManager(m_DataBackend),
      ipcReadTimer(nullptr),
      pruMemory(nullptr),
      m_Thread(nullptr)
{
    m_Thread = new QThread;
    m_Thread->setObjectName("PruControlClass");
    connect(m_Thread,SIGNAL(started()),this,SLOT(initPruControl()));
    moveToThread(m_Thread);
    m_Thread->start();
}

PruControlClass::~PruControlClass()
{
    if(m_Thread)
        m_Thread->exit();

    connect(m_Thread,SIGNAL(finished()),m_Thread,SLOT(deleteLater()));
    connect(m_Thread,SIGNAL(finished()),ipcReadTimer,SLOT(deleteLater()));
}

void PruControlClass::powerOnUpdateSettings(void)
{
    pruMemory[eIPC_PID_KP_PARAM] = 30;
    pruMemory[eIPC_PID_KI_PARAM] = 25;
    pruMemory[eIPC_PID_KI_POS_PARAM] = 2000;
    pruMemory[eIPC_PID_KFF_PARAM] = 130;
    pruMemory[eIPC_PID_INTEGRAL_PARAM] = 0;
    pruMemory[eIPC_PID_ERROR_PARAM] = 0;
    pruMemory[eIPC_PID_DRV_OUTPUT_COUNT] = 0;
    pruMemory[eIPC_PID_DRV_LAST_OUTPUT_COUNT] = 0;

    pruMemory[eIPC_THERAPY_RUNNING] = 0;
    pruMemory[eIPC_ARM_UPDATE_TO_PRU0] = 0;

    pruMemory[eIPC_MANUFACTURING_BLOWER_STATE] = 0;
    pruMemory[eIPC_MANUFACTURING_BLOWER_SPEED] = 0;
    pruMemory[eIPC_MANUFACTURING_MODE] = 0;

    beforeStartTherapyProcedure();
}

void PruControlClass::beforePressureOffsetGetProcedure(void)
{
    pruMemory[eIPC_CALIBRATION_PRESSURE_OFFSET_AVERAGE] = 0;
    pruMemory[eIPC_CALIBRATION_PRESSURE_OFFSET_COUNT] = 0;
    pruMemory[eIPC_CALIBRATION_PRESSURE_OFFSET_UPDATED] = 0;
    pruMemory[eIPC_CALIBRATION_GET_PRESSURE_OFFSET] = 1;
}

void PruControlClass::updateTunningParameter(int * param)
{
    pruMemory[eIPC_PARAMETER_TUNE_BREATH_AVERAGE] = param[TUNE_BUFFER_SIZE];
    pruMemory[eIPC_PARAMETER_TUNE_APNEA_THRESHOLD] = param[TUNE_APNEA];
    pruMemory[eIPC_PARAMETER_TUNE_PRECURSOR_THRESHOLD] = param[TUNE_PRECURSOR];

    pruMemory[eIPC_PARAMETER_TUNE_W1] = param[TUNE_W1];
    pruMemory[eIPC_PARAMETER_TUNE_W2] = param[TUNE_W2];
    pruMemory[eIPC_PARAMETER_TUNE_VARIABLE1] = param[TUNE_VARIABLE1];
    pruMemory[eIPC_PARAMETER_TUNE_FLOW_FILTER_COFF] = param[TUNE_FLOW_COFF];

    pruMemory[eIPC_PARAMETER_TUNE_NO_EVENT_FOR_TIME] = param[TUNE_NO_EVENT_FOR_TIME];
    pruMemory[eIPC_PARAMETER_TUNE_MAX_ENABLE_TIME] = param[TUNE_MAX_ENABLE_TIME];
    pruMemory[eIPC_PARAMETER_TUNE_EN_IF_STABLE] = param[TUNE_EN_IF_STABLE];
    pruMemory[eIPC_PARAMETER_TUNE_FLOW_AVERAGE] = param[TUNE_CURRENT_FLOW_AVG];

    pruMemory[eIPC_PARAMETER_TUNE_EVENT_THRESHOLD] = param[TUNE_EVENT_THRESHOLD];
    pruMemory[eIPC_PARAMETER_TUNE_APNEA_INCREMENT] = param[TUNE_APNEA_INCREMENT];
    pruMemory[eIPC_PARAMETER_TUNE_APNEA2_INCREMENT] = param[TUNE_APNEA2_INCREMENT];
    pruMemory[eIPC_PARAMETER_TUNE_HYPOAPNEA_INCREMENT] = param[TUNE_HYPOAPNEA_INCREMENT];
    pruMemory[eIPC_PARAMETER_TUNE_PRECURSOR_INCREMENT] = param[TUNE_PRECURSOR_INCREMENT];

    pruMemory[eIPC_PARAMETER_TUNE_APNEA2_THRESHOLD_COUNT] = param[TUNE_APNEA2_THRESHOLD_COUNT];
    pruMemory[eIPC_PARAMETER_TUNE_LEAK2_THRESHOLD_COUNT] = param[TUNE_LEAK2_THRESHOLD_COUNT];
    pruMemory[eIPC_PARAMETER_TUNE_LEAK_ALGORITHM_STATE] = param[TUNE_LEAK_ALGORITHM_EN];

    pruMemory[eIPC_PARAMETER_TUNE_LEAK_FLOW_MULTIPLIER] = param[TUNE_LEAK_FLOW_MULTIPLIER];
    pruMemory[eIPC_PARAMETER_TUNE_LEAK2_FLOW_MULTIPLIER] = param[TUNE_LEAK2_FLOW_MULTIPLIER];
    pruMemory[eIPC_PARAMETER_TUNE_APNEA2_FLOW_MULTIPLIER] = param[TUNE_APNEA2_FLOW_MULTIPLIER];
    pruMemory[eIPC_PARAMETER_TUNE_FLOW_COFF_EVENT_DETECTION] = param[TUNE_FLOW_COFF_EVENT_DETECTION];

//    pruMemory[eIPC_PARAMETER_TUNE_PRE_CURSOR_THRESHOLDA] = param[TUNE_PRE_CURSOR_THRESHOLDA];
//    pruMemory[eIPC_PARAMETER_TUNE_PRE_CURSOR_THRESHOLDB] = param[TUNE_PRE_CURSOR_THRESHOLDB];
//    pruMemory[eIPC_PARAMETER_TUNE_PRE_CURSOR_THRESHOLDC] = param[TUNE_PRE_CURSOR_THRESHOLDC];

    pruMemory[eIPC_PARAMETER_TUNE_ALGO2_BUFFER_SIZE] = param[TUNE_ALGO2_BUFFER_SIZE];


    pruMemory[eIPC_PARAMETER_TUNE_PRE_CURSOR_THRESHOLD45] = param[TUNE_PRE_CURSOR_THRESHOLD45];
    pruMemory[eIPC_PARAMETER_TUNE_PRE_CURSOR_THRESHOLD67] = param[TUNE_PRE_CURSOR_THRESHOLD67];
    pruMemory[eIPC_PARAMETER_TUNE_PRE_CURSOR_THRESHOLD89] = param[TUNE_PRE_CURSOR_THRESHOLD89];
    pruMemory[eIPC_PARAMETER_TUNE_PRE_CURSOR_THRESHOLD1011] = param[TUNE_PRE_CURSOR_THRESHOLD1011];
    pruMemory[eIPC_PARAMETER_TUNE_PRE_CURSOR_THRESHOLD1213] = param[TUNE_PRE_CURSOR_THRESHOLD1213];
    pruMemory[eIPC_PARAMETER_TUNE_PRE_CURSOR_THRESHOLD1415] = param[TUNE_PRE_CURSOR_THRESHOLD1415];
    pruMemory[eIPC_PARAMETER_TUNE_PRE_CURSOR_THRESHOLD1617] = param[TUNE_PRE_CURSOR_THRESHOLD1617];
    pruMemory[eIPC_PARAMETER_TUNE_PRE_CURSOR_THRESHOLD1819] = param[TUNE_PRE_CURSOR_THRESHOLD1819];
    pruMemory[eIPC_PARAMETER_TUNE_PRE_CURSOR_THRESHOLD20] = param[TUNE_PRE_CURSOR_THRESHOLD20];
    pruMemory[eIPC_PARAMETER_TUNE_REFERENCE_WINDOW] = param[TUNE_REFERENCE_WINDOW];

    pruMemory[eIPC_PARAMETER_TUNE_APNEA_THRESHOLD1011] = param[TUNE_APNEA_THRESHOLD1011];
    pruMemory[eIPC_PARAMETER_TUNE_APNEA_THRESHOLD1213] = param[TUNE_APNEA_THRESHOLD1213];
    pruMemory[eIPC_PARAMETER_TUNE_APNEA_THRESHOLD1415] = param[TUNE_APNEA_THRESHOLD1415];
    pruMemory[eIPC_PARAMETER_TUNE_APNEA_THRESHOLD1617] = param[TUNE_APNEA_THRESHOLD1617];
    pruMemory[eIPC_PARAMETER_TUNE_APNEA_THRESHOLD1819] = param[TUNE_APNEA_THRESHOLD1819];
    pruMemory[eIPC_PARAMETER_TUNE_APNEA_THRESHOLD20] = param[TUNE_APNEA_THRESHOLD20];
    pruMemory[eIPC_PARAMETER_TUNE_APNEA_THRESHOLD45] = param[TUNE_APNEA_THRESHOLD45];
    pruMemory[eIPC_PARAMETER_TUNE_APNEA_THRESHOLD67] = param[TUNE_APNEA_THRESHOLD67];
    pruMemory[eIPC_PARAMETER_TUNE_APNEA_THRESHOLD89] = param[TUNE_APNEA_THRESHOLD89];


//    pruMemory[eIPC_PARAMETER_TUNE_APNEA_THRESHOLD] = 60;
//    pruMemory[eIPC_PARAMETER_TUNE_PRECURSOR_THRESHOLD] = 10;
//    pruMemory[eIPC_PARAMETER_TUNE_MAX_ENABLE_TIME] = 1;
//    pruMemory[eIPC_PARAMETER_TUNE_EN_IF_STABLE] = 1;
//    pruMemory[eIPC_PARAMETER_TUNE_FLOW_AVERAGE] = 2;
//    pruMemory[eIPC_PARAMETER_TUNE_NO_EVENT_FOR_TIME] = 1;
//    pruMemory[eIPC_PARAMETER_TUNE_FLOW_FILTER_COFF] = 10;
//    pruMemory[eIPC_PARAMETER_TUNE_FLOW_COFF_EVENT_DETECTION] = 5;

//    qDebug() << "Tunning" << param[TUNE_BUFFER_SIZE]
//                        << param[TUNE_APNEA]
//                        << param[TUNE_PRECURSOR]
//                        << param[TUNE_W1]
//                        << param[TUNE_W2]
//                        << param[TUNE_VARIABLE1]
//                        << param[TUNE_FLOW_COFF]
//                        << param[TUNE_MAX_ENABLE_TIME]
//                        << param[TUNE_EN_IF_STABLE]
//                        << param[TUNE_CURRENT_FLOW_AVG];
}

void PruControlClass::beforeManufacturingModeProcedure(int manuFactMode,int blowerState,int blowerSpeed)
{
    if(pruMemory[eIPC_MANUFACTURING_MODE] != manuFactMode){
        pruMemory[eIPC_MANUFACTURING_MODE] = manuFactMode;
        pruMemory[eIPC_MANUFACTURING_FLOW_ADC_COUNT] = 0;
        pruMemory[eIPC_MANUFACTURING_PRESSURE_ADC_COUNT] = 0;
        pruMemory[eIPC_MANUFACTURING_VOLTAGE_INPUT_ADC_COUNT] = 0;
        pruMemory[eIPC_MANUFACTURING_BLDC_CURRENT_ADC_COUNT] = 0;
        pruMemory[eIPC_MANUFACTURING_MOTOR_TEMP_ADC_COUNT] = 0;
        pruMemory[eIPC_MANUFACTURING_BLDC_SPEED_RAW_COUNT] = 0;
        pruMemory[eIPC_MANUFACTURING_UPDATE_COUNT] = 0;
    }

    pruMemory[eIPC_MANUFACTURING_BLOWER_SPEED] = blowerSpeed;
    pruMemory[eIPC_MANUFACTURING_UPDATE_COUNT] = 0;

    if(pruMemory[eIPC_MANUFACTURING_BLOWER_STATE] != blowerState){
        pruMemory[eIPC_MANUFACTURING_BLOWER_STATE] = blowerState;
        pruMemory[eIPC_ARM_UPDATE_TO_PRU0] = 1;
    }
}

void PruControlClass::beforeStartTherapyProcedure(void)
{

    pruMemory[eIPC_MASK_DRY_ENABLE] = globalVar.maskDryState;

    int controlPressure =0;
#ifdef CHANGE_PRESSURE_STEP_TO_05
    if(globalVar.therapyMode == cpapMode)
        controlPressure = globalVar.pressure.targetedPressure;
    else
        controlPressure = globalVar.pressure.apapMinPressure;
#else
    if(globalVar.therapyMode == cpapMode)
        controlPressure = globalVar.pressure.targetedPressure * 100;
    else
        controlPressure = globalVar.pressure.apapMinPressure * 100;
#endif

//    Providers::pBackgroundScreen->parameterTuneScreen->sendTunningParameterToPRU();

    pruMemory[eIPC_CALIBRATION_PRESSURE_OFFSET] = globalVar.pressure.pressureOffset;
    pruMemory[eIPC_CALIBRATION_PRESSURE_SLOP] = 758;
    pruMemory[eIPC_CALIBRATION_FLOW_SLOP] = globalVar.flow.slop;
//    pruMemory[eIPC_CALIBRATION_LEAK_THRESHOLD] = globalVar.flow.threshold;
    pruMemory[eIPC_CALIBRATION_FLOW_OFFSET] = 0;

//    qDebug() << Q_FUNC_INFO << globalVar.therapyMode << "tP" << controlPressure << pruMemory[eIPC_CALIBRATION_LEAK_THRESHOLD];

    pruMemory[eIPC_SETTINGS_SET_PRESSURE] = 0;
    pruMemory[eIPC_SETTINGS_TARGET_PRESSURE] = controlPressure;
#ifdef CHANGE_PRESSURE_STEP_TO_05
    pruMemory[eIPC_SETTINGS_MIN_PRESSURE_APAP] = globalVar.pressure.apapMinPressure;
    pruMemory[eIPC_SETTINGS_MAX_PRESSURE_APAP] = globalVar.pressure.apapMaxPressure;
#else
    pruMemory[eIPC_SETTINGS_MIN_PRESSURE_APAP] = globalVar.pressure.apapMinPressure * 100;
    pruMemory[eIPC_SETTINGS_MAX_PRESSURE_APAP] = globalVar.pressure.apapMaxPressure * 100;
#endif
//    qDebug() << "Pressure" << pruMemory[eIPC_SETTINGS_SET_PRESSURE]
//                            << pruMemory[eIPC_SETTINGS_TARGET_PRESSURE]
//                            << pruMemory[eIPC_SETTINGS_MIN_PRESSURE_APAP]
//                            << pruMemory[eIPC_SETTINGS_MAX_PRESSURE_APAP] ;

    int stepSizeInPressure=0,maxDropInPressure=0,comfortLevel=0,comfortState=0,pressureAfterDrop=0;
    if(globalVar.comfortLevel.state == true){
        comfortLevel = globalVar.comfortLevel.comfortLevelSet * 2;
        maxDropInPressure = (comfortLevel * 100);
        stepSizeInPressure = maxDropInPressure / 200;
        pressureAfterDrop = controlPressure - maxDropInPressure;
        comfortState = 1;
    }
    pruMemory[eIPC_SETTINGS_COMFORT_LEVEL] = comfortLevel;
    pruMemory[eIPC_SETTINGS_COMFORT_STATE] = comfortState;
    pruMemory[eIPC_SETTINGS_COMFORT_PRESSURE_STEP_SIZE] = stepSizeInPressure;
    pruMemory[eIPC_SETTINGS_COMFORT_PRESSURE_AFTER_DROP] = pressureAfterDrop;

//    qDebug() << "Comfort" << comfortState << comfortLevel << stepSizeInPressure;

    pruMemory[eIPC_SETTINGS_MODE] = globalVar.therapyMode;

    int tGotoSleepState=0,tGoToSleepTime=0,tGotoSleepCount=0;
    if(globalVar.goToSleep.state == On){
        if(globalVar.goToSleep.goToSleepTime != 0){
            tGoToSleepTime = globalVar.goToSleep.goToSleepTime;
            tGotoSleepState = 1;
            tGotoSleepCount = tGoToSleepTime * 60 * 100;
        }
    }
    pruMemory[eIPC_SETTINGS_GOTOSLEEP_STATE] = tGotoSleepState;
    pruMemory[eIPC_SETTINGS_GOTOSLEEP_MINUTE] = tGoToSleepTime;
    pruMemory[eIPC_SETTINGS_GOTOSLEEP_TIME_COUNT] = tGotoSleepCount;
//    qDebug() << "Goto Sleep" << tGotoSleepState << tGoToSleepTime << tGotoSleepCount;

    int tRampState=0,tRampTime=0,tRampCount=0,tRampStepSize=0;
    if((globalVar.rampTime.state == On) & (globalVar.rampTime.rampTime != 0)) {
        tRampTime = globalVar.rampTime.rampTime;
        tRampCount = tRampTime * 60 * 100;
    } else {
        tRampTime = 10; // seconds
        tRampCount = tRampTime * 100;
    }

    tRampState = 1;
    tRampStepSize = static_cast<float>(controlPressure * 100)/tRampCount;
//    tRampStepSize = tRampCount/controlPressure;

    pruMemory[eIPC_SETTINGS_RAMP_STATE] = tRampState;
    pruMemory[eIPC_SETTINGS_RAMP_MINUTE] = ((globalVar.rampTime.state == On)
                                            & (globalVar.rampTime.rampTime != 0))
                                            ? tRampTime : 0;
//    pruMemory[eIPC_SETTINGS_RAMP_MINUTE] = (globalVar.rampTime.state == On) ? tRampTime : 0;
    pruMemory[eIPC_SETTINGS_RAMP_TIME_COUNT] = tRampCount;
    pruMemory[eIPC_SETTINGS_RAMP_PRESSURE_STEP_SIZE] = tRampStepSize;

    // 1 Minutes Ramp 1 1 6000 11 1 1 6000 11
    // 2 Minutes Ramp 1 0 1000 70 1 10 1000 70

//    qDebug() << "Ramp" << pruMemory[eIPC_SETTINGS_RAMP_STATE] << pruMemory[eIPC_SETTINGS_RAMP_MINUTE]
//             << pruMemory[eIPC_SETTINGS_RAMP_TIME_COUNT] << pruMemory[eIPC_SETTINGS_RAMP_PRESSURE_STEP_SIZE]
//             << tRampState << tRampTime << tRampCount << tRampStepSize;

    int tSnoozeState=0,tSnoozeTime=0,tSnoozeCount=0;
    if(globalVar.snooze.state == On){
        if(globalVar.snooze.snoozeTime != 0){
            tSnoozeTime = globalVar.snooze.snoozeTime;
            tSnoozeState = 1;
            tSnoozeCount = tSnoozeTime * 60 * 100;
        }
    }
    pruMemory[eIPC_SETTINGS_SNOOZE_STATE] = tSnoozeState;
    pruMemory[eIPC_SETTINGS_SNOOZE_MINUTE] = tSnoozeTime;
    pruMemory[eIPC_SETTINGS_SNOOZE_TIME_COUNT] = tSnoozeCount;
//    qDebug() << "Snooze" << tSnoozeState << tSnoozeTime << tSnoozeCount;

    pruMemory[eIPC_SETTINGS_FLOW_IE_THRESHOLD_PERCENTAGE] = 25;
    //this should be 75%,according "Calculate current flow value is at 75% of maximum flow in this breath" in BLOWER_PRU0
//    pruMemory[eIPC_SETTINGS_FLOW_IE_THRESHOLD_PERCENTAGE] = 75;
    pruMemory[eIPC_SETTINGS_FLOW_EI_THRESHOLD] = globalVar.flow.threshold;//420;

    pruMemory[eIPC_EVENT_TYPE1] = 0;
    pruMemory[eIPC_EVENT_TYPE2] = 0;
    pruMemory[eIPC_EVENT_TYPE3] = 0;
    pruMemory[eIPC_EVENT_TYPE4] = 0;
    pruMemory[eIPC_EVENT_CHANGED] = 0;

    pruMemory[eIPC_THERAPY_IE_STATE] = STATE_MACHINE_INIT_INSP;
    pruMemory[eIPC_THERAPY_NEW_BREATH_DETECTED] = 0;
    pruMemory[eIPC_THERAPY_BREATH_TIME] = 0;
    pruMemory[eIPC_THERAPY_AMPLITUDE] = 0;
    pruMemory[eIPC_THERAPY_BREATH_COUNT] = 0;
    pruMemory[eIPC_THERAPY_STABLE_BREATH] = 0;
    pruMemory[eIPC_THERAPY_STABLE_BREATH_TIME] = 0;

    pruMemory[eIPC_BREATH_IE_TRANSITION_SAMPLES] = 0;
    pruMemory[eIPC_BREATH_EI_TRANSITION_SAMPLES] = 0;
    pruMemory[eIPC_BREATH_IE_COUNT] = 0;
    pruMemory[eIPC_BREATH_EI_COUNT] = 0;
    pruMemory[eIPC_BREATH_INSPIRATION_COUNT] = 0;
    pruMemory[eIPC_BREATH_EXPIRATION_COUNT] = 0;
    pruMemory[eIPC_BREATH_FLOW_MAX] = 0;
    pruMemory[eIPC_BREATH_FLOW_MIN] = 0;
//    pruMemory[eIPC_BREATH_FLOW_LEAK] = 0;
//    pruMemory[eIPC_BREATH_FLOW_LEAK] = pruMemory[eIPC_PARAMETER_TUNE_LEAK_SLOP_COUNT];

    pruMemory[eIPC_ERROR_DRV_IC] = 0;

    pruMemory[eIPC_DATA_LOG_COUNT] = 4;

    pruMemory[eIPC_THERAPY_APAP_CONTROL_ENABLE] = 0;
    pruMemory[eIPC_EVENT_HYPOAPNEA_COUNT] = 0;
    pruMemory[eIPC_THERAPY_START_TIME_COUNT] = 0;

    pruMemory[eIPC_THERAPY_STABLE_BREATH] = 0;
    pruMemory[eIPC_EVENT_APAP_CONTROL_STATE] = 0;
    pruMemory[eIPC_EVENT_HYPOAPNEA_COUNT] = 0;
    pruMemory[eIPC_THERAPY_APAP_CONTROL_TIME_COUNT] = 0;
    pruMemory[eIPC_THERAPY_START_TIME_COUNT] = 0;
    pruMemory[eIPC_THERAPY_APAP_APNEA2_TIMEOUT] = 0;

    int tRunningPeriod=0;
    if(tGotoSleepCount)          tRunningPeriod = eTHERAPY_PERIOD_GOTOSLEEP;
    else                         tRunningPeriod = eTHERAPY_PERIOD_RAMP_TIME;

//    qDebug() << "beforeStartTherapyProcedure()"
//                << pruMemory[eIPC_SETTINGS_SET_PRESSURE]
//                << controlPressure
//                << pruMemory[eIPC_SETTINGS_COMFORT_PRESSURE_STEP_SIZE]
//                << pruMemory[eIPC_SETTINGS_MODE]
//                << pruMemory[eIPC_SETTINGS_RAMP_PRESSURE_STEP_SIZE];

    pruMemory[eIPC_THERAPY_RUNNING_PERIOD] = tRunningPeriod;

    pruMemory[eIPC_THERAPY_RUNNING] = globalVar.therapyState;

    pruMemory[eIPC_SETTINGS_AUTOSTART_ENABLE] = globalVar.autoStartTherapy;
    pruMemory[eIPC_SETTINGS_AUTOSTART_FLOW_DETECT_INSP_THRESHOLD] = 40;
    pruMemory[eIPC_SETTINGS_AUTOSTART_FLOW_DETECT_EXP_THRESHOLD] = 40;
    pruMemory[eIPC_AUTOSTART_INSP_TRIG_COUNT] = 0;
    pruMemory[eIPC_AUTOSTART_EXP_TRIG_COUNT] = 0;
    pruMemory[eIPC_AUTOSTART_SPONTANEOUS_FLAG] = 0;
    pruMemory[eIPC_AUTOSTART_SPONTANEOUS_BREATH_COUNT] = 0;
    pruMemory[eIPC_AUTOSTART_SPONTANEOUS_TIMER_COUNT] = 0;
    pruMemory[eIPC_AUTOSTART_FLOW_TRIG_INSP_ENABLED] = 0;

    pruMemory[eIPC_EVENT_LEAK_TIME_COUNT] = 0;
    pruMemory[eIPC_EVENT_LEAK_STOP_TIME] = 10;

    drv8308_error = pruMemory[eIPC_ERROR_DRV_IC] = 0;
    mcp3204_error = pruMemory[eIPC_MCP3204_MEASUREMENT_INVALID_ERROR] = 0;
    mcp3202_error = pruMemory[eIPC_MCP3202_MEASUREMENT_INVALID_ERROR] = 0;
    flow_sensor_error = pruMemory[eIPC_FLOW_SENSOR_FAULT_ERROR] = 0;
    i2c1_bus_error = pruMemory[eIPC_I2C1_BUS_FAULT_ERROR] = 0;


    emit sendTunningParameterToPRU();

    pruMemory[eIPC_ARM_UPDATE_TO_PRU1] = 1;
    pruMemory[eIPC_ARM_UPDATE_TO_PRU0] = 1;

    pruMemory[eIPC_CURRENT_WINDOW_AVG_DATA] = 0;
    pruMemory[eIPC_REFERENCE_WINDOW_AVG_DATA] = 0;
}

void PruControlClass::beforeSnoozeProcedure(int state)
{
    if(state == 1)      pruMemory[eIPC_THERAPY_RUNNING_PERIOD] = eTHERAPY_PERIOD_SNOOZE_TIME;
    else                pruMemory[eIPC_THERAPY_RUNNING_PERIOD] = eTHERAPY_PERIOD_RAMP_TIME;
}

void PruControlClass::initPruControl(void)
{
    connect(this,SIGNAL(updateEventToDataLogger(uint,uint)),m_DataManager,SLOT(updateEventFromPru(uint,uint)));
    connect(this,SIGNAL(addParamToSpecificFiles(int*)),m_DataManager,SLOT(addParamToSpecificFiles(int*)));

    pruProcessorStartStopProcess(1,"BLOWER_PRU0.out",false);
    pruProcessorStartStopProcess(2,"BLOWER_PRU1.out",false);

    pruProcessorStartStopProcess(1,"BLOWER_PRU0.out",true);
    pruProcessorStartStopProcess(2,"BLOWER_PRU1.out",true);
}

void PruControlClass::startPruProcessing(void)

{
    ipcReadTimer = new QTimer;
    connect(ipcReadTimer, SIGNAL(timeout()), this, SLOT(ipcReadTimerTimeOutSlot()));

    int filehandle=0;

    filehandle = open("/dev/mem",O_RDWR | O_SYNC);

//    pruMemory = reinterpret_cast<int *>(mmap(0,0x3000,PROT_READ|PROT_WRITE,MAP_SHARED,filehandle,0x4a312000));
    pruMemory = reinterpret_cast<int *>(mmap(0,0x3000,PROT_READ|PROT_WRITE,MAP_SHARED,filehandle,0x4a310000));
    qDebug() << Q_FUNC_INFO << pruMemory << errno;
    if(pruMemory == MAP_FAILED){
        qDebug() << Q_FUNC_INFO << "error mapping" << pruMemory;
        return;
    }


//    QString lStr;
//    lStr.sprintf("\n PRUMEM: 0x%p",pruMemory);
//    Providers::pBackgroundScreen->writeToConsole(lStr);
    qDebug() << Q_FUNC_INFO << "PRUMEM:  0x" << hex << pruMemory;

    /* CALL AFTER POWER ON */
    powerOnUpdateSettings();

//    close(filehandle);
    ipcReadTimer->start(IPC_READ_TIMER_COUNT);

    pruMemory[eIPC_PRU0_INIT] = 0x55;
    pruMemory[eIPC_PRU1_INIT] = 0x55;
}

void PruControlClass::updateTherapyScreen(void)
{
    globalVar.therapyPeriod = static_cast<therapyPeriodParam>(pruMemory[eIPC_THERAPY_RUNNING_PERIOD]);

    int seconds=0;
    seconds = pruMemory[eIPC_SETTINGS_GOTOSLEEP_TIME_COUNT] / 100;
    globalVar.goToSleep.countMinutes = seconds / 60;
    globalVar.goToSleep.countSeconds = seconds % 60;

    seconds = pruMemory[eIPC_SETTINGS_RAMP_TIME_COUNT] / 100;
    globalVar.rampTime.countMinutes = seconds / 60;
    globalVar.rampTime.countSeconds = seconds % 60;

    seconds = pruMemory[eIPC_SETTINGS_SNOOZE_TIME_COUNT] / 100;
    globalVar.snooze.countMinutes = seconds / 60;
    globalVar.snooze.countSeconds = seconds % 60;

    if(globalVar.therapyPeriod == Therapy)
        globalVar.pressure.setPressure = pruMemory[eIPC_SETTINGS_TARGET_PRESSURE];
    else
        globalVar.pressure.setPressure = pruMemory[eIPC_SETTINGS_SET_PRESSURE];

//    if(globalVar.therapyPeriod == Therapy)
//        globalVar.pressure.setPressure = pruMemory[eIPC_SETTINGS_TARGET_PRESSURE]/100;
//    else
//        globalVar.pressure.setPressure = pruMemory[eIPC_SETTINGS_SET_PRESSURE]/100;

    emit processGotoSleepRampRuntime();
}

int PruControlClass::getSetPressureAsPerState(int tTherapyPeriod)
{
    switch(tTherapyPeriod)
    {
    case eTHERAPY_PERIOD_GOTOSLEEP:
        return pruMemory[eIPC_SETTINGS_SET_PRESSURE];
    case eTHERAPY_PERIOD_RAMP_TIME:
        return pruMemory[eIPC_SETTINGS_SET_PRESSURE];
    case eTHERAPY_PERIOD_SNOOZE_TIME:
        return pruMemory[eIPC_SETTINGS_SET_PRESSURE];
    case eTHERAPY_PERIOD_THERAPY:
        return pruMemory[eIPC_SETTINGS_TARGET_PRESSURE];
    }
return 0;
}

void PruControlClass::ipcReadTimerTimeOutSlot()
{
    if(pruMemory[eIPC_THERAPY_RUNNING] == 1)
    {
        unsigned int eventId1 = pruMemory[eIPC_EVENT_TYPE1];
        unsigned int eventId3 = pruMemory[eIPC_EVENT_TYPE3];
        emit updateEventToDataLogger(eventId1,eventId3);

        int tDataLogPacket[IPC_DATA_LOG_MAX_DATA];
        tDataLogPacket[IPC_DATA_LOG_LEAK] = pruMemory[eIPC_BREATH_FLOW_LEAK];
        tDataLogPacket[IPC_DATA_LOG_FLOW] = pruMemory[eIPC_DATA_LOG_FLOW_BREATH];
        tDataLogPacket[IPC_DATA_LOG_PRESSURE_MON] = pruMemory[eIPC_DATA_LOG_FLOW_EVENT];
        tDataLogPacket[IPC_DATA_LOG_PRESSURE_SET] = getSetPressureAsPerState(pruMemory[eIPC_THERAPY_RUNNING_PERIOD]);

//        tDataLogPacket[IPC_DATA_LOG_EVENT_FLOW_FILTERED] = pruMemory[eIPC_BREATH_FLOW_EVENT_DETECTION] - pruMemory[eIPC_BREATH_FLOW_LEAK];
//        tDataLogPacket[IPC_DATA_LOG_EVENT_FLOW_FILTERED_OFFSET] = pruMemory[eIPC_BREATH_FLOW_EVENT_DETECTION];

//        tDataLogPacket[IPC_DATA_LOG_FLOW] = pruMemory[eIPC_FLOW_ENG_DATA];
//        tDataLogPacket[IPC_DATA_LOG_FLOW_OFFSET] = pruMemory[eIPC_FLOW_ADC_COUNT];

        emit addParamToSpecificFiles(tDataLogPacket);

        /* Update data to GUI */
        if(globalVar.therapyState == On)
        {
            updateTherapyScreen();
        }
        else
        {
            // Possible if autostart therapy procedure successful update GUI once
            globalVar.therapyState = On;
            emit updateStartStopTherapyDetails();
            emit autoStartDetected();

            beforeStartTherapyProcedure();

            if(globalVar.therapyState)      globalVar.rgbColorMode = RGB_COLOR_BLOWER_RUNNING;
        }

        //TODO remove in production
        emit updateFlowParameter(pruMemory[eIPC_FLOW_ENG_DATA]);
        emit updateEventTypeStatus(pruMemory[eIPC_EVENT_TYPE1]);
        emit updateStableStatus(pruMemory[eIPC_EVENT_TYPE2]);
        emit updateMaskLeakStatus(pruMemory[eIPC_EVENT_TYPE3]);
        emit updateEnableApap(pruMemory[eIPC_THERAPY_APAP_CONTROL_ENABLE]);
        emit updateHypoApneaCount(pruMemory[eIPC_EVENT_HYPOAPNEA_COUNT]);
        emit updatebreathCount(pruMemory[eIPC_THERAPY_BREATH_COUNT]);
        emit updateLeakageCount(pruMemory[eIPC_BREATH_FLOW_LEAK]);
        emit updateCurrentWindowParameter(pruMemory[eIPC_CURRENT_WINDOW_AVG_DATA]);
        emit updateReferenceWindowParameter(pruMemory[eIPC_REFERENCE_WINDOW_AVG_DATA]);
    }
    else if(pruMemory[eIPC_SENSOR_DATA_UPDATED] == 1)
    {
        pruMemory[eIPC_SENSOR_DATA_UPDATED] = 0;
        uint64_t flowSerialNumber=0;
        int64_t serialNumberLsb=0,serialNumberMsb=0;
        serialNumberMsb = pruMemory[eIPC_FLOW_SENSOR_SERIAL_NO_MSB];
        serialNumberLsb = pruMemory[eIPC_FLOW_SENSOR_SERIAL_NO_LSB];
        flowSerialNumber = (serialNumberMsb << 32) | serialNumberLsb;
    }
    else if(pruMemory[eIPC_CALIBRATION_PRESSURE_OFFSET_UPDATED] == 1)
    {
        pruMemory[eIPC_CALIBRATION_PRESSURE_OFFSET_UPDATED] = 0;
        pruMemory[eIPC_CALIBRATION_PRESSURE_OFFSET] = pruMemory[eIPC_CALIBRATION_PRESSURE_OFFSET_AVERAGE] / pruMemory[eIPC_CALIBRATION_PRESSURE_OFFSET_COUNT];
        globalVar.pressure.pressureOffset = pruMemory[eIPC_CALIBRATION_PRESSURE_OFFSET];
        qDebug() << Q_FUNC_INFO << "P Offset" << globalVar.pressure.pressureOffset << pruMemory[eIPC_CALIBRATION_PRESSURE_OFFSET_AVERAGE] << pruMemory[eIPC_CALIBRATION_PRESSURE_OFFSET_COUNT];
        pruMemory[eIPC_CALIBRATION_PRESSURE_OFFSET_AVERAGE] = 0 ;
        pruMemory[eIPC_CALIBRATION_PRESSURE_OFFSET_COUNT] = 0;
        emit updatePressureSensorOffset(globalVar.pressure.pressureOffset);
    }
    else if(pruMemory[eIPC_MANUFACTURING_UPDATE_DATA] == 1)
    {
        pruMemory[eIPC_MANUFACTURING_UPDATE_DATA] = 0;
        unsigned int manufacturingArray[7];
        manufacturingArray[IPC_PRESSURE_RAW] = pruMemory[eIPC_MANUFACTURING_PRESSURE_ADC_COUNT] / pruMemory[eIPC_MANUFACTURING_UPDATE_COUNT];
        manufacturingArray[IPC_FLOW_RAW] = pruMemory[eIPC_MANUFACTURING_FLOW_ADC_COUNT] / pruMemory[eIPC_MANUFACTURING_UPDATE_COUNT];
        manufacturingArray[IPC_BLOWER_SPEED] = pruMemory[eIPC_MANUFACTURING_BLDC_SPEED_RAW_COUNT];
//        manufacturingArray[IPC_BLOWER_SPEED] = pruMemory[eIPC_MANUFACTURING_BLDC_SPEED_RAW_COUNT] / pruMemory[eIPC_MANUFACTURING_UPDATE_COUNT];
        manufacturingArray[IPC_MOTOR_TEMP_RAW] = pruMemory[eIPC_MANUFACTURING_MOTOR_TEMP_ADC_COUNT] / pruMemory[eIPC_MANUFACTURING_UPDATE_COUNT];
        manufacturingArray[IPC_VOLTAGE_IN_RAW] = pruMemory[eIPC_MANUFACTURING_VOLTAGE_INPUT_ADC_COUNT] / pruMemory[eIPC_MANUFACTURING_UPDATE_COUNT];
        manufacturingArray[IPC_BLDC_CURRENT_RAW] = pruMemory[eIPC_MANUFACTURING_BLDC_CURRENT_ADC_COUNT] / pruMemory[eIPC_MANUFACTURING_UPDATE_COUNT];

        pruMemory[eIPC_MANUFACTURING_FLOW_ADC_COUNT] = 0;
        pruMemory[eIPC_MANUFACTURING_PRESSURE_ADC_COUNT] = 0;
        pruMemory[eIPC_MANUFACTURING_VOLTAGE_INPUT_ADC_COUNT] = 0;
        pruMemory[eIPC_MANUFACTURING_BLDC_CURRENT_ADC_COUNT] = 0;
        pruMemory[eIPC_MANUFACTURING_MOTOR_TEMP_ADC_COUNT] = 0;
        pruMemory[eIPC_MANUFACTURING_BLDC_SPEED_RAW_COUNT] = 0;
        pruMemory[eIPC_MANUFACTURING_UPDATE_COUNT] = 0;
        emit updateScreenAsPerReceivedPacket(manufacturingArray);
    }
    else if((globalVar.therapyState == On) & (pruMemory[eIPC_THERAPY_RUNNING] == 0))
    {
        qDebug() << Q_FUNC_INFO << "Stopping Therapy;";

        // Stop therapy due to leakage process is true
        globalVar.therapyState = Off;
        emit updateStartStopTherapyDetails();
        beforeStartTherapyProcedure();
        globalVar.rgbColorMode = RGB_COLOR_DEVICE_IN_USE;
    }


    if((pruMemory[eIPC_ERROR_DRV_IC] != drv8308_error)
            | (pruMemory[eIPC_MCP3204_MEASUREMENT_INVALID_ERROR] != mcp3204_error)
            | (pruMemory[eIPC_MCP3202_MEASUREMENT_INVALID_ERROR] != mcp3202_error)
            | (pruMemory[eIPC_FLOW_SENSOR_FAULT_ERROR] != flow_sensor_error)
            | (pruMemory[eIPC_I2C1_BUS_FAULT_ERROR] != i2c1_bus_error))
    {
        drv8308_error = pruMemory[eIPC_ERROR_DRV_IC];
        mcp3204_error = pruMemory[eIPC_MCP3204_MEASUREMENT_INVALID_ERROR];
        mcp3202_error = pruMemory[eIPC_MCP3202_MEASUREMENT_INVALID_ERROR];
        flow_sensor_error = pruMemory[eIPC_FLOW_SENSOR_FAULT_ERROR];
        i2c1_bus_error = pruMemory[eIPC_I2C1_BUS_FAULT_ERROR];

//        qDebug() << Q_FUNC_INFO
//                 << drv8308_error << mcp3204_error << mcp3202_error
//                 << flow_sensor_error << i2c1_bus_error;

        /* Fault detected */
        parseFaultCodes();
    }
}

void PruControlClass::parseFaultCodes(void)
{
    int appErrorCode[23];
    int appErroIndex=0;

    if(pruMemory[eIPC_ERROR_DRV_IC])
    {
//        /* If blower IC Contains any error parse ic faults */
//        if(pruMemory[eIPC_ERROR_DRV_IC] & (1 << 0x00)){
//            appErrorCode[appErroIndex] = MOTOR_OVERCURRENT_ERROR; appErroIndex++;
//        }
//        if(pruMemory[eIPC_ERROR_DRV_IC] & (1 << 0x01)){
//            appErrorCode[appErroIndex] = CHARGE_PUMP_OVERCURRENT_ERROR; appErroIndex++;
//        }
//        if(pruMemory[eIPC_ERROR_DRV_IC] & (1 << 0x02)){
//            appErrorCode[appErroIndex] = OVERTEMP_SHUTDOWN_ERROR;   appErroIndex++;
//        }
//        if(pruMemory[eIPC_ERROR_DRV_IC] & (1 << 0x03)){
//            appErrorCode[appErroIndex] = VM_UNDERVOLTAGE_ERROR; appErroIndex++;
//        }
//        if(pruMemory[eIPC_ERROR_DRV_IC] & (1 << 0x04)){
//            appErrorCode[appErroIndex] = CHARGEPUMP_UNDERVOLTAGE_ERROR; appErroIndex++;
//        }
//        if(pruMemory[eIPC_ERROR_DRV_IC] & (1 << 0x05)){
//            appErrorCode[appErroIndex] = VM_OVERVOLTAGE_ERROR; appErroIndex++;
//        }
        if(pruMemory[eIPC_ERROR_DRV_IC] && (1 << 0x06))
        {
            appErrorCode[appErroIndex] = ROTOR_LOCK_CONDITION_ERROR; appErroIndex++;
        }
    }
//    if(pruMemory[eIPC_MCP3204_MEASUREMENT_INVALID_ERROR])
//    {
//        appErrorCode[appErroIndex] = MCP3204_MEASUREMENT_INVALID_ERROR; appErroIndex++;
//    }
//    if(pruMemory[eIPC_MCP3202_MEASUREMENT_INVALID_ERROR])
//    {
//        appErrorCode[appErroIndex] = MCP3202_MEASUREMENT_INVALID_ERROR; appErroIndex++;
//    }
//    if(pruMemory[eIPC_FLOW_SENSOR_FAULT_ERROR])
//    {
//        appErrorCode[appErroIndex] = FLOW_SENSOR_FAULT_ERROR; appErroIndex++;
//    }
//    if(pruMemory[eIPC_I2C1_BUS_FAULT_ERROR])
//    {
//        appErrorCode[appErroIndex] = I2C1_BUS_FAULT_ERROR; appErroIndex++;
//    }

    pruMemory[eIPC_ERROR_DRV_IC] = 0;
    pruMemory[eIPC_MCP3204_MEASUREMENT_INVALID_ERROR] = 0;
    pruMemory[eIPC_MCP3202_MEASUREMENT_INVALID_ERROR] = 0;
    pruMemory[eIPC_FLOW_SENSOR_FAULT_ERROR] = 0;
    pruMemory[eIPC_I2C1_BUS_FAULT_ERROR] = 0;


//    qDebug() << Q_FUNC_INFO << appErroIndex << appErrorCode[0] << appErrorCode[1] << pruMemory[eIPC_ERROR_DRV_IC];
    if(appErroIndex)
    {
        emit updateAndShowScreen(appErrorCode,appErroIndex);
    }
}

void PruControlClass::pruProcessorStartStopProcess(int pruNo,const QString & programmFileStr,bool processorState)
{
    QString pruStr = "/sys/class/remoteproc/remoteproc" + QString::number(pruNo);

    if(processorState)
    {
        QString firmwareStr = pruStr + "/firmware" ;
        QFile pruFirmware(firmwareStr);
        if(pruFirmware.exists()) {
            pruFirmware.open(QIODevice::WriteOnly);
            pruFirmware.write(programmFileStr.toLocal8Bit());
            pruFirmware.close();
        }
    }

    QString stateStr = pruStr + "/state" ;
    QFile remoteProcessor(stateStr);
    if(remoteProcessor.exists())
    {
        remoteProcessor.open(QIODevice::WriteOnly);

        if(processorState)
            remoteProcessor.write("start");
        else
            remoteProcessor.write("stop");

        remoteProcessor.close();
    }
}
