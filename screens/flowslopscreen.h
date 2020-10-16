#ifndef FLOWSLOPSCREEN_H
#define FLOWSLOPSCREEN_H

#include <QDialog>
#include <QGraphicsColorizeEffect>

namespace Ui {
class FlowSlopScreen;
}

class DataValidation;

class FlowSlopScreen : public QDialog
{
    Q_OBJECT

public:
    explicit FlowSlopScreen(QWidget *parent,
                            DataValidation * dataValidationBackend);
    ~FlowSlopScreen();

    void updateFlowSensorSlopScreenBeforeShow();
    void updateFlowSensorSlop(int slop);

    int flowSlop;
    QGraphicsColorizeEffect * parentEffect;
    void changeEvent(QEvent* e);
signals:
    void dialogClose();
    void writeParameterToEeprom(void);

public slots:
    void showFlowSlopScreen();

private slots:
    void on_flowSlopDecrease_released();

    void on_flowSlopIncrease_released();

    void on_flowSlopAccept_released();

    void on_flowSlopCancel_released();

private:
    Ui::FlowSlopScreen *ui;
    DataValidation * dataValidation;

};

#endif // FLOWSLOPSCREEN_H
