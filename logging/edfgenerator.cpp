#include "edfgenerator.h"
#include "shareddata.h"

#include <QDebug>
#include <QDir>
#include <QFileInfo>

EdfGenerator::EdfGenerator()
{
//    readAllEdfFiles();
}

int EdfGenerator::setDigitalMaxMin(int localFile,int channel,int max,int min)
{
    if(edf_set_digital_maximum(localFile, channel, max))
    {
        qDebug("error: edf_set_digital_maximum()\n");
        return 0;
    }

    if(edf_set_digital_minimum(localFile, channel, min))
    {
        qDebug("error: edf_set_digital_minimum()\n");
        return 0;
    }

return 1;
}

int EdfGenerator::setPhysicalMaxMin(int localFile,int channel,double max,double min)
{
    if(edf_set_physical_maximum(localFile, channel, max))
    {
      qDebug("error: edf_set_physical_maximum()\n");
      return 0;
    }
    if(edf_set_physical_minimum(localFile, channel, min))
    {
      qDebug("error: edf_set_physical_minimum()\n");
      return 0;
    }

return 1;
}

int EdfGenerator::setPhysicalDimension(int localFile,int channel,const QString & dim)
{
    if(edf_set_physical_dimension(localFile, channel, dim.toStdString().c_str()))
    {
        qDebug("error: edf_set_physical_dimension()\n");
        return 0;
    }

return 1;
}

int EdfGenerator::setEdfLabel(int localFile,int channel,const QString & label)
{
    if(edf_set_label(localFile, channel, label.toStdString().c_str()))
    {
        qDebug("error: edf_set_label()\n");
        return 0;
    }

return 1;
}

int EdfGenerator::setSamplingFrequency(int localFile,int channel,int freq)
{
    if(edf_set_samplefrequency(localFile, channel, freq))
    {
        qDebug("error: edf_set_samplefrequency()\n");
        return 0;
    }
    return 1;
}

int EdfGenerator::setChannelData(int localFile,int channelNumber,
                                 int digitalMax,int digitalMin,double physicalMax,double physicalMin,
                                 const QString & dimension,const QString & label,int samplingFreq)
{
    /* Set Digital Min Max limit */
    if(!setDigitalMaxMin(localFile,channelNumber,digitalMax,digitalMin)) {
        qDebug() << "setDigitalMaxMin";
        return 0;
    }

    /* Set Physical Min Max limit */
    if(!setPhysicalMaxMin(localFile,channelNumber,physicalMax,physicalMin)) {
        qDebug() << "setPhysicalMaxMin";
        return 0;
    }

    /* Set Physical Dimension Unit for the channel */
    if(!setPhysicalDimension(localFile,channelNumber,dimension)) {
        qDebug() << "setPhysicalDimension";
        return 0;
    }

    /* Set Channel Label name */
    if(!setEdfLabel(localFile,channelNumber,label)) {
        qDebug() << "setEdfLabel";
        return 0;
    }

    /* Set Sampling Frequency */
    if(!setSamplingFrequency(localFile,channelNumber,samplingFreq)) {
        qDebug() << "setSamplingFrequency";
        return 0;
    }

return 1;
}

int EdfGenerator::createEdfFile(const QString fileName,int channel)
{
    edfFile = edfopen_file_writeonly(fileName.toStdString().c_str(), EDFLIB_FILETYPE_EDFPLUS, channel);
    return edfFile;
}

int EdfGenerator::closeEdfFile(int localFile)
{
    edfclose_file(localFile);

return 1;
}

int EdfGenerator::generateEdfFile(int totalChannels,
                                  int * digitalMax,int * digitalMin,
                                  double * phyMax,double * phyMin,
                                  const QStringList & dimenList,const QStringList & labelList,int sampleFreq)
{
    int idx=0;
    for(idx=0 ; idx<totalChannels ; idx++ )
    {
        setChannelData(edfFile,idx,digitalMax[idx],digitalMin[idx],phyMax[idx],phyMin[idx],dimenList.at(idx),labelList.at(idx),sampleFreq);
    }

    if(edf_set_equipment(edfFile, "Airbox"))
    {
        qDebug("edf_set_equipment()\n");
        return 0;
    }

return 1;
}

int EdfGenerator::writeEdfLogData(double * channelData)
{
    if(edfwrite_physical_samples(edfFile, channelData))
    {
      qDebug("error: edfwrite_physical_samples()\n");
//      for(int i=0 ; i<1 ; i++)
//      {
//          qDebug(" %f ",channelData[i]);
//      }
      return 0;
    }

    return 1;
}

