#include "bleretransmitcommand.h"
#include "airboxfiletransferservice.h"
#include <QDataStream>
#include <QFile>

BLERetransmitCommand::BLERetransmitCommand(const QByteArray & data): BLECommand(BLECommand::RETRANSMIT_PACKET)
{
    ERRORS ret = Check(data);
    if(ret == SUCCESS)
    {
        if(data.count() == 1)
        {
            mIsReceiveResend = true;
        }
        else if(data.count() == 5)
        {
            QByteArray part = data.mid(1,4);
            QDataStream streamData(&part, QIODevice::ReadOnly);
            streamData >> mPacketNumber;
        }
        else {
            SetError(BAD_PARAMETERS);

        }
    }
}

void BLERetransmitCommand::Process(AirboxFileTransferService & transferService)
{
    transferService.GetCurrentFile().setFileName(transferService.FRESCA_TRANSMIT_ARCHIVE_FILE);

    if(!transferService.IsTransferring() && !transferService.IsReceivingTransfer())
    {
        SetError(BLECommand::INCORRECT_STATE);
    }
    else if(mIsReceiveResend)
    {
        if(transferService.IsReceivingTransfer() && (transferService.GetMissedPackets().count() > 0))
        {
            QByteArray dataArray;
            dataArray.setNum(transferService.GetMissedPackets().first());
            transferService.SendData(dataArray);
            char data[transferService.GetPacketSize()];

        }
        else
        {
            SetError(BLECommand::INCORRECT_STATE);
        }
    }
    else if (transferService.GetCurrentFile().open(QIODevice::ReadOnly))
    {
        uint32_t packetPosition = GetPacketNumber() * transferService.GetPacketSize();
         //TODO:  Make a packet size stream routine
        if(packetPosition >= 100000)
        {
            SetError(BLECommand::BAD_PARAMETERS);
        }
        else
        {
            char data[transferService.GetPacketSize()];
            QDataStream * dataStream = new QDataStream(&transferService.GetCurrentFile());
            dataStream ->skipRawData(packetPosition);
            int ret = dataStream ->readRawData(data,transferService.GetPacketSize() );
            if(ret > 0)
            {
                QByteArray dataArray;
                dataArray.setNum(transferService.GetPacketCounter());
                dataArray.append(data,ret);

                transferService.SendData(dataArray);
            }
            else
            {
                SetError(BLECommand::BAD_PARAMETERS);
            }
            if(dataStream  != NULL)
            {
                delete dataStream ;
            }
        }
    }
    else
    {
        SetError(BLECommand::SYSTEM_ERROR);
    }

}
