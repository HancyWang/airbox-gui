#ifndef BTCOMMAND_CANCEL_H
#define BTCOMMAND_CANCEL_H
#include <QByteArray>
#include <QDateTime>
#include "blecommand.h"

class AirboxFileTransferService;

class BLECancelCommand: public BLECommand
{
public:
    BLECancelCommand(const QByteArray & data);

    virtual void Process(AirboxFileTransferService & transferService);

private:
};

#endif // BTCOMMAND_CANCEL_H
