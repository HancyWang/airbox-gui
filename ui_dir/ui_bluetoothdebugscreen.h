/********************************************************************************
** Form generated from reading UI file 'bluetoothdebugscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLUETOOTHDEBUGSCREEN_H
#define UI_BLUETOOTHDEBUGSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_BluetoothDebugScreen
{
public:
    QLabel *titleBluetoothDebug;
    QPushButton *backBluetoothDebug;
    QListWidget *bluetoothListWidget;
    QPushButton *incrementButton;
    QPushButton *decrementButton;
    QLabel *textTransferSize;

    void setupUi(QDialog *BluetoothDebugScreen)
    {
        if (BluetoothDebugScreen->objectName().isEmpty())
            BluetoothDebugScreen->setObjectName(QStringLiteral("BluetoothDebugScreen"));
        BluetoothDebugScreen->resize(480, 272);
        BluetoothDebugScreen->setStyleSheet(QStringLiteral("background-color: rgb(49, 49, 49);"));
        titleBluetoothDebug = new QLabel(BluetoothDebugScreen);
        titleBluetoothDebug->setObjectName(QStringLiteral("titleBluetoothDebug"));
        titleBluetoothDebug->setGeometry(QRect(70, 30, 231, 30));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(14);
        titleBluetoothDebug->setFont(font);
        titleBluetoothDebug->setStyleSheet(QLatin1String("color:#1788c3\n"
""));
        backBluetoothDebug = new QPushButton(BluetoothDebugScreen);
        backBluetoothDebug->setObjectName(QStringLiteral("backBluetoothDebug"));
        backBluetoothDebug->setGeometry(QRect(10, 30, 38, 30));
        backBluetoothDebug->setFocusPolicy(Qt::NoFocus);
        backBluetoothDebug->setStyleSheet(QLatin1String("border:none;\n"
"border-radius:3px;\n"
"background-color: rgb(70, 70, 73);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        backBluetoothDebug->setIcon(icon);
        bluetoothListWidget = new QListWidget(BluetoothDebugScreen);
        bluetoothListWidget->setObjectName(QStringLiteral("bluetoothListWidget"));
        bluetoothListWidget->setGeometry(QRect(10, 70, 461, 192));
        bluetoothListWidget->setStyleSheet(QLatin1String(" QScrollBar:vertical {\n"
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
        bluetoothListWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        incrementButton = new QPushButton(BluetoothDebugScreen);
        incrementButton->setObjectName(QStringLiteral("incrementButton"));
        incrementButton->setGeometry(QRect(418, 30, 61, 41));
        incrementButton->setFocusPolicy(Qt::NoFocus);
        decrementButton = new QPushButton(BluetoothDebugScreen);
        decrementButton->setObjectName(QStringLiteral("decrementButton"));
        decrementButton->setGeometry(QRect(310, 30, 61, 41));
        decrementButton->setFocusPolicy(Qt::NoFocus);
        textTransferSize = new QLabel(BluetoothDebugScreen);
        textTransferSize->setObjectName(QStringLiteral("textTransferSize"));
        textTransferSize->setGeometry(QRect(372, 35, 41, 30));
        textTransferSize->setFont(font);
        textTransferSize->setStyleSheet(QLatin1String("color:#1788c3\n"
""));

        retranslateUi(BluetoothDebugScreen);

        QMetaObject::connectSlotsByName(BluetoothDebugScreen);
    } // setupUi

    void retranslateUi(QDialog *BluetoothDebugScreen)
    {
        BluetoothDebugScreen->setWindowTitle(QApplication::translate("BluetoothDebugScreen", "Dialog", nullptr));
        titleBluetoothDebug->setText(QApplication::translate("BluetoothDebugScreen", "Bluetooth Debug Screen", nullptr));
        backBluetoothDebug->setText(QString());
        incrementButton->setText(QApplication::translate("BluetoothDebugScreen", "+", nullptr));
        decrementButton->setText(QApplication::translate("BluetoothDebugScreen", "-", nullptr));
        textTransferSize->setText(QApplication::translate("BluetoothDebugScreen", "20", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BluetoothDebugScreen: public Ui_BluetoothDebugScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLUETOOTHDEBUGSCREEN_H
