#ifndef HOMEWINDOWCLINICAL_H
#define HOMEWINDOWCLINICAL_H

#include <QDialog>

#include "widgets/button3.h"

namespace Ui {
class HomeWindowClinical;
}

class HomeWindowBasic;

class HomeWindowClinical : public QDialog
{
    Q_OBJECT

public:
    explicit HomeWindowClinical(QWidget *parent,HomeWindowBasic * homeBasicBackend);
    ~HomeWindowClinical();

    void addHomeButtons(void);
    void setButtonProps(Button3 * pButton,const QString &titleStr,const QString &imageStr);
    void changeEvent(QEvent* e);
    void updateText();
signals:
    void showSleepReportScreen(QWidget * parent);

    void showSettingsClinicalScreen();

private slots:

    void on_frescaLogo_pressed();
    void sleepReportButton_released();
    void settignsButton_released();

    void on_frescaLogo_released();
    void timerClinicalTimeOut();



private:
    Ui::HomeWindowClinical *ui;
    HomeWindowBasic * homeScreenBasic;

    Button3 * sleepReportButton;
    Button3 * settignsButton;

    QTimer * timerClinical;
    bool timerOver;

};

#endif // HOMEWINDOWCLINICAL_H
