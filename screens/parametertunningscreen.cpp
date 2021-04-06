#include "parametertunningscreen.h"
#include "ui_parametertunningscreen.h"
#include "ex_variables.h"

const QStringList ParameterTunningScreen::parametrTitle =
{
    " ",
    "BUFFER SIZE",
    "APNEA",
    "PRECURSOR",
    "W1",
    "W2",
    "VARIABLE1",
    "FLOW COFF.",
    "MAX EN TIME",
    "EN IF STABLE",
    "CURRENT WINDOW",
    "NO EVENT FOR TIME",
    "EVENT THRESHOLD",
    "APNEA INCREMENT",
    "APNEA2 INCREMENT",
    "HYPOAPNEA INCREMENT",
    "PRECURSOR INCREMENT",
    "A2 THRESHOLD COUNT",
    "L2 THRESHOLD COUNT",
    "LEAK ALGORITHM EN",
    "LEAK1 FLOW MULTIPLIER",
    "LEAK2 FLOW MULTIPLIER",
    "APNEA2 FLOW MULTIPLIER",
    "FLOW COFF. EVENT",
    "HypTh45",
    "HypTh67",
    "HypTh89",
    "HypTh1011",
    "HypTh1213",
    "HypTh1415",
    "HypTh1617",
    "HypTh1819",
    "HypTh20",
    "REF. WINDOW",
    "ApnTh1011",
    "ApnTh1213",
    "ApnTh1415",
    "ApnTh1617",
    "ApnTh1819",
    "ApnTh20",
    "ApnTh45",
    "ApnTh67",
    "ApnTh89",

//    "PRECURSOR A",
//    "PRECURSOR B",
//    "PRECURSOR C",
    "ALGO2(EVENT) BUFFER SIZE",
    "BARREL TYPE",
};


ParameterTunningScreen::ParameterTunningScreen(QWidget *parent,
                                               PruControlClass * m_IpcBackend,
                                               TherapyWindowBasic * therapyBasicBackend,
                                               RestoreDefaultsWindowClinical * restoreDefaultBackend,
                                               DataValidation * dataValidationBackend,
                                               ManufacturingOptionsScreen * manufacturingOptionsBackend)
    : QDialog(parent),
    ui(new Ui::ParameterTunningScreen),
    m_IpcManager(m_IpcBackend),
    therapyBasicScreen(therapyBasicBackend),
    restoreDefaultScreen(restoreDefaultBackend),
    dataValidation(dataValidationBackend),
    manufacturingOptionsScreen(manufacturingOptionsBackend),
    tLocalTimer(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setWindowState(Qt::WindowFullScreen);
    setGeometry(0,0,width(),height());

    if(m_IpcManager)
    {
        connect(this,SIGNAL(updateTunningParameter(int*)),
                m_IpcManager,SLOT(updateTunningParameter(int*)));
    }

    if(therapyBasicScreen)
    {
        connect(therapyBasicScreen,SIGNAL(showParameterTunningScreen()),
                this,SLOT(show()));
    }

    if(restoreDefaultScreen)
    {
        connect(restoreDefaultScreen,SIGNAL(restoreDefaultTunningParametersBarrelType1()),
                this,SLOT(restoreDefaultTunningParametersBarrelType1()));
    }

    if(dataValidation)
    {
        connect(dataValidation,SIGNAL(restoreDefaultTunningParametersBarrelType1()),
                this,SLOT(restoreDefaultTunningParametersBarrelType1()));
        connect(dataValidation,SIGNAL(updateTunningParametersFromEeprom(QStringList&)),
                this,SLOT(updateTunningParametersFromEeprom(QStringList&)));
        connect(this,SIGNAL(writeParameterToEeprom()),
                dataValidation,SLOT(writeParameterToEeprom()));
        connect(this,SIGNAL(readTunningParameterFromEeprom()),
                dataValidation,SLOT(readTunningParameterFromEeprom()));
        connect(this,SIGNAL(writeTuneParameterToEeprom(int*)),
                dataValidation,SLOT(writeTuneParameterToEeprom(int*)));
    }

    if(m_IpcManager)
    {
        connect(m_IpcManager,SIGNAL(sendTunningParameterToPRU()),
                this,SLOT(sendTunningParameterToPRU()));
    }

    if(manufacturingOptionsScreen)
    {
        connect(manufacturingOptionsScreen,SIGNAL(showParameterTunningScreen()),
                this,SLOT(show()));
    }

    memset(valueParam,0,sizeof(valueParam));
    memset(minValueParam,0,sizeof(minValueParam));
    memset(maxValueParam,0,sizeof(maxValueParam));

    emit readTunningParameterFromEeprom();

    minValueParam[TUNE_BUFFER_SIZE] = 4;
    minValueParam[TUNE_APNEA] = 0;
    minValueParam[TUNE_PRECURSOR] = 0;
    minValueParam[TUNE_W1] = 0;
    minValueParam[TUNE_W2] = 0;
    minValueParam[TUNE_VARIABLE1] = 0;
    minValueParam[TUNE_FLOW_COFF] = 0;
    minValueParam[TUNE_MAX_ENABLE_TIME] = 0;//1;
    minValueParam[TUNE_EN_IF_STABLE] = 0;//1;
    minValueParam[TUNE_NO_EVENT_FOR_TIME] = 0;//1;
    minValueParam[TUNE_EVENT_THRESHOLD] = 0;
    minValueParam[TUNE_APNEA_INCREMENT] = 0;
    minValueParam[TUNE_APNEA2_INCREMENT] = 0;
    minValueParam[TUNE_HYPOAPNEA_INCREMENT] = 0;
    minValueParam[TUNE_PRECURSOR_INCREMENT] = 0;
    minValueParam[TUNE_APNEA2_THRESHOLD_COUNT] = 0;
    minValueParam[TUNE_LEAK2_THRESHOLD_COUNT] = 0;
    minValueParam[TUNE_LEAK_ALGORITHM_EN] = 0;
    minValueParam[TUNE_LEAK_FLOW_MULTIPLIER] = 0;
    minValueParam[TUNE_LEAK2_FLOW_MULTIPLIER] = 0;
    minValueParam[TUNE_APNEA2_FLOW_MULTIPLIER] = 0;
    minValueParam[TUNE_FLOW_COFF_EVENT_DETECTION] = 0;
//    minValueParam[TUNE_PRE_CURSOR_THRESHOLDA] = 0;
//    minValueParam[TUNE_PRE_CURSOR_THRESHOLDB] = 0;
//    minValueParam[TUNE_PRE_CURSOR_THRESHOLDC] = 0;
    minValueParam[TUNE_ALGO2_BUFFER_SIZE] = 1;

    minValueParam[TUNE_PRE_CURSOR_THRESHOLD45] = 0;
    minValueParam[TUNE_PRE_CURSOR_THRESHOLD67] = 0;
    minValueParam[TUNE_PRE_CURSOR_THRESHOLD89] = 0;
    minValueParam[TUNE_PRE_CURSOR_THRESHOLD1011] = 0;
    minValueParam[TUNE_PRE_CURSOR_THRESHOLD1213] = 0;
    minValueParam[TUNE_PRE_CURSOR_THRESHOLD1415] = 0;
    minValueParam[TUNE_PRE_CURSOR_THRESHOLD1617] = 0;
    minValueParam[TUNE_PRE_CURSOR_THRESHOLD1819] = 0;
    minValueParam[TUNE_PRE_CURSOR_THRESHOLD20] = 0;
    minValueParam[TUNE_REFERENCE_WINDOW] = 1;
    minValueParam[TUNE_CURRENT_FLOW_AVG] = 1;

    minValueParam[TUNE_APNEA_THRESHOLD1011] = 0;
    minValueParam[TUNE_APNEA_THRESHOLD1213] = 0;
    minValueParam[TUNE_APNEA_THRESHOLD1415] = 0;
    minValueParam[TUNE_APNEA_THRESHOLD1617] = 0;
    minValueParam[TUNE_APNEA_THRESHOLD1819] = 0;
    minValueParam[TUNE_APNEA_THRESHOLD20] = 0;
    minValueParam[TUNE_APNEA_THRESHOLD45] = 0;
    minValueParam[TUNE_APNEA_THRESHOLD67] = 0;
    minValueParam[TUNE_APNEA_THRESHOLD89] = 0;
    minValueParam[TUNE_FLOW_BARREL_TYPE] = 0;

    maxValueParam[TUNE_BUFFER_SIZE] = 16;
    maxValueParam[TUNE_APNEA] = 100;
    maxValueParam[TUNE_PRECURSOR] = 100;
    maxValueParam[TUNE_W1] = 1000;
    maxValueParam[TUNE_W2] = 1000;
    maxValueParam[TUNE_VARIABLE1] = 100;
    maxValueParam[TUNE_FLOW_COFF] = 1000;
    maxValueParam[TUNE_MAX_ENABLE_TIME] = 30;//5;
    maxValueParam[TUNE_EN_IF_STABLE] = 30;//15;
    maxValueParam[TUNE_NO_EVENT_FOR_TIME] = 30;//5;
    maxValueParam[TUNE_EVENT_THRESHOLD] = 100;
    maxValueParam[TUNE_APNEA_INCREMENT] = 100;
    maxValueParam[TUNE_APNEA2_INCREMENT] = 100;
    maxValueParam[TUNE_HYPOAPNEA_INCREMENT] = 100;
    maxValueParam[TUNE_PRECURSOR_INCREMENT] = 100;
    maxValueParam[TUNE_APNEA2_THRESHOLD_COUNT] = 32000;//4095;
    maxValueParam[TUNE_LEAK2_THRESHOLD_COUNT] = 32000;//4095;
    maxValueParam[TUNE_LEAK_ALGORITHM_EN] = 1;
    maxValueParam[TUNE_LEAK_FLOW_MULTIPLIER] = 4096;//1000; //99
    maxValueParam[TUNE_LEAK2_FLOW_MULTIPLIER] = 4096;//1000; //99
    maxValueParam[TUNE_APNEA2_FLOW_MULTIPLIER] = 1000; //99
    maxValueParam[TUNE_FLOW_COFF_EVENT_DETECTION] = 1000;
//    maxValueParam[TUNE_PRE_CURSOR_THRESHOLDA] = 100;
//    maxValueParam[TUNE_PRE_CURSOR_THRESHOLDB] = 100;
//    maxValueParam[TUNE_PRE_CURSOR_THRESHOLDC] = 100;
    maxValueParam[TUNE_ALGO2_BUFFER_SIZE] = 10;

    maxValueParam[TUNE_PRE_CURSOR_THRESHOLD45] = 100;
    maxValueParam[TUNE_PRE_CURSOR_THRESHOLD67] = 100;
    maxValueParam[TUNE_PRE_CURSOR_THRESHOLD89] = 100;
    maxValueParam[TUNE_PRE_CURSOR_THRESHOLD1011] = 100;
    maxValueParam[TUNE_PRE_CURSOR_THRESHOLD1213] = 100;
    maxValueParam[TUNE_PRE_CURSOR_THRESHOLD1415] = 100;
    maxValueParam[TUNE_PRE_CURSOR_THRESHOLD1617] = 100;
    maxValueParam[TUNE_PRE_CURSOR_THRESHOLD1819] = 100;
    maxValueParam[TUNE_PRE_CURSOR_THRESHOLD20] = 100;
    maxValueParam[TUNE_REFERENCE_WINDOW] = 16;
    maxValueParam[TUNE_CURRENT_FLOW_AVG] = 16;

    maxValueParam[TUNE_APNEA_THRESHOLD1011] = 100;
    maxValueParam[TUNE_APNEA_THRESHOLD1213] = 100;
    maxValueParam[TUNE_APNEA_THRESHOLD1415] = 100;
    maxValueParam[TUNE_APNEA_THRESHOLD1617] = 100;
    maxValueParam[TUNE_APNEA_THRESHOLD1819] = 100;
    maxValueParam[TUNE_APNEA_THRESHOLD20] = 100;
    maxValueParam[TUNE_APNEA_THRESHOLD45] = 100;
    maxValueParam[TUNE_APNEA_THRESHOLD67] = 100;
    maxValueParam[TUNE_APNEA_THRESHOLD89] = 100;
    maxValueParam[TUNE_FLOW_BARREL_TYPE] = 1;

    QFont title("Roboto-Light",10);

    title.setPointSize(12);
    ui->titleParameterTunning->setFont(title);
    ui->paramValue->setFont(title);

    title.setPointSize(8);
    ui->paramTitle->setFont(title);

    ui->scrollAreaWidgetContents->setLayout(ui->verticalLayout);
    ui->scrollArea->setStyleSheet(QStringLiteral("border:none;"));

    for(int i=0 ; i< TUNE_MAX_CHANGE_PARAM ; i++)
    {
        tuneButtons[i] = nullptr;
        tuneButtons[i] = new QPushButton(ui->verticalLayoutWidget);
        tuneButtons[i]->setFont(title);
        tuneButtons[i]->setText(parametrTitle[i]);
        tuneButtons[i]->setObjectName(parametrTitle[i]);
        tuneButtons[i]->setFixedHeight(30);
        tuneButtons[i]->setFocusPolicy(Qt::NoFocus);
        tuneButtons[i]->setStyleSheet(QLatin1String("QPushButton {\n"
                                        "background-color:#3B3B3B;\n"
                                        "color:#BDBDBD;\n"
                                        "border:none;\n"
                                        "border-radius:3px;\n"
                                        "}\n"
                                        "QPushButton:pressed {\n"
                                        "background-color:#606060;\n"
                                        "color:#BDBDBD;\n"
                                        "border:none;\n"
                                        "border-radius:3px;\n"
                                        "}\n"
                                        ""));
        tuneButtons[i]->raise();
        connect(tuneButtons[i],SIGNAL(clicked()),
                this,SLOT(on_TuneButtonClicked()));

        ui->verticalLayout->addWidget(tuneButtons[i]);
    }

    //Enable Scrolling mechanism for scroll area
    QScroller::grabGesture(ui->scrollArea->viewport(),QScroller::LeftMouseButtonGesture);

    validateTuneEepromData();

    indexChangeParam = TUNE_BUFFER_SIZE;
    updateParamValueText();

    tuneButtons[0]->hide();
    tuneButtons[TUNE_ALGO2_BUFFER_SIZE]->hide();
    tuneButtons[TUNE_APNEA]->hide();
    tuneButtons[TUNE_PRECURSOR]->hide();
}

