#include "manufacturingdiagnosisscreen.h"
#include "ui_manufacturingdiagnosisscreen.h"
#include "ex_variables.h"



#define P_SLOP  758
#define F_SLOP  240
#define MOTOR_TEMP_COEFF_A      349
#define MOTOR_TEMP_COEFF_B      -38.66

int ManufacturingDiagnosisScreen::blowerSpeed = 1300;
bool ManufacturingDiagnosisScreen::blowerState = false;

ManufacturingDiagnosisScreen::ManufacturingDiagnosisScreen(QWidget *parent,
                                                           PruControlClass * m_IpcBackend,
                                                           ManufacturingOptionsScreen * manufacturingOptionsBackend)
    : QDialog(parent),
    ui(new Ui::ManufacturingDiagnosisScreen),
    m_IpcManager(m_IpcBackend),
    manufacturingOptionsScreen(manufacturingOptionsBackend)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setWindowState(Qt::WindowFullScreen);
    setGeometry(0,0,width(),height());

    if(m_IpcManager)
    {
        connect(this,SIGNAL(beforeManufacturingModeProcedure(int,int,int)),
                m_IpcManager,SLOT(beforeManufacturingModeProcedure(int,int,int)));
        connect(m_IpcManager,SIGNAL(updateScreenAsPerReceivedPacket(uint*)),
                this,SLOT(updateScreenAsPerReceivedPacket(uint*)));
    }

    if(manufacturingOptionsScreen)
    {
        connect(manufacturingOptionsScreen,SIGNAL(showManufacturingDiagnosisScreen()),
                this,SLOT(showManufacturingDiagnosisScreen()));
    }

    ui->bldcCurrentFrame->setFixedHeight(40);
    ui->blowerSpeedFBFrame->setFixedHeight(40);
    ui->flowFrame->setFixedHeight(40);
    ui->lightIntensityFrame->setFixedHeight(40);
    ui->motorTemFrame->setFixedHeight(40);
    ui->pressureFrame->setFixedHeight(40);
    ui->voltageInputFrame->setFixedHeight(40);

    ui->faultManufacturingDiagnosis->hide();

    QFont title("Roboto-Light",12);
    ui->titleManufacturingDiagnosis->setFont(title);

    QFont unit("Roboto-Light",6);
    QFont value("Roboto-Thin",10);

    title.setPointSize(8);
    ui->pressureTitle->setFont(title);
    ui->floTitle->setFont(title);
    ui->blowerFBTitle->setFont(title);
    ui->motorTempTitle->setFont(title);
    ui->voltageInputTitle->setFont(title);
    ui->bldcCurrentTitle->setFont(title);
    ui->lightIntensityTitle->setFont(title);

    ui->pressureValue->setFont(value);
    ui->flowValue->setFont(value);
    ui->blowerFBValue->setFont(value);
    ui->motorTempValue->setFont(value);
    ui->voltageInputValue->setFont(value);
    ui->bldcCurrentValue->setFont(value);
    ui->lightIntensityValue->setFont(value);

    ui->pressureUnit->setFont(unit);
    ui->flowUnit->setFont(unit);
    ui->blowerFBUnit->setFont(unit);
    ui->motorTempUnit->setFont(unit);
    ui->voltageInputUnit->setFont(unit);
    ui->bldcCurrentUnit->setFont(unit);
    ui->lightIntensityUnit->setFont(unit);

    ui->scrollAreaWidgetContentsDiagnosis->setLayout(ui->verticalLayoutDiagnosis);
    ui->scrollAreaDiagnosis->setStyleSheet(QStringLiteral("border:none;"));

    //Enable Scrolling mechanism for scroll area
    QScroller::grabGesture(ui->scrollAreaDiagnosis->viewport(),QScroller::LeftMouseButtonGesture);
}

ManufacturingDiagnosisScreen::~ManufacturingDiagnosisScreen()
{
    delete ui;
}

void ManufacturingDiagnosisScreen::on_startBlowerButton_released()
{
    updateStartStopButton();
}

void ManufacturingDiagnosisScreen::manufacturingModeProcessBeforeShow(void)
{
    globalVar.isManuFacturingModeEnabled = true;

    QString str = QString::number(blowerSpeed);
    ui->valueBlowerSpeed->setText(str);
    ui->pressureValue->setText("0/0");
    ui->flowValue->setText("0/0");
    ui->blowerFBValue->setText("0/0");
    ui->motorTempValue->setText("0/0");
    ui->voltageInputValue->setText("0/0");
    ui->bldcCurrentValue->setText("0/0");
    ui->lightIntensityValue->setText("0");

    emit beforeManufacturingModeProcedure(1,0,0);
}

void ManufacturingDiagnosisScreen::manufacturingModeProcessBeforeExit(void)
{
    globalVar.isManuFacturingModeEnabled = false;
    updateStartStopButton();
}

void ManufacturingDiagnosisScreen::updateStartStopButton(void)
{
    blowerState = !blowerState;
    if(blowerState)
        ui->startBlowerButton->setText("Stop");
    else
        ui->startBlowerButton->setText("Start");

    emit beforeManufacturingModeProcedure(1,blowerState,blowerSpeed);
}

