/********************************************************************************
** Form generated from reading UI file 'pressureoffsetscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRESSUREOFFSETSCREEN_H
#define UI_PRESSUREOFFSETSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PressureOffsetScreen
{
public:
    QLabel *pressureOffsetTitle;
    QPushButton *pressureOffsetAccept;
    QFrame *frame;
    QPushButton *pressureOffsetAuto;
    QPushButton *pressureOffsetDecrease;
    QPushButton *pressureOffsetIncrease;
    QPushButton *pressureOffsetCancel;
    QLabel *pressureOffsetValue;

    void setupUi(QDialog *PressureOffsetScreen)
    {
        if (PressureOffsetScreen->objectName().isEmpty())
            PressureOffsetScreen->setObjectName(QStringLiteral("PressureOffsetScreen"));
        PressureOffsetScreen->resize(349, 213);
        pressureOffsetTitle = new QLabel(PressureOffsetScreen);
        pressureOffsetTitle->setObjectName(QStringLiteral("pressureOffsetTitle"));
        pressureOffsetTitle->setGeometry(QRect(23, 16, 161, 31));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(11);
        pressureOffsetTitle->setFont(font);
        pressureOffsetTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        pressureOffsetAccept = new QPushButton(PressureOffsetScreen);
        pressureOffsetAccept->setObjectName(QStringLiteral("pressureOffsetAccept"));
        pressureOffsetAccept->setGeometry(QRect(2, 170, 170, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(12);
        pressureOffsetAccept->setFont(font1);
        pressureOffsetAccept->setFocusPolicy(Qt::NoFocus);
        pressureOffsetAccept->setStyleSheet(QLatin1String("QPushButton {\n"
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
        frame = new QFrame(PressureOffsetScreen);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pressureOffsetAuto = new QPushButton(frame);
        pressureOffsetAuto->setObjectName(QStringLiteral("pressureOffsetAuto"));
        pressureOffsetAuto->setGeometry(QRect(10, 60, 170, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Roboto"));
        font2.setPointSize(14);
        pressureOffsetAuto->setFont(font2);
        pressureOffsetAuto->setFocusPolicy(Qt::NoFocus);
        pressureOffsetAuto->setStyleSheet(QLatin1String("QPushButton {\n"
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
        pressureOffsetDecrease = new QPushButton(frame);
        pressureOffsetDecrease->setObjectName(QStringLiteral("pressureOffsetDecrease"));
        pressureOffsetDecrease->setGeometry(QRect(10, 110, 80, 31));
        pressureOffsetDecrease->setFont(font2);
        pressureOffsetDecrease->setFocusPolicy(Qt::NoFocus);
        pressureOffsetDecrease->setStyleSheet(QLatin1String("QPushButton {\n"
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
        pressureOffsetIncrease = new QPushButton(frame);
        pressureOffsetIncrease->setObjectName(QStringLiteral("pressureOffsetIncrease"));
        pressureOffsetIncrease->setGeometry(QRect(100, 110, 80, 31));
        pressureOffsetIncrease->setFont(font2);
        pressureOffsetIncrease->setFocusPolicy(Qt::NoFocus);
        pressureOffsetIncrease->setStyleSheet(QLatin1String("QPushButton {\n"
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
        pressureOffsetCancel = new QPushButton(PressureOffsetScreen);
        pressureOffsetCancel->setObjectName(QStringLiteral("pressureOffsetCancel"));
        pressureOffsetCancel->setGeometry(QRect(175, 170, 170, 40));
        pressureOffsetCancel->setFont(font1);
        pressureOffsetCancel->setFocusPolicy(Qt::NoFocus);
        pressureOffsetCancel->setStyleSheet(QLatin1String("QPushButton {\n"
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
        pressureOffsetValue = new QLabel(PressureOffsetScreen);
        pressureOffsetValue->setObjectName(QStringLiteral("pressureOffsetValue"));
        pressureOffsetValue->setGeometry(QRect(210, 60, 121, 71));
        QFont font3;
        font3.setFamily(QStringLiteral("Roboto"));
        font3.setPointSize(25);
        pressureOffsetValue->setFont(font3);
        pressureOffsetValue->setStyleSheet(QStringLiteral("color:#2196F3"));
        pressureOffsetValue->setAlignment(Qt::AlignCenter);
        frame->raise();
        pressureOffsetCancel->raise();
        pressureOffsetValue->raise();
        pressureOffsetAccept->raise();
        pressureOffsetTitle->raise();

        retranslateUi(PressureOffsetScreen);

        QMetaObject::connectSlotsByName(PressureOffsetScreen);
    } // setupUi

    void retranslateUi(QDialog *PressureOffsetScreen)
    {
        PressureOffsetScreen->setWindowTitle(QApplication::translate("PressureOffsetScreen", "Dialog", nullptr));
        pressureOffsetTitle->setText(QApplication::translate("PressureOffsetScreen", "Pressure Offset", nullptr));
        pressureOffsetAccept->setText(QApplication::translate("PressureOffsetScreen", "Accept", nullptr));
        pressureOffsetAuto->setText(QApplication::translate("PressureOffsetScreen", "Get New Offset", nullptr));
        pressureOffsetDecrease->setText(QApplication::translate("PressureOffsetScreen", "-", nullptr));
        pressureOffsetIncrease->setText(QApplication::translate("PressureOffsetScreen", "+", nullptr));
        pressureOffsetCancel->setText(QApplication::translate("PressureOffsetScreen", "Cancel", nullptr));
        pressureOffsetValue->setText(QApplication::translate("PressureOffsetScreen", "5", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PressureOffsetScreen: public Ui_PressureOffsetScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRESSUREOFFSETSCREEN_H
