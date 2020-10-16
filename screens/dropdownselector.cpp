#include "dropdownselector.h"
#include "ui_dropdownselector.h"

DropDownSelector::DropDownSelector(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DropDownSelector)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
}

DropDownSelector::~DropDownSelector()
{
    delete ui;
}

void DropDownSelector::on_button1_released()
{
    index = 1;
    emit dialogClose();
    this->close();
}

void DropDownSelector::on_button2_released()
{
    index = 2;
    emit dialogClose();
    this->close();
}

void DropDownSelector::on_button3_released()
{
    index = 3;
    emit dialogClose();
    this->close();
}

void DropDownSelector::on_button4_released()
{
    index = 4;
    emit dialogClose();
    this->close();
}

void DropDownSelector::on_button5_released()
{
    index = 5;
    emit dialogClose();
    this->close();
}

void DropDownSelector::on_button6_released()
{
    index = 6;
    emit dialogClose();
    this->close();
}

void DropDownSelector::setAllButtonsHeight(int height)
{
    ui->button1->setFixedHeight(height);
    ui->button2->setFixedHeight(height);
    ui->button3->setFixedHeight(height);
    ui->button4->setFixedHeight(height);
    ui->button5->setFixedHeight(height);
    ui->button6->setFixedHeight(height);
}

void DropDownSelector::updateButton1TextVisible(const QString &str,bool visible)
{
    if(visible){
        ui->button1->setText(str);
    } else {
        ui->button1->hide();
    }
}

void DropDownSelector::updateButton2TextVisible(const QString &str,bool visible)
{
    if(visible){
        ui->button2->setText(str);
    } else {
        ui->button2->hide();
    }
}

void DropDownSelector::updateButton3TextVisible(const QString &str,bool visible)
{
    if(visible){
        ui->button3->setText(str);
    } else {
        ui->button3->hide();
    }
}

void DropDownSelector::updateButton4TextVisible(const QString &str,bool visible)
{
    if(visible){
        ui->button4->setText(str);
    } else {
        ui->button4->hide();
    }
}

void DropDownSelector::updateButton5TextVisible(const QString &str,bool visible)
{
    if(visible){
        ui->button5->setText(str);
    } else {
        ui->button5->hide();
    }
}

void DropDownSelector::updateLayoutSize(const QRect &rect)
{
    ui->verticalLayoutWidget->setGeometry(rect);
}

void DropDownSelector::updateButton6TextVisible(const QString &str,bool visible)
{
    if(visible){
        ui->button6->setText(str);
    } else {
        ui->button6->hide();
    }
}

void DropDownSelector::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
