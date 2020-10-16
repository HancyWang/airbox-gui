#ifndef MASKDRYOPTIONSBASIC_H
#define MASKDRYOPTIONSBASIC_H

#include <QDialog>
#include <QGraphicsColorizeEffect>

#include "widgets/waitingspinnerwidget.h"

namespace Ui {
class MaskDryOptionsBasic;
}

class PruControlClass;

class MaskDryOptionsBasic : public QDialog
{
    Q_OBJECT

public:
    explicit MaskDryOptionsBasic(QWidget *parent,
                                 PruControlClass * m_IpcBackend);
    ~MaskDryOptionsBasic();

    void updateStartStopButton(void);
    void updateProgressBarAsPerSeconds(int seconds);
    void updateMaskDryOptionsProcessBeforeShow(void);

    QGraphicsColorizeEffect * parentEffect;
    void changeEvent(QEvent* e);
private slots:
    void maskDryTimerTimeout();

    void on_maskDryCancel_released();

    void on_maskDryTestStartStop_released();

    void showMaskDryOptionScreen();

signals:
    void beforeStartTherapyProcedure();

private:
    Ui::MaskDryOptionsBasic *ui;
    PruControlClass * m_IpcManager;

    bool maskDryStatus;
    WaitingSpinnerWidget * spinner;
    QTimer * m_Timer;
    int m_TimerSeconds;

};

#endif // MASKDRYOPTIONSBASIC_H
