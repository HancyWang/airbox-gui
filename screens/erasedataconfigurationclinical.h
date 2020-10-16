#ifndef ERASEDATACONFIGURATIONCLINICAL_H
#define ERASEDATACONFIGURATIONCLINICAL_H


#include <QDialog>
#include <QGraphicsColorizeEffect>

namespace Ui {
class EraseDataConfigurationClinical;
}

class EraseDataConfigurationClinical : public QDialog
{
    Q_OBJECT

public:
    explicit EraseDataConfigurationClinical(QWidget *parent = 0);
    ~EraseDataConfigurationClinical();

    QGraphicsColorizeEffect * parentEffect;

    void eraseAllFiles(void);
    void changeEvent(QEvent* e);
private slots:
    void on_eraseDataYes_released();

    void on_eraseDataNo_released();

    void showEraseDataScreen();

private:
    Ui::EraseDataConfigurationClinical *ui;
};

#endif // ERASEDATACONFIGURATIONCLINICAL_H
