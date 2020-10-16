#include "blepacketdelaycommand.h"
#include "airboxfiletransferservice.h"

BLEPacketDelayCommand::BLEPacketDelayCommand(const QByteArray & data): BLECommand(BLECommand::PACKET_DELAY)
{
    ERRORS ret = Check(data);
    if(ret == SUCCESS)
    {
        if(data.count() == 3)
        {
            QByteArray part = data.mid(1,2);
            QDataStream streamData(&part, QIODevice::ReadOnly);
            streamData >> mPacketDelay;
            qDebug() <<  Q_FUNC_INFO << "Packet Delay Set: " << mPacketDelay;
        }
        else {
            SetError(BAD_PARAMETERS);

        }
    }
}

void BLEPacketDelayCommand::Process(AirboxFileTransferService & transferService)
{
    transferService.SetPacketDelay(mPacketDelay);
}
