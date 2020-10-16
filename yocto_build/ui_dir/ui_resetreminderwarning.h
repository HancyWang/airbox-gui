/********************************************************************************
** Form generated from reading UI file 'resetreminderwarning.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESETREMINDERWARNING_H
#define UI_RESETREMINDERWARNING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ResetReminderWarning
{
public:
    QFrame *frame;
    QLabel *resetWarningText;
    QLabel *airFilterText;
    QLabel *airTubeText;
    QLabel *maskText;
    QPushButton *noButton;
    QPushButton *yesButton;
    QLabel *resetRemindersTitle;

    void setupUi(QDialog *ResetReminderWarning)
    {
        if (ResetReminderWarning->objectName().isEmpty())
            ResetReminderWarning->setObjectName(QStringLiteral("ResetReminderWarning"));
        ResetReminderWarning->resize(349, 213);
        frame = new QFrame(ResetReminderWarning);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        resetWarningText = new QLabel(frame);
        resetWarningText->setObjectName(QStringLiteral("resetWarningText"));
        resetWarningText->setGeometry(QRect(20, 60, 301, 21));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(11);
        resetWarningText->setFont(font);
        resetWarningText->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        airFilterText = new QLabel(frame);
        airFilterText->setObjectName(QStringLiteral("airFilterText"));
        airFilterText->setGeometry(QRect(30, 90, 141, 21));
        airFilterText->setFont(font);
        airFilterText->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        airTubeText = new QLabel(frame);
        airTubeText->setObjectName(QStringLiteral("airTubeText"));
        airTubeText->setGeometry(QRect(30, 110, 141, 21));
        airTubeText->setFont(font);
        airTubeText->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        maskText = new QLabel(frame);
        maskText->setObjectName(QStringLiteral("maskText"));
        maskText->setGeometry(QRect(30, 130, 141, 21));
        maskText->setFont(font);
        maskText->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        noButton = new QPushButton(frame);
        noButton->setObjectName(QStringLiteral("noButton"));
        noButton->setGeometry(QRect(176, 170, 170, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(12);
        noButton->setFont(font1);
        noButton->setFocusPolicy(Qt::NoFocus);
        noButton->setStyleSheet(QLatin1String("QPushButton {\n"
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
        yesButton = new QPushButton(frame);
        yesButton->setObjectName(QStringLiteral("yesButton"));
        yesButton->setGeometry(QRect(3, 170, 170, 40));
        yesButton->setFont(font1);
        yesButton->setFocusPolicy(Qt::NoFocus);
        yesButton->setStyleSheet(QLatin1String("QPushButton {\n"
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
        resetRemindersTitle = new QLabel(ResetReminderWarning);
        resetRemindersTitle->setObjectName(QStringLiteral("resetRemindersTitle"));
        resetRemindersTitle->setGeometry(QRect(44, 26, 161, 31));
        resetRemindersTitle->setFont(font);
        resetRemindersTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));

        retranslateUi(ResetReminderWarning);

        QMetaObject::connectSlotsByName(ResetReminderWarning);
    } // setupUi

    void retranslateUi(QDialog *ResetReminderWarning)
    {
        ResetReminderWarning->setWindowTitle(QApplication::translate("ResetReminderWarning", "Dialog", nullptr));
        resetWarningText->setText(QApplication::translate("ResetReminderWarning", "Do you want to reset reminders", nullptr));
        airFilterText->setText(QApplication::translate("ResetReminderWarning", "Air Filter", nullptr));
        airTubeText->setText(QApplication::translate("ResetReminderWarning", "Hose", nullptr));
        maskText->setText(QApplication::translate("ResetReminderWarning", "Mask", nullptr));
        noButton->setText(QApplication::translate("ResetReminderWarning", "No", nullptr));
        yesButton->setText(QApplication::translate("ResetReminderWarning", "Yes", nullptr));
        resetRemindersTitle->setText(QApplication::translate("ResetReminderWarning", "Reset Reminders", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResetReminderWarning: public Ui_ResetReminderWarning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESETREMINDERWARNING_H
