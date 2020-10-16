#ifndef DROPDOWNSELECTOR_H
#define DROPDOWNSELECTOR_H

#include <QDialog>

namespace Ui {
class DropDownSelector;
}

class DropDownSelector : public QDialog
{
    Q_OBJECT

public:
    explicit DropDownSelector(QWidget *parent = 0);
    ~DropDownSelector();

    void changeEvent(QEvent* e);
    void updateButton1TextVisible(const QString &str,bool visible);
    void updateButton2TextVisible(const QString &str,bool visible);
    void updateButton3TextVisible(const QString &str,bool visible);
    void updateButton4TextVisible(const QString &str,bool visible);
    void updateButton5TextVisible(const QString &str,bool visible);
    void updateButton6TextVisible(const QString &str,bool visible);
    void setAllButtonsHeight(int height);
    void updateLayoutSize(const QRect &rect);
    int index;

signals:
    void dialogClose();

private slots:
    void on_button1_released();
    void on_button2_released();
    void on_button3_released();
    void on_button4_released();
    void on_button5_released();
    void on_button6_released();

private:
    Ui::DropDownSelector *ui;
};

#endif // DROPDOWNSELECTOR_H
