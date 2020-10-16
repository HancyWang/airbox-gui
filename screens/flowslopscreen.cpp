#include "flowslopscreen.h"
#include "ui_flowslopscreen.h"
#include "ex_variables.h"

FlowSlopScreen::FlowSlopScreen(QWidget *parent,
                               DataValidation * dataValidationBackend)
    : QDialog(parent),
    ui(new Ui::FlowSlopScreen),
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
    ui->flowSlopTitle->setFont(title);
    ui->flowSlopTitle->setText("Flow Threshold");

    title.setPointSize(10);
    ui->flowSlopAccept->setFont(title);
    ui->flowSlopCancel->setFont(title);

    QFont valueFont("Roboto-Thin",26);
    ui->flowSlopValue->setFont(valueFont);
}

FlowSlopScreen::~FlowSlopScreen()
{
    delete ui;
}

void FlowSlopScreen::on_flowSlopDecrease_released()
{
    if(flowSlop)     flowSlop--;
    updateFlowSensorSlop(flowSlop);
}

void FlowSlopScreen::on_flowSlopIncrease_released()
{
    if(flowSlop < 4096)     flowSlop++;
    updateFlowSensorSlop(flowSlop);
}

void FlowSlopScreen::on_flowSlopAccept_released()
{
//    globalVar.flow.slop = static_cast<int>(flowSlop);
    globalVar.flow.threshold = flowSlop;

    // Update Data to EEPROM
    emit writeParameterToEeprom();

    parentEffect->setEnabled(false);
    hide();
    emit dialogClose();
    setModal(false);
}

void FlowSlopScreen::on_flowSlopCancel_released()
{
//    flowSlop = globalVar.flow.slop;
    flowSlop = globalVar.flow.threshold;
    parentEffect->setEnabled(false);
    hide();
    setModal(false);
}

void FlowSlopScreen::updateFlowSensorSlopScreenBeforeShow()
{
    flowSlop = globalVar.flow.threshold;
//    flowSlop = globalVar.flow.slop;
    updateFlowSensorSlop(flowSlop);
}

void FlowSlopScreen::updateFlowSensorSlop(int slop)
{
    flowSlop = slop;
    ui->flowSlopValue->setText(QString::number(flowSlop));
}

void FlowSlopScreen::showFlowSlopScreen()
{
    parentEffect->setEnabled(true);
    setModal(true);
    updateFlowSensorSlopScreenBeforeShow();
    show();
}


void FlowSlopScreen::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
