#include "variables.h"
#include "screens/backgroundwindow.h"
#include <QFontDatabase>
#include <QElapsedTimer>

#define		CRC_START_32		0xFFFFFFFFul

//QT_QPA_EGLFS_FORCE888=1
//QT_QPA_EGLFS_INTEGRATION=none
//QT_QPA_EGLFS_PHYSICAL_HEIGHT=53
//QT_QPA_EGLFS_PHYSICAL_WIDTH=95
//QT_QPA_EGLFS_ROTATION=180
//XDG_RUNTIME_DIR=/tmp/runtime-airbox

#if defined(_APP_DEVELOPMENT_BUILD) && defined(_APP_PRODUCTION_BUILD)
#error Multiple defined Need to define _APP_DEVELOPMENT_BUILD else _APP_PRODUCTION_BUILD
#endif

#if !defined(_APP_DEVELOPMENT_BUILD) && !defined(_APP_PRODUCTION_BUILD)
#error Need to define _APP_DEVELOPMENT_BUILD or _APP_PRODUCTION_BUILD
#endif

void myMessageHandler(QtMsgType type, const QMessageLogContext &,
                      const QString &msg)
{
    QString txt;
    switch (type)
    {
        case QtDebugMsg:
            txt = QString("DEBUG    : %1").arg(msg);
            break;
        case QtWarningMsg:
            txt = QString("WARNING  : %1").arg(msg);
            break;
        case QtCriticalMsg:
            txt = QString("CRITICAL : %1").arg(msg);
            break;
        case QtFatalMsg:
            txt = QString("FATAL    : %1").arg(msg);
            break;
        case QtInfoMsg:
            txt = QString("INFO     : %1").arg(msg);
            break;
    }
    txt = "\n " + txt;

    QFile console("/dev/console");
    QTextStream textStream(&console);
    if(console.exists())
    {
        if(!console.isOpen())
        {
            console.open(QIODevice::WriteOnly);
            textStream << txt;
            console.close();
        }
    }
}

#include <QApplication>
#include <QLoggingCategory>
#include <QTranslator>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    //use the flag to control compile "airbox" for am335x
    globalVar.b_enable_compile_airbox_arm_code=true;

    QLoggingCategory::setFilterRules(QStringLiteral("qt.bluetooth* = true"));
    QApplication a(argc, argv);
    //globalVar.app=&a;
