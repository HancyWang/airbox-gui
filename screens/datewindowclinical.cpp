#include "datewindowclinical.h"
#include "ui_datewindowclinical.h"
#include "ex_variables.h"
#include "constants.h"
#include <QDate>



DateWindowClinical::DateWindowClinical(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::DateWindowClinical),
    parentEffect(nullptr),
    m_dateWheel(nullptr),
    m_monthWheel(nullptr),
    m_yearWheel(nullptr)
{
    hide();
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setAttribute(Qt::WA_TranslucentBackground,true);
    move(60,56);

    ui->dateLayout->setGeometry(QRect(74,32,205,130));

    QFont title("Roboto-Light",9);
    ui->dateTitle->setFont(title);

    title.setPointSize(10);
    ui->dateAccept->setFont(title);
    ui->dateCancel->setFont(title);

    int touch = 1;

    QFont font("Sans Serif",13);
    m_yearWheel = new StringWheelWidget(touch,this);
    m_yearWheel->setItems( Providers::getYearStringList() );
    m_yearWheel->setTextFont(font);
    ui->dateLayout->addWidget( m_yearWheel, 0, 0 );

    m_monthWheel = new StringWheelWidget(touch,this);
    m_monthWheel->setItems( Providers::getMonthStringList() );
    m_monthWheel->setTextFont(font);
    ui->dateLayout->addWidget( m_monthWheel, 0, 1 );

    m_dateWheel = new StringWheelWidget(touch,this);
    m_dateWheel->setItems( Providers::getDateStringList() );
    m_dateWheel->setTextFont(font);
    ui->dateLayout->addWidget( m_dateWheel, 0, 2 );


    connect(m_yearWheel,SIGNAL(valueChanged()),this,SLOT(yearChanged()));
    connect(m_monthWheel,SIGNAL(valueChanged()),this,SLOT(monthChanged()));

    QScroller::grabGesture(ui->dateLayout, QScroller::TouchGesture);

}

DateWindowClinical::~DateWindowClinical()
{
    delete ui;
}

void DateWindowClinical::monthChanged()
{
    updateDateAsPerYearOrMonth();
}

void DateWindowClinical::yearChanged()
{
    updateDateAsPerYearOrMonth();
}

void DateWindowClinical::updateDateAsPerYearOrMonth()
{
    int year,month,date;

    year = m_yearWheel->currentIndex();
    date = m_dateWheel->currentIndex();
    month = m_monthWheel->currentIndex() + 1;

    qDebug() << Q_FUNC_INFO << year << month << date;

    year = m_yearWheel->getItemsAt(m_yearWheel->currentIndex()).toInt();
    date = m_dateWheel->getItemsAt(m_dateWheel->currentIndex()).toInt();

    QDate tDate(year,month,date);
    if(!tDate.isValid()){
        m_dateWheel->setCurrentIndex(0);
        date = 1;
    }

    updateAvailableDatesinMonth(date,month,year);
}
void DateWindowClinical::updateAvailableDatesinMonth(int date,int month,int year)
{
    QDate tDate(year,month,date);
    int tDaysInMonth = tDate.daysInMonth();

    QStringList tDateList;
    tDateList = Providers::getDateStringList();
    int tAvailableCount = tDateList.count();

    int tRemoveDays = tAvailableCount - tDaysInMonth;
    if(tRemoveDays)
    {
        for(int i=tAvailableCount ; i>tDaysInMonth ; i--)
        {
            tDateList.removeAt(i-1);
        }
    }

    /* Update number of valid dates in a month set */
    m_dateWheel->setItems( tDateList );
}

void DateWindowClinical::updateParameteres(int date,int month,int year)
{
    currentDate = date;
    currentMonth = month;
    currentYear = PRODUCT_START_YEAR - year;
    if(year < PRODUCT_START_YEAR)
        currentYear = PRODUCT_START_YEAR - year;
    else
        currentYear = year - PRODUCT_START_YEAR;

    updateAvailableDatesinMonth(date,month,year);

    m_dateWheel->setCurrentIndex((currentDate - 1));
    m_monthWheel->setCurrentIndex((currentMonth - 1));
    m_yearWheel->setCurrentIndex(currentYear);

//    qDebug() << Q_FUNC_INFO << parentEffect ;
    setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setAttribute(Qt::WA_TranslucentBackground,true);

//    qDebug() << Q_FUNC_INFO << currentDate << currentMonth << currentYear
//             << date << month << year;
}

void DateWindowClinical::on_dateAccept_released()
{
    currentDate = m_dateWheel->currentIndex();
    currentMonth = m_monthWheel->currentIndex();
    currentYear = m_yearWheel->currentIndex();
    QString str = Providers::getYearTextString(currentYear);
    currentYear = str.toInt();

//    qDebug() << Q_FUNC_INFO << currentDate << currentMonth << currentYear;

//    qDebug() << Q_FUNC_INFO << parentEffect ;

//    emit dialogClose();
    emit screenClose(currentDate,currentMonth,currentYear);

    if(colorEffectEnabled)
    {
        parentEffect->setEnabled(false);
        colorEffectEnabled = false;
    }

    hide();
    setModal(false);
}

void DateWindowClinical::enableColorEffect(bool state)
{
    colorEffectEnabled = state;

    if(colorEffectEnabled == true)
        parentEffect->setEnabled(colorEffectEnabled);
}

void DateWindowClinical::on_dateCancel_released()
{
//    qDebug() << Q_FUNC_INFO << parentEffect ;

    if(colorEffectEnabled)
    {
        parentEffect->setEnabled(false);
        colorEffectEnabled = false;
    }

    hide();
    setModal(false);
}

void DateWindowClinical::showDateScreen(QWidget *parent,int date,int month,int year,bool colorEffect)
{
    move(0,0);
    setParent(parent);
    move(60,56);
    updateParameteres(date,month,year);
    enableColorEffect(colorEffect);
    setModal(true);
    show();
}

void DateWindowClinical::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
