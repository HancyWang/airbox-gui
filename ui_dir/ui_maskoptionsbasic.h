/********************************************************************************
** Form generated from reading UI file 'maskoptionsbasic.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MASKOPTIONSBASIC_H
#define UI_MASKOPTIONSBASIC_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MaskOptionsBasic
{
public:
    QPushButton *homeMaskOptions;
    QLabel *titleMaskOptions;

    void setupUi(QDialog *MaskOptionsBasic)
    {
        if (MaskOptionsBasic->objectName().isEmpty())
            MaskOptionsBasic->setObjectName(QStringLiteral("MaskOptionsBasic"));
        MaskOptionsBasic->resize(480, 272);
        MaskOptionsBasic->setStyleSheet(QStringLiteral("background-color: rgb(49, 49, 49);"));
        homeMaskOptions = new QPushButton(MaskOptionsBasic);
        homeMaskOptions->setObjectName(QStringLiteral("homeMaskOptions"));
        homeMaskOptions->setGeometry(QRect(9, 25, 38, 30));
        homeMaskOptions->setFocusPolicy(Qt::NoFocus);
        homeMaskOptions->setStyleSheet(QLatin1String("border:none;\n"
"border-radius:3px;\n"
"background-color: rgb(70, 70, 73);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/home.png"), QSize(), QIcon::Normal, QIcon::Off);
        homeMaskOptions->setIcon(icon);
        titleMaskOptions = new QLabel(MaskOptionsBasic);
        titleMaskOptions->setObjectName(QStringLiteral("titleMaskOptions"));
        titleMaskOptions->setGeometry(QRect(85, 25, 271, 30));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(14);
        titleMaskOptions->setFont(font);
        titleMaskOptions->setStyleSheet(QLatin1String("color:#1788c3\n"
""));

        retranslateUi(MaskOptionsBasic);

        QMetaObject::connectSlotsByName(MaskOptionsBasic);
    } // setupUi

    void retranslateUi(QDialog *MaskOptionsBasic)
    {
        MaskOptionsBasic->setWindowTitle(QApplication::translate("MaskOptionsBasic", "Dialog", nullptr));
        homeMaskOptions->setText(QString());
        titleMaskOptions->setText(QApplication::translate("MaskOptionsBasic", "Mask Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MaskOptionsBasic: public Ui_MaskOptionsBasic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MASKOPTIONSBASIC_H
