#include "maskfittestoptionsbasic.h"
#include "ui_maskfittestoptionsbasic.h"
#include "ex_variables.h"


MaskFitTestOptionsBasic::MaskFitTestOptionsBasic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MaskFitTestOptionsBasic),
    parentEffect(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setAttribute(Qt::WA_TranslucentBackground,true);
    move(60,56);

    ui->maskFitTestProgressBar->hide();

    QFont title("Roboto-Light",9);
    ui->maskFitTestTitle->setFont(title);
    ui->maskFitTestStartStop->setFont(title);

    title.setPointSize(10);
    ui->maskFitTestCancel->setFont(title);

    updateMaskFitTestProcessBeforeShow();

}

MaskFitTestOptionsBasic::~MaskFitTestOptionsBasic()
{
    delete ui;
}

void MaskFitTestOptionsBasic::updateMaskFitTestProcessBeforeShow(void)
{
    if(globalVar.maskFitTest.maskFitTestState != On)
    {
        maskFitTestState = false;
        maskFitTest = badMaskFit;
        ui->maskFitTestProgressBar->setValue(0);
    }
}

void MaskFitTestOptionsBasic::on_maskFitTestStartStop_released()
{
    if((globalVar.therapyState == Off) | (globalVar.maskFitTest.maskFitTestState == On))
    {
        maskFitTestState = !maskFitTestState;
        updateStartStopButton();
    }
}
void MaskFitTestOptionsBasic::updateStartStopButton(void)
{
    if(maskFitTestState == true)
    {
        ui->maskFitTestProgressBar->setValue(0);
        ui->maskFitTestProgressBar->show();
        ui->maskFitTestStartStop->setText("Stop Test");
        globalVar.maskFitTest.maskFitTestState = On;
        globalVar.therapyState = On;
    }
    else
    {
        ui->maskFitTestProgressBar->hide();
        ui->maskFitTestStartStop->setText("Start Test");
        globalVar.maskFitTest.maskFitTestState = Off;
        globalVar.therapyState = Off;
    }
}

void MaskFitTestOptionsBasic::on_maskFitTestCancel_released()
{
    if(globalVar.maskFitTest.maskFitTestState == On)
    {
        globalVar.maskFitTest.maskFitTestState = Off;
        maskFitTestState = Off;
        globalVar.therapyState = Off;
        updateStartStopButton();
    }

    parentEffect->setEnabled(false);
    emit dialogClose();
    hide();
    setModal(false);
    disconnect(this, SIGNAL(dialogClose()),0,0);
}

void MaskFitTestOptionsBasic::showMaskFitTestScreen()
{
    updateMaskFitTestProcessBeforeShow();
    parentEffect->setEnabled(true);
    setModal(true);
    show();
}

#define MAX_MASK_FIT_TEST_TIME      30
void MaskFitTestOptionsBasic::updateProgressBarAsPerSeconds(int seconds,unsigned int status)
{
float percentage=0;
float stepSize=0;
    if(seconds != MAX_MASK_FIT_TEST_TIME)
    {
        stepSize = static_cast<float>(100)/MAX_MASK_FIT_TEST_TIME;
        percentage = seconds * stepSize;
        if(static_cast<int>(percentage))
        {
            ui->maskFitTestProgressBar->setValue(static_cast<int>(percentage));
        }
    }
    else
    {
        ui->maskFitTestProgressBar->setValue(100);
        globalVar.maskFitTest.maskFitTestStatus = static_cast<maskFitParam>(status);
        maskFitTest = globalVar.maskFitTest.maskFitTestStatus;
        maskFitTestState = Off;
        updateStartStopButton();
    }
}

void MaskFitTestOptionsBasic::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}

