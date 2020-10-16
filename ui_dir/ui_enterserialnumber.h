/********************************************************************************
** Form generated from reading UI file 'enterserialnumber.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTERSERIALNUMBER_H
#define UI_ENTERSERIALNUMBER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EnterSerialNumber
{
public:
    QFrame *frame;
    QPushButton *digit1;
    QPushButton *digit2;
    QPushButton *digit0;
    QPushButton *digit4;
    QPushButton *digit5;
    QPushButton *digit6;
    QPushButton *digit7;
    QPushButton *digit8;
    QPushButton *digit9;
    QPushButton *digit3;
    QPushButton *serialNumberCancel;
    QPushButton *backSpace;
    QLabel *serialNumberText;
    QLabel *serialNumberWarning;
    QPushButton *serialNumberAccept;
    QLabel *serialNumberTitle;

    void setupUi(QDialog *EnterSerialNumber)
    {
        if (EnterSerialNumber->objectName().isEmpty())
            EnterSerialNumber->setObjectName(QStringLiteral("EnterSerialNumber"));
        EnterSerialNumber->resize(352, 260);
        frame = new QFrame(EnterSerialNumber);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 352, 260));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        digit1 = new QPushButton(frame);
        digit1->setObjectName(QStringLiteral("digit1"));
        digit1->setGeometry(QRect(62, 99, 40, 35));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(10);
        digit1->setFont(font);
        digit1->setFocusPolicy(Qt::NoFocus);
        digit1->setStyleSheet(QLatin1String("QPushButton {\n"
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
        digit2 = new QPushButton(frame);
        digit2->setObjectName(QStringLiteral("digit2"));
        digit2->setGeometry(QRect(112, 99, 40, 35));
        digit2->setFont(font);
        digit2->setFocusPolicy(Qt::NoFocus);
        digit2->setStyleSheet(QLatin1String("QPushButton {\n"
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
        digit0 = new QPushButton(frame);
        digit0->setObjectName(QStringLiteral("digit0"));
        digit0->setGeometry(QRect(62, 222, 40, 35));
        digit0->setFont(font);
        digit0->setFocusPolicy(Qt::NoFocus);
        digit0->setStyleSheet(QLatin1String("QPushButton {\n"
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
        digit4 = new QPushButton(frame);
        digit4->setObjectName(QStringLiteral("digit4"));
        digit4->setGeometry(QRect(62, 140, 40, 35));
        digit4->setFont(font);
        digit4->setFocusPolicy(Qt::NoFocus);
        digit4->setStyleSheet(QLatin1String("QPushButton {\n"
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
        digit5 = new QPushButton(frame);
        digit5->setObjectName(QStringLiteral("digit5"));
        digit5->setGeometry(QRect(112, 140, 40, 35));
        digit5->setFont(font);
        digit5->setFocusPolicy(Qt::NoFocus);
        digit5->setStyleSheet(QLatin1String("QPushButton {\n"
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
        digit6 = new QPushButton(frame);
        digit6->setObjectName(QStringLiteral("digit6"));
        digit6->setGeometry(QRect(162, 140, 40, 35));
        digit6->setFont(font);
        digit6->setFocusPolicy(Qt::NoFocus);
        digit6->setStyleSheet(QLatin1String("QPushButton {\n"
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
        digit7 = new QPushButton(frame);
        digit7->setObjectName(QStringLiteral("digit7"));
        digit7->setGeometry(QRect(62, 181, 40, 35));
        digit7->setFont(font);
        digit7->setFocusPolicy(Qt::NoFocus);
        digit7->setStyleSheet(QLatin1String("QPushButton {\n"
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
        digit8 = new QPushButton(frame);
        digit8->setObjectName(QStringLiteral("digit8"));
        digit8->setGeometry(QRect(112, 181, 40, 35));
        digit8->setFont(font);
        digit8->setFocusPolicy(Qt::NoFocus);
        digit8->setStyleSheet(QLatin1String("QPushButton {\n"
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
        digit9 = new QPushButton(frame);
        digit9->setObjectName(QStringLiteral("digit9"));
        digit9->setGeometry(QRect(162, 181, 40, 35));
        digit9->setFont(font);
        digit9->setFocusPolicy(Qt::NoFocus);
        digit9->setStyleSheet(QLatin1String("QPushButton {\n"
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
        digit3 = new QPushButton(frame);
        digit3->setObjectName(QStringLiteral("digit3"));
        digit3->setGeometry(QRect(162, 99, 40, 35));
        digit3->setFont(font);
        digit3->setFocusPolicy(Qt::NoFocus);
        digit3->setStyleSheet(QLatin1String("QPushButton {\n"
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
        serialNumberCancel = new QPushButton(frame);
        serialNumberCancel->setObjectName(QStringLiteral("serialNumberCancel"));
        serialNumberCancel->setGeometry(QRect(213, 183, 80, 42));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(12);
        serialNumberCancel->setFont(font1);
        serialNumberCancel->setFocusPolicy(Qt::NoFocus);
        serialNumberCancel->setStyleSheet(QLatin1String("QPushButton {\n"
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
        backSpace = new QPushButton(frame);
        backSpace->setObjectName(QStringLiteral("backSpace"));
        backSpace->setGeometry(QRect(112, 222, 90, 35));
        QFont font2;
        font2.setFamily(QStringLiteral("Roboto"));
        font2.setPointSize(14);
        backSpace->setFont(font2);
        backSpace->setFocusPolicy(Qt::NoFocus);
        backSpace->setStyleSheet(QLatin1String("QPushButton {\n"
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
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/backspace.png"), QSize(), QIcon::Normal, QIcon::Off);
        backSpace->setIcon(icon);
        serialNumberText = new QLabel(frame);
        serialNumberText->setObjectName(QStringLiteral("serialNumberText"));
        serialNumberText->setGeometry(QRect(56, 38, 238, 33));
        serialNumberText->setStyleSheet(QLatin1String("color:#FFFFFF;\n"
"background-color: rgb(33, 33, 33);\n"
""));
        serialNumberText->setAlignment(Qt::AlignCenter);
        serialNumberWarning = new QLabel(frame);
        serialNumberWarning->setObjectName(QStringLiteral("serialNumberWarning"));
        serialNumberWarning->setGeometry(QRect(58, 72, 231, 20));
        QFont font3;
        font3.setFamily(QStringLiteral("Roboto"));
        font3.setPointSize(9);
        serialNumberWarning->setFont(font3);
        serialNumberWarning->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        serialNumberWarning->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        serialNumberAccept = new QPushButton(EnterSerialNumber);
        serialNumberAccept->setObjectName(QStringLiteral("serialNumberAccept"));
        serialNumberAccept->setGeometry(QRect(213, 134, 80, 42));
        serialNumberAccept->setFont(font1);
        serialNumberAccept->setFocusPolicy(Qt::NoFocus);
        serialNumberAccept->setStyleSheet(QLatin1String("QPushButton {\n"
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
        serialNumberTitle = new QLabel(EnterSerialNumber);
        serialNumberTitle->setObjectName(QStringLiteral("serialNumberTitle"));
        serialNumberTitle->setGeometry(QRect(23, 8, 241, 31));
        QFont font4;
        font4.setFamily(QStringLiteral("Roboto"));
        font4.setPointSize(11);
        serialNumberTitle->setFont(font4);
        serialNumberTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));

        retranslateUi(EnterSerialNumber);

        QMetaObject::connectSlotsByName(EnterSerialNumber);
    } // setupUi

    void retranslateUi(QDialog *EnterSerialNumber)
    {
        EnterSerialNumber->setWindowTitle(QApplication::translate("EnterSerialNumber", "Dialog", nullptr));
        digit1->setText(QApplication::translate("EnterSerialNumber", "1", nullptr));
        digit2->setText(QApplication::translate("EnterSerialNumber", "2", nullptr));
        digit0->setText(QApplication::translate("EnterSerialNumber", "0", nullptr));
        digit4->setText(QApplication::translate("EnterSerialNumber", "4", nullptr));
        digit5->setText(QApplication::translate("EnterSerialNumber", "5", nullptr));
        digit6->setText(QApplication::translate("EnterSerialNumber", "6", nullptr));
        digit7->setText(QApplication::translate("EnterSerialNumber", "7", nullptr));
        digit8->setText(QApplication::translate("EnterSerialNumber", "8", nullptr));
        digit9->setText(QApplication::translate("EnterSerialNumber", "9", nullptr));
        digit3->setText(QApplication::translate("EnterSerialNumber", "3", nullptr));
        serialNumberCancel->setText(QApplication::translate("EnterSerialNumber", "Cancel", nullptr));
        backSpace->setText(QString());
        serialNumberText->setText(QString());
        serialNumberWarning->setText(QApplication::translate("EnterSerialNumber", "Invalid Serial Number", nullptr));
        serialNumberAccept->setText(QApplication::translate("EnterSerialNumber", "Accept", nullptr));
        serialNumberTitle->setText(QApplication::translate("EnterSerialNumber", "Enter 16-digit Serial Number", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EnterSerialNumber: public Ui_EnterSerialNumber {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTERSERIALNUMBER_H
