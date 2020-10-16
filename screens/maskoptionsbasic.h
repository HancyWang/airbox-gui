#ifndef MASKOPTIONSBASIC_H
#define MASKOPTIONSBASIC_H

#include <QDialog>
#include <QPropertyAnimation>

#include "widgets/button4.h"
#include "constants.h"


namespace Ui {
class MaskOptionsBasic;
}

class HomeWindowBasic;
class MaskFitTestOptionsBasic;
class MaskDryOptionsBasic;

class MaskOptionsBasic : public QDialog
{
    Q_OBJECT

public:
    explicit MaskOptionsBasic(QWidget *parent,
                              HomeWindowBasic * m_HomeWindowBackend,
                              MaskFitTestOptionsBasic * maskFitTestOptionBackend,
                              MaskDryOptionsBasic * maskDryOptionBackend);
    ~MaskOptionsBasic();

    void addButtonsMaskFitOptions(void);
    void setButtonProps(Button4 * pButton,const QString &title,const QString &imageLeft,const QString &imageRight,const QString &imageThird);
    void animateMaskOptionsWindow(const openCloseStatus &state);
    void updateMaskOptionsProcessBeforeShow(void);
    void changeEvent(QEvent* e);
    void updateText();
public slots:
    void showMaskOptionsWindowBasic(void);

signals:
    void showMaskFitTestScreen();

    void showMaskDryOptionScreen();

private slots:
    void on_homeMaskOptions_released();
    void maskDryButton_released();
    void maskFitTestButton_released();
    void maskFitTestClosed();

private:
    Ui::MaskOptionsBasic *ui;

    QPropertyAnimation * m_Anim;
    HomeWindowBasic * m_HomeWindow;
    MaskFitTestOptionsBasic * maskFitTestOptionScreen;
    MaskDryOptionsBasic * maskDryOptionScreen;

    Button4 * maskFitTestButton;
    Button4 * maskDryButton;

};

#endif // MASKOPTIONSBASIC_H
