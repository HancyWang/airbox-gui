#ifndef MANUFACTURINGDIAGNOSISSCREEN_H
#define MANUFACTURINGDIAGNOSISSCREEN_H

#include <QDialog>

enum IPC_MANUFACTURING_DIAGNOSIS_Type {
    IPC_PRESSURE_RAW=1,
    IPC_FLOW_RAW,
    IPC_BLOWER_SPEED,
    IPC_MOTOR_TEMP_RAW,
    IPC_VOLTAGE_IN_RAW,
    IPC_BLDC_CURRENT_RAW,
};


namespace Ui {
class ManufacturingDiagnosisScreen;
}

class PruControlClass;
class ManufacturingOptionsScreen;

class ManufacturingDiagnosisScreen : public QDialog
{
    Q_OBJECT

public:
    explicit ManufacturingDiagnosisScreen(QWidget *parent,
                                          PruControlClass * m_IpcBackend,
                                          ManufacturingOptionsScreen * manufacturingOptionsBackend);
    ~ManufacturingDiagnosisScreen();

    void updateStartStopButton(void);
    void manufacturingModeProcessBeforeShow(void);
    void manufacturingModeProcessBeforeExit(void);
    void updateManufacturingScreenLuxParam(float param);
    void changeEvent(QEvent* e);
private slots:
    void on_startBlowerButton_released();

    void on_decrementBlowerSpeed_pressed();

    void on_incrementBlowerSpeed_pressed();

    void on_backManufacturingDiagnosis_released();

    void showManufacturingDiagnosisScreen();

    void updateScreenAsPerReceivedPacket(unsigned int * localBuf);

signals:
    void beforeManufacturingModeProcedure(int manuFactMode,int blowerState,int blowerSpeed);

private:
    Ui::ManufacturingDiagnosisScreen *ui;
    PruControlClass * m_IpcManager;
    ManufacturingOptionsScreen * manufacturingOptionsScreen;

    static int blowerSpeed;
    static bool blowerState;
};

#endif // MANUFACTURINGDIAGNOSISSCREEN_H
