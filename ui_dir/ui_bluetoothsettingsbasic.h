/********************************************************************************
** Form generated from reading UI file 'bluetoothsettingsbasic.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLUETOOTHSETTINGSBASIC_H
#define UI_BLUETOOTHSETTINGSBASIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BluetoothSettingsBasic
{
public:
    QLabel *bluetoothDeviceTitle;
    QPushButton *bluetoothDeviceCancel;
    QPushButton *bluetoothDeviceAccept;
    QFrame *frame;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QPushButton *deviceIcon2;
    QPushButton *deviceIcon3;
    QPushButton *deviceIcon4;
    QPushButton *deviceIcon5;
    QPushButton *deviceText1;
    QPushButton *deviceText2;
    QPushButton *deviceText3;
    QPushButton *deviceText4;
    QPushButton *deviceText5;
    QPushButton *deviceIcon1;

    void setupUi(QDialog *BluetoothSettingsBasic)
    {
        if (BluetoothSettingsBasic->objectName().isEmpty())
            BluetoothSettingsBasic->setObjectName(QStringLiteral("BluetoothSettingsBasic"));
        BluetoothSettingsBasic->resize(349, 213);
        BluetoothSettingsBasic->setStyleSheet(QStringLiteral(""));
        bluetoothDeviceTitle = new QLabel(BluetoothSettingsBasic);
        bluetoothDeviceTitle->setObjectName(QStringLiteral("bluetoothDeviceTitle"));
        bluetoothDeviceTitle->setGeometry(QRect(24, 16, 181, 31));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(11);
        bluetoothDeviceTitle->setFont(font);
        bluetoothDeviceTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        bluetoothDeviceTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        bluetoothDeviceCancel = new QPushButton(BluetoothSettingsBasic);
        bluetoothDeviceCancel->setObjectName(QStringLiteral("bluetoothDeviceCancel"));
        bluetoothDeviceCancel->setGeometry(QRect(176, 170, 170, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(12);
        bluetoothDeviceCancel->setFont(font1);
        bluetoothDeviceCancel->setFocusPolicy(Qt::NoFocus);
        bluetoothDeviceCancel->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color:#3B3B3B;\n"
"color:#BDBDBD;\n"
"border:none;\n"
"border-radius:3px;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color:#606060;\n"
"color:#BDBDBD;\n"
"border:none;\n"
"border-radius:3px;\n"
"}\n"
""));
        bluetoothDeviceAccept = new QPushButton(BluetoothSettingsBasic);
        bluetoothDeviceAccept->setObjectName(QStringLiteral("bluetoothDeviceAccept"));
        bluetoothDeviceAccept->setGeometry(QRect(3, 170, 170, 40));
        bluetoothDeviceAccept->setFont(font1);
        bluetoothDeviceAccept->setFocusPolicy(Qt::NoFocus);
        bluetoothDeviceAccept->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color:#3B3B3B;\n"
"color:#BDBDBD;\n"
"border:none;\n"
"border-radius:3px;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color:#606060;\n"
"color:#BDBDBD;\n"
"border:none;\n"
"border-radius:3px;\n"
"}\n"
""));
        frame = new QFrame(BluetoothSettingsBasic);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        formLayoutWidget = new QWidget(frame);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(30, 40, 291, 121));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setHorizontalSpacing(90);
        formLayout->setVerticalSpacing(6);
        formLayout->setContentsMargins(20, 5, 5, 5);
        deviceIcon2 = new QPushButton(formLayoutWidget);
        deviceIcon2->setObjectName(QStringLiteral("deviceIcon2"));
        deviceIcon2->setFocusPolicy(Qt::NoFocus);

        formLayout->setWidget(1, QFormLayout::FieldRole, deviceIcon2);

        deviceIcon3 = new QPushButton(formLayoutWidget);
        deviceIcon3->setObjectName(QStringLiteral("deviceIcon3"));
        deviceIcon3->setFocusPolicy(Qt::NoFocus);

        formLayout->setWidget(2, QFormLayout::FieldRole, deviceIcon3);

        deviceIcon4 = new QPushButton(formLayoutWidget);
        deviceIcon4->setObjectName(QStringLiteral("deviceIcon4"));
        deviceIcon4->setFocusPolicy(Qt::NoFocus);

        formLayout->setWidget(3, QFormLayout::FieldRole, deviceIcon4);

        deviceIcon5 = new QPushButton(formLayoutWidget);
        deviceIcon5->setObjectName(QStringLiteral("deviceIcon5"));
        deviceIcon5->setFocusPolicy(Qt::NoFocus);

        formLayout->setWidget(4, QFormLayout::FieldRole, deviceIcon5);

        deviceText1 = new QPushButton(formLayoutWidget);
        deviceText1->setObjectName(QStringLiteral("deviceText1"));
        deviceText1->setFocusPolicy(Qt::NoFocus);
        deviceText1->setStyleSheet(QStringLiteral("color: rgb(136, 138, 133);"));

        formLayout->setWidget(0, QFormLayout::LabelRole, deviceText1);

        deviceText2 = new QPushButton(formLayoutWidget);
        deviceText2->setObjectName(QStringLiteral("deviceText2"));
        deviceText2->setFocusPolicy(Qt::NoFocus);
        deviceText2->setStyleSheet(QStringLiteral("color: rgb(136, 138, 133);"));

        formLayout->setWidget(1, QFormLayout::LabelRole, deviceText2);

        deviceText3 = new QPushButton(formLayoutWidget);
        deviceText3->setObjectName(QStringLiteral("deviceText3"));
        deviceText3->setFocusPolicy(Qt::NoFocus);
        deviceText3->setStyleSheet(QStringLiteral("color: rgb(136, 138, 133);"));

        formLayout->setWidget(2, QFormLayout::LabelRole, deviceText3);

        deviceText4 = new QPushButton(formLayoutWidget);
        deviceText4->setObjectName(QStringLiteral("deviceText4"));
        deviceText4->setFocusPolicy(Qt::NoFocus);
        deviceText4->setStyleSheet(QStringLiteral("color: rgb(136, 138, 133);"));

        formLayout->setWidget(3, QFormLayout::LabelRole, deviceText4);

        deviceText5 = new QPushButton(formLayoutWidget);
        deviceText5->setObjectName(QStringLiteral("deviceText5"));
        deviceText5->setFocusPolicy(Qt::NoFocus);
        deviceText5->setStyleSheet(QStringLiteral("color: rgb(136, 138, 133);"));

        formLayout->setWidget(4, QFormLayout::LabelRole, deviceText5);

        deviceIcon1 = new QPushButton(formLayoutWidget);
        deviceIcon1->setObjectName(QStringLiteral("deviceIcon1"));
        deviceIcon1->setFocusPolicy(Qt::NoFocus);

        formLayout->setWidget(0, QFormLayout::FieldRole, deviceIcon1);

        frame->raise();
        bluetoothDeviceTitle->raise();
        bluetoothDeviceCancel->raise();
        bluetoothDeviceAccept->raise();

        retranslateUi(BluetoothSettingsBasic);

        QMetaObject::connectSlotsByName(BluetoothSettingsBasic);
    } // setupUi

    void retranslateUi(QDialog *BluetoothSettingsBasic)
    {
        BluetoothSettingsBasic->setWindowTitle(QApplication::translate("BluetoothSettingsBasic", "Dialog", nullptr));
        bluetoothDeviceTitle->setText(QApplication::translate("BluetoothSettingsBasic", "Paired Device Name", nullptr));
        bluetoothDeviceCancel->setText(QApplication::translate("BluetoothSettingsBasic", "Cancel", nullptr));
        bluetoothDeviceAccept->setText(QApplication::translate("BluetoothSettingsBasic", "Accept", nullptr));
        deviceIcon2->setText(QString());
        deviceIcon3->setText(QString());
        deviceIcon4->setText(QString());
        deviceIcon5->setText(QString());
        deviceText1->setText(QString());
        deviceText2->setText(QString());
        deviceText3->setText(QString());
        deviceText4->setText(QString());
        deviceText5->setText(QString());
        deviceIcon1->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BluetoothSettingsBasic: public Ui_BluetoothSettingsBasic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLUETOOTHSETTINGSBASIC_H
