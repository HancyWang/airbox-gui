/********************************************************************************
** Form generated from reading UI file 'sleepreportwindowbasic.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLEEPREPORTWINDOWBASIC_H
#define UI_SLEEPREPORTWINDOWBASIC_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SleepReportWindowBasic
{
public:
    QFrame *SleepReportWindowBasicBk;
    QPushButton *homeSleepReportButton;
    QPushButton *moreSleepReportButton;
    QLabel *sleepReportTitle;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QFrame *lastRecordTime;
    QLabel *lastRecordTimeTitle;
    QLabel *lastRecordTimeText;
    QFrame *usageTime;
    QLabel *usageTimeTitle;
    QLabel *usageTimeIcon;
    QLabel *usageTimeStatus;
    QLabel *usageTimeUnit;
    QFrame *eventsPerHour;
    QLabel *eventsPerHourTitle;
    QLabel *evntsPerHourIcon;
    QLabel *eventPerHourStatus;
    QLabel *eventsPerHourUnit;
    QFrame *maskFit;
    QLabel *maskFitTitle;
    QLabel *maskFitIcon;
    QLabel *mskFitStatus;

    void setupUi(QWidget *SleepReportWindowBasic)
    {
        if (SleepReportWindowBasic->objectName().isEmpty())
            SleepReportWindowBasic->setObjectName(QStringLiteral("SleepReportWindowBasic"));
        SleepReportWindowBasic->resize(480, 272);
        SleepReportWindowBasicBk = new QFrame(SleepReportWindowBasic);
        SleepReportWindowBasicBk->setObjectName(QStringLiteral("SleepReportWindowBasicBk"));
        SleepReportWindowBasicBk->setGeometry(QRect(0, 0, 480, 272));
        SleepReportWindowBasicBk->setMaximumSize(QSize(480, 272));
        SleepReportWindowBasicBk->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
""));
        SleepReportWindowBasicBk->setFrameShape(QFrame::StyledPanel);
        SleepReportWindowBasicBk->setFrameShadow(QFrame::Raised);
        homeSleepReportButton = new QPushButton(SleepReportWindowBasicBk);
        homeSleepReportButton->setObjectName(QStringLiteral("homeSleepReportButton"));
        homeSleepReportButton->setGeometry(QRect(9, 24, 38, 30));
        homeSleepReportButton->setFocusPolicy(Qt::NoFocus);
        homeSleepReportButton->setStyleSheet(QLatin1String("border:none;\n"
"border-radius:3px;\n"
"background-color: rgb(70, 70, 73);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/home.png"), QSize(), QIcon::Normal, QIcon::Off);
        homeSleepReportButton->setIcon(icon);
        moreSleepReportButton = new QPushButton(SleepReportWindowBasicBk);
        moreSleepReportButton->setObjectName(QStringLiteral("moreSleepReportButton"));
        moreSleepReportButton->setGeometry(QRect(433, 24, 38, 30));
        moreSleepReportButton->setFocusPolicy(Qt::NoFocus);
        moreSleepReportButton->setStyleSheet(QLatin1String("border:none;\n"
"border-radius:3px;\n"
"background-color: rgb(70, 70, 73);"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        moreSleepReportButton->setIcon(icon1);
        sleepReportTitle = new QLabel(SleepReportWindowBasicBk);
        sleepReportTitle->setObjectName(QStringLiteral("sleepReportTitle"));
        sleepReportTitle->setGeometry(QRect(60, 24, 161, 30));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(14);
        sleepReportTitle->setFont(font);
        sleepReportTitle->setStyleSheet(QLatin1String("color:#1788c3\n"
""));
        layoutWidget = new QWidget(SleepReportWindowBasicBk);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 60, 391, 211));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lastRecordTime = new QFrame(layoutWidget);
        lastRecordTime->setObjectName(QStringLiteral("lastRecordTime"));
        lastRecordTime->setStyleSheet(QLatin1String("background-color:#3D3D3D;\n"
"border-radius:3px;\n"
""));
        lastRecordTime->setFrameShape(QFrame::StyledPanel);
        lastRecordTime->setFrameShadow(QFrame::Raised);
        lastRecordTimeTitle = new QLabel(lastRecordTime);
        lastRecordTimeTitle->setObjectName(QStringLiteral("lastRecordTimeTitle"));
        lastRecordTimeTitle->setGeometry(QRect(6, 4, 151, 18));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(10);
        lastRecordTimeTitle->setFont(font1);
        lastRecordTimeTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        lastRecordTimeText = new QLabel(lastRecordTime);
        lastRecordTimeText->setObjectName(QStringLiteral("lastRecordTimeText"));
        lastRecordTimeText->setGeometry(QRect(20, 20, 361, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Roboto"));
        font2.setPointSize(12);
        lastRecordTimeText->setFont(font2);
        lastRecordTimeText->setStyleSheet(QStringLiteral("color:#2196F3"));
        lastRecordTimeText->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(lastRecordTime);

        usageTime = new QFrame(layoutWidget);
        usageTime->setObjectName(QStringLiteral("usageTime"));
        usageTime->setStyleSheet(QLatin1String("background-color:#3D3D3D;\n"
"border-radius:3px;\n"
""));
        usageTime->setFrameShape(QFrame::StyledPanel);
        usageTime->setFrameShadow(QFrame::Raised);
        usageTimeTitle = new QLabel(usageTime);
        usageTimeTitle->setObjectName(QStringLiteral("usageTimeTitle"));
        usageTimeTitle->setGeometry(QRect(6, 4, 211, 16));
        usageTimeTitle->setFont(font1);
        usageTimeTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        usageTimeIcon = new QLabel(usageTime);
        usageTimeIcon->setObjectName(QStringLiteral("usageTimeIcon"));
        usageTimeIcon->setGeometry(QRect(20, 19, 28, 31));
        usageTimeIcon->setStyleSheet(QStringLiteral(""));
        usageTimeIcon->setPixmap(QPixmap(QString::fromUtf8(":/icons/usage_time.png")));
        usageTimeStatus = new QLabel(usageTime);
        usageTimeStatus->setObjectName(QStringLiteral("usageTimeStatus"));
        usageTimeStatus->setGeometry(QRect(280, 0, 35, 47));
        QFont font3;
        font3.setFamily(QStringLiteral("Roboto"));
        font3.setPointSize(24);
        usageTimeStatus->setFont(font3);
        usageTimeStatus->setStyleSheet(QLatin1String("color:#2196F3;\n"
""));
        usageTimeStatus->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        usageTimeUnit = new QLabel(usageTime);
        usageTimeUnit->setObjectName(QStringLiteral("usageTimeUnit"));
        usageTimeUnit->setGeometry(QRect(310, 30, 71, 21));
        QFont font4;
        font4.setFamily(QStringLiteral("Roboto"));
        font4.setPointSize(9);
        usageTimeUnit->setFont(font4);
        usageTimeUnit->setStyleSheet(QStringLiteral("color:#2196F3"));
        usageTimeUnit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(usageTime);

        eventsPerHour = new QFrame(layoutWidget);
        eventsPerHour->setObjectName(QStringLiteral("eventsPerHour"));
        eventsPerHour->setStyleSheet(QLatin1String("background-color:#3D3D3D;\n"
"border-radius:3px;\n"
""));
        eventsPerHour->setFrameShape(QFrame::StyledPanel);
        eventsPerHour->setFrameShadow(QFrame::Raised);
        eventsPerHourTitle = new QLabel(eventsPerHour);
        eventsPerHourTitle->setObjectName(QStringLiteral("eventsPerHourTitle"));
        eventsPerHourTitle->setGeometry(QRect(6, 4, 201, 18));
        eventsPerHourTitle->setFont(font1);
        eventsPerHourTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        evntsPerHourIcon = new QLabel(eventsPerHour);
        evntsPerHourIcon->setObjectName(QStringLiteral("evntsPerHourIcon"));
        evntsPerHourIcon->setGeometry(QRect(20, 20, 28, 28));
        evntsPerHourIcon->setStyleSheet(QStringLiteral(""));
        evntsPerHourIcon->setPixmap(QPixmap(QString::fromUtf8(":/icons/reminders.png")));
        eventPerHourStatus = new QLabel(eventsPerHour);
        eventPerHourStatus->setObjectName(QStringLiteral("eventPerHourStatus"));
        eventPerHourStatus->setGeometry(QRect(280, 0, 35, 47));
        QFont font5;
        font5.setFamily(QStringLiteral("Roboto"));
        font5.setPointSize(23);
        eventPerHourStatus->setFont(font5);
        eventPerHourStatus->setStyleSheet(QLatin1String("color:#2196F3;\n"
""));
        eventPerHourStatus->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        eventsPerHourUnit = new QLabel(eventsPerHour);
        eventsPerHourUnit->setObjectName(QStringLiteral("eventsPerHourUnit"));
        eventsPerHourUnit->setGeometry(QRect(310, 30, 71, 21));
        eventsPerHourUnit->setFont(font4);
        eventsPerHourUnit->setStyleSheet(QStringLiteral("color:#2196F3"));
        eventsPerHourUnit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(eventsPerHour);

        maskFit = new QFrame(layoutWidget);
        maskFit->setObjectName(QStringLiteral("maskFit"));
        maskFit->setStyleSheet(QLatin1String("background-color:#3D3D3D;\n"
"border-radius:3px;\n"
""));
        maskFit->setFrameShape(QFrame::StyledPanel);
        maskFit->setFrameShadow(QFrame::Raised);
        maskFitTitle = new QLabel(maskFit);
        maskFitTitle->setObjectName(QStringLiteral("maskFitTitle"));
        maskFitTitle->setGeometry(QRect(6, 4, 111, 18));
        maskFitTitle->setFont(font1);
        maskFitTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        maskFitIcon = new QLabel(maskFit);
        maskFitIcon->setObjectName(QStringLiteral("maskFitIcon"));
        maskFitIcon->setGeometry(QRect(20, 20, 28, 28));
        maskFitIcon->setPixmap(QPixmap(QString::fromUtf8(":/icons/mask_fit.png")));
        mskFitStatus = new QLabel(maskFit);
        mskFitStatus->setObjectName(QStringLiteral("mskFitStatus"));
        mskFitStatus->setGeometry(QRect(280, 0, 35, 47));
        mskFitStatus->setStyleSheet(QStringLiteral(""));
        mskFitStatus->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(maskFit);


        retranslateUi(SleepReportWindowBasic);

        QMetaObject::connectSlotsByName(SleepReportWindowBasic);
    } // setupUi

    void retranslateUi(QWidget *SleepReportWindowBasic)
    {
        SleepReportWindowBasic->setWindowTitle(QApplication::translate("SleepReportWindowBasic", "Form", nullptr));
        homeSleepReportButton->setText(QString());
        moreSleepReportButton->setText(QString());
        sleepReportTitle->setText(QApplication::translate("SleepReportWindowBasic", "Sleep Report", nullptr));
        lastRecordTimeTitle->setText(QApplication::translate("SleepReportWindowBasic", "Last Recorded Therapy", nullptr));
        lastRecordTimeText->setText(QApplication::translate("SleepReportWindowBasic", "Wednesday,December 6", nullptr));
        usageTimeTitle->setText(QApplication::translate("SleepReportWindowBasic", "Usage Hours", nullptr));
        usageTimeIcon->setText(QString());
        usageTimeStatus->setText(QString());
        usageTimeUnit->setText(QApplication::translate("SleepReportWindowBasic", "2.00-3.99", nullptr));
        eventsPerHourTitle->setText(QApplication::translate("SleepReportWindowBasic", "Events ( A H I ) Per Hour", nullptr));
        evntsPerHourIcon->setText(QString());
        eventPerHourStatus->setText(QString());
        eventsPerHourUnit->setText(QApplication::translate("SleepReportWindowBasic", "10-19.99", nullptr));
        maskFitTitle->setText(QApplication::translate("SleepReportWindowBasic", "Mask Fit", nullptr));
        maskFitIcon->setText(QString());
        mskFitStatus->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SleepReportWindowBasic: public Ui_SleepReportWindowBasic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLEEPREPORTWINDOWBASIC_H
