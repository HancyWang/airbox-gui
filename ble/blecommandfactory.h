#ifndef BTCOMMANDFACTORY_H
#define BTCOMMANDFACTORY_H

#include "blecommand.h"
#include "bleretrievecommand.h"
#include "blecancelcommand.h"
#include "bleretransmitcommand.h"
#include "blesenddatacommand.h"
#include "blepacketdelaycommand.h"
#include "blesetlogtypecommand.h"

class BLECommandFactory
{
public:

    BLECommandFactory()
    {
    }

    BLECommand * CreateCommand(const QByteArray & data)
    {
        if(data.count() <= 0)
            return new BLECommand();

        switch(data[0])
        {
            case BLECommand::RETRIEVE_DATA_CMD:
                return new BLERetrieveCommand(data);
            case BLECommand::CANCEL_TRANSFER:
                return new BLECancelCommand(data);
            case BLECommand::RETRANSMIT_PACKET:
                return new BLERetransmitCommand(data);
            case BLECommand::SEND_DATA:
                return new BLESendDataCommand(data);
            case BLECommand::PACKET_DELAY:
                return new BLEPacketDelayCommand(data);
            case BLECommand::SET_TYPE:
                return new BLESetLogTypeCommand(data);
            default:
                return new BLECommand();
        }
    }
};

#endif // BTCOMMANDFACTORY_H
