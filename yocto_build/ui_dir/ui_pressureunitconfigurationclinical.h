/********************************************************************************
** Form generated from reading UI file 'pressureunitconfigurationclinical.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRESSUREUNITCONFIGURATIONCLINICAL_H
#define UI_PRESSUREUNITCONFIGURATIONCLINICAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_PressureUnitConfigurationClinical
{
public:
    QPushButton *pressureUnitAccept;
    QRadioButton *hpaRadio;
    QRadioButton *cmh2oRadio;
    QLabel *pressureUnitTitle;
    QPushButton *pressureUnitCancel;
    QFrame *frame;

    void setupUi(QDialog *PressureUnitConfigurationClinical)
    {
        if (PressureUnitConfigurationClinical->objectName().isEmpty())
            PressureUnitConfigurationClinical->setObjectName(QStringLiteral("PressureUnitConfigurationClinical"));
        PressureUnitConfigurationClinical->resize(349, 213);
        PressureUnitConfigurationClinical->setStyleSheet(QStringLiteral(""));
        pressureUnitAccept = new QPushButton(PressureUnitConfigurationClinical);
        pressureUnitAccept->setObjectName(QStringLiteral("pressureUnitAccept"));
        pressureUnitAccept->setGeometry(QRect(3, 170, 170, 40));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(12);
        pressureUnitAccept->setFont(font);
        pressureUnitAccept->setFocusPolicy(Qt::NoFocus);
        pressureUnitAccept->setStyleSheet(QLatin1String("QPushButton {\n"
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
        hpaRadio = new QRadioButton(PressureUnitConfigurationClinical);
        hpaRadio->setObjectName(QStringLiteral("hpaRadio"));
        hpaRadio->setEnabled(false);
        hpaRadio->setGeometry(QRect(88, 100, 100, 25));
        hpaRadio->setFocusPolicy(Qt::NoFocus);
        hpaRadio->setStyleSheet(QLatin1String("QRadioButton::disabled {\n"
"color:#3B3B3B;\n"
"}\n"
"QRadioButton::indicator::unchecked{ \n"
"background-color:#3B3B3B;\n"
"}"));
        cmh2oRadio = new QRadioButton(PressureUnitConfigurationClinical);
        cmh2oRadio->setObjectName(QStringLiteral("cmh2oRadio"));
        cmh2oRadio->setGeometry(QRect(88, 75, 111, 25));
        cmh2oRadio->setFocusPolicy(Qt::NoFocus);
        cmh2oRadio->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        pressureUnitTitle = new QLabel(PressureUnitConfigurationClinical);
        pressureUnitTitle->setObjectName(QStringLiteral("pressureUnitTitle"));
        pressureUnitTitle->setGeometry(QRect(24, 16, 231, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(11);
        pressureUnitTitle->setFont(font1);
        pressureUnitTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        pressureUnitCancel = new QPushButton(PressureUnitConfigurationClinical);
        pressureUnitCancel->setObjectName(QStringLiteral("pressureUnitCancel"));
        pressureUnitCancel->setGeometry(QRect(176, 170, 170, 40));
        pressureUnitCancel->setFont(font);
        pressureUnitCancel->setFocusPolicy(Qt::NoFocus);
        pressureUnitCancel->setStyleSheet(QLatin1String("QPushButton {\n"
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
        frame = new QFrame(PressureUnitConfigurationClinical);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        pressureUnitAccept->raise();
        hpaRadio->raise();
        cmh2oRadio->raise();
        pressureUnitTitle->raise();
        pressureUnitCancel->raise();

        retranslateUi(PressureUnitConfigurationClinical);

        QMetaObject::connectSlotsByName(PressureUnitConfigurationClinical);
    } // setupUi

    void retranslateUi(QDialog *PressureUnitConfigurationClinical)
    {
        PressureUnitConfigurationClinical->setWindowTitle(QApplication::translate("PressureUnitConfigurationClinical", "Dialog", nullptr));
        pressureUnitAccept->setText(QApplication::translate("PressureUnitConfigurationClinical", "Accept", nullptr));
        hpaRadio->setText(QApplication::translate("PressureUnitConfigurationClinical", "hPa", nullptr));
        cmh2oRadio->setText(QApplication::translate("PressureUnitConfigurationClinical", "cmH2O", nullptr));
        pressureUnitTitle->setText(QApplication::translate("PressureUnitConfigurationClinical", "Pressure Unit", nullptr));
        pressureUnitCancel->setText(QApplication::translate("PressureUnitConfigurationClinical", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PressureUnitConfigurationClinical: public Ui_PressureUnitConfigurationClinical {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRESSUREUNITCONFIGURATIONCLINICAL_H
