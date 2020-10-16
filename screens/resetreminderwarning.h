#ifndef RESETREMINDERWARNING_H
#define RESETREMINDERWARNING_H

#include <QDialog>

namespace Ui {
class ResetReminderWarning;
}

class ActiveReminderScreen;
class DataValidation;

class ResetReminderWarning : public QDialog
{
    Q_OBJECT

public:
    explicit ResetReminderWarning(QWidget *parent,
                                  ActiveReminderScreen * activeReminderBackend,
                                  DataValidation * dataValidationBackend);
    ~ResetReminderWarning();

    void updateResetReminderBeforeShow(void);
    void changeEvent(QEvent* e);
signals:
    void closeScreen();

    void writeParameterToEeprom(void);

private slots:
    void on_yesButton_clicked();

    void on_noButton_clicked();

    void showResetReminderScreen();

    void showAirFilterAtIndex(int index);

    void showAirTubeAtIndex(int index);

    void showMaskAtIndex(int index);

private:
    Ui::ResetReminderWarning *ui;
    ActiveReminderScreen * activeReminderScreen;
    DataValidation * dataValidation;

    int widgetYOffset=90;
    int widgetSize=20;

};

#endif // RESETREMINDERWARNING_H
