/********************************************************************************
** Form generated from reading UI file 'settingswindowclinical.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOWCLINICAL_H
#define UI_SETTINGSWINDOWCLINICAL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsWindowClinical
{
public:
    QPushButton *homeSettings;
    QScrollArea *scrollAreaSettings;
    QWidget *scrollAreaWidgetContentsSettings;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayoutSettings;
    QLabel *titleSettings;

    void setupUi(QDialog *SettingsWindowClinical)
    {
        if (SettingsWindowClinical->objectName().isEmpty())
            SettingsWindowClinical->setObjectName(QStringLiteral("SettingsWindowClinical"));
        SettingsWindowClinical->resize(480, 272);
        SettingsWindowClinical->setStyleSheet(QStringLiteral("background-color: rgb(49, 49, 49);"));
        homeSettings = new QPushButton(SettingsWindowClinical);
        homeSettings->setObjectName(QStringLiteral("homeSettings"));
        homeSettings->setGeometry(QRect(6, 25, 38, 30));
        homeSettings->setFocusPolicy(Qt::NoFocus);
        homeSettings->setStyleSheet(QLatin1String("border:none;\n"
"border-radius:3px;\n"
"background-color: rgb(70, 70, 73);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/home.png"), QSize(), QIcon::Normal, QIcon::Off);
        homeSettings->setIcon(icon);
        scrollAreaSettings = new QScrollArea(SettingsWindowClinical);
        scrollAreaSettings->setObjectName(QStringLiteral("scrollAreaSettings"));
        scrollAreaSettings->setGeometry(QRect(0, 64, 480, 209));
        scrollAreaSettings->setStyleSheet(QLatin1String(" QScrollBar:vertical {\n"
"     border: none;\n"
"     width: 5px;\n"
" }\n"
" QScrollBar::handle:vertical {\n"
"     background:#1788c3;\n"
"     min-height: 20px;\n"
" }\n"
" QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {\n"
"     border: 2px #1788c3;\n"
"     width: 5px;\n"
"     height: 5px;\n"
"     background: #1788c3;\n"
" }"));
        scrollAreaSettings->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollAreaSettings->setWidgetResizable(true);
        scrollAreaWidgetContentsSettings = new QWidget();
        scrollAreaWidgetContentsSettings->setObjectName(QStringLiteral("scrollAreaWidgetContentsSettings"));
        scrollAreaWidgetContentsSettings->setGeometry(QRect(0, 0, 464, 207));
        verticalLayoutWidget = new QWidget(scrollAreaWidgetContentsSettings);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 9, 461, 201));
        verticalLayoutSettings = new QVBoxLayout(verticalLayoutWidget);
        verticalLayoutSettings->setObjectName(QStringLiteral("verticalLayoutSettings"));
        verticalLayoutSettings->setContentsMargins(60, 5, 60, 5);
        scrollAreaSettings->setWidget(scrollAreaWidgetContentsSettings);
        titleSettings = new QLabel(SettingsWindowClinical);
        titleSettings->setObjectName(QStringLiteral("titleSettings"));
        titleSettings->setGeometry(QRect(80, 30, 171, 25));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(14);
        titleSettings->setFont(font);
        titleSettings->setStyleSheet(QLatin1String("color:#1788c3\n"
""));

        retranslateUi(SettingsWindowClinical);

        QMetaObject::connectSlotsByName(SettingsWindowClinical);
    } // setupUi

    void retranslateUi(QDialog *SettingsWindowClinical)
    {
        SettingsWindowClinical->setWindowTitle(QApplication::translate("SettingsWindowClinical", "Dialog", nullptr));
        homeSettings->setText(QString());
        titleSettings->setText(QApplication::translate("SettingsWindowClinical", "Clinical Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsWindowClinical: public Ui_SettingsWindowClinical {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOWCLINICAL_H
