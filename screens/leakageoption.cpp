#include "leakageoption.h"
#include "ui_leakageoption.h"
#include "global.h"

LeakageOption::LeakageOption(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LeakageOption),
    leakageTimer(nullptr),
    leakageMsg(" "),
    parentEffect(nullptr)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setAttribute(Qt::WA_TranslucentBackground,true);
    move(60,56);

    leakageTimer=new QTimer(this);
    QObject::connect(leakageTimer, SIGNAL(timeout()), this, SLOT(leakageTimerTimeout()));
}

LeakageOption::~LeakageOption()
{
    delete ui;
}

void LeakageOption::on_leakageBtnOK_released()
{
    show_ui(false);
    leakageTimer->start(10000);
}

void LeakageOption::show_ui(bool b_show)
{
    if(b_show)
    {
        parentEffect->setEnabled(true);
        setModal(true);
        show();
    }
    else
    {
        parentEffect->setEnabled(false);
        hide();
        setModal(false);
    }
    updateText();
}

void LeakageOption::show_leak_msg(QString msg)
{
    leakageMsg=msg;
    if(msg=="L1"||msg=="L2")
    {
        show_ui(true);
    }
    else
    {
        show_ui(false);
    }
}

void LeakageOption::leakageTimerTimeout()
{
    if(leakageMsg=="L1"||leakageMsg=="L2")
    {
        show_leak_msg(leakageMsg);
    }
    else
    {
        leakageTimer->stop();
    }
}

void LeakageOption::updateText()
{
    if(leakageMsg=="L1")
    {
        ui->leakagelabel->setText(Providers::getTitleTextString(LEAK_1_STR));
    }
    else if(leakageMsg=="L2")
    {
        ui->leakagelabel->setText(Providers::getTitleTextString(LEAK_2_STR));
    }
    else
    {
        ui->leakagelabel->setText(" ");
    }
    //update();
}

void LeakageOption::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        updateText();
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
