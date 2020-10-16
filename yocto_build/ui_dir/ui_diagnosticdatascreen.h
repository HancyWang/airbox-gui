/********************************************************************************
** Form generated from reading UI file 'diagnosticdatascreen.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIAGNOSTICDATASCREEN_H
#define UI_DIAGNOSTICDATASCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_DiagnosticDataScreen
{
public:
    QPushButton *diagDataAccept;
    QRadioButton *offRadio;
    QRadioButton *onRadio;
    QLabel *diagDataTitle;
    QPushButton *diagDataCancel;
    QFrame *frame;

    void setupUi(QDialog *DiagnosticDataScreen)
    {
        if (DiagnosticDataScreen->objectName().isEmpty())
            DiagnosticDataScreen->setObjectName(QStringLiteral("DiagnosticDataScreen"));
        DiagnosticDataScreen->resize(349, 213);
        DiagnosticDataScreen->setStyleSheet(QStringLiteral(""));
        diagDataAccept = new QPushButton(DiagnosticDataScreen);
        diagDataAccept->setObjectName(QStringLiteral("diagDataAccept"));
        diagDataAccept->setGeometry(QRect(3, 170, 170, 40));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(12);
        diagDataAccept->setFont(font);
        diagDataAccept->setFocusPolicy(Qt::NoFocus);
        diagDataAccept->setStyleSheet(QLatin1String("QPushButton {\n"
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
        offRadio = new QRadioButton(DiagnosticDataScreen);
        offRadio->setObjectName(QStringLiteral("offRadio"));
        offRadio->setEnabled(true);
        offRadio->setGeometry(QRect(88, 100, 100, 25));
        offRadio->setFocusPolicy(Qt::NoFocus);
        offRadio->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        onRadio = new QRadioButton(DiagnosticDataScreen);
        onRadio->setObjectName(QStringLiteral("onRadio"));
        onRadio->setGeometry(QRect(88, 75, 100, 25));
        onRadio->setFocusPolicy(Qt::NoFocus);
        onRadio->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        diagDataTitle = new QLabel(DiagnosticDataScreen);
        diagDataTitle->setObjectName(QStringLiteral("diagDataTitle"));
        diagDataTitle->setGeometry(QRect(24, 16, 231, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(11);
        diagDataTitle->setFont(font1);
        diagDataTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        diagDataCancel = new QPushButton(DiagnosticDataScreen);
        diagDataCancel->setObjectName(QStringLiteral("diagDataCancel"));
        diagDataCancel->setGeometry(QRect(176, 170, 170, 40));
        diagDataCancel->setFont(font);
        diagDataCancel->setFocusPolicy(Qt::NoFocus);
        diagDataCancel->setStyleSheet(QLatin1String("QPushButton {\n"
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
        frame = new QFrame(DiagnosticDataScreen);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        diagDataAccept->raise();
        offRadio->raise();
        onRadio->raise();
        diagDataTitle->raise();
        diagDataCancel->raise();

        retranslateUi(DiagnosticDataScreen);

        QMetaObject::connectSlotsByName(DiagnosticDataScreen);
    } // setupUi

    void retranslateUi(QDialog *DiagnosticDataScreen)
    {
        DiagnosticDataScreen->setWindowTitle(QApplication::translate("DiagnosticDataScreen", "Dialog", nullptr));
        diagDataAccept->setText(QApplication::translate("DiagnosticDataScreen", "Accept", nullptr));
        offRadio->setText(QApplication::translate("DiagnosticDataScreen", "Off", nullptr));
        onRadio->setText(QApplication::translate("DiagnosticDataScreen", "On", nullptr));
        diagDataTitle->setText(QApplication::translate("DiagnosticDataScreen", "Display Diagnostic Data", nullptr));
        diagDataCancel->setText(QApplication::translate("DiagnosticDataScreen", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DiagnosticDataScreen: public Ui_DiagnosticDataScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIAGNOSTICDATASCREEN_H
