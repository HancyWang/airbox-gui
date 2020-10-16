#ifndef AIRFILTERWINDOWREMINDERCLINICAL_H
#define AIRFILTERWINDOWREMINDERCLINICAL_H


#include <QDialog>
#include <QGraphicsColorizeEffect>

namespace Ui {
class AirFilterWindowReminderClinical;
}

class DateWindowClinical;
class DataValidation;

class AirFilterWindowReminderClinical : public QDialog
{
    Q_OBJECT

public:
    explicit AirFilterWindowReminderClinical(QWidget *parent,
                                             DateWindowClinical * dateScreenBackend,
                                             DataValidation * dataValidationBackend);
    ~AirFilterWindowReminderClinical();

    void updateAirFilterDuration(int duration);
    void updateAirFilterRemindersBeforeShowProcess(void);
    void updateAirFilterSetStartDate(int mDate,int mMonth,int mYear);
    QGraphicsColorizeEffect * parentEffect;
    void changeEvent(QEvent* e);
signals:
    void showDateScreen(QWidget *parent, int date, int month, int year, bool colorEffect);

    void writeParameterToEeprom(void);

private slots:
    void on_airFilterSetDate_released();

    void on_airFilterAccept_released();

    void on_airFilterCancel_released();

    void dateWindowClosed(int date, int month, int year);

    void on_airFilterIncrement_pressed();

    void on_airFilterDecrement_pressed();

public slots:
    void showAirFilterReminderScreen();

private:
    Ui::AirFilterWindowReminderClinical *ui;
    DateWindowClinical * dateScreen;
    DataValidation * dataValidation;

    int airFilterDuration;
    static int localDate;
    static int localMonth;
    static int localYear;
};

#endif // AIRFILTERWINDOWREMINDERCLINICAL_H
