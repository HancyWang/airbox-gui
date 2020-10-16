/********************************************************************************
** Form generated from reading UI file 'notificationtray.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTIFICATIONTRAY_H
#define UI_NOTIFICATIONTRAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NotificationTray
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *date;
    QLabel *time;
    QLabel *flow;
    QLabel *eventCountHypoApnea;
    QLabel *leakageCount;
    QLabel *breathCount;
    QLabel *stableUnstable;
    QLabel *maskOffLeak;
    QLabel *eventDetected;
    QLabel *en;
    QLabel *sdcardIcon;
    QLabel *airplaneModeIcon;
    QLabel *bluetoothIcon;

    void setupUi(QDialog *NotificationTray)
    {
        if (NotificationTray->objectName().isEmpty())
            NotificationTray->setObjectName(QStringLiteral("NotificationTray"));
        NotificationTray->resize(480, 20);
        NotificationTray->setStyleSheet(QStringLiteral("background-color: rgb(33, 33, 33);"));
        horizontalLayoutWidget = new QWidget(NotificationTray);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(1, 1, 481, 21));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 1, 5, 1);
        date = new QLabel(horizontalLayoutWidget);
        date->setObjectName(QStringLiteral("date"));
        date->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(date);

        time = new QLabel(horizontalLayoutWidget);
        time->setObjectName(QStringLiteral("time"));
        time->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(time);

        flow = new QLabel(horizontalLayoutWidget);
        flow->setObjectName(QStringLiteral("flow"));
        flow->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(flow);

        eventCountHypoApnea = new QLabel(horizontalLayoutWidget);
        eventCountHypoApnea->setObjectName(QStringLiteral("eventCountHypoApnea"));
        eventCountHypoApnea->setStyleSheet(QStringLiteral("color: rgb(204, 0, 0);"));

        horizontalLayout->addWidget(eventCountHypoApnea);

        leakageCount = new QLabel(horizontalLayoutWidget);
        leakageCount->setObjectName(QStringLiteral("leakageCount"));
        leakageCount->setStyleSheet(QStringLiteral("color: rgb(115, 210, 22);"));

        horizontalLayout->addWidget(leakageCount);

        breathCount = new QLabel(horizontalLayoutWidget);
        breathCount->setObjectName(QStringLiteral("breathCount"));
        breathCount->setStyleSheet(QStringLiteral("color: rgb(204, 0, 0);"));

        horizontalLayout->addWidget(breathCount);

        stableUnstable = new QLabel(horizontalLayoutWidget);
        stableUnstable->setObjectName(QStringLiteral("stableUnstable"));
        stableUnstable->setStyleSheet(QStringLiteral("color: rgb(204, 0, 0);"));

        horizontalLayout->addWidget(stableUnstable);

        maskOffLeak = new QLabel(horizontalLayoutWidget);
        maskOffLeak->setObjectName(QStringLiteral("maskOffLeak"));
        maskOffLeak->setStyleSheet(QStringLiteral("color: rgb(204, 0, 0);"));

        horizontalLayout->addWidget(maskOffLeak);

        eventDetected = new QLabel(horizontalLayoutWidget);
        eventDetected->setObjectName(QStringLiteral("eventDetected"));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(12);
        eventDetected->setFont(font);
        eventDetected->setStyleSheet(QStringLiteral("color: rgb(204, 0, 0);"));
        eventDetected->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(eventDetected);

        en = new QLabel(horizontalLayoutWidget);
        en->setObjectName(QStringLiteral("en"));
        en->setStyleSheet(QStringLiteral("color: rgb(204, 0, 0);"));

        horizontalLayout->addWidget(en);

        sdcardIcon = new QLabel(horizontalLayoutWidget);
        sdcardIcon->setObjectName(QStringLiteral("sdcardIcon"));

        horizontalLayout->addWidget(sdcardIcon);

        airplaneModeIcon = new QLabel(horizontalLayoutWidget);
        airplaneModeIcon->setObjectName(QStringLiteral("airplaneModeIcon"));
        airplaneModeIcon->setStyleSheet(QLatin1String("image: url(:/icons/notification_airplane.png);\n"
""));

        horizontalLayout->addWidget(airplaneModeIcon);

        bluetoothIcon = new QLabel(horizontalLayoutWidget);
        bluetoothIcon->setObjectName(QStringLiteral("bluetoothIcon"));
        bluetoothIcon->setStyleSheet(QStringLiteral("image: url(:/icons/notification_bluetooth.png);"));

        horizontalLayout->addWidget(bluetoothIcon);

        horizontalLayout->setStretch(0, 5);
        horizontalLayout->setStretch(1, 5);
        horizontalLayout->setStretch(2, 3);
        horizontalLayout->setStretch(3, 3);
        horizontalLayout->setStretch(4, 3);
        horizontalLayout->setStretch(5, 1);
        horizontalLayout->setStretch(6, 1);
        horizontalLayout->setStretch(7, 1);
        horizontalLayout->setStretch(8, 1);
        horizontalLayout->setStretch(9, 1);
        horizontalLayout->setStretch(10, 1);
        horizontalLayout->setStretch(11, 1);
        horizontalLayout->setStretch(12, 1);

        retranslateUi(NotificationTray);

        QMetaObject::connectSlotsByName(NotificationTray);
    } // setupUi

    void retranslateUi(QDialog *NotificationTray)
    {
        NotificationTray->setWindowTitle(QApplication::translate("NotificationTray", "Dialog", nullptr));
        date->setText(QApplication::translate("NotificationTray", "Date", nullptr));
        time->setText(QApplication::translate("NotificationTray", "Time", nullptr));
        flow->setText(QApplication::translate("NotificationTray", "Flow", nullptr));
        eventCountHypoApnea->setText(QString());
        leakageCount->setText(QString());
        breathCount->setText(QString());
        stableUnstable->setText(QString());
        maskOffLeak->setText(QString());
        eventDetected->setText(QString());
        en->setText(QString());
        sdcardIcon->setText(QString());
        airplaneModeIcon->setText(QString());
        bluetoothIcon->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class NotificationTray: public Ui_NotificationTray {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTIFICATIONTRAY_H
