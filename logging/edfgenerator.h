#ifndef EDFGENERATOR_H
#define EDFGENERATOR_H


#include <QStringList>
#include <QString>
#include "edflib.h"

class EdfGenerator
{
public:
    EdfGenerator();

    typedef enum {
        EDF_LRD_DATA_FILE=0,
        EDF_HRD_DATA_FILE,
        EDF_EVE_DATA_FILE,
        EDF_SET_DATA_FILE,
    } EDF_TYPE_Files;

    int edfFile;
    struct edf_hdr_struct hdr;


    int setChannelNo(int * chnNo);
    int getAvailableSamplesInFile(int chn);
    int openEdfFileForReadOnly(const char * filePath);
    int readAllDataFromFile(int fileHandle,double * dataSamples,int chn);

    void readAllEdfFiles(void);
    int readEventEdfFile(const char * filePath,unsigned int * eventsDuringSession,unsigned int * usageHoursInSession);
    int readLeakEdfFile(const char * filePath,float * leakDuringSession);

    int printEdfFileInfo(int channel);
    int createEdfFile(const QString fileName,int channel);
    int closeEdfFile(int localFile);
    int writeEdfLogData(double * channelData);
    int generateEdfFile(int totalChannels,
                        int * digitalMax, int * digitalMin,
                        double * phyMax, double * phyMin,
                        const QStringList & dimenList, const QStringList & labelList, int sampleFreq);

    int setDigitalMaxMin(int localFile,int channel,int max,int min);
    int setPhysicalMaxMin(int localFile,int channel,double max,double min);
    int setPhysicalDimension(int localFile,int channel,const QString & dim);
    int setEdfLabel(int localFile,int channel,const QString & label);
    int setSamplingFrequency(int localFile,int channel,int freq);

    int setChannelData(int localFile,int channelNumber,
                       int digitalMax,int digitalMin,double physicalMax,double physicalMin,
                       const QString & dimension,const QString & label,int samplingFreq);

};

#endif // EDFGENERATOR_H
