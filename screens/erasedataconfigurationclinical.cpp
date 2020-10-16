#include "erasedataconfigurationclinical.h"
#include "ui_erasedataconfigurationclinical.h"
#include "ex_variables.h"

EraseDataConfigurationClinical::EraseDataConfigurationClinical(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EraseDataConfigurationClinical),
    parentEffect(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground,true);
    setAttribute(Qt::WA_DeleteOnClose,true);
    move(60,56);

    QFont title("Roboto-Light",9);
    ui->eraseDataTitle->setFont(title);
    ui->eraseDataWarning->setFont(title);

    title.setPointSize(10);
    ui->eraseDataNo->setFont(title);
    ui->eraseDataYes->setFont(title);
}

EraseDataConfigurationClinical::~EraseDataConfigurationClinical()
{
    delete ui;
}

void EraseDataConfigurationClinical::on_eraseDataYes_released()
{
    /* Erase all the data */
    eraseAllFiles();

    parentEffect->setEnabled(false);
    hide();
    setModal(false);
}

void EraseDataConfigurationClinical::on_eraseDataNo_released()
{
    parentEffect->setEnabled(false);
    hide();
    setModal(false);
}

void EraseDataConfigurationClinical::showEraseDataScreen()
{
    parentEffect->setEnabled(true);
    setModal(true);
    show();
}

void EraseDataConfigurationClinical::eraseAllFiles(void)
{
    /* Set edf Folder path to remove from directory */
    QDir logDirectory(Providers::getEdfLogFilesPath());

    /* Remove all the files & folders recurssively */
    logDirectory.removeRecursively();
}


void EraseDataConfigurationClinical::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
