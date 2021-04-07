#ifndef LEAKAGEOPTION_H
#define LEAKAGEOPTION_H

#include <QDialog>
#include <QTimer>
#include <QGraphicsColorizeEffect>

namespace Ui {
class LeakageOption;
}

class LeakageOption : public QDialog
{
    Q_OBJECT

public:
    explicit LeakageOption(QWidget *parent = nullptr);
    ~LeakageOption();

    void updateText();
    void changeEvent(QEvent* e);
private slots:
    void on_leakageBtnOK_released();
    void leakageTimerTimeout();

public slots:
    void show_leak_msg(QString msg);


private:
    Ui::LeakageOption *ui;
    QTimer* leakageTimer;
    QString leakageMsg;

    void show_ui(bool b_show);

public:
    QGraphicsColorizeEffect * parentEffect;

};

#endif // LEAKAGEOPTION_H
