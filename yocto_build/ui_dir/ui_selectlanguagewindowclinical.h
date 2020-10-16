/********************************************************************************
** Form generated from reading UI file 'selectlanguagewindowclinical.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTLANGUAGEWINDOWCLINICAL_H
#define UI_SELECTLANGUAGEWINDOWCLINICAL_H

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

class Ui_SelectLanguageWindowClinical
{
public:
    QPushButton *languageAccept;
    QLabel *languageTitle;
    QPushButton *languageCancel;
    QFrame *frame;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *english;
    QRadioButton *chinese;
    QRadioButton *spanish;

    void setupUi(QDialog *SelectLanguageWindowClinical)
    {
        if (SelectLanguageWindowClinical->objectName().isEmpty())
            SelectLanguageWindowClinical->setObjectName(QStringLiteral("SelectLanguageWindowClinical"));
        SelectLanguageWindowClinical->resize(349, 213);
        languageAccept = new QPushButton(SelectLanguageWindowClinical);
        languageAccept->setObjectName(QStringLiteral("languageAccept"));
        languageAccept->setGeometry(QRect(3, 170, 170, 40));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(12);
        languageAccept->setFont(font);
        languageAccept->setFocusPolicy(Qt::NoFocus);
        languageAccept->setStyleSheet(QLatin1String("QPushButton {\n"
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
        languageTitle = new QLabel(SelectLanguageWindowClinical);
        languageTitle->setObjectName(QStringLiteral("languageTitle"));
        languageTitle->setGeometry(QRect(23, 13, 161, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(11);
        languageTitle->setFont(font1);
        languageTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        languageCancel = new QPushButton(SelectLanguageWindowClinical);
        languageCancel->setObjectName(QStringLiteral("languageCancel"));
        languageCancel->setGeometry(QRect(176, 170, 170, 40));
        languageCancel->setFont(font);
        languageCancel->setFocusPolicy(Qt::NoFocus);
        languageCancel->setStyleSheet(QLatin1String("QPushButton {\n"
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
        frame = new QFrame(SelectLanguageWindowClinical);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 349, 213));
        frame->setStyleSheet(QLatin1String("background-color: rgb(49, 49, 49);\n"
"border: 1px;\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 37, 191, 121));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        english = new QRadioButton(layoutWidget);
        english->setObjectName(QStringLiteral("english"));
        english->setFocusPolicy(Qt::NoFocus);
        english->setStyleSheet(QStringLiteral("color:#BDBDBD"));

        verticalLayout->addWidget(english);

        chinese = new QRadioButton(layoutWidget);
        chinese->setObjectName(QStringLiteral("chinese"));
        chinese->setFocusPolicy(Qt::NoFocus);
        chinese->setStyleSheet(QStringLiteral("color:#BDBDBD"));

        verticalLayout->addWidget(chinese);

        spanish = new QRadioButton(layoutWidget);
        spanish->setObjectName(QStringLiteral("spanish"));
        spanish->setFocusPolicy(Qt::NoFocus);
        spanish->setStyleSheet(QStringLiteral("color:#BDBDBD"));

        verticalLayout->addWidget(spanish);

        frame->raise();
        languageCancel->raise();
        languageAccept->raise();
        languageTitle->raise();

        retranslateUi(SelectLanguageWindowClinical);

        QMetaObject::connectSlotsByName(SelectLanguageWindowClinical);
    } // setupUi

    void retranslateUi(QDialog *SelectLanguageWindowClinical)
    {
        SelectLanguageWindowClinical->setWindowTitle(QApplication::translate("SelectLanguageWindowClinical", "Dialog", nullptr));
        languageAccept->setText(QApplication::translate("SelectLanguageWindowClinical", "Accept", nullptr));
        languageTitle->setText(QApplication::translate("SelectLanguageWindowClinical", "Select Language", nullptr));
        languageCancel->setText(QApplication::translate("SelectLanguageWindowClinical", "Cancel", nullptr));
        english->setText(QApplication::translate("SelectLanguageWindowClinical", "English", nullptr));
        chinese->setText(QApplication::translate("SelectLanguageWindowClinical", "Chinese", nullptr));
        spanish->setText(QApplication::translate("SelectLanguageWindowClinical", "Spanish", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SelectLanguageWindowClinical: public Ui_SelectLanguageWindowClinical {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTLANGUAGEWINDOWCLINICAL_H