void ParameterTunningScreen::restoreDefaultTunningParametersBarrelType0(void)
{
    globalVar.flow.threshold = 150;

    valueParam[0] = 0;
    valueParam[TUNE_BUFFER_SIZE] = 16;
    valueParam[TUNE_APNEA] = 80;
    valueParam[TUNE_PRECURSOR] = 30;
    valueParam[TUNE_W1] = 100;
    valueParam[TUNE_W2] = 100;
    valueParam[TUNE_VARIABLE1] = 5;
    valueParam[TUNE_FLOW_COFF] = 10;
    valueParam[TUNE_MAX_ENABLE_TIME] = 15;
    valueParam[TUNE_EN_IF_STABLE] = 5;
    valueParam[TUNE_CURRENT_FLOW_AVG] = 4;
    valueParam[TUNE_NO_EVENT_FOR_TIME] = 8;
    valueParam[TUNE_EVENT_THRESHOLD] = 15;
    valueParam[TUNE_APNEA_INCREMENT] = 10;
    valueParam[TUNE_APNEA2_INCREMENT] = 10;
    valueParam[TUNE_HYPOAPNEA_INCREMENT] = 3;
    valueParam[TUNE_PRECURSOR_INCREMENT] = 1;
    valueParam[TUNE_APNEA2_THRESHOLD_COUNT] = 300;
    valueParam[TUNE_LEAK2_THRESHOLD_COUNT] = 600;
    valueParam[TUNE_LEAK_ALGORITHM_EN] = 1;
    valueParam[TUNE_LEAK_FLOW_MULTIPLIER] = 70;
    valueParam[TUNE_LEAK2_FLOW_MULTIPLIER] = 90;
    valueParam[TUNE_APNEA2_FLOW_MULTIPLIER] = 50;
    valueParam[TUNE_FLOW_COFF_EVENT_DETECTION] = 10;
//    valueParam[TUNE_PRE_CURSOR_THRESHOLDA] = 30;
//    valueParam[TUNE_PRE_CURSOR_THRESHOLDB] = 40;
//    valueParam[TUNE_PRE_CURSOR_THRESHOLDC] = 50;
    valueParam[TUNE_ALGO2_BUFFER_SIZE] = 4;

    valueParam[TUNE_PRE_CURSOR_THRESHOLD45] = 20;
    valueParam[TUNE_PRE_CURSOR_THRESHOLD67] = 30;
    valueParam[TUNE_PRE_CURSOR_THRESHOLD89] = 30;
    valueParam[TUNE_PRE_CURSOR_THRESHOLD1011] = 40;
    valueParam[TUNE_PRE_CURSOR_THRESHOLD1213] = 40;
    valueParam[TUNE_PRE_CURSOR_THRESHOLD1415] = 40;
    valueParam[TUNE_PRE_CURSOR_THRESHOLD1617] = 50;
    valueParam[TUNE_PRE_CURSOR_THRESHOLD1819] = 50;
    valueParam[TUNE_PRE_CURSOR_THRESHOLD20] = 50;
    valueParam[TUNE_REFERENCE_WINDOW] = 16;

    valueParam[TUNE_APNEA_THRESHOLD1011] = 80;
    valueParam[TUNE_APNEA_THRESHOLD1213] = 80;
    valueParam[TUNE_APNEA_THRESHOLD1415] = 80;
    valueParam[TUNE_APNEA_THRESHOLD1617] = 80;
    valueParam[TUNE_APNEA_THRESHOLD1819] = 80;
    valueParam[TUNE_APNEA_THRESHOLD20] = 80;
    valueParam[TUNE_APNEA_THRESHOLD45] = 80;
    valueParam[TUNE_APNEA_THRESHOLD67] = 80;
    valueParam[TUNE_APNEA_THRESHOLD89] = 80;
    valueParam[TUNE_FLOW_BARREL_TYPE] = 0;

    emit writeTuneParameterToEeprom(valueParam);
}

