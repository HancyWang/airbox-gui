/********************************************************************************
** Form generated from reading UI file 'gotosleepsettingsbasic.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOTOSLEEPSETTINGSBASIC_H
#define UI_GOTOSLEEPSETTINGSBASIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_GoToSleepSettingsBasic
{
public:
    QLabel *goToSleepTitle;
    QPushButton *goToSleepTimeAccept;
    QPushButton *goToSleepTimeCancel;
    QLabel *smartStartTitle;
    QPushButton *goToSleepTimeIncrement;
    QPushButton *goToSleepTimeDecrement;
    QLabel *goToSleepTimeValue;
    QLabel *goToSleepTimeUnit;
    QSlider *goToSleepTimeSlider;
    QFrame *frame;

    void setupUi(QDialog *GoToSleepSettingsBasic)
    {
        if (GoToSleepSettingsBasic->objectName().isEmpty())
            GoToSleepSettingsBasic->setObjectName(QStringLiteral("GoToSleepSettingsBasic"));
        GoToSleepSettingsBasic->resize(349, 213);
        GoToSleepSettingsBasic->setStyleSheet(QStringLiteral(""));
        goToSleepTitle = new QLabel(GoToSleepSettingsBasic);
        goToSleepTitle->setObjectName(QStringLiteral("goToSleepTitle"));
        goToSleepTitle->setGeometry(QRect(24, 16, 161, 31));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(11);
        goToSleepTitle->setFont(font);
        goToSleepTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        goToSleepTimeAccept = new QPushButton(GoToSleepSettingsBasic);
        goToSleepTimeAccept->setObjectName(QStringLiteral("goToSleepTimeAccept"));
        goToSleepTimeAccept->setGeometry(QRect(3, 170, 170, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(12);
        goToSleepTimeAccept->setFont(font1);
        goToSleepTimeAccept->setFocusPolicy(Qt::NoFocus);
        goToSleepTimeAccept->setStyleSheet(QLatin1String("QPushButton {\n"
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
        goToSleepTimeCancel = new QPushButton(GoToSleepSettingsBasic);
        goToSleepTimeCancel->setObjectName(QStringLiteral("goToSleepTimeCancel"));
        goToSleepTimeCancel->setGeometry(QRect(176, 170, 170, 40));
        goToSleepTimeCancel->setFont(font1);
        goToSleepTimeCancel->setFocusPolicy(Qt::NoFocus);
        goToSleepTimeCancel->setStyleSheet(QLatin1String("QPushButton {\n"
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
        smartStartTitle = new QLabel(GoToSleepSettingsBasic);
        smartStartTitle->setObjectName(QStringLiteral("smartStartTitle"));
        smartStartTitle->setGeometry(QRect(200, 20, 80, 31));
        smartStartTitle->setStyleSheet(QStringLiteral("color:#616161"));
        goToSleepTimeIncrement = new QPushButton(GoToSleepSettingsBasic);
        goToSleepTimeIncrement->setObjectName(QStringLiteral("goToSleepTimeIncrement"));
        goToSleepTimeIncrement->setGeometry(QRect(255, 72, 66, 33));
        QFont font2;
        font2.setFamily(QStringLiteral("Roboto"));
        font2.setPointSize(14);
        goToSleepTimeIncrement->setFont(font2);
        goToSleepTimeIncrement->setFocusPolicy(Qt::NoFocus);
        goToSleepTimeIncrement->setStyleSheet(QLatin1String("QPushButton {\n"
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
        goToSleepTimeDecrement = new QPushButton(GoToSleepSettingsBasic);
        goToSleepTimeDecrement->setObjectName(QStringLiteral("goToSleepTimeDecrement"));
        goToSleepTimeDecrement->setGeometry(QRect(255, 118, 66, 33));
        goToSleepTimeDecrement->setFont(font2);
        goToSleepTimeDecrement->setFocusPolicy(Qt::NoFocus);
        goToSleepTimeDecrement->setStyleSheet(QLatin1String("QPushButton {\n"
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
        goToSleepTimeValue = new QLabel(GoToSleepSettingsBasic);
        goToSleepTimeValue->setObjectName(QStringLiteral("goToSleepTimeValue"));
        goToSleepTimeValue->setGeometry(QRect(121, 55, 50, 44));
        QFont font3;
        font3.setFamily(QStringLiteral("Roboto"));
        font3.setPointSize(28);
        goToSleepTimeValue->setFont(font3);
        goToSleepTimeValue->setStyleSheet(QStringLiteral("color:#2196F3"));
        goToSleepTimeValue->setAlignment(Qt::AlignCenter);
        goToSleepTimeUnit = new QLabel(GoToSleepSettingsBasic);
        goToSleepTimeUnit->setObjectName(QStringLiteral("goToSleepTimeUnit"));
        goToSleepTimeUnit->setGeometry(QRect(121, 99, 50, 14));
        goToSleepTimeUnit->setStyleSheet(QStringLiteral("color:#616161"));
        goToSleepTimeUnit->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        goToSleepTimeSlider = new QSlider(GoToSleepSettingsBasic);
        goToSleepTimeSlider->setObjectName(QStringLiteral("goToSleepTimeSlider"));
        goToSleepTimeSlider->setGeometry(QRect(19, 125, 217, 32));
        goToSleepTimeSlider->setFocusPolicy(Qt::NoFocus);
        goToSleepTimeSlider->setStyleSheet(QLatin1String("QSlider::handle:horizontal {\n"
"    background: #8f8f8f;\n"
"    width: 20px;\n"
"    border-radius: 7px;\n"
"}"));
        goToSleepTimeSlider->setMaximum(45);
        goToSleepTimeSlider->setSingleStep(5);
        goToSleepTimeSlider->setOrientation(Qt::Horizontal);
        goToSleepTimeSlider->setInvertedAppearance(false);
        goToSleepTimeSlider->setInvertedControls(false);
        frame = new QFrame(GoToSleepSettingsBasic);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        goToSleepTitle->raise();
        goToSleepTimeAccept->raise();
        goToSleepTimeCancel->raise();
        smartStartTitle->raise();
        goToSleepTimeIncrement->raise();
        goToSleepTimeDecrement->raise();
        goToSleepTimeValue->raise();
        goToSleepTimeUnit->raise();
        goToSleepTimeSlider->raise();

        retranslateUi(GoToSleepSettingsBasic);

        QMetaObject::connectSlotsByName(GoToSleepSettingsBasic);
    } // setupUi

    void retranslateUi(QDialog *GoToSleepSettingsBasic)
    {
        GoToSleepSettingsBasic->setWindowTitle(QApplication::translate("GoToSleepSettingsBasic", "Dialog", nullptr));
        goToSleepTitle->setText(QApplication::translate("GoToSleepSettingsBasic", "GoTo Sleep Time", nullptr));
        goToSleepTimeAccept->setText(QApplication::translate("GoToSleepSettingsBasic", "Accept", nullptr));
        goToSleepTimeCancel->setText(QApplication::translate("GoToSleepSettingsBasic", "Cancel", nullptr));
        smartStartTitle->setText(QApplication::translate("GoToSleepSettingsBasic", "Smart Start", nullptr));
        goToSleepTimeIncrement->setText(QApplication::translate("GoToSleepSettingsBasic", "+", nullptr));
        goToSleepTimeDecrement->setText(QApplication::translate("GoToSleepSettingsBasic", "-", nullptr));
        goToSleepTimeValue->setText(QApplication::translate("GoToSleepSettingsBasic", "25", nullptr));
        goToSleepTimeUnit->setText(QApplication::translate("GoToSleepSettingsBasic", "min", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GoToSleepSettingsBasic: public Ui_GoToSleepSettingsBasic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOTOSLEEPSETTINGSBASIC_H
