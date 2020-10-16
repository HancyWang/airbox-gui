/********************************************************************************
** Form generated from reading UI file 'settingswindowbasic.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOWBASIC_H
#define UI_SETTINGSWINDOWBASIC_H

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

class Ui_SettingsWindow
{
public:
    QPushButton *homeSettings;
    QLabel *titleSettings;
    QScrollArea *scrollAreaSettings;
    QWidget *scrollAreaWidgetContentsSettings;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayoutSettings;
    QPushButton *pushButton;

    void setupUi(QDialog *SettingsWindow)
    {
        if (SettingsWindow->objectName().isEmpty())
            SettingsWindow->setObjectName(QStringLiteral("SettingsWindow"));
        SettingsWindow->resize(480, 272);
        SettingsWindow->setStyleSheet(QStringLiteral("background-color: rgb(49, 49, 49);"));
        homeSettings = new QPushButton(SettingsWindow);
        homeSettings->setObjectName(QStringLiteral("homeSettings"));
        homeSettings->setGeometry(QRect(9, 24, 38, 30));
        homeSettings->setFocusPolicy(Qt::NoFocus);
        homeSettings->setStyleSheet(QLatin1String("border:none;\n"
"border-radius:3px;\n"
"background-color: rgb(70, 70, 73);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/home.png"), QSize(), QIcon::Normal, QIcon::Off);
        homeSettings->setIcon(icon);
        titleSettings = new QLabel(SettingsWindow);
        titleSettings->setObjectName(QStringLiteral("titleSettings"));
        titleSettings->setGeometry(QRect(83, 29, 108, 25));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(14);
        titleSettings->setFont(font);
        titleSettings->setStyleSheet(QLatin1String("color:#1788c3\n"
""));
        scrollAreaSettings = new QScrollArea(SettingsWindow);
        scrollAreaSettings->setObjectName(QStringLiteral("scrollAreaSettings"));
        scrollAreaSettings->setGeometry(QRect(0, 63, 480, 209));
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
        pushButton = new QPushButton(SettingsWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(328, 30, 141, 25));
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->setStyleSheet(QLatin1String("border:none;\n"
"border-radius:3px;\n"
"background-color: rgb(70, 70, 73);color:#1788c3\n"
""));

        retranslateUi(SettingsWindow);

        QMetaObject::connectSlotsByName(SettingsWindow);
    } // setupUi

    void retranslateUi(QDialog *SettingsWindow)
    {
        SettingsWindow->setWindowTitle(QApplication::translate("SettingsWindow", "Dialog", nullptr));
        homeSettings->setText(QString());
        titleSettings->setText(QApplication::translate("SettingsWindow", "Settings", nullptr));
        pushButton->setText(QApplication::translate("SettingsWindow", "Debug BLE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsWindow: public Ui_SettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOWBASIC_H