void ParameterTunningScreen::restoreDefaultTunningParametersBarrelType1(void)
{
    globalVar.flow.threshold = 1050;

    valueParam[0] = 0;
    valueParam[TUNE_BUFFER_SIZE] = 16;
    valueParam[TUNE_APNEA] = 65;
    valueParam[TUNE_PRECURSOR] = 30;
    valueParam[TUNE_W1] = 100;
    valueParam[TUNE_W2] = 100;
    valueParam[TUNE_VARIABLE1] = 5;
    valueParam[TUNE_FLOW_COFF] = 10;
    valueParam[TUNE_MAX_ENABLE_TIME] = 15;
    valueParam[TUNE_EN_IF_STABLE] = 5;
    valueParam[TUNE_CURRENT_FLOW_AVG] = 4;
    valueParam[TUNE_NO_EVENT_FOR_TIME] = 8;
    valueParam[TUNE_EVENT_THRESHOLD] = 15;
    valueParam[TUNE_APNEA_INCREMENT] = 10;
    valueParam[TUNE_APNEA2_INCREMENT] = 10;
    valueParam[TUNE_HYPOAPNEA_INCREMENT] = 3;
    valueParam[TUNE_PRECURSOR_INCREMENT] = 1;
    valueParam[TUNE_APNEA2_THRESHOLD_COUNT] = 2100;
    valueParam[TUNE_LEAK2_THRESHOLD_COUNT] = 4095;
    valueParam[TUNE_LEAK_ALGORITHM_EN] = 1;
    valueParam[TUNE_LEAK_FLOW_MULTIPLIER] = 490;
    valueParam[TUNE_LEAK2_FLOW_MULTIPLIER] = 630;
    valueParam[TUNE_APNEA2_FLOW_MULTIPLIER] = 350;
    valueParam[TUNE_FLOW_COFF_EVENT_DETECTION] = 10;
//    valueParam[TUNE_PRE_CURSOR_THRESHOLDA] = 30;
//    valueParam[TUNE_PRE_CURSOR_THRESHOLDB] = 40;
//    valueParam[TUNE_PRE_CURSOR_THRESHOLDC] = 50;
    valueParam[TUNE_ALGO2_BUFFER_SIZE] = 4;

    valueParam[TUNE_PRE_CURSOR_THRESHOLD45] = 20;
    valueParam[TUNE_PRE_CURSOR_THRESHOLD67] = 30;
    valueParam[TUNE_PRE_CURSOR_THRESHOLD89] = 30;
    valueParam[TUNE_PRE_CURSOR_THRESHOLD1011] = 40;
    valueParam[TUNE_PRE_CURSOR_THRESHOLD1213] = 40;
    valueParam[TUNE_PRE_CURSOR_THRESHOLD1415] = 40;
    valueParam[TUNE_PRE_CURSOR_THRESHOLD1617] = 50;
    valueParam[TUNE_PRE_CURSOR_THRESHOLD1819] = 50;
    valueParam[TUNE_PRE_CURSOR_THRESHOLD20] = 50;
    valueParam[TUNE_REFERENCE_WINDOW] = 16;

    valueParam[TUNE_APNEA_THRESHOLD1011] = 65;
    valueParam[TUNE_APNEA_THRESHOLD1213] = 65;
    valueParam[TUNE_APNEA_THRESHOLD1415] = 65;
    valueParam[TUNE_APNEA_THRESHOLD1617] = 65;
    valueParam[TUNE_APNEA_THRESHOLD1819] = 65;
    valueParam[TUNE_APNEA_THRESHOLD20] = 65;
    valueParam[TUNE_APNEA_THRESHOLD45] = 65;
    valueParam[TUNE_APNEA_THRESHOLD67] = 65;
    valueParam[TUNE_APNEA_THRESHOLD89] = 65;
    valueParam[TUNE_FLOW_BARREL_TYPE] = 1;

    emit writeTuneParameterToEeprom(valueParam);
}

