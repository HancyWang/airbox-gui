#ifndef BUTTON3_H
#define BUTTON3_H

#include <QAbstractButton>

class Button3 : public QAbstractButton
{
//    Q_OBJECT
public:
    explicit Button3(QWidget* parent = nullptr);
    ~Button3();
    void setTitle(const QString &titleStr,const QFont &titleFont,const QColor &titleColor);
    void setOpacity(const qreal &opace);
    void setBackgroundColor(const QColor &gradColor0,const QColor &gradColor1);
    void setImage(const QString &fileName);
    void setTextSpacing(int textSpace);
    void setButtonRadius(int rad);
    void setTitleText(const QString &titleText);
    void enableGradientEffect(bool stat);

protected:
    void paintEvent(QPaintEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void mousePressEvent(QMouseEvent *) override;
    void enterEvent(QEvent*) override;
    //void changeEvent(QEvent* e) override;

private:
    QString TitleText;
    QFont TitleFont;
    QColor TitleColor;
    QColor GradientColor0,GradientColor1;
    QPixmap Image;
    int partitionSpace;
    int ButtonRadius;
    qreal opacity = 0;
    bool gradientEffect=false;
};

#endif // BUTTON3_H
