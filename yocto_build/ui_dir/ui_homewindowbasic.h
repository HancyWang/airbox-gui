/********************************************************************************
** Form generated from reading UI file 'homewindowbasic.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEWINDOWBASIC_H
#define UI_HOMEWINDOWBASIC_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_HomeWindowBasic
{
public:
    QPushButton *frescaLogo;

    void setupUi(QDialog *HomeWindowBasic)
    {
        if (HomeWindowBasic->objectName().isEmpty())
            HomeWindowBasic->setObjectName(QStringLiteral("HomeWindowBasic"));
        HomeWindowBasic->resize(480, 272);
        HomeWindowBasic->setStyleSheet(QStringLiteral("background-color: rgb(49, 49, 49);"));
        frescaLogo = new QPushButton(HomeWindowBasic);
        frescaLogo->setObjectName(QStringLiteral("frescaLogo"));
        frescaLogo->setGeometry(QRect(135, 30, 210, 67));
        frescaLogo->setFocusPolicy(Qt::NoFocus);
        frescaLogo->setStyleSheet(QStringLiteral("border:none;"));
        frescaLogo->setText(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/somnera.png"), QSize(), QIcon::Normal, QIcon::Off);
        frescaLogo->setIcon(icon);
        frescaLogo->setIconSize(QSize(210, 65));

        retranslateUi(HomeWindowBasic);

        QMetaObject::connectSlotsByName(HomeWindowBasic);
    } // setupUi

    void retranslateUi(QDialog *HomeWindowBasic)
    {
        HomeWindowBasic->setWindowTitle(QApplication::translate("HomeWindowBasic", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomeWindowBasic: public Ui_HomeWindowBasic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEWINDOWBASIC_H
