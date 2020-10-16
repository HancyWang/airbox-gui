/********************************************************************************
** Form generated from reading UI file 'maskfittestoptionsbasic.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MASKFITTESTOPTIONSBASIC_H
#define UI_MASKFITTESTOPTIONSBASIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MaskFitTestOptionsBasic
{
public:
    QLabel *maskFitTestTitle;
    QPushButton *maskFitTestCancel;
    QPushButton *maskFitTestStartStop;
    QProgressBar *maskFitTestProgressBar;
    QFrame *frame;

    void setupUi(QDialog *MaskFitTestOptionsBasic)
    {
        if (MaskFitTestOptionsBasic->objectName().isEmpty())
            MaskFitTestOptionsBasic->setObjectName(QStringLiteral("MaskFitTestOptionsBasic"));
        MaskFitTestOptionsBasic->resize(349, 213);
        MaskFitTestOptionsBasic->setStyleSheet(QStringLiteral(""));
        maskFitTestTitle = new QLabel(MaskFitTestOptionsBasic);
        maskFitTestTitle->setObjectName(QStringLiteral("maskFitTestTitle"));
        maskFitTestTitle->setGeometry(QRect(24, 16, 161, 31));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(11);
        maskFitTestTitle->setFont(font);
        maskFitTestTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        maskFitTestCancel = new QPushButton(MaskFitTestOptionsBasic);
        maskFitTestCancel->setObjectName(QStringLiteral("maskFitTestCancel"));
        maskFitTestCancel->setGeometry(QRect(3, 170, 343, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(12);
        maskFitTestCancel->setFont(font1);
        maskFitTestCancel->setFocusPolicy(Qt::NoFocus);
        maskFitTestCancel->setStyleSheet(QLatin1String("QPushButton {\n"
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
        maskFitTestStartStop = new QPushButton(MaskFitTestOptionsBasic);
        maskFitTestStartStop->setObjectName(QStringLiteral("maskFitTestStartStop"));
        maskFitTestStartStop->setGeometry(QRect(96, 103, 158, 40));
        maskFitTestStartStop->setFont(font1);
        maskFitTestStartStop->setFocusPolicy(Qt::NoFocus);
        maskFitTestStartStop->setStyleSheet(QLatin1String("QPushButton {\n"
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
        maskFitTestProgressBar = new QProgressBar(MaskFitTestOptionsBasic);
        maskFitTestProgressBar->setObjectName(QStringLiteral("maskFitTestProgressBar"));
        maskFitTestProgressBar->setGeometry(QRect(57, 65, 244, 23));
        maskFitTestProgressBar->setStyleSheet(QLatin1String("QProgressBar {\n"
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
        maskFitTestProgressBar->setValue(0);
        maskFitTestProgressBar->setTextVisible(true);
        frame = new QFrame(MaskFitTestOptionsBasic);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        maskFitTestTitle->raise();
        maskFitTestCancel->raise();
        maskFitTestStartStop->raise();
        maskFitTestProgressBar->raise();

        retranslateUi(MaskFitTestOptionsBasic);

        QMetaObject::connectSlotsByName(MaskFitTestOptionsBasic);
    } // setupUi

    void retranslateUi(QDialog *MaskFitTestOptionsBasic)
    {
        MaskFitTestOptionsBasic->setWindowTitle(QApplication::translate("MaskFitTestOptionsBasic", "Dialog", nullptr));
        maskFitTestTitle->setText(QApplication::translate("MaskFitTestOptionsBasic", "Mask Fit Test", nullptr));
        maskFitTestCancel->setText(QApplication::translate("MaskFitTestOptionsBasic", "Exit", nullptr));
        maskFitTestStartStop->setText(QApplication::translate("MaskFitTestOptionsBasic", "Start Test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MaskFitTestOptionsBasic: public Ui_MaskFitTestOptionsBasic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MASKFITTESTOPTIONSBASIC_H
