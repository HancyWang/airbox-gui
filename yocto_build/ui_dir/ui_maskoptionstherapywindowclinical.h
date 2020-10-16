/********************************************************************************
** Form generated from reading UI file 'maskoptionstherapywindowclinical.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MASKOPTIONSTHERAPYWINDOWCLINICAL_H
#define UI_MASKOPTIONSTHERAPYWINDOWCLINICAL_H

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

class Ui_MaskOptionsTherapyWindowClinical
{
public:
    QPushButton *maskAccept;
    QLabel *maskTitle;
    QPushButton *maskCancel;
    QFrame *frame;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *nasalPillow;
    QRadioButton *nasalMask;

    void setupUi(QDialog *MaskOptionsTherapyWindowClinical)
    {
        if (MaskOptionsTherapyWindowClinical->objectName().isEmpty())
            MaskOptionsTherapyWindowClinical->setObjectName(QStringLiteral("MaskOptionsTherapyWindowClinical"));
        MaskOptionsTherapyWindowClinical->resize(349, 213);
        maskAccept = new QPushButton(MaskOptionsTherapyWindowClinical);
        maskAccept->setObjectName(QStringLiteral("maskAccept"));
        maskAccept->setGeometry(QRect(3, 170, 170, 40));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(12);
        maskAccept->setFont(font);
        maskAccept->setFocusPolicy(Qt::NoFocus);
        maskAccept->setStyleSheet(QLatin1String("QPushButton {\n"
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
        maskTitle = new QLabel(MaskOptionsTherapyWindowClinical);
        maskTitle->setObjectName(QStringLiteral("maskTitle"));
        maskTitle->setGeometry(QRect(23, 13, 161, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(11);
        maskTitle->setFont(font1);
        maskTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        maskCancel = new QPushButton(MaskOptionsTherapyWindowClinical);
        maskCancel->setObjectName(QStringLiteral("maskCancel"));
        maskCancel->setGeometry(QRect(176, 170, 170, 40));
        maskCancel->setFont(font);
        maskCancel->setFocusPolicy(Qt::NoFocus);
        maskCancel->setStyleSheet(QLatin1String("QPushButton {\n"
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
        frame = new QFrame(MaskOptionsTherapyWindowClinical);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 70, 191, 51));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        nasalPillow = new QRadioButton(layoutWidget);
        nasalPillow->setObjectName(QStringLiteral("nasalPillow"));
        nasalPillow->setFocusPolicy(Qt::NoFocus);
        nasalPillow->setStyleSheet(QStringLiteral("color:#BDBDBD"));

        verticalLayout->addWidget(nasalPillow);

        nasalMask = new QRadioButton(layoutWidget);
        nasalMask->setObjectName(QStringLiteral("nasalMask"));
        nasalMask->setFocusPolicy(Qt::NoFocus);
        nasalMask->setStyleSheet(QStringLiteral("color:#BDBDBD"));

        verticalLayout->addWidget(nasalMask);

        frame->raise();
        maskCancel->raise();
        maskAccept->raise();
        maskTitle->raise();

        retranslateUi(MaskOptionsTherapyWindowClinical);

        QMetaObject::connectSlotsByName(MaskOptionsTherapyWindowClinical);
    } // setupUi

    void retranslateUi(QDialog *MaskOptionsTherapyWindowClinical)
    {
        MaskOptionsTherapyWindowClinical->setWindowTitle(QApplication::translate("MaskOptionsTherapyWindowClinical", "Dialog", nullptr));
        maskAccept->setText(QApplication::translate("MaskOptionsTherapyWindowClinical", "Accept", nullptr));
        maskTitle->setText(QApplication::translate("MaskOptionsTherapyWindowClinical", "Mask", nullptr));
        maskCancel->setText(QApplication::translate("MaskOptionsTherapyWindowClinical", "Cancel", nullptr));
        nasalPillow->setText(QApplication::translate("MaskOptionsTherapyWindowClinical", "Nasal Pillows", nullptr));
        nasalMask->setText(QApplication::translate("MaskOptionsTherapyWindowClinical", "Nasal Mask", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MaskOptionsTherapyWindowClinical: public Ui_MaskOptionsTherapyWindowClinical {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MASKOPTIONSTHERAPYWINDOWCLINICAL_H
