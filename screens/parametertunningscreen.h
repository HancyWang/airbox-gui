#ifndef PARAMETERTUNNINGSCREEN_H
#define PARAMETERTUNNINGSCREEN_H



#include <QDialog>
#include <QPushButton>


enum {
    TUNE_BUFFER_SIZE=1,
    TUNE_APNEA,
    TUNE_PRECURSOR,
    TUNE_W1,
    TUNE_W2,
    TUNE_VARIABLE1,
    TUNE_FLOW_COFF,
    TUNE_MAX_ENABLE_TIME,
    TUNE_EN_IF_STABLE,
    TUNE_CURRENT_FLOW_AVG,
    TUNE_NO_EVENT_FOR_TIME,
    TUNE_EVENT_THRESHOLD,
    TUNE_APNEA_INCREMENT,
    TUNE_APNEA2_INCREMENT,
    TUNE_HYPOAPNEA_INCREMENT,
    TUNE_PRECURSOR_INCREMENT,
    TUNE_APNEA2_THRESHOLD_COUNT,
    TUNE_LEAK2_THRESHOLD_COUNT,
    TUNE_LEAK_ALGORITHM_EN,
    TUNE_LEAK_FLOW_MULTIPLIER,
    TUNE_LEAK2_FLOW_MULTIPLIER,
    TUNE_APNEA2_FLOW_MULTIPLIER,
    TUNE_FLOW_COFF_EVENT_DETECTION,

    TUNE_PRE_CURSOR_THRESHOLD45,
    TUNE_PRE_CURSOR_THRESHOLD67,
    TUNE_PRE_CURSOR_THRESHOLD89,
    TUNE_PRE_CURSOR_THRESHOLD1011,
    TUNE_PRE_CURSOR_THRESHOLD1213,
    TUNE_PRE_CURSOR_THRESHOLD1415,
    TUNE_PRE_CURSOR_THRESHOLD1617,
    TUNE_PRE_CURSOR_THRESHOLD1819,
    TUNE_PRE_CURSOR_THRESHOLD20,
    TUNE_REFERENCE_WINDOW,

    TUNE_APNEA_THRESHOLD1011,
    TUNE_APNEA_THRESHOLD1213,
    TUNE_APNEA_THRESHOLD1415,
    TUNE_APNEA_THRESHOLD1617,
    TUNE_APNEA_THRESHOLD1819,
    TUNE_APNEA_THRESHOLD20,
    TUNE_APNEA_THRESHOLD45,
    TUNE_APNEA_THRESHOLD67,
    TUNE_APNEA_THRESHOLD89,

//    TUNE_PRE_CURSOR_THRESHOLDA,
//    TUNE_PRE_CURSOR_THRESHOLDB,
//    TUNE_PRE_CURSOR_THRESHOLDC,

    TUNE_ALGO2_BUFFER_SIZE,
    TUNE_FLOW_BARREL_TYPE,
    TUNE_MAX_CHANGE_PARAM
};

namespace Ui {
class ParameterTunningScreen;
}

class PruControlClass;
class TherapyWindowBasic;
class RestoreDefaultsWindowClinical;
class DataValidation;
class ManufacturingOptionsScreen;


class ParameterTunningScreen : public QDialog
{
    Q_OBJECT

public:
    explicit ParameterTunningScreen(QWidget *parent,
                                    PruControlClass * m_IpcBackend,
                                    TherapyWindowBasic * therapyBasicBackend,
                                    RestoreDefaultsWindowClinical * restoreDefaultBackend,
                                    DataValidation * dataValidationBackend,
                                    ManufacturingOptionsScreen * manufacturingOptionsBackend);
    ~ParameterTunningScreen();

    void updateParamOnValue(unsigned int value);
    void updateParamValueText(void);

    void validateTuneEepromData(void);

    QTimer * tLocalTimer;
    void changeEvent(QEvent* e);
signals:
    void updateTunningParameter(int * param);

    void updateFlowThreshold(int threshold);

    void writeParameterToEeprom(void);

    void readTunningParameterFromEeprom(void);

    void writeTuneParameterToEeprom(int * tuneParam);

private slots:
    void on_backParameterTunning_released();

    void on_paramIncrement_pressed();

    void on_paramDecrement_pressed();

    void sendTunningParametersFirstTime();

    void on_TuneButtonClicked();

public slots:
    void restoreDefaultTunningParametersBarrelType0(void);

    void updateTunningParametersFromEeprom(QStringList & listTuneData);

    void showParameterTunningScreen(QWidget * parent);

    void sendTunningParameterToPRU(void);

    void restoreDefaultTunningParametersBarrelType1();

    void updateFlowBarrelTypeAndDefaultData();
private:
    Ui::ParameterTunningScreen *ui;
    PruControlClass * m_IpcManager;
    TherapyWindowBasic * therapyBasicScreen;
    RestoreDefaultsWindowClinical * restoreDefaultScreen;
    DataValidation * dataValidation;
    ManufacturingOptionsScreen * manufacturingOptionsScreen;

    QPushButton * tuneButtons[TUNE_MAX_CHANGE_PARAM];

    static const QStringList parametrTitle;
    int valueParam[TUNE_MAX_CHANGE_PARAM];
    int minValueParam[TUNE_MAX_CHANGE_PARAM];
    int maxValueParam[TUNE_MAX_CHANGE_PARAM];
    int indexChangeParam=0;

};

#endif // PARAMETERTUNNINGSCREEN_H
