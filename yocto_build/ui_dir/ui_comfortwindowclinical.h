/********************************************************************************
** Form generated from reading UI file 'comfortwindowclinical.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMFORTWINDOWCLINICAL_H
#define UI_COMFORTWINDOWCLINICAL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ComfortWindowClinical
{
public:
    QLabel *titleComfort;
    QPushButton *backComfort;

    void setupUi(QDialog *ComfortWindowClinical)
    {
        if (ComfortWindowClinical->objectName().isEmpty())
            ComfortWindowClinical->setObjectName(QStringLiteral("ComfortWindowClinical"));
        ComfortWindowClinical->resize(480, 272);
        ComfortWindowClinical->setStyleSheet(QStringLiteral("background-color: rgb(49, 49, 49);"));
        titleComfort = new QLabel(ComfortWindowClinical);
        titleComfort->setObjectName(QStringLiteral("titleComfort"));
        titleComfort->setGeometry(QRect(80, 30, 171, 25));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(14);
        titleComfort->setFont(font);
        titleComfort->setStyleSheet(QLatin1String("color:#1788c3\n"
""));
        backComfort = new QPushButton(ComfortWindowClinical);
        backComfort->setObjectName(QStringLiteral("backComfort"));
        backComfort->setGeometry(QRect(6, 25, 38, 30));
        backComfort->setFocusPolicy(Qt::NoFocus);
        backComfort->setStyleSheet(QLatin1String("border:none;\n"
"border-radius:3px;\n"
"background-color: rgb(70, 70, 73);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        backComfort->setIcon(icon);

        retranslateUi(ComfortWindowClinical);

        QMetaObject::connectSlotsByName(ComfortWindowClinical);
    } // setupUi

    void retranslateUi(QDialog *ComfortWindowClinical)
    {
        ComfortWindowClinical->setWindowTitle(QApplication::translate("ComfortWindowClinical", "Dialog", nullptr));
        titleComfort->setText(QApplication::translate("ComfortWindowClinical", "Comfort", nullptr));
        backComfort->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ComfortWindowClinical: public Ui_ComfortWindowClinical {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMFORTWINDOWCLINICAL_H
