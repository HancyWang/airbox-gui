#ifndef BLUETOOTHSETTINGSBASIC_H
#define BLUETOOTHSETTINGSBASIC_H

#include <QDialog>
#include <QGraphicsColorizeEffect>

#include "constants.h"

namespace Ui {
class BluetoothSettingsBasic;
}

class BluetoothSettingsBasic : public QDialog
{
    Q_OBJECT

public:
    explicit BluetoothSettingsBasic(QWidget *parent = 0);
    ~BluetoothSettingsBasic();

    void updateBluetoothSettingsBeforeShow(void);
    void connectWithDeviceInList1(void);
    void connectWithDeviceInList2(void);
    void connectWithDeviceInList3(void);
    void connectWithDeviceInList4(void);
    void connectWithDeviceInList5(void);

    QGraphicsColorizeEffect * parentEffect;
    void changeEvent(QEvent* e);
public slots:
    void showBluetoothBasicScreen();

private slots:
    void on_bluetoothDeviceAccept_released();

    void on_bluetoothDeviceCancel_released();


    void on_deviceIcon1_pressed();

    void on_deviceIcon3_pressed();

    void on_deviceIcon2_pressed();

    void on_deviceIcon4_pressed();

    void on_deviceIcon5_pressed();

    void on_deviceText1_pressed();

    void on_deviceText2_pressed();

    void on_deviceText3_pressed();

    void on_deviceText4_pressed();

    void on_deviceText5_pressed();

private:
    Ui::BluetoothSettingsBasic *ui;

};

#endif // BLUETOOTHSETTINGSBASIC_H
