#ifndef ACCESSORIESWINDOWCLINICAL_H
#define ACCESSORIESWINDOWCLINICAL_H

#include <QDialog>
#include <QPropertyAnimation>
#include "widgets/button1.h"
#include "constants.h"

namespace Ui {
class AccessoriesWindowClinical;
}

class SettingsWindowClinical;

class AccessoriesWindowClinical : public QDialog
{
    Q_OBJECT

public:
    explicit AccessoriesWindowClinical(QWidget *parent,
                                       SettingsWindowClinical * settingsClinicalBackend);
    ~AccessoriesWindowClinical();

    void addButtons(void);
    void updateButton1Details(Button1 * pButton,const QString &Title,const QString &imageLeft,const QString &imageRight);
    void animateSettingsWindow(openCloseStatus state);
    void updateAccessoriesWindowClinicalProcessBeforeShow(void);
    void changeEvent(QEvent* e);
    void updateText();
signals:
    void showAirFilterWindowClinical();

public slots:
    void showAccesoriesClinicalScreen();

private slots:
    void on_backAccessories_released();
    void airTubeButton_released();
    void airFilterButton_released();
    void airFilterWindowClosed();

private:
    Ui::AccessoriesWindowClinical *ui;
    SettingsWindowClinical * settingsClinicalScreen;

    QPropertyAnimation * m_Anim;

    Button1 * airTubeButton;
    Button1 * airFilterButton;
};

#endif // ACCESSORIESWINDOWCLINICAL_H
