#ifndef BUTTON2_H
#define BUTTON2_H

#include <QAbstractButton>

#include "switch.h"

class Button2 : public QAbstractButton
{
//    Q_OBJECT
public:
    explicit Button2(QWidget* parent = nullptr);
    ~Button2();
    void setTitle(const QString &titleStr,const QFont &titleFont,const QColor &titleColor);
    void setSubTitle(const QString &subTitleStr,const QFont &subTitleFont,const QColor &subTitleColor);
    void setOpacity(const qreal &opace);
    void setBackgroundColor(const QColor &bkColorPressed,const QColor &bkColorUnPressed);
    void setImageLeft(int x,int y,int w,int h,const QString &fileName);
    void setSwitchHeightWidth(int width,int height);
    void setLeftRightSpacing(int left,int right);
    void setButtonRadius(int rad);
    void updateSubTitleText(const QString &subTitleText);
    void setUnit(const QString &unitStr,const QFont &unitFont,const QColor &unitColor);
    void setUnitVisibility(bool vis);
    void updateUnitText(const QString &unitText);

    Switch * switchWidget;

protected:
    void paintEvent(QPaintEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void mousePressEvent(QMouseEvent *) override;
    void enterEvent(QEvent*) override;
    //void changeEvent(QEvent* e) override;
private:
    QString TitleText,SubTitleText,UnitText;
    QFont TitleFont,SubTitleFont,UnitFont;
    QColor TitleColor,SubTitleColor,UnitColor;
    QColor BackgroundColorPressed,BackgroundColorUnPressed;
    QPixmap LeftImage;
    int leftX,leftY,leftW,leftH;
    int leftSpace,rightSpace;
    int ButtonRadius;
    QRect LeftImageRect;
    qreal opacity = 0;
    bool unitVisibility=false;
};

#endif // BUTTON2_H
