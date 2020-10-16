/********************************************************************************
** Form generated from reading UI file 'poweroffoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POWEROFFOPTIONS_H
#define UI_POWEROFFOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PowerOffOptions
{
public:
    QFrame *frame;
    QPushButton *powerOffCancel;

    void setupUi(QDialog *PowerOffOptions)
    {
        if (PowerOffOptions->objectName().isEmpty())
            PowerOffOptions->setObjectName(QStringLiteral("PowerOffOptions"));
        PowerOffOptions->resize(349, 213);
        frame = new QFrame(PowerOffOptions);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        powerOffCancel = new QPushButton(PowerOffOptions);
        powerOffCancel->setObjectName(QStringLiteral("powerOffCancel"));
        powerOffCancel->setGeometry(QRect(3, 170, 343, 40));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(12);
        powerOffCancel->setFont(font);
        powerOffCancel->setFocusPolicy(Qt::NoFocus);
        powerOffCancel->setStyleSheet(QLatin1String("QPushButton {\n"
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

        retranslateUi(PowerOffOptions);

        QMetaObject::connectSlotsByName(PowerOffOptions);
    } // setupUi

    void retranslateUi(QDialog *PowerOffOptions)
    {
        PowerOffOptions->setWindowTitle(QApplication::translate("PowerOffOptions", "Dialog", nullptr));
        powerOffCancel->setText(QApplication::translate("PowerOffOptions", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PowerOffOptions: public Ui_PowerOffOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POWEROFFOPTIONS_H
