#ifndef BLEDEVICEINFORMATION_H
#define BLEDEVICEINFORMATION_H
#include <QtBluetooth/qlowenergycharacteristic.h>
#include <QtBluetooth/qlowenergycharacteristicdata.h>
#include <QtBluetooth/qlowenergydescriptordata.h>
#include <QtBluetooth/qlowenergycontroller.h>
#include <QtBluetooth/qlowenergyservice.h>
#include <QtBluetooth/qlowenergyservicedata.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qcoreapplication.h>
#include <QtCore/qlist.h>
#include <QtCore/qloggingcategory.h>
#include <QtCore/qscopedpointer.h>
#include <QtCore/qtimer.h>
#include <QtCore/qthread.h>
#include <QtCore/qdatastream.h>
#include <QFile>

#include <QObject>
#include <QDateTime>
#include <QDataStream>

#include "blecommandfactory.h"

class AirboxDeviceInformationService: public QObject
{
    Q_OBJECT

public:
    explicit AirboxDeviceInformationService(QLowEnergyController * leController)
    {
        mController = leController;

        // Device name Characteristic & Descriptor
        QLowEnergyCharacteristicData deviceNameData;
        deviceNameData.setUuid(QBluetoothUuid::DeviceName);
        deviceNameData.setProperties(QLowEnergyCharacteristic::Read);
        deviceNameData.setValue("Airbox");

        // Serial number Characteristic & Descriptor
        QLowEnergyCharacteristicData serialNumberData;
        serialNumberData.setUuid(QBluetoothUuid::SerialNumberString);
        serialNumberData.setProperties(QLowEnergyCharacteristic::Read);
        serialNumberData.setValue(QString::number(12345).toLocal8Bit());

        // Firmware Version Characteristic & Descriptor
        QLowEnergyCharacteristicData firmwareVersionData;
        firmwareVersionData.setUuid(QBluetoothUuid::FirmwareRevisionString);
        firmwareVersionData.setProperties(QLowEnergyCharacteristic::Read);
        firmwareVersionData.setValue("0.1");

        // Software Version Characteristic & Descriptor
        QLowEnergyCharacteristicData softwareVersionData;
        softwareVersionData.setUuid(QBluetoothUuid::SoftwareRevisionString);
        softwareVersionData.setProperties(QLowEnergyCharacteristic::Read);
        softwareVersionData.setValue("0.1");

        // Manufacturer Name Characteristic & Descriptor
        QLowEnergyCharacteristicData manufacturerNameData;
        manufacturerNameData.setUuid(QBluetoothUuid::ManufacturerNameString);
        manufacturerNameData.setProperties(QLowEnergyCharacteristic::Read);
        manufacturerNameData.setValue("Fresca");

        serviceData.setType(QLowEnergyServiceData::ServiceTypePrimary);
        serviceData.setUuid(QBluetoothUuid::DeviceInformation);

        serviceData.addCharacteristic(deviceNameData);
        serviceData.addCharacteristic(serialNumberData);
        serviceData.addCharacteristic(firmwareVersionData);
        serviceData.addCharacteristic(softwareVersionData);
        serviceData.addCharacteristic(manufacturerNameData);
        Reset();

    }

    void Reset()
    {
        mController->addService(serviceData);
    }

private:
    QLowEnergyServiceData serviceData;
    QLowEnergyController * mController = NULL;

};
#endif // BLEDEVICEINFORMATION_H
