/********************************************************************************
** Form generated from reading UI file 'airtubewindowreminderclinical.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIRTUBEWINDOWREMINDERCLINICAL_H
#define UI_AIRTUBEWINDOWREMINDERCLINICAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AirTubeWindowReminderClinical
{
public:
    QLabel *airTubeDurationUnit;
    QPushButton *airTubeDecrement;
    QLabel *airTubeSetDurationTitle;
    QLabel *airTubeDuration;
    QLabel *airTubeSetStartDateTitle;
    QPushButton *airTubeAccept;
    QPushButton *airTubeIncrement;
    QPushButton *airTubeCancel;
    QLabel *airTubeTitle;
    QPushButton *airTubeSetDate;
    QFrame *frame;

    void setupUi(QDialog *AirTubeWindowReminderClinical)
    {
        if (AirTubeWindowReminderClinical->objectName().isEmpty())
            AirTubeWindowReminderClinical->setObjectName(QStringLiteral("AirTubeWindowReminderClinical"));
        AirTubeWindowReminderClinical->resize(349, 213);
        AirTubeWindowReminderClinical->setStyleSheet(QStringLiteral(""));
        airTubeDurationUnit = new QLabel(AirTubeWindowReminderClinical);
        airTubeDurationUnit->setObjectName(QStringLiteral("airTubeDurationUnit"));
        airTubeDurationUnit->setGeometry(QRect(190, 87, 61, 20));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(11);
        airTubeDurationUnit->setFont(font);
        airTubeDurationUnit->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        airTubeDecrement = new QPushButton(AirTubeWindowReminderClinical);
        airTubeDecrement->setObjectName(QStringLiteral("airTubeDecrement"));
        airTubeDecrement->setGeometry(QRect(259, 120, 66, 33));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(14);
        airTubeDecrement->setFont(font1);
        airTubeDecrement->setFocusPolicy(Qt::NoFocus);
        airTubeDecrement->setStyleSheet(QLatin1String("QPushButton {\n"
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
        airTubeSetDurationTitle = new QLabel(AirTubeWindowReminderClinical);
        airTubeSetDurationTitle->setObjectName(QStringLiteral("airTubeSetDurationTitle"));
        airTubeSetDurationTitle->setGeometry(QRect(25, 84, 101, 18));
        airTubeSetDurationTitle->setFont(font);
        airTubeSetDurationTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        airTubeDuration = new QLabel(AirTubeWindowReminderClinical);
        airTubeDuration->setObjectName(QStringLiteral("airTubeDuration"));
        airTubeDuration->setGeometry(QRect(150, 79, 31, 29));
        airTubeDuration->setFont(font);
        airTubeDuration->setStyleSheet(QStringLiteral("color:#1788C3"));
        airTubeSetStartDateTitle = new QLabel(AirTubeWindowReminderClinical);
        airTubeSetStartDateTitle->setObjectName(QStringLiteral("airTubeSetStartDateTitle"));
        airTubeSetStartDateTitle->setGeometry(QRect(25, 52, 111, 18));
        airTubeSetStartDateTitle->setFont(font);
        airTubeSetStartDateTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        airTubeAccept = new QPushButton(AirTubeWindowReminderClinical);
        airTubeAccept->setObjectName(QStringLiteral("airTubeAccept"));
        airTubeAccept->setGeometry(QRect(3, 170, 170, 40));
        QFont font2;
        font2.setFamily(QStringLiteral("Roboto"));
        font2.setPointSize(12);
        airTubeAccept->setFont(font2);
        airTubeAccept->setFocusPolicy(Qt::NoFocus);
        airTubeAccept->setStyleSheet(QLatin1String("QPushButton {\n"
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
        airTubeIncrement = new QPushButton(AirTubeWindowReminderClinical);
        airTubeIncrement->setObjectName(QStringLiteral("airTubeIncrement"));
        airTubeIncrement->setGeometry(QRect(259, 82, 66, 33));
        airTubeIncrement->setFont(font1);
        airTubeIncrement->setFocusPolicy(Qt::NoFocus);
        airTubeIncrement->setStyleSheet(QLatin1String("QPushButton {\n"
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
        airTubeCancel = new QPushButton(AirTubeWindowReminderClinical);
        airTubeCancel->setObjectName(QStringLiteral("airTubeCancel"));
        airTubeCancel->setGeometry(QRect(176, 170, 170, 40));
        airTubeCancel->setFont(font2);
        airTubeCancel->setFocusPolicy(Qt::NoFocus);
        airTubeCancel->setStyleSheet(QLatin1String("QPushButton {\n"
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
        airTubeTitle = new QLabel(AirTubeWindowReminderClinical);
        airTubeTitle->setObjectName(QStringLiteral("airTubeTitle"));
        airTubeTitle->setGeometry(QRect(24, 16, 101, 31));
        airTubeTitle->setFont(font);
        airTubeTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        airTubeTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        airTubeSetDate = new QPushButton(AirTubeWindowReminderClinical);
        airTubeSetDate->setObjectName(QStringLiteral("airTubeSetDate"));
        airTubeSetDate->setGeometry(QRect(150, 50, 171, 23));
        airTubeSetDate->setFont(font1);
        airTubeSetDate->setFocusPolicy(Qt::NoFocus);
        airTubeSetDate->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color:#3B3B3B;\n"
"color:#1788C3;\n"
"border:none;\n"
"border-radius:3px;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color:#606060;\n"
"color:#1788C3;\n"
"border:none;\n"
"border-radius:3px;\n"
"}\n"
""));
        frame = new QFrame(AirTubeWindowReminderClinical);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        airTubeDurationUnit->raise();
        airTubeDecrement->raise();
        airTubeSetDurationTitle->raise();
        airTubeDuration->raise();
        airTubeSetStartDateTitle->raise();
        airTubeAccept->raise();
        airTubeIncrement->raise();
        airTubeCancel->raise();
        airTubeTitle->raise();
        airTubeSetDate->raise();

        retranslateUi(AirTubeWindowReminderClinical);

        QMetaObject::connectSlotsByName(AirTubeWindowReminderClinical);
    } // setupUi

    void retranslateUi(QDialog *AirTubeWindowReminderClinical)
    {
        AirTubeWindowReminderClinical->setWindowTitle(QApplication::translate("AirTubeWindowReminderClinical", "Dialog", nullptr));
        airTubeDurationUnit->setText(QApplication::translate("AirTubeWindowReminderClinical", "months", nullptr));
        airTubeDecrement->setText(QApplication::translate("AirTubeWindowReminderClinical", "-", nullptr));
        airTubeSetDurationTitle->setText(QApplication::translate("AirTubeWindowReminderClinical", "Set Duration", nullptr));
        airTubeDuration->setText(QApplication::translate("AirTubeWindowReminderClinical", "3", nullptr));
        airTubeSetStartDateTitle->setText(QApplication::translate("AirTubeWindowReminderClinical", "Set Start Date", nullptr));
        airTubeAccept->setText(QApplication::translate("AirTubeWindowReminderClinical", "Accept", nullptr));
        airTubeIncrement->setText(QApplication::translate("AirTubeWindowReminderClinical", "+", nullptr));
        airTubeCancel->setText(QApplication::translate("AirTubeWindowReminderClinical", "Cancel", nullptr));
        airTubeTitle->setText(QApplication::translate("AirTubeWindowReminderClinical", "Hose", nullptr));
        airTubeSetDate->setText(QApplication::translate("AirTubeWindowReminderClinical", "12 Oct 2017", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AirTubeWindowReminderClinical: public Ui_AirTubeWindowReminderClinical {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIRTUBEWINDOWREMINDERCLINICAL_H
