/********************************************************************************
** Form generated from reading UI file 'activereminderscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIVEREMINDERSCREEN_H
#define UI_ACTIVEREMINDERSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ActiveReminderScreen
{
public:
    QPushButton *remindLaterButton;
    QLabel *remindersTitle;
    QFrame *frame;
    QLabel *changeWarningText;
    QLabel *airFilterText;
    QLabel *airTubeText;
    QLabel *maskText;
    QPushButton *resetReminderButton;

    void setupUi(QDialog *ActiveReminderScreen)
    {
        if (ActiveReminderScreen->objectName().isEmpty())
            ActiveReminderScreen->setObjectName(QStringLiteral("ActiveReminderScreen"));
        ActiveReminderScreen->resize(349, 213);
        remindLaterButton = new QPushButton(ActiveReminderScreen);
        remindLaterButton->setObjectName(QStringLiteral("remindLaterButton"));
        remindLaterButton->setGeometry(QRect(3, 170, 170, 40));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(12);
        remindLaterButton->setFont(font);
        remindLaterButton->setFocusPolicy(Qt::NoFocus);
        remindLaterButton->setStyleSheet(QLatin1String("QPushButton {\n"
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
        remindersTitle = new QLabel(ActiveReminderScreen);
        remindersTitle->setObjectName(QStringLiteral("remindersTitle"));
        remindersTitle->setGeometry(QRect(24, 16, 161, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(11);
        remindersTitle->setFont(font1);
        remindersTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        frame = new QFrame(ActiveReminderScreen);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        changeWarningText = new QLabel(frame);
        changeWarningText->setObjectName(QStringLiteral("changeWarningText"));
        changeWarningText->setGeometry(QRect(20, 60, 301, 21));
        changeWarningText->setFont(font1);
        changeWarningText->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        airFilterText = new QLabel(frame);
        airFilterText->setObjectName(QStringLiteral("airFilterText"));
        airFilterText->setGeometry(QRect(30, 90, 141, 21));
        airFilterText->setFont(font1);
        airFilterText->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        airTubeText = new QLabel(frame);
        airTubeText->setObjectName(QStringLiteral("airTubeText"));
        airTubeText->setGeometry(QRect(30, 110, 141, 21));
        airTubeText->setFont(font1);
        airTubeText->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        maskText = new QLabel(frame);
        maskText->setObjectName(QStringLiteral("maskText"));
        maskText->setGeometry(QRect(30, 130, 141, 21));
        maskText->setFont(font1);
        maskText->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        resetReminderButton = new QPushButton(ActiveReminderScreen);
        resetReminderButton->setObjectName(QStringLiteral("resetReminderButton"));
        resetReminderButton->setGeometry(QRect(176, 170, 170, 40));
        resetReminderButton->setFont(font);
        resetReminderButton->setFocusPolicy(Qt::NoFocus);
        resetReminderButton->setStyleSheet(QLatin1String("QPushButton {\n"
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
        remindersTitle->raise();
        remindLaterButton->raise();
        resetReminderButton->raise();

        retranslateUi(ActiveReminderScreen);

        QMetaObject::connectSlotsByName(ActiveReminderScreen);
    } // setupUi

    void retranslateUi(QDialog *ActiveReminderScreen)
    {
        ActiveReminderScreen->setWindowTitle(QApplication::translate("ActiveReminderScreen", "Dialog", nullptr));
        remindLaterButton->setText(QApplication::translate("ActiveReminderScreen", "Remind Later", nullptr));
        remindersTitle->setText(QApplication::translate("ActiveReminderScreen", "Reminders", nullptr));
        changeWarningText->setText(QApplication::translate("ActiveReminderScreen", "Please change the following", nullptr));
        airFilterText->setText(QApplication::translate("ActiveReminderScreen", "Air Filter", nullptr));
        airTubeText->setText(QApplication::translate("ActiveReminderScreen", "Hose", nullptr));
        maskText->setText(QApplication::translate("ActiveReminderScreen", "Mask", nullptr));
        resetReminderButton->setText(QApplication::translate("ActiveReminderScreen", "Reset Reminder", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ActiveReminderScreen: public Ui_ActiveReminderScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIVEREMINDERSCREEN_H
