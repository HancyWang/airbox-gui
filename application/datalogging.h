#ifndef DATALOGGING_H
#define DATALOGGING_H

#include <QObject>
#include <QDir>
#include <QTimer>
#include <QTime>

#include "application.h"
#include "logging/edfgenerator.h"

enum {
    EVENT_DATA_EVENT=1,
    EVENT_DATA_USAGE_PARAMETER
};

enum IPC_DATA_LOGGING_Type{
    IPC_DATA_LOG_LEAK=1,
    IPC_DATA_LOG_FLOW,
    IPC_DATA_LOG_PRESSURE_MON,
    IPC_DATA_LOG_PRESSURE_SET,
    IPC_DATA_LOG_EVENT_FLOW_FILTERED,
    IPC_DATA_LOG_EVENT_FLOW_FILTERED_OFFSET,
    IPC_DATA_LOG_FLOW_OFFSET,
    IPC_DATA_LOG_MAX_DATA
};

#define DATA_LOGGING_INTERVAL       40

class DataValidation;
class BackgroundWindow;

class DataLogging : public QObject
{
    Q_OBJECT

public:
    explicit DataLogging(BackgroundWindow *parent,
                         DataValidation * dataValidationBackend);
    ~DataLogging();

    int edfFileHandle;

//    QFile * lrdParam;
//    QFile * hrdParam;
//    QFile * eveParam;
//    QFile * setParam;

//    QDir dir;
//    QFile lrdParam;
//    QFile hrdParam;
//    QFile eveParam;
//    QFile setParam;
//    QFile therapyDetailsFile;
//    QString therapyTimeStamp;


    unsigned int sdcardSize=0;

    int logParam[IPC_DATA_LOG_MAX_DATA];
//    unsigned int logParam[IPC_DATA_LOG_MAX_DATA];

    unsigned int lrdPacketCount=0;
    unsigned int hrdPacketCount=0;
    unsigned int evePacketCount=0;
//    unsigned int eventId=0;
//    unsigned int prevEventId=0;
    bool vLogLrdData=false;
    bool vLogUsageData=false;

    unsigned int eventId1=0;
    unsigned int eventId3=0;
    unsigned int prevEventId1=0;
    unsigned int prevEventId3=0;

    void createLastLoggedDataEdf(void);
    bool copyDirRecursive(QString & srcDirectory,QString & dstDirectory, bool replaceOnConflit);
    void logHrdData(void);
    void logLrdData(void);
    void logSetData(void);
    void logEveData(unsigned int eventId,int dataType);
    void generateEdfFiles(void);

    void generateLrdEdfFile(void);
    void generateHrdEdfFile(void);
    void generateEventEdfFile(void);
    void generateSettingsEdfFile(void);
    void removeCacheFiles(void);
    void createCacheFiles(void);
    unsigned int getTotalLinesInAFiles(QFile * localFile);

    static const unsigned long crc_table[256];
    unsigned long crc32(unsigned long crc,const char *buf,unsigned int len);
    unsigned long getFileCrc32(const QString & fileName);

    unsigned long lrdFileCRC=0;
    unsigned long hrdFileCRC=0;
    unsigned long eveFileCRC=0;
    unsigned long setFileCRC=0;
    unsigned int ipcTherapyIndexCount=0;
    unsigned int blowerOnTime=0;
    unsigned int blowerOnTimeWithoutEvent=0;
//    unsigned int machineUsageTime=0;
//    unsigned int eventStartTime=0;
//    unsigned int eventStopTime=0;
//    unsigned int totalEventActiveTime=0;
    void generateCRCFile(void);


    void logMachineOnTimeAndUsageTime(void);
    void logEventRelatedData(void);


    bool isSdCardAvailable=false;
    void copyLocalFilesToLogDirectory(void);

    void renameTextFiles(const QString & sourceName,const QString & dstName);

signals:
    void writeDeviceLifeDataToEeprom(void);

    void updateSdCardStatus(bool state);

public slots:
    void lrdTimerTimeout();
    void checkSdCardExistTimerTimeout();
    void copyDataTimerTimeout();
    void secondsTimerTimeout();

    void therapyStartFilesProcess(void);
    void therapyStopFilesProcess(void);

    void getSleepReportData(int tSleepReportType,sendSleepReportParam sleepReportDuration,const QFileInfoList & list,int index,
                            float * tUsageHours,float * tEventsPerHour,float * tLeakage,
                            int * usedHours4PlusIndex,int * usedDaysIndex,float * tAverageUsage);
    void getDataForOneDay(int tSleepReportType,const QFileInfoList & list,QString & tPrevDateStr,QString & tTodayDateStr,int index,
                            float * tUsageHours,float * tEventsPerHour,float * tLeakage);

    void copyDataToSDCard(void);

    void addParamToSpecificFiles(int * data);

    void updateEventFromPru(unsigned int event1,unsigned int event3);

    void datalogInitProcedures();

    void startSdCardDetectionTimer(void);

private:
    BackgroundWindow *backgroundScreen;
    DataValidation * dataValidation;
    QThread * m_Thread;

    EdfGenerator * generateEdf;
    QTimer * lrdTimer;
    QTimer * checkSdExistTimer;
    QTimer * secondsTimer;
    QTimer * copyDataTimer;

    QDir runningTherapyDir;
    QFile * lrdParam;
    QFile * hrdParam;
    QFile * eveParam;
    QFile * setParam;
    QFile * therapyDetailsFile;
    QString * therapyTimeStamp;

};

#endif // DATALOGGING_H
