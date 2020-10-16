#ifndef BUTTON4_H
#define BUTTON4_H

#include <QAbstractButton>

class Button4 : public QAbstractButton
{
//    Q_OBJECT
public:
    explicit Button4(QWidget* parent = nullptr);
    ~Button4();
    void setTitle(const QString &titleStr,const QFont &titleFont,const QColor &titleColor);
    void setOpacity(const qreal &opace);
    void setBackgroundColor(const QColor &bkColorPressed,const QColor &bkColorUnPressed);
    void setImageLeft(const QString &fileName);
    void setImageRight(const QString &fileName);
    void setImageThird(const QString &fileName);
    void setLeftRightSpacing(int left,int right,int third);
    void setButtonRadius(int rad);

protected:
    void paintEvent(QPaintEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void mousePressEvent(QMouseEvent *) override;
    void enterEvent(QEvent*) override;

private:
    QString TitleText;
    QFont TitleFont;
    QColor TitleColor;
    QColor BackgroundColorPressed,BackgroundColorUnPressed;
    QPixmap LeftImage,RightImage,ThirdImage;
    int leftX,leftY,leftW,leftH;
    int rightX,rightY,rightW,rightH;
    int leftSpace,rightSpace,thirdSpace;
    int ButtonRadius;
    QRect LeftImageRect,RightImageRect;
    qreal opacity = 0;
};

#endif // BUTTON4_H
