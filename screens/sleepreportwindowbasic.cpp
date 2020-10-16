#include "sleepreportwindowbasic.h"
#include "sleepreportmorewindowbasic.h"
#include "ui_sleepreportwindowbasic.h"
#include "ex_variables.h"

#include "application/datalogging.h"

SleepReportWindowBasic::SleepReportWindowBasic(QWidget *parent,
                                               DataLogging * m_DataBackend,
                                               HomeWindowBasic * m_HomeWindowBackend,
                                               HomeWindowClinical * homeClinicalBackend)
    : QDialog(parent),
    ui(new Ui::SleepReportWindowBasic),
    m_DataManager(m_DataBackend),
    m_HomeWindow(m_HomeWindowBackend),
    homeClinicalScreen(homeClinicalBackend),
    m_Anim(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowState(Qt::WindowFullScreen);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setGeometry(0,0,width(),height());

    if(m_DataManager)
    {
        connect(this,SIGNAL(getSleepReportData(int,sendSleepReportParam,QFileInfoList,int,float*,float*,float*,int*,int*,float*)),
                m_DataManager,SLOT(getSleepReportData(int,sendSleepReportParam,QFileInfoList,int,float*,float*,float*,int*,int*,float*)));
    }

    if(m_HomeWindow)
    {
        connect(m_HomeWindow,SIGNAL(showSleepReportWindowBasic()),
                this,SLOT(showSleepReportWindowBasic()));
    }

    if(homeClinicalScreen)
    {
        connect(homeClinicalScreen,SIGNAL(showSleepReportScreen(QWidget*)),
                this,SLOT(showSleepReportScreen(QWidget*)));
    }

    ui->usageTimeUnit->hide();
    ui->usageTimeUnit->hide();
    ui->eventsPerHourUnit->hide();

    m_Anim = new QPropertyAnimation(this,"geometry");

    QFont title("Roboto-Light",12);
    ui->sleepReportTitle->setFont(title);

    title.setPointSize(8);
    ui->lastRecordTimeTitle->setFont(title);
    ui->maskFitTitle->setFont(title);
    ui->eventsPerHourTitle->setFont(title);
    ui->usageTimeTitle->setFont(title);

    title.setPointSize(7);
    ui->usageTimeUnit->setFont(title);
    ui->eventsPerHourUnit->setFont(title);

    title.setPointSize(10);
    ui->lastRecordTimeText->setFont(title);

    QFont subTitle("Roboto-Thin",22);
    ui->usageTimeStatus->setFont(subTitle);
    ui->eventPerHourStatus->setFont(subTitle);

    updateSleepReportAsPerMode(globalVar.clinicalMode);
    ui->mskFitStatus->setPixmap(QPixmap(Providers::getEmojiIconString(globalVar.maskFitTest.maskFitTestStatus)));

    // Not required now
    ui->eventsPerHour->hide();
}

SleepReportWindowBasic::~SleepReportWindowBasic()
{
    delete ui;
}

void SleepReportWindowBasic::showSleepReportWindowBasic(void)
{
    updateSleepReportProcessBeforeShow();
    setParent(m_HomeWindow);
    animateSleepReportWindow(Open);
}

void SleepReportWindowBasic::animateSleepReportWindow(openCloseStatus state)
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

void SleepReportWindowBasic::updateLastRecordTherapyDetails(const QFileInfoList & list,int index)
{
    if(list.count() < index)        return;

    // Update Last recorded therapy time in UI
    QString lastTime = list.at(index).fileName();

    lastTime.size();

    QStringList dateTime = lastTime.split("_");

    if(dateTime.count() < 2)       return;

    //Format Date
    QString dateString = dateTime.at(0);
    QString year = dateString.mid(0,4);
    QString month = dateString.mid(4,2);
    QString date = dateString.mid(6,2);
    QDate localDate;
    month = localDate.shortMonthName(month.toInt());

    //Format Time
    QString timeString = dateTime.at(1);
    QString hour = timeString.mid(0,2);
    QString minute = timeString.mid(2,2);

    // Update Formatted Date & Time
    QString lastRecordTime = QString("%1,%2,%3 %4:%5").arg(date).arg(month).arg(year).arg(hour).arg(minute);
    ui->lastRecordTimeText->setText(lastRecordTime);
}

void SleepReportWindowBasic::updateUsageHoursAndEventsPerHoursLastNight(const QFileInfoList & list,int index)
{
    float tUsageHours=0;
    float tEventsPerHour=0;
    float tLeakage=0;
    int tHoursUsed4Plus=0;
    int tDaysUsed=0;
    float tAverageUsed=0;

    emit getSleepReportData(SLEEP_REPORT_BASIC,day1,list,index,&tUsageHours,&tEventsPerHour,&tLeakage,
                                  &tHoursUsed4Plus,&tDaysUsed,&tAverageUsed);

    updateUsageHourIconAsPerCondition(tUsageHours);
    updateEventsIconAsPerCondition(tEventsPerHour);

//    qDebug() << tUsageHours << tEventsPerHour ;
}

void SleepReportWindowBasic::updateUsageHourIconAsPerCondition(float tUsedTime)
{
//    qDebug() << "Used Time" << tUsedTime;
    if(tUsedTime > 4){
        ui->usageTimeStatus->setPixmap(QPixmap(Providers::getEmojiIconString(3)));
    }
    else if((tUsedTime > 2) & (tUsedTime < 3.99)){
        ui->usageTimeStatus->setPixmap(QPixmap(Providers::getEmojiIconString(2)));
    }
    else if((tUsedTime > 0) & (tUsedTime < 1.99)){
        ui->usageTimeStatus->setPixmap(QPixmap(Providers::getEmojiIconString(1)));
    }
}

void SleepReportWindowBasic::updateEventsIconAsPerCondition(float tEvents)
{
//    qDebug() << "Events" << tEvents;
    if(tEvents < 10){
        ui->eventPerHourStatus->setPixmap(QPixmap(Providers::getEmojiIconString(3)));
    }
    else if((tEvents > 10) & (tEvents < 19.99)){
        ui->eventPerHourStatus->setPixmap(QPixmap(Providers::getEmojiIconString(2)));
    }
    else if(tEvents > 20){
        ui->eventPerHourStatus->setPixmap(QPixmap(Providers::getEmojiIconString(1)));
    }
}

void SleepReportWindowBasic::getDirectoryWhichContainsEdfFiles(void)
{
    QStringList filterType;
    filterType.clear();
    filterType << "*.edf";

    QFileInfoList localFileList;
    QDir tSampleDir;
    QStringList localList;

    localFileList = directorList;
    int maxFilesInDir=directorList.length();
    for(int i=0 ; i<maxFilesInDir ; i++)
    {
        tSampleDir.setPath(localFileList.at(i).filePath());
        tSampleDir.setNameFilters(filterType);
        localList = tSampleDir.entryList();

        if(!localList.length())
        {
            /* If any directory doesn't contains edf file remove it from list */
            localFileList.removeAt(i);
        }
    }

    directorList.clear();
    directorList = localFileList;
}

void SleepReportWindowBasic::updateSleepReportProcessBeforeShow(void)
{
    // Update Last Record Therapy details
    QDir dirCheck;

    dirCheck.setPath(Providers::getEdfLogFilesPath());
    directorList = dirCheck.entryInfoList(QDir::NoDotAndDotDot|QDir::Dirs,QDir::Name);

    getDirectoryWhichContainsEdfFiles();

    // Get last Index
    int currentFileIndex = directorList.length() - 1;

    if(directorList.length()) {
        updateLastRecordTherapyDetails(directorList,currentFileIndex);
        updateUsageHoursAndEventsPerHoursLastNight(directorList,currentFileIndex);
    } else {
        //Show "-" in UI
        ui->lastRecordTimeText->setText("-");
        ui->mskFitStatus->setPixmap(QPixmap(Providers::getEmojiIconString(0)));
        ui->eventPerHourStatus->setPixmap(QPixmap(Providers::getEmojiIconString(0)));
        ui->usageTimeStatus->setPixmap(QPixmap(Providers::getEmojiIconString(0)));
    }
}

void SleepReportWindowBasic::updateSleepReportAsPerMode(bool clinicalMode)
{
    QIcon icon;
    if(clinicalMode) {
        ui->lastRecordTime->hide();
        icon.addFile(QStringLiteral(":/icons/clinical_logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        ui->homeSleepReportButton->setIcon(icon);
    } else {
        ui->lastRecordTime->show();
        icon.addFile(QStringLiteral(":/icons/home.png"), QSize(), QIcon::Normal, QIcon::Off);
        ui->homeSleepReportButton->setIcon(icon);
    }
}

void SleepReportWindowBasic::on_homeSleepReportButton_clicked()
{
    animateSleepReportWindow(Close);
}

void SleepReportWindowBasic::on_moreSleepReportButton_clicked()
{
    emit showSleepReportMoreScreenFromList(directorList);
}

void SleepReportWindowBasic::backToHomeSleepReport()
{
    animateSleepReportWindow(Close);
}

void SleepReportWindowBasic::showSleepReportScreen(QWidget *parent)
{
    updateSleepReportProcessBeforeShow();
    setParent(parent);
    animateSleepReportWindow(Open);
}

void SleepReportWindowBasic::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
