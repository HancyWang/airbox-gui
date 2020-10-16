#ifndef BLEFILETRANSFER_H
#define BLEFILETRANSFER_H

#include <QLowEnergyController>
#include <QLowEnergyCharacteristicData>
#include <QLowEnergyDescriptorData>
#include <QLowEnergyServiceData>

#include <QLowEnergyService>
#include <QFile>
#include <QElapsedTimer>
#include <QDir>
#include <QDate>
#include <QProcess>
#include <QTimer>
#include <QObject>
#include <QDateTime>
#include <QDataStream>
#include <QByteArray>
#include <QElapsedTimer>
#include <QList>

#include "blecommandfactory.h"

class AirboxFileTransferService : public QObject
{
    Q_OBJECT

public:
    explicit AirboxFileTransferService(QLowEnergyController * leController);

    QFile & GetFile()
    {
        return mCurrentFile;
    }

    void SetPacketDelay(qint16 packetDelay)
    {
        mPacketDelay = packetDelay;
    }

    ushort GetPacketDelay()
    {
        return mPacketDelay;
    }

    void Reset()
    {
        mController->addService(serviceData);
    }
    void SetTransferring(bool isTransferring)
    {
        mIsTransferring = true;
    }

    void SetReceivingTransfer(bool isReceiving)
    {
        mIsReceiving = isReceiving;
    }

    void SetPacketCount(ushort count)
    {
        mPacketCount = count;
    }

    void SetPacketCounter(ushort count)
    {
        mPacketCounter = count;
    }

    QTimer * GetFileTimer()
    {
        return mFileTimer;
    }

    bool IsTransferring()
    {
        return mIsTransferring;
    }

    bool IsReceivingTransfer()
    {
        return mIsReceiving;
    }

    bool StopTransfer()
    {
        mFileTimer->stop();
        mIsTransferring = false;
        mIsReceiving = false;
    }

    void SetFileStream()
    {
        mCurrentFileStream.setDevice(&mCurrentFile);
    }

    void SetLogType(QString logType)
    {
        mLogType = logType;
    }

    QFile & GetCurrentFile()
    {
        return mCurrentFile;
    }

    ushort GetPacketSize()
    {
        return mPacketSize;
    }
    ushort GetPacketCounter()
    {
        return mPacketCounter;
    }

    ushort GetPacketCount()
    {
        return mPacketCount;
    }

    QList<uint32_t> GetMissedPackets()
    {
        return mMissedPacketList;
    }


    void SendData(QByteArray & dataArray)
    {
        QLowEnergyCharacteristic characteristic
                = mService->characteristic(QBluetoothUuid(FRESCA_OTS_SERVICE_DATA_TRANSFER_UUID));
        mService->writeCharacteristic(characteristic, dataArray);

    }

    bool GetDirs(const QDateTime & start, const QDateTime  & end);

    const QString FRESCA_OTS_SERVICE_UUID = "{2628fc04-8fe6-11e8-9eb6-529269fb1459}";
    QElapsedTimer testtimer;

    const QString FRESCA_LOG_PATH = "LOG/";
    const QString FRESCA_TRANSMIT_ARCHIVE_FILE = "/" + FRESCA_LOG_PATH + "download.tgz";

    const QString FRESCA_FIRMWARE_PATH = "/FIRMWARE/";
    const QString FRESCA_RECIEVE_FIRMWARE_FILE = FRESCA_FIRMWARE_PATH + "firmware.tgz";

private slots:
    void onCharacteristicChanged(const QLowEnergyCharacteristic &characteristic, const QByteArray &newValue);
    void onCharacteristicWritten(const QLowEnergyCharacteristic &characteristic, const QByteArray &newValue);
    void onFileTimer();

private:

    const QString FRESCA_OTS_SERVICE_CONTROL_POINT_UUID = "{8854c45c-a450-11e8-98d0-529269fb1459}";
    const QString FRESCA_OTS_SERVICE_DATA_TRANSFER_UUID = "{8854c768-a450-11e8-98d0-529269fb1459}";


    QDataStream  mCurrentFileStream;
    QTimer * mFileTimer = NULL;
    QLowEnergyController * mController = NULL;
    QLowEnergyService * mService;

    QFile mCurrentFile;
    BLECommandFactory mFactory;
    QLowEnergyServiceData serviceData;
    quint16 mPacketDelay = 26;
    ushort mPacketCounter = 0;
    ushort mPacketSize = 181;
    uint32_t mPacketCount = 0;
    bool mIsTransferring = false;
    QString mLogType = "LESC";
    bool mIsReceiving = false;
    QList<uint32_t> mMissedPacketList;


};

#endif // BLEFILETRANSFER_H
