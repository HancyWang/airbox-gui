/********************************************************************************
** Form generated from reading UI file 'optionswindowclinical.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSWINDOWCLINICAL_H
#define UI_OPTIONSWINDOWCLINICAL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_OptionsWindowClinical
{
public:
    QPushButton *backOptions;
    QLabel *titleOptions;

    void setupUi(QDialog *OptionsWindowClinical)
    {
        if (OptionsWindowClinical->objectName().isEmpty())
            OptionsWindowClinical->setObjectName(QStringLiteral("OptionsWindowClinical"));
        OptionsWindowClinical->resize(480, 272);
        OptionsWindowClinical->setStyleSheet(QStringLiteral("background-color: rgb(49, 49, 49);"));
        backOptions = new QPushButton(OptionsWindowClinical);
        backOptions->setObjectName(QStringLiteral("backOptions"));
        backOptions->setGeometry(QRect(6, 25, 38, 30));
        backOptions->setFocusPolicy(Qt::NoFocus);
        backOptions->setStyleSheet(QLatin1String("border:none;\n"
"border-radius:3px;\n"
"background-color: rgb(70, 70, 73);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        backOptions->setIcon(icon);
        titleOptions = new QLabel(OptionsWindowClinical);
        titleOptions->setObjectName(QStringLiteral("titleOptions"));
        titleOptions->setGeometry(QRect(80, 30, 171, 25));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(14);
        titleOptions->setFont(font);
        titleOptions->setStyleSheet(QLatin1String("color:#1788c3\n"
""));

        retranslateUi(OptionsWindowClinical);

        QMetaObject::connectSlotsByName(OptionsWindowClinical);
    } // setupUi

    void retranslateUi(QDialog *OptionsWindowClinical)
    {
        OptionsWindowClinical->setWindowTitle(QApplication::translate("OptionsWindowClinical", "Dialog", nullptr));
        backOptions->setText(QString());
        titleOptions->setText(QApplication::translate("OptionsWindowClinical", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OptionsWindowClinical: public Ui_OptionsWindowClinical {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSWINDOWCLINICAL_H
