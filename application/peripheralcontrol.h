#ifndef PERIPHERALCONTROL_H
#define PERIPHERALCONTROL_H

#include <QObject>

class PeripheralControl : public QObject
{
    Q_OBJECT
public:
    explicit PeripheralControl(QObject *parent = nullptr);


    void enableGpioToSysfs(int gpioNo);
    void setGpioDirection(int gpioNo,bool direction);
    bool readGpioState(int gpioNo);
    void removeGpioFromSysfs(int gpioNo);

signals:

public slots:
    void setGpioState(int gpioNo,bool outputState);
};

#endif // PERIPHERALCONTROL_H
