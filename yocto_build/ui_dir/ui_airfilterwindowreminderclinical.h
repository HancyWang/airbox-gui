/********************************************************************************
** Form generated from reading UI file 'airfilterwindowreminderclinical.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIRFILTERWINDOWREMINDERCLINICAL_H
#define UI_AIRFILTERWINDOWREMINDERCLINICAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AirFilterWindowReminderClinical
{
public:
    QPushButton *airFilterAccept;
    QLabel *airFilterTitle;
    QPushButton *airFilterCancel;
    QPushButton *airFilterDecrement;
    QPushButton *airFilterIncrement;
    QLabel *airFilterSetStartDateTitle;
    QLabel *airFilterSetDurationTitle;
    QLabel *airFilterDuration;
    QLabel *airFilterDurationUnit;
    QPushButton *airFilterSetDate;
    QFrame *frame;

    void setupUi(QDialog *AirFilterWindowReminderClinical)
    {
        if (AirFilterWindowReminderClinical->objectName().isEmpty())
            AirFilterWindowReminderClinical->setObjectName(QStringLiteral("AirFilterWindowReminderClinical"));
        AirFilterWindowReminderClinical->resize(349, 213);
        AirFilterWindowReminderClinical->setStyleSheet(QStringLiteral(""));
        airFilterAccept = new QPushButton(AirFilterWindowReminderClinical);
        airFilterAccept->setObjectName(QStringLiteral("airFilterAccept"));
        airFilterAccept->setGeometry(QRect(3, 170, 170, 40));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(12);
        airFilterAccept->setFont(font);
        airFilterAccept->setFocusPolicy(Qt::NoFocus);
        airFilterAccept->setStyleSheet(QLatin1String("QPushButton {\n"
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
        airFilterTitle = new QLabel(AirFilterWindowReminderClinical);
        airFilterTitle->setObjectName(QStringLiteral("airFilterTitle"));
        airFilterTitle->setGeometry(QRect(24, 16, 111, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(11);
        airFilterTitle->setFont(font1);
        airFilterTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        airFilterTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        airFilterCancel = new QPushButton(AirFilterWindowReminderClinical);
        airFilterCancel->setObjectName(QStringLiteral("airFilterCancel"));
        airFilterCancel->setGeometry(QRect(176, 170, 170, 40));
        airFilterCancel->setFont(font);
        airFilterCancel->setFocusPolicy(Qt::NoFocus);
        airFilterCancel->setStyleSheet(QLatin1String("QPushButton {\n"
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
        airFilterDecrement = new QPushButton(AirFilterWindowReminderClinical);
        airFilterDecrement->setObjectName(QStringLiteral("airFilterDecrement"));
        airFilterDecrement->setGeometry(QRect(259, 119, 66, 33));
        QFont font2;
        font2.setFamily(QStringLiteral("Roboto"));
        font2.setPointSize(14);
        airFilterDecrement->setFont(font2);
        airFilterDecrement->setFocusPolicy(Qt::NoFocus);
        airFilterDecrement->setStyleSheet(QLatin1String("QPushButton {\n"
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
        airFilterIncrement = new QPushButton(AirFilterWindowReminderClinical);
        airFilterIncrement->setObjectName(QStringLiteral("airFilterIncrement"));
        airFilterIncrement->setGeometry(QRect(259, 81, 66, 33));
        airFilterIncrement->setFont(font2);
        airFilterIncrement->setFocusPolicy(Qt::NoFocus);
        airFilterIncrement->setStyleSheet(QLatin1String("QPushButton {\n"
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
        airFilterSetStartDateTitle = new QLabel(AirFilterWindowReminderClinical);
        airFilterSetStartDateTitle->setObjectName(QStringLiteral("airFilterSetStartDateTitle"));
        airFilterSetStartDateTitle->setGeometry(QRect(23, 51, 111, 18));
        airFilterSetStartDateTitle->setFont(font1);
        airFilterSetStartDateTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        airFilterSetDurationTitle = new QLabel(AirFilterWindowReminderClinical);
        airFilterSetDurationTitle->setObjectName(QStringLiteral("airFilterSetDurationTitle"));
        airFilterSetDurationTitle->setGeometry(QRect(23, 83, 101, 18));
        airFilterSetDurationTitle->setFont(font1);
        airFilterSetDurationTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        airFilterDuration = new QLabel(AirFilterWindowReminderClinical);
        airFilterDuration->setObjectName(QStringLiteral("airFilterDuration"));
        airFilterDuration->setGeometry(QRect(148, 78, 30, 29));
        airFilterDuration->setFont(font1);
        airFilterDuration->setStyleSheet(QStringLiteral("color:#1788C3"));
        airFilterDurationUnit = new QLabel(AirFilterWindowReminderClinical);
        airFilterDurationUnit->setObjectName(QStringLiteral("airFilterDurationUnit"));
        airFilterDurationUnit->setGeometry(QRect(190, 86, 61, 16));
        airFilterDurationUnit->setFont(font1);
        airFilterDurationUnit->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        airFilterSetDate = new QPushButton(AirFilterWindowReminderClinical);
        airFilterSetDate->setObjectName(QStringLiteral("airFilterSetDate"));
        airFilterSetDate->setGeometry(QRect(148, 49, 171, 23));
        airFilterSetDate->setFont(font2);
        airFilterSetDate->setFocusPolicy(Qt::NoFocus);
        airFilterSetDate->setStyleSheet(QLatin1String("QPushButton {\n"
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
        frame = new QFrame(AirFilterWindowReminderClinical);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        airFilterAccept->raise();
        airFilterTitle->raise();
        airFilterCancel->raise();
        airFilterDecrement->raise();
        airFilterIncrement->raise();
        airFilterSetStartDateTitle->raise();
        airFilterSetDurationTitle->raise();
        airFilterDuration->raise();
        airFilterDurationUnit->raise();
        airFilterSetDate->raise();

        retranslateUi(AirFilterWindowReminderClinical);

        QMetaObject::connectSlotsByName(AirFilterWindowReminderClinical);
    } // setupUi

    void retranslateUi(QDialog *AirFilterWindowReminderClinical)
    {
        AirFilterWindowReminderClinical->setWindowTitle(QApplication::translate("AirFilterWindowReminderClinical", "Dialog", nullptr));
        airFilterAccept->setText(QApplication::translate("AirFilterWindowReminderClinical", "Accept", nullptr));
        airFilterTitle->setText(QApplication::translate("AirFilterWindowReminderClinical", "Air Filter", nullptr));
        airFilterCancel->setText(QApplication::translate("AirFilterWindowReminderClinical", "Cancel", nullptr));
        airFilterDecrement->setText(QApplication::translate("AirFilterWindowReminderClinical", "-", nullptr));
        airFilterIncrement->setText(QApplication::translate("AirFilterWindowReminderClinical", "+", nullptr));
        airFilterSetStartDateTitle->setText(QApplication::translate("AirFilterWindowReminderClinical", "Set Start Date", nullptr));
        airFilterSetDurationTitle->setText(QApplication::translate("AirFilterWindowReminderClinical", "Set Duration", nullptr));
        airFilterDuration->setText(QApplication::translate("AirFilterWindowReminderClinical", "3", nullptr));
        airFilterDurationUnit->setText(QApplication::translate("AirFilterWindowReminderClinical", "Weeks", nullptr));
        airFilterSetDate->setText(QApplication::translate("AirFilterWindowReminderClinical", "12 Oct 2017", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AirFilterWindowReminderClinical: public Ui_AirFilterWindowReminderClinical {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIRFILTERWINDOWREMINDERCLINICAL_H
