#ifndef HOMEWINDOWBASIC_H
#define HOMEWINDOWBASIC_H

#include <QDialog>
#include <QPropertyAnimation>

#include "widgets/button3.h"

namespace Ui {
class HomeWindowBasic;
}

class PasswordCheckScreen;

class HomeWindowBasic : public QDialog
{
    Q_OBJECT

public:
    explicit HomeWindowBasic(QWidget *parent,PasswordCheckScreen * passwordBackend);
    ~HomeWindowBasic();

    void addHomeButtons(void);
    void setButtonProps(Button3 * pButton,const QString &titleStr,const QString &imageStr);
    void updateText();
public slots:
    void therapyButton_released();
    void sleepReportButton_released();
    void maskOptionButton_released();
    void settignsButton_released();

    void timerClinicalTimeOut();

    void passwordCheckWindowClosed();

    void changeEvent(QEvent* e);
signals:
    void showHomeWindowBasic(void);
    void showSleepReportWindowBasic(void);
    void showMaskOptionsWindowBasic(void);
    void showSettingsWindowBasic(void);

    void showPasswordEnterScreen(const int *password);

    void showClinicalHomeScreen();

private slots:
    void on_frescaLogo_pressed();
    void on_frescaLogo_released();

private:
    Ui::HomeWindowBasic *ui;
    PasswordCheckScreen * passwordScreen;

    QPropertyAnimation * m_Anim;

    Button3 * therapyButton;
    Button3 * sleepReportButton;
    Button3 * maskOptionButton;
    Button3 * settignsButton;


    QTimer * timerClinical;
    bool timerOver;

    static const int clinicalPassword[9];
};

#endif // HOMEWINDOWBASIC_H
