/********************************************************************************
** Form generated from reading UI file 'modewindowtherapyclinical.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODEWINDOWTHERAPYCLINICAL_H
#define UI_MODEWINDOWTHERAPYCLINICAL_H

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

class Ui_ModeWindowTherapyClinical
{
public:
    QPushButton *modeAccept;
    QPushButton *modeCancel;
    QLabel *modeTitle;
    QFrame *frame;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *modeCpap;
    QRadioButton *modeApap;

    void setupUi(QDialog *ModeWindowTherapyClinical)
    {
        if (ModeWindowTherapyClinical->objectName().isEmpty())
            ModeWindowTherapyClinical->setObjectName(QStringLiteral("ModeWindowTherapyClinical"));
        ModeWindowTherapyClinical->resize(349, 213);
        modeAccept = new QPushButton(ModeWindowTherapyClinical);
        modeAccept->setObjectName(QStringLiteral("modeAccept"));
        modeAccept->setGeometry(QRect(3, 170, 170, 40));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(12);
        modeAccept->setFont(font);
        modeAccept->setFocusPolicy(Qt::NoFocus);
        modeAccept->setStyleSheet(QLatin1String("QPushButton {\n"
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
        modeCancel = new QPushButton(ModeWindowTherapyClinical);
        modeCancel->setObjectName(QStringLiteral("modeCancel"));
        modeCancel->setGeometry(QRect(176, 170, 170, 40));
        modeCancel->setFont(font);
        modeCancel->setFocusPolicy(Qt::NoFocus);
        modeCancel->setStyleSheet(QLatin1String("QPushButton {\n"
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
        modeTitle = new QLabel(ModeWindowTherapyClinical);
        modeTitle->setObjectName(QStringLiteral("modeTitle"));
        modeTitle->setGeometry(QRect(23, 13, 161, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(11);
        modeTitle->setFont(font1);
        modeTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        frame = new QFrame(ModeWindowTherapyClinical);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 70, 101, 51));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        modeCpap = new QRadioButton(layoutWidget);
        modeCpap->setObjectName(QStringLiteral("modeCpap"));
        modeCpap->setFocusPolicy(Qt::NoFocus);
        modeCpap->setStyleSheet(QStringLiteral("color:#BDBDBD"));

        verticalLayout->addWidget(modeCpap);

        modeApap = new QRadioButton(layoutWidget);
        modeApap->setObjectName(QStringLiteral("modeApap"));
        modeApap->setFocusPolicy(Qt::NoFocus);
        modeApap->setStyleSheet(QStringLiteral("color:#BDBDBD"));

        verticalLayout->addWidget(modeApap);

        frame->raise();
        modeAccept->raise();
        modeTitle->raise();
        modeCancel->raise();

        retranslateUi(ModeWindowTherapyClinical);

        QMetaObject::connectSlotsByName(ModeWindowTherapyClinical);
    } // setupUi

    void retranslateUi(QDialog *ModeWindowTherapyClinical)
    {
        ModeWindowTherapyClinical->setWindowTitle(QApplication::translate("ModeWindowTherapyClinical", "Dialog", nullptr));
        modeAccept->setText(QApplication::translate("ModeWindowTherapyClinical", "Accept", nullptr));
        modeCancel->setText(QApplication::translate("ModeWindowTherapyClinical", "Cancel", nullptr));
        modeTitle->setText(QApplication::translate("ModeWindowTherapyClinical", "Mode", nullptr));
        modeCpap->setText(QApplication::translate("ModeWindowTherapyClinical", "PAP", nullptr));
        modeApap->setText(QApplication::translate("ModeWindowTherapyClinical", "APAP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModeWindowTherapyClinical: public Ui_ModeWindowTherapyClinical {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODEWINDOWTHERAPYCLINICAL_H
