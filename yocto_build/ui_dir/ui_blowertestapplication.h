/********************************************************************************
** Form generated from reading UI file 'blowertestapplication.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLOWERTESTAPPLICATION_H
#define UI_BLOWERTESTAPPLICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_BlowerTestApplication
{
public:
    QFrame *frame;
    QLabel *flowEngValue;
    QPushButton *decrementButton;
    QLabel *rpmTitle;
    QLabel *statusText;
    QLabel *pressureEngUnit;
    QLabel *brakeValue;
    QLabel *rpmValue;
    QLabel *brakeTitle;
    QLabel *brakeUnit;
    QLabel *flowEngTitle;
    QLabel *lightTitle;
    QPushButton *startStopButton;
    QLabel *lightValue;
    QLabel *lightUnit;
    QLabel *rpmUnit;
    QLabel *pressureEngValue;
    QPushButton *incrementButton;
    QLabel *flowEngUnit;
    QLabel *pressureEngTitle;
    QPushButton *exitButton;
    QPushButton *brakeDecrementButton;
    QPushButton *brakeIncrementButton;
    QRadioButton *resBrakeButton;
    QRadioButton *plugBrakeButton;
    QRadioButton *noBrakeButton;
    QButtonGroup *brakeButtonGroup;

    void setupUi(QDialog *BlowerTestApplication)
    {
        if (BlowerTestApplication->objectName().isEmpty())
            BlowerTestApplication->setObjectName(QStringLiteral("BlowerTestApplication"));
        BlowerTestApplication->resize(480, 272);
        frame = new QFrame(BlowerTestApplication);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 20, 480, 272));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QStringLiteral("background-color:rgb(29,32,39);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        flowEngValue = new QLabel(frame);
        flowEngValue->setObjectName(QStringLiteral("flowEngValue"));
        flowEngValue->setEnabled(false);
        flowEngValue->setGeometry(QRect(390, 75, 70, 65));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        font.setKerning(true);
        flowEngValue->setFont(font);
        flowEngValue->setLayoutDirection(Qt::LeftToRight);
        flowEngValue->setStyleSheet(QLatin1String("background-color:rgb(47,52,58);\n"
"color:rgb(10,192,245);\n"
"border-color: rgb(89, 89, 89);\n"
"border:1px solid grey; \n"
"border-radius: 3px;\n"
""));
        flowEngValue->setFrameShape(QFrame::StyledPanel);
        flowEngValue->setFrameShadow(QFrame::Raised);
        flowEngValue->setLineWidth(7);
        flowEngValue->setMidLineWidth(2);
        flowEngValue->setAlignment(Qt::AlignCenter);
        flowEngValue->setTextInteractionFlags(Qt::TextEditable);
        decrementButton = new QPushButton(frame);
        decrementButton->setObjectName(QStringLiteral("decrementButton"));
        decrementButton->setEnabled(true);
        decrementButton->setGeometry(QRect(106, 140, 80, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setWeight(50);
        decrementButton->setFont(font1);
        decrementButton->setFocusPolicy(Qt::NoFocus);
        decrementButton->setStyleSheet(QStringLiteral("color:#FFFFFF;"));
        rpmTitle = new QLabel(frame);
        rpmTitle->setObjectName(QStringLiteral("rpmTitle"));
        rpmTitle->setEnabled(false);
        rpmTitle->setGeometry(QRect(321, 150, 31, 21));
        QFont font2;
        font2.setFamily(QStringLiteral("Roboto"));
        font2.setPointSize(9);
        rpmTitle->setFont(font2);
        rpmTitle->setStyleSheet(QLatin1String("background:transparent;\n"
"border:0px;\n"
"border-radius: 0px;"));
        rpmTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        statusText = new QLabel(frame);
        statusText->setObjectName(QStringLiteral("statusText"));
        statusText->setGeometry(QRect(0, 222, 480, 30));
        QFont font3;
        font3.setFamily(QStringLiteral("Roboto"));
        font3.setPointSize(16);
        statusText->setFont(font3);
        statusText->setLayoutDirection(Qt::LeftToRight);
        statusText->setStyleSheet(QLatin1String("color:rgb(255,255,255);\n"
"background-color: rgb(170, 0, 0);"));
        statusText->setAlignment(Qt::AlignCenter);
        pressureEngUnit = new QLabel(frame);
        pressureEngUnit->setObjectName(QStringLiteral("pressureEngUnit"));
        pressureEngUnit->setEnabled(false);
        pressureEngUnit->setGeometry(QRect(436, 45, 20, 20));
        pressureEngUnit->setFont(font2);
        pressureEngUnit->setStyleSheet(QStringLiteral("background:transparent;"));
        pressureEngUnit->setAlignment(Qt::AlignCenter);
        brakeValue = new QLabel(frame);
        brakeValue->setObjectName(QStringLiteral("brakeValue"));
        brakeValue->setEnabled(false);
        brakeValue->setGeometry(QRect(316, 5, 70, 65));
        brakeValue->setFont(font);
        brakeValue->setLayoutDirection(Qt::LeftToRight);
        brakeValue->setStyleSheet(QLatin1String("background-color:rgb(47,52,58);\n"
"color:rgb(233,30,99);\n"
"border-color: rgb(89, 89, 89);\n"
"border:1px solid grey; \n"
"border-radius: 3px;\n"
""));
        brakeValue->setFrameShape(QFrame::StyledPanel);
        brakeValue->setFrameShadow(QFrame::Raised);
        brakeValue->setLineWidth(7);
        brakeValue->setMidLineWidth(2);
        brakeValue->setAlignment(Qt::AlignCenter);
        brakeValue->setTextInteractionFlags(Qt::TextEditable);
        rpmValue = new QLabel(frame);
        rpmValue->setObjectName(QStringLiteral("rpmValue"));
        rpmValue->setEnabled(false);
        rpmValue->setGeometry(QRect(316, 145, 144, 65));
        QFont font4;
        font4.setFamily(QStringLiteral("DejaVu Sans"));
        font4.setPointSize(23);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setUnderline(false);
        font4.setWeight(50);
        font4.setStrikeOut(false);
        font4.setKerning(true);
        rpmValue->setFont(font4);
        rpmValue->setLayoutDirection(Qt::LeftToRight);
        rpmValue->setStyleSheet(QLatin1String("background-color:rgb(47,52,58);\n"
"color:rgb(233,30,99);\n"
"border-color: rgb(89, 89, 89);\n"
"border:1px solid grey; \n"
"border-radius: 3px;\n"
""));
        rpmValue->setFrameShape(QFrame::StyledPanel);
        rpmValue->setFrameShadow(QFrame::Raised);
        rpmValue->setLineWidth(7);
        rpmValue->setMidLineWidth(2);
        rpmValue->setAlignment(Qt::AlignCenter);
        rpmValue->setTextInteractionFlags(Qt::TextEditable);
        brakeTitle = new QLabel(frame);
        brakeTitle->setObjectName(QStringLiteral("brakeTitle"));
        brakeTitle->setEnabled(false);
        brakeTitle->setGeometry(QRect(321, 10, 51, 20));
        brakeTitle->setFont(font2);
        brakeTitle->setStyleSheet(QLatin1String("border:0px;\n"
"border-radius: 0px;\n"
"background:transparent;"));
        brakeTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        brakeUnit = new QLabel(frame);
        brakeUnit->setObjectName(QStringLiteral("brakeUnit"));
        brakeUnit->setEnabled(false);
        brakeUnit->setGeometry(QRect(366, 45, 20, 20));
        brakeUnit->setFont(font2);
        brakeUnit->setStyleSheet(QStringLiteral("background:transparent;"));
        brakeUnit->setAlignment(Qt::AlignCenter);
        flowEngTitle = new QLabel(frame);
        flowEngTitle->setObjectName(QStringLiteral("flowEngTitle"));
        flowEngTitle->setEnabled(false);
        flowEngTitle->setGeometry(QRect(396, 80, 31, 20));
        flowEngTitle->setFont(font2);
        flowEngTitle->setStyleSheet(QLatin1String("border:0px;\n"
"border-radius: 0px;\n"
"background:transparent;\n"
""));
        flowEngTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lightTitle = new QLabel(frame);
        lightTitle->setObjectName(QStringLiteral("lightTitle"));
        lightTitle->setEnabled(false);
        lightTitle->setGeometry(QRect(321, 80, 51, 16));
        lightTitle->setFont(font2);
        lightTitle->setStyleSheet(QLatin1String("border:0px;\n"
"border-radius: 0px;\n"
"background:transparent;"));
        lightTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        startStopButton = new QPushButton(frame);
        startStopButton->setObjectName(QStringLiteral("startStopButton"));
        startStopButton->setGeometry(QRect(16, 95, 80, 85));
        startStopButton->setFont(font1);
        startStopButton->setFocusPolicy(Qt::NoFocus);
        startStopButton->setStyleSheet(QStringLiteral("color:#FFFFFF;"));
        lightValue = new QLabel(frame);
        lightValue->setObjectName(QStringLiteral("lightValue"));
        lightValue->setEnabled(false);
        lightValue->setGeometry(QRect(316, 75, 70, 65));
        lightValue->setFont(font);
        lightValue->setLayoutDirection(Qt::LeftToRight);
        lightValue->setStyleSheet(QLatin1String("background-color:rgb(47,52,58);\n"
"color:rgb(10,192,245);\n"
"border-color: rgb(89, 89, 89);\n"
"border:1px solid grey; \n"
"border-radius: 3px;\n"
""));
        lightValue->setFrameShape(QFrame::StyledPanel);
        lightValue->setFrameShadow(QFrame::Raised);
        lightValue->setLineWidth(7);
        lightValue->setMidLineWidth(2);
        lightValue->setAlignment(Qt::AlignCenter);
        lightValue->setTextInteractionFlags(Qt::TextEditable);
        lightUnit = new QLabel(frame);
        lightUnit->setObjectName(QStringLiteral("lightUnit"));
        lightUnit->setEnabled(false);
        lightUnit->setGeometry(QRect(356, 115, 31, 21));
        lightUnit->setFont(font2);
        lightUnit->setStyleSheet(QStringLiteral("background:transparent;"));
        lightUnit->setAlignment(Qt::AlignCenter);
        rpmUnit = new QLabel(frame);
        rpmUnit->setObjectName(QStringLiteral("rpmUnit"));
        rpmUnit->setEnabled(false);
        rpmUnit->setGeometry(QRect(426, 185, 31, 20));
        rpmUnit->setFont(font2);
        rpmUnit->setStyleSheet(QStringLiteral("background:transparent;"));
        rpmUnit->setAlignment(Qt::AlignCenter);
        pressureEngValue = new QLabel(frame);
        pressureEngValue->setObjectName(QStringLiteral("pressureEngValue"));
        pressureEngValue->setEnabled(false);
        pressureEngValue->setGeometry(QRect(390, 5, 70, 65));
        pressureEngValue->setFont(font);
        pressureEngValue->setLayoutDirection(Qt::LeftToRight);
        pressureEngValue->setStyleSheet(QLatin1String("background-color:rgb(47,52,58);\n"
"color:rgb(10,192,245);\n"
"border-color: rgb(89, 89, 89);\n"
"border:1px solid grey; \n"
"border-radius: 3px;\n"
""));
        pressureEngValue->setFrameShape(QFrame::StyledPanel);
        pressureEngValue->setFrameShadow(QFrame::Raised);
        pressureEngValue->setLineWidth(7);
        pressureEngValue->setMidLineWidth(2);
        pressureEngValue->setAlignment(Qt::AlignCenter);
        pressureEngValue->setTextInteractionFlags(Qt::TextEditable);
        incrementButton = new QPushButton(frame);
        incrementButton->setObjectName(QStringLiteral("incrementButton"));
        incrementButton->setGeometry(QRect(106, 95, 80, 40));
        incrementButton->setFont(font1);
        incrementButton->setFocusPolicy(Qt::NoFocus);
        incrementButton->setStyleSheet(QStringLiteral("color:#FFFFFF;"));
        flowEngUnit = new QLabel(frame);
        flowEngUnit->setObjectName(QStringLiteral("flowEngUnit"));
        flowEngUnit->setEnabled(false);
        flowEngUnit->setGeometry(QRect(425, 115, 31, 20));
        flowEngUnit->setFont(font2);
        flowEngUnit->setStyleSheet(QStringLiteral("background:transparent;"));
        flowEngUnit->setAlignment(Qt::AlignCenter);
        pressureEngTitle = new QLabel(frame);
        pressureEngTitle->setObjectName(QStringLiteral("pressureEngTitle"));
        pressureEngTitle->setEnabled(false);
        pressureEngTitle->setGeometry(QRect(396, 10, 61, 20));
        pressureEngTitle->setFont(font2);
        pressureEngTitle->setStyleSheet(QLatin1String("background:transparent;\n"
"border:0px;\n"
"border-radius: 0px;"));
        pressureEngTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        exitButton = new QPushButton(frame);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(16, 183, 170, 31));
        exitButton->setFocusPolicy(Qt::NoFocus);
        exitButton->setStyleSheet(QStringLiteral("color:#FFFFFF;"));
        brakeDecrementButton = new QPushButton(frame);
        brakeDecrementButton->setObjectName(QStringLiteral("brakeDecrementButton"));
        brakeDecrementButton->setEnabled(true);
        brakeDecrementButton->setGeometry(QRect(120, 40, 61, 31));
        brakeDecrementButton->setFont(font1);
        brakeDecrementButton->setFocusPolicy(Qt::NoFocus);
        brakeDecrementButton->setStyleSheet(QStringLiteral("color:#FFFFFF;"));
        brakeIncrementButton = new QPushButton(frame);
        brakeIncrementButton->setObjectName(QStringLiteral("brakeIncrementButton"));
        brakeIncrementButton->setGeometry(QRect(120, 10, 61, 31));
        brakeIncrementButton->setFont(font1);
        brakeIncrementButton->setFocusPolicy(Qt::NoFocus);
        brakeIncrementButton->setStyleSheet(QStringLiteral("color:#FFFFFF;"));
        resBrakeButton = new QRadioButton(frame);
        brakeButtonGroup = new QButtonGroup(BlowerTestApplication);
        brakeButtonGroup->setObjectName(QStringLiteral("brakeButtonGroup"));
        brakeButtonGroup->addButton(resBrakeButton);
        resBrakeButton->setObjectName(QStringLiteral("resBrakeButton"));
        resBrakeButton->setGeometry(QRect(20, 10, 100, 20));
        resBrakeButton->setFocusPolicy(Qt::NoFocus);
        resBrakeButton->setStyleSheet(QStringLiteral("color:#FFFFFF;"));
        plugBrakeButton = new QRadioButton(frame);
        brakeButtonGroup->addButton(plugBrakeButton);
        plugBrakeButton->setObjectName(QStringLiteral("plugBrakeButton"));
        plugBrakeButton->setGeometry(QRect(20, 30, 100, 20));
        plugBrakeButton->setFocusPolicy(Qt::NoFocus);
        plugBrakeButton->setStyleSheet(QStringLiteral("color:#FFFFFF;"));
        noBrakeButton = new QRadioButton(frame);
        brakeButtonGroup->addButton(noBrakeButton);
        noBrakeButton->setObjectName(QStringLiteral("noBrakeButton"));
        noBrakeButton->setGeometry(QRect(20, 50, 100, 20));
        noBrakeButton->setFocusPolicy(Qt::NoFocus);
        noBrakeButton->setStyleSheet(QStringLiteral("color:#FFFFFF;"));
        rpmValue->raise();
        lightValue->raise();
        flowEngValue->raise();
        decrementButton->raise();
        rpmTitle->raise();
        statusText->raise();
        brakeValue->raise();
        brakeTitle->raise();
        brakeUnit->raise();
        flowEngTitle->raise();
        lightTitle->raise();
        startStopButton->raise();
        lightUnit->raise();
        rpmUnit->raise();
        pressureEngValue->raise();
        incrementButton->raise();
        flowEngUnit->raise();
        pressureEngTitle->raise();
        exitButton->raise();
        pressureEngUnit->raise();
        brakeDecrementButton->raise();
        brakeIncrementButton->raise();
        resBrakeButton->raise();
        plugBrakeButton->raise();
        noBrakeButton->raise();

        retranslateUi(BlowerTestApplication);

        QMetaObject::connectSlotsByName(BlowerTestApplication);
    } // setupUi

    void retranslateUi(QDialog *BlowerTestApplication)
    {
        BlowerTestApplication->setWindowTitle(QApplication::translate("BlowerTestApplication", "Dialog", nullptr));
        flowEngValue->setText(QApplication::translate("BlowerTestApplication", "0", nullptr));
        decrementButton->setText(QApplication::translate("BlowerTestApplication", "-", nullptr));
        rpmTitle->setText(QApplication::translate("BlowerTestApplication", "RPM", nullptr));
        statusText->setText(QApplication::translate("BlowerTestApplication", "BLOWER OFF", nullptr));
        pressureEngUnit->setText(QApplication::translate("BlowerTestApplication", "bar", nullptr));
        brakeValue->setText(QApplication::translate("BlowerTestApplication", "0", nullptr));
        rpmValue->setText(QApplication::translate("BlowerTestApplication", "0", nullptr));
        brakeTitle->setText(QApplication::translate("BlowerTestApplication", "Brake", nullptr));
        brakeUnit->setText(QApplication::translate("BlowerTestApplication", "%", nullptr));
        flowEngTitle->setText(QApplication::translate("BlowerTestApplication", "Flow", nullptr));
        lightTitle->setText(QApplication::translate("BlowerTestApplication", "Light", nullptr));
        startStopButton->setText(QApplication::translate("BlowerTestApplication", "START", nullptr));
        lightValue->setText(QApplication::translate("BlowerTestApplication", "0", nullptr));
        lightUnit->setText(QApplication::translate("BlowerTestApplication", "%", nullptr));
        rpmUnit->setText(QApplication::translate("BlowerTestApplication", "%", nullptr));
        pressureEngValue->setText(QApplication::translate("BlowerTestApplication", "0", nullptr));
        incrementButton->setText(QApplication::translate("BlowerTestApplication", "+", nullptr));
        flowEngUnit->setText(QApplication::translate("BlowerTestApplication", "cc/s", nullptr));
        pressureEngTitle->setText(QApplication::translate("BlowerTestApplication", "Pressure", nullptr));
        exitButton->setText(QApplication::translate("BlowerTestApplication", "Exit", nullptr));
        brakeDecrementButton->setText(QApplication::translate("BlowerTestApplication", "-", nullptr));
        brakeIncrementButton->setText(QApplication::translate("BlowerTestApplication", "+", nullptr));
        resBrakeButton->setText(QApplication::translate("BlowerTestApplication", "Res. Brake", nullptr));
        plugBrakeButton->setText(QApplication::translate("BlowerTestApplication", "Plug. Brake", nullptr));
        noBrakeButton->setText(QApplication::translate("BlowerTestApplication", "No Brake", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BlowerTestApplication: public Ui_BlowerTestApplication {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLOWERTESTAPPLICATION_H
