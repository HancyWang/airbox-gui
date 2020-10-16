/********************************************************************************
** Form generated from reading UI file 'maskdryoptionsbasic.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MASKDRYOPTIONSBASIC_H
#define UI_MASKDRYOPTIONSBASIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MaskDryOptionsBasic
{
public:
    QLabel *maskDryTitle;
    QPushButton *maskDryCancel;
    QPushButton *maskDryTestStartStop;
    QWidget *spinnerParent;
    QFrame *frame;
    QProgressBar *maskDryProgressBar;

    void setupUi(QDialog *MaskDryOptionsBasic)
    {
        if (MaskDryOptionsBasic->objectName().isEmpty())
            MaskDryOptionsBasic->setObjectName(QStringLiteral("MaskDryOptionsBasic"));
        MaskDryOptionsBasic->resize(349, 213);
        MaskDryOptionsBasic->setStyleSheet(QStringLiteral(""));
        maskDryTitle = new QLabel(MaskDryOptionsBasic);
        maskDryTitle->setObjectName(QStringLiteral("maskDryTitle"));
        maskDryTitle->setGeometry(QRect(24, 16, 161, 31));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(11);
        maskDryTitle->setFont(font);
        maskDryTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        maskDryCancel = new QPushButton(MaskDryOptionsBasic);
        maskDryCancel->setObjectName(QStringLiteral("maskDryCancel"));
        maskDryCancel->setGeometry(QRect(3, 170, 343, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(12);
        maskDryCancel->setFont(font1);
        maskDryCancel->setFocusPolicy(Qt::NoFocus);
        maskDryCancel->setStyleSheet(QLatin1String("QPushButton {\n"
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
        maskDryTestStartStop = new QPushButton(MaskDryOptionsBasic);
        maskDryTestStartStop->setObjectName(QStringLiteral("maskDryTestStartStop"));
        maskDryTestStartStop->setGeometry(QRect(96, 103, 158, 40));
        maskDryTestStartStop->setFont(font1);
        maskDryTestStartStop->setFocusPolicy(Qt::NoFocus);
        maskDryTestStartStop->setStyleSheet(QLatin1String("QPushButton {\n"
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
        spinnerParent = new QWidget(MaskDryOptionsBasic);
        spinnerParent->setObjectName(QStringLiteral("spinnerParent"));
        spinnerParent->setGeometry(QRect(145, 30, 60, 60));
        frame = new QFrame(MaskDryOptionsBasic);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        maskDryProgressBar = new QProgressBar(MaskDryOptionsBasic);
        maskDryProgressBar->setObjectName(QStringLiteral("maskDryProgressBar"));
        maskDryProgressBar->setGeometry(QRect(57, 65, 244, 23));
        maskDryProgressBar->setStyleSheet(QLatin1String("QProgressBar {\n"
"    border: 1px solid grey;\n"
"    border-radius: 5px;\n"
"    text-align: centre;\n"
"}\n"
"QProgressBar::chunk {\n"
"    background-color: #1788c3;\n"
"    width: 20px;\n"
"    text-align: centre;\n"
"}\n"
""));
        maskDryProgressBar->setValue(0);
        maskDryProgressBar->setTextVisible(true);
        frame->raise();
        maskDryTitle->raise();
        maskDryCancel->raise();
        maskDryTestStartStop->raise();
        spinnerParent->raise();
        maskDryProgressBar->raise();

        retranslateUi(MaskDryOptionsBasic);

        QMetaObject::connectSlotsByName(MaskDryOptionsBasic);
    } // setupUi

    void retranslateUi(QDialog *MaskDryOptionsBasic)
    {
        MaskDryOptionsBasic->setWindowTitle(QApplication::translate("MaskDryOptionsBasic", "Dialog", nullptr));
        maskDryTitle->setText(QApplication::translate("MaskDryOptionsBasic", "Mask Dry", nullptr));
        maskDryCancel->setText(QApplication::translate("MaskDryOptionsBasic", "Exit", nullptr));
        maskDryTestStartStop->setText(QApplication::translate("MaskDryOptionsBasic", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MaskDryOptionsBasic: public Ui_MaskDryOptionsBasic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MASKDRYOPTIONSBASIC_H
