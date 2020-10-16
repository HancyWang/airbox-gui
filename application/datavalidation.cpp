#include "ex_variables.h"
#include "datavalidation.h"
#include "global.h"



DataValidation::DataValidation(QObject * parent)
    : QObject(parent)
{
    updateMinMaxOtherVariables();

    eeprom = new QFile("/sys/bus/i2c/devices/0-0050/eeprom");

    memset(eepromData,0,sizeof eepromData);

    QFileInfo eepromCheck(*eeprom);

    //TODO Add bluetooth paired device names & total Number

//    eraseParameterBlock();
//    factoryDefaultVariables();
//    writeParameterToEeprom();

    if(eeprom->exists() && eepromCheck.isFile())
    {
        readParameterFromEeprom();
        readDeviceInformationFromEeprom();
        readDeviceLifeDataFromEeprom();

        if(isDataValid == false)
            readParameterFromEeprom();

        updateParameters();
    }
    else
    {
        qDebug() << "File Not valid." ;
        factoryDefaultVariables();
//        this->writeParameterToEeprom();
    }
}

DataValidation::~DataValidation()
{

}

void DataValidation::readTunningParameterFromEeprom(void)
{
    if(!eeprom->open(QIODevice::ReadWrite | QIODevice::Text))       return;

    QTextStream in(eeprom);
    QString parameterRead;
    in.seek(TUNE_PARAMETER_OFFSET);
    parameterRead = in.read(TUNE_PARAMETER_LENGTH);

    qDebug() << Q_FUNC_INFO << "EEPROM:" << parameterRead;

    parseUpdateTunningEepromData(parameterRead);

    if(eeprom->isOpen())        eeprom->close();
}

void DataValidation::eraseTunningParameterBlock(void)
{
    if(!eeprom->isOpen()){
        if(!eeprom->open(QIODevice::ReadWrite))       return;
    }

    QTextStream erase(eeprom);
    QString data;

    // Set Data to FF
    data.fill('F',TUNE_PARAMETER_LENGTH);

    // Seek To data position
    erase.seek(TUNE_PARAMETER_OFFSET);
    erase << data;

    if(eeprom->isOpen())        eeprom->close();
}

void DataValidation::parseUpdateTunningEepromData(const QString & str)
{
QStringList tuneParameterList;
int tuneListItems=0;

    tuneParameterList.clear();
    tuneParameterList = str.split('/');

    tuneListItems = tuneParameterList.count();
    tuneListItems--;        // remove data after last slash

//    qDebug() << Q_FUNC_INFO
//             << "Items" << tuneListItems
//             << "Str" << str
//             << "Max Tune" << TUNE_MAX_CHANGE_PARAM;

//    Providers::pBackgroundScreen->writeToConsole(QString("\n Tune :--> %1 : %2 : %3").arg(tuneListItems).arg(TUNE_MAX_CHANGE_PARAM).arg(str));

    if(tuneListItems != TUNE_MAX_CHANGE_PARAM)
    {
        qDebug() << Q_FUNC_INFO << tuneListItems << TUNE_MAX_CHANGE_PARAM;
        emit restoreDefaultTunningParameters();
//        int defaultTuneData[TUNE_MAX_CHANGE_PARAM];
//        Providers::pBackgroundScreen->parameterTuneScreen->getDefaultTunningParameters(defaultTuneData);
//        eraseTunningParameterBlock();
//        writeTuneParameterToEeprom(defaultTuneData);
    }
    else
        emit updateTunningParametersFromEeprom(tuneParameterList);
}

void DataValidation::writeTuneParameterToEeprom(int * tuneParam)
{
    eraseTunningParameterBlock();

    if(!eeprom->isOpen()){
        if(!eeprom->open(QIODevice::ReadWrite | QIODevice::Text))       return;
    }

    QTextStream out(eeprom);

    int localData[TUNE_MAX_CHANGE_PARAM];
    memcpy(localData,tuneParam,sizeof(localData));

    // Add Separator line
    QString parameterStr;
    int j=0;
    for(j=0 ; j<TUNE_MAX_CHANGE_PARAM ; j++)
    {
        if(j == 0)      parameterStr += QString::number(localData[j]);
        else            parameterStr += "/" + QString::number(localData[j]);
    }

    // Add Last parameter separator
    parameterStr += "/" ;

    qDebug() << Q_FUNC_INFO << parameterStr << parameterStr.length();

    out.seek(TUNE_PARAMETER_OFFSET);
    out << parameterStr;

    if(eeprom->isOpen())        eeprom->close();
}

void DataValidation::readDeviceInformationFromEeprom(void)
{
    if(!eeprom->open(QIODevice::ReadWrite | QIODevice::Text))       return;

    QTextStream in(eeprom);
    QString deviceInformationRead;
    in.seek(DEVICE_INFORMATION);
    deviceInformationRead = in.read(DEVICE_INFORMATION_LENGTH);

    globalVar.serialNumberStr.clear();
    globalVar.serialNumberStr = QString(deviceInformationRead);

    if(eeprom->isOpen())        eeprom->close();
}

