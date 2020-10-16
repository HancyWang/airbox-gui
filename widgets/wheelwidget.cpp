/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QPainter>
#include <QScroller>

#include "wheelwidget.h"
#include <QDebug>

#define WHEEL_SCROLL_OFFSET 50000.0

AbstractWheelWidget::AbstractWheelWidget(bool touch, QWidget *parent)
    : QWidget(parent)
    , m_currentItem(0)
    , m_itemOffset(0)
{
// ![0]
//    QScroller::grabGesture(this, touch ? QScroller::TouchGesture : QScroller::LeftMouseButtonGesture);
//    setAttribute(Qt::WA_AcceptTouchEvents);
//    installEventFilter(this);
    QScroller::grabGesture(this, QScroller::TouchGesture);
//    QScroller::grabGesture(this, QScroller::LeftMouseButtonGesture);
// ![0]
}

AbstractWheelWidget::~AbstractWheelWidget()
{ }

int AbstractWheelWidget::currentIndex() const
{
    return m_currentItem;
}

void AbstractWheelWidget::setCurrentIndex(int index)
{
    if (index >= 0 && index < itemCount())
    {
        m_currentItem = index;
        m_itemOffset = 0;
        update();
    }
}

void AbstractWheelWidget::mouseMoveEvent(QMouseEvent *event)
{

//        int activeItemY = m_currentItem * itemHeight();
        int minActive = m_LastPoint.y() - itemHeight();
        int maxActive = m_LastPoint.y() + itemHeight();

        if((event->y() < minActive)
            | (event->y() > maxActive))
        {
//            qDebug() << Q_FUNC_INFO << m_LastPoint << event->pos() << itemHeight() << itemCount();
            m_LastPoint = event->pos();

            if(event->y() < minActive)
            {
                if(m_currentItem < (itemCount() - 1))
                    m_currentItem++;
            }
            else
            {
                if(m_currentItem > 0)
                    m_currentItem--;
            }
            // -- repaint
            update();
        }

}

//bool AbstractWheelWidget::event(QEvent *e)
//{

////    qDebug() << Q_FUNC_INFO << e;
//    switch (e->type()) {

////    case QEvent::MouseButtonPress:
////        setFocus();
////        qDebug() << Q_FUNC_INFO << QScroller::scroller(this) << QScroller::grabGesture(this, QScroller::TouchGesture);
////        break;

//// ![1]
//    case QEvent::ScrollPrepare:
//    {
//        // We set the snap positions as late as possible so that we are sure
//        // we get the correct itemHeight
//        QScroller *scroller = QScroller::scroller(this);
//        scroller->setSnapPositionsY( WHEEL_SCROLL_OFFSET, itemHeight() );

//        QScrollPrepareEvent *se = static_cast<QScrollPrepareEvent *>(e);
//        se->setViewportSize(QSizeF(size()));
//        // we claim a huge scrolling area and a huge content position and
//        // hope that the user doesn't notice that the scroll area is restricted
//        se->setContentPosRange(QRectF(0.0, 0.0, 0.0, WHEEL_SCROLL_OFFSET * 2));
//        se->setContentPos(QPointF(0.0, WHEEL_SCROLL_OFFSET + m_currentItem * itemHeight() + m_itemOffset));
//        se->accept();

//        if((isVisible() == false) & (se->isAccepted() == true))
//        {
//            qDebug() << Q_FUNC_INFO << e << "Accepted";
//            se->setAccepted(false);
//        }

//        return true;
////        break;
//    }
//// ![1]
//// ![2]
////    case QEvent::MouseMove:
//    case QEvent::Scroll:
//    {
//        QScrollEvent *se = static_cast<QScrollEvent *>(e);

//        if((isVisible() == false) & (se->isAccepted() == true))
//        {
//            qDebug() << Q_FUNC_INFO << e << "Accepted";
//            se->setAccepted(false);
//        }

//        qreal y = se->contentPos().y();
//        int iy = y - WHEEL_SCROLL_OFFSET;
//        int ih = itemHeight();

//// ![2]
//// ![3]
//        // -- calculate the current item position and offset and redraw the widget
//        int ic = itemCount();
//        if (ic>0) {
//            m_currentItem = iy / ih % ic;
//            m_itemOffset = iy % ih;

//            // take care when scrolling backwards. Modulo returns negative numbers
//            if (m_itemOffset < 0) {
//                m_itemOffset += ih;
//                m_currentItem--;
////                qDebug() << Q_FUNC_INFO << "--->" << m_currentItem << m_itemOffset << ih ;
//            }

////            if((m_currentItem + 1) >= ic){
////                m_currentItem = ic - 1;
////                qDebug() << Q_FUNC_INFO << "===>" << m_currentItem << ic ;
////            }

////            qDebug() << Q_FUNC_INFO << m_currentItem << m_prevItem << m_itemOffset << iy << ih << ic << y;
//            if (m_currentItem < 0)
//                m_currentItem += ic;


//            int totalHeight=ih * ic;
//            if(iy > totalHeight) {
////                qDebug() << Q_FUNC_INFO << "===>" << m_currentItem << iy << ih;
//                m_currentItem = ic - 1;
////                m_currentItem = 0;
////                m_itemOffset = ic * ih;
//            }

//            if(m_prevItem != m_currentItem){
////                qDebug() << Q_FUNC_INFO << "Mismatch" << m_currentItem << m_prevItem << m_itemOffset << iy << ih;
//                m_prevItem = m_currentItem;
//                emit valueChanged();
//            }

//        }
//        // -- repaint
//        update();

