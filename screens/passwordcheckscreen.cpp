#include "passwordcheckscreen.h"
#include "ui_passwordcheckscreen.h"



int PasswordCheckScreen::bkupPassword[PASSWORD_MAX_CHAR] = {0};
int PasswordCheckScreen::password[PASSWORD_MAX_CHAR] = {0};
int PasswordCheckScreen::passwordIndex = 0;
int PasswordCheckScreen::passwordInputIndex = 0;


PasswordCheckScreen::PasswordCheckScreen(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::PasswordCheckScreen),
    parentEffect(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setAttribute(Qt::WA_TranslucentBackground,true);
    move(64,6);

    QFont title("Roboto-Light",9);
    ui->passwordTitle->setFont(title);
    ui->passwordWarning->hide();
    passwordInputIndex = 0;
}

PasswordCheckScreen::~PasswordCheckScreen()
{
    delete ui;
}

void PasswordCheckScreen::on_digit1_pressed()
{
    /* Add 1 in buffer */
    addDigitInPassword(1);
}

void PasswordCheckScreen::on_digit2_pressed()
{
    /* Add 2 in buffer */
    addDigitInPassword(2);
}

void PasswordCheckScreen::on_digit3_pressed()
{
    /* Add 3 in buffer */
    addDigitInPassword(3);
}

void PasswordCheckScreen::on_digit4_pressed()
{
    /* Add 4 in buffer */
    addDigitInPassword(4);
}

void PasswordCheckScreen::on_digit5_pressed()
{
    /* Add 5 in buffer */
    addDigitInPassword(5);
}

void PasswordCheckScreen::on_digit6_pressed()
{
    /* Add 6 in buffer */
    addDigitInPassword(6);
}

void PasswordCheckScreen::on_digit7_pressed()
{
    /* Add 7 in buffer */
    addDigitInPassword(7);
}

void PasswordCheckScreen::on_digit8_pressed()
{
    /* Add 8 in buffer */
    addDigitInPassword(8);
}

void PasswordCheckScreen::on_digit9_pressed()
{
    /* Add 9 in buffer */
    addDigitInPassword(9);
}

void PasswordCheckScreen::on_digit0_pressed()
{
    /* Add 0 in buffer */
    addDigitInPassword(0);
}

void PasswordCheckScreen::on_backSpace_pressed()
{
    /* Check if entered number of digit
     * if gerater than one[1].
     */
    if(passwordIndex > 0)
    {
        /* Decrement index & remove that digit from buffer */
        passwordIndex--;
        password[passwordIndex] = 0;

        /* Update string to display in editor */
        convertInToString();
    }
}


void PasswordCheckScreen::on_passwordAccept_released()
{
int res=0;

    /* Clear text edit widget */
    ui->passwordText->setText("");

    /* Check if entered total number of digits
     * are equal to maximum digits of password
     */
    if(passwordIndex < PASSWORD_MAX_CHAR)
    {
        /* If entered digit are lower than total character
         * discard those digit & show error on screen
         */
        passwordIndex = 0;
        passwordInputIndex = 0;
        ui->passwordWarning->show();
        memset(password,0,sizeof(password));
    }
    else
    {
        /* If entered digit are equal to total character
         * check if entered index is 0 future improvements
         */
        if(!passwordInputIndex)
        {

            /* If input index is 0 Compare pass with provided one
             */
            passwordInputIndex = 0;
            passwordIndex = 0;

            res = comparePassword();
            if(!res)
            {
                /* If password matches update the result & close screen
                 * Emit window close signal
                 */
                passwordResult = true;
                emit dialogClose();
                parentEffect->setEnabled(false);
                hide();
                setModal(false);
                disconnect(this, SIGNAL(dialogClose()),0,0);
            }
            else
            {
                /* If password does not match than show warning
                 * and reset buffer array
                 */
                ui->passwordWarning->show();
                memset(password,0,sizeof(password));
            }
        }
    }
}

int PasswordCheckScreen::comparePassword(void)
{
int i=0;
    /* Loop to verify passsword entered with provided */
    for(i=0; i<PASSWORD_MAX_CHAR ; i++)
    {
        if(bkupPassword[i] != password[i])
        {
            /* If any character is invalid
             * return with error
             */
            return -1;
        }
    }
return 0;
}

void PasswordCheckScreen::on_passwordCancel_released()
{
    /* Discard all entered data and return to previous screen */
    passwordInputIndex = 0;
    parentEffect->setEnabled(false);
    hide();
    setModal(false);
    disconnect(this, SIGNAL(dialogClose()),0,0);
}

void PasswordCheckScreen::addDigitInPassword(int number)
{
    /* Check if current index number is less than maximum allowed
     * password characters
     */
    if(passwordIndex < PASSWORD_MAX_CHAR)
    {
        /* Update character to buffer */
        password[passwordIndex] = number;
        passwordIndex++;
    }

    /* Modify & update to password edit widget on screen */
    convertInToString();
}

void PasswordCheckScreen::convertInToString(void)
{
    QString serialStr = "";
    for(int i=0; i<passwordIndex ; i++)
    {
        /* Convert all the integers to characters
         * Loop to append all the characters to string
         */
        serialStr += QString::number(password[i]);
    }
    /* Update updated password string to screen
     * & hide warning text
     */
    ui->passwordText->setText(serialStr);
    ui->passwordWarning->hide();
}

void PasswordCheckScreen::updatePasswordScreenBeforeShow(void)
{
    /* Update parameters before showing screen */
    passwordResult = false;
    passwordIndex = 0;
    passwordInputIndex = 0;
    memset(password,0,sizeof(password));
    memset(bkupPassword,0,sizeof(bkupPassword));

    ui->passwordWarning->hide();
    ui->passwordText->setText("");
}

void PasswordCheckScreen::setPassword(const int * localPass)
{
    /* Password must be maximum PASSWORD_MAX_CHAR character  */
    memcpy(bkupPassword,localPass,sizeof(bkupPassword));
}

void PasswordCheckScreen::showPasswordEnterScreen(const int * password)
{
    parentEffect->setEnabled(true);
    setModal(true);
    updatePasswordScreenBeforeShow();
    setPassword(password);
    show();
}

void PasswordCheckScreen::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