void ParameterTunningScreen::validateTuneEepromData(void)
{
    bool restoreToDefault=false;
    for(int i=0 ; i<TUNE_MAX_CHANGE_PARAM ; i++)
    {
        if((valueParam[i] > maxValueParam[i]) | (valueParam[i] < minValueParam[i]))
        {
            restoreToDefault = true;
            qDebug() << Q_FUNC_INFO << i << valueParam[i] << maxValueParam[i] << minValueParam[i];
        }
    }

    if(restoreToDefault == true)        restoreDefaultTunningParametersBarrelType1();
}

void ParameterTunningScreen::updateTunningParametersFromEeprom(QStringList & listTuneData)
{
    QString readTuneData;
    readTuneData.clear();
    for(int i=0 ; i<TUNE_MAX_CHANGE_PARAM ; i++)
    {
        valueParam[i] = listTuneData.at(i).toInt();
        readTuneData += valueParam[i] + " ";
    }

    qDebug() << "Tunning data" //<< readTuneData << " <== List ==> " << listTuneData
                << valueParam[TUNE_BUFFER_SIZE] << valueParam[TUNE_APNEA] << valueParam[TUNE_PRECURSOR]
                << valueParam[TUNE_W1] << valueParam[TUNE_W2] << valueParam[TUNE_VARIABLE1]
                << valueParam[TUNE_FLOW_COFF] << valueParam[TUNE_MAX_ENABLE_TIME] << valueParam[TUNE_EN_IF_STABLE]
                << valueParam[TUNE_CURRENT_FLOW_AVG] << valueParam[TUNE_NO_EVENT_FOR_TIME] << valueParam[TUNE_EVENT_THRESHOLD]
                << valueParam[TUNE_APNEA_INCREMENT] << valueParam[TUNE_APNEA2_INCREMENT] << valueParam[TUNE_HYPOAPNEA_INCREMENT]
                << valueParam[TUNE_PRECURSOR_INCREMENT] << valueParam[TUNE_APNEA2_THRESHOLD_COUNT] << valueParam[TUNE_LEAK2_THRESHOLD_COUNT]
                << valueParam[TUNE_LEAK_ALGORITHM_EN] << valueParam[TUNE_LEAK_FLOW_MULTIPLIER]
                << valueParam[TUNE_LEAK2_FLOW_MULTIPLIER] << valueParam[TUNE_APNEA2_FLOW_MULTIPLIER] << valueParam[TUNE_FLOW_COFF_EVENT_DETECTION]
//                << valueParam[TUNE_PRE_CURSOR_THRESHOLDA] << valueParam[TUNE_PRE_CURSOR_THRESHOLDB] << valueParam[TUNE_PRE_CURSOR_THRESHOLDC]
                << valueParam[TUNE_ALGO2_BUFFER_SIZE];
}