void DataValidation::eraseDeviceInformationBlock(void)
{
    if(!eeprom->isOpen()){
        if(!eeprom->open(QIODevice::ReadWrite))       return;
    }
    QTextStream erase(eeprom);
    QString data;

    // Set Data to FF
    data.fill('F',DEVICE_INFORMATION_LENGTH);

    // Seek To data position
    erase.seek(DEVICE_INFORMATION);
    erase << data;

    eeprom->close();
}

void DataValidation::writeDeviceInformationToEeprom(void)
{
    eraseDeviceInformationBlock();

    if(!eeprom->isOpen()){
        if(!eeprom->open(QIODevice::ReadWrite | QIODevice::Text))       return;
    }

    QTextStream out(eeprom);
    qDebug() << globalVar.serialNumberStr;
    out.seek(DEVICE_INFORMATION);
    out << globalVar.serialNumberStr;

    eeprom->close();
}


void DataValidation::readDeviceLifeDataFromEeprom(void)
{
    if(!eeprom->open(QIODevice::ReadWrite | QIODevice::Text))       return;

    QTextStream in(eeprom);
    QString deviceLifeDataRead;
    in.seek(DEVICE_LIFE_DATA_OFFSET);
    deviceLifeDataRead = in.read(DEVICE_LIFE_DATA_LENGTH);

    QStringList listData = deviceLifeDataRead.split('/');

//    qDebug() << "##---------->" << listData;
    globalVar.deviceLifeData.totalMinutesOfFlowGeneration = listData.at(0).toUInt();
    globalVar.deviceLifeData.totalHoursFlowGeneration = globalVar.deviceLifeData.totalMinutesOfFlowGeneration / 60;

//    qDebug() << globalVar.deviceLifeData.totalMinutesOfFlowGeneration << globalVar.deviceLifeData.totalHoursFlowGeneration;

    if(eeprom->isOpen())        eeprom->close();
}

void DataValidation::eraseDeviceLifeDataBlock(void)
{
    if(!eeprom->isOpen()){
        if(!eeprom->open(QIODevice::ReadWrite))       return;
    }
    QTextStream erase(eeprom);
    QString data;

    // Set Data to FF
    data.fill('F',DEVICE_LIFE_DATA_LENGTH);

    // Seek To data position
    erase.seek(DEVICE_LIFE_DATA_OFFSET);
    erase << data;

    eeprom->close();
}

void DataValidation::writeDeviceLifeDataToEeprom(void)
{
    eraseDeviceLifeDataBlock();

    if(!eeprom->isOpen()){
        if(!eeprom->open(QIODevice::ReadWrite | QIODevice::Text))       return;
    }

    QTextStream out(eeprom);

    QString localStr = QString("%1/").arg(globalVar.deviceLifeData.totalMinutesOfFlowGeneration);

    out.seek(DEVICE_LIFE_DATA_OFFSET);
    out << localStr;

    eeprom->close();
}

void DataValidation::readParameterFromEeprom(void)
{
    if(!eeprom->open(QIODevice::ReadWrite | QIODevice::Text))       return;

    QTextStream in(eeprom);
    QString parameterRead;
    in.seek(DEVICE_DATA_OFFSET);
    parameterRead = in.read(EEPROM_PARAMETER_LENGTH);

    qDebug() << Q_FUNC_INFO << "EEPROM:" << parameterRead;

    parseUpdateEepromData(parameterRead);

    if(eeprom->isOpen())        eeprom->close();
}

void DataValidation::eraseParameterBlock(void)
{
    if(!eeprom->isOpen()){
        if(!eeprom->open(QIODevice::ReadWrite))       return;
    }
    QTextStream erase(eeprom);
    QString data;

    // Set Data to FF
    data.fill('F',EEPROM_PARAMETER_LENGTH);

    // Seek To data position
    erase.seek(DEVICE_DATA_OFFSET);
    erase << data;

    eeprom->close();
}

void DataValidation::parseUpdateEepromData(const QString & str)
{
//QStringList parameterList;
//int listItems;

    parameterList.clear();
    parameterList = str.split('/');

    listItems = 0;
    listItems = parameterList.count();
    listItems--;        // remove data after last slash
    qDebug() << Q_FUNC_INFO << "Items:" << listItems << "Max Count" << CRC_CHECKSUM_CALCULATED;

    if(listItems != (CRC_CHECKSUM_CALCULATED + 1))
    {
        qDebug() << "EEPROM Data mismatch";
//        eraseParameterBlock();
        factoryDefaultVariables();
        writeParameterToEeprom();
        isDataValid = false;
    }
    else
    {
        isDataValid = true;
    }
}

