/*!
    \class Button1
    \brief The Button1 class is a button class that contains
    Title,Subtitle,Icon,Arrow

    \ingroup Widgetes
*/

#include <QPainter>
#include <QPainterPath>

#include "button1.h"
#include "constants.h"

Button1::Button1(QWidget *parent) : QAbstractButton(parent)
{

}
Button1::~Button1()
{
//    delete ui;
}

void Button1::paintEvent(QPaintEvent *e) {
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

        if(opacity) {
            p.setOpacity(opacity);
        }

        //Draw Rounded Rect
        path.addRoundedRect(rect(), ButtonRadius, ButtonRadius);
        QPen pen(Qt::black, 1);
        p.setPen(pen);
        if(isDown()) {
            p.fillPath(path,QColor(BackgroundColorPressed));
        } else {
            p.fillPath(path,QColor(BackgroundColorUnPressed));
        }

        p.setOpacity(1.0);
        //Draw Title
        if(!TitleText.isNull()) {
            p.setPen(TitleColor);
            p.setFont(TitleFont);
            if(SubTitleText.isNull()) {
                p.drawText(rect().adjusted(leftSpace,0,-rightSpace,0), Qt::AlignLeft | Qt::AlignVCenter,TitleText);
            } else {
                p.drawText(rect().adjusted(leftSpace,0,-rightSpace,-(rect().height()/3)*2), Qt::AlignLeft | Qt::AlignVCenter,TitleText);
            }
        }

        //Draw SubTitle
        if(!SubTitleText.isNull()) {
            p.setPen(SubTitleColor);
            p.setFont(SubTitleFont);
            p.drawText(rect().adjusted(leftSpace,(rect().height()/3),-rightSpace,0), Qt::AlignLeft | Qt::AlignVCenter,SubTitleText);
        }

        if(unitVisibility){
            QFontMetrics fm(SubTitleFont);
            int width = fm.width(SubTitleText);
            p.setPen(UnitColor);
            p.setFont(UnitFont);
            p.drawText(rect().adjusted(leftSpace + width +10,(rect().height()/3),-rightSpace,0), Qt::AlignLeft | Qt::AlignVCenter,UnitText);
        }

        //Draw Left Images
        if(!LeftImage.isNull()) {
            p.drawPixmap(((leftSpace/2)-(LeftImage.width()/2)),((rect().height()/2)-(LeftImage.height()/2)),LeftImage.width(),LeftImage.height(),LeftImage);
        }

        //Draw Right Images
        if(!RightImage.isNull()) {
            p.drawPixmap((rect().width()-(rightSpace/2))-(RightImage.width()/2),((rect().height()/2)-(RightImage.height()/2)),RightImage.width(),RightImage.height(),RightImage);
        }
    }
}
void Button1::setButtonRadius(int rad)
{
    ButtonRadius = rad;
    update();
}

void Button1::setBackgroundColor(const QColor &bkColorPressed,const QColor &bkColorUnPressed)
{
    BackgroundColorPressed = bkColorPressed;
    BackgroundColorUnPressed = bkColorUnPressed;
    update();
}

void Button1::setTitle(const QString &titleStr,const QFont &titleFont,const QColor &titleColor)
{
    TitleText = titleStr;
    TitleFont = titleFont;
    TitleColor = titleColor;
    update();
}

void Button1::setUnit(const QString &unitStr,const QFont &unitFont,const QColor &unitColor)
{
    UnitText = unitStr;
    UnitFont = unitFont;
    UnitColor = unitColor;
    update();
}

void Button1::setLeftRightSpacing(int left,int right)
{
    leftSpace = left;
    rightSpace = right;
    update();
}

void Button1::setSubTitle(const QString &subTitleStr,const QFont &subTitleFont,const QColor &subTitleColor)
{
    SubTitleText = subTitleStr;
    SubTitleFont = subTitleFont;
    SubTitleColor = subTitleColor;
    update();
}
void Button1::updateSubTitleText(const QString &subTitleText)
{
    SubTitleText = subTitleText;
    update();
}
//void Button1::updateSubTitleText(const QChar* s)
//{
//    SubTitleText=QString(s);
//    update();
//}

void Button1::updateUnitText(const QString &unitText)
{
    UnitText = unitText;
    update();
}
void Button1::setUnitVisibility(bool vis)
{
    unitVisibility = vis;
    update();
}

void Button1::updateTitleText(const QString &titleText)
{
    TitleText = titleText;
    update();
}

void Button1::setOpacity(const qreal &opace)
{
    opacity = opace;
    update();
}

void Button1::setImageLeft(int x,int y,int w,int h,const QString &fileName)
{
    leftX = x;
    leftY = y;
    leftW = w;
    leftH = h;

    LeftImage.load(fileName);
    update();
}

void Button1::setImageRight(int x,int y,int w,int h,const QString &fileName)
{
    rightX = x;
    rightY = y;
    rightW = w;
    rightH = h;
    RightImage.load(fileName);
    update();
}

/*!
    \class Button1
    \brief On Button pressed event

    \ingroup Widgets
*/
void Button1::mousePressEvent(QMouseEvent *e)
{
    QAbstractButton::mousePressEvent(e);
}

/*!
    \class Button1
    \brief On Button released event

    \ingroup Widgets
*/
void Button1::mouseReleaseEvent(QMouseEvent *e)
{
    QAbstractButton::mouseReleaseEvent(e);
//    animateClick();
}


void Button1::enterEvent(QEvent *e)
{
    QAbstractButton::enterEvent(e);
}
