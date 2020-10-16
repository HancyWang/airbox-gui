#ifndef MASKFITTESTOPTIONSBASIC_H
#define MASKFITTESTOPTIONSBASIC_H

#include <QDialog>
#include <QGraphicsColorizeEffect>

#include "application.h"

namespace Ui {
class MaskFitTestOptionsBasic;
}

class MaskFitTestOptionsBasic : public QDialog
{
    Q_OBJECT

public:
    explicit MaskFitTestOptionsBasic(QWidget *parent = 0);
    ~MaskFitTestOptionsBasic();

    QGraphicsColorizeEffect * parentEffect;

    void updateProgressBarAsPerSeconds(int seconds,unsigned int status);
    void updateStartStopButton(void);
    void updateMaskFitTestProcessBeforeShow(void);
    void changeEvent(QEvent* e);
signals:
    void dialogClose();

private slots:
    void on_maskFitTestStartStop_released();

    void on_maskFitTestCancel_released();

    void showMaskFitTestScreen();

private:
    Ui::MaskFitTestOptionsBasic *ui;

    maskFitParam maskFitTest;
    bool maskFitTestState;

};

#endif // MASKFITTESTOPTIONSBASIC_H
