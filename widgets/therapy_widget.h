#ifndef THERAPYWIDGET_H
#define THERAPYWIDGET_H


#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

class TherapyWidget : public QWidget
{
//    Q_OBJECT
public:
    explicit TherapyWidget(QWidget* parent = nullptr);
    ~TherapyWidget();

    void setTitleProperties(const QString &text,const QFont &font,const QString &styleSheet);
    void setUnitProperties(const QString &unitStr,const QFont &font,const QString &styleSheet);
    void setPressureValue(int val);
    void setValueProperties(const QFont &font,const QString &styleSheet);
    void setSubValueProperties(const QFont &font,const QString &styleSheet);
    void setSubValue(int val);
    void setLeftRightAngles(int left,int right);
    void setBarSize(int size);
    void setPressure(int pres);
    void setBlankBarColor(QColor color);
    void setFillBarColor(QColor color);
    void setFillBarVisibleState(bool state);
    void setmaxPressure(int max);
    void setLayoutGeometry(const QRect &rec);

    int getPressure(void);


protected:
    void paintEvent(QPaintEvent*) override;

private:
    void initialize();

    QVBoxLayout * layout;
    QLabel * title;
    QLabel * value;
    QLabel * unit;
    QLabel * subValue;
    bool fillBarVisibility;
    int maxPressure;
    QString TitleText,UnitText,ValueText,Value2Text;
    QFont TitleFont,UnitFont,ValueFont,Value2Font;
    QColor TitleColor,UnitColor,ValueColor,Value2Color;
    QColor fillBarColor,blankBarColor;
    int leftAngle,rightAngle;
    int pressure=-1,value2;
    int barSize;
    int subValueInt;
    qreal opacity = 0;

    int visiblePressure=0;

};

#endif // THERAPYWIDGET_H
