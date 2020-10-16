/********************************************************************************
** Form generated from reading UI file 'dropdownselector.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DROPDOWNSELECTOR_H
#define UI_DROPDOWNSELECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DropDownSelector
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *button4;
    QPushButton *button5;
    QPushButton *button6;

    void setupUi(QDialog *DropDownSelector)
    {
        if (DropDownSelector->objectName().isEmpty())
            DropDownSelector->setObjectName(QStringLiteral("DropDownSelector"));
        DropDownSelector->resize(123, 180);
        DropDownSelector->setStyleSheet(QStringLiteral("background-color: rgb(49, 49, 49);"));
        verticalLayoutWidget = new QWidget(DropDownSelector);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, -1, 121, 181));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 0, 0);
        button1 = new QPushButton(verticalLayoutWidget);
        button1->setObjectName(QStringLiteral("button1"));
        button1->setFocusPolicy(Qt::NoFocus);
        button1->setStyleSheet(QLatin1String("QPushButton {\n"
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

        verticalLayout->addWidget(button1);

        button2 = new QPushButton(verticalLayoutWidget);
        button2->setObjectName(QStringLiteral("button2"));
        button2->setFocusPolicy(Qt::NoFocus);
        button2->setStyleSheet(QLatin1String("QPushButton {\n"
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

        verticalLayout->addWidget(button2);

        button3 = new QPushButton(verticalLayoutWidget);
        button3->setObjectName(QStringLiteral("button3"));
        button3->setFocusPolicy(Qt::NoFocus);
        button3->setStyleSheet(QLatin1String("QPushButton {\n"
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

        verticalLayout->addWidget(button3);

        button4 = new QPushButton(verticalLayoutWidget);
        button4->setObjectName(QStringLiteral("button4"));
        button4->setFocusPolicy(Qt::NoFocus);
        button4->setStyleSheet(QLatin1String("QPushButton {\n"
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

        verticalLayout->addWidget(button4);

        button5 = new QPushButton(verticalLayoutWidget);
        button5->setObjectName(QStringLiteral("button5"));
        button5->setFocusPolicy(Qt::NoFocus);
        button5->setStyleSheet(QLatin1String("QPushButton {\n"
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

        verticalLayout->addWidget(button5);

        button6 = new QPushButton(verticalLayoutWidget);
        button6->setObjectName(QStringLiteral("button6"));
        button6->setFocusPolicy(Qt::NoFocus);
        button6->setStyleSheet(QLatin1String("QPushButton {\n"
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

        verticalLayout->addWidget(button6);


        retranslateUi(DropDownSelector);

        QMetaObject::connectSlotsByName(DropDownSelector);
    } // setupUi

    void retranslateUi(QDialog *DropDownSelector)
    {
        DropDownSelector->setWindowTitle(QApplication::translate("DropDownSelector", "Dialog", nullptr));
        button1->setText(QApplication::translate("DropDownSelector", "1 Day", nullptr));
        button2->setText(QApplication::translate("DropDownSelector", "1 Week", nullptr));
        button3->setText(QApplication::translate("DropDownSelector", "1 Month", nullptr));
        button4->setText(QApplication::translate("DropDownSelector", "3 Month", nullptr));
        button5->setText(QApplication::translate("DropDownSelector", "6 Month", nullptr));
        button6->setText(QApplication::translate("DropDownSelector", "1 Year", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DropDownSelector: public Ui_DropDownSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DROPDOWNSELECTOR_H
