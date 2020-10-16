/********************************************************************************
** Form generated from reading UI file 'timewindowclinical.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMEWINDOWCLINICAL_H
#define UI_TIMEWINDOWCLINICAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TimeWindowClinical
{
public:
    QPushButton *timeAccept;
    QPushButton *timeCancel;
    QLabel *timeTitle;
    QFrame *frame;
    QWidget *gridLayoutWidget;
    QGridLayout *timeLayout;

    void setupUi(QDialog *TimeWindowClinical)
    {
        if (TimeWindowClinical->objectName().isEmpty())
            TimeWindowClinical->setObjectName(QStringLiteral("TimeWindowClinical"));
        TimeWindowClinical->resize(349, 213);
        TimeWindowClinical->setStyleSheet(QStringLiteral(""));
        timeAccept = new QPushButton(TimeWindowClinical);
        timeAccept->setObjectName(QStringLiteral("timeAccept"));
        timeAccept->setGeometry(QRect(3, 170, 170, 40));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(12);
        timeAccept->setFont(font);
        timeAccept->setFocusPolicy(Qt::NoFocus);
        timeAccept->setStyleSheet(QLatin1String("QPushButton {\n"
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
        timeCancel = new QPushButton(TimeWindowClinical);
        timeCancel->setObjectName(QStringLiteral("timeCancel"));
        timeCancel->setGeometry(QRect(176, 170, 170, 40));
        timeCancel->setFont(font);
        timeCancel->setFocusPolicy(Qt::NoFocus);
        timeCancel->setStyleSheet(QLatin1String("QPushButton {\n"
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
        timeTitle = new QLabel(TimeWindowClinical);
        timeTitle->setObjectName(QStringLiteral("timeTitle"));
        timeTitle->setGeometry(QRect(24, 16, 161, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(11);
        timeTitle->setFont(font1);
        timeTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        frame = new QFrame(TimeWindowClinical);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayoutWidget = new QWidget(TimeWindowClinical);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(40, 50, 271, 101));
        timeLayout = new QGridLayout(gridLayoutWidget);
        timeLayout->setSpacing(0);
        timeLayout->setObjectName(QStringLiteral("timeLayout"));
        timeLayout->setContentsMargins(0, 0, 0, 0);
        frame->raise();
        timeAccept->raise();
        timeCancel->raise();
        timeTitle->raise();
        gridLayoutWidget->raise();

        retranslateUi(TimeWindowClinical);

        QMetaObject::connectSlotsByName(TimeWindowClinical);
    } // setupUi

    void retranslateUi(QDialog *TimeWindowClinical)
    {
        TimeWindowClinical->setWindowTitle(QApplication::translate("TimeWindowClinical", "Dialog", nullptr));
        timeAccept->setText(QApplication::translate("TimeWindowClinical", "Accept", nullptr));
        timeCancel->setText(QApplication::translate("TimeWindowClinical", "Cancel", nullptr));
        timeTitle->setText(QApplication::translate("TimeWindowClinical", "Time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TimeWindowClinical: public Ui_TimeWindowClinical {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMEWINDOWCLINICAL_H
