#include "sleepreportmorewindowbasic.h"
#include "ui_sleepreportmorewindowbasic.h"
#include "ex_variables.h"


#include "application/datalogging.h"

const QStringList SleepReportMoreWindowBasic::periodList =
{
    "1 Day",
    "1 Week",
    "1 Month",
    "3 Month",
    "6 Month",
    "1 Year"
};

SleepReportMoreWindowBasic::SleepReportMoreWindowBasic(QWidget *parent,
                                                       DataLogging * m_DataBackend,
                                                       SleepReportWindowBasic * sleepReportBasicBackend)
    : QDialog(parent),
    ui(new Ui::SleepReportMoreWindowBasic),
    m_DataManager(m_DataBackend),
    sleepReportBasicScreen(sleepReportBasicBackend),
    m_Anim(nullptr),
    periodSelection(nullptr),
    backToHomeButton(nullptr),
    dropDownScreen(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowState(Qt::WindowFullScreen);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setGeometry(0,0,width(),height());

    connect(this,SIGNAL(getSleepReportData(int,sendSleepReportParam,QFileInfoList,int,float*,float*,float*,int*,int*,float*)),
            m_DataManager,SLOT(getSleepReportData(int,sendSleepReportParam,QFileInfoList,int,float*,float*,float*,int*,int*,float*)));

    if(sleepReportBasicScreen)
    {
        connect(this, SIGNAL(backToHomeButtonPressed()),
                sleepReportBasicScreen,SLOT(backToHomeSleepReport()));

        connect(sleepReportBasicScreen,SIGNAL(showSleepReportMoreScreenFromList(QFileInfoList&)),
                this,SLOT(showSleepReportMoreScreenFromList(QFileInfoList&)));
    }

    periodSelection = new Button1(this);
    periodSelection->setGeometry(QRect(87,70,123,30));
    QFont settingsFontTitle("Roboto-Light", 8);
    QFont settingsFontSubTitle("Roboto-Thin", 14);

    periodSelection->setButtonRadius(3);
    periodSelection->setTitle(periodList.at(globalVar.sleepReportDuration - 1),settingsFontTitle,QColor(0xBDBDBD));
    periodSelection->updateSubTitleText(NULL);
    periodSelection->setBackgroundColor(0x606060,0x3e3e3e);
    periodSelection->setLeftRightSpacing(10,50);
    periodSelection->setImageRight(50,10,24,24,":/icons/drop_down.png");

    m_Anim = new QPropertyAnimation(this,"geometry");

    QFont title("Roboto-Light",12);
    ui->sleepReportMoreTitle->setFont(title);

    QFont unit("Roboto-Light",5);
    QFont value("Roboto-Thin",18);

    title.setPointSize(8);
    ui->daysUsedTitle->setFont(title);
    ui->days4HrsPlusTitle->setFont(title);
    ui->averageUsageTitle->setFont(title);
    ui->usedHoursTitle->setFont(title);
    ui->leakTitle->setFont(title);
    ui->ahiTitle->setFont(title);
    ui->sendSleepReportButton->setFont(title);

    ui->daysUsedText->setFont(value);
    ui->days4HrsPlusText->setFont(value);
    ui->averageUsageText->setFont(value);
    ui->usedHoursText->setFont(value);
    ui->leakText->setFont(value);
    ui->ahiText->setFont(value);

    ui->daysUsedUnit->setFont(unit);
    ui->days4HrsPlusUnit->setFont(unit);
    ui->averageUsageUnit->setFont(unit);
    ui->usedHoursUnit->setFont(unit);
    ui->leakUnit->setFont(unit);

    ui->selectionPeriod->setFont(title);

    backToHomeButton = new Button3(this);
    backToHomeButton->setGeometry(QRect(8,215,118,50));
    backToHomeButton->setButtonRadius(5);
    backToHomeButton->setTitle("Home",title,QColor(0xBDBDBD));
    backToHomeButton->setTextSpacing(30);
    backToHomeButton->setImage(":/icons/back_home_button.png");
    backToHomeButton->setBackgroundColor(0x3B3B3B,0x606060);

    connect(backToHomeButton, SIGNAL(released()),SLOT(backToHomeButton_released()));
    connect(periodSelection, SIGNAL(released()),SLOT(periodSelection_released()));

    updateSleepReportMoreAsPerMode(globalVar.clinicalMode);

    // Not required now
    ui->ahi->hide();
    ui->sendSleepReportButton->hide();
}

SleepReportMoreWindowBasic::~SleepReportMoreWindowBasic()
{
    delete ui;
}

void SleepReportMoreWindowBasic::animateSleepReportMoreWindow(openCloseStatus state)
{
    if (state) {
        this->show();
        m_Anim->setStartValue(QRect(480, 0, 480, 272));
        m_Anim->setEndValue(QRect(0, 0, 480, 272));
        m_Anim->setDuration(WINDOW_ANIMATION_OPEN_DURATION);
        m_Anim->setEasingCurve(WINDOW_OPEN_TRANSITION);
        connect(m_Anim, SIGNAL(finished()),SLOT(show()));
    } else {
        m_Anim->setStartValue(QRect(0, 0, 480, 272));
        m_Anim->setEndValue(QRect(480, 0, 480, 272));
        m_Anim->setDuration(WINDOW_ANIMATION_CLOSE_DURATION);
        m_Anim->setEasingCurve(WINDOW_CLOSE_TRANSITION);
        connect(m_Anim, SIGNAL(finished()),SLOT(hide()));
    }
    m_Anim->start();
}


void SleepReportMoreWindowBasic::updateSleepReportMoreAsPerMode(bool clinicalMode)
{
    if(clinicalMode)
        ui->sendSleepReportButton->hide();
    else
        ui->sendSleepReportButton->show();
}

void SleepReportMoreWindowBasic::on_backSleepReportMoreButton_clicked()
{
    animateSleepReportMoreWindow(Close);
}

void SleepReportMoreWindowBasic::on_sendSleepReportButton_released()
{
}

void SleepReportMoreWindowBasic::backToHomeButton_released()
{
    animateSleepReportMoreWindow(Close);
    emit backToHomeButtonPressed();
}

void SleepReportMoreWindowBasic::periodSelection_released()
{
    dropDownScreen = new DropDownSelector(this);
    dropDownScreen->move(87,70);
    dropDownScreen->updateButton1TextVisible(periodList.at(0),true);
    dropDownScreen->updateButton2TextVisible(periodList.at(1),true);
    dropDownScreen->updateButton3TextVisible(periodList.at(2),true);
    dropDownScreen->updateButton4TextVisible(periodList.at(3),true);
    dropDownScreen->updateButton5TextVisible(periodList.at(4),true);
    dropDownScreen->updateButton6TextVisible(periodList.at(5),true);
    connect(dropDownScreen, SIGNAL(dialogClose()),this,SLOT(periodSelectionClosed()));
    dropDownScreen->setAllButtonsHeight(20);
    dropDownScreen->updateLayoutSize(QRect(0,0,123,127));
    dropDownScreen->resize(123,127);
    dropDownScreen->show();
}

void SleepReportMoreWindowBasic::showSleepReportMoreScreenFromList(QFileInfoList &directorList)
{
    updateSleepReportMoreProcessBeforeShow(directorList);
    animateSleepReportMoreWindow(Open);
}

void SleepReportMoreWindowBasic::periodSelectionClosed()
{
    globalVar.sleepReportDuration = static_cast<sendSleepReportParam>(dropDownScreen->index);
    periodSelection->updateTitleText(periodList.at((globalVar.sleepReportDuration - 1)));

    parseAndUpdateFieldAsPerSelection(globalVar.sleepReportDuration,fileList);
}

void SleepReportMoreWindowBasic::updateSleepReportMoreProcessBeforeShow(QFileInfoList & logFileList)
{
    globalVar.sleepReportDuration = day1;
    periodSelection->updateTitleText(periodList.at((globalVar.sleepReportDuration - 1)));

    fileList = logFileList;
    parseAndUpdateFieldAsPerSelection(globalVar.sleepReportDuration,fileList);
//    parseAndUpdateFieldAsPerSelection(globalVar.sleepReportDuration,logFileList);
}

#include <QFileInfoList>
void SleepReportMoreWindowBasic::parseAndUpdateFieldAsPerSelection(sendSleepReportParam param,QFileInfoList & logFileList)
{
    float tUsageHours=0;
    float tEventsPerHour=0;
    float tLeakage=0;
    int tHoursUsed4Plus=0;
    int tDaysUsed=0;
    float tAverageUsed=0;
    //TODO Parse & set text to appropriate field in this window
    if(fileList.length()){
        emit getSleepReportData(SLEEP_REPORT_EXTENDED,param,fileList,(fileList.length() - 1),&tUsageHours,&tEventsPerHour,&tLeakage,&tHoursUsed4Plus,&tDaysUsed,&tAverageUsed);
        ui->usedHoursText->setText(QString::number(tUsageHours,'f',2));
        ui->ahiText->setText(QString().setNum(tEventsPerHour,'f',2));
        ui->leakText->setText(QString().setNum(tLeakage,'f',2));
        ui->days4HrsPlusText->setText(QString::number(tHoursUsed4Plus));
        ui->daysUsedText->setText(QString::number(tDaysUsed));
        ui->averageUsageText->setText(QString().setNum(tAverageUsed,'f',2));
    } else {
        ui->days4HrsPlusText->setText("-");
        ui->daysUsedText->setText("-");
        ui->averageUsageText->setText("-");
        ui->usedHoursText->setText("-");
        ui->leakText->setText("-");
        ui->ahiText->setText("-");
    }
}

void SleepReportMoreWindowBasic::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