//    qInstallMessageHandler(myMessageHandler);

    // Create the DataValidation Object - this will load the global variables
    DataValidation *pDataValidateObj = new DataValidation(&a);


    QTextCodec* codec=QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);


    // Handle the Language Setting
    // Create the translator object
    //QTranslator nTranslator;
    globalVar.nTranslator=new QTranslator;
    bool bTranslationLoaded = false;


    // TODO Delete Debug Test
    //globalVar.language = language_english;
    QString qm_str;

    // Setup the translations and fonts based on the language
    if(globalVar.language == language_chinese)
    {
        // Chinese
        // Asian Languages
        /*
        QFontDatabase::addApplicationFont(":/fonts/Roboto/Roboto-Light.ttf");
        QFontDatabase::addApplicationFont(":/fonts/Roboto/Roboto-Regular.ttf");
        QFontDatabase::addApplicationFont(":/fonts/Roboto/Roboto-Thin.ttf");*/

        if(globalVar.b_enable_compile_airbox_arm_code)
        {
            QFontDatabase::addApplicationFont("/usr/share/mime/font/SourceHanSansCN-Regular.ttf");
            qm_str="/home/root/chinese.qm";
        }
        else
        {
            QFontDatabase::addApplicationFont(":/fonts/Roboto/SourceHanSansCN-Regular.ttf");
            qm_str=":/chinese.qm";
        }
        // Based on the language switch the font type
        // insertSubstitution - Appears to not work on embedded
        //QFont::insertSubstitution("Roboto", "Han Sans");



        //QFontDatabase::addApplicationFont(":/fonts/Roboto/SourceHanSansCN-Regular.ttf");
        //QFont::insertSubstitution(QString::fromLocal8Bit("微软雅黑"), QString::fromLocal8Bit("宋体"));
        //QStringList list = QFont::substitutes(QString::fromLocal8Bit("微软雅黑"));

        qDebug() << "Main: Set Chinese";
        // Load the translation file

        if( globalVar.nTranslator->load(qm_str))
        {

            // Note we loaded a translation
            bTranslationLoaded = true;
        }
    }
    else if(globalVar.language == language_japanese)
    {
        if(globalVar.b_enable_compile_airbox_arm_code)
        {
            QFontDatabase::addApplicationFont("/usr/share/mime/font/SourceHanSansCN-Regular.ttf");
            qm_str="/home/root/japanese.qm";
        }
        else
        {
            QFontDatabase::addApplicationFont(":/fonts/Roboto/SourceHanSansCN-Regular.ttf");
            qm_str=":/japanese.qm";
        }

        qDebug() << "Main: Set Japanese";
        // Load the translation file

        if( globalVar.nTranslator->load(qm_str) )
        {
            // Note we loaded a translation
            bTranslationLoaded = true;
        }
    }
    else if(globalVar.language == language_spanish)
    {
        // Spanish
        // Latin Languages
        QFontDatabase::addApplicationFont(":/fonts/Roboto/Roboto-Light.ttf");
        QFontDatabase::addApplicationFont(":/fonts/Roboto/Roboto-Regular.ttf");
        QFontDatabase::addApplicationFont(":/fonts/Roboto/Roboto-Thin.ttf");
        // insertSubstitution - Appears to not work on embedded
        //QFont::insertSubstitution("Roboto", "Droid Sans");

        qDebug() << "Main: Set Spanish";
        // Load the translation file

        if(globalVar.b_enable_compile_airbox_arm_code)
        {
            qm_str="/home/root/spanish.qm";
        }
        else
        {
            qm_str=":/spanish.qm";
        }

        if( globalVar.nTranslator->load(qm_str) )
        {
            // Note we loaded a translation
            bTranslationLoaded = true;
        }
    }
    else
    {
        // English - or default to english on bad setting
        // Do nothing
        /* Add Fonts in Application */
        // Latin Languages
        QFontDatabase::addApplicationFont(":/fonts/Roboto/Roboto-Light.ttf");
        QFontDatabase::addApplicationFont(":/fonts/Roboto/Roboto-Regular.ttf");
        QFontDatabase::addApplicationFont(":/fonts/Roboto/Roboto-Thin.ttf");
    }

    // Install the Translator if not english
    if(bTranslationLoaded == true)
    {
        // Install the translation into the application
        a.installTranslator(globalVar.nTranslator);
    }


#ifdef _APP_DEVELOPMENT_BUILD
    /* TODO Remove for productions use */
    QElapsedTimer qElpTimer;
    qElpTimer.start();
#endif

    a.setApplicationName(Providers::getDeviceInformationString(DEVICE_NAME));
    a.setApplicationVersion(Providers::getDeviceInformationString(SOFTWARE_VERSION));


    /* Create Parent Window/Background screen
     * Which will handle all the backgroud stuff
     * creating screen/IPC communication/Thread creation
     */
    BackgroundWindow backgroundScreen(pDataValidateObj);

    /* Show Background Window */
    backgroundScreen.show();

    QDate buildDate(QDate::fromString(__DATE__,"MMM d yyyy"));
    QTime buildTime(QTime::fromString(__TIME__,"h:m:s"));
    QDate today(QDate::currentDate());
    qint64 leftDays = buildDate.daysTo(today);
#ifdef _APP_DEVELOPMENT_BUILD
    qDebug() << __DATE__ << __TIME__ << leftDays << QDate::currentDate() << buildDate << buildTime;
#endif
    if(leftDays < 0) {
        /* Error in Date & time
         * Update System date to build date
         */
        backgroundScreen.tErrorInRTC = true;
        qDebug() << "Error in RTC";
    }


#ifdef _APP_DEVELOPMENT_BUILD
    qDebug() << "Application launch & Show Time:" << qElpTimer.nsecsElapsed() << qElpTimer.elapsed();
#endif

    return a.exec();
}