void EdfGenerator::readAllEdfFiles(void)
{
//    QString localPath = "/home/jigar/Desktop/LOG";
    QString localPath = "/root/LOG";

    QFileInfoList fileList;
    QDir dir(localPath);
    fileList.clear();
    fileList = dir.entryInfoList(QDir::NoDotAndDotDot|QDir::Dirs,QDir::Name);

    qDebug() << "readAllEdfFiles" << fileList.length();

    QString localFileName;
    QFileInfo localFileInfo;
    int index=0;
    int res=0;
    unsigned int eventInThatSession=0,usageTimeInSeconds=0;
    float usageHours=0;
    for( index = 0 ; index<fileList.length() ; index++)
    {
        localFileName.clear();
        localFileName = fileList.at(index).filePath() + "/" +fileList.at(index).fileName() + "E.edf";
        localFileInfo.setFile(localFileName);
        if(localFileInfo.exists())
        {
            qDebug() << "*************************************************************************************";
            res = readEventEdfFile(localFileName.toStdString().c_str(),&eventInThatSession,&usageTimeInSeconds);
            if(res){
                /* File read success print usage time & events */
                qDebug() << localFileName.toStdString().c_str() << eventInThatSession << usageTimeInSeconds;
                usageHours = static_cast<float>(usageTimeInSeconds)/60;
            }
        }
    }
}
int EdfGenerator::setChannelNo(int * chnNo)
{
    if((*chnNo) < 1)
    {
      qDebug("\nsignalnumber must be > 0\n\n");
      return -1;
    }

    if((*chnNo) > (hdr.edfsignals))
    {
      qDebug("\nerror: file has %i signals and you selected signal %i\n\n", hdr.edfsignals, *chnNo);
      return -1;
    }

    (*chnNo)--;

return 1;
}

int EdfGenerator::openEdfFileForReadOnly(const char * filePath)
{
    if(edfopen_file_readonly(filePath, &hdr, EDFLIB_DO_NOT_READ_ANNOTATIONS))
    {
      switch(hdr.filetype)
      {
        case EDFLIB_MALLOC_ERROR                : qDebug("\nmalloc error\n\n");
                                                  break;
        case EDFLIB_NO_SUCH_FILE_OR_DIRECTORY   : qDebug("\ncan not open file, no such file or directory\n\n");
                                                  break;
        case EDFLIB_FILE_CONTAINS_FORMAT_ERRORS : qDebug("\nthe file is not EDF(+) or BDF(+) compliant\n"
                                                         "(it contains format errors)\n\n");
                                                  break;
        case EDFLIB_MAXFILES_REACHED            : qDebug("\nto many files opened\n\n");
                                                  break;
        case EDFLIB_FILE_READ_ERROR             : qDebug("\na read error occurred\n\n");
                                                  break;
        case EDFLIB_FILE_ALREADY_OPENED         : qDebug("\nfile has already been opened\n\n");
                                                  break;
        default                                 : qDebug("\nunknown error\n\n");
                                                  break;
      }

      return -1;
    }

return hdr.handle;
}

int EdfGenerator::getAvailableSamplesInFile(int chn)
{
return hdr.signalparam[chn].smp_in_file;
}

int EdfGenerator::readAllDataFromFile(int fileHandle,double * dataSamples,int chn)
{
    int readCount=0;
    int x=0;

    readCount = getAvailableSamplesInFile(chn);

    /* Update x value to read data from an offset */
    edfseek(fileHandle, chn, (long long)((((double)x) / ((double)hdr.file_duration / (double)EDFLIB_TIME_DIMENSION)) * ((double)hdr.signalparam[chn].smp_in_file)), EDFSEEK_SET);

    /* read all the samples from the file */
    readCount = edfread_physical_samples(fileHandle, chn, readCount, dataSamples);

return readCount;
}

int EdfGenerator::readEventEdfFile(const char * filePath,unsigned int * eventsDuringSession,unsigned int * usageHoursInSession)
{
    int i,fileHandle,channel,totalSamplesInFile;
    int ret=0;
    double * tEventCodeBuffer;
    double * tEventDataBuffer;
    int tCloseFile = 0;

    /* Open EDF file to read */
    fileHandle = openEdfFileForReadOnly(filePath);
    if(fileHandle != -1)
    {
        /* Set channel no */
        channel = 7;
        ret = setChannelNo(&channel);
        if(ret)
        {
            /* Print EDF file info */
            printEdfFileInfo(channel);

            /* read all available samples from the file
             * for the specific channel
             */
            totalSamplesInFile = getAvailableSamplesInFile(channel);

            /* allocate memory to store data samples from file */
            tEventCodeBuffer = (double *)malloc(sizeof(double[totalSamplesInFile]));
            if(tEventCodeBuffer==NULL)
            {
              qDebug("\nmalloc error\n");
              closeEdfFile(fileHandle);
              free(tEventCodeBuffer);
            }

            /* Read all the samples from the file */
            totalSamplesInFile = readAllDataFromFile(fileHandle,tEventCodeBuffer,channel);
            if(totalSamplesInFile==(-1))
            {
              qDebug("\nerror: edf_read_physical_samples()\n");
              closeEdfFile(fileHandle);
              free(tEventCodeBuffer);
            }

            tCloseFile = 1;
        }
        if(ret != -1)
        {
            channel = 8;

            /* Set channel no */
            ret = setChannelNo(&channel);
            if(ret)
            {
                /* read all available samples from the file */
                totalSamplesInFile = getAvailableSamplesInFile(channel);

                /* allocate memory to store data samples from file */
                tEventDataBuffer = (double *)malloc(sizeof(double[totalSamplesInFile]));
                if(tEventDataBuffer == NULL)
                {
                  qDebug("\nmalloc error\n");
                  closeEdfFile(fileHandle);
                  free(tEventCodeBuffer);
                  free(tEventDataBuffer);
                }

                /* Read all the samples from the file */
                totalSamplesInFile = readAllDataFromFile(fileHandle,tEventDataBuffer,channel);
                if(totalSamplesInFile==(-1))
                {
                  qDebug("\nerror: edf_read_physical_samples()\n");
                  closeEdfFile(fileHandle);
                  free(tEventCodeBuffer);
                  free(tEventDataBuffer);
                }

                tCloseFile = 1;

                unsigned int tUsageHours=0,tTotalEvents=0;
                /* Update totalevents & usage time variables for this session */
                for(int j=0; j < totalSamplesInFile ; j++)
                {
//                    qDebug() << static_cast<unsigned int>(tEventCodeBuffer[j]) << static_cast<unsigned int>(tEventDataBuffer[j]);

                    /* Update total events in file */
                    if((static_cast<unsigned int>(tEventCodeBuffer[j]) == EVENT_TYPE_HYPOAPNEA) | (static_cast<unsigned int>(tEventCodeBuffer[j]) == EVENT_TYPE_APNEA) |
                        (static_cast<unsigned int>(tEventCodeBuffer[j]) == EVENT_TYPE_PRECURSOR) | (static_cast<unsigned int>(tEventCodeBuffer[j]) == EVENT_TYPE_APNEA2))
                        tTotalEvents++;

                    /* Update total hours machine used from file */
                    if(static_cast<unsigned int>(tEventCodeBuffer[j]) == EVENT_TYPE_USAGE_TIME)
                        tUsageHours += static_cast<unsigned int>(tEventDataBuffer[j]);
                }
//                qDebug() << "Events" << tTotalEvents << "Usage" << tUsageHours;
                *eventsDuringSession = tTotalEvents;
                *usageHoursInSession = tUsageHours;
            }
        }
    }

    if(tCloseFile)
    {
        qDebug("\n\n");
        closeEdfFile(fileHandle);
        free(tEventCodeBuffer);
        free(tEventDataBuffer);
    }

return 1;
}

