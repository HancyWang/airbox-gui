#include "datalogging.h"
#include "ex_variables.h"

/*
 * ********************************************************************************
 * LOG FREQ     --> 40 ms
 * IPC Packet   --> Leak/Flow/Pressure
 * ********************************************************************************
 * YYYYMMDD_HHMMSSL.edf
 * YYYYMMDD_HHMMSSL.crc
 * LRD File --> 1 Samp/Sec -->Leak/Therapy Pressure
 * ********************************************************************************
 * YYYYMMDD_HHMMSSH.edf
 * YYYYMMDD_HHMMSSH.crc
 * HRD File --> 25 Samp/Sec --> Flow/Pressure
 * ********************************************************************************
 * YYYYMMDD_HHMMSSE.edf
 * YYYYMMDD_HHMMSSE.crc
 * Eve File --> 25 Samp/Sec --> Event Id
 * ********************************************************************************
 * YYYYMMDD_HHMMSSS.edf
 * YYYYMMDD_HHMMSSS.crc
 * Settings File --> Therapy Start --> Max Pressure/Min Pressure/Comfort State/
 *                                      Comfort Level/Ramp Time/Go to sleep Time/
 *                                      Auto Therapy/Tube Type/Mask Type
 * ********************************************************************************
 *
 * We can reproduce the CRC-32 from online tool on website
 * https://emn178.github.io/online-tools/crc32_checksum.html
 *
 */

//#define LOCAL_LOG_FILE_PATH     "/home/root/LOCAL"

//#define LOG_FILE_PATH           "/home/root/LOG"

//#define LOG_FILE_PATH       "/run/media/mmcblk0p1/GENERATED_LOG"


const unsigned long DataLogging::crc_table[256] = {
  0x00000000L, 0x77073096L, 0xee0e612cL, 0x990951baL, 0x076dc419L,
  0x706af48fL, 0xe963a535L, 0x9e6495a3L, 0x0edb8832L, 0x79dcb8a4L,
  0xe0d5e91eL, 0x97d2d988L, 0x09b64c2bL, 0x7eb17cbdL, 0xe7b82d07L,
  0x90bf1d91L, 0x1db71064L, 0x6ab020f2L, 0xf3b97148L, 0x84be41deL,
  0x1adad47dL, 0x6ddde4ebL, 0xf4d4b551L, 0x83d385c7L, 0x136c9856L,
  0x646ba8c0L, 0xfd62f97aL, 0x8a65c9ecL, 0x14015c4fL, 0x63066cd9L,
  0xfa0f3d63L, 0x8d080df5L, 0x3b6e20c8L, 0x4c69105eL, 0xd56041e4L,
  0xa2677172L, 0x3c03e4d1L, 0x4b04d447L, 0xd20d85fdL, 0xa50ab56bL,
  0x35b5a8faL, 0x42b2986cL, 0xdbbbc9d6L, 0xacbcf940L, 0x32d86ce3L,
  0x45df5c75L, 0xdcd60dcfL, 0xabd13d59L, 0x26d930acL, 0x51de003aL,
  0xc8d75180L, 0xbfd06116L, 0x21b4f4b5L, 0x56b3c423L, 0xcfba9599L,
  0xb8bda50fL, 0x2802b89eL, 0x5f058808L, 0xc60cd9b2L, 0xb10be924L,
  0x2f6f7c87L, 0x58684c11L, 0xc1611dabL, 0xb6662d3dL, 0x76dc4190L,
  0x01db7106L, 0x98d220bcL, 0xefd5102aL, 0x71b18589L, 0x06b6b51fL,
  0x9fbfe4a5L, 0xe8b8d433L, 0x7807c9a2L, 0x0f00f934L, 0x9609a88eL,
  0xe10e9818L, 0x7f6a0dbbL, 0x086d3d2dL, 0x91646c97L, 0xe6635c01L,
  0x6b6b51f4L, 0x1c6c6162L, 0x856530d8L, 0xf262004eL, 0x6c0695edL,
  0x1b01a57bL, 0x8208f4c1L, 0xf50fc457L, 0x65b0d9c6L, 0x12b7e950L,
  0x8bbeb8eaL, 0xfcb9887cL, 0x62dd1ddfL, 0x15da2d49L, 0x8cd37cf3L,
  0xfbd44c65L, 0x4db26158L, 0x3ab551ceL, 0xa3bc0074L, 0xd4bb30e2L,
  0x4adfa541L, 0x3dd895d7L, 0xa4d1c46dL, 0xd3d6f4fbL, 0x4369e96aL,
  0x346ed9fcL, 0xad678846L, 0xda60b8d0L, 0x44042d73L, 0x33031de5L,
  0xaa0a4c5fL, 0xdd0d7cc9L, 0x5005713cL, 0x270241aaL, 0xbe0b1010L,
  0xc90c2086L, 0x5768b525L, 0x206f85b3L, 0xb966d409L, 0xce61e49fL,
  0x5edef90eL, 0x29d9c998L, 0xb0d09822L, 0xc7d7a8b4L, 0x59b33d17L,
  0x2eb40d81L, 0xb7bd5c3bL, 0xc0ba6cadL, 0xedb88320L, 0x9abfb3b6L,
  0x03b6e20cL, 0x74b1d29aL, 0xead54739L, 0x9dd277afL, 0x04db2615L,
  0x73dc1683L, 0xe3630b12L, 0x94643b84L, 0x0d6d6a3eL, 0x7a6a5aa8L,
  0xe40ecf0bL, 0x9309ff9dL, 0x0a00ae27L, 0x7d079eb1L, 0xf00f9344L,
  0x8708a3d2L, 0x1e01f268L, 0x6906c2feL, 0xf762575dL, 0x806567cbL,
  0x196c3671L, 0x6e6b06e7L, 0xfed41b76L, 0x89d32be0L, 0x10da7a5aL,
  0x67dd4accL, 0xf9b9df6fL, 0x8ebeeff9L, 0x17b7be43L, 0x60b08ed5L,
  0xd6d6a3e8L, 0xa1d1937eL, 0x38d8c2c4L, 0x4fdff252L, 0xd1bb67f1L,
  0xa6bc5767L, 0x3fb506ddL, 0x48b2364bL, 0xd80d2bdaL, 0xaf0a1b4cL,
  0x36034af6L, 0x41047a60L, 0xdf60efc3L, 0xa867df55L, 0x316e8eefL,
  0x4669be79L, 0xcb61b38cL, 0xbc66831aL, 0x256fd2a0L, 0x5268e236L,
  0xcc0c7795L, 0xbb0b4703L, 0x220216b9L, 0x5505262fL, 0xc5ba3bbeL,
  0xb2bd0b28L, 0x2bb45a92L, 0x5cb36a04L, 0xc2d7ffa7L, 0xb5d0cf31L,
  0x2cd99e8bL, 0x5bdeae1dL, 0x9b64c2b0L, 0xec63f226L, 0x756aa39cL,
  0x026d930aL, 0x9c0906a9L, 0xeb0e363fL, 0x72076785L, 0x05005713L,
  0x95bf4a82L, 0xe2b87a14L, 0x7bb12baeL, 0x0cb61b38L, 0x92d28e9bL,
  0xe5d5be0dL, 0x7cdcefb7L, 0x0bdbdf21L, 0x86d3d2d4L, 0xf1d4e242L,
  0x68ddb3f8L, 0x1fda836eL, 0x81be16cdL, 0xf6b9265bL, 0x6fb077e1L,
  0x18b74777L, 0x88085ae6L, 0xff0f6a70L, 0x66063bcaL, 0x11010b5cL,
  0x8f659effL, 0xf862ae69L, 0x616bffd3L, 0x166ccf45L, 0xa00ae278L,
  0xd70dd2eeL, 0x4e048354L, 0x3903b3c2L, 0xa7672661L, 0xd06016f7L,
  0x4969474dL, 0x3e6e77dbL, 0xaed16a4aL, 0xd9d65adcL, 0x40df0b66L,
  0x37d83bf0L, 0xa9bcae53L, 0xdebb9ec5L, 0x47b2cf7fL, 0x30b5ffe9L,
  0xbdbdf21cL, 0xcabac28aL, 0x53b39330L, 0x24b4a3a6L, 0xbad03605L,
  0xcdd70693L, 0x54de5729L, 0x23d967bfL, 0xb3667a2eL, 0xc4614ab8L,
  0x5d681b02L, 0x2a6f2b94L, 0xb40bbe37L, 0xc30c8ea1L, 0x5a05df1bL,
  0x2d02ef8dL
};


#include <QTimer>
#include <QFile>
#include <QDir>
#include <QStorageInfo>
#include "screens/backgroundwindow.h"

DataLogging::DataLogging(BackgroundWindow *parent,
                         DataValidation * dataValidationBackend)
    : QObject(),
    backgroundScreen(parent),
    dataValidation(dataValidationBackend),
    m_Thread(nullptr),
    generateEdf(nullptr),
    lrdTimer(nullptr),
    checkSdExistTimer(nullptr),
    secondsTimer(nullptr),
    copyDataTimer(nullptr),
    lrdParam(nullptr),
    hrdParam(nullptr),
    eveParam(nullptr),
    setParam(nullptr),
    therapyDetailsFile(nullptr),
    therapyTimeStamp(nullptr)
{
    m_Thread = new QThread;
    m_Thread->setObjectName("DataLogging");
    connect(m_Thread,SIGNAL(started()),this,SLOT(datalogInitProcedures()));
    moveToThread(m_Thread);
    m_Thread->start();
}

