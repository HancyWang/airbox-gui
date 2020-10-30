/*!
    \class Button3
    \brief The Button3 class is a button class that contains
    Title,Subtitle,Icon,Arrow

    \ingroup Widgetes
*/

#include <QPainter>
#include <QPainterPath>

#include "button3.h"
#include "constants.h"

Button3::Button3(QWidget *parent) : QAbstractButton(parent)
{

}
Button3::~Button3()
{
//    delete ui;
}

void Button3::paintEvent(QPaintEvent *e) {
    (void)e;
    if (isEnabled()) {
        //Draw Background

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

        if(gradientEffect == true){
            QLinearGradient gradient(rect().x(),rect().y(),rect().x(),rect().height());
            if(isDown()) {
                gradient.setColorAt(0,QColor(GradientColor1));
                gradient.setColorAt(1,QColor(GradientColor0));
                p.fillPath(path,gradient);
            } else {
                gradient.setColorAt(0,QColor(GradientColor0));
                gradient.setColorAt(1,QColor(GradientColor1));
                p.fillPath(path,gradient);
            }
        } else {
            if(isDown()) {
                p.fillPath(path,QColor(GradientColor1));
            } else {
                p.fillPath(path,QColor(GradientColor0));
            }
        }

        p.setOpacity(1.0);
        //Draw Title
        if(!TitleText.isNull())
        {
            p.setPen(TitleColor);
            p.setFont(TitleFont);
            p.drawText(rect().adjusted(0,partitionSpace,0,0), Qt::AlignHCenter | Qt::AlignVCenter,TitleText);
        }

        //Draw Left Images
        if(!Image.isNull())
        {
            p.drawPixmap(((rect().width()/2)-(Image.width()/2)),partitionSpace-Image.height(),Image.width(),Image.height(),Image);
        }
    }
}

void Button3::setButtonRadius(int rad)
{
    ButtonRadius = rad;
    update();
}

void Button3::setBackgroundColor(const QColor &gradColor0,const QColor &gradColor1)
{
    GradientColor0 = gradColor0;
    GradientColor1 = gradColor1;
    update();
}
void Button3::enableGradientEffect(bool stat)
{
    gradientEffect = stat;
}

void Button3::setTitle(const QString &titleStr,const QFont &titleFont,const QColor &titleColor)
{
    TitleText = titleStr;
    TitleFont = titleFont;
    TitleColor = titleColor;
    update();
}

void Button3::setTitleText(const QString &titleText)
{
    TitleText = titleText;
    update();
}

void Button3::setTextSpacing(int textSpace)
{
    partitionSpace = textSpace;
    update();
}

void Button3::setOpacity(const qreal &opace)
{
    opacity = opace;
    update();
}

void Button3::setImage(const QString &fileName)
{
    Image.load(fileName);
    update();
}

/*!
    \class Button3
    \brief On Button pressed event

    \ingroup Widgets
*/
void Button3::mousePressEvent(QMouseEvent *e)
{
    QAbstractButton::mousePressEvent(e);
}

/*!
    \class Button3
    \brief On Button released event

    \ingroup Widgets
*/
void Button3::mouseReleaseEvent(QMouseEvent *e)
{
    QAbstractButton::mouseReleaseEvent(e);
//    animateClick();
}


void Button3::enterEvent(QEvent *e)
{
    QAbstractButton::enterEvent(e);
}


