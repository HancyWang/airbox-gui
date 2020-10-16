/********************************************************************************
** Form generated from reading UI file 'erasedataconfigurationclinical.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERASEDATACONFIGURATIONCLINICAL_H
#define UI_ERASEDATACONFIGURATIONCLINICAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EraseDataConfigurationClinical
{
public:
    QLabel *eraseDataTitle;
    QPushButton *eraseDataNo;
    QLabel *eraseDataWarning;
    QPushButton *eraseDataYes;
    QFrame *frame;

    void setupUi(QDialog *EraseDataConfigurationClinical)
    {
        if (EraseDataConfigurationClinical->objectName().isEmpty())
            EraseDataConfigurationClinical->setObjectName(QStringLiteral("EraseDataConfigurationClinical"));
        EraseDataConfigurationClinical->resize(349, 213);
        EraseDataConfigurationClinical->setStyleSheet(QStringLiteral(""));
        eraseDataTitle = new QLabel(EraseDataConfigurationClinical);
        eraseDataTitle->setObjectName(QStringLiteral("eraseDataTitle"));
        eraseDataTitle->setGeometry(QRect(24, 16, 161, 31));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(11);
        eraseDataTitle->setFont(font);
        eraseDataTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        eraseDataNo = new QPushButton(EraseDataConfigurationClinical);
        eraseDataNo->setObjectName(QStringLiteral("eraseDataNo"));
        eraseDataNo->setGeometry(QRect(176, 170, 170, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(12);
        eraseDataNo->setFont(font1);
        eraseDataNo->setFocusPolicy(Qt::NoFocus);
        eraseDataNo->setStyleSheet(QLatin1String("QPushButton {\n"
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
        eraseDataWarning = new QLabel(EraseDataConfigurationClinical);
        eraseDataWarning->setObjectName(QStringLiteral("eraseDataWarning"));
        eraseDataWarning->setGeometry(QRect(48, 66, 251, 61));
        eraseDataWarning->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        eraseDataWarning->setAlignment(Qt::AlignCenter);
        eraseDataYes = new QPushButton(EraseDataConfigurationClinical);
        eraseDataYes->setObjectName(QStringLiteral("eraseDataYes"));
        eraseDataYes->setGeometry(QRect(3, 170, 170, 40));
        eraseDataYes->setFont(font1);
        eraseDataYes->setFocusPolicy(Qt::NoFocus);
        eraseDataYes->setStyleSheet(QLatin1String("QPushButton {\n"
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
        frame = new QFrame(EraseDataConfigurationClinical);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        eraseDataTitle->raise();
        eraseDataNo->raise();
        eraseDataWarning->raise();
        eraseDataYes->raise();

        retranslateUi(EraseDataConfigurationClinical);

        QMetaObject::connectSlotsByName(EraseDataConfigurationClinical);
    } // setupUi

    void retranslateUi(QDialog *EraseDataConfigurationClinical)
    {
        EraseDataConfigurationClinical->setWindowTitle(QApplication::translate("EraseDataConfigurationClinical", "Dialog", nullptr));
        eraseDataTitle->setText(QApplication::translate("EraseDataConfigurationClinical", "Erase Data", nullptr));
        eraseDataNo->setText(QApplication::translate("EraseDataConfigurationClinical", "No", nullptr));
        eraseDataWarning->setText(QApplication::translate("EraseDataConfigurationClinical", "Do You Really Want to \n"
"Erase All Data?", nullptr));
        eraseDataYes->setText(QApplication::translate("EraseDataConfigurationClinical", "Yes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EraseDataConfigurationClinical: public Ui_EraseDataConfigurationClinical {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERASEDATACONFIGURATIONCLINICAL_H
