/********************************************************************************
** Form generated from reading UI file 'parametertunningscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETERTUNNINGSCREEN_H
#define UI_PARAMETERTUNNINGSCREEN_H

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

class Ui_ParameterTunningScreen
{
public:
    QPushButton *backParameterTunning;
    QLabel *titleParameterTunning;
    QPushButton *paramIncrement;
    QPushButton *paramDecrement;
    QLabel *paramValue;
    QLabel *paramTitle;
    QLabel *paramUnit;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *ParameterTunningScreen)
    {
        if (ParameterTunningScreen->objectName().isEmpty())
            ParameterTunningScreen->setObjectName(QStringLiteral("ParameterTunningScreen"));
        ParameterTunningScreen->resize(480, 272);
        ParameterTunningScreen->setStyleSheet(QStringLiteral("background-color: rgb(49, 49, 49);"));
        backParameterTunning = new QPushButton(ParameterTunningScreen);
        backParameterTunning->setObjectName(QStringLiteral("backParameterTunning"));
        backParameterTunning->setGeometry(QRect(9, 31, 38, 30));
        backParameterTunning->setFocusPolicy(Qt::NoFocus);
        backParameterTunning->setStyleSheet(QLatin1String("border:none;\n"
"border-radius:3px;\n"
"background-color: rgb(70, 70, 73);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        backParameterTunning->setIcon(icon);
        titleParameterTunning = new QLabel(ParameterTunningScreen);
        titleParameterTunning->setObjectName(QStringLiteral("titleParameterTunning"));
        titleParameterTunning->setGeometry(QRect(83, 36, 291, 25));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(14);
        titleParameterTunning->setFont(font);
        titleParameterTunning->setStyleSheet(QLatin1String("color:#1788c3\n"
""));
        paramIncrement = new QPushButton(ParameterTunningScreen);
        paramIncrement->setObjectName(QStringLiteral("paramIncrement"));
        paramIncrement->setGeometry(QRect(140, 120, 66, 33));
        paramIncrement->setFont(font);
        paramIncrement->setFocusPolicy(Qt::NoFocus);
        paramIncrement->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color:#3B3B3B;\n"
"color:#BDBDBD;\n"
"border:none;\n"
"border-radius:3px;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color:#606060;\n"
"color:#BDBDBD;\n"
"border:none;\n"
"border-radius:3px;\n"
"}\n"
""));
        paramDecrement = new QPushButton(ParameterTunningScreen);
        paramDecrement->setObjectName(QStringLiteral("paramDecrement"));
        paramDecrement->setGeometry(QRect(140, 166, 66, 33));
        paramDecrement->setFont(font);
        paramDecrement->setFocusPolicy(Qt::NoFocus);
        paramDecrement->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color:#3B3B3B;\n"
"color:#BDBDBD;\n"
"border:none;\n"
"border-radius:3px;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color:#606060;\n"
"color:#BDBDBD;\n"
"border:none;\n"
"border-radius:3px;\n"
"}\n"
""));
        paramValue = new QLabel(ParameterTunningScreen);
        paramValue->setObjectName(QStringLiteral("paramValue"));
        paramValue->setGeometry(QRect(20, 120, 111, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(28);
        paramValue->setFont(font1);
        paramValue->setStyleSheet(QStringLiteral("color:#2196F3"));
        paramValue->setAlignment(Qt::AlignCenter);
        paramTitle = new QLabel(ParameterTunningScreen);
        paramTitle->setObjectName(QStringLiteral("paramTitle"));
        paramTitle->setGeometry(QRect(13, 70, 211, 41));
        QFont font2;
        font2.setFamily(QStringLiteral("Roboto"));
        font2.setPointSize(11);
        paramTitle->setFont(font2);
        paramTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        paramTitle->setAlignment(Qt::AlignCenter);
        paramUnit = new QLabel(ParameterTunningScreen);
        paramUnit->setObjectName(QStringLiteral("paramUnit"));
        paramUnit->setGeometry(QRect(50, 180, 50, 14));
        paramUnit->setStyleSheet(QStringLiteral("color:#616161"));
        paramUnit->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        scrollArea = new QScrollArea(ParameterTunningScreen);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(240, 70, 241, 201));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 239, 199));
        verticalLayoutWidget = new QWidget(scrollAreaWidgetContents);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(-1, -1, 241, 1284));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(ParameterTunningScreen);

        QMetaObject::connectSlotsByName(ParameterTunningScreen);
    } // setupUi

    void retranslateUi(QDialog *ParameterTunningScreen)
    {
        ParameterTunningScreen->setWindowTitle(QApplication::translate("ParameterTunningScreen", "Dialog", nullptr));
        backParameterTunning->setText(QString());
        titleParameterTunning->setText(QApplication::translate("ParameterTunningScreen", "Parameter Tuning Screen", nullptr));
        paramIncrement->setText(QApplication::translate("ParameterTunningScreen", "+", nullptr));
        paramDecrement->setText(QApplication::translate("ParameterTunningScreen", "-", nullptr));
        paramValue->setText(QApplication::translate("ParameterTunningScreen", "5", nullptr));
        paramTitle->setText(QApplication::translate("ParameterTunningScreen", "Snooze Time", nullptr));
        paramUnit->setText(QApplication::translate("ParameterTunningScreen", "min", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ParameterTunningScreen: public Ui_ParameterTunningScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETERTUNNINGSCREEN_H
