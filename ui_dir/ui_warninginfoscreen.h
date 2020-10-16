/********************************************************************************
** Form generated from reading UI file 'warninginfoscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARNINGINFOSCREEN_H
#define UI_WARNINGINFOSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_WarningInfoScreen
{
public:
    QFrame *frame;
    QLabel *warningText;
    QPushButton *closeButton;

    void setupUi(QDialog *WarningInfoScreen)
    {
        if (WarningInfoScreen->objectName().isEmpty())
            WarningInfoScreen->setObjectName(QStringLiteral("WarningInfoScreen"));
        WarningInfoScreen->resize(349, 213);
        frame = new QFrame(WarningInfoScreen);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        warningText = new QLabel(frame);
        warningText->setObjectName(QStringLiteral("warningText"));
        warningText->setGeometry(QRect(74, 30, 201, 101));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(10);
        warningText->setFont(font);
        warningText->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        warningText->setAlignment(Qt::AlignCenter);
        warningText->setWordWrap(true);
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

        retranslateUi(WarningInfoScreen);

        QMetaObject::connectSlotsByName(WarningInfoScreen);
    } // setupUi

    void retranslateUi(QDialog *WarningInfoScreen)
    {
        WarningInfoScreen->setWindowTitle(QApplication::translate("WarningInfoScreen", "Dialog", nullptr));
        warningText->setText(QString());
        closeButton->setText(QApplication::translate("WarningInfoScreen", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WarningInfoScreen: public Ui_WarningInfoScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARNINGINFOSCREEN_H
