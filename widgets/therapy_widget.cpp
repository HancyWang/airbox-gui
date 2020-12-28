/*!
    \class TherapyWidget
    \brief The TherapyWidget class is a button class that contains
    Title,Subtitle,Icon,Arrow

    \ingroup Widgets
*/

#include <QPainter>

#include "therapy_widget.h"
#include "shareddata.h"

TherapyWidget::TherapyWidget(QWidget *parent)
    : QWidget(parent),
      layout(nullptr),
      title(nullptr),
      value(nullptr),
      unit(nullptr),
      subValue(nullptr)
{
    initialize();
}
void TherapyWidget::initialize()
{
    layout = new QVBoxLayout(this);
    title = new QLabel(this);
    value = new QLabel(this);
    unit = new QLabel(this);
    subValue = new QLabel(this);

    layout->setSpacing(0);

    subValue->setAttribute(Qt::WA_TranslucentBackground,true);
    value->setAttribute(Qt::WA_TranslucentBackground,true);
    title->setAttribute(Qt::WA_TranslucentBackground,true);
    unit->setAttribute(Qt::WA_TranslucentBackground,true);

    layout->addWidget(subValue);
    layout->addWidget(value);
    layout->addWidget(unit);
    layout->addWidget(title);

    layout->setStretch(0,6);
    layout->setStretch(1,7);
    layout->setStretch(2,1);
    layout->setStretch(3,1);

    subValue->setAlignment(Qt::AlignHCenter|Qt::AlignBottom);
    title->setAlignment(Qt::AlignHCenter|Qt::AlignBottom);
    unit->setAlignment(Qt::AlignHCenter|Qt::AlignBottom);
    value->setAlignment(Qt::AlignHCenter|Qt::AlignBottom);
}

TherapyWidget::~TherapyWidget()
{
//    delete ui;
}

void TherapyWidget::paintEvent(QPaintEvent *e) {
    (void)e;
    if (isEnabled()) {

        QPainter p(this);
        p.setRenderHint(QPainter::Antialiasing,true);
        if(opacity)
        {
            p.setOpacity(opacity);
        }

        //Draw Rounded Rect
        QPen pen(blankBarColor,barSize);
        p.setPen(pen);

        pen.setColor(blankBarColor);
        //each degree is divided into 16 stepsS
        //ie.   270 degree = 270 * 16 = 4320
        p.drawArc(rect().adjusted(10,10,-10,0), (leftAngle * 16), -(rightAngle * 16));

        if(fillBarVisibility == true) {
            float tempArea = static_cast<float>(rightAngle)/maxPressure;
            int fillArea = tempArea * pressure * 16;

//            qDebug() << "P :" << tempArea << fillArea << pressure << rightAngle << maxPressure;
            if(fillArea) {
                QPen pen1(fillBarColor,barSize);
                p.setPen(pen1);
                p.drawArc(rect().adjusted(10,10,-10,0), (leftAngle * 16), -fillArea);
            }
        }
    }
}


void TherapyWidget::setLeftRightAngles(int left,int right)
{
    leftAngle = left;
    rightAngle = right;
    update();
}
void TherapyWidget::setPressureValue(int val)
{
    if(pressure != val)
    {
        pressure = val;
        QString s = QString::number(val);
        value->setText(s);
        update();
    }
}

void TherapyWidget::setValueProperties(const QFont &font,const QString &styleSheet)
{
    value->setFont(font);
    value->setStyleSheet(styleSheet);
}
void TherapyWidget::setSubValueProperties(const QFont &font,const QString &styleSheet)
{
    subValue->setFont(font);
    subValue->setStyleSheet(styleSheet);
}

void TherapyWidget::setUnitProperties(const QString &unitStr,const QFont &font,const QString &styleSheet)
{
    unit->setStyleSheet(styleSheet);
    unit->setFont(font);
    unit->setText(unitStr);
}

void TherapyWidget::setTitleProperties(const QString &text,const QFont &font,const QString &styleSheet)
{
    title->setFont(font);
    title->setStyleSheet(styleSheet);
    title->setText(text);
}

void TherapyWidget::setSubValue(int val)
{
    if(subValueInt != val)
    {
        subValueInt = val;

#ifdef CHANGE_PRESSURE_STEP_TO_05
    QString str_integer=QString::number(subValueInt/100);
    QString str_decimals=QString::number(subValueInt%100/10);
    QString str=str_integer+"."+str_decimals;
#else
    QString str = QString::number(subValueInt);
#endif

        subValue->setText(str);
    }
}

void TherapyWidget::setBarSize(int size)
{
    if(barSize != size)
    {
        barSize = size;
        update();
    }
}

#include <QDebug>
void TherapyWidget::setPressure(int pres)
{
    if(pressure != pres)
    {
//        qDebug() << Q_FUNC_INFO << pressure << pres;
        pressure = pres;
        float lVisiblePressure = static_cast<float>(pres)/ 100;
        QString s = QString::number(lVisiblePressure,'f',1);
        value->setText(s);
        update();
    }
}

int TherapyWidget::getPressure(void)
{
    return pressure;
}

void TherapyWidget::setLayoutGeometry(const QRect &rec)
{
    layout->setGeometry(rec);
}

void TherapyWidget::setBlankBarColor(QColor color)
{
    if(blankBarColor != color)
    {
        blankBarColor = color;
        update();
    }
}

void TherapyWidget::setFillBarColor(QColor color)
{
    if(fillBarColor != color)
    {
        fillBarColor = color;
        update();
    }
}

void TherapyWidget::setFillBarVisibleState(bool state)
{
    if(fillBarVisibility != state)
    {
        fillBarVisibility = state;
        update();
    }
}

void TherapyWidget::setmaxPressure(int max)
{
#ifdef CHANGE_PRESSURE_STEP_TO_05
    int tMaxValue = max;
#else
    int tMaxValue = max * 100;
#endif

    if(maxPressure != tMaxValue)
    {
//        qDebug() << Q_FUNC_INFO << maxPressure << tMaxValue;

        maxPressure = tMaxValue;
        update();
    }
}
