/********************************************************************************
** Form generated from reading UI file 'configurationwindowclinical.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGURATIONWINDOWCLINICAL_H
#define UI_CONFIGURATIONWINDOWCLINICAL_H

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

class Ui_ConfigurationWindowClinical
{
public:
    QPushButton *backConfiguration;
    QLabel *titleConfiguration;
    QScrollArea *scrollAreaConfiguration;
    QWidget *scrollAreaWidgetContentsConfiguration;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayoutConfiguration;

    void setupUi(QDialog *ConfigurationWindowClinical)
    {
        if (ConfigurationWindowClinical->objectName().isEmpty())
            ConfigurationWindowClinical->setObjectName(QStringLiteral("ConfigurationWindowClinical"));
        ConfigurationWindowClinical->resize(480, 272);
        ConfigurationWindowClinical->setStyleSheet(QStringLiteral("background-color: rgb(49, 49, 49);"));
        backConfiguration = new QPushButton(ConfigurationWindowClinical);
        backConfiguration->setObjectName(QStringLiteral("backConfiguration"));
        backConfiguration->setGeometry(QRect(6, 25, 38, 30));
        backConfiguration->setFocusPolicy(Qt::NoFocus);
        backConfiguration->setStyleSheet(QLatin1String("border:none;\n"
"border-radius:3px;\n"
"background-color: rgb(70, 70, 73);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        backConfiguration->setIcon(icon);
        titleConfiguration = new QLabel(ConfigurationWindowClinical);
        titleConfiguration->setObjectName(QStringLiteral("titleConfiguration"));
        titleConfiguration->setGeometry(QRect(80, 30, 171, 25));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(14);
        titleConfiguration->setFont(font);
        titleConfiguration->setStyleSheet(QLatin1String("color:#1788c3\n"
""));
        scrollAreaConfiguration = new QScrollArea(ConfigurationWindowClinical);
        scrollAreaConfiguration->setObjectName(QStringLiteral("scrollAreaConfiguration"));
        scrollAreaConfiguration->setGeometry(QRect(0, 64, 480, 209));
        scrollAreaConfiguration->setStyleSheet(QLatin1String(" QScrollBar:vertical {\n"
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
        scrollAreaConfiguration->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollAreaConfiguration->setWidgetResizable(true);
        scrollAreaWidgetContentsConfiguration = new QWidget();
        scrollAreaWidgetContentsConfiguration->setObjectName(QStringLiteral("scrollAreaWidgetContentsConfiguration"));
        scrollAreaWidgetContentsConfiguration->setGeometry(QRect(0, 0, 464, 207));
        verticalLayoutWidget = new QWidget(scrollAreaWidgetContentsConfiguration);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 9, 461, 201));
        verticalLayoutConfiguration = new QVBoxLayout(verticalLayoutWidget);
        verticalLayoutConfiguration->setObjectName(QStringLiteral("verticalLayoutConfiguration"));
        verticalLayoutConfiguration->setContentsMargins(60, 5, 60, 5);
        scrollAreaConfiguration->setWidget(scrollAreaWidgetContentsConfiguration);

        retranslateUi(ConfigurationWindowClinical);

        QMetaObject::connectSlotsByName(ConfigurationWindowClinical);
    } // setupUi

    void retranslateUi(QDialog *ConfigurationWindowClinical)
    {
        ConfigurationWindowClinical->setWindowTitle(QApplication::translate("ConfigurationWindowClinical", "Dialog", nullptr));
        backConfiguration->setText(QString());
        titleConfiguration->setText(QApplication::translate("ConfigurationWindowClinical", "Configuration", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfigurationWindowClinical: public Ui_ConfigurationWindowClinical {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURATIONWINDOWCLINICAL_H
