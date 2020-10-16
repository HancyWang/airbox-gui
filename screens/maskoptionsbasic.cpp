#include "maskoptionsbasic.h"
#include "ui_maskoptionsbasic.h"
#include "ex_variables.h"




MaskOptionsBasic::MaskOptionsBasic(QWidget *parent,
                                   HomeWindowBasic * m_HomeWindowBackend,
                                   MaskFitTestOptionsBasic * maskFitTestOptionBackend,
                                   MaskDryOptionsBasic * maskDryOptionBackend)
    : QDialog(parent),
    ui(new Ui::MaskOptionsBasic),
    m_Anim(nullptr),
    m_HomeWindow(m_HomeWindowBackend),
    maskFitTestOptionScreen(maskFitTestOptionBackend),
    maskDryOptionScreen(maskDryOptionBackend),
    maskFitTestButton(nullptr),
    maskDryButton(nullptr)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setWindowState(Qt::WindowFullScreen);
    setGeometry(0,0,width(),height());

    m_Anim = new QPropertyAnimation(this,"geometry");

    if(m_HomeWindow)
    {
        connect(m_HomeWindow,SIGNAL(showMaskOptionsWindowBasic()),
                this,SLOT(showMaskOptionsWindowBasic()));
    }

    if(maskFitTestOptionScreen)
    {
        connect(this,SIGNAL(showMaskFitTestScreen()),
                maskFitTestOptionScreen,SLOT(showMaskFitTestScreen()));
    }

    if(maskDryOptionScreen)
    {
        connect(this,SIGNAL(showMaskDryOptionScreen()),
                maskDryOptionScreen,SLOT(showMaskDryOptionScreen()));
    }

    addButtonsMaskFitOptions();

    QFont title("Roboto-Light",12);
    ui->titleMaskOptions->setFont(title);

    updateMaskOptionsProcessBeforeShow();

    this->maskFitTestButton->hide();
}

MaskOptionsBasic::~MaskOptionsBasic()
{
    delete ui;
}

void MaskOptionsBasic::updateMaskOptionsProcessBeforeShow(void)
{
    maskFitTestButton->setImageThird(Providers::getEmojiIconString(globalVar.maskFitTest.maskFitTestStatus));
}

void MaskOptionsBasic::showMaskOptionsWindowBasic()
{
    updateMaskOptionsProcessBeforeShow();
    animateMaskOptionsWindow(Open);
}

void MaskOptionsBasic::animateMaskOptionsWindow(const openCloseStatus &state)
{
    if (state) {
        this->show();
        m_Anim->setStartValue(QRect(480, 0, 480, 272));
        m_Anim->setEndValue(QRect(0, 0, 480, 272));
        m_Anim->setDuration(WINDOW_ANIMATION_OPEN_DURATION);
        m_Anim->setEasingCurve(WINDOW_OPEN_TRANSITION);
        connect(m_Anim, SIGNAL(finished()),SLOT(show()));
    } else {
        m_Anim->setStartValue(QRect(0, 0, 480, 272));
        m_Anim->setEndValue(QRect(480, 0, 480, 272));
        m_Anim->setDuration(WINDOW_ANIMATION_CLOSE_DURATION);
        m_Anim->setEasingCurve(WINDOW_CLOSE_TRANSITION);
        connect(m_Anim, SIGNAL(finished()),SLOT(hide()));
    }
    m_Anim->start();
}

void MaskOptionsBasic::addButtonsMaskFitOptions(void)
{
    maskDryButton = new Button4(this);
    maskDryButton->setGeometry(QRect(60,63,330,50));
//    maskDryButton->setGeometry(QRect(60,118,330,50));
    setButtonProps(maskDryButton,Providers::getTitleTextString(MASK_DRY_STR),Providers::getIconString(MASK_DRY_ICON),Providers::getNavigationIconString(),NULL);
    connect(maskDryButton, SIGNAL(released()),SLOT(maskDryButton_released()));

    maskFitTestButton = new Button4(this);
    maskFitTestButton->setGeometry(QRect(60,63,330,50));
    setButtonProps(maskFitTestButton,Providers::getTitleTextString(MASK_FIT_TEST_STR),Providers::getIconString(MASK_FIT_TEST_ICON),Providers::getNavigationIconString(),":/icons/good_icon.png");
    connect(maskFitTestButton, SIGNAL(released()),SLOT(maskFitTestButton_released()));
}

void MaskOptionsBasic::setButtonProps(Button4 * pButton,const QString &title,const QString &imageLeft,const QString &imageRight,const QString &imageThird)
{
    QFont fontTitle("Roboto-Light", 8);

    pButton->setButtonRadius(5);
    pButton->setTitle(title,fontTitle,QColor(0xBDBDBD));
    pButton->setBackgroundColor(0x606060,0x3e3e3e);
    pButton->setLeftRightSpacing(50,50,150);
    pButton->setImageLeft(imageLeft);
    pButton->setImageRight(imageRight);
    pButton->setImageThird(imageThird);
}

void MaskOptionsBasic::on_homeMaskOptions_released()
{
    animateMaskOptionsWindow(Close);
}

void MaskOptionsBasic::maskFitTestButton_released(void)
{
    connect(maskFitTestOptionScreen, SIGNAL(dialogClose()),
            this,SLOT(maskFitTestClosed()));

    emit showMaskFitTestScreen();
}

void MaskOptionsBasic::maskFitTestClosed()
{
    updateMaskOptionsProcessBeforeShow();
}

void MaskOptionsBasic::maskDryButton_released(void)
{
    emit showMaskDryOptionScreen();
}

void MaskOptionsBasic::updateText()
{
    setButtonProps(maskDryButton,Providers::getTitleTextString(MASK_DRY_STR),Providers::getIconString(MASK_DRY_ICON),Providers::getNavigationIconString(),NULL);
    setButtonProps(maskFitTestButton,Providers::getTitleTextString(MASK_FIT_TEST_STR),Providers::getIconString(MASK_FIT_TEST_ICON),Providers::getNavigationIconString(),":/icons/good_icon.png");
}

void MaskOptionsBasic::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        updateText();
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
