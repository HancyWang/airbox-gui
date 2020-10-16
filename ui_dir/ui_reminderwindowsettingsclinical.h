/********************************************************************************
** Form generated from reading UI file 'reminderwindowsettingsclinical.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMINDERWINDOWSETTINGSCLINICAL_H
#define UI_REMINDERWINDOWSETTINGSCLINICAL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ReminderWindowSettingsClinical
{
public:
    QLabel *titleReminders;
    QPushButton *backReminders;

    void setupUi(QDialog *ReminderWindowSettingsClinical)
    {
        if (ReminderWindowSettingsClinical->objectName().isEmpty())
            ReminderWindowSettingsClinical->setObjectName(QStringLiteral("ReminderWindowSettingsClinical"));
        ReminderWindowSettingsClinical->resize(480, 272);
        ReminderWindowSettingsClinical->setStyleSheet(QStringLiteral("background-color: rgb(49, 49, 49);"));
        titleReminders = new QLabel(ReminderWindowSettingsClinical);
        titleReminders->setObjectName(QStringLiteral("titleReminders"));
        titleReminders->setGeometry(QRect(80, 30, 171, 25));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(14);
        titleReminders->setFont(font);
        titleReminders->setStyleSheet(QLatin1String("color:#1788c3\n"
""));
        backReminders = new QPushButton(ReminderWindowSettingsClinical);
        backReminders->setObjectName(QStringLiteral("backReminders"));
        backReminders->setGeometry(QRect(6, 25, 38, 30));
        backReminders->setFocusPolicy(Qt::NoFocus);
        backReminders->setStyleSheet(QLatin1String("border:none;\n"
"border-radius:3px;\n"
"background-color: rgb(70, 70, 73);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        backReminders->setIcon(icon);

        retranslateUi(ReminderWindowSettingsClinical);

        QMetaObject::connectSlotsByName(ReminderWindowSettingsClinical);
    } // setupUi

    void retranslateUi(QDialog *ReminderWindowSettingsClinical)
    {
        ReminderWindowSettingsClinical->setWindowTitle(QApplication::translate("ReminderWindowSettingsClinical", "Dialog", nullptr));
        titleReminders->setText(QApplication::translate("ReminderWindowSettingsClinical", "Reminders", nullptr));
        backReminders->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ReminderWindowSettingsClinical: public Ui_ReminderWindowSettingsClinical {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMINDERWINDOWSETTINGSCLINICAL_H
