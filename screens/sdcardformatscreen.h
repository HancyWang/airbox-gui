#ifndef SDCARDFORMATSCREEN_H
#define SDCARDFORMATSCREEN_H

#include <QDialog>
#include <QGraphicsColorizeEffect>

namespace Ui {
class SdCardFormatScreen;
}

class SdCardFormatScreen : public QDialog
{
    Q_OBJECT

public:
    explicit SdCardFormatScreen(QWidget *parent = 0);
    ~SdCardFormatScreen();

    QGraphicsColorizeEffect * parentEffect;
    void updateScreenBeforeShow();
    void changeEvent(QEvent* e);
private slots:
    void on_closeButton_clicked();

private:
    Ui::SdCardFormatScreen *ui;
};

#endif // SDCARDFORMATSCREEN_H
