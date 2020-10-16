#ifndef BTCOMMAND_RETRIEVE_H
#define BTCOMMAND_RETRIEVE_H
#include <QByteArray>
#include <QDateTime>
#include <QDir>
#include "blecommand.h"

class AirboxFileTransferService;

class BLERetrieveCommand : public BLECommand
{
public:
    BLERetrieveCommand(const QByteArray & data);

    virtual void Process(AirboxFileTransferService & transferService);

    QDateTime & GetStartDate()
    {
        return mStartDate;
    }

    QDateTime & GetEndDate()
    {
        return mEndDate;
    }


private:
    QDateTime mStartDate,mEndDate;
};

#endif // BTCOMMAND_RETRIEVE_H
