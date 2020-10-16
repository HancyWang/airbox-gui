/********************************************************************************
** Form generated from reading UI file 'setpressureclinical.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETPRESSURECLINICAL_H
#define UI_SETPRESSURECLINICAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_SetPressureClinical
{
public:
    QSlider *setPressureSlider;
    QPushButton *setPressureIncrement;
    QLabel *setPressureTitle;
    QLabel *setPressureValue;
    QPushButton *setPressureAccept;
    QLabel *setPressureUnit;
    QPushButton *setPressureDecrement;
    QPushButton *setPressureCancel;
    QFrame *frame;

    void setupUi(QDialog *SetPressureClinical)
    {
        if (SetPressureClinical->objectName().isEmpty())
            SetPressureClinical->setObjectName(QStringLiteral("SetPressureClinical"));
        SetPressureClinical->resize(349, 213);
        SetPressureClinical->setStyleSheet(QStringLiteral(""));
        setPressureSlider = new QSlider(SetPressureClinical);
        setPressureSlider->setObjectName(QStringLiteral("setPressureSlider"));
        setPressureSlider->setGeometry(QRect(19, 125, 217, 32));
        setPressureSlider->setFocusPolicy(Qt::NoFocus);
        setPressureSlider->setStyleSheet(QLatin1String("QSlider::handle:horizontal {\n"
"    background: #8f8f8f;\n"
"    width: 20px;\n"
"    border-radius: 7px;\n"
"}"));
        setPressureSlider->setMinimum(4);
        setPressureSlider->setMaximum(20);
        setPressureSlider->setPageStep(1);
        setPressureSlider->setOrientation(Qt::Horizontal);
        setPressureIncrement = new QPushButton(SetPressureClinical);
        setPressureIncrement->setObjectName(QStringLiteral("setPressureIncrement"));
        setPressureIncrement->setGeometry(QRect(255, 72, 66, 33));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(14);
        setPressureIncrement->setFont(font);
        setPressureIncrement->setFocusPolicy(Qt::NoFocus);
        setPressureIncrement->setStyleSheet(QLatin1String("QPushButton {\n"
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
        setPressureTitle = new QLabel(SetPressureClinical);
        setPressureTitle->setObjectName(QStringLiteral("setPressureTitle"));
        setPressureTitle->setGeometry(QRect(24, 16, 161, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(11);
        setPressureTitle->setFont(font1);
        setPressureTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        setPressureValue = new QLabel(SetPressureClinical);
        setPressureValue->setObjectName(QStringLiteral("setPressureValue"));
        setPressureValue->setGeometry(QRect(121, 53, 50, 44));
        QFont font2;
        font2.setFamily(QStringLiteral("Roboto"));
        font2.setPointSize(28);
        setPressureValue->setFont(font2);
        setPressureValue->setStyleSheet(QStringLiteral("color:#2196F3"));
        setPressureValue->setAlignment(Qt::AlignCenter);
        setPressureAccept = new QPushButton(SetPressureClinical);
        setPressureAccept->setObjectName(QStringLiteral("setPressureAccept"));
        setPressureAccept->setGeometry(QRect(3, 170, 170, 40));
        QFont font3;
        font3.setFamily(QStringLiteral("Roboto"));
        font3.setPointSize(12);
        setPressureAccept->setFont(font3);
        setPressureAccept->setFocusPolicy(Qt::NoFocus);
        setPressureAccept->setStyleSheet(QLatin1String("QPushButton {\n"
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
        setPressureUnit = new QLabel(SetPressureClinical);
        setPressureUnit->setObjectName(QStringLiteral("setPressureUnit"));
        setPressureUnit->setGeometry(QRect(111, 100, 71, 20));
        setPressureUnit->setStyleSheet(QStringLiteral("color:#616161"));
        setPressureUnit->setAlignment(Qt::AlignCenter);
        setPressureDecrement = new QPushButton(SetPressureClinical);
        setPressureDecrement->setObjectName(QStringLiteral("setPressureDecrement"));
        setPressureDecrement->setGeometry(QRect(255, 118, 66, 33));
        setPressureDecrement->setFont(font);
        setPressureDecrement->setFocusPolicy(Qt::NoFocus);
        setPressureDecrement->setStyleSheet(QLatin1String("QPushButton {\n"
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
        setPressureCancel = new QPushButton(SetPressureClinical);
        setPressureCancel->setObjectName(QStringLiteral("setPressureCancel"));
        setPressureCancel->setGeometry(QRect(176, 170, 170, 40));
        setPressureCancel->setFont(font3);
        setPressureCancel->setFocusPolicy(Qt::NoFocus);
        setPressureCancel->setStyleSheet(QLatin1String("QPushButton {\n"
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
        frame = new QFrame(SetPressureClinical);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        setPressureSlider->raise();
        setPressureIncrement->raise();
        setPressureTitle->raise();
        setPressureValue->raise();
        setPressureAccept->raise();
        setPressureUnit->raise();
        setPressureDecrement->raise();
        setPressureCancel->raise();

        retranslateUi(SetPressureClinical);

        QMetaObject::connectSlotsByName(SetPressureClinical);
    } // setupUi

    void retranslateUi(QDialog *SetPressureClinical)
    {
        SetPressureClinical->setWindowTitle(QApplication::translate("SetPressureClinical", "Dialog", nullptr));
        setPressureIncrement->setText(QApplication::translate("SetPressureClinical", "+", nullptr));
        setPressureTitle->setText(QApplication::translate("SetPressureClinical", "Set Pressure", nullptr));
        setPressureValue->setText(QApplication::translate("SetPressureClinical", "5", nullptr));
        setPressureAccept->setText(QApplication::translate("SetPressureClinical", "Accept", nullptr));
        setPressureUnit->setText(QApplication::translate("SetPressureClinical", "<html><head/><body><p>cmH<span style=\" vertical-align:sub;\">2</span>O</p></body></html>", nullptr));
        setPressureDecrement->setText(QApplication::translate("SetPressureClinical", "-", nullptr));
        setPressureCancel->setText(QApplication::translate("SetPressureClinical", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetPressureClinical: public Ui_SetPressureClinical {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETPRESSURECLINICAL_H
