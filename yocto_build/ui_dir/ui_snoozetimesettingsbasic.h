/********************************************************************************
** Form generated from reading UI file 'snoozetimesettingsbasic.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNOOZETIMESETTINGSBASIC_H
#define UI_SNOOZETIMESETTINGSBASIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_SnoozeTimeSettingsBasic
{
public:
    QPushButton *snoozeTimeAccept;
    QLabel *snoozeTimeUnit;
    QLabel *snoozeTimeTitle;
    QSlider *snoozeTimeSlider;
    QPushButton *snoozeTimeIncrement;
    QPushButton *snoozeTimeCancel;
    QPushButton *snoozeTimeDecrement;
    QLabel *snoozeTimeValue;
    QFrame *frame;

    void setupUi(QDialog *SnoozeTimeSettingsBasic)
    {
        if (SnoozeTimeSettingsBasic->objectName().isEmpty())
            SnoozeTimeSettingsBasic->setObjectName(QStringLiteral("SnoozeTimeSettingsBasic"));
        SnoozeTimeSettingsBasic->resize(349, 213);
        SnoozeTimeSettingsBasic->setStyleSheet(QStringLiteral(""));
        snoozeTimeAccept = new QPushButton(SnoozeTimeSettingsBasic);
        snoozeTimeAccept->setObjectName(QStringLiteral("snoozeTimeAccept"));
        snoozeTimeAccept->setGeometry(QRect(3, 170, 170, 40));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(12);
        snoozeTimeAccept->setFont(font);
        snoozeTimeAccept->setFocusPolicy(Qt::NoFocus);
        snoozeTimeAccept->setStyleSheet(QLatin1String("QPushButton {\n"
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
        snoozeTimeUnit = new QLabel(SnoozeTimeSettingsBasic);
        snoozeTimeUnit->setObjectName(QStringLiteral("snoozeTimeUnit"));
        snoozeTimeUnit->setGeometry(QRect(121, 100, 50, 14));
        snoozeTimeUnit->setStyleSheet(QStringLiteral("color:#616161"));
        snoozeTimeUnit->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        snoozeTimeTitle = new QLabel(SnoozeTimeSettingsBasic);
        snoozeTimeTitle->setObjectName(QStringLiteral("snoozeTimeTitle"));
        snoozeTimeTitle->setGeometry(QRect(24, 16, 161, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(11);
        snoozeTimeTitle->setFont(font1);
        snoozeTimeTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        snoozeTimeSlider = new QSlider(SnoozeTimeSettingsBasic);
        snoozeTimeSlider->setObjectName(QStringLiteral("snoozeTimeSlider"));
        snoozeTimeSlider->setGeometry(QRect(19, 125, 217, 32));
        snoozeTimeSlider->setFocusPolicy(Qt::NoFocus);
        snoozeTimeSlider->setStyleSheet(QLatin1String("QSlider::handle:horizontal {\n"
"    background: #8f8f8f;\n"
"    width: 20px;\n"
"    border-radius: 7px;\n"
"}"));
        snoozeTimeSlider->setOrientation(Qt::Horizontal);
        snoozeTimeIncrement = new QPushButton(SnoozeTimeSettingsBasic);
        snoozeTimeIncrement->setObjectName(QStringLiteral("snoozeTimeIncrement"));
        snoozeTimeIncrement->setGeometry(QRect(255, 72, 66, 33));
        QFont font2;
        font2.setFamily(QStringLiteral("Roboto"));
        font2.setPointSize(14);
        snoozeTimeIncrement->setFont(font2);
        snoozeTimeIncrement->setFocusPolicy(Qt::NoFocus);
        snoozeTimeIncrement->setStyleSheet(QLatin1String("QPushButton {\n"
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
        snoozeTimeCancel = new QPushButton(SnoozeTimeSettingsBasic);
        snoozeTimeCancel->setObjectName(QStringLiteral("snoozeTimeCancel"));
        snoozeTimeCancel->setGeometry(QRect(176, 170, 170, 40));
        snoozeTimeCancel->setFont(font);
        snoozeTimeCancel->setFocusPolicy(Qt::NoFocus);
        snoozeTimeCancel->setStyleSheet(QLatin1String("QPushButton {\n"
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
        snoozeTimeDecrement = new QPushButton(SnoozeTimeSettingsBasic);
        snoozeTimeDecrement->setObjectName(QStringLiteral("snoozeTimeDecrement"));
        snoozeTimeDecrement->setGeometry(QRect(255, 118, 66, 33));
        snoozeTimeDecrement->setFont(font2);
        snoozeTimeDecrement->setFocusPolicy(Qt::NoFocus);
        snoozeTimeDecrement->setStyleSheet(QLatin1String("QPushButton {\n"
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
        snoozeTimeValue = new QLabel(SnoozeTimeSettingsBasic);
        snoozeTimeValue->setObjectName(QStringLiteral("snoozeTimeValue"));
        snoozeTimeValue->setGeometry(QRect(121, 50, 50, 44));
        QFont font3;
        font3.setFamily(QStringLiteral("Roboto"));
        font3.setPointSize(28);
        snoozeTimeValue->setFont(font3);
        snoozeTimeValue->setStyleSheet(QStringLiteral("color:#2196F3"));
        snoozeTimeValue->setAlignment(Qt::AlignCenter);
        frame = new QFrame(SnoozeTimeSettingsBasic);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        snoozeTimeAccept->raise();
        snoozeTimeUnit->raise();
        snoozeTimeTitle->raise();
        snoozeTimeSlider->raise();
        snoozeTimeIncrement->raise();
        snoozeTimeCancel->raise();
        snoozeTimeDecrement->raise();
        snoozeTimeValue->raise();

        retranslateUi(SnoozeTimeSettingsBasic);

        QMetaObject::connectSlotsByName(SnoozeTimeSettingsBasic);
    } // setupUi

    void retranslateUi(QDialog *SnoozeTimeSettingsBasic)
    {
        SnoozeTimeSettingsBasic->setWindowTitle(QApplication::translate("SnoozeTimeSettingsBasic", "Dialog", nullptr));
        snoozeTimeAccept->setText(QApplication::translate("SnoozeTimeSettingsBasic", "Accept", nullptr));
        snoozeTimeUnit->setText(QApplication::translate("SnoozeTimeSettingsBasic", "min", nullptr));
        snoozeTimeTitle->setText(QApplication::translate("SnoozeTimeSettingsBasic", "Snooze Time", nullptr));
        snoozeTimeIncrement->setText(QApplication::translate("SnoozeTimeSettingsBasic", "+", nullptr));
        snoozeTimeCancel->setText(QApplication::translate("SnoozeTimeSettingsBasic", "Cancel", nullptr));
        snoozeTimeDecrement->setText(QApplication::translate("SnoozeTimeSettingsBasic", "-", nullptr));
        snoozeTimeValue->setText(QApplication::translate("SnoozeTimeSettingsBasic", "5", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SnoozeTimeSettingsBasic: public Ui_SnoozeTimeSettingsBasic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNOOZETIMESETTINGSBASIC_H
