#include "bluetoothinit.h"
#include "ex_variables.h"
#include <QtBluetooth/qlowenergycontroller.h>

#include "airboxfiletransferservice.h"
#include "airboxdeviceinformationservice.h"

#include <QLowEnergyAdvertisingParameters>
#include <QLowEnergyConnectionParameters>
#include <QLowEnergyController>
#include <QDir>
#include <QDebug>

#include "application/datalogging.h"

BluetoothInit::BluetoothInit(PeripheralControl * peripheralControl,
                             int shutdownPin,
                             BluetoothDebugScreen * m_BleDebug,
                             DataLogging * m_DataBackend,
                             SettingsWindowBasic * settingsBasicBackend)
    : QObject(),
    m_PeripheralControl(peripheralControl),
    shutdownDisablePinNo(shutdownPin),
    m_BleDebugScreen(m_BleDebug),
    m_DataManager(m_DataBackend),
    settingsBasicScreen(settingsBasicBackend),
    bleController(nullptr),
    bleLocalDevice(nullptr),
    advertisingData(nullptr),
    charData(nullptr),
    serviceData(nullptr),
    clientConfig(nullptr),
    service(nullptr),
    deviceInformationService(nullptr),
    fileTransferService(nullptr),
    bleProcess(nullptr),
    outputString(nullptr),
    m_Thread(nullptr),
    poweringOff(false),
    getProcessOutput(false),
    bleInitializeSuccess(false)
{
    m_Thread = new QThread;
    m_Thread->setObjectName("BluetoothInit");
    connect(m_Thread,SIGNAL(started()),this,SLOT(bleInitProcedures()));
    moveToThread(m_Thread);
    m_Thread->start();
}

BluetoothInit::~BluetoothInit()
{
    poweringOff = true;

    bleController->stopAdvertising();
    bleController->disconnectFromDevice();
    bleLocalDevice->setHostMode(QBluetoothLocalDevice::HostPoweredOff);

    if(hciattachPID)
    {
        QString localStr;
        localStr = "kill " + QString("%1").arg(hciattachPID);
        runShellCommand(localStr);

        if(bluetoothDaemonPID)
        {
            localStr = "kill " + QString("%1").arg(bluetoothDaemonPID);
            runShellCommand(localStr);
        }
    }

    // Power Off Ble module
    emit setGpioState(shutdownDisablePinNo,false);

    if(m_Thread)
        m_Thread->exit();

    delete outputString;
    delete advertisingData;

    connect(m_Thread,SIGNAL(finished()),m_Thread,SLOT(deleteLater()));
    connect(m_Thread,SIGNAL(finished()),deviceInformationService,SLOT(deleteLater()));
    connect(m_Thread,SIGNAL(finished()),fileTransferService,SLOT(deleteLater()));
}

