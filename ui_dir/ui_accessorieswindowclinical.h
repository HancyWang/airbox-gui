/********************************************************************************
** Form generated from reading UI file 'accessorieswindowclinical.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCESSORIESWINDOWCLINICAL_H
#define UI_ACCESSORIESWINDOWCLINICAL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AccessoriesWindowClinical
{
public:
    QPushButton *backAccessories;
    QLabel *titleAccessories;

    void setupUi(QDialog *AccessoriesWindowClinical)
    {
        if (AccessoriesWindowClinical->objectName().isEmpty())
            AccessoriesWindowClinical->setObjectName(QStringLiteral("AccessoriesWindowClinical"));
        AccessoriesWindowClinical->resize(480, 272);
        AccessoriesWindowClinical->setStyleSheet(QStringLiteral("background-color: rgb(49, 49, 49);"));
        backAccessories = new QPushButton(AccessoriesWindowClinical);
        backAccessories->setObjectName(QStringLiteral("backAccessories"));
        backAccessories->setGeometry(QRect(6, 25, 38, 30));
        backAccessories->setFocusPolicy(Qt::NoFocus);
        backAccessories->setStyleSheet(QLatin1String("border:none;\n"
"border-radius:3px;\n"
"background-color: rgb(70, 70, 73);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        backAccessories->setIcon(icon);
        titleAccessories = new QLabel(AccessoriesWindowClinical);
        titleAccessories->setObjectName(QStringLiteral("titleAccessories"));
        titleAccessories->setGeometry(QRect(80, 30, 171, 25));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(14);
        titleAccessories->setFont(font);
        titleAccessories->setStyleSheet(QLatin1String("color:#1788c3\n"
""));

        retranslateUi(AccessoriesWindowClinical);

        QMetaObject::connectSlotsByName(AccessoriesWindowClinical);
    } // setupUi

    void retranslateUi(QDialog *AccessoriesWindowClinical)
    {
        AccessoriesWindowClinical->setWindowTitle(QApplication::translate("AccessoriesWindowClinical", "Dialog", nullptr));
        backAccessories->setText(QString());
        titleAccessories->setText(QApplication::translate("AccessoriesWindowClinical", "Accessories", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AccessoriesWindowClinical: public Ui_AccessoriesWindowClinical {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCESSORIESWINDOWCLINICAL_H
