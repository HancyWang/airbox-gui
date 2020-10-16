#include "restoredefaultswindowclinical.h"
#include "ui_restoredefaultswindowclinical.h"
#include "ex_variables.h"

RestoreDefaultsWindowClinical::RestoreDefaultsWindowClinical(QWidget *parent,
                                                             DataValidation * dataValidationBackend)
    : QDialog(parent),
    ui(new Ui::RestoreDefaultsWindowClinical),
    dataValidation(dataValidationBackend),
    parentEffect(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setAttribute(Qt::WA_TranslucentBackground,true);
    move(60,56);


    if(dataValidation)
    {
        connect(this,SIGNAL(writeParameterToEeprom()),
                dataValidation,SLOT(writeParameterToEeprom()));
        connect(this,SIGNAL(factoryDefaultVariables()),
                dataValidation,SLOT(factoryDefaultVariables()));
    }

    QFont title("Roboto-Light",9);
    ui->restoreFactoryTitle->setFont(title);
    ui->restoreFactoryWarning->setFont(title);

    title.setPointSize(10);
    ui->restoreFactoryNo->setFont(title);
    ui->restoreFactoryYes->setFont(title);
}

RestoreDefaultsWindowClinical::~RestoreDefaultsWindowClinical()
{
    delete ui;
}

void RestoreDefaultsWindowClinical::on_restoreFactoryYes_released()
{
    emit factoryDefaultVariables();
    emit writeParameterToEeprom();

    // Restore tunning parameters to default
    emit restoreDefaultTunningParameters();

    parentEffect->setEnabled(false);
    hide();
    setModal(false);
}

void RestoreDefaultsWindowClinical::on_restoreFactoryNo_released()
{
    parentEffect->setEnabled(false);
    hide();
    setModal(false);
}

void RestoreDefaultsWindowClinical::showRestoreDefaultScreen()
{
    parentEffect->setEnabled(true);
    setModal(true);
    show();
}

void RestoreDefaultsWindowClinical::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
