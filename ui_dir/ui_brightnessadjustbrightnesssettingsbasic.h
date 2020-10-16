/********************************************************************************
** Form generated from reading UI file 'brightnessadjustbrightnesssettingsbasic.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BRIGHTNESSADJUSTBRIGHTNESSSETTINGSBASIC_H
#define UI_BRIGHTNESSADJUSTBRIGHTNESSSETTINGSBASIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_BrightnessAdjustBrightnessSettingsBasic
{
public:
    QLabel *brightnessLevelTitle;
    QPushButton *brightnessLevelCancel;
    QLabel *brightnessLevelSetTitle;
    QPushButton *brightnessLevelAccept;
    QFrame *frame;
    QLabel *brightnessAdjustUnit;
    QSlider *brightnessSlider;
    QPushButton *brightnessAdjustIncrement;
    QPushButton *brightnessAdjustDecrement;

    void setupUi(QDialog *BrightnessAdjustBrightnessSettingsBasic)
    {
        if (BrightnessAdjustBrightnessSettingsBasic->objectName().isEmpty())
            BrightnessAdjustBrightnessSettingsBasic->setObjectName(QStringLiteral("BrightnessAdjustBrightnessSettingsBasic"));
        BrightnessAdjustBrightnessSettingsBasic->resize(349, 213);
        BrightnessAdjustBrightnessSettingsBasic->setStyleSheet(QStringLiteral(""));
        brightnessLevelTitle = new QLabel(BrightnessAdjustBrightnessSettingsBasic);
        brightnessLevelTitle->setObjectName(QStringLiteral("brightnessLevelTitle"));
        brightnessLevelTitle->setGeometry(QRect(24, 13, 181, 31));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(11);
        brightnessLevelTitle->setFont(font);
        brightnessLevelTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        brightnessLevelTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        brightnessLevelCancel = new QPushButton(BrightnessAdjustBrightnessSettingsBasic);
        brightnessLevelCancel->setObjectName(QStringLiteral("brightnessLevelCancel"));
        brightnessLevelCancel->setGeometry(QRect(176, 170, 170, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(12);
        brightnessLevelCancel->setFont(font1);
        brightnessLevelCancel->setFocusPolicy(Qt::NoFocus);
        brightnessLevelCancel->setStyleSheet(QLatin1String("QPushButton {\n"
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
        brightnessLevelSetTitle = new QLabel(BrightnessAdjustBrightnessSettingsBasic);
        brightnessLevelSetTitle->setObjectName(QStringLiteral("brightnessLevelSetTitle"));
        brightnessLevelSetTitle->setGeometry(QRect(38, 69, 111, 20));
        QFont font2;
        font2.setFamily(QStringLiteral("Roboto"));
        font2.setPointSize(10);
        brightnessLevelSetTitle->setFont(font2);
        brightnessLevelSetTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        brightnessLevelAccept = new QPushButton(BrightnessAdjustBrightnessSettingsBasic);
        brightnessLevelAccept->setObjectName(QStringLiteral("brightnessLevelAccept"));
        brightnessLevelAccept->setGeometry(QRect(3, 170, 170, 40));
        brightnessLevelAccept->setFont(font1);
        brightnessLevelAccept->setFocusPolicy(Qt::NoFocus);
        brightnessLevelAccept->setStyleSheet(QLatin1String("QPushButton {\n"
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
        frame = new QFrame(BrightnessAdjustBrightnessSettingsBasic);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        brightnessAdjustUnit = new QLabel(frame);
        brightnessAdjustUnit->setObjectName(QStringLiteral("brightnessAdjustUnit"));
        brightnessAdjustUnit->setGeometry(QRect(220, 20, 50, 30));
        brightnessAdjustUnit->setStyleSheet(QStringLiteral("color:#616161"));
        brightnessAdjustUnit->setAlignment(Qt::AlignCenter);
        brightnessSlider = new QSlider(frame);
        brightnessSlider->setObjectName(QStringLiteral("brightnessSlider"));
        brightnessSlider->setGeometry(QRect(38, 105, 217, 41));
        brightnessSlider->setFocusPolicy(Qt::NoFocus);
        brightnessSlider->setStyleSheet(QLatin1String("QSlider::handle:horizontal {\n"
"	background: #8f8f8f;\n"
"	height:50px;\n"
"	width: 20px;\n"
"	border-radius: 7px;\n"
"}"));
        brightnessSlider->setMinimum(1);
        brightnessSlider->setMaximum(100);
        brightnessSlider->setValue(10);
        brightnessSlider->setSliderPosition(10);
        brightnessSlider->setOrientation(Qt::Horizontal);
        brightnessAdjustIncrement = new QPushButton(frame);
        brightnessAdjustIncrement->setObjectName(QStringLiteral("brightnessAdjustIncrement"));
        brightnessAdjustIncrement->setGeometry(QRect(260, 74, 66, 33));
        QFont font3;
        font3.setFamily(QStringLiteral("Roboto"));
        font3.setPointSize(14);
        brightnessAdjustIncrement->setFont(font3);
        brightnessAdjustIncrement->setFocusPolicy(Qt::NoFocus);
        brightnessAdjustIncrement->setStyleSheet(QLatin1String("QPushButton {\n"
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
        brightnessAdjustDecrement = new QPushButton(frame);
        brightnessAdjustDecrement->setObjectName(QStringLiteral("brightnessAdjustDecrement"));
        brightnessAdjustDecrement->setGeometry(QRect(260, 120, 66, 33));
        brightnessAdjustDecrement->setFont(font3);
        brightnessAdjustDecrement->setFocusPolicy(Qt::NoFocus);
        brightnessAdjustDecrement->setStyleSheet(QLatin1String("QPushButton {\n"
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
        frame->raise();
        brightnessLevelTitle->raise();
        brightnessLevelCancel->raise();
        brightnessLevelSetTitle->raise();
        brightnessLevelAccept->raise();

        retranslateUi(BrightnessAdjustBrightnessSettingsBasic);

        QMetaObject::connectSlotsByName(BrightnessAdjustBrightnessSettingsBasic);
    } // setupUi

    void retranslateUi(QDialog *BrightnessAdjustBrightnessSettingsBasic)
    {
        BrightnessAdjustBrightnessSettingsBasic->setWindowTitle(QApplication::translate("BrightnessAdjustBrightnessSettingsBasic", "Dialog", nullptr));
        brightnessLevelTitle->setText(QApplication::translate("BrightnessAdjustBrightnessSettingsBasic", "Brightness Adjustment", nullptr));
        brightnessLevelCancel->setText(QApplication::translate("BrightnessAdjustBrightnessSettingsBasic", "Cancel", nullptr));
        brightnessLevelSetTitle->setText(QApplication::translate("BrightnessAdjustBrightnessSettingsBasic", "Brightness Level", nullptr));
        brightnessLevelAccept->setText(QApplication::translate("BrightnessAdjustBrightnessSettingsBasic", "Accept", nullptr));
        brightnessAdjustUnit->setText(QApplication::translate("BrightnessAdjustBrightnessSettingsBasic", "Auto", nullptr));
        brightnessAdjustIncrement->setText(QApplication::translate("BrightnessAdjustBrightnessSettingsBasic", "+", nullptr));
        brightnessAdjustDecrement->setText(QApplication::translate("BrightnessAdjustBrightnessSettingsBasic", "-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BrightnessAdjustBrightnessSettingsBasic: public Ui_BrightnessAdjustBrightnessSettingsBasic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BRIGHTNESSADJUSTBRIGHTNESSSETTINGSBASIC_H