int EdfGenerator::readLeakEdfFile(const char * filePath,float * leakDuringSession)
{
    int fileHandle,channel,totalSamplesInFile;
    int ret=0;
    double * tLeakBuffer;
    int tCloseFile = 0;

    /* Open EDF file to read */
    fileHandle = openEdfFileForReadOnly(filePath);
    if(fileHandle != -1)
    {
        /* Set channel no */
        channel = 2;
        ret = setChannelNo(&channel);
        if(ret)
        {
            /* Print EDF file info */
            printEdfFileInfo(channel);

            /* read all available samples from the file
             * for the specific channel
             */
            totalSamplesInFile = getAvailableSamplesInFile(channel);

            /* allocate memory to store data samples from file */
            tLeakBuffer = (double *)malloc(sizeof(double[totalSamplesInFile]));
            if(tLeakBuffer==NULL)
            {
              qDebug("\nmalloc error\n");
              closeEdfFile(fileHandle);
              free(tLeakBuffer);
              return -1;
            }

            /* Read all the samples from the file */
            totalSamplesInFile = readAllDataFromFile(fileHandle,tLeakBuffer,channel);
            if(totalSamplesInFile==(-1))
            {
              qDebug("\nerror: edf_read_physical_samples()\n");
              closeEdfFile(fileHandle);
              free(tLeakBuffer);
              return -1;
            }

            float tLeakage=0;
            /* Update totalevents & usage time variables for this session */
            for(int j=0; j < totalSamplesInFile ; j++)
            {
                /* Update total hours machine used from file */
                tLeakage += tLeakBuffer[j];
            }
            *leakDuringSession = tLeakage/totalSamplesInFile;
        }
     }

    if(tCloseFile)
    {
        qDebug("\n\n");
        closeEdfFile(fileHandle);
        free(tLeakBuffer);
        if(ret == -1)       return -1;
    }

return 1;
}
int EdfGenerator::printEdfFileInfo(int channel)
{
    if(edfFile < 0)
    {
        qDebug("\nlibrary version: %i.%02i\n", edflib_version() / 100, edflib_version() % 100);

        qDebug("\ngeneral header:\n\n");

        qDebug("filetype: %i\n", hdr.filetype);
        qDebug("edfsignals: %i\n", hdr.edfsignals);

        qDebug("file duration: %lli seconds\n", hdr.file_duration / EDFLIB_TIME_DIMENSION);

        qDebug("startdate: %i-%i-%i\n", hdr.startdate_day, hdr.startdate_month, hdr.startdate_year);
        qDebug("starttime: %i:%02i:%02i\n", hdr.starttime_hour, hdr.starttime_minute, hdr.starttime_second);
        qDebug("patient: %s\n", hdr.patient);
        qDebug("recording: %s\n", hdr.recording);
        qDebug("patientcode: %s\n", hdr.patientcode);
        qDebug("gender: %s\n", hdr.gender);
        qDebug("birthdate: %s\n", hdr.birthdate);
        qDebug("patient_name: %s\n", hdr.patient_name);
        qDebug("patient_additional: %s\n", hdr.patient_additional);
        qDebug("admincode: %s\n", hdr.admincode);
        qDebug("technician: %s\n", hdr.technician);
        qDebug("equipment: %s\n", hdr.equipment);
        qDebug("recording_additional: %s\n", hdr.recording_additional);
        qDebug("datarecord duration: %f seconds\n", ((double)hdr.datarecord_duration) / EDFLIB_TIME_DIMENSION);

        qDebug("number of datarecords in the file: %lli\n", hdr.datarecords_in_file);
        qDebug("number of annotations in the file: %lli\n", hdr.annotations_in_file);

        qDebug("\nsignal parameters:\n\n");

        qDebug("label: %s\n", hdr.signalparam[channel].label);

        qDebug("samples in file: %lli\n", hdr.signalparam[channel].smp_in_file);

        qDebug("samples in datarecord: %i\n", hdr.signalparam[channel].smp_in_datarecord);
        qDebug("physical maximum: %f\n", hdr.signalparam[channel].phys_max);
        qDebug("physical minimum: %f\n", hdr.signalparam[channel].phys_min);
        qDebug("digital maximum: %i\n", hdr.signalparam[channel].dig_max);
        qDebug("digital minimum: %i\n", hdr.signalparam[channel].dig_min);
        qDebug("physical dimension: %s\n", hdr.signalparam[channel].physdimension);
        qDebug("prefilter: %s\n", hdr.signalparam[channel].prefilter);
        qDebug("transducer: %s\n", hdr.signalparam[channel].transducer);
        qDebug("samplefrequency: %f\n", ((double)hdr.signalparam[channel].smp_in_datarecord / (double)hdr.datarecord_duration) * EDFLIB_TIME_DIMENSION);

        struct edf_annotation_struct annot;

        qDebug("\n");

        int i=0;
        for(i=0; i<hdr.annotations_in_file; i++)
        {
          if(edf_get_annotation(edfFile, i, &annot))
          {
            qDebug("\nerror: edf_get_annotations()\n");
            closeEdfFile(edfFile);
            return 0;
          }
          else
          {
            qDebug("annotation: onset is %lli    duration is %s    description is %s\n",
                  annot.onset / EDFLIB_TIME_DIMENSION,
                  annot.duration,
                  annot.annotation);
          }
        }
    }

return 1;
}
