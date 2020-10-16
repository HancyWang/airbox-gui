/********************************************************************************
** Form generated from reading UI file 'setminpressureclinical.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETMINPRESSURECLINICAL_H
#define UI_SETMINPRESSURECLINICAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_SetMinPressureClinical
{
public:
    QPushButton *setMinPressureAccept;
    QLabel *setMinPressureUnit;
    QLabel *setMinPressureValue;
    QPushButton *setMinPressureCancel;
    QFrame *frame;
    QLabel *warningSetMaxPressureTitle;
    QLabel *setMaxPressure;
    QLabel *setMinPressureTitle;
    QSlider *setMinPressureSlider;
    QPushButton *setMinPressureIncrement;
    QPushButton *setMinPressureDecrement;

    void setupUi(QDialog *SetMinPressureClinical)
    {
        if (SetMinPressureClinical->objectName().isEmpty())
            SetMinPressureClinical->setObjectName(QStringLiteral("SetMinPressureClinical"));
        SetMinPressureClinical->resize(349, 213);
        setMinPressureAccept = new QPushButton(SetMinPressureClinical);
        setMinPressureAccept->setObjectName(QStringLiteral("setMinPressureAccept"));
        setMinPressureAccept->setGeometry(QRect(3, 170, 170, 40));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(12);
        setMinPressureAccept->setFont(font);
        setMinPressureAccept->setFocusPolicy(Qt::NoFocus);
        setMinPressureAccept->setStyleSheet(QLatin1String("QPushButton {\n"
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
        setMinPressureUnit = new QLabel(SetMinPressureClinical);
        setMinPressureUnit->setObjectName(QStringLiteral("setMinPressureUnit"));
        setMinPressureUnit->setGeometry(QRect(116, 102, 50, 20));
        setMinPressureUnit->setStyleSheet(QStringLiteral("color:#616161"));
        setMinPressureUnit->setAlignment(Qt::AlignCenter);
        setMinPressureValue = new QLabel(SetMinPressureClinical);
        setMinPressureValue->setObjectName(QStringLiteral("setMinPressureValue"));
        setMinPressureValue->setGeometry(QRect(116, 55, 50, 44));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(28);
        setMinPressureValue->setFont(font1);
        setMinPressureValue->setStyleSheet(QLatin1String("color:#2196F3;\n"
"background:transparent"));
        setMinPressureValue->setAlignment(Qt::AlignCenter);
        setMinPressureCancel = new QPushButton(SetMinPressureClinical);
        setMinPressureCancel->setObjectName(QStringLiteral("setMinPressureCancel"));
        setMinPressureCancel->setGeometry(QRect(176, 170, 170, 40));
        setMinPressureCancel->setFont(font);
        setMinPressureCancel->setFocusPolicy(Qt::NoFocus);
        setMinPressureCancel->setStyleSheet(QLatin1String("QPushButton {\n"
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
        frame = new QFrame(SetMinPressureClinical);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        warningSetMaxPressureTitle = new QLabel(frame);
        warningSetMaxPressureTitle->setObjectName(QStringLiteral("warningSetMaxPressureTitle"));
        warningSetMaxPressureTitle->setGeometry(QRect(20, 40, 291, 21));
        QFont font2;
        font2.setFamily(QStringLiteral("Roboto"));
        font2.setPointSize(9);
        warningSetMaxPressureTitle->setFont(font2);
        warningSetMaxPressureTitle->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));
        warningSetMaxPressureTitle->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        setMaxPressure = new QLabel(frame);
        setMaxPressure->setObjectName(QStringLiteral("setMaxPressure"));
        setMaxPressure->setGeometry(QRect(160, 80, 50, 20));
        setMaxPressure->setStyleSheet(QStringLiteral("color:#616161"));
        setMaxPressure->setAlignment(Qt::AlignCenter);
        setMaxPressure->raise();
        warningSetMaxPressureTitle->raise();
        setMinPressureTitle = new QLabel(SetMinPressureClinical);
        setMinPressureTitle->setObjectName(QStringLiteral("setMinPressureTitle"));
        setMinPressureTitle->setGeometry(QRect(24, 10, 161, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Roboto"));
        font3.setPointSize(11);
        setMinPressureTitle->setFont(font3);
        setMinPressureTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        setMinPressureSlider = new QSlider(SetMinPressureClinical);
        setMinPressureSlider->setObjectName(QStringLiteral("setMinPressureSlider"));
        setMinPressureSlider->setGeometry(QRect(14, 127, 217, 32));
        setMinPressureSlider->setFocusPolicy(Qt::NoFocus);
        setMinPressureSlider->setStyleSheet(QLatin1String("QSlider::handle:horizontal {\n"
"    background: #8f8f8f;\n"
"    width: 20px;\n"
"    border-radius: 7px;\n"
"}"));
        setMinPressureSlider->setMinimum(4);
        setMinPressureSlider->setMaximum(20);
        setMinPressureSlider->setOrientation(Qt::Horizontal);
        setMinPressureIncrement = new QPushButton(SetMinPressureClinical);
        setMinPressureIncrement->setObjectName(QStringLiteral("setMinPressureIncrement"));
        setMinPressureIncrement->setGeometry(QRect(250, 74, 66, 33));
        QFont font4;
        font4.setFamily(QStringLiteral("Roboto"));
        font4.setPointSize(14);
        setMinPressureIncrement->setFont(font4);
        setMinPressureIncrement->setFocusPolicy(Qt::NoFocus);
        setMinPressureIncrement->setStyleSheet(QLatin1String("QPushButton {\n"
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
        setMinPressureDecrement = new QPushButton(SetMinPressureClinical);
        setMinPressureDecrement->setObjectName(QStringLiteral("setMinPressureDecrement"));
        setMinPressureDecrement->setGeometry(QRect(250, 120, 66, 33));
        setMinPressureDecrement->setFont(font4);
        setMinPressureDecrement->setFocusPolicy(Qt::NoFocus);
        setMinPressureDecrement->setStyleSheet(QLatin1String("QPushButton {\n"
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
        frame->raise();
        setMinPressureIncrement->raise();
        setMinPressureUnit->raise();
        setMinPressureDecrement->raise();
        setMinPressureAccept->raise();
        setMinPressureCancel->raise();
        setMinPressureSlider->raise();
        setMinPressureTitle->raise();
        setMinPressureValue->raise();

        retranslateUi(SetMinPressureClinical);

        QMetaObject::connectSlotsByName(SetMinPressureClinical);
    } // setupUi

    void retranslateUi(QDialog *SetMinPressureClinical)
    {
        SetMinPressureClinical->setWindowTitle(QApplication::translate("SetMinPressureClinical", "Dialog", nullptr));
        setMinPressureAccept->setText(QApplication::translate("SetMinPressureClinical", "Accept", nullptr));
        setMinPressureUnit->setText(QApplication::translate("SetMinPressureClinical", "<html><head/><body><p>cmH<span style=\" vertical-align:sub;\">2</span>O</p></body></html>", nullptr));
        setMinPressureValue->setText(QApplication::translate("SetMinPressureClinical", "5", nullptr));
        setMinPressureCancel->setText(QApplication::translate("SetMinPressureClinical", "Cancel", nullptr));
        warningSetMaxPressureTitle->setText(QApplication::translate("SetMinPressureClinical", "Reached to Set Max Pressure Limit", nullptr));
        setMaxPressure->setText(QApplication::translate("SetMinPressureClinical", "10", nullptr));
        setMinPressureTitle->setText(QApplication::translate("SetMinPressureClinical", "Set Min Pressure", nullptr));
        setMinPressureIncrement->setText(QApplication::translate("SetMinPressureClinical", "+", nullptr));
        setMinPressureDecrement->setText(QApplication::translate("SetMinPressureClinical", "-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetMinPressureClinical: public Ui_SetMinPressureClinical {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETMINPRESSURECLINICAL_H
