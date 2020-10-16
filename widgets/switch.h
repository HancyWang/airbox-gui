#ifndef SWITCH_H
#define SWITCH_H

#include <QAbstractButton>
#include <QPropertyAnimation>


class Switch : public QAbstractButton {
    Q_OBJECT
    Q_PROPERTY(int offset READ offset WRITE setOffset)
    Q_PROPERTY(QBrush brush READ brush WRITE setBrush)

public:
    Switch(QWidget* parent = nullptr);
    Switch(const QBrush& brush, QWidget* parent = nullptr);

    QSize sizeHint() const override;

    QBrush brush() const {
        return _brush;
    }
    void setBrush(const QBrush &brsh) {
        _brush = brsh;
    }

    int offset() const {
        return _x;
    }
    void setOffset(int o) {
        _x = o;
        update();
    }

    bool _switch;
    bool getSwitchState(void);
    void setSwitchState(bool state);

    void paint();
signals:
    void toggleSwitchClicked();

public slots:
    void processOnClicked(bool state);
protected:
    void paintEvent(QPaintEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void enterEvent(QEvent*) override;
    void changeEvent(QEvent* e) override;
private:
    qreal _opacity;
    int _x, _y,  _margin;
    QBrush _thumb, _track, _brush;
    QPropertyAnimation *_anim = nullptr;
};

#endif // SWITCH_H