void ManufacturingDiagnosisScreen::on_decrementBlowerSpeed_pressed()
{
    if(blowerSpeed > 0)
    {
        blowerSpeed -= 5;
        if(blowerSpeed < 0)     blowerSpeed = 0;
        QString str = QString::number(blowerSpeed);
        ui->valueBlowerSpeed->setText(str);
        emit beforeManufacturingModeProcedure(1,blowerState,blowerSpeed);
    }
}

void ManufacturingDiagnosisScreen::on_incrementBlowerSpeed_pressed()
{
    if(blowerSpeed < 4096)
    {
        blowerSpeed += 5;
        if(blowerSpeed > 4095)     blowerSpeed = 4095;
        QString str = QString::number(blowerSpeed);
        ui->valueBlowerSpeed->setText(str);
        emit beforeManufacturingModeProcedure(1,blowerState,blowerSpeed);
    }
}

void ManufacturingDiagnosisScreen::on_backManufacturingDiagnosis_released()
{
    manufacturingModeProcessBeforeExit();
    emit beforeManufacturingModeProcedure(0,0,0);
    hide();
}

void ManufacturingDiagnosisScreen::showManufacturingDiagnosisScreen()
{
    manufacturingModeProcessBeforeShow();
    show();
}

void ManufacturingDiagnosisScreen::updateScreenAsPerReceivedPacket(unsigned int * localBuf)
{
    QString localStr;
    Providers providers;

    int pressureRaw=0;
    double pressureEng=0;
    pressureRaw = static_cast<int>(localBuf[IPC_PRESSURE_RAW]);
//    pressureEng = static_cast<double>((pressureRaw - globalVar.pressure.pressureOffset) * 10)/P_SLOP;
    pressureEng = providers.getPressureRawToEngineeringWithSlopValues(pressureRaw);
    localStr.sprintf("%4d/%1.2f",pressureRaw,pressureEng);
    ui->pressureValue->setText(localStr);

    int flowRaw=0;
    double flowEng=0;
    flowRaw = static_cast<int>(localBuf[IPC_FLOW_RAW]);
//    flowEng = static_cast<double>(flowRaw)/F_SLOP;
    flowEng = providers.getFlowEngineeringValues(flowRaw);
    localStr.sprintf("%4d/%1.2f",flowRaw,flowEng);
    ui->flowValue->setText(localStr);

    int blowerSpeedRaw=0,blowerRpmRaw=0;
    double blowerSpeedEng=0,blowerRpmEng=0;
    blowerSpeedRaw = static_cast<int>(localBuf[IPC_BLOWER_SPEED]);
//    blowerSpeedEng = static_cast<double>(1000000)/blowerSpeedRaw;
    blowerSpeedEng = providers.getBlowerSpeedEngineeringValues(blowerSpeedRaw);
    blowerRpmEng = blowerSpeedEng * 1000 * 60;
    blowerRpmRaw = static_cast<int>(blowerRpmEng);
    localStr.sprintf("%1.2f/%d",blowerSpeedEng,blowerRpmRaw);
    ui->blowerFBValue->setText(localStr);

    int motorTempRaw=0;
    double motorTempEng=0;
    motorTempRaw = static_cast<int>(localBuf[IPC_MOTOR_TEMP_RAW]);
//    motorTempEng = MOTOR_TEMP_COEFF_A + (MOTOR_TEMP_COEFF_B * qLn(motorTempRaw));
    motorTempEng = providers.getMotorTempratureEngineeringValues(motorTempRaw);
    localStr.sprintf("%4d/%1.2f",motorTempRaw,motorTempEng);
    ui->motorTempValue->setText(localStr);

    int voltageInRaw=0;
    double voltageInEng=0;
    voltageInRaw = static_cast<int>(localBuf[IPC_VOLTAGE_IN_RAW]);
//    voltageInEng = (static_cast<double>(voltageInRaw) * 3.3 * 57)/(4096 * 10);
    voltageInEng = providers.getVoltageInEngineeringValues(voltageInRaw);
    localStr.sprintf("%4d/%1.2f",voltageInRaw,voltageInEng);
    ui->voltageInputValue->setText(localStr);

    int bldcCurrentRaw=0;
    double bldcCurrentEng=0;
    bldcCurrentRaw = static_cast<int>(localBuf[IPC_BLDC_CURRENT_RAW]);
//    bldcCurrentEng = (static_cast<double>(bldcCurrentRaw) * 3.3)/(4096 * 0.039);
    bldcCurrentEng = providers.getCurrentInEngineeringValues(bldcCurrentRaw);
    localStr.sprintf("%4d/%1.2f",bldcCurrentRaw,bldcCurrentEng);
    ui->bldcCurrentValue->setText(localStr);
}

void ManufacturingDiagnosisScreen::updateManufacturingScreenLuxParam(float param)
{
    QString str = QString::number(static_cast<double>(param));
    qDebug() << Q_FUNC_INFO << param << str;
    ui->lightIntensityValue->setText(str);
}

void ManufacturingDiagnosisScreen::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
