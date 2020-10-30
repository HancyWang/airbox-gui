/*!
    \class Button2
    \brief The Button2 class is a button class that contains
    Title,Subtitle,Icon,Switch

    \ingroup Widgetes
*/

#include <QPainter>
#include <QPainterPath>

#include "button2.h"
#include "constants.h"
#include "switch.h"
#include <QEvent>

Button2::Button2(QWidget *parent) : QAbstractButton(parent)
{
}

Button2::~Button2()
{
//    delete ui;
}

void Button2::paintEvent(QPaintEvent *e)
{
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
    }
}

void Button2::updateSubTitleText(const QString &subTitleText)
{
    SubTitleText = subTitleText;
    update();
}

void Button2::setUnit(const QString &unitStr,const QFont &unitFont,const QColor &unitColor)
{
    UnitText = unitStr;
    UnitFont = unitFont;
    UnitColor = unitColor;
    update();
}

void Button2::updateUnitText(const QString &unitText)
{
    UnitText = unitText;
    update();
}

void Button2::setUnitVisibility(bool vis)
{
    unitVisibility = vis;
    update();
}

void Button2::setButtonRadius(int rad)
{
    ButtonRadius = rad;
    update();
}

void Button2::setBackgroundColor(const QColor &bkColorPressed,const QColor &bkColorUnPressed)
{
    BackgroundColorPressed = bkColorPressed;
    BackgroundColorUnPressed = bkColorUnPressed;
    update();
}

void Button2::setTitle(const QString &titleStr,const QFont &titleFont,const QColor &titleColor)
{
    TitleText = titleStr;
    TitleFont = titleFont;
    TitleColor = titleColor;
    update();
}

void Button2::setLeftRightSpacing(int left,int right)
{
    leftSpace = left;
    rightSpace = right;
    update();
}

void Button2::setSubTitle(const QString &subTitleStr,const QFont &subTitleFont,const QColor &subTitleColor)
{
    SubTitleText = subTitleStr;
    SubTitleFont = subTitleFont;
    SubTitleColor = subTitleColor;
    update();
}

void Button2::setOpacity(const qreal &opace)
{
    opacity = opace;
    update();
}

void Button2::setImageLeft(int x,int y,int w,int h,const QString &fileName)
{
    leftX = x;
    leftY = y;
    leftW = w;
    leftH = h;

    LeftImage.load(fileName);
    update();
}

void Button2::setSwitchHeightWidth(int width,int height)
{
    switchWidget = new Switch(this);
    switchWidget->setGeometry(QRect((rect().width()-(rightSpace/2))-(width/2),((rect().height()/2)-(height/2)),width,height));
    update();
}

/*!
    \class Button2
    \brief On Button pressed event

    \ingroup Widgets
*/
void Button2::mousePressEvent(QMouseEvent *e)
{
    QAbstractButton::mousePressEvent(e);
}

/*!
    \class Button2
    \brief On Button released event


    \ingroup Widgets
*/
void Button2::mouseReleaseEvent(QMouseEvent *e)
{
    QAbstractButton::mouseReleaseEvent(e);
//    animateClick();
}


void Button2::enterEvent(QEvent *e)
{
    QAbstractButton::enterEvent(e);
}

//void Button2::changeEvent(QEvent* e)
//{
//    switch (e->type()) {
//    case QEvent::LanguageChange:
//        //ui->retranslateUi(this);
//        QPaintEvent* ee;
//        paintEvent(ee);
//        break;
//    default:
//        break;

//    }
//}
