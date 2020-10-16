#include "enterserialnumber.h"
#include "ui_enterserialnumber.h"
#include "ex_variables.h"


int EnterSerialNumber::bkupSerialNumber[SERIAL_NUMBER_MAX_CHAR] = {0};
int EnterSerialNumber::serialNumber[SERIAL_NUMBER_MAX_CHAR] = {0};
int EnterSerialNumber::serialNumberIndex = 0;
int EnterSerialNumber::serialNumberInputIndex = 0;


#define SERIAL_NUMBER_MISMATCH  1
#define SERIAL_NUMBER_ONE       2
#define SERIAL_NUMBER_TWO       3

EnterSerialNumber::EnterSerialNumber(QWidget *parent,
                                     DataValidation * dataValidationBackend)
    : QDialog(parent),
    ui(new Ui::EnterSerialNumber),
    dataValidation(dataValidationBackend),
    parentEffect(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setAttribute(Qt::WA_TranslucentBackground,true);
    move(64,6);

    if(dataValidation)
    {
        connect(this,SIGNAL(writeDeviceInformationToEeprom()),
                dataValidation,SLOT(writeDeviceInformationToEeprom()));
    }

    QFont title("Roboto-Light",9);
    ui->serialNumberTitle->setFont(title);
    ui->serialNumberWarning->hide();
    serialNumberInputIndex = 0;
}

EnterSerialNumber::~EnterSerialNumber()
{
    delete ui;
}

void EnterSerialNumber::on_digit1_pressed()
{
    addDigitInSerialNumber(1);
}

void EnterSerialNumber::on_digit2_pressed()
{
    addDigitInSerialNumber(2);
}

void EnterSerialNumber::on_digit3_pressed()
{
    addDigitInSerialNumber(3);
}

void EnterSerialNumber::on_digit4_pressed()
{
    addDigitInSerialNumber(4);
}

void EnterSerialNumber::on_digit5_pressed()
{
    addDigitInSerialNumber(5);
}

void EnterSerialNumber::on_digit6_pressed()
{
    addDigitInSerialNumber(6);
}

void EnterSerialNumber::on_digit7_pressed()
{
    addDigitInSerialNumber(7);
}

void EnterSerialNumber::on_digit8_pressed()
{
    addDigitInSerialNumber(8);
}

void EnterSerialNumber::on_digit9_pressed()
{
    addDigitInSerialNumber(9);
}

void EnterSerialNumber::on_digit0_pressed()
{
    addDigitInSerialNumber(0);
}

void EnterSerialNumber::on_backSpace_pressed()
{
    if(serialNumberIndex > 0)
    {
        serialNumberIndex--;
        serialNumber[serialNumberIndex] = 0;
        convertInToString();
    }
}

void EnterSerialNumber::on_serialNumberAccept_released()
{
int res=0;

    ui->serialNumberText->setText("");

    qDebug() << Q_FUNC_INFO << serialNumberIndex ;
    if(serialNumberIndex != SERIAL_NUMBER_MAX_CHAR) {
        serialNumberIndex = 0;
        serialNumberInputIndex = 0;
        updateWarningText(SERIAL_NUMBER_MISMATCH);
        memset(bkupSerialNumber,0,sizeof(bkupSerialNumber));
        memset(serialNumber,0,sizeof(serialNumber));
    } else {
        if(!serialNumberInputIndex) {
            serialNumberInputIndex++;
            updateWarningText(SERIAL_NUMBER_TWO);
            memcpy(bkupSerialNumber,serialNumber,sizeof(serialNumber));
            serialNumberIndex = 0;
            memset(serialNumber,0,sizeof(serialNumber));

        } else if(serialNumberInputIndex) {
            serialNumberInputIndex = 0;
            serialNumberIndex = 0;

            res = compareSerialNumber();
            if(!res){
                memset(bkupSerialNumber,0,sizeof(bkupSerialNumber));

                globalVar.serialNumberStr.clear();
                int i=0;
                for(i=0 ; i<SERIAL_NUMBER_MAX_CHAR ; i++){
                    globalVar.serialNumberStr += QString::number(serialNumber[i]);
                }
                qDebug() << Q_FUNC_INFO << globalVar.serialNumberStr;
                emit writeDeviceInformationToEeprom();

                emit dialogClose();
                parentEffect->setEnabled(false);
                hide();
                setModal(false);
            } else {
                updateWarningText(SERIAL_NUMBER_MISMATCH);
                memset(bkupSerialNumber,0,sizeof(bkupSerialNumber));
                memset(serialNumber,0,sizeof(serialNumber));
            }
        }
    }
}

int EnterSerialNumber::compareSerialNumber(void)
{
int i=0;
    for(i=0; i<SERIAL_NUMBER_MAX_CHAR ; i++)
    {
        if(bkupSerialNumber[i] != serialNumber[i])
            return -1;
    }
    return 0;
}

void EnterSerialNumber::showEnterSerialNumberScreen()
{
    parentEffect->setEnabled(true);
    setModal(true);
    updateEnterSerialNumberScreenBeforeShow();
    show();
}

void EnterSerialNumber::on_serialNumberCancel_released()
{
    serialNumberInputIndex = 0;
    parentEffect->setEnabled(false);
    hide();
    setModal(false);
}

void EnterSerialNumber::addDigitInSerialNumber(int number)
{
    if(serialNumberIndex < SERIAL_NUMBER_MAX_CHAR)
    {
        serialNumber[serialNumberIndex] = number;
        serialNumberIndex++;
    }
    convertInToString();
}

void EnterSerialNumber::convertInToString(void)
{
    QString serialStr = "";
    for(int i=0; i<serialNumberIndex ; i++)
    {
        serialStr += QString::number(serialNumber[i]);
    }
    ui->serialNumberText->setText(serialStr);
}

void EnterSerialNumber::updateWarningText(int state)
{
    switch(state)
    {
        case SERIAL_NUMBER_MISMATCH:
            ui->serialNumberWarning->setText("Serial Number Mismatch");
            break;

        case SERIAL_NUMBER_ONE:
            ui->serialNumberWarning->setText("Enter Serial Number");
            break;

        case SERIAL_NUMBER_TWO:
            ui->serialNumberWarning->setText("Re-Enter Serial Number");
            break;
    }
    if(!ui->serialNumberWarning->isVisible())
        ui->serialNumberWarning->show();
}

void EnterSerialNumber::updateEnterSerialNumberScreenBeforeShow(void)
{
    serialNumberIndex = 0;
    serialNumberInputIndex = 0;
    memset(serialNumber,0,sizeof(serialNumber));
    memset(bkupSerialNumber,0,sizeof(bkupSerialNumber));

    updateWarningText(SERIAL_NUMBER_ONE);
    ui->serialNumberText->setText("");
}


void EnterSerialNumber::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
