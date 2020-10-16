#include "bleretrievecommand.h"
#include "airboxfiletransferservice.h"

BLERetrieveCommand::BLERetrieveCommand(const QByteArray & data): BLECommand(BLECommand::RETRIEVE_DATA_CMD)
{
    ERRORS ret = Check(data);
    if(ret == SUCCESS)
    {
        if(data.count() == 16)
        {
            QByteArray part = data.mid(1,15);
            QDateTime dt = QDateTime::fromString(QString(part).remove(8,1),"yyyyMMddhhmmss");
            if(!dt.isValid())
            {
                SetError(BAD_PARAMETERS);
            }
            else {
                mStartDate = dt;
            }
        }
        else if(data.count() == 31)
        {
            QByteArray part = data.mid(1,15);
            QString partString = QString(part);
            QDateTime dt = QDateTime::fromString(partString.remove(8,1),"yyyyMMddhhmmss");
            if(!dt.isValid())
            {
                SetError(BAD_PARAMETERS);
            }
            else
            {
                mStartDate = dt;
                part = data.mid(16,15);
                partString = QString(part);
                dt = QDateTime::fromString(partString.remove(8,1),"yyyyMMddhhmmss");
                if(!dt.isValid())
                {
                    SetError(BAD_PARAMETERS);
                }
                else
                {
                    mEndDate = dt;
                }

            }

        }
        else {
            SetError(BAD_PARAMETERS);

        }
    }
}

void BLERetrieveCommand::Process(AirboxFileTransferService & transferService)
{
    if(transferService.IsTransferring() || transferService.IsReceivingTransfer())
    {
        SetError(BLECommand::INCORRECT_STATE);
    }
    else
    {
        if(transferService.GetDirs(GetStartDate(),GetEndDate()))
        {
            qDebug() << "Stop Transfer";
        //    transferService.StopTransfer();
            qDebug() << "Get Current File " << transferService.FRESCA_TRANSMIT_ARCHIVE_FILE;

            transferService.GetCurrentFile().setFileName(transferService.FRESCA_TRANSMIT_ARCHIVE_FILE);


            if (transferService.GetCurrentFile().open(QIODevice::ReadOnly | QIODevice::Unbuffered))
            {
                QByteArray fileSizeArray;
                QDataStream streamVMan(&fileSizeArray, QIODevice::WriteOnly);
                streamVMan << (qint32) transferService.GetCurrentFile().bytesAvailable();
                AddReturnData(fileSizeArray);
                transferService.SetFileStream();
                transferService.SetPacketCounter(0);
                transferService.SetTransferring(true);
            }
            else
            {
                SetError(BLECommand::SYSTEM_ERROR);
            }
        }
        else
        {
            SetError(BLECommand::SYSTEM_ERROR);
        }
    }

}