void DataValidation::updateParameters(void)
{

    if(listItems == (CRC_CHECKSUM_CALCULATED + 1))
    {
        globalVar.pressure.targetedPressure     = parameterList.at(TARGET_PRESSURE).toInt();
        globalVar.airFilter                     = static_cast<airFilterParam>(parameterList.at(AIR_FILTER_TYPE).toInt());
        globalVar.pressureUnit                  = static_cast<pressureUnitTypeParam>(parameterList.at(PRESSURE_UNIT).toInt());
        globalVar.pressure.pressureOffset       = parameterList.at(PRESSURE_OFFSET).toInt();
        globalVar.flow.threshold            = parameterList.at(FLOW_SLOP).toInt();
        globalVar.goToSleep.goToSleepTime       = parameterList.at(GO_TO_SLEEP_TIME).toInt();
        globalVar.goToSleep.state               = static_cast<OnOff>(parameterList.at(GO_TO_SLEEP_STATE).toInt());
        globalVar.rampTime.rampTime             = parameterList.at(RAMP_TIME).toInt();
        globalVar.rampTime.state                = static_cast<OnOff>(parameterList.at(RAMP_STATE).toInt());
        globalVar.displaySettings.autoBrightnessAdjustment = static_cast<OnOff>(parameterList.at(BRIGTNESS_CONTROL_STATE).toInt());
        globalVar.displaySettings.displayDimDuration = parameterList.at(DISPLAY_DIM_DURATION).toInt();
        globalVar.displaySettings.brightnessLevel = parameterList.at(BRIGHTNESS_LEVEL).toInt();
        globalVar.autoTherapy                   = static_cast<OnOff>(parameterList.at(AUTO_THERAPY).toInt());
        globalVar.autoStartTherapy              = static_cast<OnOff>(parameterList.at(AUTO_START_THERAPY).toInt());
//        globalVar.sleepTitrationMode            = static_cast<OnOff>(parameterList.at(BLUETOOTH_STATE).toInt());
        globalVar.bluetooth.state               = static_cast<OnOff>(parameterList.at(BLUETOOTH_STATE).toInt());
        globalVar.powerSavings                  = static_cast<OnOff>(parameterList.at(POWER_SAVINGS).toInt());
        globalVar.snooze.snoozeTime             = parameterList.at(SNOOZE_TIME).toInt();
        globalVar.sendSleepReportDuration       = static_cast<sendSleepReportParam>(parameterList.at(SEND_SLEEP_REPORT_DURATION).toInt());
        globalVar.comfortLevel.state            = static_cast<OnOff>(parameterList.at(COMFORT_LEVEL_STATE).toInt());
        globalVar.comfortLevel.comfortLevelSet  = static_cast<comfortLevelType>(parameterList.at(COMFORT_LEVEL).toInt());
        globalVar.maskFitTest.maskFitTestStatus = static_cast<maskFitParam>(parameterList.at(MASK_FIT_TEST).toInt());
//        globalVar.deviceLifeData.totalMinutesOfFlowGeneration = parameterList.at(HOURS_OF_FLOW_GENERATION).toUInt();
//        globalVar.deviceLifeData.totalHoursFlowGeneration = parameterList.at(HOURS_OF_FLOW_GENERATION).toInt();
        globalVar.snooze.state                  = static_cast<OnOff>(parameterList.at(SNOOZE_STATE).toInt());
        globalVar.goToSleep.Auto                = static_cast<OnOff>(parameterList.at(GO_TO_SLEEP_AUTO).toInt());
        globalVar.rampTime.Auto                 = static_cast<OnOff>(parameterList.at(RAMP_TIME_AUTO).toInt());
        globalVar.therapyMode                   = static_cast<therapyModeParam>(parameterList.at(THERAPY_MODE).toInt());
        globalVar.maskType                      = static_cast<maskTypeParam>(parameterList.at(MASK_TYPE).toInt());
        globalVar.pressure.apapMinPressure          = parameterList.at(SET_MIN_PRESSURE).toInt();
        globalVar.pressure.apapMaxPressure          = parameterList.at(SET_MAX_PRESSURE).toInt();

        globalVar.reminder.airFilter.state = static_cast<OnOff>(parameterList.at(AIRFILTER_CHANGE_STATE).toInt());
        globalVar.reminder.airFilter.changeDuration = parameterList.at(AIRFILTER_CHANGE_DURATION).toInt();
        globalVar.reminder.airFilter.setStartDate.date = parameterList.at(AIRFILTER_CHANGE_DATE).toInt();
        globalVar.reminder.airFilter.setStartDate.month = parameterList.at(AIRFILTER_CHANGE_MONTH).toInt();
        globalVar.reminder.airFilter.setStartDate.year = parameterList.at(AIRFILTER_CHANGE_YEAR).toInt();

        globalVar.reminder.airTube.state = static_cast<OnOff>(parameterList.at(AIRTUBE_CHANGE_STATE).toInt());
        globalVar.reminder.airTube.changeDuration = parameterList.at(AIRTUBE_CHANGE_DURATION).toInt();
        globalVar.reminder.airTube.setStartDate.date = parameterList.at(AIRTUBE_CHANGE_DATE).toInt();
        globalVar.reminder.airTube.setStartDate.month = parameterList.at(AIRTUBE_CHANGE_MONTH).toInt();
        globalVar.reminder.airTube.setStartDate.year = parameterList.at(AIRTUBE_CHANGE_YEAR).toInt();

        globalVar.reminder.mask.state = static_cast<OnOff>(parameterList.at(MASK_CHANGE_STATE).toInt());
        globalVar.reminder.mask.changeDuration = parameterList.at(MASK_CHANGE_DURATION).toInt();
        globalVar.reminder.mask.setStartDate.date = parameterList.at(MASK_CHANGE_DATE).toInt();
        globalVar.reminder.mask.setStartDate.month = parameterList.at(MASK_CHANGE_MONTH).toInt();
        globalVar.reminder.mask.setStartDate.year = parameterList.at(MASK_CHANGE_YEAR).toInt();

        globalVar.diagnosticData                = static_cast<OnOff>(parameterList.at(DIAGNOSTIC_DATA).toInt());
        globalVar.language                      = static_cast<languageParam>(parameterList.at(LANGUAGE).toInt());

        // Read CRC
        readChecksum = parameterList.at(CRC_CHECKSUM_CALCULATED).toUInt();

//        globalVar.deviceLifeData.totalHoursFlowGeneration = globalVar.deviceLifeData.totalMinutesOfFlowGeneration / 60;

        int i=0;
        unsigned int crcChecksum=0;
        for(i=0 ; i <CRC_CHECKSUM_CALCULATED ; i++)
        {
            crcChecksum += parameterList.at(i).toUInt();
        }

        if(readChecksum == crcChecksum){
//            qDebug() << "CRC" << readChecksum << crcChecksum;
            isDataValid = true;
        }
    }
    else
    {
        isDataValid = false;
    }

    // If Data is not valid then restore to factory defaults
    if(isDataValid == false)
    {
        // Restore to factory default variables
        factoryDefaultVariables();
        writeParameterToEeprom();
    }
}

