#include "diagnosticdatascreen.h"
#include "ui_diagnosticdatascreen.h"
#include "ex_variables.h"

DiagnosticDataScreen::DiagnosticDataScreen(QWidget *parent,
                                                                     DataValidation * dataValidationBackend)
    : QDialog(parent),
    ui(new Ui::DiagnosticDataScreen),
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
    }

    QFont title("Roboto-Light",9);
    ui->diagDataTitle->setFont(title);

    title.setPointSize(10);
    ui->diagDataAccept->setFont(title);
    ui->diagDataCancel->setFont(title);

    updateDiagDataProcessBeforeShow();
}

DiagnosticDataScreen::~DiagnosticDataScreen()
{
    delete ui;
}

void DiagnosticDataScreen::updateDiagDataProcessBeforeShow(void)
{
    diagnosticData = globalVar.diagnosticData;
    if(diagnosticData == On){
        ui->onRadio->setChecked(true);
    } else {
        ui->offRadio->setChecked(true);
    }
}

void DiagnosticDataScreen::on_diagDataAccept_released()
{
    globalVar.diagnosticData = diagnosticData;
    emit dialogClose();
    parentEffect->setEnabled(false);

    // Update Data to EEPROM
    emit writeParameterToEeprom();

    hide();
    setModal(false);
}

void DiagnosticDataScreen::on_diagDataCancel_released()
{
    parentEffect->setEnabled(false);
    hide();
    setModal(false);
}

void DiagnosticDataScreen::on_offRadio_pressed()
{
    diagnosticData = Off;
}

void DiagnosticDataScreen::on_onRadio_pressed()
{
    diagnosticData = On;
}

void DiagnosticDataScreen::showDiagnosticDataScreen()
{
    updateDiagDataProcessBeforeShow();
    parentEffect->setEnabled(true);
    setModal(true);
    show();
}

void DiagnosticDataScreen::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