void BluetoothInit::bleInitProcedures(void)
{
    outputString = new QString;

    if(m_PeripheralControl)
    {
        connect(this,SIGNAL(setGpioState(int,bool)),m_PeripheralControl,SLOT(setGpioState(int,bool)));
    }

    if(m_BleDebugScreen)
    {
        connect(this,SIGNAL(logDataToDebugScreen(QString,BluetoothDebugColorType)),
                m_BleDebugScreen,SLOT(addRowData(QString,BluetoothDebugColorType)));
    }

    if(m_DataManager)
    {
        connect(this,SIGNAL(copyDataToSDCard()),m_DataManager,SLOT(copyDataToSDCard()));
    }

    if(settingsBasicScreen)
    {
        connect(settingsBasicScreen,SIGNAL(handleBlePowerOnOff(bool)),
                this,SLOT(handleBlePowerOnOff(bool)));
    }

    /* Generate Reset Pulse
     * to poweron bluetooth module */
    emit setGpioState(shutdownDisablePinNo,true);
    emit setGpioState(shutdownDisablePinNo,false);
    emit setGpioState(shutdownDisablePinNo,true);

    /* Start a terminal application where we can execute bluetooth related commands */
    bleProcess = new QProcess(this);
    connect(bleProcess, SIGNAL(readyReadStandardOutput()), this, SLOT(printOutput()));
    connect(bleProcess, SIGNAL(readyReadStandardError()), this, SLOT(printError()));

    /* Attach uart port to bluetooth module
     *      hciattach /dev/ttyS1 texas 115200
     * command will attach uart module mounted at /dev/ttyS1
     * to blueZ library stack at the baud rate of 115200
     */
    getProcessOutput = true;

    /* Run command in a shell created earlier */
    runShellCommand("hciattach /dev/ttyS1 texas 115200");
    qDebug() << "Final Output" << *outputString << bleInitializeSuccess;

    /* Check if the device initialize successfully */
    if(bleInitializeSuccess == true)
    {
        /* Get Process ID of hciattach daemon
         * which will drive bluetooth UART driver in background
         */
        getProcessOutput = true;
        runShellCommand("pgrep hciattach");
        hciattachPID = outputString->toInt();

        /* Get Process ID of bluetoothd daemon
         * which will drive blueZ driver in background
         */
        getProcessOutput = true;
        runShellCommand("pgrep bluetoothd");
        bluetoothDaemonPID = outputString->toInt();

        /* Create local bluetooth device instance and power on it */
        bleLocalDevice = new QBluetoothLocalDevice(this);
        bleLocalDevice->powerOn();

        /* Create BLE Peripheral Device */
        bleController = QLowEnergyController::createPeripheral();

        /* Create advertising packet data instance */
        advertisingData = new QLowEnergyAdvertisingData;

        /* Create advertising header instance */
        updateAdvertisingHeaderData();

        /* Create All service class
         * Device Information,File Transfer Service
         */
        fileTransferService = new AirboxFileTransferService(bleController);
        deviceInformationService = new AirboxDeviceInformationService(bleController);

        /* Connecting bluetooth related signal to
         * proper slots for handling
         */
        connect(bleController,SIGNAL(connectionUpdated(QLowEnergyConnectionParameters)),this,SLOT(bleConnectionUpdated(QLowEnergyConnectionParameters)));
        connect(bleController,SIGNAL(disconnected()),this,SLOT(bleDisconnected()));
        connect(bleController,SIGNAL(discoveryFinished()),this,SLOT(bleDiscoveryFinished()));
        connect(bleController,SIGNAL(error(QLowEnergyController::Error)),this,SLOT(bleError(QLowEnergyController::Error)));
        connect(bleController,SIGNAL(serviceDiscovered(QBluetoothUuid)),this,SLOT(bleServiceDiscovered(QBluetoothUuid)));
        connect(bleController,SIGNAL(stateChanged(QLowEnergyController::ControllerState)),this,SLOT(bleStateChanged(QLowEnergyController::ControllerState)));

        /* Start BLE Peripheral Device
         * Advertisement
         */
        startBleAdvertising();

        /* Create timer to update therapy status
         * flag in advertising header
         */
        handleBlePowerOnOff(globalVar.bluetooth.state);

    } else {
        //TODO error handling if bluetooth doesn't starts
    }
}

void BluetoothInit::addServices()
{
//    QList<QBluetoothUuid> localList = advertisingData->services();
//    if(localList.size() == 2)
//    {
//        qDebug() << Q_FUNC_INFO << localList;
//        return;
//    }

    advertisingData->setServices(QList<QBluetoothUuid>()
                                 << QBluetoothUuid::DeviceInformation
                                 << QBluetoothUuid(fileTransferService->FRESCA_OTS_SERVICE_UUID));
}


void BluetoothInit::handleBlePowerOnOff(bool tState)
{
    /* Update ble State as per the switch in Settings Screen */
    if(tState == true)
    {
        if(bleLocalDevice)
        {
            bleLocalDevice->powerOn();
            updateAdvertisingHeaderData();
        }
    }
    else
    {
        if(bleController)
        {
            if(bleController->state() == QLowEnergyController::AdvertisingState)
                bleController->stopAdvertising();

            bleController->disconnectFromDevice();
            bleLocalDevice->setHostMode(QBluetoothLocalDevice::HostPoweredOff);
        }
    }

    startBleAdvertising();
}


