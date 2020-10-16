#include "peripheralcontrol.h"
#include "ex_variables.h"

PeripheralControl::PeripheralControl(QObject *parent) : QObject(parent)
{

}

void PeripheralControl::enableGpioToSysfs(int gpioNo)
{
    QFile gpioFile("/sys/class/gpio/export");
    if(gpioFile.exists())
    {
        gpioFile.open(QIODevice::WriteOnly);
        QTextStream out(&gpioFile);
        QString str = QString::number(gpioNo);
        out << str;
        gpioFile.close();
    }
}

void PeripheralControl::setGpioDirection(int gpioNo,bool direction)
{
    QString gpioStr = QString("/sys/class/gpio/gpio%1/direction").arg(gpioNo);
    QFile gpioFile(gpioStr);
    if(gpioFile.exists())
    {
        gpioFile.open(QIODevice::WriteOnly);
        QTextStream out(&gpioFile);
        if(direction)   out << "out";
        else            out << "in";
        gpioFile.close();
    }
}

void PeripheralControl::setGpioState(int gpioNo,bool outputState)
{
    QString gpioStr = QString("/sys/class/gpio/gpio%1/value").arg(gpioNo);
    QFile gpioFile(gpioStr);
    if(gpioFile.exists())
    {
        gpioFile.open(QIODevice::WriteOnly);
        QTextStream out(&gpioFile);
        QString str = QString::number(outputState);
        out << str;
        gpioFile.close();
    }
}

bool PeripheralControl::readGpioState(int gpioNo)
{
    bool tPinState=false;
    int tPinInt=0;
    QString gpioStr = QString("/sys/class/gpio/gpio%1/value").arg(gpioNo);
    QFile gpioFile(gpioStr);

    if(gpioFile.exists())
    {
        gpioFile.open(QIODevice::ReadOnly);
        tPinInt = gpioFile.readAll().toInt();
        if(tPinInt == 0)            tPinState = false;
        else if(tPinInt == 1)       tPinState = true;
        gpioFile.close();
    }
return tPinState;
}

void PeripheralControl::removeGpioFromSysfs(int gpioNo)
{
    QFile gpioFile("/sys/class/gpio/unexport");
    if(gpioFile.exists())
    {
        gpioFile.open(QIODevice::WriteOnly);
        QTextStream out(&gpioFile);
        QString str = QString::number(gpioNo);
        out << str;
        gpioFile.close();
    }
}
