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

#ifndef WHEELWIDGET_H
#define WHEELWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPaintEvent>


class QPainter;
class QRect;

class AbstractWheelWidget : public QWidget {
    Q_OBJECT

public:
    AbstractWheelWidget(bool touch, QWidget *parent = 0);
    virtual ~AbstractWheelWidget();

    int currentIndex() const;
    void setCurrentIndex(int index);
    void setTextFont(const QFont &fnt);

//    bool event(QEvent*);
    void paintEvent(QPaintEvent *e);
    virtual void paintItem(QPainter* painter, int index, const QRect &rect) = 0;
    virtual void mouseMoveEvent(QMouseEvent *event);

    virtual int itemHeight() const = 0;
    virtual int itemCount() const = 0;

public slots:
    void scrollTo(int index);

signals:
    void stopped(int index);
    void valueChanged();

protected:
    int m_currentItem;
    int m_prevItem=0;
    int m_itemOffset; // 0-itemHeight()
    qreal m_lastY;
    QFont textFont;

    QPoint m_LastPoint;
};

class StringWheelWidget : public AbstractWheelWidget {
    Q_OBJECT

public:
    StringWheelWidget(bool touch,QWidget * parent);

    QStringList items() const;
    void setItems( const QStringList &items );

    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    const QString getItemsAt( int index );

    void paintItem(QPainter* painter, int index, const QRect &rect);

    int itemHeight() const;
    int itemCount() const;

private:
    QStringList m_items;
};

#endif // WHEELWIDGET_H