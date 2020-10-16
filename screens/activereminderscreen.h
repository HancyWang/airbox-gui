#ifndef ACTIVEREMINDERSCREEN_H
#define ACTIVEREMINDERSCREEN_H

#include <QDialog>
#include <QGraphicsColorizeEffect>

namespace Ui {
class ActiveReminderScreen;
}

class ActiveReminderScreen : public QDialog
{
    Q_OBJECT

public:
    explicit ActiveReminderScreen(QWidget *parent = 0);
    ~ActiveReminderScreen();

    QGraphicsColorizeEffect * parentEffect;
    void updateActiveReminderBeforeShow(void);
    void showAirFilterAtIndex(int index);
    void showAirTubeAtIndex(int index);
    void showMaskAtIndex(int index);

    void changeEvent(QEvent* e);
signals:
    void showResetReminderScreen();
    void showAirFilterAtIndexResetReminder(int index);
    void showAirTubeAtIndexResetReminder(int index);
    void showMaskAtIndexResetReminder(int index);

public slots:
    void closeScreen();

private slots:
    void on_resetReminderButton_clicked();

    void on_remindLaterButton_clicked();

private:
    Ui::ActiveReminderScreen *ui;

    int widgetYOffset=90;
    int widgetSize=20;
};

#endif // ACTIVEREMINDERSCREEN_H
