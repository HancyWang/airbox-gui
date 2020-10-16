#include "airboxfiletransferservice.h"
#include <QLowEnergyConnectionParameters>
AirboxFileTransferService::AirboxFileTransferService(QLowEnergyController * leController)
{
    mController = leController;
    QLowEnergyCharacteristicData objectControlPointData;
    objectControlPointData.setUuid(QBluetoothUuid(FRESCA_OTS_SERVICE_CONTROL_POINT_UUID));
    objectControlPointData.setProperties(QLowEnergyCharacteristic::Read|QLowEnergyCharacteristic::Write|QLowEnergyCharacteristic::Indicate);
    QByteArray objectControl = QByteArray::fromStdString("0");
    QLowEnergyDescriptorData objectControlDescriptor(QBluetoothUuid::ClientCharacteristicConfiguration,QByteArray(2, 0));
    objectControlPointData.setValue(objectControl);
    objectControlPointData.addDescriptor(objectControlDescriptor);

    QLowEnergyCharacteristicData objectDataTransferData;
    objectDataTransferData.setUuid(QBluetoothUuid(FRESCA_OTS_SERVICE_DATA_TRANSFER_UUID));
    objectDataTransferData.setProperties(QLowEnergyCharacteristic::WriteNoResponse|QLowEnergyCharacteristic::Notify);
    QByteArray objectTransfer = QByteArray::fromStdString("0");
    QLowEnergyDescriptorData objectTransferDescriptor(QBluetoothUuid::ClientCharacteristicConfiguration,QByteArray(2, 0));
    objectDataTransferData.setValue(objectTransfer);
    objectDataTransferData.addDescriptor(objectTransferDescriptor);

    serviceData.setType(QLowEnergyServiceData::ServiceTypePrimary);
    serviceData.setUuid(QBluetoothUuid(FRESCA_OTS_SERVICE_UUID));
    serviceData.addCharacteristic(objectControlPointData);
    serviceData.addCharacteristic(objectDataTransferData);

    mService = leController->addService(serviceData);
    connect(mService, SIGNAL(characteristicChanged(QLowEnergyCharacteristic, QByteArray)), this, SLOT(onCharacteristicChanged(QLowEnergyCharacteristic, QByteArray)));
    connect(mService, SIGNAL(characteristicWritten(QLowEnergyCharacteristic, QByteArray)), this, SLOT(onCharacteristicWritten(QLowEnergyCharacteristic, QByteArray)));

    mFileTimer = new QTimer(this);
    connect(mFileTimer, SIGNAL(timeout()), this , SLOT(onFileTimer()));
}

void AirboxFileTransferService::onFileTimer()
{
    char data[mPacketSize];
    if(!mIsTransferring)
        return;
    int ret = mCurrentFileStream.readRawData(data,mPacketSize - sizeof(mPacketCounter));
    if(ret > 0)
    {
        QByteArray dataArray;
        QDataStream streamVMan((QByteArray *)&dataArray, QIODevice::WriteOnly);
        streamVMan << mPacketCounter;
        streamVMan.writeRawData(data,ret);

        mPacketCounter++;

        QLowEnergyCharacteristic characteristic
                = mService->characteristic(QBluetoothUuid(FRESCA_OTS_SERVICE_DATA_TRANSFER_UUID));
        mService->writeCharacteristic(characteristic, dataArray);
        QLowEnergyService::ServiceError err = mService->error();
        if(err != QLowEnergyService::NoError)
        {
            qDebug() <<  "Error " << err;

        }
    }
    else {
        mFileTimer->stop();
        mCurrentFile.close();
        mIsTransferring = false;
        qDebug() <<  "Transfer Complete in " <<testtimer.elapsed();
    }

}

bool AirboxFileTransferService::GetDirs(const QDateTime & start, const QDateTime & end)
{
    bool returnValue = false;
    QDateTime startDate = start;
    QDateTime endDate = end.isNull() ? start : end;

    QDir dirList;
    dirList.setFilter(QDir::Dirs | QDir::NoSymLinks | QDir::NoDotAndDotDot);
    dirList.setSorting(QDir::Name | QDir::DirsFirst);
    dirList.setPath("/"+FRESCA_LOG_PATH);

    if(dirList.exists()) {
        QStringList sl = dirList.entryList();
        QList<QDateTime> dateList;
        QStringList args = {"-zcvf",FRESCA_TRANSMIT_ARCHIVE_FILE};
        for(int i = 0; i < dirList.count();i++)
        {
            QDateTime dt = QDateTime::fromString(dirList[i].remove(8,1),"yyyyMMddhhmmss");
            if((startDate <= dt) && (dt <= endDate))
            {
                for(int j = 0; j < mLogType.length(); j++)
                {
                    args.push_back("/"+FRESCA_LOG_PATH + dirList[i] + "/" + dirList[i] + mLogType[j] + ".txt");
                }
                dateList.push_front(dt);
            }
        }
        if(dateList.count() > 0)
        {
            QProcess * process = new QProcess(this);
            QString cmd = QString("/bin/tar");
            int result = process->execute(cmd,args);
            if(result == 0)
            {
                qDebug() << "Archive Successful Exit Status " << process->exitStatus();
                returnValue = true;
            }
            else {
                qDebug() << "Archive Failed Exit Status " << process->exitStatus();
            }
        }
    }
    return returnValue;
}

void AirboxFileTransferService::onCharacteristicChanged(const QLowEnergyCharacteristic &characteristic, const QByteArray &newValue)
{
    if(characteristic.uuid() == QBluetoothUuid(FRESCA_OTS_SERVICE_CONTROL_POINT_UUID))
    {
        BLECommand * cmd = mFactory.CreateCommand(newValue);
        if(cmd->GetError() == BLECommand::SUCCESS)
        {
            cmd->Process(*this);
            mService->writeCharacteristic(characteristic, cmd->GetReturnBuffer());
            if(cmd->GetId() == BLECommand::RETRIEVE_DATA_CMD)
            {
                GetFileTimer()->start(GetPacketDelay());
            }
        }

/*
        if(cmd->GetId() == BLECommand::PACKET_DELAY)
        {
            QLowEnergyConnectionParameters params;
            params.setIntervalRange(30,62.5);
            params.setSupervisionTimeout(5500);
            params.setLatency(5);
            mController->requestConnectionUpdate(params);
        }*/
        delete cmd;
    }
    else if(characteristic.uuid() == QBluetoothUuid(FRESCA_OTS_SERVICE_DATA_TRANSFER_UUID))
    {
        if(mIsReceiving)
        {
            QDataStream streamVMan((QByteArray *)&newValue, QIODevice::ReadOnly);
            quint16 packetNum = 0;
            streamVMan >> packetNum;
            if(mPacketCounter == packetNum)
            {
                QByteArray newArray(newValue);
                newArray.remove(0,2);
                mCurrentFileStream.writeRawData(newArray,newArray.length());
            }
            else
            {
                QByteArray nullArray(mPacketSize,0);
                mCurrentFileStream.writeRawData(nullArray,nullArray.length());
                mMissedPacketList.append(packetNum);
            }
            if(mPacketCounter == mPacketCount)
            {
            }
            mPacketCounter++;
        }
        qDebug() <<  Q_FUNC_INFO << "Data Transfer:";
    }
    else {
        qDebug() <<  Q_FUNC_INFO << "Wrong UUID:";
    }
}

void AirboxFileTransferService::onCharacteristicWritten(const QLowEnergyCharacteristic &characteristic, const QByteArray &newValue)
{
    qDebug() << "onCharacteristicWritten:" << characteristic.handle() << newValue;
}
