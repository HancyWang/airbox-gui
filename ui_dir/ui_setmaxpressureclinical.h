/********************************************************************************
** Form generated from reading UI file 'setmaxpressureclinical.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETMAXPRESSURECLINICAL_H
#define UI_SETMAXPRESSURECLINICAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_SetMaxPressureClinical
{
public:
    QPushButton *setMaxPressureIncrement;
    QLabel *setMaxPressureUnit;
    QPushButton *setMaxPressureDecrement;
    QFrame *frame;
    QLabel *warningSetMinPressureTitle;
    QLabel *setMinPressure;
    QPushButton *setMaxPressureAccept;
    QPushButton *setMaxPressureCancel;
    QSlider *setMaxPressureSlider;
    QLabel *setMaxPressureValue;
    QLabel *setMaxPressureTitle;

    void setupUi(QDialog *SetMaxPressureClinical)
    {
        if (SetMaxPressureClinical->objectName().isEmpty())
            SetMaxPressureClinical->setObjectName(QStringLiteral("SetMaxPressureClinical"));
        SetMaxPressureClinical->resize(349, 213);
        setMaxPressureIncrement = new QPushButton(SetMaxPressureClinical);
        setMaxPressureIncrement->setObjectName(QStringLiteral("setMaxPressureIncrement"));
        setMaxPressureIncrement->setGeometry(QRect(251, 76, 66, 33));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(14);
        setMaxPressureIncrement->setFont(font);
        setMaxPressureIncrement->setFocusPolicy(Qt::NoFocus);
        setMaxPressureIncrement->setStyleSheet(QLatin1String("QPushButton {\n"
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
        setMaxPressureUnit = new QLabel(SetMaxPressureClinical);
        setMaxPressureUnit->setObjectName(QStringLiteral("setMaxPressureUnit"));
        setMaxPressureUnit->setGeometry(QRect(117, 104, 50, 20));
        setMaxPressureUnit->setStyleSheet(QStringLiteral("color:#616161"));
        setMaxPressureUnit->setAlignment(Qt::AlignCenter);
        setMaxPressureDecrement = new QPushButton(SetMaxPressureClinical);
        setMaxPressureDecrement->setObjectName(QStringLiteral("setMaxPressureDecrement"));
        setMaxPressureDecrement->setGeometry(QRect(251, 122, 66, 33));
        setMaxPressureDecrement->setFont(font);
        setMaxPressureDecrement->setFocusPolicy(Qt::NoFocus);
        setMaxPressureDecrement->setStyleSheet(QLatin1String("QPushButton {\n"
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
        frame = new QFrame(SetMaxPressureClinical);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        warningSetMinPressureTitle = new QLabel(frame);
        warningSetMinPressureTitle->setObjectName(QStringLiteral("warningSetMinPressureTitle"));
        warningSetMinPressureTitle->setGeometry(QRect(20, 40, 311, 21));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(9);
        warningSetMinPressureTitle->setFont(font1);
        warningSetMinPressureTitle->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));
        warningSetMinPressureTitle->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        setMinPressure = new QLabel(frame);
        setMinPressure->setObjectName(QStringLiteral("setMinPressure"));
        setMinPressure->setGeometry(QRect(70, 80, 50, 20));
        setMinPressure->setStyleSheet(QStringLiteral("color:#616161"));
        setMinPressure->setAlignment(Qt::AlignCenter);
        setMaxPressureAccept = new QPushButton(SetMaxPressureClinical);
        setMaxPressureAccept->setObjectName(QStringLiteral("setMaxPressureAccept"));
        setMaxPressureAccept->setGeometry(QRect(3, 170, 170, 40));
        QFont font2;
        font2.setFamily(QStringLiteral("Roboto"));
        font2.setPointSize(12);
        setMaxPressureAccept->setFont(font2);
        setMaxPressureAccept->setFocusPolicy(Qt::NoFocus);
        setMaxPressureAccept->setStyleSheet(QLatin1String("QPushButton {\n"
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
        setMaxPressureCancel = new QPushButton(SetMaxPressureClinical);
        setMaxPressureCancel->setObjectName(QStringLiteral("setMaxPressureCancel"));
        setMaxPressureCancel->setGeometry(QRect(176, 170, 170, 40));
        setMaxPressureCancel->setFont(font2);
        setMaxPressureCancel->setFocusPolicy(Qt::NoFocus);
        setMaxPressureCancel->setStyleSheet(QLatin1String("QPushButton {\n"
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
        setMaxPressureSlider = new QSlider(SetMaxPressureClinical);
        setMaxPressureSlider->setObjectName(QStringLiteral("setMaxPressureSlider"));
        setMaxPressureSlider->setGeometry(QRect(15, 129, 217, 32));
        setMaxPressureSlider->setFocusPolicy(Qt::NoFocus);
        setMaxPressureSlider->setStyleSheet(QLatin1String("QSlider::handle:horizontal {\n"
"    background: #8f8f8f;\n"
"    width: 20px;\n"
"    border-radius: 7px;\n"
"}"));
        setMaxPressureSlider->setMinimum(4);
        setMaxPressureSlider->setMaximum(20);
        setMaxPressureSlider->setOrientation(Qt::Horizontal);
        setMaxPressureValue = new QLabel(SetMaxPressureClinical);
        setMaxPressureValue->setObjectName(QStringLiteral("setMaxPressureValue"));
        setMaxPressureValue->setGeometry(QRect(117, 57, 50, 44));
        QFont font3;
        font3.setFamily(QStringLiteral("Roboto"));
        font3.setPointSize(28);
        setMaxPressureValue->setFont(font3);
        setMaxPressureValue->setStyleSheet(QLatin1String("color:#2196F3;\n"
"background:transparent"));
        setMaxPressureValue->setAlignment(Qt::AlignCenter);
        setMaxPressureTitle = new QLabel(SetMaxPressureClinical);
        setMaxPressureTitle->setObjectName(QStringLiteral("setMaxPressureTitle"));
        setMaxPressureTitle->setGeometry(QRect(20, 10, 161, 31));
        QFont font4;
        font4.setFamily(QStringLiteral("Roboto"));
        font4.setPointSize(11);
        setMaxPressureTitle->setFont(font4);
        setMaxPressureTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        frame->raise();
        setMaxPressureAccept->raise();
        setMaxPressureCancel->raise();
        setMaxPressureSlider->raise();
        setMaxPressureValue->raise();
        setMaxPressureTitle->raise();
        setMaxPressureIncrement->raise();
        setMaxPressureDecrement->raise();
        setMaxPressureUnit->raise();

        retranslateUi(SetMaxPressureClinical);

        QMetaObject::connectSlotsByName(SetMaxPressureClinical);
    } // setupUi

    void retranslateUi(QDialog *SetMaxPressureClinical)
    {
        SetMaxPressureClinical->setWindowTitle(QApplication::translate("SetMaxPressureClinical", "Dialog", nullptr));
        setMaxPressureIncrement->setText(QApplication::translate("SetMaxPressureClinical", "+", nullptr));
        setMaxPressureUnit->setText(QApplication::translate("SetMaxPressureClinical", "<html><head/><body><p>cmH<span style=\" vertical-align:sub;\">2</span>O</p></body></html>", nullptr));
        setMaxPressureDecrement->setText(QApplication::translate("SetMaxPressureClinical", "-", nullptr));
        warningSetMinPressureTitle->setText(QApplication::translate("SetMaxPressureClinical", "Reached to Set Min Pressure Limit", nullptr));
        setMinPressure->setText(QApplication::translate("SetMaxPressureClinical", "5", nullptr));
        setMaxPressureAccept->setText(QApplication::translate("SetMaxPressureClinical", "Accept", nullptr));
        setMaxPressureCancel->setText(QApplication::translate("SetMaxPressureClinical", "Cancel", nullptr));
        setMaxPressureValue->setText(QApplication::translate("SetMaxPressureClinical", "10", nullptr));
        setMaxPressureTitle->setText(QApplication::translate("SetMaxPressureClinical", "Set Max Pressure", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetMaxPressureClinical: public Ui_SetMaxPressureClinical {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETMAXPRESSURECLINICAL_H
