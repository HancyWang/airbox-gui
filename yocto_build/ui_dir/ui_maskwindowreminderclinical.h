/********************************************************************************
** Form generated from reading UI file 'maskwindowreminderclinical.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MASKWINDOWREMINDERCLINICAL_H
#define UI_MASKWINDOWREMINDERCLINICAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MaskWindowReminderClinical
{
public:
    QPushButton *maskAccept;
    QLabel *maskDurationUnit;
    QPushButton *maskSetDate;
    QLabel *maskSetDurationTitle;
    QPushButton *maskIncrement;
    QLabel *maskTitle;
    QPushButton *maskCancel;
    QLabel *maskDuration;
    QLabel *maskSetStartDateTitle;
    QPushButton *maskDecrement;
    QFrame *frame;

    void setupUi(QDialog *MaskWindowReminderClinical)
    {
        if (MaskWindowReminderClinical->objectName().isEmpty())
            MaskWindowReminderClinical->setObjectName(QStringLiteral("MaskWindowReminderClinical"));
        MaskWindowReminderClinical->resize(349, 213);
        MaskWindowReminderClinical->setStyleSheet(QStringLiteral(""));
        maskAccept = new QPushButton(MaskWindowReminderClinical);
        maskAccept->setObjectName(QStringLiteral("maskAccept"));
        maskAccept->setGeometry(QRect(3, 170, 170, 40));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(12);
        maskAccept->setFont(font);
        maskAccept->setFocusPolicy(Qt::NoFocus);
        maskAccept->setStyleSheet(QLatin1String("QPushButton {\n"
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
        maskDurationUnit = new QLabel(MaskWindowReminderClinical);
        maskDurationUnit->setObjectName(QStringLiteral("maskDurationUnit"));
        maskDurationUnit->setGeometry(QRect(190, 87, 61, 20));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(11);
        maskDurationUnit->setFont(font1);
        maskDurationUnit->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        maskSetDate = new QPushButton(MaskWindowReminderClinical);
        maskSetDate->setObjectName(QStringLiteral("maskSetDate"));
        maskSetDate->setGeometry(QRect(148, 50, 171, 23));
        QFont font2;
        font2.setFamily(QStringLiteral("Roboto"));
        font2.setPointSize(14);
        maskSetDate->setFont(font2);
        maskSetDate->setFocusPolicy(Qt::NoFocus);
        maskSetDate->setStyleSheet(QLatin1String("QPushButton {\n"
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
        maskSetDurationTitle = new QLabel(MaskWindowReminderClinical);
        maskSetDurationTitle->setObjectName(QStringLiteral("maskSetDurationTitle"));
        maskSetDurationTitle->setGeometry(QRect(23, 84, 91, 18));
        maskSetDurationTitle->setFont(font1);
        maskSetDurationTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        maskIncrement = new QPushButton(MaskWindowReminderClinical);
        maskIncrement->setObjectName(QStringLiteral("maskIncrement"));
        maskIncrement->setGeometry(QRect(259, 81, 66, 33));
        maskIncrement->setFont(font2);
        maskIncrement->setFocusPolicy(Qt::NoFocus);
        maskIncrement->setStyleSheet(QLatin1String("QPushButton {\n"
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
        maskTitle = new QLabel(MaskWindowReminderClinical);
        maskTitle->setObjectName(QStringLiteral("maskTitle"));
        maskTitle->setGeometry(QRect(24, 16, 91, 31));
        maskTitle->setFont(font1);
        maskTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        maskTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        maskCancel = new QPushButton(MaskWindowReminderClinical);
        maskCancel->setObjectName(QStringLiteral("maskCancel"));
        maskCancel->setGeometry(QRect(176, 170, 170, 40));
        maskCancel->setFont(font);
        maskCancel->setFocusPolicy(Qt::NoFocus);
        maskCancel->setStyleSheet(QLatin1String("QPushButton {\n"
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
        maskDuration = new QLabel(MaskWindowReminderClinical);
        maskDuration->setObjectName(QStringLiteral("maskDuration"));
        maskDuration->setGeometry(QRect(138, 79, 41, 29));
        maskDuration->setFont(font1);
        maskDuration->setStyleSheet(QStringLiteral("color:#1788C3"));
        maskSetStartDateTitle = new QLabel(MaskWindowReminderClinical);
        maskSetStartDateTitle->setObjectName(QStringLiteral("maskSetStartDateTitle"));
        maskSetStartDateTitle->setGeometry(QRect(23, 52, 101, 18));
        maskSetStartDateTitle->setFont(font1);
        maskSetStartDateTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        maskDecrement = new QPushButton(MaskWindowReminderClinical);
        maskDecrement->setObjectName(QStringLiteral("maskDecrement"));
        maskDecrement->setGeometry(QRect(259, 119, 66, 33));
        maskDecrement->setFont(font2);
        maskDecrement->setFocusPolicy(Qt::NoFocus);
        maskDecrement->setStyleSheet(QLatin1String("QPushButton {\n"
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
        frame = new QFrame(MaskWindowReminderClinical);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        maskAccept->raise();
        maskDurationUnit->raise();
        maskSetDate->raise();
        maskSetDurationTitle->raise();
        maskIncrement->raise();
        maskTitle->raise();
        maskCancel->raise();
        maskDuration->raise();
        maskSetStartDateTitle->raise();
        maskDecrement->raise();

        retranslateUi(MaskWindowReminderClinical);

        QMetaObject::connectSlotsByName(MaskWindowReminderClinical);
    } // setupUi

    void retranslateUi(QDialog *MaskWindowReminderClinical)
    {
        MaskWindowReminderClinical->setWindowTitle(QApplication::translate("MaskWindowReminderClinical", "Dialog", nullptr));
        maskAccept->setText(QApplication::translate("MaskWindowReminderClinical", "Accept", nullptr));
        maskDurationUnit->setText(QApplication::translate("MaskWindowReminderClinical", "months", nullptr));
        maskSetDate->setText(QApplication::translate("MaskWindowReminderClinical", "12 Oct 2017", nullptr));
        maskSetDurationTitle->setText(QApplication::translate("MaskWindowReminderClinical", "Set Duration", nullptr));
        maskIncrement->setText(QApplication::translate("MaskWindowReminderClinical", "+", nullptr));
        maskTitle->setText(QApplication::translate("MaskWindowReminderClinical", "Mask", nullptr));
        maskCancel->setText(QApplication::translate("MaskWindowReminderClinical", "Cancel", nullptr));
        maskDuration->setText(QApplication::translate("MaskWindowReminderClinical", "3", nullptr));
        maskSetStartDateTitle->setText(QApplication::translate("MaskWindowReminderClinical", "Set Start Date", nullptr));
        maskDecrement->setText(QApplication::translate("MaskWindowReminderClinical", "-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MaskWindowReminderClinical: public Ui_MaskWindowReminderClinical {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MASKWINDOWREMINDERCLINICAL_H