bool DataValidation::validateDataRead(void)
{
    if((globalVar.pressure.targetedPressure < TARGET_PRESSURE_MIN) | (globalVar.pressure.targetedPressure > TARGET_PRESSURE_MAX)){
        return false;
    }
    if((globalVar.airFilter < AIR_FILTER_TYPE_MIN) | (globalVar.airFilter > AIR_FILTER_TYPE_MAX)){
        return false;
    }
    if((globalVar.pressureUnit < PRESSURE_UNIT_MIN) | (globalVar.pressureUnit > PRESSURE_UNIT_MAX)){
        return false;
    }
    if((globalVar.pressure.pressureOffset < PRESSURE_OFFSET_MIN) | (globalVar.pressure.pressureOffset > PRESSURE_OFFSET_MAX)){
        return false;
    }
    if((globalVar.flow.threshold < FLOW_SLOP_MIN) | (globalVar.flow.threshold > FLOW_SLOP_MAX)){
        return false;
    }
    if((globalVar.goToSleep.goToSleepTime < GO_TO_SLEEP_TIME_MIN) | (globalVar.goToSleep.goToSleepTime > GO_TO_SLEEP_TIME_MAX)){
        return false;
    }
    if((globalVar.rampTime.rampTime < RAMP_TIME_MIN) | (globalVar.rampTime.rampTime > RAMP_TIME_MAX)){
        return false;
    }
    if((globalVar.displaySettings.displayDimDuration < DISPLAY_DIM_DURATION_MIN) | (globalVar.displaySettings.displayDimDuration > DISPLAY_DIM_DURATION_MAX)){
        return false;
    }
    if((globalVar.comfortLevel.state != On) & (globalVar.comfortLevel.state != Off)){
        return false;
    }
    if((globalVar.comfortLevel.comfortLevelSet < COMFORT_LEVEL_1) | (globalVar.comfortLevel.comfortLevelSet > COMFORT_LEVEL_3)){
        return false;
    }
    if((globalVar.displaySettings.brightnessLevel < BRIGHTNESS_LEVEL_MIN) | (globalVar.displaySettings.brightnessLevel > BRIGHTNESS_LEVEL_MAX)){
        return false;
    }
    if((globalVar.snooze.snoozeTime < SNOOZE_TIME_MIN) | (globalVar.snooze.snoozeTime > SNOOZE_TIME_MAX)){
        return false;
    }
//    if(globalVar.deviceLifeData.totalHoursFlowGeneration < 0){
//        return false;
//    }
    if((globalVar.rampTime.state != On) & (globalVar.rampTime.state != Off)){
        return false;
    }
    if((globalVar.goToSleep.state != On) & (globalVar.goToSleep.state != Off)){
        return false;
    }
    if((globalVar.displaySettings.autoBrightnessAdjustment != On) & (globalVar.displaySettings.autoBrightnessAdjustment != Off)){
        return false;
    }
    if((globalVar.autoTherapy != On) & (globalVar.autoTherapy != Off)){
        return false;
    }
    if((globalVar.autoStartTherapy != On) & (globalVar.autoStartTherapy != Off)){
        return false;
    }
    if((globalVar.sleepTitrationMode != On) & (globalVar.sleepTitrationMode != Off)){
        return false;
    }
    if((globalVar.powerSavings != On) & (globalVar.powerSavings != Off)){
        return false;
    }
    if((globalVar.snooze.state != On) & (globalVar.snooze.state != Off)){
        return false;
    }
    if((globalVar.goToSleep.Auto != On) & (globalVar.goToSleep.Auto != Off)){
        return false;
    }
    if((globalVar.rampTime.Auto != On) & (globalVar.rampTime.Auto != Off)){
        return false;
    }
    if((globalVar.reminder.airFilter.state != On) & (globalVar.reminder.airFilter.state != Off)){
        return false;
    }
    if((globalVar.reminder.airFilter.changeDuration < REM_AIRFILTER_DURATION_MIN) | (globalVar.reminder.airFilter.changeDuration > REM_AIRFILTER_DURATION_MAX)){
        return false;
    }
    if((globalVar.therapyMode != cpapMode) & (globalVar.therapyMode != apapMode)){
        return false;
    }
    if((globalVar.maskType != nasalPillow) & (globalVar.maskType != nasalMask)){
        return false;
    }
    if((globalVar.pressure.apapMinPressure < TARGET_PRESSURE_MIN) | (globalVar.pressure.apapMinPressure > TARGET_PRESSURE_MAX)){
        return false;
    }
    if((globalVar.pressure.apapMaxPressure < TARGET_PRESSURE_MIN) | (globalVar.pressure.apapMaxPressure > TARGET_PRESSURE_MAX)){
        return false;
    }

    if(globalVar.reminder.airFilter.setStartDate.date < 0)      return false;
    if(globalVar.reminder.airFilter.setStartDate.month < 0)     return false;
    if(globalVar.reminder.airFilter.setStartDate.year < 0)      return false;

    if((globalVar.reminder.airTube.state != On) & (globalVar.reminder.airTube.state != Off)){
        return false;
    }
    if((globalVar.reminder.airTube.changeDuration < REM_AIRTUBE_DURATION_MIN) | (globalVar.reminder.airTube.changeDuration > REM_AIRTUBE_DURATION_MAX)){
        return false;
    }
    if(globalVar.reminder.airTube.setStartDate.date < 0)      return false;
    if(globalVar.reminder.airTube.setStartDate.month < 0)     return false;
    if(globalVar.reminder.airTube.setStartDate.year < 0)      return false;

    if((globalVar.reminder.mask.state != On) & (globalVar.reminder.mask.state != Off)){
        return false;
    }
    if((globalVar.reminder.mask.changeDuration < REM_MASK_DURATION_MIN) | (globalVar.reminder.mask.changeDuration > REM_MASK_DURATION_MAX)){
        return false;
    }
    if(globalVar.reminder.mask.setStartDate.date < 0)      return false;
    if(globalVar.reminder.mask.setStartDate.month < 0)     return false;
    if(globalVar.reminder.mask.setStartDate.year < 0)      return false;

    unsigned int crcChecksum = globalVar.pressure.targetedPressure + globalVar.airFilter +
                                globalVar.pressureUnit + globalVar.pressure.pressureOffset +
                                globalVar.flow.threshold +
                                globalVar.goToSleep.goToSleepTime + globalVar.goToSleep.state + globalVar.rampTime.rampTime +
                                globalVar.rampTime.state + globalVar.displaySettings.autoBrightnessAdjustment + globalVar.displaySettings.displayDimDuration +
                                globalVar.displaySettings.brightnessLevel + globalVar.autoTherapy + globalVar.autoStartTherapy +
                                globalVar.sleepTitrationMode + globalVar.powerSavings + globalVar.snooze.snoozeTime +
                                globalVar.comfortLevel.state + globalVar.comfortLevel.comfortLevelSet + globalVar.maskFitTest.maskFitTestStatus + static_cast<unsigned int>(globalVar.deviceLifeData.totalHoursFlowGeneration) +
                                globalVar.snooze.state + globalVar.goToSleep.Auto + globalVar.rampTime.Auto +
                                globalVar.therapyMode + globalVar.maskType +
                                globalVar.pressure.apapMinPressure + globalVar.pressure.apapMaxPressure +
                                globalVar.reminder.airFilter.state + globalVar.reminder.airFilter.changeDuration + globalVar.reminder.airFilter.setStartDate.date +
                                globalVar.reminder.airFilter.setStartDate.month + globalVar.reminder.airFilter.setStartDate.year +
                                globalVar.reminder.airTube.state + globalVar.reminder.airTube.changeDuration + globalVar.reminder.airTube.setStartDate.date +
                                globalVar.reminder.airTube.setStartDate.month + globalVar.reminder.airTube.setStartDate.year +
                                globalVar.reminder.mask.state + globalVar.reminder.mask.changeDuration + globalVar.reminder.mask.setStartDate.date +
                                globalVar.reminder.mask.setStartDate.month + globalVar.reminder.mask.setStartDate.year;


    if(((unsigned int)readChecksum) != ((unsigned int)crcChecksum)){
        qDebug() << "validateDataRead" << "CRC Read:" << readChecksum << "CRC Cal:" << crcChecksum;
        return false;
    }

return true;
}

