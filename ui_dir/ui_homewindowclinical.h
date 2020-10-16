/********************************************************************************
** Form generated from reading UI file 'homewindowclinical.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEWINDOWCLINICAL_H
#define UI_HOMEWINDOWCLINICAL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_HomeWindowClinical
{
public:
    QPushButton *frescaLogo;
    QLabel *clinicalMenuTitle;

    void setupUi(QDialog *HomeWindowClinical)
    {
        if (HomeWindowClinical->objectName().isEmpty())
            HomeWindowClinical->setObjectName(QStringLiteral("HomeWindowClinical"));
        HomeWindowClinical->resize(480, 272);
        HomeWindowClinical->setStyleSheet(QStringLiteral("background-color: rgb(49, 49, 49);"));
        frescaLogo = new QPushButton(HomeWindowClinical);
        frescaLogo->setObjectName(QStringLiteral("frescaLogo"));
        frescaLogo->setGeometry(QRect(135, 30, 210, 67));
        frescaLogo->setFocusPolicy(Qt::NoFocus);
        frescaLogo->setStyleSheet(QStringLiteral("border:none;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/somnera.png"), QSize(), QIcon::Normal, QIcon::Off);
        frescaLogo->setIcon(icon);
        frescaLogo->setIconSize(QSize(210, 65));
        clinicalMenuTitle = new QLabel(HomeWindowClinical);
        clinicalMenuTitle->setObjectName(QStringLiteral("clinicalMenuTitle"));
        clinicalMenuTitle->setGeometry(QRect(24, 111, 150, 25));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(16);
        clinicalMenuTitle->setFont(font);
        clinicalMenuTitle->setStyleSheet(QLatin1String("color:#1788c3\n"
""));

        retranslateUi(HomeWindowClinical);

        QMetaObject::connectSlotsByName(HomeWindowClinical);
    } // setupUi

    void retranslateUi(QDialog *HomeWindowClinical)
    {
        HomeWindowClinical->setWindowTitle(QApplication::translate("HomeWindowClinical", "Dialog", nullptr));
        frescaLogo->setText(QString());
        clinicalMenuTitle->setText(QApplication::translate("HomeWindowClinical", "Clinical Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomeWindowClinical: public Ui_HomeWindowClinical {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEWINDOWCLINICAL_H
