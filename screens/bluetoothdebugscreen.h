#ifndef BLUETOOTHDEBUGSCREEN_H
#define BLUETOOTHDEBUGSCREEN_H


#include <QDialog>

enum BluetoothDebugColorType {
    BLUETOOTH_TRANSMIT=1,
    BLUETOOTH_RECEIVE,
    BLUETOOTH_DATA
};

namespace Ui {
class BluetoothDebugScreen;
}

class SettingsWindowBasic;

class BluetoothDebugScreen : public QDialog
{
    Q_OBJECT

public:
    explicit BluetoothDebugScreen(QWidget *parent,SettingsWindowBasic * settingsBasicBackend);
    ~BluetoothDebugScreen();

    bool bluetoothDebugEnable=false;
    void logToFile(const QString & localStrData);
    void setBleDebugFilePath(const QString & filePath);
    void resetLogScreen(void);


    int fileTransferPacketSize=20;
    void changeEvent(QEvent* e);
private slots:
    void on_backBluetoothDebug_pressed();

    void on_decrementButton_released();

    void on_incrementButton_released();

public slots:
    void addRowData(const QString & data,BluetoothDebugColorType colorType);

private:
    Ui::BluetoothDebugScreen *ui;
    SettingsWindowBasic * settingsBasicScreen;

    int indexCount=0;

    QString bleDebugFilePath;
};

#endif // BLUETOOTHDEBUGSCREEN_H