void DataValidation::writeParameterToEeprom(void)
{
    eraseParameterBlock();

    if(!eeprom->isOpen()){
        if(!eeprom->open(QIODevice::ReadWrite | QIODevice::Text))       return;
    }

    QTextStream out(eeprom);

    eepromData[TARGET_PRESSURE] = globalVar.pressure.targetedPressure;
    eepromData[AIR_FILTER_TYPE] = globalVar.airFilter;
    eepromData[PRESSURE_UNIT] = globalVar.pressureUnit;
    eepromData[PRESSURE_OFFSET] = globalVar.pressure.pressureOffset;
    eepromData[FLOW_SLOP] = globalVar.flow.threshold;
    eepromData[GO_TO_SLEEP_TIME] = globalVar.goToSleep.goToSleepTime;
    eepromData[GO_TO_SLEEP_STATE] = globalVar.goToSleep.state;
    eepromData[GO_TO_SLEEP_AUTO] = globalVar.goToSleep.Auto;
    eepromData[RAMP_TIME_AUTO] = globalVar.rampTime.Auto;
    eepromData[RAMP_TIME] = globalVar.rampTime.rampTime;
    eepromData[RAMP_STATE] = globalVar.rampTime.state;
    eepromData[BRIGTNESS_CONTROL_STATE] = globalVar.displaySettings.autoBrightnessAdjustment;
    eepromData[DISPLAY_DIM_DURATION] = globalVar.displaySettings.displayDimDuration;
    eepromData[BRIGHTNESS_LEVEL] = globalVar.displaySettings.brightnessLevel;
    eepromData[AUTO_THERAPY] = globalVar.autoTherapy;
    eepromData[AUTO_START_THERAPY] = globalVar.autoStartTherapy;
    eepromData[BLUETOOTH_STATE] = globalVar.bluetooth.state; //globalVar.sleepTitrationMode;
    eepromData[POWER_SAVINGS] = globalVar.powerSavings;
    eepromData[SNOOZE_TIME] = globalVar.snooze.snoozeTime;
    eepromData[SEND_SLEEP_REPORT_DURATION] = globalVar.sendSleepReportDuration;
    eepromData[COMFORT_LEVEL_STATE] = globalVar.comfortLevel.state;
    eepromData[COMFORT_LEVEL] = globalVar.comfortLevel.comfortLevelSet;
    eepromData[MASK_FIT_TEST] = globalVar.maskFitTest.maskFitTestStatus;
    eepromData[SNOOZE_STATE] = globalVar.snooze.state;
//    eepromData[HOURS_OF_FLOW_GENERATION] = static_cast<int>(globalVar.deviceLifeData.totalMinutesOfFlowGeneration);
    eepromData[THERAPY_MODE] = globalVar.therapyMode;
    eepromData[MASK_TYPE] = globalVar.maskType;
    eepromData[SET_MIN_PRESSURE] = globalVar.pressure.apapMinPressure;
    eepromData[SET_MAX_PRESSURE] = globalVar.pressure.apapMaxPressure;

    eepromData[AIRFILTER_CHANGE_STATE] = globalVar.reminder.airFilter.state;
    eepromData[AIRFILTER_CHANGE_DURATION] = globalVar.reminder.airFilter.changeDuration;
    eepromData[AIRFILTER_CHANGE_DATE] = globalVar.reminder.airFilter.setStartDate.date;
    eepromData[AIRFILTER_CHANGE_MONTH] = globalVar.reminder.airFilter.setStartDate.month;
    eepromData[AIRFILTER_CHANGE_YEAR] = globalVar.reminder.airFilter.setStartDate.year;

    eepromData[AIRTUBE_CHANGE_STATE] = globalVar.reminder.airTube.state;
    eepromData[AIRTUBE_CHANGE_DURATION] = globalVar.reminder.airTube.changeDuration;
    eepromData[AIRTUBE_CHANGE_DATE] = globalVar.reminder.airTube.setStartDate.date;
    eepromData[AIRTUBE_CHANGE_MONTH] = globalVar.reminder.airTube.setStartDate.month;
    eepromData[AIRTUBE_CHANGE_YEAR] = globalVar.reminder.airTube.setStartDate.year;

    eepromData[MASK_CHANGE_STATE] = globalVar.reminder.mask.state;
    eepromData[MASK_CHANGE_DURATION] = globalVar.reminder.mask.changeDuration;
    eepromData[MASK_CHANGE_DATE] = globalVar.reminder.mask.setStartDate.date;
    eepromData[MASK_CHANGE_MONTH] = globalVar.reminder.mask.setStartDate.month;
    eepromData[MASK_CHANGE_YEAR] = globalVar.reminder.mask.setStartDate.year;

    eepromData[DIAGNOSTIC_DATA] = globalVar.diagnosticData;
    eepromData[LANGUAGE] = globalVar.language;

    // Calculate Checksum
    int i=0;
    eepromData[CRC_CHECKSUM_CALCULATED] = 0;
    for(i=0 ; i<CRC_CHECKSUM_CALCULATED ; i++)
    {
        eepromData[CRC_CHECKSUM_CALCULATED] += eepromData[i];
    }

    // Add Separator line
    QString parameterStr;
    parameterStr.clear();

    for(int j=0 ; j<=CRC_CHECKSUM_CALCULATED ; j++)
    {
        if(j == 0)      parameterStr += QString::number(eepromData[j]);
        else            parameterStr += "/" + QString::number(eepromData[j]);
    }

    // Add Last parameter separator
    parameterStr += "/" ;

    qDebug() << "writeParameterToEeprom" << parameterStr;
    qDebug() << "CRC" << eepromData[CRC_CHECKSUM_CALCULATED] << "at" << i;

    out.seek(DEVICE_DATA_OFFSET);
    out << parameterStr;

    eeprom->close();
}


/*
 * Factory Default Values for each parameters
 *
 */
void DataValidation::factoryDefaultVariables(void)
{
    qDebug() << "Factory Default Variables";

    globalVar.clinicalMode = Off;
    globalVar.therapyState = Off;
    globalVar.bluetooth.state = Off;
    globalVar.airplaneMode = Off;
    globalVar.autoTherapy = Off;
    globalVar.therapyPeriod = GoToSleep;
    globalVar.sleepTitrationMode = Off;

    globalVar.autoStartTherapy = Off;
    globalVar.therapyMode = apapMode;
    globalVar.maskType = nasalPillow;

    globalVar.systemDate.date = 10;
    globalVar.systemDate.month = 12;
    globalVar.systemDate.year = 2017;
    globalVar.systemTime.hour = 17;
    globalVar.systemTime.minute = 36;

    globalVar.reminder.mask.state = Off;
    globalVar.reminder.mask.changeDuration = 3;
    globalVar.reminder.mask.setStartDate.date = 12;
    globalVar.reminder.mask.setStartDate.month = 5;
    globalVar.reminder.mask.setStartDate.year = 2017;
    globalVar.reminder.mask.maxDuration = REM_MASK_DURATION_MAX;
    globalVar.reminder.mask.minDuration = REM_MASK_DURATION_MIN;

    globalVar.reminder.airTube.state = Off;
    globalVar.reminder.airTube.changeDuration = 3;
    globalVar.reminder.airTube.setStartDate.date = 12;
    globalVar.reminder.airTube.setStartDate.month = 5;
    globalVar.reminder.airTube.setStartDate.year = 2017;
    globalVar.reminder.airTube.maxDuration = REM_AIRTUBE_DURATION_MAX;
    globalVar.reminder.airTube.minDuration = REM_AIRTUBE_DURATION_MIN;

    globalVar.reminder.airFilter.state = Off;
    globalVar.reminder.airFilter.changeDuration = 2;
    globalVar.reminder.airFilter.setStartDate.date = 12;
    globalVar.reminder.airFilter.setStartDate.month = 5;
    globalVar.reminder.airFilter.setStartDate.year = 2017;
    globalVar.reminder.airFilter.maxDuration = REM_AIRFILTER_DURATION_MAX;
    globalVar.reminder.airFilter.minDuration = REM_AIRFILTER_DURATION_MIN;

    globalVar.airFilter = standardFilter;
    globalVar.sleepReportType = customSleepReport;

    globalVar.pressureUnit = cmh2o;
    globalVar.pressure.currentPressure = 0;
    globalVar.pressure.setPressure = 4;
    globalVar.pressure.targetedPressure = 4;
    globalVar.pressure.apapMinPressure = 7;
    globalVar.pressure.apapMaxPressure = 14;
    globalVar.pressure.globalMinPressure = TARGET_PRESSURE_MIN;
    globalVar.pressure.globalMaxPressure = TARGET_PRESSURE_MAX;

    globalVar.flow.threshold = 150;

    globalVar.goToSleep.state = Off;
    globalVar.goToSleep.Auto = Off;
    globalVar.goToSleep.goToSleepTime = 5;
    globalVar.goToSleep.changeInterval = GO_TO_SLEEP_TIME_CHANGE_INTERVAL;
    globalVar.goToSleep.minLimit = GO_TO_SLEEP_TIME_MIN;
    globalVar.goToSleep.maxLimit = GO_TO_SLEEP_TIME_MAX;

    globalVar.rampTime.state = Off;
    globalVar.rampTime.Auto = Off;
    globalVar.rampTime.rampTime = 5;
    globalVar.rampTime.changeInterval = RAMP_CHANGE_INTERVAL;
    globalVar.rampTime.minLimit = RAMP_TIME_MIN;
    globalVar.rampTime.maxLimit = RAMP_TIME_MAX;

    globalVar.powerSavings = Off;

    globalVar.displaySettings.autoBrightnessAdjustment = Off;
    globalVar.displaySettings.displayDimDuration = 10;
    globalVar.displaySettings.changeDisplayDimDurationInterval = DISPLAY_DIM_DURATION_INTERVAL;
    globalVar.displaySettings.minDisplayDimDurationLimit = DISPLAY_DIM_DURATION_MIN;
    globalVar.displaySettings.maxDisplayDimDurationLimit = DISPLAY_DIM_DURATION_MAX;
    globalVar.displaySettings.brightnessLevel = 90;
    globalVar.displaySettings.minBrightnessLevel = BRIGHTNESS_LEVEL_MIN;
    globalVar.displaySettings.maxBrightnessLevel = BRIGHTNESS_LEVEL_MAX;

    globalVar.maskFitTest.maskFitTestState = Off;

    globalVar.sendSleepReportDuration = day1;
    globalVar.sleepReportDuration = day1;

    globalVar.comfortLevel.state = On;
    globalVar.comfortLevel.comfortLevelSet = COMFORT_LEVEL_3;
    globalVar.comfortLevel.minComfortLevelLimit = COMFORT_LEVEL_1;
    globalVar.comfortLevel.maxComfortLevelLimit = COMFORT_LEVEL_3;

    globalVar.snooze.state = Off;
    globalVar.snooze.snoozeTime = 5;
    globalVar.snooze.minSnoozeTime = SNOOZE_TIME_MIN;
    globalVar.snooze.maxSnoozeTime = SNOOZE_TIME_MAX;
    globalVar.snooze.snoozeInterval = SNOOZE_CHANGE_INTERVAL;

    globalVar.diagnosticData = Off;
    globalVar.language = language_english;
}

