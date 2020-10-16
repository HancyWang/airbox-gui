/********************************************************************************
** Form generated from reading UI file 'deviceinfosettingsbasic.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICEINFOSETTINGSBASIC_H
#define UI_DEVICEINFOSETTINGSBASIC_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeviceInfoSettingsBasic
{
public:
    QLabel *deviceInfoSettingsTitle;
    QPushButton *backDeviceInfoSettings;
    QScrollArea *scrollAreaDeviceInfo;
    QWidget *scrollAreaWidgetContentsDeviceInfo;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayoutDeviceInfo;
    QFrame *deviceNameDeviceInfo;
    QHBoxLayout *monWidget_9;
    QVBoxLayout *deviceNameDeviceInfoLeftLayout;
    QLabel *deviceNameLeftTitleDeviceInfo;
    QVBoxLayout *deviceNameDeviceInfoRightLayout;
    QLabel *deviceNameRightTitleDeviceInfo;
    QFrame *ruHoursDeviceInfo;
    QHBoxLayout *monWidget_3;
    QVBoxLayout *ruHoursDeviceInfoLeftLayout;
    QLabel *ruHoursLeftTitleDeviceInfo;
    QLabel *ruHoursLeftSubTitleDeviceInfo;
    QVBoxLayout *ruHoursDeviceInfoRightLayout;
    QLabel *ruHoursRightTitleDeviceInfo;
    QFrame *serialNumberVersionDeviceInfo;
    QHBoxLayout *monWidget_8;
    QVBoxLayout *serialNumberDeviceInfoLeftLayout;
    QLabel *serialNumberLeftTitleDeviceInfo;
    QVBoxLayout *serialNumberDeviceInfoRightLayout;
    QLabel *serialNumberRightTitleDeviceInfo;
    QFrame *hwVersionDeviceInfo;
    QHBoxLayout *monWidget_7;
    QVBoxLayout *hwVersionDeviceInfoLeftLayout;
    QLabel *hwVersionLeftTitleDeviceInfo;
    QVBoxLayout *hwVersionDeviceInfoRightLayout;
    QLabel *hwVersionRightTitleDeviceInfo;
    QFrame *fwVersionDeviceInfo;
    QHBoxLayout *monWidget_4;
    QVBoxLayout *fwVersionDeviceInfoLeftLayout;
    QLabel *fwVersionLeftTitleDeviceInfo;
    QVBoxLayout *fwVersionDeviceInfoRightLayout;
    QLabel *fwVersionRightTitleDeviceInfo;
    QFrame *swVersionDeviceInfo;
    QHBoxLayout *monWidget_6;
    QVBoxLayout *swVersionDeviceInfoLeftLayout;
    QLabel *swVersionLeftTitleDeviceInfo;
    QVBoxLayout *swVersionDeviceInfoRightLayout;
    QLabel *swVersionRightTitleDeviceInfo;

    void setupUi(QDialog *DeviceInfoSettingsBasic)
    {
        if (DeviceInfoSettingsBasic->objectName().isEmpty())
            DeviceInfoSettingsBasic->setObjectName(QStringLiteral("DeviceInfoSettingsBasic"));
        DeviceInfoSettingsBasic->resize(480, 272);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DeviceInfoSettingsBasic->sizePolicy().hasHeightForWidth());
        DeviceInfoSettingsBasic->setSizePolicy(sizePolicy);
        DeviceInfoSettingsBasic->setStyleSheet(QStringLiteral("background-color: rgb(49, 49, 49);"));
        deviceInfoSettingsTitle = new QLabel(DeviceInfoSettingsBasic);
        deviceInfoSettingsTitle->setObjectName(QStringLiteral("deviceInfoSettingsTitle"));
        deviceInfoSettingsTitle->setGeometry(QRect(70, 30, 150, 23));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(14);
        deviceInfoSettingsTitle->setFont(font);
        deviceInfoSettingsTitle->setStyleSheet(QStringLiteral("color:#1788C3;"));
        backDeviceInfoSettings = new QPushButton(DeviceInfoSettingsBasic);
        backDeviceInfoSettings->setObjectName(QStringLiteral("backDeviceInfoSettings"));
        backDeviceInfoSettings->setGeometry(QRect(13, 28, 30, 30));
        backDeviceInfoSettings->setFocusPolicy(Qt::NoFocus);
        backDeviceInfoSettings->setStyleSheet(QLatin1String("border:none;\n"
"border-radius:3px;\n"
"background-color: rgb(70, 70, 73);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        backDeviceInfoSettings->setIcon(icon);
        scrollAreaDeviceInfo = new QScrollArea(DeviceInfoSettingsBasic);
        scrollAreaDeviceInfo->setObjectName(QStringLiteral("scrollAreaDeviceInfo"));
        scrollAreaDeviceInfo->setGeometry(QRect(0, 63, 480, 209));
        scrollAreaDeviceInfo->setStyleSheet(QLatin1String(" QScrollBar:vertical {\n"
"     border: none;\n"
"     width: 5px;\n"
" }\n"
" QScrollBar::handle:vertical {\n"
"     background:#1788c3;\n"
"     min-height: 20px;\n"
" }\n"
" QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {\n"
"     border: 2px #1788c3;\n"
"     width: 5px;\n"
"     height: 5px;\n"
"     background: #1788c3;\n"
" }"));
        scrollAreaDeviceInfo->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollAreaDeviceInfo->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollAreaDeviceInfo->setWidgetResizable(true);
        scrollAreaWidgetContentsDeviceInfo = new QWidget();
        scrollAreaWidgetContentsDeviceInfo->setObjectName(QStringLiteral("scrollAreaWidgetContentsDeviceInfo"));
        scrollAreaWidgetContentsDeviceInfo->setGeometry(QRect(0, 0, 473, 207));
        scrollAreaWidgetContentsDeviceInfo->setStyleSheet(QStringLiteral(""));
        verticalLayoutWidget = new QWidget(scrollAreaWidgetContentsDeviceInfo);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(-1, -1, 481, 317));
        verticalLayoutDeviceInfo = new QVBoxLayout(verticalLayoutWidget);
        verticalLayoutDeviceInfo->setSpacing(6);
        verticalLayoutDeviceInfo->setObjectName(QStringLiteral("verticalLayoutDeviceInfo"));
        verticalLayoutDeviceInfo->setContentsMargins(60, 5, 60, 5);
        deviceNameDeviceInfo = new QFrame(verticalLayoutWidget);
        deviceNameDeviceInfo->setObjectName(QStringLiteral("deviceNameDeviceInfo"));
        deviceNameDeviceInfo->setStyleSheet(QLatin1String("background-color: rgb(59, 59, 59);\n"
"border:1px;\n"
"border-radius:5px;"));
        monWidget_9 = new QHBoxLayout(deviceNameDeviceInfo);
        monWidget_9->setObjectName(QStringLiteral("monWidget_9"));
        deviceNameDeviceInfoLeftLayout = new QVBoxLayout();
        deviceNameDeviceInfoLeftLayout->setObjectName(QStringLiteral("deviceNameDeviceInfoLeftLayout"));
        deviceNameDeviceInfoLeftLayout->setContentsMargins(4, -1, -1, -1);
        deviceNameLeftTitleDeviceInfo = new QLabel(deviceNameDeviceInfo);
        deviceNameLeftTitleDeviceInfo->setObjectName(QStringLiteral("deviceNameLeftTitleDeviceInfo"));
        deviceNameLeftTitleDeviceInfo->setStyleSheet(QStringLiteral("color: rgb(189, 189, 189);"));
        deviceNameLeftTitleDeviceInfo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        deviceNameDeviceInfoLeftLayout->addWidget(deviceNameLeftTitleDeviceInfo);


        monWidget_9->addLayout(deviceNameDeviceInfoLeftLayout);

        deviceNameDeviceInfoRightLayout = new QVBoxLayout();
        deviceNameDeviceInfoRightLayout->setObjectName(QStringLiteral("deviceNameDeviceInfoRightLayout"));
        deviceNameDeviceInfoRightLayout->setContentsMargins(-1, -1, 10, -1);
        deviceNameRightTitleDeviceInfo = new QLabel(deviceNameDeviceInfo);
        deviceNameRightTitleDeviceInfo->setObjectName(QStringLiteral("deviceNameRightTitleDeviceInfo"));
        deviceNameRightTitleDeviceInfo->setStyleSheet(QStringLiteral("color: rgb(33, 150, 243);"));
        deviceNameRightTitleDeviceInfo->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        deviceNameDeviceInfoRightLayout->addWidget(deviceNameRightTitleDeviceInfo);


        monWidget_9->addLayout(deviceNameDeviceInfoRightLayout);


        verticalLayoutDeviceInfo->addWidget(deviceNameDeviceInfo);

        ruHoursDeviceInfo = new QFrame(verticalLayoutWidget);
        ruHoursDeviceInfo->setObjectName(QStringLiteral("ruHoursDeviceInfo"));
        ruHoursDeviceInfo->setStyleSheet(QLatin1String("background-color: rgb(59, 59, 59);\n"
"border:1px;\n"
"border-radius:5px;"));
        monWidget_3 = new QHBoxLayout(ruHoursDeviceInfo);
        monWidget_3->setObjectName(QStringLiteral("monWidget_3"));
        ruHoursDeviceInfoLeftLayout = new QVBoxLayout();
        ruHoursDeviceInfoLeftLayout->setObjectName(QStringLiteral("ruHoursDeviceInfoLeftLayout"));
        ruHoursDeviceInfoLeftLayout->setContentsMargins(4, -1, -1, -1);
        ruHoursLeftTitleDeviceInfo = new QLabel(ruHoursDeviceInfo);
        ruHoursLeftTitleDeviceInfo->setObjectName(QStringLiteral("ruHoursLeftTitleDeviceInfo"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(10);
        sizePolicy1.setHeightForWidth(ruHoursLeftTitleDeviceInfo->sizePolicy().hasHeightForWidth());
        ruHoursLeftTitleDeviceInfo->setSizePolicy(sizePolicy1);
        ruHoursLeftTitleDeviceInfo->setStyleSheet(QStringLiteral("color: rgb(189, 189, 189);"));
        ruHoursLeftTitleDeviceInfo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        ruHoursDeviceInfoLeftLayout->addWidget(ruHoursLeftTitleDeviceInfo);

        ruHoursLeftSubTitleDeviceInfo = new QLabel(ruHoursDeviceInfo);
        ruHoursLeftSubTitleDeviceInfo->setObjectName(QStringLiteral("ruHoursLeftSubTitleDeviceInfo"));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(7);
        ruHoursLeftSubTitleDeviceInfo->setFont(font1);
        ruHoursLeftSubTitleDeviceInfo->setStyleSheet(QStringLiteral("color: rgb(97, 97, 97);"));
        ruHoursLeftSubTitleDeviceInfo->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        ruHoursDeviceInfoLeftLayout->addWidget(ruHoursLeftSubTitleDeviceInfo);


        monWidget_3->addLayout(ruHoursDeviceInfoLeftLayout);

        ruHoursDeviceInfoRightLayout = new QVBoxLayout();
        ruHoursDeviceInfoRightLayout->setObjectName(QStringLiteral("ruHoursDeviceInfoRightLayout"));
        ruHoursDeviceInfoRightLayout->setContentsMargins(-1, -1, 10, -1);
        ruHoursRightTitleDeviceInfo = new QLabel(ruHoursDeviceInfo);
        ruHoursRightTitleDeviceInfo->setObjectName(QStringLiteral("ruHoursRightTitleDeviceInfo"));
        ruHoursRightTitleDeviceInfo->setStyleSheet(QStringLiteral("color: rgb(33, 150, 243);"));
        ruHoursRightTitleDeviceInfo->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        ruHoursDeviceInfoRightLayout->addWidget(ruHoursRightTitleDeviceInfo);


        monWidget_3->addLayout(ruHoursDeviceInfoRightLayout);


        verticalLayoutDeviceInfo->addWidget(ruHoursDeviceInfo);

        serialNumberVersionDeviceInfo = new QFrame(verticalLayoutWidget);
        serialNumberVersionDeviceInfo->setObjectName(QStringLiteral("serialNumberVersionDeviceInfo"));
        serialNumberVersionDeviceInfo->setStyleSheet(QLatin1String("background-color: rgb(59, 59, 59);\n"
"border:1px;\n"
"border-radius:5px;"));
        monWidget_8 = new QHBoxLayout(serialNumberVersionDeviceInfo);
        monWidget_8->setObjectName(QStringLiteral("monWidget_8"));
        serialNumberDeviceInfoLeftLayout = new QVBoxLayout();
        serialNumberDeviceInfoLeftLayout->setObjectName(QStringLiteral("serialNumberDeviceInfoLeftLayout"));
        serialNumberDeviceInfoLeftLayout->setContentsMargins(4, -1, -1, -1);
        serialNumberLeftTitleDeviceInfo = new QLabel(serialNumberVersionDeviceInfo);
        serialNumberLeftTitleDeviceInfo->setObjectName(QStringLiteral("serialNumberLeftTitleDeviceInfo"));
        serialNumberLeftTitleDeviceInfo->setStyleSheet(QStringLiteral("color: rgb(189, 189, 189);"));
        serialNumberLeftTitleDeviceInfo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        serialNumberDeviceInfoLeftLayout->addWidget(serialNumberLeftTitleDeviceInfo);


        monWidget_8->addLayout(serialNumberDeviceInfoLeftLayout);

        serialNumberDeviceInfoRightLayout = new QVBoxLayout();
        serialNumberDeviceInfoRightLayout->setObjectName(QStringLiteral("serialNumberDeviceInfoRightLayout"));
        serialNumberDeviceInfoRightLayout->setContentsMargins(-1, -1, 10, -1);
        serialNumberRightTitleDeviceInfo = new QLabel(serialNumberVersionDeviceInfo);
        serialNumberRightTitleDeviceInfo->setObjectName(QStringLiteral("serialNumberRightTitleDeviceInfo"));
        serialNumberRightTitleDeviceInfo->setStyleSheet(QStringLiteral("color: rgb(33, 150, 243);"));
        serialNumberRightTitleDeviceInfo->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        serialNumberDeviceInfoRightLayout->addWidget(serialNumberRightTitleDeviceInfo);


        monWidget_8->addLayout(serialNumberDeviceInfoRightLayout);


        verticalLayoutDeviceInfo->addWidget(serialNumberVersionDeviceInfo);

        hwVersionDeviceInfo = new QFrame(verticalLayoutWidget);
        hwVersionDeviceInfo->setObjectName(QStringLiteral("hwVersionDeviceInfo"));
        hwVersionDeviceInfo->setStyleSheet(QLatin1String("background-color: rgb(59, 59, 59);\n"
"border:1px;\n"
"border-radius:5px;"));
        monWidget_7 = new QHBoxLayout(hwVersionDeviceInfo);
        monWidget_7->setObjectName(QStringLiteral("monWidget_7"));
        hwVersionDeviceInfoLeftLayout = new QVBoxLayout();
        hwVersionDeviceInfoLeftLayout->setObjectName(QStringLiteral("hwVersionDeviceInfoLeftLayout"));
        hwVersionDeviceInfoLeftLayout->setContentsMargins(4, -1, -1, -1);
        hwVersionLeftTitleDeviceInfo = new QLabel(hwVersionDeviceInfo);
        hwVersionLeftTitleDeviceInfo->setObjectName(QStringLiteral("hwVersionLeftTitleDeviceInfo"));
        hwVersionLeftTitleDeviceInfo->setStyleSheet(QStringLiteral("color: rgb(189, 189, 189);"));
        hwVersionLeftTitleDeviceInfo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        hwVersionDeviceInfoLeftLayout->addWidget(hwVersionLeftTitleDeviceInfo);


        monWidget_7->addLayout(hwVersionDeviceInfoLeftLayout);

        hwVersionDeviceInfoRightLayout = new QVBoxLayout();
        hwVersionDeviceInfoRightLayout->setObjectName(QStringLiteral("hwVersionDeviceInfoRightLayout"));
        hwVersionDeviceInfoRightLayout->setContentsMargins(-1, -1, 10, -1);
        hwVersionRightTitleDeviceInfo = new QLabel(hwVersionDeviceInfo);
        hwVersionRightTitleDeviceInfo->setObjectName(QStringLiteral("hwVersionRightTitleDeviceInfo"));
        hwVersionRightTitleDeviceInfo->setStyleSheet(QStringLiteral("color: rgb(33, 150, 243);"));
        hwVersionRightTitleDeviceInfo->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        hwVersionDeviceInfoRightLayout->addWidget(hwVersionRightTitleDeviceInfo);


        monWidget_7->addLayout(hwVersionDeviceInfoRightLayout);


        verticalLayoutDeviceInfo->addWidget(hwVersionDeviceInfo);

        fwVersionDeviceInfo = new QFrame(verticalLayoutWidget);
        fwVersionDeviceInfo->setObjectName(QStringLiteral("fwVersionDeviceInfo"));
        fwVersionDeviceInfo->setStyleSheet(QLatin1String("background-color: rgb(59, 59, 59);\n"
"border:1px;\n"
"border-radius:5px;"));
        monWidget_4 = new QHBoxLayout(fwVersionDeviceInfo);
        monWidget_4->setObjectName(QStringLiteral("monWidget_4"));
        fwVersionDeviceInfoLeftLayout = new QVBoxLayout();
        fwVersionDeviceInfoLeftLayout->setObjectName(QStringLiteral("fwVersionDeviceInfoLeftLayout"));
        fwVersionDeviceInfoLeftLayout->setContentsMargins(4, -1, -1, -1);
        fwVersionLeftTitleDeviceInfo = new QLabel(fwVersionDeviceInfo);
        fwVersionLeftTitleDeviceInfo->setObjectName(QStringLiteral("fwVersionLeftTitleDeviceInfo"));
        fwVersionLeftTitleDeviceInfo->setStyleSheet(QStringLiteral("color: rgb(189, 189, 189);"));
        fwVersionLeftTitleDeviceInfo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        fwVersionDeviceInfoLeftLayout->addWidget(fwVersionLeftTitleDeviceInfo);


        monWidget_4->addLayout(fwVersionDeviceInfoLeftLayout);

        fwVersionDeviceInfoRightLayout = new QVBoxLayout();
        fwVersionDeviceInfoRightLayout->setObjectName(QStringLiteral("fwVersionDeviceInfoRightLayout"));
        fwVersionDeviceInfoRightLayout->setContentsMargins(-1, -1, 10, -1);
        fwVersionRightTitleDeviceInfo = new QLabel(fwVersionDeviceInfo);
        fwVersionRightTitleDeviceInfo->setObjectName(QStringLiteral("fwVersionRightTitleDeviceInfo"));
        fwVersionRightTitleDeviceInfo->setStyleSheet(QStringLiteral("color: rgb(33, 150, 243);"));
        fwVersionRightTitleDeviceInfo->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        fwVersionDeviceInfoRightLayout->addWidget(fwVersionRightTitleDeviceInfo);


        monWidget_4->addLayout(fwVersionDeviceInfoRightLayout);


        verticalLayoutDeviceInfo->addWidget(fwVersionDeviceInfo);

        swVersionDeviceInfo = new QFrame(verticalLayoutWidget);
        swVersionDeviceInfo->setObjectName(QStringLiteral("swVersionDeviceInfo"));
        swVersionDeviceInfo->setStyleSheet(QLatin1String("background-color: rgb(59, 59, 59);\n"
"border:1px;\n"
"border-radius:5px;"));
        monWidget_6 = new QHBoxLayout(swVersionDeviceInfo);
        monWidget_6->setObjectName(QStringLiteral("monWidget_6"));
        swVersionDeviceInfoLeftLayout = new QVBoxLayout();
        swVersionDeviceInfoLeftLayout->setObjectName(QStringLiteral("swVersionDeviceInfoLeftLayout"));
        swVersionDeviceInfoLeftLayout->setContentsMargins(4, -1, -1, -1);
        swVersionLeftTitleDeviceInfo = new QLabel(swVersionDeviceInfo);
        swVersionLeftTitleDeviceInfo->setObjectName(QStringLiteral("swVersionLeftTitleDeviceInfo"));
        swVersionLeftTitleDeviceInfo->setStyleSheet(QStringLiteral("color: rgb(189, 189, 189);"));
        swVersionLeftTitleDeviceInfo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        swVersionDeviceInfoLeftLayout->addWidget(swVersionLeftTitleDeviceInfo);


        monWidget_6->addLayout(swVersionDeviceInfoLeftLayout);

        swVersionDeviceInfoRightLayout = new QVBoxLayout();
        swVersionDeviceInfoRightLayout->setObjectName(QStringLiteral("swVersionDeviceInfoRightLayout"));
        swVersionDeviceInfoRightLayout->setContentsMargins(-1, -1, 10, -1);
        swVersionRightTitleDeviceInfo = new QLabel(swVersionDeviceInfo);
        swVersionRightTitleDeviceInfo->setObjectName(QStringLiteral("swVersionRightTitleDeviceInfo"));
        swVersionRightTitleDeviceInfo->setStyleSheet(QStringLiteral("color: rgb(33, 150, 243);"));
        swVersionRightTitleDeviceInfo->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        swVersionDeviceInfoRightLayout->addWidget(swVersionRightTitleDeviceInfo);


        monWidget_6->addLayout(swVersionDeviceInfoRightLayout);


        verticalLayoutDeviceInfo->addWidget(swVersionDeviceInfo);

        scrollAreaDeviceInfo->setWidget(scrollAreaWidgetContentsDeviceInfo);

        retranslateUi(DeviceInfoSettingsBasic);

        QMetaObject::connectSlotsByName(DeviceInfoSettingsBasic);
    } // setupUi

    void retranslateUi(QDialog *DeviceInfoSettingsBasic)
    {
        DeviceInfoSettingsBasic->setWindowTitle(QApplication::translate("DeviceInfoSettingsBasic", "Dialog", nullptr));
        deviceInfoSettingsTitle->setText(QApplication::translate("DeviceInfoSettingsBasic", "Device Info", nullptr));
        backDeviceInfoSettings->setText(QString());
        deviceNameLeftTitleDeviceInfo->setText(QApplication::translate("DeviceInfoSettingsBasic", "Device Name", nullptr));
        deviceNameRightTitleDeviceInfo->setText(QApplication::translate("DeviceInfoSettingsBasic", "1234", nullptr));
        ruHoursLeftTitleDeviceInfo->setText(QApplication::translate("DeviceInfoSettingsBasic", "Device Run Hours", nullptr));
        ruHoursLeftSubTitleDeviceInfo->setText(QApplication::translate("DeviceInfoSettingsBasic", "Hours", nullptr));
        ruHoursRightTitleDeviceInfo->setText(QApplication::translate("DeviceInfoSettingsBasic", "5000", nullptr));
        serialNumberLeftTitleDeviceInfo->setText(QApplication::translate("DeviceInfoSettingsBasic", "Serial Number", nullptr));
        serialNumberRightTitleDeviceInfo->setText(QApplication::translate("DeviceInfoSettingsBasic", "1234", nullptr));
        hwVersionLeftTitleDeviceInfo->setText(QApplication::translate("DeviceInfoSettingsBasic", "HW Version", nullptr));
        hwVersionRightTitleDeviceInfo->setText(QApplication::translate("DeviceInfoSettingsBasic", "1234", nullptr));
        fwVersionLeftTitleDeviceInfo->setText(QApplication::translate("DeviceInfoSettingsBasic", "FW Version", nullptr));
        fwVersionRightTitleDeviceInfo->setText(QApplication::translate("DeviceInfoSettingsBasic", "1234", nullptr));
        swVersionLeftTitleDeviceInfo->setText(QApplication::translate("DeviceInfoSettingsBasic", "SW Version", nullptr));
        swVersionRightTitleDeviceInfo->setText(QApplication::translate("DeviceInfoSettingsBasic", "1234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeviceInfoSettingsBasic: public Ui_DeviceInfoSettingsBasic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICEINFOSETTINGSBASIC_H
