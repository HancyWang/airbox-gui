#include "deviceinfosettingsbasic.h"
#include "ui_deviceinfosettingsbasic.h"
#include "ex_variables.h"

DeviceInfoSettingsBasic::DeviceInfoSettingsBasic(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::DeviceInfoSettingsBasic),
    m_Anim(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setWindowState(Qt::WindowFullScreen);
    setGeometry(0,0,width(),height());

    m_Anim = new QPropertyAnimation(this,"geometry");

    QFont FontTitle("Roboto-Light", 8);
    QFont FontSubTitle("Roboto-Thin", 10);

    ui->swVersionLeftTitleDeviceInfo->setFont(FontTitle);
    ui->deviceNameLeftTitleDeviceInfo->setFont(FontTitle);
    ui->ruHoursLeftTitleDeviceInfo->setFont(FontTitle);
    ui->fwVersionLeftTitleDeviceInfo->setFont(FontTitle);
    ui->swVersionLeftTitleDeviceInfo->setFont(FontTitle);
    ui->serialNumberLeftTitleDeviceInfo->setFont(FontTitle);
    ui->hwVersionLeftTitleDeviceInfo->setFont(FontTitle);

    ui->swVersionRightTitleDeviceInfo->setFont(FontSubTitle);
    ui->deviceNameRightTitleDeviceInfo->setFont(FontSubTitle);
    ui->ruHoursRightTitleDeviceInfo->setFont(FontSubTitle);
    ui->fwVersionRightTitleDeviceInfo->setFont(FontSubTitle);
    ui->swVersionRightTitleDeviceInfo->setFont(FontSubTitle);
    ui->serialNumberRightTitleDeviceInfo->setFont(FontSubTitle);
    ui->hwVersionRightTitleDeviceInfo->setFont(FontSubTitle);

    FontTitle.setPointSize(5);
    ui->ruHoursLeftSubTitleDeviceInfo->setFont(FontTitle);

    FontTitle.setPointSize(12);
    ui->deviceInfoSettingsTitle->setFont(FontTitle);

    ui->scrollAreaWidgetContentsDeviceInfo->setLayout(ui->verticalLayoutDeviceInfo);
    ui->scrollAreaDeviceInfo->setStyleSheet(QStringLiteral("border:none;"));

    QScroller::grabGesture(ui->scrollAreaDeviceInfo->viewport(),QScroller::LeftMouseButtonGesture);

    ui->fwVersionDeviceInfo->hide();
}

void DeviceInfoSettingsBasic::animateDeviceInfoWindow(openCloseStatus state)
{
    if (state) {
        this->show();
        m_Anim->setStartValue(QRect(480, 0, 480, 272));
        m_Anim->setEndValue(QRect(0, 0, 480, 272));
        m_Anim->setDuration(WINDOW_ANIMATION_OPEN_DURATION);
        m_Anim->setEasingCurve(WINDOW_OPEN_TRANSITION);
        connect(m_Anim, SIGNAL(finished()),SLOT(show()));
    } else {
        m_Anim->setStartValue(QRect(0, 0, 480, 272));
        m_Anim->setEndValue(QRect(480, 0, 480, 272));
        m_Anim->setDuration(WINDOW_ANIMATION_CLOSE_DURATION);
        m_Anim->setEasingCurve(WINDOW_CLOSE_TRANSITION);
        connect(m_Anim, SIGNAL(finished()),SLOT(hide()));
    }
    m_Anim->start();
}

DeviceInfoSettingsBasic::~DeviceInfoSettingsBasic()
{
    delete ui;
}

void DeviceInfoSettingsBasic::on_backDeviceInfoSettings_released()
{
    animateDeviceInfoWindow(Close);
}

void DeviceInfoSettingsBasic::showDeviceInfoScreen(QWidget * parent)
{
    updateDeviceInfoProcessBeforeShow();
    setParent(parent);
    animateDeviceInfoWindow(Open);
}

void DeviceInfoSettingsBasic::updateDeviceInfoProcessBeforeShow(void)
{
    ui->scrollAreaDeviceInfo->setStyleSheet(QStringLiteral("border:none;"));

    //TODO Implement routine to update Device info parameter as per information
    ui->swVersionRightTitleDeviceInfo->setText(Providers::getDeviceInformationString(SOFTWARE_VERSION));
    ui->fwVersionRightTitleDeviceInfo->setText(Providers::getDeviceInformationString(FIRMWARE_VERSION));
    ui->deviceNameRightTitleDeviceInfo->setText(Providers::getDeviceInformationString(DEVICE_NAME));
    ui->serialNumberRightTitleDeviceInfo->setText(globalVar.serialNumberStr);
    ui->hwVersionRightTitleDeviceInfo->setText(Providers::getDeviceInformationString(HARDWARE_VERSION));
    ui->ruHoursRightTitleDeviceInfo->setText(QString("%1").arg(globalVar.deviceLifeData.totalHoursFlowGeneration));

    QScrollBar * tScrollBar = ui->scrollAreaDeviceInfo->verticalScrollBar();
    tScrollBar->setValue(0);
}

void DeviceInfoSettingsBasic::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
