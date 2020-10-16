#include "brightnessoffsetscreen.h"
#include "ui_brightnessoffsetscreen.h"
#include "ex_variables.h"


int BrightnessOffsetScreen::brightnessOffset = 0;


BrightnessOffsetScreen::BrightnessOffsetScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrightnessOffsetScreen),
    parentEffect(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setAttribute(Qt::WA_TranslucentBackground,true);
    move(60,56);

    QFont title("Roboto-Light",9);
    ui->brightnessOffsetTitle->setFont(title);

    title.setPointSize(8);
    ui->brightnessOffsetUnit->setFont(title);

    title.setPointSize(12);
    ui->brightnessOffsetDecrement->setFont(title);
    ui->brightnessOffsetIncrement->setFont(title);

    title.setPointSize(10);
    ui->brightnessOffsetAccept->setFont(title);
    ui->brightnessOffsetCancel->setFont(title);

    QFont valueFont("Roboto-Thin",26);
    ui->brightnessOffsetValue->setFont(valueFont);
}

BrightnessOffsetScreen::~BrightnessOffsetScreen()
{
    delete ui;
}

void BrightnessOffsetScreen::on_brightnessOffsetIncrement_pressed()
{
    if(brightnessOffset < 100)
    {
        brightnessOffset++;
        ui->brightnessOffsetSlider->setValue(brightnessOffset);
        QString str = QString::number(brightnessOffset);
        ui->brightnessOffsetValue->setText(str);
    }
}

void BrightnessOffsetScreen::on_brightnessOffsetDecrement_pressed()
{
    if(brightnessOffset > 0)
    {
        brightnessOffset--;
        ui->brightnessOffsetSlider->setValue(brightnessOffset);
        QString str = QString::number(brightnessOffset);
        ui->brightnessOffsetValue->setText(str);
    }
}

void BrightnessOffsetScreen::on_brightnessOffsetAccept_released()
{
    parentEffect->setEnabled(false);
    hide();
    emit dialogClose();
    setModal(false);
}

void BrightnessOffsetScreen::on_brightnessOffsetCancel_released()
{
    parentEffect->setEnabled(false);
    hide();
    setModal(false);
}

void BrightnessOffsetScreen::showBrightnessOffsetScreen()
{
    parentEffect->setEnabled(true);
    setModal(true);
    show();
}

void BrightnessOffsetScreen::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
