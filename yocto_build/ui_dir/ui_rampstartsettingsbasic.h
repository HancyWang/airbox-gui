/********************************************************************************
** Form generated from reading UI file 'rampstartsettingsbasic.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RAMPSTARTSETTINGSBASIC_H
#define UI_RAMPSTARTSETTINGSBASIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_RampStartSettingsBasic
{
public:
    QLabel *rampTimeValue;
    QLabel *rampTimeTitle;
    QPushButton *rampTimeIncrement;
    QLabel *rampSmartStartTitle;
    QPushButton *rampTimeCancel;
    QPushButton *rampTimeDecrement;
    QPushButton *rampTimeAccept;
    QLabel *rampTimeUnit;
    QSlider *rampTimeSlider;
    QFrame *frame;

    void setupUi(QDialog *RampStartSettingsBasic)
    {
        if (RampStartSettingsBasic->objectName().isEmpty())
            RampStartSettingsBasic->setObjectName(QStringLiteral("RampStartSettingsBasic"));
        RampStartSettingsBasic->resize(349, 213);
        RampStartSettingsBasic->setStyleSheet(QStringLiteral(""));
        rampTimeValue = new QLabel(RampStartSettingsBasic);
        rampTimeValue->setObjectName(QStringLiteral("rampTimeValue"));
        rampTimeValue->setGeometry(QRect(121, 49, 50, 44));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(28);
        rampTimeValue->setFont(font);
        rampTimeValue->setStyleSheet(QStringLiteral("color:#2196F3"));
        rampTimeValue->setAlignment(Qt::AlignCenter);
        rampTimeTitle = new QLabel(RampStartSettingsBasic);
        rampTimeTitle->setObjectName(QStringLiteral("rampTimeTitle"));
        rampTimeTitle->setGeometry(QRect(24, 16, 121, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(11);
        rampTimeTitle->setFont(font1);
        rampTimeTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        rampTimeIncrement = new QPushButton(RampStartSettingsBasic);
        rampTimeIncrement->setObjectName(QStringLiteral("rampTimeIncrement"));
        rampTimeIncrement->setGeometry(QRect(255, 72, 66, 33));
        QFont font2;
        font2.setFamily(QStringLiteral("Roboto"));
        font2.setPointSize(14);
        rampTimeIncrement->setFont(font2);
        rampTimeIncrement->setFocusPolicy(Qt::NoFocus);
        rampTimeIncrement->setStyleSheet(QLatin1String("QPushButton {\n"
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
        rampSmartStartTitle = new QLabel(RampStartSettingsBasic);
        rampSmartStartTitle->setObjectName(QStringLiteral("rampSmartStartTitle"));
        rampSmartStartTitle->setGeometry(QRect(200, 20, 80, 30));
        rampSmartStartTitle->setStyleSheet(QStringLiteral("color:#616161"));
        rampTimeCancel = new QPushButton(RampStartSettingsBasic);
        rampTimeCancel->setObjectName(QStringLiteral("rampTimeCancel"));
        rampTimeCancel->setGeometry(QRect(176, 170, 170, 40));
        QFont font3;
        font3.setFamily(QStringLiteral("Roboto"));
        font3.setPointSize(12);
        rampTimeCancel->setFont(font3);
        rampTimeCancel->setFocusPolicy(Qt::NoFocus);
        rampTimeCancel->setStyleSheet(QLatin1String("QPushButton {\n"
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
        rampTimeDecrement = new QPushButton(RampStartSettingsBasic);
        rampTimeDecrement->setObjectName(QStringLiteral("rampTimeDecrement"));
        rampTimeDecrement->setGeometry(QRect(255, 118, 66, 33));
        rampTimeDecrement->setFont(font2);
        rampTimeDecrement->setFocusPolicy(Qt::NoFocus);
        rampTimeDecrement->setStyleSheet(QLatin1String("QPushButton {\n"
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
        rampTimeAccept = new QPushButton(RampStartSettingsBasic);
        rampTimeAccept->setObjectName(QStringLiteral("rampTimeAccept"));
        rampTimeAccept->setGeometry(QRect(3, 170, 170, 40));
        rampTimeAccept->setFont(font3);
        rampTimeAccept->setFocusPolicy(Qt::NoFocus);
        rampTimeAccept->setStyleSheet(QLatin1String("QPushButton {\n"
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
        rampTimeUnit = new QLabel(RampStartSettingsBasic);
        rampTimeUnit->setObjectName(QStringLiteral("rampTimeUnit"));
        rampTimeUnit->setGeometry(QRect(121, 100, 50, 14));
        rampTimeUnit->setStyleSheet(QStringLiteral("color:#616161"));
        rampTimeUnit->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        rampTimeSlider = new QSlider(RampStartSettingsBasic);
        rampTimeSlider->setObjectName(QStringLiteral("rampTimeSlider"));
        rampTimeSlider->setGeometry(QRect(19, 125, 217, 32));
        rampTimeSlider->setFocusPolicy(Qt::NoFocus);
        rampTimeSlider->setStyleSheet(QLatin1String("QSlider::handle:horizontal {\n"
"    background: #8f8f8f;\n"
"    width: 20px;\n"
"    border-radius: 7px;\n"
"}"));
        rampTimeSlider->setMaximum(45);
        rampTimeSlider->setSingleStep(5);
        rampTimeSlider->setOrientation(Qt::Horizontal);
        rampTimeSlider->setInvertedAppearance(false);
        rampTimeSlider->setInvertedControls(false);
        frame = new QFrame(RampStartSettingsBasic);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        rampTimeValue->raise();
        rampTimeTitle->raise();
        rampTimeIncrement->raise();
        rampSmartStartTitle->raise();
        rampTimeCancel->raise();
        rampTimeDecrement->raise();
        rampTimeAccept->raise();
        rampTimeUnit->raise();
        rampTimeSlider->raise();

        retranslateUi(RampStartSettingsBasic);

        QMetaObject::connectSlotsByName(RampStartSettingsBasic);
    } // setupUi

    void retranslateUi(QDialog *RampStartSettingsBasic)
    {
        RampStartSettingsBasic->setWindowTitle(QApplication::translate("RampStartSettingsBasic", "Dialog", nullptr));
        rampTimeValue->setText(QApplication::translate("RampStartSettingsBasic", "25", nullptr));
        rampTimeTitle->setText(QApplication::translate("RampStartSettingsBasic", "Ramp Time", nullptr));
        rampTimeIncrement->setText(QApplication::translate("RampStartSettingsBasic", "+", nullptr));
        rampSmartStartTitle->setText(QApplication::translate("RampStartSettingsBasic", "Smart Start", nullptr));
        rampTimeCancel->setText(QApplication::translate("RampStartSettingsBasic", "Cancel", nullptr));
        rampTimeDecrement->setText(QApplication::translate("RampStartSettingsBasic", "-", nullptr));
        rampTimeAccept->setText(QApplication::translate("RampStartSettingsBasic", "Accept", nullptr));
        rampTimeUnit->setText(QApplication::translate("RampStartSettingsBasic", "min", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RampStartSettingsBasic: public Ui_RampStartSettingsBasic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RAMPSTARTSETTINGSBASIC_H
