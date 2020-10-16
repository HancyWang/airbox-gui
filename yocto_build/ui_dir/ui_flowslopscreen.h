/********************************************************************************
** Form generated from reading UI file 'flowslopscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLOWSLOPSCREEN_H
#define UI_FLOWSLOPSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FlowSlopScreen
{
public:
    QPushButton *flowSlopCancel;
    QLabel *flowSlopValue;
    QFrame *frame;
    QPushButton *flowSlopDecrease;
    QPushButton *flowSlopIncrease;
    QLabel *flowSlopTitle;
    QPushButton *flowSlopAccept;

    void setupUi(QDialog *FlowSlopScreen)
    {
        if (FlowSlopScreen->objectName().isEmpty())
            FlowSlopScreen->setObjectName(QStringLiteral("FlowSlopScreen"));
        FlowSlopScreen->resize(349, 213);
        flowSlopCancel = new QPushButton(FlowSlopScreen);
        flowSlopCancel->setObjectName(QStringLiteral("flowSlopCancel"));
        flowSlopCancel->setGeometry(QRect(175, 170, 170, 40));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(12);
        flowSlopCancel->setFont(font);
        flowSlopCancel->setFocusPolicy(Qt::NoFocus);
        flowSlopCancel->setStyleSheet(QLatin1String("QPushButton {\n"
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
        flowSlopValue = new QLabel(FlowSlopScreen);
        flowSlopValue->setObjectName(QStringLiteral("flowSlopValue"));
        flowSlopValue->setGeometry(QRect(210, 60, 121, 71));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(25);
        flowSlopValue->setFont(font1);
        flowSlopValue->setStyleSheet(QStringLiteral("color:#2196F3"));
        flowSlopValue->setAlignment(Qt::AlignCenter);
        frame = new QFrame(FlowSlopScreen);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        flowSlopDecrease = new QPushButton(frame);
        flowSlopDecrease->setObjectName(QStringLiteral("flowSlopDecrease"));
        flowSlopDecrease->setGeometry(QRect(10, 110, 80, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Roboto"));
        font2.setPointSize(14);
        flowSlopDecrease->setFont(font2);
        flowSlopDecrease->setFocusPolicy(Qt::NoFocus);
        flowSlopDecrease->setStyleSheet(QLatin1String("QPushButton {\n"
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
        flowSlopIncrease = new QPushButton(frame);
        flowSlopIncrease->setObjectName(QStringLiteral("flowSlopIncrease"));
        flowSlopIncrease->setGeometry(QRect(100, 110, 80, 31));
        flowSlopIncrease->setFont(font2);
        flowSlopIncrease->setFocusPolicy(Qt::NoFocus);
        flowSlopIncrease->setStyleSheet(QLatin1String("QPushButton {\n"
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
        flowSlopTitle = new QLabel(FlowSlopScreen);
        flowSlopTitle->setObjectName(QStringLiteral("flowSlopTitle"));
        flowSlopTitle->setGeometry(QRect(23, 16, 161, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Roboto"));
        font3.setPointSize(11);
        flowSlopTitle->setFont(font3);
        flowSlopTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        flowSlopAccept = new QPushButton(FlowSlopScreen);
        flowSlopAccept->setObjectName(QStringLiteral("flowSlopAccept"));
        flowSlopAccept->setGeometry(QRect(2, 170, 170, 40));
        flowSlopAccept->setFont(font);
        flowSlopAccept->setFocusPolicy(Qt::NoFocus);
        flowSlopAccept->setStyleSheet(QLatin1String("QPushButton {\n"
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
        frame->raise();
        flowSlopTitle->raise();
        flowSlopAccept->raise();
        flowSlopCancel->raise();
        flowSlopValue->raise();

        retranslateUi(FlowSlopScreen);

        QMetaObject::connectSlotsByName(FlowSlopScreen);
    } // setupUi

    void retranslateUi(QDialog *FlowSlopScreen)
    {
        FlowSlopScreen->setWindowTitle(QApplication::translate("FlowSlopScreen", "Dialog", nullptr));
        flowSlopCancel->setText(QApplication::translate("FlowSlopScreen", "Cancel", nullptr));
        flowSlopValue->setText(QApplication::translate("FlowSlopScreen", "5", nullptr));
        flowSlopDecrease->setText(QApplication::translate("FlowSlopScreen", "-", nullptr));
        flowSlopIncrease->setText(QApplication::translate("FlowSlopScreen", "+", nullptr));
        flowSlopTitle->setText(QApplication::translate("FlowSlopScreen", "Flow Slop", nullptr));
        flowSlopAccept->setText(QApplication::translate("FlowSlopScreen", "Accept", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FlowSlopScreen: public Ui_FlowSlopScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLOWSLOPSCREEN_H
