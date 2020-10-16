/********************************************************************************
** Form generated from reading UI file 'manufacturingoptionsscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANUFACTURINGOPTIONSSCREEN_H
#define UI_MANUFACTURINGOPTIONSSCREEN_H

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

class Ui_ManufacturingOptionsScreen
{
public:
    QLabel *titleManufacturingOptions;
    QPushButton *backManufacturingOptions;
    QScrollArea *scrollAreaConfiguration;
    QWidget *scrollAreaWidgetContentsConfiguration;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayoutConfiguration;

    void setupUi(QDialog *ManufacturingOptionsScreen)
    {
        if (ManufacturingOptionsScreen->objectName().isEmpty())
            ManufacturingOptionsScreen->setObjectName(QStringLiteral("ManufacturingOptionsScreen"));
        ManufacturingOptionsScreen->resize(480, 272);
        ManufacturingOptionsScreen->setStyleSheet(QStringLiteral("background-color: rgb(49, 49, 49);"));
        titleManufacturingOptions = new QLabel(ManufacturingOptionsScreen);
        titleManufacturingOptions->setObjectName(QStringLiteral("titleManufacturingOptions"));
        titleManufacturingOptions->setGeometry(QRect(85, 25, 271, 30));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(14);
        titleManufacturingOptions->setFont(font);
        titleManufacturingOptions->setStyleSheet(QLatin1String("color:#1788c3\n"
""));
        backManufacturingOptions = new QPushButton(ManufacturingOptionsScreen);
        backManufacturingOptions->setObjectName(QStringLiteral("backManufacturingOptions"));
        backManufacturingOptions->setGeometry(QRect(9, 25, 38, 30));
        backManufacturingOptions->setFocusPolicy(Qt::NoFocus);
        backManufacturingOptions->setStyleSheet(QLatin1String("border:none;\n"
"border-radius:3px;\n"
"background-color: rgb(70, 70, 73);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        backManufacturingOptions->setIcon(icon);
        scrollAreaConfiguration = new QScrollArea(ManufacturingOptionsScreen);
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

        retranslateUi(ManufacturingOptionsScreen);

        QMetaObject::connectSlotsByName(ManufacturingOptionsScreen);
    } // setupUi

    void retranslateUi(QDialog *ManufacturingOptionsScreen)
    {
        ManufacturingOptionsScreen->setWindowTitle(QApplication::translate("ManufacturingOptionsScreen", "Dialog", nullptr));
        titleManufacturingOptions->setText(QApplication::translate("ManufacturingOptionsScreen", "Manufacturing Options", nullptr));
        backManufacturingOptions->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ManufacturingOptionsScreen: public Ui_ManufacturingOptionsScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANUFACTURINGOPTIONSSCREEN_H
