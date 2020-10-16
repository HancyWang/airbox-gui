#ifndef MASKWINDOWREMINDERCLINICAL_H
#define MASKWINDOWREMINDERCLINICAL_H


#include <QDialog>
#include <QGraphicsColorizeEffect>

namespace Ui {
class MaskWindowReminderClinical;
}

class DateWindowClinical;
class DataValidation;

class MaskWindowReminderClinical : public QDialog
{
    Q_OBJECT

public:
    explicit MaskWindowReminderClinical(QWidget *parent,
                                        DateWindowClinical * dateScreenBackend,
                                        DataValidation * dataValidationBackend);
    ~MaskWindowReminderClinical();

    void updateMaskWindowReminderProcessBeforeShow(void);
    void updateMaskDuration(int duration);
    void updateMaskSetStartDate(int mDate,int mMonth,int mYear);
    QGraphicsColorizeEffect * parentEffect;
    void changeEvent(QEvent* e);
signals:
    void showDateScreen(QWidget *parent, int date, int month, int year, bool colorEffect);
    void writeParameterToEeprom(void);

public slots:
    void showMaskReminderScreen();

private slots:
    void on_maskAccept_released();

    void on_maskCancel_released();

    void on_maskSetDate_released();

    void dateWindowClosed(int date, int month, int year);

    void on_maskIncrement_pressed();

    void on_maskDecrement_pressed();

private:
    Ui::MaskWindowReminderClinical *ui;
    DateWindowClinical * dateScreen;
    DataValidation * dataValidation;

    int maskDuration;
    static int localDate;
    static int localMonth;
    static int localYear;
};

#endif // MASKWINDOWREMINDERCLINICAL_H
