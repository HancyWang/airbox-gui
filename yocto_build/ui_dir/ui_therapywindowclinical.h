/********************************************************************************
** Form generated from reading UI file 'therapywindowclinical.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THERAPYWINDOWCLINICAL_H
#define UI_THERAPYWINDOWCLINICAL_H

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

class Ui_TherapyWindowClinical
{
public:
    QLabel *titleTherapy;
    QPushButton *backTherapy;
    QScrollArea *scrollAreaSettings;
    QWidget *scrollAreaWidgetContentsSettings;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayoutSettings;

    void setupUi(QDialog *TherapyWindowClinical)
    {
        if (TherapyWindowClinical->objectName().isEmpty())
            TherapyWindowClinical->setObjectName(QStringLiteral("TherapyWindowClinical"));
        TherapyWindowClinical->resize(480, 272);
        TherapyWindowClinical->setStyleSheet(QStringLiteral("background-color: rgb(49, 49, 49);"));
        titleTherapy = new QLabel(TherapyWindowClinical);
        titleTherapy->setObjectName(QStringLiteral("titleTherapy"));
        titleTherapy->setGeometry(QRect(80, 30, 171, 25));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(14);
        titleTherapy->setFont(font);
        titleTherapy->setStyleSheet(QLatin1String("color:#1788c3\n"
""));
        backTherapy = new QPushButton(TherapyWindowClinical);
        backTherapy->setObjectName(QStringLiteral("backTherapy"));
        backTherapy->setGeometry(QRect(6, 25, 38, 30));
        backTherapy->setFocusPolicy(Qt::NoFocus);
        backTherapy->setStyleSheet(QLatin1String("border:none;\n"
"border-radius:3px;\n"
"background-color: rgb(70, 70, 73);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        backTherapy->setIcon(icon);
        scrollAreaSettings = new QScrollArea(TherapyWindowClinical);
        scrollAreaSettings->setObjectName(QStringLiteral("scrollAreaSettings"));
        scrollAreaSettings->setGeometry(QRect(0, 63, 480, 209));
        scrollAreaSettings->setStyleSheet(QLatin1String(" QScrollBar:vertical {\n"
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
        scrollAreaSettings->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollAreaSettings->setWidgetResizable(true);
        scrollAreaWidgetContentsSettings = new QWidget();
        scrollAreaWidgetContentsSettings->setObjectName(QStringLiteral("scrollAreaWidgetContentsSettings"));
        scrollAreaWidgetContentsSettings->setGeometry(QRect(0, 0, 464, 207));
        verticalLayoutWidget = new QWidget(scrollAreaWidgetContentsSettings);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 9, 461, 201));
        verticalLayoutSettings = new QVBoxLayout(verticalLayoutWidget);
        verticalLayoutSettings->setObjectName(QStringLiteral("verticalLayoutSettings"));
        verticalLayoutSettings->setContentsMargins(60, 5, 60, 5);
        scrollAreaSettings->setWidget(scrollAreaWidgetContentsSettings);

        retranslateUi(TherapyWindowClinical);

        QMetaObject::connectSlotsByName(TherapyWindowClinical);
    } // setupUi

    void retranslateUi(QDialog *TherapyWindowClinical)
    {
        TherapyWindowClinical->setWindowTitle(QApplication::translate("TherapyWindowClinical", "Dialog", nullptr));
        titleTherapy->setText(QApplication::translate("TherapyWindowClinical", "Therapy", nullptr));
        backTherapy->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TherapyWindowClinical: public Ui_TherapyWindowClinical {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THERAPYWINDOWCLINICAL_H
