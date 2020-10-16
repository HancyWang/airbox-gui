#include "sdcardformatscreen.h"
#include "ui_sdcardformatscreen.h"

SdCardFormatScreen::SdCardFormatScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SdCardFormatScreen),
    parentEffect(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setAttribute(Qt::WA_TranslucentBackground,true);
    move(60,56);
}

SdCardFormatScreen::~SdCardFormatScreen()
{
    delete ui;
}

void SdCardFormatScreen::updateScreenBeforeShow()
{

}

void SdCardFormatScreen::on_closeButton_clicked()
{
    parentEffect->setEnabled(false);
    hide();
}

void SdCardFormatScreen::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
