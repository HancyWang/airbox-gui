#ifndef MANUFACTURINGOPTIONSSCREEN_H
#define MANUFACTURINGOPTIONSSCREEN_H

#include <QDialog>
#include <QPropertyAnimation>

#include "widgets/button1.h"
#include "constants.h"

namespace Ui {
class ManufacturingOptionsScreen;
}

class PasswordCheckScreen;
class SettingsWindowClinical;
class DiagnosticDataScreen;

class ManufacturingOptionsScreen : public QDialog
{
    Q_OBJECT

public:
    explicit ManufacturingOptionsScreen(QWidget *parent,
                                        PasswordCheckScreen * passwordCheckBackend,
                                        SettingsWindowClinical * settingsClinicalBackend,
                                        DiagnosticDataScreen * diagnosticDataWindowBackend);
    ~ManufacturingOptionsScreen();


    void addButtonsManufacturingOptions(void);
    void updateButton1Details(Button1 * pButton,const QString &Title,const QString &imageLeft,const QString &imageRight);
    void animateManufacturingOptionsWindow(const openCloseStatus &state);
    void updateManufacturingOptionsProcessBeforeShow(void);
    void changeEvent(QEvent* e);
    void updateText();
private slots:
    void on_backManufacturingOptions_released();
    void menufacturingDiagButton_released();
    void menufacturingSetupButton_released();
    void blowerTestButton_released();
    void parameterTuneButton_released();
    void diagnosticData_released();

    void passwordCheckWindowClosed();
    void diagnosticDataClosed();

public slots:
    void showManufacturingOptionsScreen(QWidget *parent);

signals:
    void showPasswordEnterScreen(const int *password);

    void showManufacturingDiagnosisScreen();

    void showManufacturingSetupScreen();

    void showParameterTunningScreen(void);

    void showBlowerTestScreen();

    void showDiagnosticDataScreen();

private:
    Ui::ManufacturingOptionsScreen *ui;
    PasswordCheckScreen * passwordCheckScreen;
    SettingsWindowClinical * settingsClinicalScreen;
    DiagnosticDataScreen * diagnosticDataWindowScreen;

    QPropertyAnimation * m_Anim;

    Button1 * menufacturingDiagButton;
    Button1 * menufacturingSetupButton;
    Button1 * blowerTestButton;
    Button1 * parameterTuneButton;
    Button1 * diagnosticData;

    static const int tuneParameterPassword[9];
};

#endif // MANUFACTURINGOPTIONSSCREEN_H
