#include "homewindowbasic.h"
#include "ui_homewindowbasic.h"
#include "ex_variables.h"


HomeWindowBasic::HomeWindowBasic(QWidget *parent,
                                 PasswordCheckScreen * passwordBackend)
    : QDialog(parent),
    ui(new Ui::HomeWindowBasic),
    m_Anim(nullptr),
    passwordScreen(passwordBackend),
    therapyButton(nullptr),
    sleepReportButton(nullptr),
    maskOptionButton(nullptr),
    settignsButton(nullptr),
    timerClinical(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowState(Qt::WindowFullScreen);
    setGeometry(0,0,width(),height());

    if(passwordScreen)
    {
        connect(this,SIGNAL(showPasswordEnterScreen(const int*)),
                passwordScreen,SLOT(showPasswordEnterScreen(const int*)));
    }

    /* Create timer to check if clinical entry button pressed for defined time */
    timerClinical = new QTimer(this);
    connect(timerClinical, SIGNAL(timeout()), this, SLOT(timerClinicalTimeOut()));

    /* Create all the required button in this screen */
    addHomeButtons();

    this->sleepReportButton->hide();
}

HomeWindowBasic::~HomeWindowBasic()
{
    delete ui;
}

void HomeWindowBasic::addHomeButtons(void)
{
    /* Button creation */
    therapyButton = new Button3(this);
    sleepReportButton = new Button3(this);
    maskOptionButton = new Button3(this);
    settignsButton = new Button3(this);

    /* Set Button position */
//    therapyButton->setGeometry(QRect(6,100,230,75));

//    therapyButton->setGeometry(QRect(125,100,230,75));
//    sleepReportButton->setGeometry(QRect(244,100,230,75));
//    maskOptionButton->setGeometry(QRect(6,185,230,75));
//    settignsButton->setGeometry(QRect(244,185,230,75));

    maskOptionButton->setGeometry(QRect(6,185,153,75));
    therapyButton->setGeometry(QRect(164,185,153,75));
    settignsButton->setGeometry(QRect(322,185,153,75));

    /* Set Button Text & Icon properties */
    setButtonProps(therapyButton, tr(" Therapy"),Providers::getIconString(THERAPY_ICON));
    setButtonProps(sleepReportButton, tr("Sleep Report"),Providers::getIconString(SLEEP_REPORT_ICON));
    setButtonProps(maskOptionButton, tr("Mask Options"),Providers::getIconString(MASK_OPTION_ICON));
    setButtonProps(settignsButton, tr("Settings"),Providers::getIconString(SETTINGS_ICON));

    /* Connect Button Pressed events to user defined functions */
    connect(therapyButton, SIGNAL(released()),SLOT(therapyButton_released()));
    connect(sleepReportButton, SIGNAL(released()),SLOT(sleepReportButton_released()));
    connect(maskOptionButton, SIGNAL(released()),SLOT(maskOptionButton_released()));
    connect(settignsButton, SIGNAL(released()),SLOT(settignsButton_released()));
}
void HomeWindowBasic::setButtonProps(Button3 * pButton,const QString &titleStr,const QString &imageStr)
{
    QFont fontTitle("Roboto-Light", 9);

    /* Set button radius */
    pButton->setButtonRadius(5);
    /* Set button Title with Specified font & text */
    pButton->setTitle(titleStr,fontTitle,QColor(0xFFFFFF));
    /* Set button text spacing */
    pButton->setTextSpacing(40);
    /* Set image of button specified */
    pButton->setImage(imageStr);
    /* Set backgound gradient color */
    pButton->setBackgroundColor(0x0082C8,0x667DB6);
    /* Enable gradient effect */
    pButton->enableGradientEffect(true);
}

void HomeWindowBasic::therapyButton_released(void)
{
    /* When therapy button pressed update therapy screen widget &
     * start animation to show Therapy screen
     */
    emit showHomeWindowBasic();
}

void HomeWindowBasic::sleepReportButton_released(void)
{
    /* When Sleep report button pressed update Sleep report screen widget &
     * start animation to show Sleep report screen
     */
    emit showSleepReportWindowBasic();
}

void HomeWindowBasic::maskOptionButton_released(void)
{
    /* When Mask button pressed update Mask screen widget &
     * start animation to show Mask screen
     */
    emit showMaskOptionsWindowBasic();
}

void HomeWindowBasic::settignsButton_released(void)
{
    /* When Settings button pressed update Settings screen widget &
     * start animation to show Settings screen
     */
    emit showSettingsWindowBasic();
}

void HomeWindowBasic::on_frescaLogo_pressed()
{
    /* When clinical view button pressed start its timer for specified interval */
    timerOver = false;
    timerClinical->start(USER_CLINICAL_MODE_SWITCHING_TIME);
}

const int HomeWindowBasic::clinicalPassword[9] = {1,9,1,0,2,0,1,8,1};

void HomeWindowBasic::on_frescaLogo_released()
{
    /* Whene Clinical view button released stop timer
     * check if timer expire flag activate or not
     */
    timerClinical->stop();
    if(timerOver == true)
    {
//#ifdef ENABLE_PASSWORD
//        connect(passwordScreen, SIGNAL(dialogClose()),
//                this,SLOT(passwordCheckWindowClosed()));

//        emit showPasswordEnterScreen(clinicalPassword);
//#else
        passwordCheckWindowClosed();
//#endif
    }

    ui->frescaLogo->setStyleSheet(QStringLiteral("border:none;border-radius:3px;background-color:#313131;"));
}

void HomeWindowBasic::passwordCheckWindowClosed()
{
    /* If entered password is correct show Clinical view screen */
    globalVar.clinicalMode = On;
    emit showClinicalHomeScreen();
}

void HomeWindowBasic::timerClinicalTimeOut()
{
    /* When Clinical screen timer timeouts
     * Stop timer & update clinical entry button background
     */
    timerOver = true;
    timerClinical->stop();
    ui->frescaLogo->setStyleSheet(QStringLiteral("border:none;border-radius:3px;background-color:#3B3B3B;"));
}


void HomeWindowBasic::updateText()
{
    setButtonProps(therapyButton, tr(" Therapy"),Providers::getIconString(THERAPY_ICON));
    setButtonProps(sleepReportButton, tr("Sleep Report"),Providers::getIconString(SLEEP_REPORT_ICON));
    setButtonProps(maskOptionButton, tr("Mask Options"),Providers::getIconString(MASK_OPTION_ICON));
    setButtonProps(settignsButton, tr("Settings"),Providers::getIconString(SETTINGS_ICON));
}

void HomeWindowBasic::changeEvent(QEvent* e)
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
