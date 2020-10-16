#ifndef DEVICEINFOSETTINGSBASIC_H
#define DEVICEINFOSETTINGSBASIC_H

#include <QDialog>
#include <QPropertyAnimation>

#include "constants.h"

namespace Ui {
class DeviceInfoSettingsBasic;
}

class DeviceInfoSettingsBasic : public QDialog
{
    Q_OBJECT

public:
    explicit DeviceInfoSettingsBasic(QWidget *parent = 0);
    ~DeviceInfoSettingsBasic();

    void animateDeviceInfoWindow(openCloseStatus state);
    void updateDeviceInfoProcessBeforeShow(void);
    void changeEvent(QEvent* e);
public slots:
    void showDeviceInfoScreen(QWidget *parent);

private slots:
    void on_backDeviceInfoSettings_released();

private:
    Ui::DeviceInfoSettingsBasic *ui;

    QPropertyAnimation * m_Anim;

};

#endif // DEVICEINFOSETTINGSBASIC_H