void DataValidation::updateMinMaxOtherVariables(void)
{
    globalVar.clinicalMode = Off;
    globalVar.therapyState = Off;
//    globalVar.bluetooth.state = Off;
//    globalVar.airplaneMode = Off;
//    globalVar.autoTherapy = Off;
    globalVar.therapyPeriod = GoToSleep;

    globalVar.systemDate.date = 10;
    globalVar.systemDate.month = 12;
    globalVar.systemDate.year = 2017;
    globalVar.systemTime.hour = 17;
    globalVar.systemTime.minute = 36;

//    globalVar.reminder.mask.state = On;
//    globalVar.reminder.mask.changeDuration = 6;
//    globalVar.reminder.mask.setStartDate.date = 12;
//    globalVar.reminder.mask.setStartDate.month = 5;
//    globalVar.reminder.mask.setStartDate.year = 2017;
    globalVar.reminder.mask.maxDuration = REM_MASK_DURATION_MAX;
    globalVar.reminder.mask.minDuration = REM_MASK_DURATION_MIN;
    globalVar.maskFitTest.maskFitTestState = Off;

//    globalVar.reminder.airTube.state = On;
//    globalVar.reminder.airTube.changeDuration = 10;
//    globalVar.reminder.airTube.setStartDate.date = 12;
//    globalVar.reminder.airTube.setStartDate.month = 5;
//    globalVar.reminder.airTube.setStartDate.year = 2017;
    globalVar.reminder.airTube.maxDuration = REM_AIRTUBE_DURATION_MAX;
    globalVar.reminder.airTube.minDuration = REM_AIRTUBE_DURATION_MIN;

//    globalVar.reminder.airFilter.state = On;
//    globalVar.reminder.airFilter.changeDuration = 6;
//    globalVar.reminder.airFilter.setStartDate.date = 12;
//    globalVar.reminder.airFilter.setStartDate.month = 5;
//    globalVar.reminder.airFilter.setStartDate.year = 2017;
    globalVar.reminder.airFilter.maxDuration = REM_AIRFILTER_DURATION_MAX;
    globalVar.reminder.airFilter.minDuration = REM_AIRFILTER_DURATION_MIN;

//    globalVar.airFilter = standardFilter;
//    globalVar.sleepReportType = customSleepReport;

//    globalVar.pressureUnit = cmh2o;
//    globalVar.pressure.currentPressure = 0;
//    globalVar.pressure.setPressure = 5;
//    globalVar.pressure.targetedPressure = 10;
    globalVar.pressure.globalMinPressure = TARGET_PRESSURE_MIN;
    globalVar.pressure.globalMaxPressure = TARGET_PRESSURE_MAX;

//    globalVar.goToSleep.state = On;
//    globalVar.goToSleep.Auto = Off;
//    globalVar.goToSleep.goToSleepTime = 15;
    globalVar.goToSleep.changeInterval = GO_TO_SLEEP_TIME_CHANGE_INTERVAL;
    globalVar.goToSleep.minLimit = GO_TO_SLEEP_TIME_MIN;
    globalVar.goToSleep.maxLimit = GO_TO_SLEEP_TIME_MAX;

//    globalVar.rampTime.state = On;
//    globalVar.rampTime.Auto = Off;
//    globalVar.rampTime.rampTime = 0;
    globalVar.rampTime.changeInterval = RAMP_CHANGE_INTERVAL;
    globalVar.rampTime.minLimit = RAMP_TIME_MIN;
    globalVar.rampTime.maxLimit = RAMP_TIME_MAX;

//    globalVar.powerSavings = Off;

//    globalVar.displaySettings.autoBrightnessAdjustment = Off;
//    globalVar.displaySettings.displayDimDuration = 4;
    globalVar.displaySettings.changeDisplayDimDurationInterval = DISPLAY_DIM_DURATION_INTERVAL;
    globalVar.displaySettings.minDisplayDimDurationLimit = DISPLAY_DIM_DURATION_MIN;
    globalVar.displaySettings.maxDisplayDimDurationLimit = DISPLAY_DIM_DURATION_MAX;
//    globalVar.displaySettings.brightnessLevel = 3;
    globalVar.displaySettings.minBrightnessLevel = BRIGHTNESS_LEVEL_MIN;
    globalVar.displaySettings.maxBrightnessLevel = BRIGHTNESS_LEVEL_MAX;

//    globalVar.sendSleepReportDuration = day1;
//    globalVar.sleepReportDuration = day1;

//    globalVar.comfortLevel.state = On;
//    globalVar.comfortLevel.comfortLevelSet = 3;
    globalVar.comfortLevel.minComfortLevelLimit = COMFORT_LEVEL_1;
    globalVar.comfortLevel.maxComfortLevelLimit = COMFORT_LEVEL_3;

//    globalVar.snooze.state = On;
//    globalVar.snooze.snoozeTime = 20;
    globalVar.snooze.minSnoozeTime = SNOOZE_TIME_MIN;
    globalVar.snooze.maxSnoozeTime = SNOOZE_TIME_MAX;
    globalVar.snooze.snoozeInterval = SNOOZE_CHANGE_INTERVAL;
}



