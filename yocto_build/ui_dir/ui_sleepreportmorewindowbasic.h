/********************************************************************************
** Form generated from reading UI file 'sleepreportmorewindowbasic.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLEEPREPORTMOREWINDOWBASIC_H
#define UI_SLEEPREPORTMOREWINDOWBASIC_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SleepReportMoreWindowBasic
{
public:
    QFrame *SleepReportMoreWindowBasicBk;
    QPushButton *backSleepReportMoreButton;
    QLabel *sleepReportMoreTitle;
    QFrame *daysUsed;
    QLabel *daysUsedTitle;
    QLabel *daysUsedText;
    QLabel *daysUsedUnit;
    QFrame *days4HrsPlus;
    QLabel *days4HrsPlusTitle;
    QLabel *days4HrsPlusText;
    QLabel *days4HrsPlusUnit;
    QFrame *averageUsage;
    QLabel *averageUsageTitle;
    QLabel *averageUsageText;
    QLabel *averageUsageUnit;
    QFrame *usedHours;
    QLabel *usedHoursTitle;
    QLabel *usedHoursText;
    QLabel *usedHoursUnit;
    QFrame *leak;
    QLabel *leakTitle;
    QLabel *leakText;
    QLabel *leakUnit;
    QFrame *ahi;
    QLabel *ahiTitle;
    QLabel *ahiText;
    QLabel *selectionPeriod;
    QPushButton *sendSleepReportButton;

    void setupUi(QDialog *SleepReportMoreWindowBasic)
    {
        if (SleepReportMoreWindowBasic->objectName().isEmpty())
            SleepReportMoreWindowBasic->setObjectName(QStringLiteral("SleepReportMoreWindowBasic"));
        SleepReportMoreWindowBasic->resize(480, 272);
        SleepReportMoreWindowBasicBk = new QFrame(SleepReportMoreWindowBasic);
        SleepReportMoreWindowBasicBk->setObjectName(QStringLiteral("SleepReportMoreWindowBasicBk"));
        SleepReportMoreWindowBasicBk->setGeometry(QRect(0, 0, 480, 272));
        SleepReportMoreWindowBasicBk->setMaximumSize(QSize(480, 272));
        SleepReportMoreWindowBasicBk->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
""));
        SleepReportMoreWindowBasicBk->setFrameShape(QFrame::StyledPanel);
        SleepReportMoreWindowBasicBk->setFrameShadow(QFrame::Raised);
        backSleepReportMoreButton = new QPushButton(SleepReportMoreWindowBasicBk);
        backSleepReportMoreButton->setObjectName(QStringLiteral("backSleepReportMoreButton"));
        backSleepReportMoreButton->setGeometry(QRect(9, 24, 38, 30));
        backSleepReportMoreButton->setFocusPolicy(Qt::NoFocus);
        backSleepReportMoreButton->setStyleSheet(QLatin1String("border:none;\n"
"border-radius:3px;\n"
"background-color: rgb(70, 70, 73);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        backSleepReportMoreButton->setIcon(icon);
        sleepReportMoreTitle = new QLabel(SleepReportMoreWindowBasicBk);
        sleepReportMoreTitle->setObjectName(QStringLiteral("sleepReportMoreTitle"));
        sleepReportMoreTitle->setGeometry(QRect(83, 29, 131, 25));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(14);
        sleepReportMoreTitle->setFont(font);
        sleepReportMoreTitle->setStyleSheet(QLatin1String("color:#1788c3\n"
""));
        daysUsed = new QFrame(SleepReportMoreWindowBasicBk);
        daysUsed->setObjectName(QStringLiteral("daysUsed"));
        daysUsed->setGeometry(QRect(260, 45, 210, 33));
        daysUsed->setStyleSheet(QLatin1String("background-color:#3D3D3D;\n"
"border-radius:3px;\n"
""));
        daysUsed->setFrameShape(QFrame::StyledPanel);
        daysUsed->setFrameShadow(QFrame::Raised);
        daysUsedTitle = new QLabel(daysUsed);
        daysUsedTitle->setObjectName(QStringLiteral("daysUsedTitle"));
        daysUsedTitle->setGeometry(QRect(3, 2, 81, 16));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto Light"));
        font1.setPointSize(10);
        daysUsedTitle->setFont(font1);
        daysUsedTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        daysUsedText = new QLabel(daysUsed);
        daysUsedText->setObjectName(QStringLiteral("daysUsedText"));
        daysUsedText->setGeometry(QRect(112, 0, 91, 35));
        QFont font2;
        font2.setFamily(QStringLiteral("Roboto Thin"));
        font2.setPointSize(20);
        daysUsedText->setFont(font2);
        daysUsedText->setStyleSheet(QStringLiteral("color:#2196F3"));
        daysUsedText->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        daysUsedUnit = new QLabel(daysUsed);
        daysUsedUnit->setObjectName(QStringLiteral("daysUsedUnit"));
        daysUsedUnit->setGeometry(QRect(3, 20, 41, 12));
        QFont font3;
        font3.setFamily(QStringLiteral("Roboto Light"));
        font3.setPointSize(7);
        daysUsedUnit->setFont(font3);
        daysUsedUnit->setStyleSheet(QStringLiteral("color:#616161"));
        daysUsedUnit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        days4HrsPlus = new QFrame(SleepReportMoreWindowBasicBk);
        days4HrsPlus->setObjectName(QStringLiteral("days4HrsPlus"));
        days4HrsPlus->setGeometry(QRect(260, 82, 210, 33));
        days4HrsPlus->setStyleSheet(QLatin1String("background-color:#3D3D3D;\n"
"border-radius:3px;\n"
""));
        days4HrsPlus->setFrameShape(QFrame::StyledPanel);
        days4HrsPlus->setFrameShadow(QFrame::Raised);
        days4HrsPlusTitle = new QLabel(days4HrsPlus);
        days4HrsPlusTitle->setObjectName(QStringLiteral("days4HrsPlusTitle"));
        days4HrsPlusTitle->setGeometry(QRect(3, 2, 81, 16));
        days4HrsPlusTitle->setFont(font1);
        days4HrsPlusTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        days4HrsPlusText = new QLabel(days4HrsPlus);
        days4HrsPlusText->setObjectName(QStringLiteral("days4HrsPlusText"));
        days4HrsPlusText->setGeometry(QRect(112, 0, 91, 35));
        QFont font4;
        font4.setFamily(QStringLiteral("Roboto"));
        font4.setPointSize(20);
        days4HrsPlusText->setFont(font4);
        days4HrsPlusText->setStyleSheet(QStringLiteral("color:#2196F3"));
        days4HrsPlusText->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        days4HrsPlusUnit = new QLabel(days4HrsPlus);
        days4HrsPlusUnit->setObjectName(QStringLiteral("days4HrsPlusUnit"));
        days4HrsPlusUnit->setGeometry(QRect(3, 20, 41, 12));
        days4HrsPlusUnit->setFont(font3);
        days4HrsPlusUnit->setStyleSheet(QStringLiteral("color:#616161"));
        days4HrsPlusUnit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        averageUsage = new QFrame(SleepReportMoreWindowBasicBk);
        averageUsage->setObjectName(QStringLiteral("averageUsage"));
        averageUsage->setGeometry(QRect(260, 119, 210, 33));
        averageUsage->setStyleSheet(QLatin1String("background-color:#3D3D3D;\n"
"border-radius:3px;\n"
""));
        averageUsage->setFrameShape(QFrame::StyledPanel);
        averageUsage->setFrameShadow(QFrame::Raised);
        averageUsageTitle = new QLabel(averageUsage);
        averageUsageTitle->setObjectName(QStringLiteral("averageUsageTitle"));
        averageUsageTitle->setGeometry(QRect(3, 2, 101, 16));
        averageUsageTitle->setFont(font1);
        averageUsageTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        averageUsageText = new QLabel(averageUsage);
        averageUsageText->setObjectName(QStringLiteral("averageUsageText"));
        averageUsageText->setGeometry(QRect(122, 0, 81, 35));
        averageUsageText->setFont(font2);
        averageUsageText->setStyleSheet(QStringLiteral("color:#2196F3"));
        averageUsageText->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        averageUsageUnit = new QLabel(averageUsage);
        averageUsageUnit->setObjectName(QStringLiteral("averageUsageUnit"));
        averageUsageUnit->setGeometry(QRect(3, 20, 41, 12));
        averageUsageUnit->setFont(font3);
        averageUsageUnit->setStyleSheet(QStringLiteral("color:#616161"));
        averageUsageUnit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        usedHours = new QFrame(SleepReportMoreWindowBasicBk);
        usedHours->setObjectName(QStringLiteral("usedHours"));
        usedHours->setGeometry(QRect(260, 156, 210, 33));
        usedHours->setStyleSheet(QLatin1String("background-color:#3D3D3D;\n"
"border-radius:3px;\n"
""));
        usedHours->setFrameShape(QFrame::StyledPanel);
        usedHours->setFrameShadow(QFrame::Raised);
        usedHoursTitle = new QLabel(usedHours);
        usedHoursTitle->setObjectName(QStringLiteral("usedHoursTitle"));
        usedHoursTitle->setGeometry(QRect(3, 2, 81, 16));
        usedHoursTitle->setFont(font1);
        usedHoursTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        usedHoursText = new QLabel(usedHours);
        usedHoursText->setObjectName(QStringLiteral("usedHoursText"));
        usedHoursText->setGeometry(QRect(112, 0, 91, 35));
        usedHoursText->setFont(font2);
        usedHoursText->setStyleSheet(QStringLiteral("color:#2196F3"));
        usedHoursText->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        usedHoursUnit = new QLabel(usedHours);
        usedHoursUnit->setObjectName(QStringLiteral("usedHoursUnit"));
        usedHoursUnit->setGeometry(QRect(3, 20, 41, 12));
        usedHoursUnit->setFont(font3);
        usedHoursUnit->setStyleSheet(QStringLiteral("color:#616161"));
        usedHoursUnit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        leak = new QFrame(SleepReportMoreWindowBasicBk);
        leak->setObjectName(QStringLiteral("leak"));
        leak->setGeometry(QRect(260, 193, 210, 33));
        leak->setStyleSheet(QLatin1String("background-color:#3D3D3D;\n"
"border-radius:3px;\n"
""));
        leak->setFrameShape(QFrame::StyledPanel);
        leak->setFrameShadow(QFrame::Raised);
        leakTitle = new QLabel(leak);
        leakTitle->setObjectName(QStringLiteral("leakTitle"));
        leakTitle->setGeometry(QRect(3, 2, 81, 16));
        leakTitle->setFont(font1);
        leakTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        leakText = new QLabel(leak);
        leakText->setObjectName(QStringLiteral("leakText"));
        leakText->setGeometry(QRect(102, 0, 101, 35));
        leakText->setFont(font2);
        leakText->setStyleSheet(QStringLiteral("color:#2196F3"));
        leakText->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        leakUnit = new QLabel(leak);
        leakUnit->setObjectName(QStringLiteral("leakUnit"));
        leakUnit->setGeometry(QRect(3, 20, 41, 12));
        leakUnit->setFont(font3);
        leakUnit->setStyleSheet(QStringLiteral("color:#616161"));
        leakUnit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        ahi = new QFrame(SleepReportMoreWindowBasicBk);
        ahi->setObjectName(QStringLiteral("ahi"));
        ahi->setGeometry(QRect(260, 231, 210, 33));
        ahi->setStyleSheet(QLatin1String("background-color:#3D3D3D;\n"
"border-radius:3px;\n"
""));
        ahi->setFrameShape(QFrame::StyledPanel);
        ahi->setFrameShadow(QFrame::Raised);
        ahiTitle = new QLabel(ahi);
        ahiTitle->setObjectName(QStringLiteral("ahiTitle"));
        ahiTitle->setGeometry(QRect(3, 2, 81, 16));
        ahiTitle->setFont(font1);
        ahiTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        ahiText = new QLabel(ahi);
        ahiText->setObjectName(QStringLiteral("ahiText"));
        ahiText->setGeometry(QRect(32, 0, 171, 35));
        ahiText->setFont(font2);
        ahiText->setStyleSheet(QStringLiteral("color:#2196F3"));
        ahiText->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        selectionPeriod = new QLabel(SleepReportMoreWindowBasicBk);
        selectionPeriod->setObjectName(QStringLiteral("selectionPeriod"));
        selectionPeriod->setGeometry(QRect(40, 74, 41, 21));
        selectionPeriod->setFont(font1);
        selectionPeriod->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        sendSleepReportButton = new QPushButton(SleepReportMoreWindowBasicBk);
        sendSleepReportButton->setObjectName(QStringLiteral("sendSleepReportButton"));
        sendSleepReportButton->setGeometry(QRect(130, 215, 118, 50));
        QFont font5;
        font5.setFamily(QStringLiteral("Roboto"));
        font5.setPointSize(10);
        sendSleepReportButton->setFont(font5);
        sendSleepReportButton->setFocusPolicy(Qt::NoFocus);
        sendSleepReportButton->setStyleSheet(QLatin1String("QPushButton {\n"
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

        retranslateUi(SleepReportMoreWindowBasic);

        QMetaObject::connectSlotsByName(SleepReportMoreWindowBasic);
    } // setupUi

    void retranslateUi(QDialog *SleepReportMoreWindowBasic)
    {
        SleepReportMoreWindowBasic->setWindowTitle(QApplication::translate("SleepReportMoreWindowBasic", "Dialog", nullptr));
        backSleepReportMoreButton->setText(QString());
        sleepReportMoreTitle->setText(QApplication::translate("SleepReportMoreWindowBasic", "Sleep Report", nullptr));
        daysUsedTitle->setText(QApplication::translate("SleepReportMoreWindowBasic", "Days Used", nullptr));
        daysUsedText->setText(QString());
        daysUsedUnit->setText(QApplication::translate("SleepReportMoreWindowBasic", "Period", nullptr));
        days4HrsPlusTitle->setText(QApplication::translate("SleepReportMoreWindowBasic", "Days 4Hrs+", nullptr));
        days4HrsPlusText->setText(QString());
        days4HrsPlusUnit->setText(QApplication::translate("SleepReportMoreWindowBasic", "Period", nullptr));
        averageUsageTitle->setText(QApplication::translate("SleepReportMoreWindowBasic", "Average Usage", nullptr));
        averageUsageText->setText(QString());
        averageUsageUnit->setText(QApplication::translate("SleepReportMoreWindowBasic", "Hours", nullptr));
        usedHoursTitle->setText(QApplication::translate("SleepReportMoreWindowBasic", "Used Hours", nullptr));
        usedHoursText->setText(QString());
        usedHoursUnit->setText(QApplication::translate("SleepReportMoreWindowBasic", "Hours", nullptr));
        leakTitle->setText(QApplication::translate("SleepReportMoreWindowBasic", "Leak", nullptr));
        leakText->setText(QString());
        leakUnit->setText(QApplication::translate("SleepReportMoreWindowBasic", "L/min", nullptr));
        ahiTitle->setText(QApplication::translate("SleepReportMoreWindowBasic", "AHI", nullptr));
        ahiText->setText(QString());
        selectionPeriod->setText(QApplication::translate("SleepReportMoreWindowBasic", "Period", nullptr));
        sendSleepReportButton->setText(QApplication::translate("SleepReportMoreWindowBasic", "Send Sleep Report", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SleepReportMoreWindowBasic: public Ui_SleepReportMoreWindowBasic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLEEPREPORTMOREWINDOWBASIC_H