void ParameterTunningScreen::showParameterTunningScreen(QWidget *parent)
{
    setParent(this);
    show();
}

void ParameterTunningScreen::sendTunningParametersFirstTime()
{
    sendTunningParameterToPRU();
}

ParameterTunningScreen::~ParameterTunningScreen()
{
    delete ui;
}


void ParameterTunningScreen::on_TuneButtonClicked()
{
    QPushButton *btn = qobject_cast<QPushButton *>(sender());

    int index = parametrTitle.indexOf(btn->objectName());
    if(index == -1)
    {
        qDebug() << Q_FUNC_INFO << "Invalid object name" << btn->objectName() << index;
        return;
    }
    indexChangeParam = index;
    updateParamValueText();
}

void ParameterTunningScreen::on_backParameterTunning_released()
{
    hide();
}

void ParameterTunningScreen::updateParamValueText(void)
{
    ui->paramUnit->setText(" ");
    ui->paramTitle->setText(parametrTitle.at(indexChangeParam));
    updateParamOnValue(valueParam[indexChangeParam]);
}


void ParameterTunningScreen::updateParamOnValue(unsigned int value)
{
    QString str;
    float tLocal=0;
    tLocal = value;

    if((indexChangeParam == TUNE_BUFFER_SIZE) | (indexChangeParam == TUNE_EN_IF_STABLE)
            | (indexChangeParam == TUNE_MAX_ENABLE_TIME) | (indexChangeParam == TUNE_CURRENT_FLOW_AVG)
            | (indexChangeParam == TUNE_NO_EVENT_FOR_TIME)
            | (indexChangeParam == TUNE_EVENT_THRESHOLD) | (indexChangeParam == TUNE_APNEA_INCREMENT)
            | (indexChangeParam == TUNE_APNEA2_INCREMENT)
            | (indexChangeParam == TUNE_HYPOAPNEA_INCREMENT) | (indexChangeParam == TUNE_PRECURSOR_INCREMENT)
            | (indexChangeParam == TUNE_APNEA2_THRESHOLD_COUNT)
            | (indexChangeParam == TUNE_LEAK2_THRESHOLD_COUNT)
            | (indexChangeParam == TUNE_LEAK_ALGORITHM_EN)
            | (indexChangeParam == TUNE_LEAK_FLOW_MULTIPLIER)
            | (indexChangeParam == TUNE_LEAK2_FLOW_MULTIPLIER)
            | (indexChangeParam == TUNE_APNEA2_FLOW_MULTIPLIER)
            | (indexChangeParam == TUNE_ALGO2_BUFFER_SIZE) | (indexChangeParam == TUNE_REFERENCE_WINDOW)
            | (indexChangeParam == TUNE_FLOW_BARREL_TYPE))
    {
        tLocal = tLocal;
    }
    else
    {
        tLocal /= 100;
    }

    str = QString("%1").arg(tLocal);

    ui->paramValue->setText(str);
}

