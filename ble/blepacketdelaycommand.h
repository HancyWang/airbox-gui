#ifndef BLEPACKETDELAYCOMMAND_H
#define BLEPACKETDELAYCOMMAND_H
#include "blecommand.h"

class AirboxFileTransferService;

class BLEPacketDelayCommand : public BLECommand
{
public:
    BLEPacketDelayCommand(const QByteArray & data);

    virtual void Process(AirboxFileTransferService & transferService);

    uint16_t GetPacketDelay()
    {
        return mPacketDelay;
    }
private:
    quint16 mPacketDelay;
};

#endif // BLEPACKETDELAYCOMMAND_H