DataLogging::~DataLogging()
{
    if(m_Thread)
        m_Thread->exit();

    connect(m_Thread,SIGNAL(finished()),m_Thread,SLOT(deleteLater()));
    connect(m_Thread,SIGNAL(finished()),lrdTimer,SLOT(deleteLater()));
    connect(m_Thread,SIGNAL(finished()),secondsTimer,SLOT(deleteLater()));
    connect(m_Thread,SIGNAL(finished()),copyDataTimer,SLOT(deleteLater()));
    connect(m_Thread,SIGNAL(finished()),checkSdExistTimer,SLOT(deleteLater()));

    delete generateEdf;
    delete lrdParam;
    delete hrdParam;
    delete eveParam;
    delete setParam;
    delete therapyDetailsFile;
    delete therapyTimeStamp;
}

void DataLogging::datalogInitProcedures()
{
    if(dataValidation)
    {
        connect(this,SIGNAL(writeDeviceLifeDataToEeprom()),
                dataValidation,SLOT(writeDeviceLifeDataToEeprom()));
    }

    if(backgroundScreen)
    {
        connect(backgroundScreen,SIGNAL(startSdCardDetectionTimer()),
                this,SLOT(startSdCardDetectionTimer()));
    }

    generateEdf = new EdfGenerator();

    lrdTimer = new QTimer;
    connect(lrdTimer, SIGNAL(timeout()), this, SLOT(lrdTimerTimeout()));

    checkSdExistTimer = new QTimer;
    connect(checkSdExistTimer, SIGNAL(timeout()), this, SLOT(checkSdCardExistTimerTimeout()));

    secondsTimer = new QTimer;
    connect(secondsTimer, SIGNAL(timeout()), this, SLOT(secondsTimerTimeout()));

    copyDataTimer = new QTimer;
    copyDataTimer->setSingleShot(true);
    connect(copyDataTimer, SIGNAL(timeout()), this, SLOT(copyDataTimerTimeout()));

    lrdParam = new QFile;
    hrdParam = new QFile;
    eveParam = new QFile;
    setParam = new QFile;
    therapyDetailsFile = new QFile;
    therapyTimeStamp = new QString;
}

void DataLogging::createLastLoggedDataEdf(void)
{
    QString localName;
    localName = QString("%1/LRD.txt").arg(Providers::getLocalLogFilesPath());
    lrdParam->setFileName(localName);

    localName = QString("%1/HRD.txt").arg(Providers::getLocalLogFilesPath());
    hrdParam->setFileName(localName);

    localName = QString("%1/EVE.txt").arg(Providers::getLocalLogFilesPath());
    eveParam->setFileName(localName);

    localName = QString("%1/SET.txt").arg(Providers::getLocalLogFilesPath());
    setParam->setFileName(localName);

    localName = QString("%1/last_therapy.txt").arg(Providers::getLocalLogFilesPath());
    therapyDetailsFile->setFileName(localName);

    if(therapyDetailsFile->exists() == true)
    {
        if(therapyDetailsFile->open(QIODevice::ReadOnly) == true)
        {
            QString therapyTime;
            therapyTime = therapyDetailsFile->readLine();
            therapyTime.remove(QRegExp("[\\n\\t\\r]"));
            *therapyTimeStamp = therapyTime;
            qDebug() << "Last time stamp" << therapyTimeStamp;
            therapyDetailsFile->close();

            therapyStopFilesProcess();
        }
    }
}

void DataLogging::startSdCardDetectionTimer(void)
{
    checkSdExistTimer->start(500);

    /* Create EDF files if previous data is still pending */
    createLastLoggedDataEdf();
}

void DataLogging::checkSdCardExistTimerTimeout()
{
    QStorageInfo storage(Providers::getSdcardEdfLogFilesPath());

    if (storage.isValid() && storage.isReady())
    {
        /* If sdcard available
         * Show sdcard icon on notification bar
         */
        if(isSdCardAvailable == false)
        {
            qDebug() << "Sdcard Connected";
            emit updateSdCardStatus(true);
            copyDataTimer->start(2000);
            isSdCardAvailable = true;
            qDebug() << Q_FUNC_INFO << storage.name() << storage.isValid() << storage.isReady();
        }
    }
    else
    {
        if(isSdCardAvailable == true)
        {
            isSdCardAvailable = false;
            qDebug() << "Sdcard disconnected";
            emit updateSdCardStatus(false);
        }
    }
}

void DataLogging::copyDataTimerTimeout()
{
    /* Check if previous data exist */
    QDir checkDir(Providers::getSdcardEdfLogFilesPath());
    QFileInfoList directorList;

    qDebug() << "Sdcard file copy";

//    if(checkDir.exists()){
//        qDebug() << "Sdcard path exists";
//        directorList = checkDir.entryInfoList(QDir::NoDotAndDotDot|QDir::AllEntries,QDir::Name);
//        if(directorList.length()){
//            qDebug() << "Sdcard contains files" << directorList.length();
//            for(int i=0;i< directorList.length() ; i++){
//                qDebug() << i << directorList.at(i).filePath();
//            }
////            /* Show warning to format sdcard & then insert again */
////            Providers::pBackgroundScreen->sdCardFormatScreen->parentEffect = Providers::pBackgroundScreen->getAndEnableBackgoundColorEffect();;
////            Providers::pBackgroundScreen->sdCardFormatScreen->setModal(true);
////            Providers::pBackgroundScreen->sdCardFormatScreen->show();

//            /* exit from function because user must enter
//             * formatted sd card
//             */
//            return;
//        }
//    }

    /* Copy all the data to LOG directory */
    copyDataToSDCard();
}


void DataLogging::copyLocalFilesToLogDirectory(void)
{
    /* Start copying temporary text files from local directory to log directory */
    bool copyStatus=false;
    QString srcPath = Providers::getLocalLogFilesPath();
    QString dstPath = Providers::getEdfLogFilesPath() + "/" + therapyTimeStamp;
    copyStatus = copyDirRecursive(srcPath,dstPath,true);
    if(copyStatus == false){
        qDebug() << Q_FUNC_INFO << srcPath << dstPath;
    }

    renameTextFiles(QString("%1/%2/EVE.txt").arg(Providers::getEdfLogFilesPath()).arg(*therapyTimeStamp),
                    QString("%1/%2/%2E.txt").arg(Providers::getEdfLogFilesPath()).arg(*therapyTimeStamp));

    renameTextFiles(QString("%1/%2/HRD.txt").arg(Providers::getEdfLogFilesPath()).arg(*therapyTimeStamp),
                    QString("%1/%2/%2H.txt").arg(Providers::getEdfLogFilesPath()).arg(*therapyTimeStamp));

    renameTextFiles(QString("%1/%2/LRD.txt").arg(Providers::getEdfLogFilesPath()).arg(*therapyTimeStamp),
                    QString("%1/%2/%2L.txt").arg(Providers::getEdfLogFilesPath()).arg(*therapyTimeStamp));

    renameTextFiles(QString("%1/%2/SET.txt").arg(Providers::getEdfLogFilesPath()).arg(*therapyTimeStamp),
                    QString("%1/%2/%2S.txt").arg(Providers::getEdfLogFilesPath()).arg(*therapyTimeStamp));
}

void DataLogging::renameTextFiles(const QString & sourceName,const QString & dstName)
{
    QFile eveFile(sourceName);
    if(eveFile.exists() == true)
    {
        eveFile.rename(dstName);
    }
}

void DataLogging::copyDataToSDCard(void)
{
    if(isSdCardAvailable == false)          return;

    QString srcPath = Providers::getEdfLogFilesPath();
    QString dstPath = Providers::getSdcardEdfLogFilesPath() + "LOG";

    QStorageInfo storage(Providers::getSdcardEdfLogFilesPath());

    if (storage.isValid() && storage.isReady())
    {
        QDir localDir(dstPath);
        if(localDir.exists() == false)
        {
            bool status = localDir.mkpath(dstPath);
            qDebug() << Q_FUNC_INFO << dstPath << status;
        }

    //    QString copyStr = QString("cp -rf %1/* %2/.").arg(srcPath).arg(dstPath);
    //    qDebug() << Q_FUNC_INFO << copyStr;
    //    system(copyStr.toStdString().c_str());

        /* Start copying data from internal to external sdcard */
        bool copyStatus=false;
        copyStatus = copyDirRecursive(srcPath,dstPath,true);
        if(copyStatus == false){
            qCritical() << Q_FUNC_INFO << srcPath << dstPath;
        }
    }
}

bool DataLogging::copyDirRecursive(QString & srcDirectory,QString & dstDirectory, bool replaceOnConflit)
{
    QDir dir;
    dir.setPath(srcDirectory);

    srcDirectory += QDir::separator();
    dstDirectory += QDir::separator();

    foreach (QString copy_file, dir.entryList(QDir::Files))
    {
        QString from = srcDirectory + copy_file;
        QString to = dstDirectory + copy_file;

//        qDebug() << Q_FUNC_INFO << "Files" << from << "==>" << to ;

        if (QFile::exists(to)) {
            if (replaceOnConflit) {
                QFile::setPermissions(to,QFileDevice::WriteOther);
                if (QFile::remove(to) == false) {
                    qCritical() << Q_FUNC_INFO << "Unable to remove file" << from << "==>" << to ;
                    return false;
                }
            } else {
                continue;
            }
        }

        if (QFile::copy(from, to) == false){
            qCritical() << Q_FUNC_INFO << "Unable to copy file" << from << "==>" << to  ;
            return false;
        }
    }

    foreach (QString copy_dir, dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot))
    {
        QString from = srcDirectory + copy_dir;
        QString to = dstDirectory + copy_dir;

//        qDebug() << Q_FUNC_INFO << "Directory" << from << "==>" << to ;

        if (dir.mkpath(to) == false) {
            qCritical() << Q_FUNC_INFO << "Recursively :Unable to makepath" << to  ;
            return false;
        }

        if (copyDirRecursive(from, to, replaceOnConflit) == false) {
            qCritical() << Q_FUNC_INFO << "Recursively :Unable to copy file" << from << "==>" << to  ;
            return false;
        }
    }

return true;
}

void DataLogging::therapyStartFilesProcess(void)
{
//#ifdef _APP_DEVELOPMENT_BUILD
//    QDate buildDate(QDate::fromString(__DATE__,"MMM d yyyy"));
//    QTime buildTime(QTime::fromString(__TIME__,"h:m:s"));
//    QString dateStr = buildDate.toString("yyyyMMdd");
//    QString timeStr = buildTime.toString("hhmmss");
//#elif defined(_APP_PRODUCTION_BUILD)
    QString dateStr = QDate::currentDate().toString("yyyyMMdd");
    QString timeStr= QTime::currentTime().toString("hhmmss");
//#endif

    therapyTimeStamp->clear();
    *therapyTimeStamp = dateStr + "_" + timeStr;

    qDebug() << "Therapy time" << therapyTimeStamp << dateStr << timeStr;

    /* Reset CRC-32 of files */
    lrdFileCRC=0;
    hrdFileCRC=0;
    eveFileCRC=0;
    setFileCRC=0;

    /* Create cache files */
    createCacheFiles();

    /* Create Settings File as it will be changed only once in a therapy */
    logSetData();
    lrdTimer->start(1000);

    secondsTimer->start(1000);

    lrdPacketCount=0;
    hrdPacketCount=0;
    evePacketCount=0;

    ipcTherapyIndexCount=0;
    blowerOnTime =0;
//    machineUsageTime = 0;
    blowerOnTimeWithoutEvent = 0;

    eventId1 = 0;
    eventId3 = 0;
    prevEventId1 = 0;
    prevEventId3 = 0;

    /* Create path for the new Therapy Stat Time */
    QString dirName = QString("%1/%2").arg(Providers::getEdfLogFilesPath()).arg(*therapyTimeStamp);
    runningTherapyDir.setPath(dirName);
    if(runningTherapyDir.exists() == false) {
        runningTherapyDir.mkpath(dirName);
    }

    /* Create a text file which contains last recorded therapy date & time */
}

void DataLogging::therapyStopFilesProcess(void)
{
    /* Stop timers if they are active & running */
    if(lrdTimer->isActive() == true)
        lrdTimer->stop();

    if(secondsTimer->isActive() == true)
        secondsTimer->stop();

    /* Generate EDF Files from raw files */
    generateEdfFiles();

    /* Update used hours value to EEPROM */
    float tUsedMinutes=0;
    tUsedMinutes = blowerOnTimeWithoutEvent/60;
    globalVar.deviceLifeData.totalMinutesOfFlowGeneration += tUsedMinutes;
    globalVar.deviceLifeData.totalHoursFlowGeneration = globalVar.deviceLifeData.totalMinutesOfFlowGeneration / 60;
    emit writeDeviceLifeDataToEeprom();

//    machineUsageTime = 0;
    blowerOnTimeWithoutEvent = 0;

    /* Remove cache files
     * Required for verifying edf generation
     */
//    removeCacheFiles();

    /*TODO Temporary*/
    copyLocalFilesToLogDirectory();

    copyDataToSDCard();
}

void DataLogging::lrdTimerTimeout()
{
    vLogLrdData = true;
}

void DataLogging::updateEventFromPru(unsigned int event1,unsigned int event3)
{
    eventId1 = event1;
    eventId3 = event3;
}

//void DataLogging::addParamToSpecificFiles(unsigned int * data)
void DataLogging::addParamToSpecificFiles(int * data)
{
    if(globalVar.therapyState == On)
    {

        /* Get log parameters to local array */
//        logParam[IPC_DATA_LOG_LEAK] = data[IPC_DATA_LOG_LEAK];
//        logParam[IPC_DATA_LOG_FLOW] = data[IPC_DATA_LOG_FLOW];
//        logParam[IPC_DATA_LOG_PRESSURE_MON] = data[IPC_DATA_LOG_PRESSURE_MON];
//        logParam[IPC_DATA_LOG_PRESSURE_SET] = data[IPC_DATA_LOG_PRESSURE_SET];

        /* Get log parameters to local array */
        memset(logParam,0,sizeof(logParam));
        memcpy(logParam,data,sizeof(logParam));

        /* Log data LOW RESOLUTION DATA log timer timeouts */
        if(vLogLrdData == true) {
            logLrdData();
            vLogLrdData = false;
            lrdPacketCount++;
        }

        /* Log HIGH RESOLUTION DATA */
        logHrdData();
        hrdPacketCount++;

        /* Log EVENT DATA whenever event code changes */
        logEventRelatedData();

        if(vLogUsageData == true){
            vLogUsageData = false;
            logMachineOnTimeAndUsageTime();
        }
    }
}

void DataLogging::secondsTimerTimeout()
{
    if(QTime::currentTime().second() == 0)
        vLogUsageData = true;
    else
        vLogUsageData = false;

    blowerOnTime++;
    if((!eventId1) & (!eventId3))
    {
        blowerOnTimeWithoutEvent++;
    }
}

void DataLogging::logMachineOnTimeAndUsageTime(void)
{
    logEveData(eventId1,EVENT_DATA_USAGE_PARAMETER);
}

void DataLogging::logEventRelatedData(void)
{
    if(eventId1 != prevEventId1)
    {
//        qDebug() << Q_FUNC_INFO << eventId1;
        prevEventId1 = eventId1;
        logEveData(eventId1,EVENT_DATA_EVENT);
    }

    if(eventId3 != prevEventId3)
    {
        prevEventId3 = eventId3;

        int localId=0;
        if(eventId3 == 0)
            localId = EVENT_LEAK_RELEASED;
        else
            localId = eventId3;

        logEveData(localId,EVENT_DATA_EVENT);
    }
}

