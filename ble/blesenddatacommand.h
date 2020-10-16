#ifndef BLESENDDATACOMMAND_H
#define BLESENDDATACOMMAND_H
#include "blecommand.h"

class AirboxFileTransferService;

class BLESendDataCommand: public BLECommand
{
public:
    BLESendDataCommand(const QByteArray & data);

    virtual void Process(AirboxFileTransferService & transferService);

    uint32_t GetFileSize()
    {
        return mFileSize;
    }

private:
    uint32_t mFileSize = 0;
};


#endif // BLESENDDATACOMMAND_H
