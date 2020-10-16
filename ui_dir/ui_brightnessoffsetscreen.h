/********************************************************************************
** Form generated from reading UI file 'brightnessoffsetscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BRIGHTNESSOFFSETSCREEN_H
#define UI_BRIGHTNESSOFFSETSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_BrightnessOffsetScreen
{
public:
    QFrame *frame;
    QSlider *brightnessOffsetSlider;
    QLabel *brightnessOffsetValue;
    QLabel *brightnessOffsetTitle;
    QPushButton *brightnessOffsetCancel;
    QPushButton *brightnessOffsetIncrement;
    QPushButton *brightnessOffsetDecrement;
    QPushButton *brightnessOffsetAccept;
    QLabel *brightnessOffsetUnit;

    void setupUi(QDialog *BrightnessOffsetScreen)
    {
        if (BrightnessOffsetScreen->objectName().isEmpty())
            BrightnessOffsetScreen->setObjectName(QStringLiteral("BrightnessOffsetScreen"));
        BrightnessOffsetScreen->resize(349, 213);
        frame = new QFrame(BrightnessOffsetScreen);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        brightnessOffsetSlider = new QSlider(BrightnessOffsetScreen);
        brightnessOffsetSlider->setObjectName(QStringLiteral("brightnessOffsetSlider"));
        brightnessOffsetSlider->setGeometry(QRect(18, 125, 217, 32));
        brightnessOffsetSlider->setFocusPolicy(Qt::NoFocus);
        brightnessOffsetSlider->setStyleSheet(QLatin1String("QSlider::handle:horizontal {\n"
"    background: #8f8f8f;\n"
"    width: 20px;\n"
"    border-radius: 7px;\n"
"}"));
        brightnessOffsetSlider->setOrientation(Qt::Horizontal);
        brightnessOffsetValue = new QLabel(BrightnessOffsetScreen);
        brightnessOffsetValue->setObjectName(QStringLiteral("brightnessOffsetValue"));
        brightnessOffsetValue->setGeometry(QRect(120, 50, 50, 44));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(28);
        brightnessOffsetValue->setFont(font);
        brightnessOffsetValue->setStyleSheet(QStringLiteral("color:#2196F3"));
        brightnessOffsetValue->setAlignment(Qt::AlignCenter);
        brightnessOffsetTitle = new QLabel(BrightnessOffsetScreen);
        brightnessOffsetTitle->setObjectName(QStringLiteral("brightnessOffsetTitle"));
        brightnessOffsetTitle->setGeometry(QRect(23, 16, 161, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(11);
        brightnessOffsetTitle->setFont(font1);
        brightnessOffsetTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        brightnessOffsetCancel = new QPushButton(BrightnessOffsetScreen);
        brightnessOffsetCancel->setObjectName(QStringLiteral("brightnessOffsetCancel"));
        brightnessOffsetCancel->setGeometry(QRect(175, 170, 170, 40));
        QFont font2;
        font2.setFamily(QStringLiteral("Roboto"));
        font2.setPointSize(12);
        brightnessOffsetCancel->setFont(font2);
        brightnessOffsetCancel->setFocusPolicy(Qt::NoFocus);
        brightnessOffsetCancel->setStyleSheet(QLatin1String("QPushButton {\n"
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
        brightnessOffsetIncrement = new QPushButton(BrightnessOffsetScreen);
        brightnessOffsetIncrement->setObjectName(QStringLiteral("brightnessOffsetIncrement"));
        brightnessOffsetIncrement->setGeometry(QRect(254, 72, 66, 33));
        QFont font3;
        font3.setFamily(QStringLiteral("Roboto"));
        font3.setPointSize(14);
        brightnessOffsetIncrement->setFont(font3);
        brightnessOffsetIncrement->setFocusPolicy(Qt::NoFocus);
        brightnessOffsetIncrement->setStyleSheet(QLatin1String("QPushButton {\n"
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
        brightnessOffsetDecrement = new QPushButton(BrightnessOffsetScreen);
        brightnessOffsetDecrement->setObjectName(QStringLiteral("brightnessOffsetDecrement"));
        brightnessOffsetDecrement->setGeometry(QRect(254, 118, 66, 33));
        brightnessOffsetDecrement->setFont(font3);
        brightnessOffsetDecrement->setFocusPolicy(Qt::NoFocus);
        brightnessOffsetDecrement->setStyleSheet(QLatin1String("QPushButton {\n"
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
        brightnessOffsetAccept = new QPushButton(BrightnessOffsetScreen);
        brightnessOffsetAccept->setObjectName(QStringLiteral("brightnessOffsetAccept"));
        brightnessOffsetAccept->setGeometry(QRect(2, 170, 170, 40));
        brightnessOffsetAccept->setFont(font2);
        brightnessOffsetAccept->setFocusPolicy(Qt::NoFocus);
        brightnessOffsetAccept->setStyleSheet(QLatin1String("QPushButton {\n"
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
        brightnessOffsetUnit = new QLabel(BrightnessOffsetScreen);
        brightnessOffsetUnit->setObjectName(QStringLiteral("brightnessOffsetUnit"));
        brightnessOffsetUnit->setGeometry(QRect(120, 100, 50, 14));
        brightnessOffsetUnit->setStyleSheet(QStringLiteral("color:#616161"));
        brightnessOffsetUnit->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        retranslateUi(BrightnessOffsetScreen);

        QMetaObject::connectSlotsByName(BrightnessOffsetScreen);
    } // setupUi

    void retranslateUi(QDialog *BrightnessOffsetScreen)
    {
        BrightnessOffsetScreen->setWindowTitle(QApplication::translate("BrightnessOffsetScreen", "Dialog", nullptr));
        brightnessOffsetValue->setText(QApplication::translate("BrightnessOffsetScreen", "5", nullptr));
        brightnessOffsetTitle->setText(QApplication::translate("BrightnessOffsetScreen", "Brightness Offset", nullptr));
        brightnessOffsetCancel->setText(QApplication::translate("BrightnessOffsetScreen", "Cancel", nullptr));
        brightnessOffsetIncrement->setText(QApplication::translate("BrightnessOffsetScreen", "+", nullptr));
        brightnessOffsetDecrement->setText(QApplication::translate("BrightnessOffsetScreen", "-", nullptr));
        brightnessOffsetAccept->setText(QApplication::translate("BrightnessOffsetScreen", "Accept", nullptr));
        brightnessOffsetUnit->setText(QApplication::translate("BrightnessOffsetScreen", "%", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BrightnessOffsetScreen: public Ui_BrightnessOffsetScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BRIGHTNESSOFFSETSCREEN_H
