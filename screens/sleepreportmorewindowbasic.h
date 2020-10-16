#ifndef SLEEPREPORTMOREWINDOW_H
#define SLEEPREPORTMOREWINDOW_H

#include <QDialog>
#include <QPropertyAnimation>
#include <QFileInfoList>

#include "screens/dropdownselector.h"
#include "widgets/button1.h"
#include "widgets/button3.h"
#include "constants.h"
#include "application.h"



namespace Ui {
class SleepReportMoreWindowBasic;
}

class DataLogging;
class SleepReportWindowBasic;

class SleepReportMoreWindowBasic : public QDialog
{
    Q_OBJECT

public:
    explicit SleepReportMoreWindowBasic(QWidget *parent,
                                        DataLogging * m_DataBackend,
                                        SleepReportWindowBasic * sleepReportBasicBackend);
    ~SleepReportMoreWindowBasic();

    void animateSleepReportMoreWindow(openCloseStatus state);
    void updateSleepReportMoreAsPerMode(bool clinicalMode);
    void updateSleepReportMoreProcessBeforeShow(QFileInfoList & logFileList);
    void parseAndUpdateFieldAsPerSelection(sendSleepReportParam param,QFileInfoList & logFileList);
    void changeEvent(QEvent* e);
signals:
    void backToHomeButtonPressed();

signals:
    void getSleepReportData(int tSleepReportType,sendSleepReportParam sleepReportDuration,const QFileInfoList & list,int index,
                            float * tUsageHours,float * tEventsPerHour,float * tLeakage,
                            int * usedHours4PlusIndex,int * usedDaysIndex,float * tAverageUsage);

private slots:
    void on_backSleepReportMoreButton_clicked();
    void backToHomeButton_released();
    void on_sendSleepReportButton_released();

    void periodSelectionClosed();
    void periodSelection_released();

    void showSleepReportMoreScreenFromList(QFileInfoList & directorList);

private:
    Ui::SleepReportMoreWindowBasic *ui;
    DataLogging * m_DataManager;
    SleepReportWindowBasic * sleepReportBasicScreen;

    QPropertyAnimation * m_Anim;


    Button1 * periodSelection;
    Button3 * backToHomeButton;
    DropDownSelector * dropDownScreen;
    QFileInfoList fileList;

    static const QStringList periodList;
};

#endif // SLEEPREPORTMOREWINDOW_H
