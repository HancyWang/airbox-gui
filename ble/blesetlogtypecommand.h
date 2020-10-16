#ifndef BLESETLOGTYPE_H
#define BLESETLOGTYPE_H
#include <QString>

#include "blecommand.h"

class BLESetLogTypeCommand : public BLECommand
{
private:
    QString mLogType;
public:
    BLESetLogTypeCommand(const QByteArray & data);
    virtual void Process(AirboxFileTransferService & transferService);

};

#endif // BLESETLOGTYPE_H
