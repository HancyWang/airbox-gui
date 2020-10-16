/********************************************************************************
** Form generated from reading UI file 'snoozeexitscreenbasic.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNOOZEEXITSCREENBASIC_H
#define UI_SNOOZEEXITSCREENBASIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SnoozeExitScreenBasic
{
public:
    QPushButton *snoozeExitYes;
    QLabel *snoozeExitTitle;
    QPushButton *snoozeExitNo;
    QLabel *snoozeExitWarning;
    QFrame *frame;

    void setupUi(QDialog *SnoozeExitScreenBasic)
    {
        if (SnoozeExitScreenBasic->objectName().isEmpty())
            SnoozeExitScreenBasic->setObjectName(QStringLiteral("SnoozeExitScreenBasic"));
        SnoozeExitScreenBasic->resize(349, 213);
        SnoozeExitScreenBasic->setStyleSheet(QStringLiteral(""));
        snoozeExitYes = new QPushButton(SnoozeExitScreenBasic);
        snoozeExitYes->setObjectName(QStringLiteral("snoozeExitYes"));
        snoozeExitYes->setGeometry(QRect(3, 170, 170, 40));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(12);
        snoozeExitYes->setFont(font);
        snoozeExitYes->setFocusPolicy(Qt::NoFocus);
        snoozeExitYes->setStyleSheet(QLatin1String("QPushButton {\n"
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
        snoozeExitTitle = new QLabel(SnoozeExitScreenBasic);
        snoozeExitTitle->setObjectName(QStringLiteral("snoozeExitTitle"));
        snoozeExitTitle->setGeometry(QRect(24, 16, 161, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(11);
        snoozeExitTitle->setFont(font1);
        snoozeExitTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        snoozeExitNo = new QPushButton(SnoozeExitScreenBasic);
        snoozeExitNo->setObjectName(QStringLiteral("snoozeExitNo"));
        snoozeExitNo->setGeometry(QRect(176, 170, 170, 40));
        snoozeExitNo->setFont(font);
        snoozeExitNo->setFocusPolicy(Qt::NoFocus);
        snoozeExitNo->setStyleSheet(QLatin1String("QPushButton {\n"
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
        snoozeExitWarning = new QLabel(SnoozeExitScreenBasic);
        snoozeExitWarning->setObjectName(QStringLiteral("snoozeExitWarning"));
        snoozeExitWarning->setGeometry(QRect(48, 66, 251, 61));
        snoozeExitWarning->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        snoozeExitWarning->setAlignment(Qt::AlignCenter);
        frame = new QFrame(SnoozeExitScreenBasic);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        snoozeExitYes->raise();
        snoozeExitTitle->raise();
        snoozeExitNo->raise();
        snoozeExitWarning->raise();

        retranslateUi(SnoozeExitScreenBasic);

        QMetaObject::connectSlotsByName(SnoozeExitScreenBasic);
    } // setupUi

    void retranslateUi(QDialog *SnoozeExitScreenBasic)
    {
        SnoozeExitScreenBasic->setWindowTitle(QApplication::translate("SnoozeExitScreenBasic", "Dialog", nullptr));
        snoozeExitYes->setText(QApplication::translate("SnoozeExitScreenBasic", "Yes", nullptr));
        snoozeExitTitle->setText(QApplication::translate("SnoozeExitScreenBasic", "Snooze", nullptr));
        snoozeExitNo->setText(QApplication::translate("SnoozeExitScreenBasic", "No", nullptr));
        snoozeExitWarning->setText(QApplication::translate("SnoozeExitScreenBasic", "Do You really want to Exit \n"
"Snooz?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SnoozeExitScreenBasic: public Ui_SnoozeExitScreenBasic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNOOZEEXITSCREENBASIC_H
