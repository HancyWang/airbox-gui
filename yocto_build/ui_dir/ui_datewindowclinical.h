/********************************************************************************
** Form generated from reading UI file 'datewindowclinical.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATEWINDOWCLINICAL_H
#define UI_DATEWINDOWCLINICAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DateWindowClinical
{
public:
    QLabel *dateTitle;
    QPushButton *dateAccept;
    QPushButton *dateCancel;
    QWidget *gridLayoutWidget;
    QGridLayout *dateLayout;
    QFrame *frame;

    void setupUi(QDialog *DateWindowClinical)
    {
        if (DateWindowClinical->objectName().isEmpty())
            DateWindowClinical->setObjectName(QStringLiteral("DateWindowClinical"));
        DateWindowClinical->resize(349, 213);
        DateWindowClinical->setStyleSheet(QStringLiteral(""));
        dateTitle = new QLabel(DateWindowClinical);
        dateTitle->setObjectName(QStringLiteral("dateTitle"));
        dateTitle->setGeometry(QRect(24, 16, 161, 31));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(11);
        dateTitle->setFont(font);
        dateTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        dateAccept = new QPushButton(DateWindowClinical);
        dateAccept->setObjectName(QStringLiteral("dateAccept"));
        dateAccept->setGeometry(QRect(3, 170, 170, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(12);
        dateAccept->setFont(font1);
        dateAccept->setFocusPolicy(Qt::NoFocus);
        dateAccept->setStyleSheet(QLatin1String("QPushButton {\n"
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
        dateCancel = new QPushButton(DateWindowClinical);
        dateCancel->setObjectName(QStringLiteral("dateCancel"));
        dateCancel->setGeometry(QRect(176, 170, 170, 40));
        dateCancel->setFont(font1);
        dateCancel->setFocusPolicy(Qt::NoFocus);
        dateCancel->setStyleSheet(QLatin1String("QPushButton {\n"
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
        gridLayoutWidget = new QWidget(DateWindowClinical);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(40, 50, 271, 101));
        dateLayout = new QGridLayout(gridLayoutWidget);
        dateLayout->setSpacing(0);
        dateLayout->setObjectName(QStringLiteral("dateLayout"));
        dateLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(DateWindowClinical);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        dateTitle->raise();
        dateAccept->raise();
        dateCancel->raise();
        gridLayoutWidget->raise();

        retranslateUi(DateWindowClinical);

        QMetaObject::connectSlotsByName(DateWindowClinical);
    } // setupUi

    void retranslateUi(QDialog *DateWindowClinical)
    {
        DateWindowClinical->setWindowTitle(QApplication::translate("DateWindowClinical", "Dialog", nullptr));
        dateTitle->setText(QApplication::translate("DateWindowClinical", "Date", nullptr));
        dateAccept->setText(QApplication::translate("DateWindowClinical", "Accept", nullptr));
        dateCancel->setText(QApplication::translate("DateWindowClinical", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DateWindowClinical: public Ui_DateWindowClinical {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATEWINDOWCLINICAL_H
