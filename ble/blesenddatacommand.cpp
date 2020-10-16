#include "blesenddatacommand.h"
#include "airboxfiletransferservice.h"

BLESendDataCommand::BLESendDataCommand(const QByteArray & data): BLECommand(BLECommand::SEND_DATA)
{
    ERRORS ret = Check(data);
    if(ret == SUCCESS)
    {
        if(data.count() == 5)
        {
            QByteArray part = data.mid(1,4);
            QDataStream streamData(&part, QIODevice::ReadOnly);
            streamData >> mFileSize;
        }
        else {
            SetError(BAD_PARAMETERS);

        }
    }
}

void BLESendDataCommand::Process(AirboxFileTransferService & transferService)
{
    if(transferService.IsTransferring() || transferService.IsReceivingTransfer())
    {
        SetError(BLECommand::INCORRECT_STATE);
    }
    else
    {
        transferService.StopTransfer();
        transferService.GetCurrentFile().setFileName(transferService.FRESCA_RECIEVE_FIRMWARE_FILE);
        if (transferService.GetCurrentFile().open(QIODevice::WriteOnly| QIODevice::Unbuffered))
        {
            transferService.SetReceivingTransfer(true);
            transferService.SetPacketCount(GetFileSize() / transferService.GetPacketSize());
            transferService.SetFileStream();
            transferService.SetPacketCounter(0);
        }
        else
        {
            SetError(BLECommand::SYSTEM_ERROR);
        }
    }

}
