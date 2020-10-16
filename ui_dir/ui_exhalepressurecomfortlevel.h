/********************************************************************************
** Form generated from reading UI file 'exhalepressurecomfortlevel.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXHALEPRESSURECOMFORTLEVEL_H
#define UI_EXHALEPRESSURECOMFORTLEVEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExhalePressureComfortLevel
{
public:
    QLabel *exhaleComfortTitle;
    QPushButton *exhaleComfortCancel;
    QPushButton *exhaleComfortAccept;
    QFrame *frame;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *level1Radio;
    QRadioButton *level2Radio;
    QRadioButton *level3Radio;

    void setupUi(QDialog *ExhalePressureComfortLevel)
    {
        if (ExhalePressureComfortLevel->objectName().isEmpty())
            ExhalePressureComfortLevel->setObjectName(QStringLiteral("ExhalePressureComfortLevel"));
        ExhalePressureComfortLevel->resize(349, 213);
        ExhalePressureComfortLevel->setStyleSheet(QStringLiteral(""));
        exhaleComfortTitle = new QLabel(ExhalePressureComfortLevel);
        exhaleComfortTitle->setObjectName(QStringLiteral("exhaleComfortTitle"));
        exhaleComfortTitle->setGeometry(QRect(24, 16, 301, 31));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(11);
        exhaleComfortTitle->setFont(font);
        exhaleComfortTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        exhaleComfortCancel = new QPushButton(ExhalePressureComfortLevel);
        exhaleComfortCancel->setObjectName(QStringLiteral("exhaleComfortCancel"));
        exhaleComfortCancel->setGeometry(QRect(176, 170, 170, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(12);
        exhaleComfortCancel->setFont(font1);
        exhaleComfortCancel->setFocusPolicy(Qt::NoFocus);
        exhaleComfortCancel->setStyleSheet(QLatin1String("QPushButton {\n"
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
        exhaleComfortAccept = new QPushButton(ExhalePressureComfortLevel);
        exhaleComfortAccept->setObjectName(QStringLiteral("exhaleComfortAccept"));
        exhaleComfortAccept->setGeometry(QRect(3, 170, 170, 40));
        exhaleComfortAccept->setFont(font1);
        exhaleComfortAccept->setFocusPolicy(Qt::NoFocus);
        exhaleComfortAccept->setStyleSheet(QLatin1String("QPushButton {\n"
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
        frame = new QFrame(ExhalePressureComfortLevel);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 70, 111, 71));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        level1Radio = new QRadioButton(layoutWidget);
        level1Radio->setObjectName(QStringLiteral("level1Radio"));
        level1Radio->setFocusPolicy(Qt::NoFocus);
        level1Radio->setStyleSheet(QStringLiteral("color:#BDBDBD"));

        verticalLayout->addWidget(level1Radio);

        level2Radio = new QRadioButton(layoutWidget);
        level2Radio->setObjectName(QStringLiteral("level2Radio"));
        level2Radio->setFocusPolicy(Qt::NoFocus);
        level2Radio->setStyleSheet(QStringLiteral("color:#BDBDBD"));

        verticalLayout->addWidget(level2Radio);

        level3Radio = new QRadioButton(layoutWidget);
        level3Radio->setObjectName(QStringLiteral("level3Radio"));
        level3Radio->setFocusPolicy(Qt::NoFocus);
        level3Radio->setStyleSheet(QStringLiteral("color:#BDBDBD"));

        verticalLayout->addWidget(level3Radio);

        frame->raise();
        exhaleComfortTitle->raise();
        exhaleComfortCancel->raise();
        exhaleComfortAccept->raise();

        retranslateUi(ExhalePressureComfortLevel);

        QMetaObject::connectSlotsByName(ExhalePressureComfortLevel);
    } // setupUi

    void retranslateUi(QDialog *ExhalePressureComfortLevel)
    {
        ExhalePressureComfortLevel->setWindowTitle(QApplication::translate("ExhalePressureComfortLevel", "Dialog", nullptr));
        exhaleComfortTitle->setText(QApplication::translate("ExhalePressureComfortLevel", "Exhale Pressure Comfort Level", nullptr));
        exhaleComfortCancel->setText(QApplication::translate("ExhalePressureComfortLevel", "Cancel", nullptr));
        exhaleComfortAccept->setText(QApplication::translate("ExhalePressureComfortLevel", "Accept", nullptr));
        level1Radio->setText(QApplication::translate("ExhalePressureComfortLevel", "Level 1", nullptr));
        level2Radio->setText(QApplication::translate("ExhalePressureComfortLevel", "Level 2", nullptr));
        level3Radio->setText(QApplication::translate("ExhalePressureComfortLevel", "Level 3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExhalePressureComfortLevel: public Ui_ExhalePressureComfortLevel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXHALEPRESSURECOMFORTLEVEL_H
