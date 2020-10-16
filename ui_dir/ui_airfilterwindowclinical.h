/********************************************************************************
** Form generated from reading UI file 'airfilterwindowclinical.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIRFILTERWINDOWCLINICAL_H
#define UI_AIRFILTERWINDOWCLINICAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_AirFilterWindowClinical
{
public:
    QRadioButton *standardRadio;
    QPushButton *airFilterCancel;
    QLabel *airFilterTitle;
    QPushButton *airFilterAccept;
    QRadioButton *hepaRadio;
    QFrame *frame;

    void setupUi(QDialog *AirFilterWindowClinical)
    {
        if (AirFilterWindowClinical->objectName().isEmpty())
            AirFilterWindowClinical->setObjectName(QStringLiteral("AirFilterWindowClinical"));
        AirFilterWindowClinical->resize(349, 213);
        AirFilterWindowClinical->setStyleSheet(QStringLiteral(""));
        standardRadio = new QRadioButton(AirFilterWindowClinical);
        standardRadio->setObjectName(QStringLiteral("standardRadio"));
        standardRadio->setGeometry(QRect(88, 60, 131, 25));
        standardRadio->setFocusPolicy(Qt::NoFocus);
        standardRadio->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        airFilterCancel = new QPushButton(AirFilterWindowClinical);
        airFilterCancel->setObjectName(QStringLiteral("airFilterCancel"));
        airFilterCancel->setGeometry(QRect(176, 170, 170, 40));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(12);
        airFilterCancel->setFont(font);
        airFilterCancel->setFocusPolicy(Qt::NoFocus);
        airFilterCancel->setStyleSheet(QLatin1String("QPushButton {\n"
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
        airFilterTitle = new QLabel(AirFilterWindowClinical);
        airFilterTitle->setObjectName(QStringLiteral("airFilterTitle"));
        airFilterTitle->setGeometry(QRect(24, 16, 231, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(11);
        airFilterTitle->setFont(font1);
        airFilterTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        airFilterTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        airFilterAccept = new QPushButton(AirFilterWindowClinical);
        airFilterAccept->setObjectName(QStringLiteral("airFilterAccept"));
        airFilterAccept->setGeometry(QRect(3, 170, 170, 40));
        airFilterAccept->setFont(font);
        airFilterAccept->setFocusPolicy(Qt::NoFocus);
        airFilterAccept->setStyleSheet(QLatin1String("QPushButton {\n"
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
        hepaRadio = new QRadioButton(AirFilterWindowClinical);
        hepaRadio->setObjectName(QStringLiteral("hepaRadio"));
        hepaRadio->setGeometry(QRect(88, 85, 131, 25));
        hepaRadio->setFocusPolicy(Qt::NoFocus);
        hepaRadio->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        frame = new QFrame(AirFilterWindowClinical);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        standardRadio->raise();
        airFilterCancel->raise();
        airFilterTitle->raise();
        airFilterAccept->raise();
        hepaRadio->raise();

        retranslateUi(AirFilterWindowClinical);

        QMetaObject::connectSlotsByName(AirFilterWindowClinical);
    } // setupUi

    void retranslateUi(QDialog *AirFilterWindowClinical)
    {
        AirFilterWindowClinical->setWindowTitle(QApplication::translate("AirFilterWindowClinical", "Dialog", nullptr));
        standardRadio->setText(QApplication::translate("AirFilterWindowClinical", "Standard", nullptr));
        airFilterCancel->setText(QApplication::translate("AirFilterWindowClinical", "Cancel", nullptr));
        airFilterTitle->setText(QApplication::translate("AirFilterWindowClinical", "Air Filter", nullptr));
        airFilterAccept->setText(QApplication::translate("AirFilterWindowClinical", "Accept", nullptr));
        hepaRadio->setText(QApplication::translate("AirFilterWindowClinical", "HEPA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AirFilterWindowClinical: public Ui_AirFilterWindowClinical {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIRFILTERWINDOWCLINICAL_H
