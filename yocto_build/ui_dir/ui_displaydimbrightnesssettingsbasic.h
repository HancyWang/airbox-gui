/********************************************************************************
** Form generated from reading UI file 'displaydimbrightnesssettingsbasic.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYDIMBRIGHTNESSSETTINGSBASIC_H
#define UI_DISPLAYDIMBRIGHTNESSSETTINGSBASIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_DisplayDimBrightnessSettingsBasic
{
public:
    QPushButton *displayDimAccept;
    QLabel *displayDimUnit;
    QPushButton *displayDimCancel;
    QLabel *displayDimTitle;
    QSlider *displayDimSlider;
    QPushButton *displayDimIncrement;
    QPushButton *displayDimDecrement;
    QLabel *displayDimValue;
    QFrame *frame;

    void setupUi(QDialog *DisplayDimBrightnessSettingsBasic)
    {
        if (DisplayDimBrightnessSettingsBasic->objectName().isEmpty())
            DisplayDimBrightnessSettingsBasic->setObjectName(QStringLiteral("DisplayDimBrightnessSettingsBasic"));
        DisplayDimBrightnessSettingsBasic->resize(349, 213);
        DisplayDimBrightnessSettingsBasic->setStyleSheet(QStringLiteral(""));
        displayDimAccept = new QPushButton(DisplayDimBrightnessSettingsBasic);
        displayDimAccept->setObjectName(QStringLiteral("displayDimAccept"));
        displayDimAccept->setGeometry(QRect(3, 170, 170, 40));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(12);
        displayDimAccept->setFont(font);
        displayDimAccept->setFocusPolicy(Qt::NoFocus);
        displayDimAccept->setStyleSheet(QLatin1String("QPushButton {\n"
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
        displayDimUnit = new QLabel(DisplayDimBrightnessSettingsBasic);
        displayDimUnit->setObjectName(QStringLiteral("displayDimUnit"));
        displayDimUnit->setGeometry(QRect(121, 99, 50, 14));
        displayDimUnit->setStyleSheet(QStringLiteral("color:#616161"));
        displayDimUnit->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        displayDimCancel = new QPushButton(DisplayDimBrightnessSettingsBasic);
        displayDimCancel->setObjectName(QStringLiteral("displayDimCancel"));
        displayDimCancel->setGeometry(QRect(176, 170, 170, 40));
        displayDimCancel->setFont(font);
        displayDimCancel->setFocusPolicy(Qt::NoFocus);
        displayDimCancel->setStyleSheet(QLatin1String("QPushButton {\n"
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
        displayDimTitle = new QLabel(DisplayDimBrightnessSettingsBasic);
        displayDimTitle->setObjectName(QStringLiteral("displayDimTitle"));
        displayDimTitle->setGeometry(QRect(24, 16, 161, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(11);
        displayDimTitle->setFont(font1);
        displayDimTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        displayDimSlider = new QSlider(DisplayDimBrightnessSettingsBasic);
        displayDimSlider->setObjectName(QStringLiteral("displayDimSlider"));
        displayDimSlider->setGeometry(QRect(19, 125, 217, 32));
        displayDimSlider->setFocusPolicy(Qt::NoFocus);
        displayDimSlider->setStyleSheet(QLatin1String("QSlider::handle:horizontal {\n"
"    background: #8f8f8f;\n"
"    width: 20px;\n"
"    border-radius: 7px;\n"
"}"));
        displayDimSlider->setMinimum(1);
        displayDimSlider->setMaximum(10);
        displayDimSlider->setPageStep(1);
        displayDimSlider->setOrientation(Qt::Horizontal);
        displayDimSlider->setInvertedAppearance(false);
        displayDimSlider->setInvertedControls(false);
        displayDimIncrement = new QPushButton(DisplayDimBrightnessSettingsBasic);
        displayDimIncrement->setObjectName(QStringLiteral("displayDimIncrement"));
        displayDimIncrement->setGeometry(QRect(255, 72, 66, 33));
        QFont font2;
        font2.setFamily(QStringLiteral("Roboto"));
        font2.setPointSize(14);
        displayDimIncrement->setFont(font2);
        displayDimIncrement->setFocusPolicy(Qt::NoFocus);
        displayDimIncrement->setStyleSheet(QLatin1String("QPushButton {\n"
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
        displayDimDecrement = new QPushButton(DisplayDimBrightnessSettingsBasic);
        displayDimDecrement->setObjectName(QStringLiteral("displayDimDecrement"));
        displayDimDecrement->setGeometry(QRect(255, 118, 66, 33));
        displayDimDecrement->setFont(font2);
        displayDimDecrement->setFocusPolicy(Qt::NoFocus);
        displayDimDecrement->setStyleSheet(QLatin1String("QPushButton {\n"
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
        displayDimValue = new QLabel(DisplayDimBrightnessSettingsBasic);
        displayDimValue->setObjectName(QStringLiteral("displayDimValue"));
        displayDimValue->setGeometry(QRect(121, 50, 50, 44));
        QFont font3;
        font3.setFamily(QStringLiteral("Roboto"));
        font3.setPointSize(28);
        displayDimValue->setFont(font3);
        displayDimValue->setStyleSheet(QStringLiteral("color:#2196F3"));
        displayDimValue->setAlignment(Qt::AlignCenter);
        frame = new QFrame(DisplayDimBrightnessSettingsBasic);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        displayDimAccept->raise();
        displayDimUnit->raise();
        displayDimCancel->raise();
        displayDimTitle->raise();
        displayDimSlider->raise();
        displayDimIncrement->raise();
        displayDimDecrement->raise();
        displayDimValue->raise();

        retranslateUi(DisplayDimBrightnessSettingsBasic);

        QMetaObject::connectSlotsByName(DisplayDimBrightnessSettingsBasic);
    } // setupUi

    void retranslateUi(QDialog *DisplayDimBrightnessSettingsBasic)
    {
        DisplayDimBrightnessSettingsBasic->setWindowTitle(QApplication::translate("DisplayDimBrightnessSettingsBasic", "Dialog", nullptr));
        displayDimAccept->setText(QApplication::translate("DisplayDimBrightnessSettingsBasic", "Accept", nullptr));
        displayDimUnit->setText(QApplication::translate("DisplayDimBrightnessSettingsBasic", "min", nullptr));
        displayDimCancel->setText(QApplication::translate("DisplayDimBrightnessSettingsBasic", "Cancel", nullptr));
        displayDimTitle->setText(QApplication::translate("DisplayDimBrightnessSettingsBasic", "Display Dim Duration", nullptr));
        displayDimIncrement->setText(QApplication::translate("DisplayDimBrightnessSettingsBasic", "+", nullptr));
        displayDimDecrement->setText(QApplication::translate("DisplayDimBrightnessSettingsBasic", "-", nullptr));
        displayDimValue->setText(QApplication::translate("DisplayDimBrightnessSettingsBasic", "5", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DisplayDimBrightnessSettingsBasic: public Ui_DisplayDimBrightnessSettingsBasic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYDIMBRIGHTNESSSETTINGSBASIC_H
