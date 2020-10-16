#include "ex_variables.h"
#include "ui_activereminderscreen.h"

ActiveReminderScreen::ActiveReminderScreen(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::ActiveReminderScreen),
    parentEffect(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setAttribute(Qt::WA_TranslucentBackground,true);
    setWindowState(Qt::WindowFullScreen);
    move(60,56);
}

ActiveReminderScreen::~ActiveReminderScreen()
{
    delete ui;
}

void ActiveReminderScreen::updateActiveReminderBeforeShow(void)
{
    ui->airFilterText->hide();
    ui->airTubeText->hide();
    ui->maskText->hide();
}

void ActiveReminderScreen::showAirFilterAtIndex(int index)
{
    ui->airFilterText->move(30,widgetYOffset + (index * widgetSize));
    ui->airFilterText->show();
}

void ActiveReminderScreen::showAirTubeAtIndex(int index)
{
    ui->airTubeText->move(30,widgetYOffset + (index * widgetSize));
    ui->airTubeText->show();
}

void ActiveReminderScreen::showMaskAtIndex(int index)
{
    ui->maskText->move(30,widgetYOffset + (index * widgetSize));
    ui->maskText->show();
}

void ActiveReminderScreen::on_resetReminderButton_clicked()
{
    /* Reset reminder date to today's date
     * Show warning screen
     */

    int indexCount=0;
    if(ui->airFilterText->isVisible())
        emit showAirFilterAtIndexResetReminder(indexCount++);

    if(ui->airTubeText->isVisible())
        emit showAirTubeAtIndexResetReminder(indexCount++);

    if(ui->maskText->isVisible())
        emit showMaskAtIndexResetReminder(indexCount);

    emit showResetReminderScreen();
}

void ActiveReminderScreen::closeScreen()
{
    parentEffect->setEnabled(false);
    hide();
}

void ActiveReminderScreen::on_remindLaterButton_clicked()
{
    closeScreen();
}

void ActiveReminderScreen::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
