/*!
    \class Button4
    \brief The Button4 class is a button class that contains
    Title,Subtitle,Icon,Arrow

    \ingroup Widgetes
*/

#include <QPainter>
#include <QPainterPath>

#include "button4.h"
#include "constants.h"

Button4::Button4(QWidget *parent) : QAbstractButton(parent)
{

}
Button4::~Button4()
{
//    delete ui;
}

void Button4::paintEvent(QPaintEvent *e) {
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
            p.drawText(rect().adjusted(leftSpace,0,-rightSpace,0), Qt::AlignLeft | Qt::AlignVCenter,TitleText);
//            if(SubTitleText.isNull())
//            {
//            }
//            else
//            {
//                p.drawText(rect().adjusted(leftSpace,0,-rightSpace,-(rect().height()/3)*2), Qt::AlignLeft | Qt::AlignVCenter,TitleText);
//            }
        }

        //Draw Left Images
        if(!LeftImage.isNull())
        {
            p.drawPixmap(((leftSpace/2)-(LeftImage.width()/2)),((rect().height()/2)-(LeftImage.height()/2)),LeftImage.width(),LeftImage.height(),LeftImage);
        }

        //Draw Right Images
        if(!RightImage.isNull())
        {
            p.drawPixmap((rect().width()-(rightSpace/2))-(RightImage.width()/2),((rect().height()/2)-(RightImage.height()/2)),RightImage.width(),RightImage.height(),RightImage);
        }

        //Draw Third Images
        if(!ThirdImage.isNull())
        {
            p.drawPixmap((rect().width()-(thirdSpace/2))-(ThirdImage.width()/2),((rect().height()/2)-(ThirdImage.height()/2)),ThirdImage.width(),ThirdImage.height(),ThirdImage);
        }
    }
}
void Button4::setButtonRadius(int rad)
{
    ButtonRadius = rad;
    update();
}

void Button4::setBackgroundColor(const QColor &bkColorPressed,const QColor &bkColorUnPressed)
{
    BackgroundColorPressed = bkColorPressed;
    BackgroundColorUnPressed = bkColorUnPressed;
    update();
}

void Button4::setTitle(const QString &titleStr,const QFont &titleFont,const QColor &titleColor)
{
    TitleText = titleStr;
    TitleFont = titleFont;
    TitleColor = titleColor;
    update();
}

void Button4::setLeftRightSpacing(int left,int right,int third)
{
    leftSpace = left;
    rightSpace = right;
    thirdSpace = third;
    update();
}


void Button4::setOpacity(const qreal &opace)
{
    opacity = opace;
    update();
}

void Button4::setImageLeft(const QString &fileName)
{
    LeftImage.load(fileName);
    update();
}

void Button4::setImageRight(const QString &fileName)
{
    RightImage.load(fileName);
    update();
}

void Button4::setImageThird(const QString &fileName)
{
    ThirdImage.load(fileName);
    update();
}


/*!
    \class Button4
    \brief On Button pressed event

    \ingroup Widgets
*/
void Button4::mousePressEvent(QMouseEvent *e)
{
    QAbstractButton::mousePressEvent(e);
}

/*!
    \class Button4
    \brief On Button released event

    \ingroup Widgets
*/
void Button4::mouseReleaseEvent(QMouseEvent *e)
{
//    QAbstractButton::mouseReleaseEvent(e);
    animateClick();
}


void Button4::enterEvent(QEvent *e)
{
    QAbstractButton::enterEvent(e);
}
