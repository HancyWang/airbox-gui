#ifndef SLEEPREPORTWINDOW_H
#define SLEEPREPORTWINDOW_H

#include <QDialog>
#include <QPropertyAnimation>
#include <QFileInfoList>

#include "constants.h"
#include "application.h"

namespace Ui {
class SleepReportWindowBasic;
}

class DataLogging;
class HomeWindowBasic;
class HomeWindowClinical;

class SleepReportWindowBasic : public QDialog
{
    Q_OBJECT

public:
    explicit SleepReportWindowBasic(QWidget *parent,
                                    DataLogging * m_DataBackend,
                                    HomeWindowBasic * m_HomeWindowBackend,
                                    HomeWindowClinical * homeClinicalBackend);
    ~SleepReportWindowBasic();

    void animateSleepReportWindow(openCloseStatus state);
    void updateSleepReportAsPerMode(bool clinicalMode);
    void updateSleepReportProcessBeforeShow(void);
    void updateLastRecordTherapyDetails(const QFileInfoList & list,int index);
    void updateUsageHoursAndEventsPerHoursLastNight(const QFileInfoList & list,int index);

    void updateUsageHourIconAsPerCondition(float tUsedTime);
    void updateEventsIconAsPerCondition(float tEvents);


    void getDirectoryWhichContainsEdfFiles(void);
    void changeEvent(QEvent* e);
public slots:
    void showSleepReportWindowBasic();
signals:
    void getSleepReportData(int tSleepReportType,sendSleepReportParam sleepReportDuration,const QFileInfoList & list,int index,
                            float * tUsageHours,float * tEventsPerHour,float * tLeakage,
                            int * usedHours4PlusIndex,int * usedDaysIndex,float * tAverageUsage);

    void showSleepReportMoreScreenFromList(QFileInfoList & directorList);

private slots:
    void on_homeSleepReportButton_clicked();

    void on_moreSleepReportButton_clicked();
    void backToHomeSleepReport();

    void showSleepReportScreen(QWidget * parent);

private:
    Ui::SleepReportWindowBasic *ui;
    HomeWindowClinical * homeClinicalScreen;

    DataLogging * m_DataManager;
    HomeWindowBasic * m_HomeWindow;

    QPropertyAnimation * m_Anim;
    QFileInfoList directorList;


};

#endif // SLEEPREPORTWINDOW_H
