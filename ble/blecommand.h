#ifndef BTCOMMAND_H
#define BTCOMMAND_H
#include <QByteArray>

class AirboxFileTransferService;

class BLECommand
{

public:
    enum COMMANDS
    {
        NONE_CMD = 0,
        RETRIEVE_DATA_CMD=1,
        RETRANSMIT_PACKET=2,
        SEND_DATA=3,
        CANCEL_TRANSFER=4,
        PACKET_DELAY=5,
        SET_TYPE = 6,
    };

    enum ERRORS
    {
        SUCCESS = 0,
        UNKNOWN_COMMAND =1,
        BAD_PARAMETERS =2,
        SYSTEM_ERROR=3,
        DATA_NOT_AVAILABLE = 4,
        INCORRECT_STATE = 5,
    };

    virtual void Process(AirboxFileTransferService & transferService);

    BLECommand(COMMANDS command)
    {
        mCommandId = command;
        mReturnValue.append(SUCCESS);
    }

    BLECommand()
    {
        mCommandId = NONE_CMD;
        mReturnValue.append(UNKNOWN_COMMAND);
    }

    COMMANDS GetId()
    {
        return mCommandId;
    }

    QByteArray & GetReturnBuffer()
    {
        return mReturnValue;
    }

    void SetError(ERRORS error)
    {
        mReturnValue[0] = error;
    }

    ERRORS GetError()
    {
        return (ERRORS)(char)mReturnValue[0];
    }

    void AddReturnData(const QByteArray & data)
    {
        mReturnValue.append(data);
    }

    ERRORS Check(const QByteArray & data)
    {
        if(data.count() <= 0)
        {
            SetError(UNKNOWN_COMMAND);
        }

        if(data[0] != mCommandId)
        {
            SetError(UNKNOWN_COMMAND);
        }
        return GetError();
    }

private:
    COMMANDS mCommandId;
    QByteArray mReturnValue;
};

#endif // BTCOMMAND_H
