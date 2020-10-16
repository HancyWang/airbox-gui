/********************************************************************************
** Form generated from reading UI file 'sdcardformatscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SDCARDFORMATSCREEN_H
#define UI_SDCARDFORMATSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SdCardFormatScreen
{
public:
    QFrame *frame;
    QLabel *formatWarningText;
    QPushButton *closeButton;

    void setupUi(QDialog *SdCardFormatScreen)
    {
        if (SdCardFormatScreen->objectName().isEmpty())
            SdCardFormatScreen->setObjectName(QStringLiteral("SdCardFormatScreen"));
        SdCardFormatScreen->resize(349, 213);
        frame = new QFrame(SdCardFormatScreen);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        formatWarningText = new QLabel(frame);
        formatWarningText->setObjectName(QStringLiteral("formatWarningText"));
        formatWarningText->setGeometry(QRect(60, 30, 201, 101));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(10);
        formatWarningText->setFont(font);
        formatWarningText->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        formatWarningText->setAlignment(Qt::AlignCenter);
        formatWarningText->setWordWrap(true);
        closeButton = new QPushButton(frame);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(3, 170, 343, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(12);
        closeButton->setFont(font1);
        closeButton->setFocusPolicy(Qt::NoFocus);
        closeButton->setStyleSheet(QLatin1String("QPushButton {\n"
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

        retranslateUi(SdCardFormatScreen);

        QMetaObject::connectSlotsByName(SdCardFormatScreen);
    } // setupUi

    void retranslateUi(QDialog *SdCardFormatScreen)
    {
        SdCardFormatScreen->setWindowTitle(QApplication::translate("SdCardFormatScreen", "Dialog", nullptr));
        formatWarningText->setText(QApplication::translate("SdCardFormatScreen", "Please format the \n"
"SD card \n"
"and insert again", nullptr));
        closeButton->setText(QApplication::translate("SdCardFormatScreen", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SdCardFormatScreen: public Ui_SdCardFormatScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SDCARDFORMATSCREEN_H
