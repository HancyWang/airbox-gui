#include "timewindowclinical.h"
#include "ui_timewindowclinical.h"
#include "ex_variables.h"



TimeWindowClinical::TimeWindowClinical(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimeWindowClinical),
    parentEffect(nullptr),
    m_hourWheel(nullptr),
    m_minuteWheel(nullptr)
{
    hide();
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setAttribute(Qt::WA_TranslucentBackground,true);
    move(60,56);

    ui->timeLayout->setGeometry(QRect(74,32,205,130));

    QFont title("Roboto-Light",9);
    ui->timeTitle->setFont(title);

    title.setPointSize(10);
    ui->timeAccept->setFont(title);
    ui->timeCancel->setFont(title);

    int touch = 1;

    QFont font("Sans Serif",13);
    m_hourWheel = new StringWheelWidget(touch,this);
    m_hourWheel->setItems(Providers::getHourStringList());
    m_hourWheel->setTextFont(font);
    ui->timeLayout->addWidget( m_hourWheel, 0, 0 );

    m_minuteWheel = new StringWheelWidget(touch,this);
    m_minuteWheel->setItems(Providers::getMinuteStringList());
    m_minuteWheel->setTextFont(font);
    ui->timeLayout->addWidget( m_minuteWheel, 0, 1 );

    QScroller::grabGesture(ui->timeLayout, QScroller::TouchGesture);
}

TimeWindowClinical::~TimeWindowClinical()
{
    delete ui;
}

void TimeWindowClinical::updateParameteres(int hrs,int min)
{
    currentHours = hrs;
    currentMinutes = min;

    m_hourWheel->setCurrentIndex(currentHours);
//    m_hourWheel->setCurrentIndex((currentHours - 1));
    m_minuteWheel->setCurrentIndex(currentMinutes);

//    qDebug() << Q_FUNC_INFO << currentHours << currentMinutes << hrs << min;
}

void TimeWindowClinical::on_timeAccept_released()
{
    currentHours = m_hourWheel->currentIndex();
    currentMinutes = m_minuteWheel->currentIndex();

//    qDebug() << Q_FUNC_INFO << currentHours << currentMinutes ;

    emit dialogClose();
    emit screenClose(currentHours,currentMinutes);

    parentEffect->setEnabled(false);
    hide();
    setModal(false);
//    parentEffect = nullptr;
}

void TimeWindowClinical::on_timeCancel_released()
{
    parentEffect->setEnabled(false);
    hide();
    setModal(false);
//    parentEffect = nullptr;
}

void TimeWindowClinical::showTimeScreen(QWidget *parent, int hour, int minute, bool colorEffect)
{
//    setParent(parent);
    parentEffect->setEnabled(colorEffect);
    move(70,63);
    updateParameteres(hour,minute);
    setModal(true);
    show();
}

void TimeWindowClinical::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
