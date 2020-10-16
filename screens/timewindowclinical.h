#ifndef TIMEWINDOWCLINICAL_H
#define TIMEWINDOWCLINICAL_H

#include <QDialog>
#include <QGraphicsColorizeEffect>

#include "widgets/wheelwidget.h"

namespace Ui {
class TimeWindowClinical;
}

class TimeWindowClinical : public QDialog
{
    Q_OBJECT

public:
    explicit TimeWindowClinical(QWidget *parent = 0);
    ~TimeWindowClinical();

    QGraphicsColorizeEffect * parentEffect;
    void updateParameteres(int hrs,int min);
    int currentHours;
    int currentMinutes;

    StringWheelWidget * m_hourWheel;
    StringWheelWidget * m_minuteWheel;
    void changeEvent(QEvent* e);
signals:
    void dialogClose();

    void screenClose(int hour, int minute);

private slots:
    void on_timeAccept_released();

    void on_timeCancel_released();

    void showTimeScreen(QWidget *parent, int hour, int minute, bool colorEffect);

private:
    Ui::TimeWindowClinical *ui;

//    StringWheelWidget * m_hourWheel;
//    StringWheelWidget * m_minuteWheel;

};

#endif // TIMEWINDOWCLINICAL_H
