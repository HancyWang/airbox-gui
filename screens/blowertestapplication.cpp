#include "blowertestapplication.h"
#include "ui_blowertestapplication.h"
#include "screens/manufacturingoptionsscreen.h"

#include <QFile>


int BlowerTestApplication::count = 7;
int BlowerTestApplication::blowerState = 0;
int BlowerTestApplication::brakePercent = 0;
int BlowerTestApplication::brakeType = 3;

BlowerTestApplication::BlowerTestApplication(QWidget *parent,
                                             ManufacturingOptionsScreen * manufacturingOptionsBackend)
    : QDialog(parent),
    ui(new Ui::BlowerTestApplication),
    manufacturingOptionsScreen(manufacturingOptionsBackend)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setMonitoringStatus(blowerState);
    setGeometry(0,0,width(),height());
    ui->noBrakeButton->setChecked(true);

    if(manufacturingOptionsScreen)
    {
        connect(manufacturingOptionsScreen,SIGNAL(showBlowerTestScreen()),
                this,SLOT(show()));
    }

    ui->resBrakeButton->hide();
    ui->plugBrakeButton->hide();
    ui->noBrakeButton->hide();
    ui->brakeDecrementButton->hide();
    ui->brakeIncrementButton->hide();
    QString s = QString::number(this->count);
    ui->rpmValue->setText(s);
}

BlowerTestApplication::~BlowerTestApplication()
{
    delete ui;
}

void BlowerTestApplication::updateBlowerPwmControl(void)
{
    QFile pwmChip1("/sys/class/pwm/pwmchip1/export");
    pwmChip1.open(QIODevice::WriteOnly);
    pwmChip1.write("0");
    pwmChip1.close();

    QFile pwmChipPeriod("/sys/class/pwm/pwmchip1/pwm0/period");
    pwmChipPeriod.open(QIODevice::WriteOnly);
    pwmChipPeriod.write("6250");
    pwmChipPeriod.close();

    QFile pwmChipDutyCycle("/sys/class/pwm/pwmchip1/pwm0/duty_cycle");
    pwmChipDutyCycle.open(QIODevice::WriteOnly);
    pwmChipDutyCycle.write("3125");
    pwmChipDutyCycle.close();

    QFile pwmChipStart("/sys/class/pwm/pwmchip1/pwm0/enable");
    pwmChipStart.open(QIODevice::WriteOnly);
    pwmChipStart.write("1");
    pwmChipStart.close();
}

void BlowerTestApplication::setMonitoringStatus(int status)
{
    if(status)
    {
        ui->brakeTitle->setEnabled(1);
        ui->brakeUnit->setEnabled(1);
        ui->brakeValue->setEnabled(1);
        ui->flowEngTitle->setEnabled(1);
        ui->flowEngValue->setEnabled(1);
        ui->flowEngUnit->setEnabled(1);
        ui->lightTitle->setEnabled(1);
        ui->lightValue->setEnabled(1);
        ui->lightUnit->setEnabled(1);
        ui->pressureEngTitle->setEnabled(1);
        ui->pressureEngValue->setEnabled(1);
        ui->pressureEngUnit->setEnabled(1);
        ui->rpmTitle->setEnabled(1);
        ui->rpmValue->setEnabled(1);
        ui->rpmUnit->setEnabled(1);
    }
    else
    {
        ui->brakeTitle->setEnabled(0);
        ui->brakeUnit->setEnabled(0);
        ui->brakeValue->setEnabled(0);
        ui->lightTitle->setEnabled(0);
        ui->lightValue->setEnabled(0);
        ui->lightUnit->setEnabled(0);
        ui->flowEngTitle->setEnabled(0);
        ui->flowEngValue->setEnabled(0);
        ui->flowEngUnit->setEnabled(0);
        ui->pressureEngTitle->setEnabled(0);
        ui->pressureEngValue->setEnabled(0);
        ui->pressureEngUnit->setEnabled(0);
        ui->rpmTitle->setEnabled(0);
        ui->rpmValue->setEnabled(0);
        ui->rpmUnit->setEnabled(0);
    }
}

void BlowerTestApplication::on_startStopButton_released()
{
    if(!this->blowerState)
    {
        ui->startStopButton->setText("STOP");
        ui->statusText->setText("BLOWER ON");
        ui->statusText->setStyleSheet("background-color: rgb(0, 170, 0)");
    }
    else
    {
        ui->startStopButton->setText("START");
        ui->statusText->setText("BLOWER OFF");
        ui->statusText->setStyleSheet("background-color: rgb(170, 0, 0)");
    }

    this->setMonitoringStatus(this->blowerState);
    this->blowerState = !this->blowerState;

//    /* PRU Start/Stop on effect of start/stop Button */
//    if(this->blowerState)
//    {
//        qDebug() << "Start";
//        emit startStopStateChanged_toThread(this->blowerState,this->count);
//    }
//    else
//    {
//        qDebug() << "Break";
//        emit sendBrakeSignal_toThread(this->brakeType,this->brakePercent);
//    }
}

#define MAX_BLOWER_COUNT    100
#define MIN_BLOWER_COUNT    0


void BlowerTestApplication::on_incrementButton_released()
{
    if(this->count < MAX_BLOWER_COUNT)   this->count++;
    QString s = QString::number(this->count);
    ui->rpmValue->setText(s);
//    this->send_data_to_pru();
//    if(this->blowerState)
//    {
//        emit sendSetParameters_toThread(this->count);
//    }
}

void BlowerTestApplication::on_decrementButton_released()
{
    if(this->count > MIN_BLOWER_COUNT)   this->count--;
    QString s = QString::number(this->count);
    ui->rpmValue->setText(s);
//    this->send_data_to_pru();
//    if(this->blowerState)
//    {
//        emit sendSetParameters_toThread(this->count);
//    }
}

void BlowerTestApplication::onProgressChanged(QString info)
{
int press;
bool status;
float pFloat;
QString str;

//    qDebug() << "Pressure:" << info;
    press = info.toInt(&status,10);
    if(status)
    {
        pFloat = static_cast<float>(press/10);
        str = QString::number(static_cast<int>(pFloat));
    }
    ui->pressureEngValue->setText(str);
}


void BlowerTestApplication::on_exitButton_clicked()
{
    hide();
}

void BlowerTestApplication::on_brakeDecrementButton_released()
{
    if(this->brakePercent > 0)          this->brakePercent--;
    QString s = QString::number(this->brakePercent);
    ui->brakeValue->setText(s);
}

void BlowerTestApplication::on_brakeIncrementButton_released()
{
    if(this->brakePercent < 100)        this->brakePercent++;
    QString s = QString::number(this->brakePercent);
    ui->brakeValue->setText(s);
}


#define BRAKE_TYPE_RESBRAKE     1
#define BRAKE_TYPE_PLUGBRAKE    2
#define BRAKE_TYPE_NOBRAKE      3

void BlowerTestApplication::on_resBrakeButton_clicked()
{
    this->brakeType = BRAKE_TYPE_RESBRAKE;
}

void BlowerTestApplication::on_plugBrakeButton_clicked()
{
    this->brakeType = BRAKE_TYPE_PLUGBRAKE;
}

void BlowerTestApplication::on_noBrakeButton_clicked()
{
    this->brakeType = BRAKE_TYPE_NOBRAKE;
}

void BlowerTestApplication::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
