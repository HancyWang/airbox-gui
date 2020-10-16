/********************************************************************************
** Form generated from reading UI file 'backgroundwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BACKGROUNDWINDOW_H
#define UI_BACKGROUNDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BackgroundWindow
{
public:
    QWidget *centralWidget;

    void setupUi(QMainWindow *BackgroundWindow)
    {
        if (BackgroundWindow->objectName().isEmpty())
            BackgroundWindow->setObjectName(QStringLiteral("BackgroundWindow"));
        BackgroundWindow->resize(480, 272);
        BackgroundWindow->setMaximumSize(QSize(480, 272));
        BackgroundWindow->setStyleSheet(QStringLiteral("background-color: rgb(49, 49, 49);"));
        centralWidget = new QWidget(BackgroundWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        BackgroundWindow->setCentralWidget(centralWidget);

        retranslateUi(BackgroundWindow);

        QMetaObject::connectSlotsByName(BackgroundWindow);
    } // setupUi

    void retranslateUi(QMainWindow *BackgroundWindow)
    {
        BackgroundWindow->setWindowTitle(QApplication::translate("BackgroundWindow", "BackgroundWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BackgroundWindow: public Ui_BackgroundWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BACKGROUNDWINDOW_H
