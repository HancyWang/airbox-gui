#include "blesetlogtypecommand.h"
#include "airboxfiletransferservice.h"

BLESetLogTypeCommand::BLESetLogTypeCommand(const QByteArray & data): BLECommand(BLECommand::SET_TYPE)
{
    ERRORS ret = Check(data);
    if(ret == SUCCESS)
    {
        if(data.count() > 1)
        {
            mLogType = QString(data.mid(1,data.length()-1));
            qDebug() <<  Q_FUNC_INFO << "Log Type Set: " << mLogType;
        }
        else {
            SetError(BAD_PARAMETERS);
        }
    }
}

void BLESetLogTypeCommand::Process(AirboxFileTransferService & transferService)
{
    transferService.SetLogType(mLogType);
}
