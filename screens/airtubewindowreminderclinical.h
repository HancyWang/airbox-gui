#ifndef AIRTUBEWINDOWREMINDERCLINICAL_H
#define AIRTUBEWINDOWREMINDERCLINICAL_H


#include <QDialog>
#include <QGraphicsColorizeEffect>


namespace Ui {
class AirTubeWindowReminderClinical;
}

class DateWindowClinical;
class DataValidation;

class AirTubeWindowReminderClinical : public QDialog
{
    Q_OBJECT

public:
    explicit AirTubeWindowReminderClinical(QWidget *parent,
                                           DateWindowClinical * dateScreenBackend,
                                           DataValidation * dataValidationBackend);
    ~AirTubeWindowReminderClinical();

    void updateAirTubeReminderBeforeShowProcess(void);
    void updateAirTubeDuration(int duration);
    void updateAirTubeSetStartDate(int mDate,int mMonth,int mYear);
    QGraphicsColorizeEffect * parentEffect;

    void changeEvent(QEvent* e);

signals:
    void showDateScreen(QWidget *parent, int date, int month, int year, bool colorEffect);

    void writeParameterToEeprom(void);

public slots:
    void showAirTubeReminderScreen();

private slots:
    void on_airTubeSetDate_released();

    void on_airTubeAccept_released();

    void on_airTubeCancel_released();

    void dateWindowClosed(int date, int month, int year);

    void on_airTubeIncrement_pressed();

    void on_airTubeDecrement_pressed();

private:
    Ui::AirTubeWindowReminderClinical *ui;
    DateWindowClinical * dateScreen;
    DataValidation * dataValidation;

    int airTubeDuration;
    static int localDate;
    static int localMonth;
    static int localYear;

};

#endif // AIRTUBEWINDOWREMINDERCLINICAL_H