void DataLogging::logHrdData(void)
{
    if (!hrdParam->open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
        return;

    hrdParam->seek(hrdParam->size());
    QTextStream outStream(hrdParam);

    outStream << QString::number(logParam[IPC_DATA_LOG_FLOW]) << "/" << QString::number(logParam[IPC_DATA_LOG_PRESSURE_MON]) << "\n";

//    outStream << QString::number(logParam[IPC_DATA_LOG_EVENT_FLOW_FILTERED]) << "/"
//                << QString::number(logParam[IPC_DATA_LOG_EVENT_FLOW_FILTERED_OFFSET]) << "/"
//                << QString::number(logParam[IPC_DATA_LOG_FLOW]) << "/"
//                << QString::number(logParam[IPC_DATA_LOG_FLOW_OFFSET]) << "\n";

    hrdParam->close();
}

void DataLogging::logLrdData(void)
{
    if (!lrdParam->open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
        return;

    lrdParam->seek(lrdParam->size());
    QTextStream outStream(lrdParam);

    outStream << QString::number(logParam[IPC_DATA_LOG_LEAK]) << "/" << QString::number(logParam[IPC_DATA_LOG_PRESSURE_SET]) << "\n";
//    outStream << QString::number(logParam[IPC_DATA_LOG_LEAK]) << "/" << QString::number(globalVar.pressure.targetedPressure) << "\n";

    lrdParam->close();
}

void DataLogging::logEveData(unsigned int eventId,int dataType)
{
    if (!eveParam->open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
        return;

//    qDebug() << Q_FUNC_INFO << eventId1 << eventId1 << blowerOnTime << blowerOnTimeWithoutEvent;

    evePacketCount++;
//    qDebug() << "P:" << evePacketCount;

    eveParam->seek(eveParam->size());
    QTextStream outStream(eveParam);

    if(dataType == EVENT_DATA_EVENT)
    {
        outStream << QString::number(QDate::currentDate().year()) << "/" << QString::number(QDate::currentDate().month()) << "/" << QString::number(QDate::currentDate().day()) << "/" <<
                     QString::number(QTime::currentTime().hour()) << "/" << QString::number(QTime::currentTime().minute()) << "/" << QString::number(QTime::currentTime().second()) << "/" <<
                     QString::number(eventId) << "/" << "0" << "\n";
    }
    else if(dataType == EVENT_DATA_USAGE_PARAMETER)
    {
        outStream << QString::number(QDate::currentDate().year()) << "/" << QString::number(QDate::currentDate().month()) << "/" << QString::number(QDate::currentDate().day()) << "/" <<
                     QString::number(QTime::currentTime().hour()) << "/" << QString::number(QTime::currentTime().minute()) << "/" << QString::number(QTime::currentTime().second()) << "/" <<
//                     QString::number(QTime::currentTime().hour()) << "/" << "0" << "/" << "0" << "/" <<
                     QString::number(EVENT_TYPE_BLOWER_ON) << "/" << QString::number(blowerOnTime) << "\n";

        outStream << QString::number(QDate::currentDate().year()) << "/" << QString::number(QDate::currentDate().month()) << "/" << QString::number(QDate::currentDate().day()) << "/" <<
                     QString::number(QTime::currentTime().hour()) << "/" << QString::number(QTime::currentTime().minute()) << "/" << QString::number(QTime::currentTime().second()) << "/" <<
//                     QString::number(QTime::currentTime().hour()) << "/" << "0" << "/" << "1" << "/" <<
                     QString::number(EVENT_TYPE_USAGE_TIME) << "/" << QString::number(blowerOnTimeWithoutEvent) << "\n";
//        QString::number(EVENT_TYPE_USAGE_TIME) << "/" << QString::number(machineUsageTime) << "\n";
    }


    eveParam->close();
}

void DataLogging::logSetData(void)
{
    if (!setParam->open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
        return;

    setParam->seek(setParam->size());
    QTextStream outStream(setParam);

//    QDate todayDate = QDate::fromString(dateString,fileNameFormat);
    QString dateStr = QDate::currentDate().toString("yyyyMMdd");
    QString timeStr = QTime::currentTime().toString("hhmmss");

    QString localSerial = globalVar.serialNumberStr.left(SERIAL_NUMBER_MAX_CHAR);
    QString ModelStr = "A1";

    int comfortLevel=0;
    if(globalVar.comfortLevel.state == true)
        comfortLevel = globalVar.comfortLevel.comfortLevelSet;
    else
        comfortLevel = 0;

    int rampLevel=0;
    if(globalVar.rampTime.state == true)
        rampLevel = globalVar.rampTime.rampTime;
    else
        rampLevel = 0;

    int goToSleepLevel=0;
    if(globalVar.goToSleep.state == true)
        goToSleepLevel = globalVar.goToSleep.goToSleepTime;
    else
        goToSleepLevel = 0;

    int snoozeLevel=0;
    if(globalVar.snooze.state == true)
        snoozeLevel = globalVar.snooze.snoozeTime;
    else
        snoozeLevel = 0;

    int minPressure=0;
    int maxPressure=0;
    if(globalVar.therapyMode == apapMode)
    {
        minPressure = globalVar.pressure.apapMinPressure;
        maxPressure = globalVar.pressure.apapMaxPressure;
    }
    else
    {
        minPressure = 0; //globalVar.pressure.targetedPressure;
        maxPressure = globalVar.pressure.targetedPressure;
    }
	
    int tubeSize = 0;
    if(HOSE_SIZE_MM == 9)
        tubeSize = 1;

    outStream << dateStr << "/"
                << timeStr << "/"
                << ModelStr << "/"
                << localSerial << "/"
                << Providers::getDeviceInformationString(SOFTWARE_VERSION) << "/"
                << QString::number(minPressure) << "/"
                << QString::number(maxPressure) << "/"
                << QString::number(comfortLevel) << "/"
                << QString::number(globalVar.autoStartTherapy) << "/"
                << QString::number(rampLevel) << "/"
                << QString::number(goToSleepLevel) << "/"
                << QString::number(snoozeLevel) << "/"
                << QString::number(tubeSize) << "/"
                << QString::number(globalVar.maskType)
                << "\n";


//    outStream << QString::number(globalVar.pressure.apapMaxPressure) << "/" << QString::number(globalVar.pressure.apapMinPressure)
//              << "/" << QString::number(globalVar.comfortLevel.state) << "/" << QString::number(globalVar.comfortLevel.comfortLevelSet)
//              << "/" << QString::number(globalVar.rampTime.rampTime) << "/" << QString::number(globalVar.goToSleep.goToSleepTime)
//                << "/" << QString::number(globalVar.autoTherapy) << "/" <<
//                   /* TODO Add tube type here */
//                   QString::number(9)
//                << "/" << QString::number(globalVar.maskType)
//                << "\n";

    setParam->close();
}

void DataLogging::generateEdfFiles(void)
{
    if(runningTherapyDir.exists() == true)
    {
        /* Generate LRD File */
        generateLrdEdfFile();

        /* Generate HRD File */
        generateHrdEdfFile();

        /* Generate EVE File */
        generateEventEdfFile();

        /* Generate SET File */
        generateSettingsEdfFile();

        /* Generate CRC File */
        generateCRCFile();
    }
}

void DataLogging::generateCRCFile(void)
{
    QFile crcFile;
    QString fileName = QString("%1/%2/%2C.txt").arg(Providers::getEdfLogFilesPath()).arg(*therapyTimeStamp);
    qDebug() << Q_FUNC_INFO << fileName;
    crcFile.setFileName(fileName);

    /* Open file to write data at the end */
    crcFile.open(QIODevice::WriteOnly|QIODevice::Append);
    QTextStream out(&crcFile);

    unsigned long lrdTxtFileCRC=0;
    unsigned long eveTxtFileCRC=0;
    unsigned long setTxtFileCRC=0;

    /* Generate CRC of text files */
//    hrdFileCRC = getFileCrc32(QString("%1/%2/%2H.txt").arg(Providers::getEdfLogFilesPath()).arg(therapyTimeStamp));
    lrdTxtFileCRC = getFileCrc32(QString("%1/LRD.txt").arg(Providers::getLocalLogFilesPath()));
    eveTxtFileCRC = getFileCrc32(QString("%1/EVE.txt").arg(Providers::getLocalLogFilesPath()));
    setTxtFileCRC = getFileCrc32(QString("%1/SET.txt").arg(Providers::getLocalLogFilesPath()));

    qDebug() << Q_FUNC_INFO << lrdFileCRC << eveFileCRC << setFileCRC;

    /* Write Low Resolution CRC Checksum */
//    out << "LE:0x" << QString::number(lrdFileCRC,16) << "\n";

//    /* Write High Resolution CRC Checksum */
//    out << "HE:0x" << QString::number(hrdFileCRC,16) << "\n";

    /* Write Event CRC Checksum */
//    out << "EE:0x" << QString::number(eveFileCRC,16) << "\n";

    /* Write Settings CRC Checksum */
//    out << "SE:0x" << QString::number(setFileCRC,16) << "\n";

    /* Write Low Resolution CRC Checksum */
    out << "LT:0x" << QString::number(lrdTxtFileCRC,16) << "\n";

//    /* Write High Resolution CRC Checksum */
//    out << "HT:0x" << QString::number(hrdFileCRC,16) << "\n";

    /* Write Event CRC Checksum */
    out << "ET:0x" << QString::number(eveTxtFileCRC,16) << "\n";

    /* Write Settings CRC Checksum */
    out << "ST:0x" << QString::number(setTxtFileCRC,16) << "\n";

    /* Close File */
    crcFile.close();

}

void DataLogging::generateLrdEdfFile(void)
{
    if(lrdParam->exists() == false)
        return;

    lrdPacketCount = getTotalLinesInAFiles(lrdParam);

    /* Open LRD.txt File */
    if (!lrdParam->open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    /* Create dynamic array to read all data from file and
     * store in an array for perticular parameter */
    //TODO Get packet count data when device restarts
    double * pLeakLrdData = new double [lrdPacketCount];
    double * pTherapyPressureLrdData = new double [lrdPacketCount];
    int i=0;
    //TODO set LeakMax temporary need to design Leak algorithm
    double leakMax=1,leakMin=0;
    double therapyPressureMax=0,therapyPressureMin=0;
    QTextStream in(lrdParam);
    QStringList itemList;

    Providers providers;

    /* Process until file reached to its end
     * Parse Leak & Therapy pressure values to an array
     * which will be passed to create EDF file
     */
    while(!in.atEnd()) {

        /* Read each line ended with null character */
        QString line = in.readLine();

        /* Split each line with '/' Separator */
        itemList = line.split('/');

        /* First indexed value is leak parameter
         * store it to leak data array */
        pLeakLrdData[i] = itemList.at(0).toInt();

        /* Convert Flow raw data to engineering */
        pLeakLrdData[i] = providers.getFlowEngineeringValues(pLeakLrdData[i]);

        if(pLeakLrdData[i] > leakMax)       leakMax = pLeakLrdData[i];
        if(pLeakLrdData[i] < leakMin)       leakMin = pLeakLrdData[i];

        /* Second indexed value is Therapy Pressure parameter
         * store it to Therapy Pressure data array */
        pTherapyPressureLrdData[i] = itemList.at(1).toInt();

        /* Convert Pressure raw data to engineering
         * Set pressure will be in multiplication of 100
         */
        pTherapyPressureLrdData[i] = pTherapyPressureLrdData[i]/100;
//        pTherapyPressureLrdData[i] = Providers::getPressureEngineeringValues(pTherapyPressureLrdData[i]);

        if(pTherapyPressureLrdData[i] > therapyPressureMax)       therapyPressureMax = pTherapyPressureLrdData[i];
        if(pTherapyPressureLrdData[i] < therapyPressureMin)       therapyPressureMin = pTherapyPressureLrdData[i];

        i++;
    }

    if(therapyPressureMin == therapyPressureMax)
        therapyPressureMax++;

    if(leakMin == leakMax)
        leakMax++;

    QString fileName = QString("%1/%2/%2L.edf").arg(Providers::getEdfLogFilesPath()).arg(*therapyTimeStamp);
    int totalChannel = 2;

    int digitalDataMax[2];
    digitalDataMax[0] = 32767;
    digitalDataMax[1] = 32767;

    int digitalDataMin[2];
    digitalDataMin[0] = -32768;
    digitalDataMin[1] = -32768;

    double physicalDataMax[2];
    physicalDataMax[0] = leakMax;
    physicalDataMax[1] = therapyPressureMax;

    double physicalDataMin[2];
    physicalDataMin[0] = leakMin;
    physicalDataMin[1] = therapyPressureMin;

    QStringList dimensionList;
//    dimensionList << "lpm" << "cmH2O";
    dimensionList << "lpm" << Providers::getPressureUnitTextString(globalVar.pressureUnit);

    QStringList labelList;
    labelList << "Leak" << "Pressure";

    int samplingFreq=0;
    samplingFreq = 1;

    int totalSamplesCount=0;
    totalSamplesCount = lrdPacketCount;

    /* Create EDF File */
    edfFileHandle = generateEdf->createEdfFile(fileName,totalChannel);

    /* Add Header related data to EDF File */
    generateEdf->generateEdfFile(totalChannel,digitalDataMax,digitalDataMin,
                                 physicalDataMax,physicalDataMin,dimensionList,labelList,
                                 samplingFreq);

    int j=0;
    int arrayIdx=0;
    int durationInSecons=0;
    durationInSecons = (totalSamplesCount/samplingFreq);

    /* NOTE It will discard last second samples to log
     * While therapy stops and receives on 10 samples instead of
     * 25 samples so whether need to log extra 15 samples to specific
     * value which can be misinterpret to reader
     *
     * It will loop for number of seconds therapy will run
     */
    for(j=0; j<durationInSecons; j++) {
        arrayIdx = j * samplingFreq;
        generateEdf->writeEdfLogData(&pLeakLrdData[arrayIdx]);
        generateEdf->writeEdfLogData(&pTherapyPressureLrdData[arrayIdx]);
    }

    /* Close EDF File */
    generateEdf->closeEdfFile(edfFileHandle);

    /* Delete dynamically created array and free memory */
    delete[] pLeakLrdData;
    delete[] pTherapyPressureLrdData;

    /* Close .txt File */
    lrdParam->close();

    /* CRC-32 Calculation */
    lrdFileCRC = getFileCrc32(fileName);
}

//void DataLogging::generateHrdEdfFile(void)
//{
//    if(!hrdParam->exists())
//        return;

//    hrdPacketCount = getTotalLinesInAFiles(&hrdParam);

//    /* Open HRD.txt File */
//    if (!hrdParam->open(QIODevice::ReadOnly | QIODevice::Text))
//        return;

//    /* Create dynamic array to read all data from file and
//     * store in an array for perticular parameter */
//    //TODO Get packet count data when device restarts
//    double * pParam1 = new double [hrdPacketCount];
//    double * pParam2 = new double [hrdPacketCount];
//    double * pParam3 = new double [hrdPacketCount];
//    double * pParam4 = new double [hrdPacketCount];
//    int i=0;
//    double param1Max=0,param1Min=0;
//    double param2Max=0,param2Min=0;
//    double param3Max=0,param3Min=0;
//    double param4Max=0,param4Min=0;
//    QTextStream in(&hrdParam);
//    QStringList itemList;

//    /* Process until file reached to its end
//     * Parse Flow & Pressure values to an array
//     * which will be passed to create EDF file
//     */
//    while(!in.atEnd()) {

//        /* Read each line ended with null character */
//        QString line = in.readLine();

//        /* Split each line with '/' Separator */
//        itemList = line.split('/');

//        /* First indexed value is leak parameter
//         * store it to leak data array */
//        pParam1[i] = itemList.at(0).toInt();

//        /* Convert Flow raw data to engineering */
//        pParam1[i] = Providers::getFlowEngineeringValues(pParam1[i]);

//        if(pParam1[i] > param1Max)       param1Max = pParam1[i];
//        if(pParam1[i] < param1Min)       param1Min = pParam1[i];

//        /* Second indexed value is Pressure parameter
//         * store it to Pressure data array */
//        pParam2[i] = itemList.at(1).toInt();

//        /* Convert Pressure raw data to engineering */
//        //TODO Temporary for testing only
//        pParam2[i] = Providers::getFlowEngineeringValues(pParam2[i]);

//        if(pParam2[i] > param2Max)       param2Max = pParam2[i];
//        if(pParam2[i] < param2Min)       param2Min = pParam2[i];

//        /* Second indexed value is Pressure parameter
//         * store it to Pressure data array */
//        pParam3[i] = itemList.at(2).toInt();

//        /* Convert Pressure raw data to engineering */
//        //TODO Temporary for testing only
//        pParam3[i] = Providers::getFlowEngineeringValues(pParam3[i]);

//        if(pParam3[i] > param3Max)       param3Max = pParam3[i];
//        if(pParam3[i] < param3Min)       param3Min = pParam3[i];

//        /* Second indexed value is Pressure parameter
//         * store it to Pressure data array */
//        pParam4[i] = itemList.at(3).toInt();

//        /* Convert Pressure raw data to engineering */
//        //TODO Temporary for testing only
//        pParam4[i] = Providers::getFlowEngineeringValues(pParam4[i]);

//        if(pParam4[i] > param4Max)       param4Max = pParam4[i];
//        if(pParam4[i] < param4Min)       param4Min = pParam4[i];

//        i++;
//    }

//    if(param1Min == param1Max){
//        param1Max++;
//    }
//    if(param2Min == param2Max){
//        param2Max++;
//    }
//    if(param3Min == param3Max){
//        param3Max++;
//    }
//    if(param4Min == param4Max){
//        param4Max++;
//    }

//    QString fileName = QString("%1/%2/%2H.edf").arg(Providers::getEdfLogFilesPath()).arg(therapyTimeStamp);
//    int totalChannel = 4;

//    int digitalDataMax[4];
//    digitalDataMax[0] = 32767;
//    digitalDataMax[1] = 32767;
//    digitalDataMax[2] = 32767;
//    digitalDataMax[3] = 32767;

//    int digitalDataMin[4];
//    digitalDataMin[0] = -32768;
//    digitalDataMin[1] = -32768;
//    digitalDataMin[2] = -32768;
//    digitalDataMin[3] = -32768;

//    double physicalDataMax[4];
//    physicalDataMax[0] = param1Max;
//    physicalDataMax[1] = param2Max;
//    physicalDataMax[2] = param3Max;
//    physicalDataMax[3] = param4Max;

//    double physicalDataMin[4];
//    physicalDataMin[0] = param1Min;
//    physicalDataMin[1] = param2Min;
//    physicalDataMin[2] = param3Min;
//    physicalDataMin[3] = param4Min;

//    //TODO add unit from the selection screen
//    QStringList dimensionList;
//    dimensionList << "lpm" << "lpm" << "lpm" << "lpm";

//    QStringList labelList;
//    labelList << "EventFlow_Filtered" << "Offset_EventFlow_Filtered" << "Flow_Filtered" << "Offset_Flow";

//    int samplingFreq=0;
//    samplingFreq = 25;

//    int totalSamplesCount=0;
//    totalSamplesCount = hrdPacketCount;

//    /* Create EDF File */
//    edfFileHandle = generateEdf->createEdfFile(fileName,totalChannel);

//    /* Add Header related data to EDF File */
//    generateEdf->generateEdfFile(totalChannel,digitalDataMax,digitalDataMin,
//                                 physicalDataMax,physicalDataMin,dimensionList,labelList,
//                                 samplingFreq);

//    int j=0;
//    int arrayIdx=0;
//    int durationInSecons=0;
//    durationInSecons = (totalSamplesCount/samplingFreq);

//    /* NOTE It will discard last second samples to log
//     * While therapy stops and receives on 10 samples instead of
//     * 25 samples so whether need to log extra 15 samples to specific
//     * value which can be misinterpret to reader
//     *
//     * It will loop for number of seconds therapy will run
//     */
//    for(j=0; j<durationInSecons; j++) {
//        arrayIdx = j * samplingFreq;
//        generateEdf->writeEdfLogData(&pParam1[arrayIdx]);
//        generateEdf->writeEdfLogData(&pParam2[arrayIdx]);
//        generateEdf->writeEdfLogData(&pParam3[arrayIdx]);
//        generateEdf->writeEdfLogData(&pParam4[arrayIdx]);
//    }

//    /* Close EDF File */
//    generateEdf->closeEdfFile(edfFileHandle);

//    /* Delete dynamically created array and free memory */
//    delete[] pParam1;
//    delete[] pParam2;
//    delete[] pParam3;
//    delete[] pParam4;

//    /* Close .txt File */
//    hrdParam->close();

//    /* CRC-32 Calculation */
//    hrdFileCRC = getFileCrc32(fileName);
//}

unsigned int DataLogging::getTotalLinesInAFiles(QFile * localFile)
{
    if (!localFile->open(QIODevice::ReadOnly | QIODevice::Text))
        return 0;

    QTextStream localStream(localFile);

    unsigned int totalLines=0;
    QString localLine;

    while(!localStream.atEnd()) {
//        qDebug() << "L" << totalLines;
        /* Read each line ended with null character */
        localLine = localStream.readLine();
        totalLines++;
    }
//    qDebug() << "Last line" << localFile->fileName() << totalLines << localLine;

    localFile->close();

return totalLines;
}

void DataLogging::generateEventEdfFile(void)
{
    if(eveParam->exists() == false)
        return;

    evePacketCount = getTotalLinesInAFiles(eveParam);;

    /* Open EVE.txt File */
    if (!eveParam->open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    /* Create dynamic array to read all data from file and
     * store in an array for perticular parameter */
    //TODO Get packet count data when device restarts
    double * pYearData = new double [evePacketCount];
    double * pMonthData = new double [evePacketCount];
    double * pDateData = new double [evePacketCount];
    double * pHourData = new double [evePacketCount];
    double * pMinuteData = new double [evePacketCount];
    double * pSecondData = new double [evePacketCount];
    double * pEveData = new double [evePacketCount];
    double * pEveTimeData = new double [evePacketCount];

    int i=0;
    double yearMax=0,yearMin=-1;
    double monthMax=0,monthMin=-1;
    double dateMax=0,dateMin=-1;
    double hourMax=0,hourMin=-1;
    double minuteMax=0,minuteMin=-1;
    double secondMax=0,secondMin=-1;
    double eveMax=0,eveMin=-1;
    double eveTimeMax=0,eveTimeMin=-1;
    QTextStream in(eveParam);
    QString line;
    QStringList itemList;

    /* Process until file reached to its end
     * Parse event Id values to an array
     * which will be passed to create EDF file
     */
    while(!in.atEnd()) {

        /* Read each line ended with null character */
        line = in.readLine();

        /* Split each line with '/' Separator */
        itemList = line.split('/');

        /* Convert Year to Integer */
        pYearData[i] = itemList.at(0).toInt();
        if(pYearData[i] > yearMax)       yearMax = pYearData[i];
        if(pYearData[i] < yearMin)       yearMin = pYearData[i];

        /* Convert Month to Integer */
        pMonthData[i] = itemList.at(1).toInt();
        if(pMonthData[i] > monthMax)       monthMax = pMonthData[i];
        if(pMonthData[i] < monthMin)       monthMin = pMonthData[i];

        /* Convert Date to Integer */
        pDateData[i] = itemList.at(2).toInt();
        if(pDateData[i] > dateMax)       dateMax = pDateData[i];
        if(pDateData[i] < dateMin)       dateMin = pDateData[i];

        /* Convert Hour to Integer */
        pHourData[i] = itemList.at(3).toInt();
        if(pHourData[i] > hourMax)       hourMax = pHourData[i];
        if(pHourData[i] < hourMin)       hourMin = pHourData[i];

        /* Convert Minute to Integer */
        pMinuteData[i] = itemList.at(4).toInt();
        if(pMinuteData[i] > minuteMax)       minuteMax = pMinuteData[i];
        if(pMinuteData[i] < minuteMin)       minuteMin = pMinuteData[i];

        /* Convert Second to Integer */
        pSecondData[i] = itemList.at(5).toInt();
        if(pSecondData[i] > secondMax)       secondMax = pSecondData[i];
        if(pSecondData[i] < secondMin)       secondMin = pSecondData[i];

        /* Convert Event Id to Integer */
        pEveData[i] = itemList.at(6).toInt();
        if(pEveData[i] > eveMax)       eveMax = pEveData[i];
        if(pEveData[i] < eveMin)       eveMin = pEveData[i];

        /* Convert usage data to Integer */
        pEveTimeData[i] = itemList.at(7).toInt();
        if(pEveTimeData[i] > eveTimeMax)       eveTimeMax = pEveTimeData[i];
        if(pEveTimeData[i] < eveTimeMin)       eveTimeMin = pEveTimeData[i];

        i++;
    }

    if(yearMin == yearMax){
        yearMax++;
    }
    if(monthMin == monthMax){
        monthMax++;
    }
    if(dateMin == dateMax){
        dateMax++;
    }
    if(hourMin == hourMax){
        hourMax++;
    }
    if(minuteMin == minuteMax){
        minuteMax++;
    }
    if(secondMin == secondMax){
        secondMax++;
    }
    if(eveMin == eveMax){
        eveMax++;
    }
    if(eveTimeMin == eveTimeMax){
        eveTimeMax++;
    }

    QString fileName = QString("%1/%2/%2E.edf").arg(Providers::getEdfLogFilesPath()).arg(*therapyTimeStamp);
    int totalChannel = 8;

    int digitalDataMax[8];
    digitalDataMax[0] = 32767;
    digitalDataMax[1] = 32767;
    digitalDataMax[2] = 32767;
    digitalDataMax[3] = 32767;
    digitalDataMax[4] = 32767;
    digitalDataMax[5] = 32767;
    digitalDataMax[6] = 32767;
    digitalDataMax[7] = 32767;

    int digitalDataMin[8];
    digitalDataMin[0] = -32768;
    digitalDataMin[1] = -32768;
    digitalDataMin[2] = -32768;
    digitalDataMin[3] = -32768;
    digitalDataMin[4] = -32768;
    digitalDataMin[5] = -32768;
    digitalDataMin[6] = -32768;
    digitalDataMin[7] = -32768;

    double physicalDataMax[8];
    physicalDataMax[0] = yearMax;
    physicalDataMax[1] = monthMax;
    physicalDataMax[2] = dateMax;
    physicalDataMax[3] = hourMax;
    physicalDataMax[4] = minuteMax;
    physicalDataMax[5] = secondMax;
    physicalDataMax[6] = eveMax;
    physicalDataMax[7] = eveTimeMax;

    double physicalDataMin[8];
    physicalDataMin[0] = yearMin;
    physicalDataMin[1] = monthMin;
    physicalDataMin[2] = dateMin;
    physicalDataMin[3] = hourMin;
    physicalDataMin[4] = minuteMin;
    physicalDataMin[5] = secondMin;
    physicalDataMin[6] = eveMin;
    physicalDataMin[7] = eveTimeMin;

    QStringList dimensionList;
    dimensionList << "Year" << "Month" << "Date" << "Hour" << "Minute" << "Second" << "Code" << "time";

    QStringList labelList;
    labelList << "Year" << "Month" << "Date" << "Hour" << "Minute" << "Second" << "Event Id" << "Usage time";

    int samplingFreq=0;
    samplingFreq = 1;

    int totalSamplesCount=0;
    totalSamplesCount = evePacketCount;

    /* Create EDF File */
    edfFileHandle = generateEdf->createEdfFile(fileName,totalChannel);

    /* Add Header related data to EDF File */
    generateEdf->generateEdfFile(totalChannel,digitalDataMax,digitalDataMin,
                                 physicalDataMax,physicalDataMin,dimensionList,labelList,
                                 samplingFreq);

    int j=0;
    int arrayIdx=0;
    int durationInSecons=0;
    durationInSecons = (totalSamplesCount/samplingFreq);

    /* NOTE It will discard last second samples to log
     * While therapy stops and receives on 10 samples instead of
     * 25 samples so whether need to log extra 15 samples to specific
     * value which can be misinterpret to reader
     *
     * It will loop for number of seconds therapy will run
     */
    for(j=0; j<durationInSecons; j++) {
        arrayIdx = j * samplingFreq;
        generateEdf->writeEdfLogData(&pYearData[arrayIdx]);
        generateEdf->writeEdfLogData(&pMonthData[arrayIdx]);
        generateEdf->writeEdfLogData(&pDateData[arrayIdx]);
        generateEdf->writeEdfLogData(&pHourData[arrayIdx]);
        generateEdf->writeEdfLogData(&pMinuteData[arrayIdx]);
        generateEdf->writeEdfLogData(&pSecondData[arrayIdx]);
        generateEdf->writeEdfLogData(&pEveData[arrayIdx]);
        generateEdf->writeEdfLogData(&pEveTimeData[arrayIdx]);
    }

    /* Close EDF File */
    generateEdf->closeEdfFile(edfFileHandle);

    /* Delete dynamically created array and free memory */
    delete[] pYearData;
    delete[] pMonthData;
    delete[] pDateData;
    delete[] pHourData;
    delete[] pMinuteData;
    delete[] pSecondData;
    delete[] pEveData;
    delete[] pEveTimeData;

    /* Close .txt File */
    eveParam->close();

    /* CRC-32 Calculation */
    eveFileCRC = getFileCrc32(fileName);
}

#include <stdint.h>
void DataLogging::generateSettingsEdfFile(void)
{
    if(!setParam->exists())
        return;

    /* Open SET.txt File */
    if (!setParam->open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    double maxPressure,minPressure,
            comfortLevel,
            rampTime,goToSleepTime,
            autoTherapyState,tubeType,
            maskType,date,time,
            model,serialNo,
            firmwareVer,snoozeTime;

    double physicalDataMax[14];
    double physicalDataMin[14];
    int digitalDataMax[14];
    int digitalDataMin[14];
    QTextStream in(setParam);

    /* Read each line ended with null character */
    QString line = in.readLine();

    /* Split each line with '/' Separator */
    QStringList itemList = line.split('/');
    physicalDataMax[0] = physicalDataMin[0] = date              = itemList.at(0).toInt();
    physicalDataMax[1] = physicalDataMin[1] = time              = itemList.at(1).toInt();
    physicalDataMax[2] = physicalDataMin[2] = model             = itemList.at(2).toInt();
    physicalDataMax[3] = physicalDataMin[3] = serialNo          = itemList.at(3).toInt();
    physicalDataMax[4] = physicalDataMin[4] = firmwareVer       = itemList.at(4).toFloat(); //itemList.at(4).toInt();
    physicalDataMax[5] = physicalDataMin[5] = minPressure       = itemList.at(5).toInt();
    physicalDataMax[6] = physicalDataMin[6] = maxPressure       = itemList.at(6).toInt();
    physicalDataMax[7] = physicalDataMin[7] = comfortLevel      = itemList.at(7).toInt();
    physicalDataMax[8] = physicalDataMin[8] = autoTherapyState  = itemList.at(8).toInt();
    physicalDataMax[9] = physicalDataMin[9] = rampTime          = itemList.at(9).toInt();
    physicalDataMax[10] = physicalDataMin[10] = goToSleepTime   = itemList.at(10).toInt();
    physicalDataMax[11] = physicalDataMin[11] = snoozeTime      = itemList.at(11).toInt();
    physicalDataMax[12] = physicalDataMin[12] = tubeType        = itemList.at(12).toInt();
    physicalDataMax[13] = physicalDataMin[13] = maskType        = itemList.at(13).toInt();

    for(int k=0 ; k<14 ; k++) {
        digitalDataMax[k] = 32767;
        digitalDataMin[k] = -32768;
        physicalDataMin[k] = -1;
    }

    QString fileName = QString("%1/%2/%2S.edf").arg(Providers::getEdfLogFilesPath()).arg(*therapyTimeStamp);
    int totalChannel = 14;

    QStringList dimensionList;
    dimensionList << " " << " " << " " << " " << " "
                  << "cmH2O" << "cmH2O" << "Level" << "On/Off"
                  << "Seconds" << "Seconds" << "Seconds"
                  << "mm" << " " ;

    QStringList labelList;
    labelList << "Date" << "Time" << "Model" << "Serial number" << "Firware ver"
              << "Min Pressure" << "Max Pressure" << "Comfort Level" << "Auto Therapy"
              << "Ramp Time" << "Go To Sleep Time" << "Snooze time"
              << "Hose Type" << "Mask Type";

    int samplingFreq=0;
    samplingFreq = 1;

    /* Create EDF File */
    edfFileHandle = generateEdf->createEdfFile(fileName,totalChannel);

    /* Add Header related data to EDF File */
    generateEdf->generateEdfFile(totalChannel,digitalDataMax,digitalDataMin,
                                 physicalDataMax,physicalDataMin,dimensionList,labelList,
                                 samplingFreq);

    generateEdf->writeEdfLogData(&date);
    generateEdf->writeEdfLogData(&time);
    generateEdf->writeEdfLogData(&model);
    generateEdf->writeEdfLogData(&serialNo);
    generateEdf->writeEdfLogData(&firmwareVer);
    generateEdf->writeEdfLogData(&minPressure);
    generateEdf->writeEdfLogData(&maxPressure);
    generateEdf->writeEdfLogData(&comfortLevel);
    generateEdf->writeEdfLogData(&autoTherapyState);
    generateEdf->writeEdfLogData(&rampTime);
    generateEdf->writeEdfLogData(&goToSleepTime);
    generateEdf->writeEdfLogData(&snoozeTime);
    generateEdf->writeEdfLogData(&tubeType);
    generateEdf->writeEdfLogData(&maskType);

    /* Close EDF File */
    generateEdf->closeEdfFile(edfFileHandle);

    /* Close .txt File */
    setParam->close();

    /* CRC-32 Calculation */
    setFileCRC = getFileCrc32(fileName);
}

#include <QFileInfoList>
#include <QDateTime>
void DataLogging::getDataForOneDay(int tSleepReportType,const QFileInfoList & list,QString & tPrevDateStr,QString & tTodayDateStr,int index,
                                              float * tUsageHours,float * tEventsPerHour,float * tLeakage)
{
    int maxFiles = list.length() - 1;
    QString readEventFileName,readLeakageFileName;
    unsigned int eventInThatSession=0,usageTimeInSeconds=0;
    unsigned int eventInLastNight=0,usageTimeInLastNight=0;
    float leakageInThatSession=0,leakageInLastNight=0;
    unsigned int totalFilesIndex=0;
    int res=0;

    if(maxFiles != 0)
    {
        for(int i = maxFiles ; i >= 0 ; i-- )
        {
            if((list.at(i).fileName() < tTodayDateStr) & (list.at(i).fileName() > tPrevDateStr))
//            if((list.at(i).fileName() < referenceDate1) & (list.at(i).fileName() > referenceDate2))
            {
//                qDebug() << "$" << i << list.at(i).fileName() << tPrevDateStr << "<-->" << tTodayDateStr;
                readEventFileName.clear();

                /* Read Event edf file */
                readEventFileName = list.at(i).filePath() + "/" + list.at(i).fileName() + "E.edf";
                res = 0;
                res = generateEdf->readEventEdfFile(readEventFileName.toStdString().c_str(),&eventInThatSession,&usageTimeInSeconds);
                if(res){
                    /* File read success print usage time & events */
//                    qDebug() << readEventFileName.toStdString().c_str() << eventInThatSession << usageTimeInSeconds;
                    eventInLastNight += eventInThatSession;
                    usageTimeInLastNight += usageTimeInSeconds;
                    totalFilesIndex++;
                }

                if(tSleepReportType == SLEEP_REPORT_EXTENDED)
                {
                    /* Read leakage related data */
                    readLeakageFileName.clear();
                    readLeakageFileName = list.at(i).filePath() + "/" + list.at(i).fileName() + "L.edf";
                    res = 0;
                    res = generateEdf->readLeakEdfFile(readLeakageFileName.toStdString().c_str(),&leakageInThatSession);
                    if(res){
                        /* File read success print leakage */
//                        qDebug() << readLeakageFileName.toStdString().c_str() << leakageInThatSession;
                        leakageInLastNight += leakageInThatSession;
                    }
                }
            }
        }
        if(usageTimeInLastNight != 0){

            *tUsageHours = static_cast<float>(usageTimeInLastNight)/3600;

            if(eventInLastNight != 0)
                *tEventsPerHour = static_cast<float>(3600 * eventInLastNight)/usageTimeInLastNight;

            if(leakageInLastNight != 0)
                *tLeakage = leakageInLastNight/totalFilesIndex;
        }
    }
}

void DataLogging::getSleepReportData(int tSleepReportType,sendSleepReportParam sleepReportDuration,const QFileInfoList & list,int index,
                                     float * tUsageHours,float * tEventsPerHour,float * tLeakage,
                                     int * usedHours4PlusIndex,int * usedDaysIndex,float * tAverageUsage)
{
    int requiredDays=1;

    QString lastFileName = list.at(index).fileName();

    QString lastTime = list.at(index).fileName();
    QStringList dateTime = lastTime.split("_");

    //Format Date
    QString dateString = dateTime.at(0);

    QString fileNameFormat = "yyyyMMdd";
    QDate todayDate = QDate::fromString(dateString,fileNameFormat);
    QDate lastRequiredDate;

    switch (sleepReportDuration) {
        case day1:
        lastRequiredDate = todayDate.addDays(-1);
        break;
        case week1:
        lastRequiredDate = todayDate.addDays(-7);
        break;
        case month1:
        lastRequiredDate = todayDate.addMonths(-1);
        break;
        case month3:
        lastRequiredDate = todayDate.addMonths(-3);
        break;
        case month6:
        lastRequiredDate = todayDate.addMonths(-6);
        break;
        case year1:
        lastRequiredDate = todayDate.addYears(-1);
        break;
    }

    requiredDays = lastRequiredDate.daysTo(todayDate);

    QString tPrevDayString,tTodayString;

    float tUsageHoursLocal=0,tEventsPerHourLocal=0,tLeakageLocal=0;
    float tUsageHoursForDuration=0,tEventsPerHourForDuration=0,tLeakageForDuration=0,tAverageUsageForDuration=0;

    qDebug() << lastRequiredDate << "<---------------->" << todayDate << requiredDays << sleepReportDuration;
    for(int i=0 ; i<requiredDays ; i++)
    {
        lastRequiredDate = todayDate.addDays(-1);
        tTodayString = QString("%1_120000").arg(todayDate.toString(fileNameFormat));
        tPrevDayString = QString("%1_120000").arg(lastRequiredDate.toString(fileNameFormat));
//        qDebug() << i << tPrevDayString << "<------------------------->" << tTodayString;

        /* Reset local variables */
        tUsageHoursLocal = 0;
        tEventsPerHourLocal = 0;
        tLeakageLocal = 0;

        getDataForOneDay(tSleepReportType,list,tPrevDayString,tTodayString,index,&tUsageHoursLocal,&tEventsPerHourLocal,&tLeakageLocal);
//        qDebug() << "#" << i << tUsageHoursLocal << tEventsPerHourLocal << tLeakageLocal << tPrevDayString << "<-->" << tTodayString;

        tUsageHoursForDuration += tUsageHoursLocal;
        tEventsPerHourForDuration += tEventsPerHourLocal;
        tLeakageForDuration += tLeakageLocal;
        tAverageUsageForDuration += tUsageHoursLocal;
        if(tUsageHoursLocal > 4)        (*usedHours4PlusIndex)++;
        if(tUsageHoursLocal > 0.0)      (*usedDaysIndex)++;

        /* Update current date to previous date */
        todayDate = lastRequiredDate;
    }

//    *tUsageHours = tUsageHoursForDuration/requiredDays;
//    *tEventsPerHour = tEventsPerHourForDuration/requiredDays;
//    *tLeakage = tLeakageForDuration/requiredDays;
    *tUsageHours = tUsageHoursForDuration;
    *tEventsPerHour = tEventsPerHourForDuration;
    *tLeakage = tLeakageForDuration;
    *tAverageUsage = tAverageUsageForDuration/requiredDays;
}

void DataLogging::createCacheFiles(void)
{
    QDir dirCheck;
    dirCheck.setPath(Providers::getLocalLogFilesPath());
    if(dirCheck.exists() == false){
        dirCheck.mkpath(Providers::getLocalLogFilesPath());
    }

    if(lrdParam->exists() == true) {
        if(lrdParam->open(QIODevice::ReadWrite|QIODevice::Truncate) == true)
            lrdParam->close();
    }

    if(hrdParam->exists() == true) {
        if(hrdParam->open(QIODevice::ReadWrite|QIODevice::Truncate) == true)
            hrdParam->close();
    }

    if(eveParam->exists() == true) {
        if(eveParam->open(QIODevice::ReadWrite|QIODevice::Truncate) == true)
            eveParam->close();
    }

    if(setParam->exists() == true) {
        if(setParam->open(QIODevice::ReadWrite|QIODevice::Truncate) == true)
            setParam->close();
    }

    if(therapyDetailsFile->exists() == true)
    {
        if(therapyDetailsFile->open(QIODevice::ReadWrite|QIODevice::Truncate) == true)
        {
            QTextStream outStream(therapyDetailsFile);

            /* Update last record therapy time stamp */
            outStream << QString("%1").arg(*therapyTimeStamp) << "\n";

            therapyDetailsFile->close();
        }
    }
}

void DataLogging::removeCacheFiles(void)
{
    /* Delete Created Temporary Files */

    if(lrdParam->exists() == true) {
        if(lrdParam->open(QIODevice::ReadWrite|QIODevice::Truncate) == true)
            lrdParam->close();
    }
    if(hrdParam->exists() == true) {
        if(hrdParam->open(QIODevice::ReadWrite|QIODevice::Truncate) == true)
            hrdParam->close();
    }
    if(eveParam->exists() == true) {
        if(eveParam->open(QIODevice::ReadWrite|QIODevice::Truncate) == true)
            eveParam->close();
    }
    if(setParam->exists() == true) {
        if(setParam->open(QIODevice::ReadWrite|QIODevice::Truncate) == true)
            setParam->close();
    }
    if(therapyDetailsFile->exists() == true) {
        if(therapyDetailsFile->open(QIODevice::ReadWrite|QIODevice::Truncate) == true)
            therapyDetailsFile->close();
    }

    if(!lrdParam->remove()){
    }
    if(!hrdParam->remove()){
    }
    if(!eveParam->remove()){
    }
    if(!setParam->remove()){
    }
    if(!therapyDetailsFile->remove()){
    }
}

unsigned long DataLogging::getFileCrc32(const QString & fileName)
{
QFile crcFile;
QString localFileName;
char localArray[32768];
qint64 readLength=0,fileSize=0,totalReadSize=0;
unsigned long crcData=0;

    crcFile.setFileName(fileName);

    /* Check if file exits */
    if(crcFile.exists() == true)
    {
        /* Open file and get size in a variable */
        crcFile.open(QIODevice::ReadOnly);
        fileSize = crcFile.size();

        /* Loop until file reaches at the end */
        while(totalReadSize < fileSize) {

            /* Check if pending read size is less than available array size
             */
            if((totalReadSize + sizeof(localArray)) > fileSize)
                readLength = fileSize - totalReadSize;
            else
                readLength = sizeof(localArray);

            /* Read bytes of array from file */
            crcFile.read(localArray,readLength);

            /* Calculate CRC from array */
            crcData = crc32(crcData,localArray,readLength);

            /* Update number of bytes read variable */
            totalReadSize += readLength;
        }
        /* Close file */
        crcFile.close();
    }
    else
    {
        qCritical() << Q_FUNC_INFO << "File does not exists" << fileName;
    }
    /* Return CRC-32 of file */
return crcData;
}

/* ========================================================================= */
#define DO1(buf) crc = crc_table[((int)crc ^ (*buf++)) & 0xff] ^ (crc >> 8);
#define DO2(buf)  DO1(buf); DO1(buf);
#define DO4(buf)  DO2(buf); DO2(buf);
#define DO8(buf)  DO4(buf); DO4(buf);


/* ========================================================================= */
unsigned long DataLogging::crc32(unsigned long crc,const char *buf,unsigned int len)
{
    if (buf == NULL)
        return 0;

    crc = crc ^ 0xffffffffL;

    while (len >= 8) {
        DO8(buf);
        len -= 8;
    }
    if (len) {
        do {
                DO1(buf);
            } while (--len);
    }
return crc ^ 0xffffffffL;
}


void DataLogging::generateHrdEdfFile(void)
{
    if(!hrdParam->exists())
        return;

    hrdPacketCount = getTotalLinesInAFiles(hrdParam);

    /* Open HRD.txt File */
    if (!hrdParam->open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    /* Create dynamic array to read all data from file and
     * store in an array for perticular parameter */
    //TODO Get packet count data when device restarts
    double * pFlowHrdData = new double [hrdPacketCount];
    double * pPressureHrdData = new double [hrdPacketCount];
    int i=0;
    double flowMax=0,flowMin=0;
    double pressureMax=0,pressureMin=0;
    QTextStream in(hrdParam);
    QStringList itemList;

    Providers providers;

    /* Process until file reached to its end
     * Parse Flow & Pressure values to an array
     * which will be passed to create EDF file
     */
    while(!in.atEnd()) {

        /* Read each line ended with null character */
        QString line = in.readLine();

        /* Split each line with '/' Separator */
        itemList = line.split('/');

        /* First indexed value is leak parameter
         * store it to leak data array */
        pFlowHrdData[i] = itemList.at(0).toInt();

        /* Convert Flow raw data to engineering */
        pFlowHrdData[i] = providers.getFlowEngineeringValues(pFlowHrdData[i]);

        if(pFlowHrdData[i] > flowMax)       flowMax = pFlowHrdData[i];
        if(pFlowHrdData[i] < flowMin)       flowMin = pFlowHrdData[i];

        /* Second indexed value is Pressure parameter
         * store it to Pressure data array */
        pPressureHrdData[i] = itemList.at(1).toInt();

        /* Convert Pressure raw data to engineering */
        pPressureHrdData[i] = providers.getFlowEngineeringValues(pPressureHrdData[i]);
//        pPressureHrdData[i] = Providers::getPressureEngineeringValues(pPressureHrdData[i]);

        if(pPressureHrdData[i] > pressureMax)       pressureMax = pPressureHrdData[i];
        if(pPressureHrdData[i] < pressureMin)       pressureMin = pPressureHrdData[i];

        i++;
    }

    if(pressureMin == pressureMax){
        pressureMax++;
    }
    if(flowMin == flowMax){
        flowMax++;
    }

    QString fileName = QString("%1/%2/%2H.edf").arg(Providers::getEdfLogFilesPath()).arg(*therapyTimeStamp);
    int totalChannel = 2;

    int digitalDataMax[2];
    digitalDataMax[0] = 32767;
    digitalDataMax[1] = 32767;

    int digitalDataMin[2];
    digitalDataMin[0] = -32768;
    digitalDataMin[1] = -32768;

    double physicalDataMax[2];
    physicalDataMax[0] = flowMax;
    physicalDataMax[1] = pressureMax;

    double physicalDataMin[2];
    physicalDataMin[0] = flowMin;
    physicalDataMin[1] = pressureMin;

    //TODO add unit from the selection screen
    QStringList dimensionList;
//    dimensionList << "lpm" << "cmH2O";
    dimensionList << "lpm" << "lpm";

    QStringList labelList;
//    labelList << "Flow" << "Pressure";
    labelList << "Trigger Flow" << "Event Flow";

    int samplingFreq=0;
    samplingFreq = 25;

    int totalSamplesCount=0;
    totalSamplesCount = hrdPacketCount;

    /* Create EDF File */
    edfFileHandle = generateEdf->createEdfFile(fileName,totalChannel);

    /* Add Header related data to EDF File */
    generateEdf->generateEdfFile(totalChannel,digitalDataMax,digitalDataMin,
                                 physicalDataMax,physicalDataMin,dimensionList,labelList,
                                 samplingFreq);

    int j=0;
    int arrayIdx=0;
    int durationInSecons=0;
    durationInSecons = (totalSamplesCount/samplingFreq);

    /* NOTE It will discard last second samples to log
     * While therapy stops and receives on 10 samples instead of
     * 25 samples so whether need to log extra 15 samples to specific
     * value which can be misinterpret to reader
     *
     * It will loop for number of seconds therapy will run
     */
    for(j=0; j<durationInSecons; j++) {
        arrayIdx = j * samplingFreq;
        generateEdf->writeEdfLogData(&pFlowHrdData[arrayIdx]);
        generateEdf->writeEdfLogData(&pPressureHrdData[arrayIdx]);
    }

    /* Close EDF File */
    generateEdf->closeEdfFile(edfFileHandle);

    /* Delete dynamically created array and free memory */
    delete[] pFlowHrdData;
    delete[] pPressureHrdData;

    /* Close .txt File */
    hrdParam->close();

    /* CRC-32 Calculation */
    hrdFileCRC = getFileCrc32(fileName);
}
