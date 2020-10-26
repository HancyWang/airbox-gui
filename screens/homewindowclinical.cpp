#include "homewindowclinical.h"
#include "ui_homewindowclinical.h"
#include "ex_variables.h"


HomeWindowClinical::HomeWindowClinical(QWidget *parent,
                                       HomeWindowBasic * homeBasicBackend)
    : QDialog(parent),
    ui(new Ui::HomeWindowClinical),
    homeScreenBasic(homeBasicBackend),
    sleepReportButton(nullptr),
    settignsButton(nullptr),
    timerClinical(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowState(Qt::WindowFullScreen);
    setGeometry(0,0,width(),height());

    if(homeScreenBasic)
    {
        connect(homeScreenBasic,SIGNAL(showClinicalHomeScreen()),
                this,SLOT(show()));
    }

    timerClinical = new QTimer(this);
    connect(timerClinical, SIGNAL(timeout()), this, SLOT(timerClinicalTimeOut()));

    QFont font("Roboto-Light",14);
    ui->clinicalMenuTitle->setFont(font);

    addHomeButtons();
    sleepReportButton->hide();
}

HomeWindowClinical::~HomeWindowClinical()
{
    delete ui;
}

void HomeWindowClinical::addHomeButtons(void)
{
    sleepReportButton = new Button3(this);
    settignsButton = new Button3(this);

    sleepReportButton->setGeometry(QRect(8,167,230,75));
//    settignsButton->setGeometry(QRect(242,167,230,75));
    settignsButton->setGeometry(QRect(125,167,230,75));

    setButtonProps(sleepReportButton,Providers::getTitleTextString(SLEEP_REPORT_STR),Providers::getIconString(SLEEP_REPORT_ICON));
    setButtonProps(settignsButton,Providers::getTitleTextString(SETTINGS_STR),Providers::getIconString(SETTINGS_ICON));

    connect(sleepReportButton, SIGNAL(released()),SLOT(sleepReportButton_released()));
    connect(settignsButton, SIGNAL(released()),SLOT(settignsButton_released()));
}

void HomeWindowClinical::setButtonProps(Button3 * pButton,const QString &titleStr,const QString &imageStr)
{
    QFont fontTitle("Roboto-Light", 9);

    pButton->setButtonRadius(5);
    pButton->setTitle(titleStr,fontTitle,QColor(0xFFFFFF));
    pButton->setTextSpacing(40);
    pButton->setImage(imageStr);
    pButton->setBackgroundColor(0x0082C8,0x667DB6);
    pButton->enableGradientEffect(true);
}

void HomeWindowClinical::sleepReportButton_released()
{
    emit showSleepReportScreen(this);
}

void HomeWindowClinical::settignsButton_released()
{
    emit showSettingsClinicalScreen();
}

void HomeWindowClinical::on_frescaLogo_pressed()
{
    timerOver = false;
    timerClinical->start(USER_CLINICAL_MODE_SWITCHING_TIME);
}

void HomeWindowClinical::on_frescaLogo_released()
{
    timerClinical->stop();
    if(timerOver == true) {
        globalVar.clinicalMode = Off;
        hide();
    }
    ui->frescaLogo->setStyleSheet(QStringLiteral("border:none;border-radius:3px;background-color:#313131;"));
}

void HomeWindowClinical::timerClinicalTimeOut()
{
    timerOver = true;
    timerClinical->stop();
    ui->frescaLogo->setStyleSheet(QStringLiteral("border:none;border-radius:3px;background-color:#3B3B3B;"));
}

void HomeWindowClinical::updateText()
{
////    QFont font("Roboto-Light",14);
////    ui->clinicalMenuTitle->setFont(font);
//    ui->clinicalMenuTitle->setText(tr("Clinical Menu"));

    setButtonProps(sleepReportButton,Providers::getTitleTextString(SLEEP_REPORT_STR),Providers::getIconString(SLEEP_REPORT_ICON));
    setButtonProps(settignsButton,Providers::getTitleTextString(SETTINGS_STR),Providers::getIconString(SETTINGS_ICON));
}

void HomeWindowClinical::changeEvent(QEvent* e)
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
