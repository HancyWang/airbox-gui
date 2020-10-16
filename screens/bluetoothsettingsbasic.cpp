#include "bluetoothsettingsbasic.h"
#include "ui_bluetoothsettingsbasic.h"
#include "ex_variables.h"

BluetoothSettingsBasic::BluetoothSettingsBasic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BluetoothSettingsBasic),
    parentEffect(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setAttribute(Qt::WA_TranslucentBackground,true);
    move(60,56);

    QFont title("Roboto-Light",9);
    ui->bluetoothDeviceTitle->setFont(title);

    title.setPointSize(9);
    ui->bluetoothDeviceAccept->setFont(title);
    ui->bluetoothDeviceCancel->setFont(title);

    updateBluetoothSettingsBeforeShow();
}

BluetoothSettingsBasic::~BluetoothSettingsBasic()
{
    delete ui;
}

void BluetoothSettingsBasic::updateBluetoothSettingsBeforeShow(void)
{
    if(globalVar.bluetooth.totalPairedDevices)
    {
        ui->deviceText1->setText(globalVar.bluetooth.pairedDeviceNames[0]);
        ui->deviceText2->setText(globalVar.bluetooth.pairedDeviceNames[1]);
        ui->deviceText3->setText(globalVar.bluetooth.pairedDeviceNames[2]);
        ui->deviceText4->setText(globalVar.bluetooth.pairedDeviceNames[3]);
        ui->deviceText5->setText(globalVar.bluetooth.pairedDeviceNames[4]);

        if(globalVar.bluetooth.currentPairedDeviceIndex == 1)
            ui->deviceIcon1->setStyleSheet(QStringLiteral("image: url(:/icons/right_accepted.png);"));
         else
            ui->deviceIcon1->setStyleSheet(NULL);

        if(globalVar.bluetooth.currentPairedDeviceIndex == 2)
            ui->deviceIcon2->setStyleSheet(QStringLiteral("image: url(:/icons/right_accepted.png);"));
         else
            ui->deviceIcon2->setStyleSheet(NULL);

        if(globalVar.bluetooth.currentPairedDeviceIndex == 3)
            ui->deviceIcon3->setStyleSheet(QStringLiteral("image: url(:/icons/right_accepted.png);"));
         else
            ui->deviceIcon3->setStyleSheet(NULL);

        if(globalVar.bluetooth.currentPairedDeviceIndex == 4)
            ui->deviceIcon4->setStyleSheet(QStringLiteral("image: url(:/icons/right_accepted.png);"));
         else
            ui->deviceIcon4->setStyleSheet(NULL);

        if(globalVar.bluetooth.currentPairedDeviceIndex == 5)
            ui->deviceIcon5->setStyleSheet(QStringLiteral("image: url(:/icons/right_accepted.png);"));
         else
            ui->deviceIcon5->setStyleSheet(NULL);
    }
}

void BluetoothSettingsBasic::on_bluetoothDeviceAccept_released()
{
    parentEffect->setEnabled(false);
    hide();
    setModal(false);
}

void BluetoothSettingsBasic::on_bluetoothDeviceCancel_released()
{
    parentEffect->setEnabled(false);
    hide();
    setModal(false);
}

void BluetoothSettingsBasic::on_deviceText1_pressed()
{
    connectWithDeviceInList1();
}
void BluetoothSettingsBasic::on_deviceIcon1_pressed()
{
    connectWithDeviceInList1();
}

void BluetoothSettingsBasic::on_deviceText2_pressed()
{
    connectWithDeviceInList2();
}

void BluetoothSettingsBasic::on_deviceIcon2_pressed()
{
    connectWithDeviceInList2();
}

void BluetoothSettingsBasic::on_deviceText3_pressed()
{
    connectWithDeviceInList3();
}

void BluetoothSettingsBasic::on_deviceIcon3_pressed()
{
    connectWithDeviceInList3();
}

void BluetoothSettingsBasic::on_deviceText4_pressed()
{
    connectWithDeviceInList4();
}

void BluetoothSettingsBasic::on_deviceIcon4_pressed()
{
    connectWithDeviceInList4();
}

void BluetoothSettingsBasic::on_deviceText5_pressed()
{
    connectWithDeviceInList5();
}

void BluetoothSettingsBasic::on_deviceIcon5_pressed()
{
    connectWithDeviceInList5();
}

//TODO Add functionalities for connecting device with bluetooth
void BluetoothSettingsBasic::connectWithDeviceInList1(void)
{

}
void BluetoothSettingsBasic::connectWithDeviceInList2(void)
{

}
void BluetoothSettingsBasic::connectWithDeviceInList3(void)
{

}
void BluetoothSettingsBasic::connectWithDeviceInList4(void)
{

}
void BluetoothSettingsBasic::connectWithDeviceInList5(void)
{

}

void BluetoothSettingsBasic::showBluetoothBasicScreen()
{
    updateBluetoothSettingsBeforeShow();
    parentEffect->setEnabled(true);
    setModal(true);
    show();
}


void BluetoothSettingsBasic::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
