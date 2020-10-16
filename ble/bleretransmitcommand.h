#ifndef BTCOMMAND_RETRANSMIT_H
#define BTCOMMAND_RETRANSMIT_H
#include <QByteArray>
#include <QDateTime>
#include "blecommand.h"

class AirboxFileTransferService;

class BLERetransmitCommand : public BLECommand
{
public:
    BLERetransmitCommand(const QByteArray & data);

    virtual void Process(AirboxFileTransferService & transferService);

    uint32_t GetPacketNumber()
    {
        return mPacketNumber;
    }


private:
    uint32_t mPacketNumber = 0;
    bool mIsReceiveResend = false;
};

#endif // BTCOMMAND_RETRANSMIT_H
