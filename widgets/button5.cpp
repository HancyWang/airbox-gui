/*!
    \class Button5
    \brief The Button5 class is a button class that contains
    Title,Subtitle,Icon,Arrow

    \ingroup Widgetes
*/

#include <QPainter>
#include <QPainterPath>

#include "button5.h"
#include "constants.h"

Button5::Button5(QWidget *parent) : QAbstractButton(parent)
{

}
Button5::~Button5()
{
//    delete ui;
}

void Button5::paintEvent(QPaintEvent *e) {
    (void)e;
    if (isEnabled()) {
//        //Draw Background
////        if requires stylesheet facility enable this
////        QStyleOption opt;
////        opt.init(this);
////        style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

        QPainter p(this);
        p.setRenderHint(QPainter::Antialiasing,true);
        QPainterPath path;

        if(opacity)
        {
            p.setOpacity(opacity);
        }

        //Draw Rounded Rect
        path.addRoundedRect(rect(), ButtonRadius, ButtonRadius);
        QPen pen(Qt::black, 1);
        p.setPen(pen);
        if(isDown())
        {
            p.fillPath(path,QColor(BackgroundColorPressed));
        }
        else
        {
            p.fillPath(path,QColor(BackgroundColorUnPressed));
        }

        p.setOpacity(1.0);
        //Draw Title
        if(!TitleText.isNull())
        {
            p.setPen(TitleColor);
            p.setFont(TitleFont);
            p.drawText(rect().adjusted(0,3,0,0), Qt::AlignTop | Qt::AlignHCenter,TitleText);
        }

        //Draw ValueTitle
        if(!ValueText.isNull())
        {
            p.setPen(ValueColor);
            p.setFont(ValueFont);
            p.drawText(rect().adjusted(3,0,-5,-3), Qt::AlignLeft | Qt::AlignBottom,ValueText);
        }

        //Draw UnitTitle
        if(!UnitText.isNull())
        {
            p.setPen(UnitColor);
            p.setFont(UnitFont);
            p.drawText(rect().adjusted(20,0,0,-3), Qt::AlignLeft | Qt::AlignBottom,UnitText);
        }
    }
}
void Button5::setButtonRadius(int rad)
{
    ButtonRadius = rad;
    update();
}

void Button5::setBackgroundColor(const QColor &bkColorPressed,const QColor &bkColorUnPressed)
{
    BackgroundColorPressed = bkColorPressed;
    BackgroundColorUnPressed = bkColorUnPressed;
    update();
}

void Button5::setTitle(const QString &titleStr,const QFont &titleFont,const QColor &titleColor)
{
    TitleText = titleStr;
    TitleFont = titleFont;
    TitleColor = titleColor;
    update();
}

void Button5::updateValueUnitText(const QString &valueStr,const QString &unitStr)
{
    ValueText = valueStr;
    UnitText = unitStr;
    update();
}

void Button5::setValue(const QString &valueStr,const QFont &valueFont,const QColor &valueColor)
{
    ValueText = valueStr;
    ValueFont = valueFont;
    ValueColor = valueColor;
    update();
}

void Button5::setUnit(const QString &unitStr,const QFont &unitFont,const QColor &unitColor)
{
    UnitText = unitStr;
    UnitFont = unitFont;
    UnitColor = unitColor;
    update();
}

void Button5::setOpacity(const qreal &opace)
{
    opacity = opace;
    update();
}

/*!
    \class Button5
    \brief On Button pressed event

    \ingroup Widgets
*/
void Button5::mousePressEvent(QMouseEvent *e)
{
    QAbstractButton::mousePressEvent(e);
}

/*!
    \class Button5
    \brief On Button released event

    \ingroup Widgets
*/
void Button5::mouseReleaseEvent(QMouseEvent *e)
{
    QAbstractButton::mouseReleaseEvent(e);
//    animateClick();
}


void Button5::enterEvent(QEvent *e)
{
    QAbstractButton::enterEvent(e);
}
