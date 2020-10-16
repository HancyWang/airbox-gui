//______________________________________________________________________________
//------------------------------------------------------------------------------
/*!
    \file       CNVMApp.h

    \brief      NVM Manager Device Class Declaration

    $Rev: $
    $Author: $
    $Date: $
    $URL: $

    Copyright (c) 2020 - InnoRevision Inc. - All Right Reserved

    The code contained in this file is confidential and may only be used
    under license and/or written consent of InnoRevision and/or Fresca Medical.
*/
//______________________________________________________________________________
//------------------------------------------------------------------------------


#ifndef __CNVMAPP_H__
#define __CNVMAPP_H__


//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <QObject>
#include <QStringList>
#include <QFile>



//-----------------------------------------------------------------------------
// Defines
//-----------------------------------------------------------------------------
// forward declaration
class CNVMApp;
// get the singleton object pointer
#define NVMAPP_OBJPTR           CNVMApp::GetSingletonObjectPtr()


//-------------------------------------
// NVM Settings uSD Card File Location
//-------------------------------------
#ifdef _APP_DEVELOPMENT_BUILD
    #define NVMFILE_APPCONFIG       "/Projects/FrescaRepo/00-Code/airbox_software/airbox-gui/appeeprom"
#elif defined(_APP_PRODUCTION_BUILD)
    #define NVMFILE_APPCONFIG       "/sys/bus/i2c/devices/0-0050/appeeprom"
#endif


//-------------------------------------
// Application NVM Settings Structure
//-------------------------------------
// NOTE: Must be 4-byte aligned values
typedef struct
{
    uint32_t nLanguage;                   ///< Language Setting for the Application
    // TODO - Insert Any other app configurations here
    uint32_t nCRC;                        ///< CRC of the NVM Data Structure (minus the CRC)
} NVMAPP_APPCONFIG;

// Size of the App Config Structure
#define NVMAPP_APPCONFIG_SIZE       sizeof(NVMAPP_APPCONFIG)


//______________________________________________________________________________
//------------------------------------------------------------------------------
/*!
    \class      CNVMApp

    \brief      Overall Application Non-Volatile Manager handler class.
    \note       The Non-Volatile Manger is a singleton which allows global access
                to all public functions.  NVM Settings are singular storage objects
                that store and retrieve only the currently set value.
*/
//______________________________________________________________________________
//------------------------------------------------------------------------------
class CNVMApp :QObject
{
public:
    /// Default Constructor
    CNVMApp(QObject *parent = nullptr);       ///< Polling interval of this device (in OS ticks)

    /// Get the Object
    static CNVMApp *GetSingletonObjectPtr() { return m_pObj; }

    /// Start the NVM Manger Service
    bool StartNVMMgr();

    /// Stop the NVM Manger Service
    bool StopNVMMgr();

    //---------------------------------
    // Specific Setting Getters
    //---------------------------------
    /// Get Language
    uint32_t GetLanguage();
    /// Get Language
    bool SetLanguage(uint32_t nLanguage);

protected:
    // Provide singleton object
    static CNVMApp *m_pObj;              ///< Singleton object pointer

    // File Pointer for the NVM Settings
    QFile *m_pFile;

    //-------------------------------------
    // Static Data Object for the NVM Setting
    //-------------------------------------
    // Application Configuration
    static NVMAPP_APPCONFIG    m_nAppConfig;

    // Default the NVM Data
    void DefaultNVMData();
    // Read the NVM Data File
    bool ReadNVMDataFile();
    // Write the NVM Data File
    bool WriteNVMDataFile();


    //-------------------------------------
    // Utility Functions
    //-------------------------------------
    /// Calculate a CRC 32
    uint32_t crc32(uint32_t nSeed, uint8_t const *pData, uint32_t nLen);
    /// Get a INT32 from a buffer
    uint32_t GetINT32fromBuffer(uint8_t *pBuffer);
    /// Put a 32 bit word into an unaligned buffer (at the current buffer pointer location) Note - overwrites existing data at location)
    void PutINT32inBuffer(uint32_t word, uint8_t *pBuffer);


};

#endif /* __CNVMAPP_H__ */
