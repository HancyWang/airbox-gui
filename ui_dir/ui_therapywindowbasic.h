/********************************************************************************
** Form generated from reading UI file 'therapywindowbasic.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THERAPYWINDOWBASIC_H
#define UI_THERAPYWINDOWBASIC_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TherapyWindowBasic
{
public:
    QLabel *therapyTitle;
    QPushButton *homeTherapyButton;
    QFrame *rampTimeFrame;
    QLabel *rampTimeTitle;
    QLabel *rampTimeRemainingTime;
    QLabel *rampTime;
    QLabel *rampTimeUnit;
    QFrame *goToSleepFrame;
    QLabel *goToSleepTitle;
    QLabel *goToSleepRemainingTime;
    QLabel *goToSleepTime;
    QLabel *goToSleepUnit;
    QFrame *snoozeDisplayFrame;
    QLabel *snoozeTitle;
    QLabel *snoozeTime;
    QWidget *therapyWidget;
    QPushButton *changeParameterButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *rLayout;
    QLabel *rTitle;
    QLabel *referenceWindow;
    QHBoxLayout *cLayout;
    QLabel *cTitle;
    QLabel *currentWindow;

    void setupUi(QDialog *TherapyWindowBasic)
    {
        if (TherapyWindowBasic->objectName().isEmpty())
            TherapyWindowBasic->setObjectName(QStringLiteral("TherapyWindowBasic"));
        TherapyWindowBasic->resize(480, 272);
        TherapyWindowBasic->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
""));
        therapyTitle = new QLabel(TherapyWindowBasic);
        therapyTitle->setObjectName(QStringLiteral("therapyTitle"));
        therapyTitle->setGeometry(QRect(71, 24, 161, 30));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(14);
        therapyTitle->setFont(font);
        therapyTitle->setStyleSheet(QLatin1String("color:#1788c3\n"
""));
        homeTherapyButton = new QPushButton(TherapyWindowBasic);
        homeTherapyButton->setObjectName(QStringLiteral("homeTherapyButton"));
        homeTherapyButton->setGeometry(QRect(9, 24, 38, 30));
        homeTherapyButton->setFocusPolicy(Qt::NoFocus);
        homeTherapyButton->setStyleSheet(QLatin1String("border:none;\n"
"border-radius:3px;\n"
"background-color: rgb(70, 70, 73);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/home.png"), QSize(), QIcon::Normal, QIcon::Off);
        homeTherapyButton->setIcon(icon);
        rampTimeFrame = new QFrame(TherapyWindowBasic);
        rampTimeFrame->setObjectName(QStringLiteral("rampTimeFrame"));
        rampTimeFrame->setGeometry(QRect(169, 207, 145, 60));
        rampTimeFrame->setStyleSheet(QLatin1String("border-radius:5px;\n"
"background-color: rgb(59, 59, 59);"));
        rampTimeFrame->setFrameShape(QFrame::StyledPanel);
        rampTimeFrame->setFrameShadow(QFrame::Raised);
        rampTimeTitle = new QLabel(rampTimeFrame);
        rampTimeTitle->setObjectName(QStringLiteral("rampTimeTitle"));
        rampTimeTitle->setGeometry(QRect(5, 0, 91, 21));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(10);
        rampTimeTitle->setFont(font1);
        rampTimeTitle->setStyleSheet(QStringLiteral("color:#BDBDBD;"));
        rampTimeRemainingTime = new QLabel(rampTimeFrame);
        rampTimeRemainingTime->setObjectName(QStringLiteral("rampTimeRemainingTime"));
        rampTimeRemainingTime->setGeometry(QRect(5, 30, 76, 21));
        QFont font2;
        font2.setFamily(QStringLiteral("Roboto"));
        font2.setPointSize(12);
        rampTimeRemainingTime->setFont(font2);
        rampTimeRemainingTime->setStyleSheet(QStringLiteral("color:#BDBDBD;"));
        rampTime = new QLabel(rampTimeFrame);
        rampTime->setObjectName(QStringLiteral("rampTime"));
        rampTime->setGeometry(QRect(80, 0, 56, 41));
        QFont font3;
        font3.setFamily(QStringLiteral("Roboto"));
        font3.setPointSize(24);
        rampTime->setFont(font3);
        rampTime->setStyleSheet(QStringLiteral("color:#2196F3;"));
        rampTime->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        rampTimeUnit = new QLabel(rampTimeFrame);
        rampTimeUnit->setObjectName(QStringLiteral("rampTimeUnit"));
        rampTimeUnit->setGeometry(QRect(80, 35, 56, 21));
        QFont font4;
        font4.setFamily(QStringLiteral("Roboto"));
        font4.setPointSize(9);
        rampTimeUnit->setFont(font4);
        rampTimeUnit->setStyleSheet(QStringLiteral("color:#616161;"));
        rampTimeUnit->setAlignment(Qt::AlignCenter);
        goToSleepFrame = new QFrame(TherapyWindowBasic);
        goToSleepFrame->setObjectName(QStringLiteral("goToSleepFrame"));
        goToSleepFrame->setGeometry(QRect(321, 207, 145, 60));
        goToSleepFrame->setStyleSheet(QLatin1String("border-radius:5px;\n"
"background-color: rgb(59, 59, 59);"));
        goToSleepFrame->setFrameShape(QFrame::StyledPanel);
        goToSleepFrame->setFrameShadow(QFrame::Raised);
        goToSleepTitle = new QLabel(goToSleepFrame);
        goToSleepTitle->setObjectName(QStringLiteral("goToSleepTitle"));
        goToSleepTitle->setGeometry(QRect(5, 0, 91, 21));
        goToSleepTitle->setFont(font1);
        goToSleepTitle->setStyleSheet(QStringLiteral("color:#BDBDBD;"));
        goToSleepRemainingTime = new QLabel(goToSleepFrame);
        goToSleepRemainingTime->setObjectName(QStringLiteral("goToSleepRemainingTime"));
        goToSleepRemainingTime->setGeometry(QRect(5, 30, 76, 21));
        goToSleepRemainingTime->setFont(font2);
        goToSleepRemainingTime->setStyleSheet(QStringLiteral("color:#BDBDBD;"));
        goToSleepTime = new QLabel(goToSleepFrame);
        goToSleepTime->setObjectName(QStringLiteral("goToSleepTime"));
        goToSleepTime->setGeometry(QRect(90, 0, 51, 41));
        goToSleepTime->setFont(font3);
        goToSleepTime->setStyleSheet(QStringLiteral("color:#2196F3;"));
        goToSleepTime->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        goToSleepUnit = new QLabel(goToSleepFrame);
        goToSleepUnit->setObjectName(QStringLiteral("goToSleepUnit"));
        goToSleepUnit->setGeometry(QRect(90, 35, 51, 21));
        goToSleepUnit->setFont(font4);
        goToSleepUnit->setStyleSheet(QStringLiteral("color:#616161;"));
        goToSleepUnit->setAlignment(Qt::AlignCenter);
        snoozeDisplayFrame = new QFrame(TherapyWindowBasic);
        snoozeDisplayFrame->setObjectName(QStringLiteral("snoozeDisplayFrame"));
        snoozeDisplayFrame->setGeometry(QRect(350, 140, 116, 60));
        snoozeDisplayFrame->setStyleSheet(QLatin1String("border-radius:5px;\n"
"background-color: rgb(46, 69, 88);"));
        snoozeDisplayFrame->setFrameShape(QFrame::StyledPanel);
        snoozeDisplayFrame->setFrameShadow(QFrame::Raised);
        snoozeTitle = new QLabel(snoozeDisplayFrame);
        snoozeTitle->setObjectName(QStringLiteral("snoozeTitle"));
        snoozeTitle->setGeometry(QRect(5, 0, 91, 21));
        QFont font5;
        font5.setFamily(QStringLiteral("Roboto"));
        font5.setPointSize(8);
        snoozeTitle->setFont(font5);
        snoozeTitle->setStyleSheet(QStringLiteral("color:#BDBDBD;"));
        snoozeTime = new QLabel(snoozeDisplayFrame);
        snoozeTime->setObjectName(QStringLiteral("snoozeTime"));
        snoozeTime->setGeometry(QRect(15, 30, 76, 21));
        snoozeTime->setFont(font2);
        snoozeTime->setStyleSheet(QStringLiteral("color:#BDBDBD;"));
        therapyWidget = new QWidget(TherapyWindowBasic);
        therapyWidget->setObjectName(QStringLiteral("therapyWidget"));
        therapyWidget->setGeometry(QRect(151, 55, 182, 150));
        changeParameterButton = new QPushButton(TherapyWindowBasic);
        changeParameterButton->setObjectName(QStringLiteral("changeParameterButton"));
        changeParameterButton->setGeometry(QRect(15, 100, 101, 51));
        changeParameterButton->setFont(font2);
        changeParameterButton->setFocusPolicy(Qt::NoFocus);
        changeParameterButton->setStyleSheet(QLatin1String("QPushButton {\n"
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
        layoutWidget = new QWidget(TherapyWindowBasic);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(340, 40, 136, 46));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        rLayout = new QHBoxLayout();
        rLayout->setObjectName(QStringLiteral("rLayout"));
        rTitle = new QLabel(layoutWidget);
        rTitle->setObjectName(QStringLiteral("rTitle"));
        rTitle->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        rLayout->addWidget(rTitle);

        referenceWindow = new QLabel(layoutWidget);
        referenceWindow->setObjectName(QStringLiteral("referenceWindow"));
        referenceWindow->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        rLayout->addWidget(referenceWindow);

        rLayout->setStretch(0, 3);
        rLayout->setStretch(1, 6);

        verticalLayout->addLayout(rLayout);

        cLayout = new QHBoxLayout();
        cLayout->setObjectName(QStringLiteral("cLayout"));
        cTitle = new QLabel(layoutWidget);
        cTitle->setObjectName(QStringLiteral("cTitle"));
        cTitle->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        cLayout->addWidget(cTitle);

        currentWindow = new QLabel(layoutWidget);
        currentWindow->setObjectName(QStringLiteral("currentWindow"));
        currentWindow->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        cLayout->addWidget(currentWindow);

        cLayout->setStretch(0, 3);
        cLayout->setStretch(1, 6);

        verticalLayout->addLayout(cLayout);


        retranslateUi(TherapyWindowBasic);

        QMetaObject::connectSlotsByName(TherapyWindowBasic);
    } // setupUi

    void retranslateUi(QDialog *TherapyWindowBasic)
    {
        TherapyWindowBasic->setWindowTitle(QApplication::translate("TherapyWindowBasic", "Dialog", nullptr));
        therapyTitle->setText(QApplication::translate("TherapyWindowBasic", "Therapy", nullptr));
        homeTherapyButton->setText(QString());
        rampTimeTitle->setText(QApplication::translate("TherapyWindowBasic", "Ramp Time", nullptr));
        rampTimeRemainingTime->setText(QApplication::translate("TherapyWindowBasic", "01:00", nullptr));
        rampTime->setText(QApplication::translate("TherapyWindowBasic", "1", nullptr));
        rampTimeUnit->setText(QApplication::translate("TherapyWindowBasic", "min", nullptr));
        goToSleepTitle->setText(QApplication::translate("TherapyWindowBasic", "Go To Sleep", nullptr));
        goToSleepRemainingTime->setText(QApplication::translate("TherapyWindowBasic", "01:00", nullptr));
        goToSleepTime->setText(QApplication::translate("TherapyWindowBasic", "1", nullptr));
        goToSleepUnit->setText(QApplication::translate("TherapyWindowBasic", "min", nullptr));
        snoozeTitle->setText(QApplication::translate("TherapyWindowBasic", "Snooze Active", nullptr));
        snoozeTime->setText(QString());
        changeParameterButton->setText(QApplication::translate("TherapyWindowBasic", "Change \n"
"Parameter", nullptr));
        rTitle->setText(QApplication::translate("TherapyWindowBasic", "w16", nullptr));
        referenceWindow->setText(QString());
        cTitle->setText(QApplication::translate("TherapyWindowBasic", "w4", nullptr));
        currentWindow->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TherapyWindowBasic: public Ui_TherapyWindowBasic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THERAPYWINDOWBASIC_H
