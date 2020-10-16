#include "pressureoffsetscreen.h"
#include "ui_pressureoffsetscreen.h"
#include "ex_variables.h"

int PressureOffsetScreen::pressureOffset = 0;


PressureOffsetScreen::PressureOffsetScreen(QWidget *parent,
                                           PruControlClass * m_IpcBackend,
                                           DataValidation * dataValidationBackend)
    : QDialog(parent),
    ui(new Ui::PressureOffsetScreen),
    m_IpcManager(m_IpcBackend),
    dataValidation(dataValidationBackend),
    parentEffect(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setAttribute(Qt::WA_TranslucentBackground,true);
    move(60,56);

    if(m_IpcManager)
    {
        connect(this,SIGNAL(beforePressureOffsetGetProcedure()),
                m_IpcManager,SLOT(beforePressureOffsetGetProcedure()));
        connect(m_IpcManager,SIGNAL(updatePressureSensorOffset(int)),
                this,SLOT(updatePressureSensorOffset(int)));
    }

    if(dataValidation)
    {
        connect(this,SIGNAL(writeParameterToEeprom()),
                dataValidation,SLOT(writeParameterToEeprom()));
    }

    QFont title("Roboto-Light",9);
    ui->pressureOffsetTitle->setFont(title);

    title.setPointSize(12);
    ui->pressureOffsetAuto->setFont(title);

    title.setPointSize(10);
    ui->pressureOffsetAccept->setFont(title);
    ui->pressureOffsetCancel->setFont(title);

    QFont valueFont("Roboto-Thin",26);
    ui->pressureOffsetValue->setFont(valueFont);
}

PressureOffsetScreen::~PressureOffsetScreen()
{
    delete ui;
}

void PressureOffsetScreen::on_pressureOffsetAuto_pressed()
{
    emit beforePressureOffsetGetProcedure();
}

void PressureOffsetScreen::on_pressureOffsetAccept_released()
{
    globalVar.pressure.pressureOffset = static_cast<int>(pressureOffset);

    // Update Data to EEPROM
    emit writeParameterToEeprom();

    parentEffect->setEnabled(false);
    hide();
    emit dialogClose();
    setModal(false);
}

void PressureOffsetScreen::on_pressureOffsetCancel_released()
{
    pressureOffset = globalVar.pressure.pressureOffset;
    parentEffect->setEnabled(false);
    hide();
    setModal(false);
}

void PressureOffsetScreen::updatePressureSensorOffsetScreenBeforeShow()
{
    pressureOffset = globalVar.pressure.pressureOffset;
    updatePressureSensorOffset(globalVar.pressure.pressureOffset);
}

void PressureOffsetScreen::updatePressureSensorOffset(int offset)
{
    pressureOffset = offset;
    ui->pressureOffsetValue->setText(QString::number(pressureOffset));
}

void PressureOffsetScreen::showPressureOffsetScreen()
{
    parentEffect->setEnabled(true);
    setModal(true);
    updatePressureSensorOffsetScreenBeforeShow();
    show();
}

void PressureOffsetScreen::on_pressureOffsetDecrease_released()
{
    if(pressureOffset)     pressureOffset--;
    updatePressureSensorOffset(pressureOffset);
}

void PressureOffsetScreen::on_pressureOffsetIncrease_released()
{
    if(pressureOffset < 4096)     pressureOffset++;
    updatePressureSensorOffset(pressureOffset);
}


void PressureOffsetScreen::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