//        se->accept();
//        return true;
////        break;
//// ![3]
//    }
////    default:
////        return QWidget::event(e);
//    }
////    return true;
//    return QWidget::event(e);
//}

void AbstractWheelWidget::paintEvent(QPaintEvent* event)
{
    Q_UNUSED( event );

    // -- first calculate size and position.
    int w = width();
    int h = height();

    QPainter painter(this);

    // linear gradient brush
    QLinearGradient grad(0.5, 0, 0.5, 1.0);
    grad.setColorAt(0, Qt::black);
    grad.setColorAt(0.2,QColor(0xC0C0C0));
    grad.setColorAt(0.8,QColor(0xC0C0C0));
    grad.setColorAt(1, Qt::black);
    grad.setCoordinateMode( QGradient::ObjectBoundingMode );
    QBrush gBrush( grad );

    // paint a border and background
    painter.setPen(Qt::black);
    painter.setBrush(gBrush);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.drawRoundedRect(QRect(0, 0, w-1, h-1),3,3);

    QLinearGradient grad2(0.5, 0, 0.5, 1.0);
    grad2.setColorAt(0, QColor(0x1788C3));
    grad2.setColorAt(1.0, QColor(0x053C8D));
    grad2.setCoordinateMode( QGradient::ObjectBoundingMode );
    QBrush gBrush2( grad2 );

    int iH = itemHeight();
    int iC = itemCount();
    int y_index = 0;

    // paint the items
    painter.setClipRect( QRect( 3, 3, w-6, h-6 ) );
    painter.setPen(Qt::black);
    painter.fillRect( QRect( 0, h/2 - iH/2,        w, iH ), gBrush2 );

    if (iC > 0)
    {
        int drawCount = 5;
//        int drawCount = height() / itemHeight() + 1;

        int iStartPoint = drawCount * itemHeight();

        if(iStartPoint > height())
        {
            iStartPoint = iStartPoint - height();
            iStartPoint = iStartPoint / 2;
        }

        painter.setFont(textFont);
        int activeValue =0;
        activeValue = (drawCount/2);
        activeValue = drawCount - activeValue;

        if((drawCount % 2) != 0)
            activeValue = activeValue - 1;

        int localIndex=0;
        for(int i=-activeValue ; i<(activeValue + 1); i++)
        {
            int itemNum = m_currentItem + i;
            y_index = (localIndex * iH ) - iStartPoint;
            localIndex++;

            if(i == 0)
            {
                painter.setPen(Qt::black);
            }
            else
            {
                painter.setPen(QColor(0x808080));
            }

            if(((m_currentItem + i) >= 0) & ((m_currentItem + i) < itemCount()))
            {
                paintItem(&painter, itemNum, QRect(6,y_index, w-6, iH ));
            }
//            qDebug() << i << itemNum << y_index << iH << activeValue << m_currentItem;
        }
    }

//        if (iC > 0)
//        {
//            m_itemOffset = m_itemOffset % iH;
//            painter.setFont(textFont);
//            for (int i=-h/2/iH; i<=h/2/iH+1; i++)
//            {
//                int itemNum = m_currentItem + i;
//                y_index =  h/2 +i*iH - m_itemOffset - iH/2;

//                if(i == 0){
//                    painter.setPen(Qt::black);
//                } else {
//                    painter.setPen(QColor(0x808080));
//                }
//                if(((m_currentItem + i) >= 0) & ((m_currentItem + i) < itemCount()))
//                {
//                    paintItem(&painter, itemNum, QRect(6,y_index, w-6, iH ));
//                }
////                qDebug() << i << m_currentItem;
//            }
//        }
}
/*!
    Rotates the wheel widget to a given index.
    You can also give an index greater than itemCount or less than zero in which
    case the wheel widget will scroll in the given direction and end up with
    (index % itemCount)
*/
void AbstractWheelWidget::scrollTo(int index)
{
    QScroller *scroller = QScroller::scroller(this);

    scroller->scrollTo(QPointF(0, WHEEL_SCROLL_OFFSET + index * itemHeight()), 5000);
}

void AbstractWheelWidget::setTextFont(const QFont &fnt)
{
    this->textFont = fnt;
}

/*!
    \class StringWheelWidget
    \brief The StringWheelWidget class is an implementation of the AbstractWheelWidget class that draws QStrings as items.
    \sa AbstractWheelWidget
*/

StringWheelWidget::StringWheelWidget(bool touch,QWidget * parent)
    : AbstractWheelWidget(touch,parent)
{ }

QStringList StringWheelWidget::items() const
{
    return m_items;
}

void StringWheelWidget::setItems( const QStringList &items )
{
    m_items = items;
    if (m_currentItem >= items.count())
        m_currentItem = items.count()-1;
    update();
}

const QString StringWheelWidget::getItemsAt( int index )
{
    return m_items.at(index);
}

QSize StringWheelWidget::sizeHint() const
{
    // determine font size
    QFontMetrics fm(textFont);

    return QSize( fm.width("m") * 10 + 6, fm.height() * 7 + 6 );
}

QSize StringWheelWidget::minimumSizeHint() const
{
    QFontMetrics fm(textFont);

    return QSize( fm.width("m") * 5 + 6, fm.height() * 3 + 6 );
}

void StringWheelWidget::paintItem(QPainter* painter, int index, const QRect &rect)
{
    painter->drawText(rect, Qt::AlignCenter, m_items.at(index));
}

int StringWheelWidget::itemHeight() const
{
    QFontMetrics fm(textFont);
    return fm.height();
}

int StringWheelWidget::itemCount() const
{
    return m_items.count();
}
