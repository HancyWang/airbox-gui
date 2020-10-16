#ifndef SNOOZEEXITSCREENBASIC_H
#define SNOOZEEXITSCREENBASIC_H

#include <QDialog>
#include <QGraphicsColorizeEffect>

namespace Ui {
class SnoozeExitScreenBasic;
}

class PruControlClass;

class SnoozeExitScreenBasic : public QDialog
{
    Q_OBJECT

public:
    explicit SnoozeExitScreenBasic(QWidget *parent,PruControlClass * m_IpcBackend);
    ~SnoozeExitScreenBasic();

    QGraphicsColorizeEffect * parentEffect;
    void changeEvent(QEvent* e);
signals:
    void beforeSnoozeProcedure(int state);

    void showHideSnoozeTimeFrame(bool showFrame);

private slots:
    void on_snoozeExitYes_released();

    void on_snoozeExitNo_released();

private:
    Ui::SnoozeExitScreenBasic *ui;
    PruControlClass * m_IpcManager;


};

#endif // SNOOZEEXITSCREENBASIC_H
