#ifndef ENTERSERIALNUMBER_H
#define ENTERSERIALNUMBER_H


#include <QDialog>
#include <QGraphicsColorizeEffect>

#define SERIAL_NUMBER_MAX_CHAR  16

namespace Ui {
class EnterSerialNumber;
}
class DataValidation;

class EnterSerialNumber : public QDialog
{
    Q_OBJECT

public:
    explicit EnterSerialNumber(QWidget *parent,
                               DataValidation * dataValidationBackend);
    ~EnterSerialNumber();

    void changeEvent(QEvent* e);
    QGraphicsColorizeEffect * parentEffect;

    static int bkupSerialNumber[SERIAL_NUMBER_MAX_CHAR];
    static int serialNumber[SERIAL_NUMBER_MAX_CHAR];
    static int serialNumberIndex;
    static int serialNumberInputIndex;

    void addDigitInSerialNumber(int number);
    void convertInToString(void);
    void updateWarningText(int state);
    void updateEnterSerialNumberScreenBeforeShow(void);
    int compareSerialNumber(void);


signals:
    void dialogClose();

    void writeDeviceInformationToEeprom(void);

public slots:
    void showEnterSerialNumberScreen();

private slots:
    void on_digit1_pressed();

    void on_digit2_pressed();

    void on_digit3_pressed();

    void on_digit4_pressed();

    void on_digit5_pressed();

    void on_digit6_pressed();

    void on_digit7_pressed();

    void on_digit8_pressed();

    void on_digit9_pressed();

    void on_digit0_pressed();

    void on_backSpace_pressed();

    void on_serialNumberAccept_released();

    void on_serialNumberCancel_released();

private:
    Ui::EnterSerialNumber *ui;
    DataValidation * dataValidation;

};

#endif // ENTERSERIALNUMBER_H
