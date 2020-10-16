/********************************************************************************
** Form generated from reading UI file 'displaysettingssettingsbasic.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYSETTINGSSETTINGSBASIC_H
#define UI_DISPLAYSETTINGSSETTINGSBASIC_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DisplaySettingsSettingsBasic
{
public:
    QPushButton *backDisplaySettings;
    QLabel *displaySettingsTitle;

    void setupUi(QDialog *DisplaySettingsSettingsBasic)
    {
        if (DisplaySettingsSettingsBasic->objectName().isEmpty())
            DisplaySettingsSettingsBasic->setObjectName(QStringLiteral("DisplaySettingsSettingsBasic"));
        DisplaySettingsSettingsBasic->resize(480, 272);
        DisplaySettingsSettingsBasic->setStyleSheet(QStringLiteral("background-color: rgb(49, 49, 49);"));
        backDisplaySettings = new QPushButton(DisplaySettingsSettingsBasic);
        backDisplaySettings->setObjectName(QStringLiteral("backDisplaySettings"));
        backDisplaySettings->setGeometry(QRect(13, 28, 30, 30));
        backDisplaySettings->setFocusPolicy(Qt::NoFocus);
        backDisplaySettings->setStyleSheet(QLatin1String("border:none;\n"
"border-radius:3px;\n"
"background-color: rgb(70, 70, 73);border:none;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        backDisplaySettings->setIcon(icon);
        displaySettingsTitle = new QLabel(DisplaySettingsSettingsBasic);
        displaySettingsTitle->setObjectName(QStringLiteral("displaySettingsTitle"));
        displaySettingsTitle->setGeometry(QRect(70, 30, 261, 23));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(14);
        displaySettingsTitle->setFont(font);
        displaySettingsTitle->setStyleSheet(QStringLiteral("color:#1788C3;"));

        retranslateUi(DisplaySettingsSettingsBasic);

        QMetaObject::connectSlotsByName(DisplaySettingsSettingsBasic);
    } // setupUi

    void retranslateUi(QDialog *DisplaySettingsSettingsBasic)
    {
        DisplaySettingsSettingsBasic->setWindowTitle(QApplication::translate("DisplaySettingsSettingsBasic", "Dialog", nullptr));
        backDisplaySettings->setText(QString());
        displaySettingsTitle->setText(QApplication::translate("DisplaySettingsSettingsBasic", "Display Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DisplaySettingsSettingsBasic: public Ui_DisplaySettingsSettingsBasic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYSETTINGSSETTINGSBASIC_H
