#ifndef BRIGHTNESSOFFSETSCREEN_H
#define BRIGHTNESSOFFSETSCREEN_H


#include <QDialog>
#include <QGraphicsColorizeEffect>

namespace Ui {
class BrightnessOffsetScreen;
}

class BrightnessOffsetScreen : public QDialog
{
    Q_OBJECT

public:
    explicit BrightnessOffsetScreen(QWidget *parent = 0);
    ~BrightnessOffsetScreen();

    QGraphicsColorizeEffect * parentEffect;
    void changeEvent(QEvent* e);
signals:
    void dialogClose();

private slots:
    void on_brightnessOffsetIncrement_pressed();

    void on_brightnessOffsetDecrement_pressed();

    void on_brightnessOffsetAccept_released();

    void on_brightnessOffsetCancel_released();

public slots:
    void showBrightnessOffsetScreen();

private:
    Ui::BrightnessOffsetScreen *ui;

    static int brightnessOffset;
};

#endif // BRIGHTNESSOFFSETSCREEN_H
