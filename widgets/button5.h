#ifndef BUTTON5_H
#define BUTTON5_H

#include <QAbstractButton>

class Button5 : public QAbstractButton
{
//    Q_OBJECT
public:
    explicit Button5(QWidget* parent = nullptr);
    ~Button5();

    void setTitle(const QString &titleStr,const QFont &titleFont,const QColor &titleColor);
    void setValue(const QString &subTitleStr,const QFont &subTitleFont,const QColor &subTitleColor);
    void setUnit(const QString &subTitleStr,const QFont &subTitleFont,const QColor &subTitleColor);
    void setOpacity(const qreal &opace);
    void setBackgroundColor(const QColor &bkColorPressed,const QColor &bkColorUnPressed);
    void setButtonRadius(int rad);
    void updateValueUnitText(const QString &valueStr,const QString &unitStr);

protected:
    void paintEvent(QPaintEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void mousePressEvent(QMouseEvent *) override;
    void enterEvent(QEvent*) override;

private:
    QString TitleText,ValueText,UnitText;
    QFont TitleFont,ValueFont,UnitFont;
    QColor TitleColor,ValueColor,UnitColor;
    QColor BackgroundColorPressed,BackgroundColorUnPressed;
    int leftSpace,rightSpace;
    int ButtonRadius;
    qreal opacity = 0;
};

#endif // BUTTON5_H
