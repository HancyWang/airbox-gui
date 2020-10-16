#ifndef BUTTON1_H
#define BUTTON1_H

#include <QAbstractButton>

class Button1 : public QAbstractButton
{
//    Q_OBJECT
public:
    explicit Button1(QWidget* parent = nullptr);
    ~Button1();
    void setTitle(const QString &titleStr,const QFont &titleFont,const QColor &titleColor);
    void setSubTitle(const QString &subTitleStr,const QFont &subTitleFont,const QColor &subTitleColor);
    void setUnit(const QString &unitStr,const QFont &unitFont,const QColor &unitColor);
    void setOpacity(const qreal &opace);
    void setBackgroundColor(const QColor &bkColorPressed,const QColor &bkColorUnPressed);
    void setImageLeft(int x,int y,int w,int h,const QString &fileName);
    void setImageRight(int x,int y,int w,int h,const QString &fileName);
    void setLeftRightSpacing(int left,int right);
    void setButtonRadius(int rad);
    void updateSubTitleText(const QString &subTitleText);
    void updateTitleText(const QString &titleText);
    void updateUnitText(const QString &unitText);
    void setUnitVisibility(bool vis);

protected:
    void paintEvent(QPaintEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void mousePressEvent(QMouseEvent *) override;
    void enterEvent(QEvent*) override;

private:
    QString TitleText,SubTitleText,UnitText;
    QFont TitleFont,SubTitleFont,UnitFont;
    QColor TitleColor,SubTitleColor,UnitColor;
    QColor BackgroundColorPressed,BackgroundColorUnPressed;
    QPixmap LeftImage,RightImage;
    int leftX,leftY,leftW,leftH;
    int rightX,rightY,rightW,rightH;
    int leftSpace,rightSpace;
    int ButtonRadius;
    QRect LeftImageRect,RightImageRect;
    qreal opacity = 0;
    bool unitVisibility=false;
};

#endif // BUTTON1_H
