#include "selectlanguagewindowclinical.h"
#include "ui_selectlanguagewindowclinical.h"
#include "ex_variables.h"
#include <QTranslator>
#include <QFontDatabase>
#include <QTextCodec>

SelectLanguageWindowClinical::SelectLanguageWindowClinical(QWidget *parent,
                                                                   SettingsWindowBasic * settingsBasicBackend,
                                                                   DataValidation * dataValidationBackend)
    : QDialog(parent),
    ui(new Ui::SelectLanguageWindowClinical),
    settingsBasicScreen(settingsBasicBackend),
    dataValidation(dataValidationBackend),
    parentEffect(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setAttribute(Qt::WA_TranslucentBackground,true);
    move(60,56);

    if(settingsBasicScreen)
    {
        connect(settingsBasicBackend,SIGNAL(showSelectLanguageClinicalScreen()),
                this,SLOT(showSelectLanguageClinicalScreen()));
    }

    if(dataValidation)
    {
        connect(this,SIGNAL(writeParameterToEeprom()),
                dataValidation,SLOT(writeParameterToEeprom()));
    }

    QFont title("Roboto-Light",9);
    //QFont title("SourceHanSansCN-Regular",9);
    ui->languageTitle->setFont(title);

    title.setPointSize(10);
    ui->languageAccept->setFont(title);
    ui->languageCancel->setFont(title);

    // Not required
    //ui->chinese->hide();
    //ui->spanish->hide();


    updateLangInLangSelectProcessBeforeShow();
}

SelectLanguageWindowClinical::~SelectLanguageWindowClinical()
{
    delete ui;
}

void SelectLanguageWindowClinical::on_languageAccept_released()
{
    // Save the new local language (selection) to the global variable
    //globalVar.language = localLanguage;
    emit dialogClose();
    parentEffect->setEnabled(false);

    updateLanguageAfterSelected();
    // Update Data to EEPROM
    emit writeParameterToEeprom();

    hide();
    setModal(false);
    disconnect(this, SIGNAL(dialogClose()),0,0);
}

void SelectLanguageWindowClinical::on_languageCancel_released()
{
    parentEffect->setEnabled(false);
    hide();
    setModal(false);
    disconnect(this, SIGNAL(dialogClose()),0,0);
}

void SelectLanguageWindowClinical::on_english_pressed()
{
    localLanguage = language_english;
}

void SelectLanguageWindowClinical::on_chinese_pressed()
{
    localLanguage = language_chinese;
}

void SelectLanguageWindowClinical::on_japanese_pressed()
{
    localLanguage = language_japanese;
}

void SelectLanguageWindowClinical::showSelectLanguageClinicalScreen()
{
    connect(this, SIGNAL(dialogClose()),settingsBasicScreen,SLOT(maskButtonClosed()));
    updateLangInLangSelectProcessBeforeShow();
    parentEffect->setEnabled(true);
    setModal(true);
    show();
}

void SelectLanguageWindowClinical::updateLangInLangSelectProcessBeforeShow(void)
{
    //globalVar.language=localLanguage;
    localLanguage=globalVar.language;
    if(localLanguage == language_chinese)
    {
        ui->chinese->setChecked(true);
    }
    else if(localLanguage == language_japanese)
    {
        ui->japanese->setChecked(true);
    }
    else
    {
        ui->english->setChecked(true);
    }

}


void SelectLanguageWindowClinical::updateLanguageAfterSelected()
{
    //if do not change the language,then return
    if(globalVar.language==localLanguage)
    {
        return;
    }
    globalVar.language=localLanguage;

    if(localLanguage == language_chinese)
    {
        ui->chinese->setChecked(true);
    }
    else if(localLanguage == language_japanese)
    {
        ui->japanese->setChecked(true);
    }
    else
    {
        ui->english->setChecked(true);
    }

    QTextCodec* codec=QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);
    bool bTranslationLoaded=false;
    QString qm_str;

    //static QTranslator* nTranslator;
    if(globalVar.nTranslator!=NULL)
    {
//       globalVar.app->removeTranslator(globalVar.nTranslator);
       qApp->removeTranslator(globalVar.nTranslator);
       delete globalVar.nTranslator;
       globalVar.nTranslator=NULL;
    }

    globalVar.nTranslator =new QTranslator;
    if(globalVar.language == language_chinese)
    {
        // Chinese
        // Asian Languages
//        QFontDatabase::addApplicationFont(":/fonts/Roboto/Roboto-Light.ttf");
//        QFontDatabase::addApplicationFont(":/fonts/Roboto/Roboto-Regular.ttf");
//        QFontDatabase::addApplicationFont(":/fonts/Roboto/Roboto-Thin.ttf");
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

         qDebug() << "select language: Set Chinese";
        // Load the translation file

        if( globalVar.nTranslator->load(qm_str) )
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

        qDebug() << "select language: Set Japanese";
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

        if(globalVar.b_enable_compile_airbox_arm_code)
        {
            qm_str="/home/root/spanish.qm";
        }
        else
        {
            qm_str=":/spanish.qm";
        }

        qDebug() << "select language: Set Spanish ";
        // Load the translation file
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

        qDebug() << "select language: Set English";
        bTranslationLoaded = true;
    }

    // Install the Translator if not english
    if(bTranslationLoaded == true)
    {
        // Install the translation into the application
//        globalVar.app->installTranslator(globalVar.nTranslator);
         qApp->installTranslator(globalVar.nTranslator);
    }
   // ui->retranslateUi(this);

}

void SelectLanguageWindowClinical::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}