void ParameterTunningScreen::on_paramIncrement_pressed()
{
    if(valueParam[indexChangeParam] < maxValueParam[indexChangeParam])
    {
        valueParam[indexChangeParam]++;

        updateParamOnValue(valueParam[indexChangeParam]);

        if(indexChangeParam == TUNE_FLOW_BARREL_TYPE)
            updateFlowBarrelTypeAndDefaultData();

        if(indexChangeParam != TUNE_FLOW_BARREL_TYPE)
            emit writeTuneParameterToEeprom(valueParam);

        sendTunningParameterToPRU();
    }
}

void ParameterTunningScreen::updateFlowBarrelTypeAndDefaultData()
{
    if(valueParam[indexChangeParam] == 1)
    {
        // Use Barrel Type 1 Settings
        restoreDefaultTunningParametersBarrelType1();
    }
    else
    {
        // Use Barrel Type 0 Settings
        restoreDefaultTunningParametersBarrelType0();
    }

    // Update Data to EEPROM
    emit writeParameterToEeprom();
}

void ParameterTunningScreen::sendTunningParameterToPRU(void)
{
    emit updateTunningParameter(valueParam);
}

void ParameterTunningScreen::on_paramDecrement_pressed()
{
    if(valueParam[indexChangeParam] > minValueParam[indexChangeParam])
    {
        valueParam[indexChangeParam]--;
        updateParamOnValue(valueParam[indexChangeParam]);

        if(indexChangeParam == TUNE_FLOW_BARREL_TYPE)
            updateFlowBarrelTypeAndDefaultData();

        if(indexChangeParam != TUNE_FLOW_BARREL_TYPE)
            emit writeTuneParameterToEeprom(valueParam);

        sendTunningParameterToPRU();
    }
}

void ParameterTunningScreen::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
