#ifndef PASSWORDCHECKSCREEN_H
#define PASSWORDCHECKSCREEN_H


#include <QDialog>
#include <QGraphicsColorizeEffect>

#define PASSWORD_MAX_CHAR  9

namespace Ui {
class PasswordCheckScreen;
}

class PasswordCheckScreen : public QDialog
{
    Q_OBJECT

public:
    explicit PasswordCheckScreen(QWidget *parent = 0);
    ~PasswordCheckScreen();

    QGraphicsColorizeEffect * parentEffect;

    static int bkupPassword[PASSWORD_MAX_CHAR];
    static int password[PASSWORD_MAX_CHAR];
    static int passwordIndex;
    static int passwordInputIndex;
    bool passwordResult;

    void addDigitInPassword(int number);
    void convertInToString(void);
    void updateWarningText(int state);
    void updatePasswordScreenBeforeShow(void);
    int comparePassword(void);
    void setPassword(const int * localPass);
    void changeEvent(QEvent* e);
public slots:
    void showPasswordEnterScreen(const int *password);

signals:
    void dialogClose();


private slots:
    void on_digit1_pressed();

    void on_digit2_pressed();

    void on_digit3_pressed();

    void on_digit4_pressed();

    void on_digit5_pressed();

    void on_digit6_pressed();

    void on_digit7_pressed();

    void on_digit8_pressed();

    void on_digit9_pressed();

    void on_digit0_pressed();

    void on_backSpace_pressed();

    void on_passwordAccept_released();

    void on_passwordCancel_released();

private:
    Ui::PasswordCheckScreen *ui;
};

#endif // PASSWORDCHECKSCREEN_H
