#include "blecancelcommand.h"
#include "airboxfiletransferservice.h"

BLECancelCommand::BLECancelCommand(const QByteArray & data): BLECommand(BLECommand::CANCEL_TRANSFER)
{
}

void BLECancelCommand::Process(AirboxFileTransferService & transferService)
{
    if(!transferService.IsTransferring() && !transferService.IsReceivingTransfer())
    {
        SetError(BLECommand::INCORRECT_STATE);
        return;
    }
    transferService.StopTransfer();
}
