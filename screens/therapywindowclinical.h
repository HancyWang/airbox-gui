#ifndef THERAPYWINDOWCLINICAL_H
#define THERAPYWINDOWCLINICAL_H

#include <QDialog>
#include <QPropertyAnimation>

#include "constants.h"
#include "widgets/button1.h"

namespace Ui {
class TherapyWindowClinical;
}

class SettingsWindowClinical;
class SetPressureClinical;
class ModeWindowTherapyClinical;
class MaskOptionsTherapyWindowClinical;
class SetMinPressureClinical;
class SetMaxPressureClinical;

class TherapyWindowClinical : public QDialog
{
    Q_OBJECT

public:
    explicit TherapyWindowClinical(QWidget *parent,
                                   SettingsWindowClinical * settingsClinicalBackend,
                                   SetPressureClinical * setPressureBackend,
                                   ModeWindowTherapyClinical * modeBackend,
                                   MaskOptionsTherapyWindowClinical * maskClinicalBackend,
                                   SetMinPressureClinical * minPressureBackend,
                                   SetMaxPressureClinical * maxPressureBackend);
    ~TherapyWindowClinical();

    void addButtons(void);
    void animateSettingsWindow(openCloseStatus state);
    void updateButton1Details(Button1 * pButton,const QString &Title,const QString &imageLeft,const QString &imageRight);

    void updateSetPressureInTherapyWindow(void);
    void updateSetMinPressureInTherapyWindow(void);
    void updateSetMaxPressureInTherapyWindow(void);
    void updateModeInTherapyWindow(void);
    void updateMaskInTherapyWindow(void);
    void updateTherapyWindowProcessBeforeShow(void);

    void updateScrollbarView(void);
    void changeEvent(QEvent* e);
    void updateText();
signals:
    void showSetPressureScreen();

    void showModeScreen();

    void showMaskOptionClinicalScreen();

    void showMinPressureScreen();

    void showMaxPressureScreen();

public slots:
    void showTherapyClinicalScreen();

    void setPressureClosed();

    void modeWindowClosed();

    void minPressureClosed();

    void maxPressureClosed();

private slots:
    void on_backTherapy_released();
    void setPressureButton_released();
    void modeButton_released();
    void maskButton_released();
    void maskButtonClosed();
    void minPressureButton_released();
    void maxPressureButton_released();


private:
    Ui::TherapyWindowClinical *ui;
    SettingsWindowClinical * settingsClinicalScreen;
    SetPressureClinical * setPressureScreen;
    ModeWindowTherapyClinical * modeScreen;
    MaskOptionsTherapyWindowClinical * maskClinicalScreen;
    SetMinPressureClinical * minPressureScreen;
    SetMaxPressureClinical * maxPressureScreen;

    QPropertyAnimation * m_Anim;

    Button1 * modeButton;
    Button1 * setPressureButton;
    Button1 * maskButton;
    Button1 * minPressureButton;
    Button1 * maxPressureButton;

    static const QStringList modeString;

};

#endif // THERAPYWINDOWCLINICAL_H
