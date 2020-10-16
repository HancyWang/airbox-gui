#ifndef WARNINGINFOSCREEN_H
#define WARNINGINFOSCREEN_H

#include <QDialog>
#include <QGraphicsColorizeEffect>
#include <QTimer>
#include <QFile>

namespace Ui {
class WarningInfoScreen;
}


enum ApplicationErrorCodes {
    BLOWER_IC_FAULTY_ERROR=1,
    MOTOR_OVERCURRENT_ERROR,
    CHARGE_PUMP_OVERCURRENT_ERROR,
    OVERTEMP_SHUTDOWN_ERROR,
    VM_UNDERVOLTAGE_ERROR,
    CHARGEPUMP_UNDERVOLTAGE_ERROR,
    VM_OVERVOLTAGE_ERROR,
    ROTOR_LOCK_CONDITION_ERROR,
    HIGH_MOTOR_TEMPERATURE_ERROR,
    INPUT_VOLTAGE_HIGH_ERROR,
    INPUT_VOLTAGE_LOW_ERROR,
    PRESSURE_SENSOR_FAULTY_ERROR,
    BLOWER_OVER_CURRENT_ERROR,
    MCP3204_MEASUREMENT_INVALID_ERROR,
    MCP3202_MEASUREMENT_INVALID_ERROR,
    SPI_BUS_FAULT_ERROR,
    FLOW_SENSOR_FAULT_ERROR,
    I2C1_BUS_FAULT_ERROR,
    RTC_FAULTY_ERROR,
    EEPROM_FAULTY_ERROR,
    TOUCHSCREEN_FAULTY_ERROR,
    AMBIENT_SENSOR_FAULTY_ERROR,
    I2C0_BUS_FAULTY_ERROR,
};

class PruControlClass;
class TherapyWindowBasic;

class WarningInfoScreen : public QDialog
{
    Q_OBJECT

public:
    explicit WarningInfoScreen(QWidget *parent,
                               PruControlClass * m_IpcBackend,
                               TherapyWindowBasic * therapyBasicBackend);
    ~WarningInfoScreen();

    QGraphicsColorizeEffect * parentEffect;

    void showErrorOnScreen(int tErrorCode);
    void parseAndUpdateErrorData(unsigned int * tBuffer);
    bool verifyIfBlowerCanRun(int * tBuffer,int tTotalErrors);
    void logErrorsInFile(int * tBuffer,int tTotalNumber);
    void processError(unsigned int * tErrorCodeArray,int tTotalErrors);

    bool isErrorsAreSame(int * tArray,int tCount);
    void changeEvent(QEvent* e);
signals:
    void beforeStartTherapyProcedure(void);

    void updateStartStopTherapyDetails(void);

    void startPowerOffProcedure(void);

private slots:
    void on_closeButton_clicked();

    void on_disabledTimerTimeout();

    void updateAndShowScreen(int * tArray,int tCount);

private:
    Ui::WarningInfoScreen *ui;

    PruControlClass * m_IpcManager;
    TherapyWindowBasic * therapyBasicScreen;

    QFile warningLogFile;
    bool tDeviceNeedToBePoweredOff;

    bool isRotorLocked=false;
    int m_RotorLockCount=0;

    QTimer disabledTimer;
    int tErrors[23];
    int tErrorCount = 0;

    static const QStringList buttonTitle;
    static const QStringList tWarningMessage;

};

#endif // WARNINGINFOSCREEN_H
