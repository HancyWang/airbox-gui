/********************************************************************************
** Form generated from reading UI file 'manufacturingsetupscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANUFACTURINGSETUPSCREEN_H
#define UI_MANUFACTURINGSETUPSCREEN_H

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

class Ui_ManufacturingSetupScreen
{
public:
    QPushButton *backManufacturingSetup;
    QLabel *titleManufacturingSetup;
    QScrollArea *scrollAreaManufacturingSetup;
    QWidget *scrollAreaWidgetContentsManufacturingSetup;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayoutManufacturingSetup;

    void setupUi(QDialog *ManufacturingSetupScreen)
    {
        if (ManufacturingSetupScreen->objectName().isEmpty())
            ManufacturingSetupScreen->setObjectName(QStringLiteral("ManufacturingSetupScreen"));
        ManufacturingSetupScreen->resize(480, 272);
        ManufacturingSetupScreen->setStyleSheet(QStringLiteral("background-color: rgb(49, 49, 49);"));
        backManufacturingSetup = new QPushButton(ManufacturingSetupScreen);
        backManufacturingSetup->setObjectName(QStringLiteral("backManufacturingSetup"));
        backManufacturingSetup->setGeometry(QRect(9, 31, 38, 30));
        backManufacturingSetup->setFocusPolicy(Qt::NoFocus);
        backManufacturingSetup->setStyleSheet(QLatin1String("border:none;\n"
"border-radius:3px;\n"
"background-color: rgb(70, 70, 73);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        backManufacturingSetup->setIcon(icon);
        titleManufacturingSetup = new QLabel(ManufacturingSetupScreen);
        titleManufacturingSetup->setObjectName(QStringLiteral("titleManufacturingSetup"));
        titleManufacturingSetup->setGeometry(QRect(83, 36, 231, 25));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(14);
        titleManufacturingSetup->setFont(font);
        titleManufacturingSetup->setStyleSheet(QLatin1String("color:#1788c3\n"
""));
        scrollAreaManufacturingSetup = new QScrollArea(ManufacturingSetupScreen);
        scrollAreaManufacturingSetup->setObjectName(QStringLiteral("scrollAreaManufacturingSetup"));
        scrollAreaManufacturingSetup->setGeometry(QRect(0, 70, 480, 200));
        scrollAreaManufacturingSetup->setStyleSheet(QLatin1String(" QScrollBar:vertical {\n"
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
        scrollAreaManufacturingSetup->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollAreaManufacturingSetup->setWidgetResizable(true);
        scrollAreaWidgetContentsManufacturingSetup = new QWidget();
        scrollAreaWidgetContentsManufacturingSetup->setObjectName(QStringLiteral("scrollAreaWidgetContentsManufacturingSetup"));
        scrollAreaWidgetContentsManufacturingSetup->setGeometry(QRect(0, 0, 464, 198));
        verticalLayoutWidget = new QWidget(scrollAreaWidgetContentsManufacturingSetup);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 9, 461, 201));
        verticalLayoutManufacturingSetup = new QVBoxLayout(verticalLayoutWidget);
        verticalLayoutManufacturingSetup->setObjectName(QStringLiteral("verticalLayoutManufacturingSetup"));
        verticalLayoutManufacturingSetup->setContentsMargins(60, 5, 60, 5);
        scrollAreaManufacturingSetup->setWidget(scrollAreaWidgetContentsManufacturingSetup);

        retranslateUi(ManufacturingSetupScreen);

        QMetaObject::connectSlotsByName(ManufacturingSetupScreen);
    } // setupUi

    void retranslateUi(QDialog *ManufacturingSetupScreen)
    {
        ManufacturingSetupScreen->setWindowTitle(QApplication::translate("ManufacturingSetupScreen", "Dialog", nullptr));
        backManufacturingSetup->setText(QString());
        titleManufacturingSetup->setText(QApplication::translate("ManufacturingSetupScreen", "Manufacturing Setup", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManufacturingSetupScreen: public Ui_ManufacturingSetupScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANUFACTURINGSETUPSCREEN_H
