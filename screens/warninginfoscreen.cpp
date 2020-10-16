#include "warninginfoscreen.h"
#include "ui_warninginfoscreen.h"
#include "ex_variables.h"

WarningInfoScreen::WarningInfoScreen(QWidget *parent,
                                     PruControlClass * m_IpcBackend,
                                     TherapyWindowBasic * therapyBasicBackend)
    : QDialog(parent),
    ui(new Ui::WarningInfoScreen),
    m_IpcManager(m_IpcBackend),
    therapyBasicScreen(therapyBasicBackend),
    parentEffect(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setAttribute(Qt::WA_TranslucentBackground,true);
    move(60,56);

    if(m_IpcManager)
    {
        connect(this,SIGNAL(beforeStartTherapyProcedure()),
                m_IpcManager,SLOT(beforeStartTherapyProcedure()));
        connect(m_IpcManager,SIGNAL(updateAndShowScreen(int*,int)),
                this,SLOT(updateAndShowScreen(int*,int)));
    }

    if(therapyBasicScreen)
    {
        connect(this,SIGNAL(updateStartStopTherapyDetails()),
                therapyBasicScreen,SLOT(updateStartStopTherapyDetails()));
    }

    warningLogFile.setFileName(Providers::getErrorLogFilesPath());

    if(disabledTimer.isActive())
        disabledTimer.stop();

    disabledTimer.setSingleShot(true);
    connect(&disabledTimer,SIGNAL(timeout()),this,SLOT(on_disabledTimerTimeout()));
}

WarningInfoScreen::~WarningInfoScreen()
{
    delete ui;
}

const QStringList WarningInfoScreen::buttonTitle = {
    "Power Off",
    "Close"
};

enum ErrorHandling {
    POWER_OFF_DEVICE,
    CLOSE_DEVICE
};

const QStringList WarningInfoScreen::tWarningMessage = {
    " ",
    "E01 \nRestart Device \nor  \nRefer to User Guide",
    "E02 \nRestart Device \nor  \nRefer to User Guide",
    "E03 \nRestart Device \nor  \nRefer to User Guide",
    "E04 \nRestart Device \nor  \nRefer to User Guide",
    "E05 \nRestart Device \nor  \nRefer to User Guide",
    "E06 \nRestart Device \nor  \nRefer to User Guide",
    "E07 \nRestart Device \nor  \nRefer to User Guide",
    "E08 - Blower Fault",//"E08 \nRestart Device \nor  \nRefer to User Guide"
    "E09 \nRestart Device \nor  \nRefer to User Guide",
    "E10 \nRestart Device \nor  \nRefer to User Guide",
    "E11 \nRestart Device \nor  \nRefer to User Guide",
    "E12 \nRestart Device \nor  \nRefer to User Guide",
    "E13 \nRestart Device \nor  \nRefer to User Guide",
    "E14 \nRestart Device \nor  \nRefer to User Guide",
    "E15 \nRestart Device \nor  \nRefer to User Guide",
    "E16 \nRestart Device \nor  \nRefer to User Guide",
    "E17 \nRestart Device \nor  \nRefer to User Guide",
    "E18 \nRestart Device \nor  \nRefer to User Guide",
    "E19 \nSleep Report Error \nor  \nRefer to User Guide",
    "E20 \nRestart Device \nor  \nRefer to User Guide",
    "E21 \nRestart Device \nor  \nRefer to User Guide",
    "E22 \nRestart Device \nor  \nRefer to User Guide",
    "E23 \nRestart Device \nor  \nRefer to User Guide",
};

void WarningInfoScreen::updateAndShowScreen(int * tArray,int tCount)
{
//    if(isErrorsAreSame(tArray,tCount))
//    {
//        return;
//    }

    tDeviceNeedToBePoweredOff = false;

    bool canRun = verifyIfBlowerCanRun(tArray,tCount);
    if(canRun == false)
    {
        // Stop therapy due to leakage process is true
        if(globalVar.therapyState == On)
        {
            globalVar.therapyState = Off;
            emit updateStartStopTherapyDetails();
            emit beforeStartTherapyProcedure();
            globalVar.rgbColorMode = RGB_COLOR_DEVICE_IN_USE;

            if(isRotorLocked == true)
            {
                m_RotorLockCount++;
                if(m_RotorLockCount >= 3)
                {
                    ui->closeButton->hide();
                    m_RotorLockCount = 0;
                    int tTimeout = 60 * 60 * 1000;
                    disabledTimer.start(tTimeout);
                }
            }
        }

        if(!isVisible())
        {
            ui->closeButton->setText(buttonTitle.at(CLOSE_DEVICE));

            parentEffect->setEnabled(true);
            setModal(true);

            if(isRotorLocked == true)
                showErrorOnScreen(ROTOR_LOCK_CONDITION_ERROR);
            else
                showErrorOnScreen(tArray[0]);

            logErrorsInFile(tArray,tCount);
        }
    }
}

void WarningInfoScreen::on_disabledTimerTimeout()
{
    if(disabledTimer.isActive())
        disabledTimer.stop();

    ui->closeButton->show();
}

/* Return false if therapy need to be stop */
bool WarningInfoScreen::verifyIfBlowerCanRun(int * tBuffer,int tTotalErrors)
{
    bool canTherapyRun=true;
    int i=0;

    isRotorLocked = false;

    for(i = 0 ; i< tTotalErrors ; i++)
    {
        /* We can run bldc motor on this errors */
//        if(tBuffer[i] == RTC_FAULTY_ERROR)                  canTherapyRun = true;
//        if(tBuffer[i] == TOUCHSCREEN_FAULTY_ERROR)          canTherapyRun = true;
//        if(tBuffer[i] == AMBIENT_SENSOR_FAULTY_ERROR)       canTherapyRun = true;

        /* We can not run bldc motor on this errors */
        if(tBuffer[i] == BLOWER_IC_FAULTY_ERROR)            canTherapyRun = false;
        if(tBuffer[i] == MOTOR_OVERCURRENT_ERROR)           canTherapyRun = false;
        if(tBuffer[i] == CHARGE_PUMP_OVERCURRENT_ERROR)     canTherapyRun = false;
        if(tBuffer[i] == OVERTEMP_SHUTDOWN_ERROR)           canTherapyRun = false;
        if(tBuffer[i] == VM_UNDERVOLTAGE_ERROR)             canTherapyRun = false;
        if(tBuffer[i] == CHARGEPUMP_UNDERVOLTAGE_ERROR)     canTherapyRun = false;
        if(tBuffer[i] == VM_OVERVOLTAGE_ERROR)              canTherapyRun = false;
        if(tBuffer[i] == ROTOR_LOCK_CONDITION_ERROR){
            isRotorLocked = true;
            canTherapyRun = false;
        }
        if(tBuffer[i] == HIGH_MOTOR_TEMPERATURE_ERROR)      canTherapyRun = false;
        if(tBuffer[i] == INPUT_VOLTAGE_HIGH_ERROR)          canTherapyRun = false;
        if(tBuffer[i] == INPUT_VOLTAGE_LOW_ERROR)           canTherapyRun = false;
        if(tBuffer[i] == PRESSURE_SENSOR_FAULTY_ERROR)      canTherapyRun = false;
        if(tBuffer[i] == BLOWER_OVER_CURRENT_ERROR)         canTherapyRun = false;
        if(tBuffer[i] == MCP3204_MEASUREMENT_INVALID_ERROR) canTherapyRun = false;
        if(tBuffer[i] == MCP3202_MEASUREMENT_INVALID_ERROR) canTherapyRun = false;
        if(tBuffer[i] == SPI_BUS_FAULT_ERROR)               canTherapyRun = false;
        if(tBuffer[i] == FLOW_SENSOR_FAULT_ERROR)           canTherapyRun = false;
        if(tBuffer[i] == I2C1_BUS_FAULT_ERROR)              canTherapyRun = false;
        if(tBuffer[i] == EEPROM_FAULTY_ERROR)               canTherapyRun = false;
        if(tBuffer[i] == I2C0_BUS_FAULTY_ERROR)             canTherapyRun = false;
    }

    return canTherapyRun;
}

void WarningInfoScreen::parseAndUpdateErrorData(unsigned int * tBuffer)
{
    int tTotalErrors = tBuffer[5];
    if(tTotalErrors)
    {
        /* Package contains errors */
        int i=0;
        unsigned int tErrorCodeArray[tTotalErrors];
        for(i=0 ; i< tTotalErrors ; i++)
        {
            tErrorCodeArray[i] = tBuffer[6 + i];
        }

//        qDebug() << "F :" << tTotalErrors << tErrorCodeArray[0];

        processError(tErrorCodeArray,tTotalErrors);
//        if(!this->isVisible()){
//            Providers::pBackgroundScreen->warningInfoScreen->parentEffect = Providers::pBackgroundScreen->getAndEnableBackgoundColorEffect();;
//            Providers::pBackgroundScreen->warningInfoScreen->setModal(true);

//            bool tBldcStatus=false;
//            /* If we can not run motor with this error
//             * then stop therapy
//             */
//            tBldcStatus = verifyIfBlowerCanRun(tErrorCodeArray,tTotalErrors);

//            /* Return false if therapy need to be stop */
//            if(tBldcStatus == false){
//                /* Stop Therapy */
//                globalVar.therapyState = Off;
//                Providers::pBackgroundScreen->therapyWindowBasicScreen->processStartStopTherapy();
//                ui->closeButton->setText(buttonTitle.at(POWER_OFF_DEVICE));
//                tDeviceNeedToBePoweredOff = true;
//            } else {
//                ui->closeButton->setText(buttonTitle.at(CLOSE_DEVICE));
//                tDeviceNeedToBePoweredOff = false;
//            }

//            showErrorOnScreen(tErrorCodeArray[0]);
//            logErrorsInFile(tErrorCodeArray,tTotalErrors);
//        }
    }
}

bool WarningInfoScreen::isErrorsAreSame(int * tArray,int tCount)
{
    if(tErrorCount != tCount)
        return false;

    for(int i=0 ; i<tCount ; i++)
    {
        if(tErrors[i] != tArray[i])
            return false;
    }

return true;
}

void WarningInfoScreen::processError(unsigned int * tErrorCodeArray,int tTotalErrors)
{
//    if(!this->isVisible()){
//        Providers::pBackgroundScreen->warningInfoScreen->parentEffect = Providers::pBackgroundScreen->getAndEnableBackgoundColorEffect();;
//        Providers::pBackgroundScreen->warningInfoScreen->setModal(true);

//        bool tBldcStatus=false;
//        /* If we can not run motor with this error
//         * then stop therapy
//         */
//        tBldcStatus = verifyIfBlowerCanRun(tErrorCodeArray,tTotalErrors);

//        /* Return false if therapy need to be stop */
//        if(tBldcStatus == false){
//            /* Stop Therapy */
//            globalVar.therapyState = Off;
//            Providers::pBackgroundScreen->therapyWindowBasicScreen->processStartStopTherapy();
//            ui->closeButton->setText(buttonTitle.at(POWER_OFF_DEVICE));
//            tDeviceNeedToBePoweredOff = true;
//        } else {
//            ui->closeButton->setText(buttonTitle.at(CLOSE_DEVICE));
//            tDeviceNeedToBePoweredOff = false;
//        }

//        showErrorOnScreen(tErrorCodeArray[0]);
//        logErrorsInFile(tErrorCodeArray,tTotalErrors);
//    }
}
void WarningInfoScreen::logErrorsInFile(int * tBuffer,int tTotalNumber)
{
    QString tErrorStr;
    for(int i = 0 ; i < tTotalNumber ; i++)
    {
        tErrorStr += QString::number(tBuffer[i]) + " ";
    }
    warningLogFile.open(QIODevice::Append | QIODevice::WriteOnly);
    warningLogFile.seek(warningLogFile.size());
    QTextStream outStream(&warningLogFile);

    QString errorStr = QString("%1 %2 %3\n").arg(QDate::currentDate().toString("yyyy-MM-dd")).arg(QTime::currentTime().toString("hh:mm:ss")).arg(tErrorStr);
//    QString errorStr = QString("%1 %2 %3\n").arg(QDate::currentDate().toString("yyyy-MM-dd")).arg(QTime::currentTime().toString("hh:mm:ss")).arg(tErrorCode);
    outStream << errorStr;

    warningLogFile.close();
}

void WarningInfoScreen::showErrorOnScreen(int tErrorCode)
{
    ui->warningText->setText(tWarningMessage.at(tErrorCode));
    this->show();
}

void WarningInfoScreen::on_closeButton_clicked()
{
    if(tDeviceNeedToBePoweredOff == true)
    {
        emit startPowerOffProcedure();
    }
    else
    {
        parentEffect->setEnabled(false);
        hide();
    }
}

void WarningInfoScreen::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
