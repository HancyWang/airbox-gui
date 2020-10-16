/********************************************************************************
** Form generated from reading UI file 'restoredefaultswindowclinical.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESTOREDEFAULTSWINDOWCLINICAL_H
#define UI_RESTOREDEFAULTSWINDOWCLINICAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RestoreDefaultsWindowClinical
{
public:
    QPushButton *restoreFactoryNo;
    QLabel *restoreFactoryTitle;
    QPushButton *restoreFactoryYes;
    QLabel *restoreFactoryWarning;
    QFrame *frame;

    void setupUi(QDialog *RestoreDefaultsWindowClinical)
    {
        if (RestoreDefaultsWindowClinical->objectName().isEmpty())
            RestoreDefaultsWindowClinical->setObjectName(QStringLiteral("RestoreDefaultsWindowClinical"));
        RestoreDefaultsWindowClinical->resize(349, 213);
        RestoreDefaultsWindowClinical->setStyleSheet(QStringLiteral(""));
        restoreFactoryNo = new QPushButton(RestoreDefaultsWindowClinical);
        restoreFactoryNo->setObjectName(QStringLiteral("restoreFactoryNo"));
        restoreFactoryNo->setGeometry(QRect(176, 170, 170, 40));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(12);
        restoreFactoryNo->setFont(font);
        restoreFactoryNo->setFocusPolicy(Qt::NoFocus);
        restoreFactoryNo->setStyleSheet(QLatin1String("QPushButton {\n"
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
        restoreFactoryTitle = new QLabel(RestoreDefaultsWindowClinical);
        restoreFactoryTitle->setObjectName(QStringLiteral("restoreFactoryTitle"));
        restoreFactoryTitle->setGeometry(QRect(24, 16, 161, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(11);
        restoreFactoryTitle->setFont(font1);
        restoreFactoryTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        restoreFactoryYes = new QPushButton(RestoreDefaultsWindowClinical);
        restoreFactoryYes->setObjectName(QStringLiteral("restoreFactoryYes"));
        restoreFactoryYes->setGeometry(QRect(3, 170, 170, 40));
        restoreFactoryYes->setFont(font);
        restoreFactoryYes->setFocusPolicy(Qt::NoFocus);
        restoreFactoryYes->setStyleSheet(QLatin1String("QPushButton {\n"
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
        restoreFactoryWarning = new QLabel(RestoreDefaultsWindowClinical);
        restoreFactoryWarning->setObjectName(QStringLiteral("restoreFactoryWarning"));
        restoreFactoryWarning->setGeometry(QRect(48, 66, 251, 61));
        restoreFactoryWarning->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        restoreFactoryWarning->setAlignment(Qt::AlignCenter);
        frame = new QFrame(RestoreDefaultsWindowClinical);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        restoreFactoryNo->raise();
        restoreFactoryTitle->raise();
        restoreFactoryYes->raise();
        restoreFactoryWarning->raise();

        retranslateUi(RestoreDefaultsWindowClinical);

        QMetaObject::connectSlotsByName(RestoreDefaultsWindowClinical);
    } // setupUi

    void retranslateUi(QDialog *RestoreDefaultsWindowClinical)
    {
        RestoreDefaultsWindowClinical->setWindowTitle(QApplication::translate("RestoreDefaultsWindowClinical", "Dialog", nullptr));
        restoreFactoryNo->setText(QApplication::translate("RestoreDefaultsWindowClinical", "No", nullptr));
        restoreFactoryTitle->setText(QApplication::translate("RestoreDefaultsWindowClinical", "Restore Defaults", nullptr));
        restoreFactoryYes->setText(QApplication::translate("RestoreDefaultsWindowClinical", "Yes", nullptr));
        restoreFactoryWarning->setText(QApplication::translate("RestoreDefaultsWindowClinical", "Do You Really Want to \n"
"Restore Factory Defaults?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RestoreDefaultsWindowClinical: public Ui_RestoreDefaultsWindowClinical {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESTOREDEFAULTSWINDOWCLINICAL_H
