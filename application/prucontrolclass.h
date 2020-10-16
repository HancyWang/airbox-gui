#ifndef PRUCONTROLCLASS_H
#define PRUCONTROLCLASS_H


#include <QObject>
#include <QFile>
#include <QTimer>
#include <QThread>
#include <shareddata.h>


class DataLogging;

class PruControlClass : public QObject
{
    Q_OBJECT
public:
    explicit PruControlClass(QObject *parent,DataLogging * m_DataBackend);
    ~PruControlClass();

    QTimer * ipcReadTimer;

    int * pruMemory;

    void powerOnUpdateSettings(void);

    void updateTherapyScreen(void);

    int getSetPressureAsPerState(int tTherapyPeriod);

    void parseFaultCodes(void);

signals:
    void addParamToSpecificFiles(int * data);

    void updateEventToDataLogger(unsigned int event1,unsigned int event3);

    void sendTunningParameterToPRU(void);

    void processGotoSleepRampRuntime(void);

    void updateStartStopTherapyDetails(void);

    void autoStartDetected(void);

    void updateReferenceWindowParameter(int referenceWindowData);

    void updateCurrentWindowParameter(int currentWindowData);

    void updatePressureSensorOffset(int offset);

    void updateScreenAsPerReceivedPacket(unsigned int * localBuf);

    void updateAndShowScreen(int * tArray,int tCount);

    void updateFlowParameter(int flowData);
    void updateEventTypeStatus(unsigned int event);
    void updateStableStatus(unsigned int tStableFlag);
    void updateMaskLeakStatus(unsigned int tLeakState);
    void updateEnableApap(unsigned int tEnFlag);
    void updateHypoApneaCount(unsigned int tCount);
    void updatebreathCount(int count);
    void updateLeakageCount(int count);

public slots:
    void ipcReadTimerTimeOutSlot();

    void initPruControl(void);

    void beforeManufacturingModeProcedure(int manuFactMode,int blowerState,int blowerSpeed);

    void startPruProcessing(void);

    void beforeSnoozeProcedure(int state);

    void beforeStartTherapyProcedure(void);

    void updateTunningParameter(int * param);

    void beforePressureOffsetGetProcedure(void);

    void pruProcessorStartStopProcess(int pruNo,const QString & programmFileStr,bool processorState);

private:
    DataLogging * m_DataManager;
    QThread * m_Thread;

    int drv8308_error=0;
    int mcp3202_error=0;
    int mcp3204_error=0;
    int flow_sensor_error=0;
    int i2c1_bus_error=0;
};

#endif // PRUCONTROLCLASS_H
