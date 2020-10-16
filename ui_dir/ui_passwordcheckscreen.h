/********************************************************************************
** Form generated from reading UI file 'passwordcheckscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDCHECKSCREEN_H
#define UI_PASSWORDCHECKSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PasswordCheckScreen
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
    QPushButton *passwordCancel;
    QPushButton *backSpace;
    QLabel *passwordText;
    QLabel *passwordWarning;
    QPushButton *passwordAccept;
    QLabel *passwordTitle;

    void setupUi(QDialog *PasswordCheckScreen)
    {
        if (PasswordCheckScreen->objectName().isEmpty())
            PasswordCheckScreen->setObjectName(QStringLiteral("PasswordCheckScreen"));
        PasswordCheckScreen->resize(352, 260);
        frame = new QFrame(PasswordCheckScreen);
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
        passwordCancel = new QPushButton(frame);
        passwordCancel->setObjectName(QStringLiteral("passwordCancel"));
        passwordCancel->setGeometry(QRect(213, 183, 80, 42));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(12);
        passwordCancel->setFont(font1);
        passwordCancel->setFocusPolicy(Qt::NoFocus);
        passwordCancel->setStyleSheet(QLatin1String("QPushButton {\n"
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
        passwordText = new QLabel(frame);
        passwordText->setObjectName(QStringLiteral("passwordText"));
        passwordText->setGeometry(QRect(56, 38, 238, 33));
        passwordText->setStyleSheet(QLatin1String("color:#FFFFFF;\n"
"background-color: rgb(33, 33, 33);\n"
""));
        passwordText->setAlignment(Qt::AlignCenter);
        passwordWarning = new QLabel(frame);
        passwordWarning->setObjectName(QStringLiteral("passwordWarning"));
        passwordWarning->setGeometry(QRect(58, 72, 231, 20));
        QFont font3;
        font3.setFamily(QStringLiteral("Roboto"));
        font3.setPointSize(9);
        passwordWarning->setFont(font3);
        passwordWarning->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        passwordWarning->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        passwordAccept = new QPushButton(PasswordCheckScreen);
        passwordAccept->setObjectName(QStringLiteral("passwordAccept"));
        passwordAccept->setGeometry(QRect(213, 134, 80, 42));
        passwordAccept->setFont(font1);
        passwordAccept->setFocusPolicy(Qt::NoFocus);
        passwordAccept->setStyleSheet(QLatin1String("QPushButton {\n"
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
        passwordTitle = new QLabel(PasswordCheckScreen);
        passwordTitle->setObjectName(QStringLiteral("passwordTitle"));
        passwordTitle->setGeometry(QRect(23, 8, 241, 31));
        QFont font4;
        font4.setFamily(QStringLiteral("Roboto"));
        font4.setPointSize(11);
        passwordTitle->setFont(font4);
        passwordTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));

        retranslateUi(PasswordCheckScreen);

        QMetaObject::connectSlotsByName(PasswordCheckScreen);
    } // setupUi

    void retranslateUi(QDialog *PasswordCheckScreen)
    {
        PasswordCheckScreen->setWindowTitle(QApplication::translate("PasswordCheckScreen", "Dialog", nullptr));
        digit1->setText(QApplication::translate("PasswordCheckScreen", "1", nullptr));
        digit2->setText(QApplication::translate("PasswordCheckScreen", "2", nullptr));
        digit0->setText(QApplication::translate("PasswordCheckScreen", "0", nullptr));
        digit4->setText(QApplication::translate("PasswordCheckScreen", "4", nullptr));
        digit5->setText(QApplication::translate("PasswordCheckScreen", "5", nullptr));
        digit6->setText(QApplication::translate("PasswordCheckScreen", "6", nullptr));
        digit7->setText(QApplication::translate("PasswordCheckScreen", "7", nullptr));
        digit8->setText(QApplication::translate("PasswordCheckScreen", "8", nullptr));
        digit9->setText(QApplication::translate("PasswordCheckScreen", "9", nullptr));
        digit3->setText(QApplication::translate("PasswordCheckScreen", "3", nullptr));
        passwordCancel->setText(QApplication::translate("PasswordCheckScreen", "Cancel", nullptr));
        backSpace->setText(QString());
        passwordText->setText(QString());
        passwordWarning->setText(QApplication::translate("PasswordCheckScreen", "Invalid Password", nullptr));
        passwordAccept->setText(QApplication::translate("PasswordCheckScreen", "Accept", nullptr));
        passwordTitle->setText(QApplication::translate("PasswordCheckScreen", "Enter Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PasswordCheckScreen: public Ui_PasswordCheckScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDCHECKSCREEN_H
