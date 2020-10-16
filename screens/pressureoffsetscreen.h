#ifndef PRESSUREOFFSETSCREEN_H
#define PRESSUREOFFSETSCREEN_H


#include <QDialog>
#include <QGraphicsColorizeEffect>

namespace Ui {
class PressureOffsetScreen;
}

class PruControlClass;
class DataValidation;

class PressureOffsetScreen : public QDialog
{
    Q_OBJECT

public:
    explicit PressureOffsetScreen(QWidget *parent,
                                  PruControlClass * m_IpcBackend,
                                  DataValidation * dataValidationBackend);
    ~PressureOffsetScreen();

    QGraphicsColorizeEffect * parentEffect;

    void updatePressureSensorOffsetScreenBeforeShow();
    void changeEvent(QEvent* e);
signals:
    void dialogClose();

    void beforePressureOffsetGetProcedure(void);

    void writeParameterToEeprom(void);

public slots:
    void showPressureOffsetScreen();

private slots:
    void on_pressureOffsetAuto_pressed();

    void on_pressureOffsetAccept_released();

    void on_pressureOffsetCancel_released();

    void on_pressureOffsetDecrease_released();

    void on_pressureOffsetIncrease_released();

    void updatePressureSensorOffset(int offset);

private:
    Ui::PressureOffsetScreen *ui;
    PruControlClass * m_IpcManager;
    DataValidation * dataValidation;

    static int pressureOffset;

};

#endif // PRESSUREOFFSETSCREEN_H