void BluetoothInit::startBleAdvertising(void)
{
    if(globalVar.bluetooth.state == On)
    {
        if(bleController)
        {
            addServices();

            bleController->startAdvertising(QLowEnergyAdvertisingParameters(),
                                            *advertisingData,
                                            *advertisingData);
        }
    }
}


void BluetoothInit::updateAdvertisingHeaderData(void)
{
    advertisingData->setDiscoverability(QLowEnergyAdvertisingData::DiscoverabilityGeneral);
    advertisingData->setIncludePowerLevel(true);

    QString bleName = "Airbox";
    if(globalVar.serialNumberStr.count() == SERIAL_NUMBER_MAX_CHAR)
    {
        QString localSerialString = globalVar.serialNumberStr;
        QString localString = localSerialString.remove( QRegExp("^[0]*") );
        quint64 serialNumberLocal = localString.toULongLong();
        bleName = bleName + " " + QString("%1").arg(serialNumberLocal, 16, 10, QChar('0'));

//        qDebug() << Q_FUNC_INFO << bleName << globalVar.serialNumberStr
//                 << serialNumberLocal << localSerialString << localString;
    }

    qDebug() << Q_FUNC_INFO << bleName << globalVar.serialNumberStr << globalVar.serialNumberStr.count();
    advertisingData->setLocalName(bleName);
}

void BluetoothInit::runShellCommand(const QString & cmd)
{
    bleProcess->start(cmd);
    bleProcess->waitForFinished();
}

void BluetoothInit::printOutput()
{
//    qDebug() << "Output";
    QByteArray byteArray = bleProcess->readAllStandardOutput();
    QStringList strLines = QString(byteArray).split("\n");

    if(getProcessOutput == true)
    {
        QString localStr = strLines.at(0);
        *outputString = QString("%1").arg(localStr);
        getProcessOutput = false;

        if(*outputString == "Device setup complete")
                bleInitializeSuccess = true;
        else
            bleInitializeSuccess = false;
    }

    foreach (QString line, strLines){
        qDebug() << "Output" << line << *outputString;
    }
}

void BluetoothInit::printError()
{
    QByteArray byteArray = bleProcess->readAllStandardError();
    QStringList strLines = QString(byteArray).split("\n");

    foreach (QString line, strLines){
        qDebug() << "Error" << line;
    }
}

void BluetoothInit::bleConnected()
{
    qDebug() << Q_FUNC_INFO ;
}


void BluetoothInit::bleConnectionUpdated(const QLowEnergyConnectionParameters & newParameters)
{
    qDebug() << Q_FUNC_INFO << newParameters.latency()
             << newParameters.minimumInterval()
             << newParameters.maximumInterval()
             << newParameters.supervisionTimeout() ;

}

void BluetoothInit::bleDisconnected()
{
    qDebug() << Q_FUNC_INFO ;
    if(poweringOff != true)
    {
        startBleAdvertising();
    }
}
void BluetoothInit::bleDiscoveryFinished()
{
    qDebug() << Q_FUNC_INFO ;
}
void BluetoothInit::bleError(QLowEnergyController::Error newError)
{
    qDebug() << Q_FUNC_INFO << newError;
}
void BluetoothInit::bleServiceDiscovered(const QBluetoothUuid &newService)
{
    qDebug() << Q_FUNC_INFO << newService;
}
void BluetoothInit::bleStateChanged(QLowEnergyController::ControllerState state)
{
    qDebug() << Q_FUNC_INFO << state ;
    if(state == QLowEnergyController::ConnectedState)
    {
//        /* Reset connection parameter of services */
//        fileTransferService->resetServiceData();
    }

    if(state == QLowEnergyController::UnconnectedState)
    {
        emit copyDataToSDCard();
    }
}

void BluetoothInit::logDataToFile(const QString & str,BluetoothDebugColorType type)
{
    emit logDataToDebugScreen(str,type);
}
