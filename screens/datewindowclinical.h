#ifndef DATEWINDOWCLINICAL_H
#define DATEWINDOWCLINICAL_H

#include <QDialog>
#include <QGraphicsColorizeEffect>

#include "widgets/wheelwidget.h"

namespace Ui {
class DateWindowClinical;
}

class DateWindowClinical : public QDialog
{
    Q_OBJECT

public:
    explicit DateWindowClinical(QWidget *parent = 0);
    ~DateWindowClinical();

    void changeEvent(QEvent* e);
    void updateAvailableDatesinMonth(int date,int month,int year);
    void updateParameteres(int date,int month,int year);
    void enableColorEffect(bool state);

    QGraphicsColorizeEffect * parentEffect;
    int currentDate;
    int currentMonth;
    int currentYear;

    StringWheelWidget * m_dateWheel;
    StringWheelWidget * m_monthWheel;
    StringWheelWidget * m_yearWheel;

signals:
    void dialogClose();

    void screenClose(int date, int month, int year);

private slots:
    void on_dateAccept_released();

    void on_dateCancel_released();

public slots:
    void updateDateAsPerYearOrMonth();

    void yearChanged();
    void monthChanged();

    void showDateScreen(QWidget *parent, int date, int month, int year, bool colorEffect);

private:
    Ui::DateWindowClinical *ui;
//    StringWheelWidget * m_dateWheel;
//    StringWheelWidget * m_monthWheel;
//    StringWheelWidget * m_yearWheel;

    bool colorEffectEnabled = false;

};

#endif // DATEWINDOWCLINICAL_H
