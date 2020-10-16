#ifndef BLUETOOTHINIT_H
#define BLUETOOTHINIT_H

#include <QLowEnergyController>
#include <QLowEnergyServiceData>
#include <QBluetoothLocalDevice>
#include <QLowEnergyDescriptorData>
#include <QProcess>
#include <QThread>

#include "screens/bluetoothdebugscreen.h"

class PeripheralControl;
class BluetoothDebugScreen;
class DataLogging;
class SettingsWindowBasic;
class BluetoothDebugScreen;
class AirboxDeviceInformationService;
class AirboxFileTransferService;

class BluetoothInit : public QObject
{
    Q_OBJECT

public:
    explicit BluetoothInit(PeripheralControl * peripheralControl,
                           int shutdownPin,
                           BluetoothDebugScreen * m_BleDebug,
                           DataLogging * m_DataBackend,
                           SettingsWindowBasic * settingsBasicBackend);
    ~BluetoothInit();

//    QScopedPointer<QLowEnergyController> bleController;
    QLowEnergyController * bleController;

    void updateAdvertisingHeaderData(void);
    void startBleAdvertising(void);

    bool bleInitializeSuccess=false;

    void addServices();

signals:
    void setGpioState(int gpioNo,bool outputState);
    void logDataToDebugScreen(const QString & str,BluetoothDebugColorType type);

    void copyDataToSDCard(void);

private slots:
    void bleConnected();
    void bleConnectionUpdated(const QLowEnergyConnectionParameters & newParameters);
    void bleDisconnected();
    void bleDiscoveryFinished();
    void bleError(QLowEnergyController::Error newError);
    void bleServiceDiscovered(const QBluetoothUuid &newService);
    void bleStateChanged(QLowEnergyController::ControllerState state);

    void printOutput();
    void printError();



public slots:
    void logDataToFile(const QString & str,BluetoothDebugColorType type);
    void bleInitProcedures(void);
    void handleBlePowerOnOff(bool tState);

private:
    PeripheralControl * m_PeripheralControl;
    BluetoothDebugScreen * m_BleDebugScreen;
    DataLogging * m_DataManager;
    SettingsWindowBasic * settingsBasicScreen;

    QBluetoothLocalDevice * bleLocalDevice;

    QLowEnergyAdvertisingData * advertisingData;
    QLowEnergyCharacteristicData * charData;
    QLowEnergyServiceData * serviceData;
    QLowEnergyDescriptorData * clientConfig;
    QLowEnergyService * service;

    AirboxDeviceInformationService * deviceInformationService;
    AirboxFileTransferService * fileTransferService;


    QProcess * bleProcess;

    bool getProcessOutput;
    bool poweringOff;
    QString * outputString;
    int bluetoothDaemonPID;
    int hciattachPID;

    int shutdownDisablePinNo=0;

    void runShellCommand(const QString & cmd);

    QThread * m_Thread;

};

#endif // BLUETOOTHINIT_H
