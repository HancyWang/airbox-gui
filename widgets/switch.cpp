#include "switch.h"

/** Default Colors
    _thumb("#d5d5d5"),
    setBrush(QColor("#009688"));
        p.setBrush(QColor("#BDBDBD"));
*/

#define TOGGLE_SWITCH_COLOR     "#1788C3"

#include <QObject>
#include <QAbstractButton>
#include <QPropertyAnimation>
#include <QPainter>
#include <QDebug>

Switch::Switch(QWidget *parent)
    : QAbstractButton(parent),
    _switch(false),
    _opacity(0.000),
    _margin(3),
    _thumb("#d5d5d5"),
    _anim(new QPropertyAnimation(this, "offset", this))
{
    setOffset(height() / 2);
    _y = height() / 2;
    setBrush(QColor(TOGGLE_SWITCH_COLOR));
    connect(this,SIGNAL(clicked(bool)),this,SLOT(processOnClicked(bool)));
}

Switch::Switch(const QBrush &brush, QWidget *parent)
    : QAbstractButton(parent),
    _switch(false),
    _opacity(0.000),
    _margin(3),
    _thumb("#d5d5d5"),
    _anim(new QPropertyAnimation(this, "offset", this))
{
    setOffset(height() / 2);
    _y = height() / 2;
    setBrush(brush);
    connect(this,SIGNAL(clicked(bool)),this,SLOT(processOnClicked(bool)));
}

void Switch::paintEvent(QPaintEvent *e)
{
//    qDebug() << Q_FUNC_INFO << e << _switch << "!!!!!!!!!!";
    QPainter p(this);
    p.setPen(Qt::NoPen);
    if (isEnabled()) {
        p.setBackgroundMode(Qt::TransparentMode);
        p.setBrush(_switch ? brush() : Qt::black);
        p.setOpacity(_switch ? 0.5 : 0.38);
        p.setRenderHint(QPainter::Antialiasing, true);
        p.drawRoundedRect(QRect(_margin, _margin, width() - 2 * _margin, height() - 2 * _margin), 8.0, 8.0);
        p.setBrush(_thumb);
        p.setOpacity(1.0);
        if(_switch == false){
            p.drawEllipse(QRectF(offset() - (height() / 2), _y - (height() / 2), height(), height()));
        } else {
            p.drawEllipse(QRectF(width() - (height()), _y - (height() / 2), height(), height()));
        }
    } else {
        p.setBrush(Qt::black);
        p.setOpacity(0.12);
        p.setRenderHint(QPainter::Antialiasing, true);
        p.drawRoundedRect(QRect(_margin, _margin, width() - 2 * _margin, height() - 2 * _margin), 8.0, 8.0);
        p.setOpacity(1.0);
        p.setBrush(QColor("#BDBDBD"));
        if(_switch == false){
            p.drawEllipse(QRectF(offset() - (height() / 2), _y - (height() / 2), height(), height()));
        } else {
            p.drawEllipse(QRectF(width() - (height()), _y - (height() / 2), height(), height()));
        }
    }
}

void Switch::paint()
{
    QPainter p(this);
    p.setPen(Qt::NoPen);
    if (isEnabled()) {
        p.setBackgroundMode(Qt::TransparentMode);
        p.setBrush(_switch ? brush() : Qt::black);
        p.setOpacity(_switch ? 0.5 : 0.38);
        p.setRenderHint(QPainter::Antialiasing, true);
        p.drawRoundedRect(QRect(_margin, _margin, width() - 2 * _margin, height() - 2 * _margin), 8.0, 8.0);
        p.setBrush(_thumb);
        p.setOpacity(1.0);
        if(_switch == false){
            p.drawEllipse(QRectF(offset() - (height() / 2), _y - (height() / 2), height(), height()));
        } else {
            p.drawEllipse(QRectF(width() - (height()), _y - (height() / 2), height(), height()));
        }
    } else {
        p.setBrush(Qt::black);
        p.setOpacity(0.12);
        p.setRenderHint(QPainter::Antialiasing, true);
        p.drawRoundedRect(QRect(_margin, _margin, width() - 2 * _margin, height() - 2 * _margin), 8.0, 8.0);
        p.setOpacity(1.0);
        p.setBrush(QColor("#BDBDBD"));
        if(_switch == false){
            p.drawEllipse(QRectF(offset() - (height() / 2), _y - (height() / 2), height(), height()));
        } else {
            p.drawEllipse(QRectF(width() - (height()), _y - (height() / 2), height(), height()));
        }
    }
}



bool Switch::getSwitchState(void)
{
    return _switch;
}
void Switch::setSwitchState(bool state)
{
    _switch = state;
    if (_switch == true) {
        _anim->setStartValue(height() / 2);
        _anim->setEndValue(width() - (height() / 2));
        _anim->setDuration(120);
        _anim->start();
    } else {
        _anim->setStartValue(offset());
        _anim->setEndValue(height() / 2);
        _anim->setDuration(120);
        _anim->start();
    }
    update();
}

#include <QEvent>

void Switch::mouseReleaseEvent(QMouseEvent *e)
{
//    qDebug() << Q_FUNC_INFO << e << e->button() << _switch;
//    if (e->button() & Qt::LeftButton)
//    {
//        _switch = _switch ? false : true;
//        _thumb = QBrush("#d5d5d5");
////        _thumb = _switch ? _brush : QBrush("#d5d5d5");
//        if (_switch)
//        {
//            _anim->setStartValue(height() / 2);
//            _anim->setEndValue(width() - (height() / 2));
//            _anim->setDuration(120);
//            _anim->start();
//        }
//        else
//        {
//            _anim->setStartValue(offset());
//            _anim->setEndValue(height() / 2);
//            _anim->setDuration(120);
//            _anim->start();
//        }
//    }
    QAbstractButton::mouseReleaseEvent(e);
}

void Switch::processOnClicked(bool state)
{
//    _switch = state;
//    _switch = _switch ? false : true;

    if(_switch == true)
        _switch = false;
    else
        _switch = true;

    _thumb = QBrush("#d5d5d5");
    if (_switch == true)
    {
        _anim->setStartValue(height() / 2);
        _anim->setEndValue(width() - (height() / 2));
        _anim->setDuration(120);
        _anim->start();
    }
    else
    {
        _anim->setStartValue(offset());
        _anim->setEndValue(height() / 2);
        _anim->setDuration(120);
        _anim->start();
    }

    emit toggleSwitchClicked();
}

void Switch::enterEvent(QEvent *e)
{
//    qDebug() << Q_FUNC_INFO << e;
    setCursor(Qt::PointingHandCursor);
    QAbstractButton::enterEvent(e);
}

QSize Switch::sizeHint() const
{
    return QSize(2 * (height() + _margin), height() + 2 * _margin);
}

void Switch::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        static int count=0;
        qDebug()<<count++;
        //paint();
        break;
    default:
        break;

    }
}
