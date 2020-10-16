/********************************************************************************
** Form generated from reading UI file 'manufacturingdiagnosisscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANUFACTURINGDIAGNOSISSCREEN_H
#define UI_MANUFACTURINGDIAGNOSISSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManufacturingDiagnosisScreen
{
public:
    QLabel *titleManufacturingDiagnosis;
    QPushButton *backManufacturingDiagnosis;
    QScrollArea *scrollAreaDiagnosis;
    QWidget *scrollAreaWidgetContentsDiagnosis;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayoutDiagnosis;
    QFrame *pressureFrame;
    QLabel *pressureTitle;
    QLabel *pressureValue;
    QLabel *pressureUnit;
    QFrame *flowFrame;
    QLabel *floTitle;
    QLabel *flowValue;
    QLabel *flowUnit;
    QFrame *blowerSpeedFBFrame;
    QLabel *blowerFBTitle;
    QLabel *blowerFBValue;
    QLabel *blowerFBUnit;
    QFrame *motorTemFrame;
    QLabel *motorTempTitle;
    QLabel *motorTempValue;
    QLabel *motorTempUnit;
    QFrame *voltageInputFrame;
    QLabel *voltageInputTitle;
    QLabel *voltageInputValue;
    QLabel *voltageInputUnit;
    QFrame *bldcCurrentFrame;
    QLabel *bldcCurrentTitle;
    QLabel *bldcCurrentValue;
    QLabel *bldcCurrentUnit;
    QFrame *lightIntensityFrame;
    QLabel *lightIntensityTitle;
    QLabel *lightIntensityValue;
    QLabel *lightIntensityUnit;
    QPushButton *startBlowerButton;
    QPushButton *incrementBlowerSpeed;
    QPushButton *decrementBlowerSpeed;
    QLabel *faultManufacturingDiagnosis;
    QLabel *titleBlowerSpeed;
    QLabel *valueBlowerSpeed;
    QLabel *unitBlowerSpeed;

    void setupUi(QDialog *ManufacturingDiagnosisScreen)
    {
        if (ManufacturingDiagnosisScreen->objectName().isEmpty())
            ManufacturingDiagnosisScreen->setObjectName(QStringLiteral("ManufacturingDiagnosisScreen"));
        ManufacturingDiagnosisScreen->resize(480, 272);
        ManufacturingDiagnosisScreen->setStyleSheet(QStringLiteral("background-color: rgb(49, 49, 49);"));
        titleManufacturingDiagnosis = new QLabel(ManufacturingDiagnosisScreen);
        titleManufacturingDiagnosis->setObjectName(QStringLiteral("titleManufacturingDiagnosis"));
        titleManufacturingDiagnosis->setGeometry(QRect(83, 29, 271, 25));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(14);
        titleManufacturingDiagnosis->setFont(font);
        titleManufacturingDiagnosis->setStyleSheet(QLatin1String("color:#1788c3\n"
""));
        backManufacturingDiagnosis = new QPushButton(ManufacturingDiagnosisScreen);
        backManufacturingDiagnosis->setObjectName(QStringLiteral("backManufacturingDiagnosis"));
        backManufacturingDiagnosis->setGeometry(QRect(9, 24, 38, 30));
        backManufacturingDiagnosis->setFocusPolicy(Qt::NoFocus);
        backManufacturingDiagnosis->setStyleSheet(QLatin1String("border:none;\n"
"border-radius:3px;\n"
"background-color: rgb(70, 70, 73);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        backManufacturingDiagnosis->setIcon(icon);
        scrollAreaDiagnosis = new QScrollArea(ManufacturingDiagnosisScreen);
        scrollAreaDiagnosis->setObjectName(QStringLiteral("scrollAreaDiagnosis"));
        scrollAreaDiagnosis->setGeometry(QRect(243, 57, 237, 215));
        scrollAreaDiagnosis->setStyleSheet(QLatin1String(" QScrollBar:vertical {\n"
"     border: none;\n"
"     width: 5px;\n"
" }\n"
" QScrollBar::handle:vertical {\n"
"     background:#1788c3;\n"
"     min-height: 20px;\n"
" }\n"
" QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {\n"
"     border: 2px #1788c3;\n"
"     width: 5px;\n"
"     height: 5px;\n"
"     background: #1788c3;\n"
" }"));
        scrollAreaDiagnosis->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollAreaDiagnosis->setWidgetResizable(true);
        scrollAreaWidgetContentsDiagnosis = new QWidget();
        scrollAreaWidgetContentsDiagnosis->setObjectName(QStringLiteral("scrollAreaWidgetContentsDiagnosis"));
        scrollAreaWidgetContentsDiagnosis->setGeometry(QRect(0, 0, 221, 213));
        verticalLayoutWidget = new QWidget(scrollAreaWidgetContentsDiagnosis);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 9, 461, 201));
        verticalLayoutDiagnosis = new QVBoxLayout(verticalLayoutWidget);
        verticalLayoutDiagnosis->setSpacing(5);
        verticalLayoutDiagnosis->setObjectName(QStringLiteral("verticalLayoutDiagnosis"));
        verticalLayoutDiagnosis->setContentsMargins(5, 5, 5, 5);
        pressureFrame = new QFrame(verticalLayoutWidget);
        pressureFrame->setObjectName(QStringLiteral("pressureFrame"));
        pressureFrame->setStyleSheet(QLatin1String("background-color:#3D3D3D;\n"
"border-radius:3px;\n"
""));
        pressureFrame->setFrameShape(QFrame::StyledPanel);
        pressureFrame->setFrameShadow(QFrame::Raised);
        pressureTitle = new QLabel(pressureFrame);
        pressureTitle->setObjectName(QStringLiteral("pressureTitle"));
        pressureTitle->setGeometry(QRect(3, 2, 81, 16));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto Light"));
        font1.setPointSize(10);
        pressureTitle->setFont(font1);
        pressureTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        pressureValue = new QLabel(pressureFrame);
        pressureValue->setObjectName(QStringLiteral("pressureValue"));
        pressureValue->setGeometry(QRect(62, 0, 151, 35));
        QFont font2;
        font2.setFamily(QStringLiteral("Roboto"));
        font2.setPointSize(18);
        font2.setItalic(false);
        pressureValue->setFont(font2);
        pressureValue->setStyleSheet(QStringLiteral("color:#2196F3"));
        pressureValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pressureUnit = new QLabel(pressureFrame);
        pressureUnit->setObjectName(QStringLiteral("pressureUnit"));
        pressureUnit->setGeometry(QRect(3, 20, 61, 16));
        QFont font3;
        font3.setFamily(QStringLiteral("Roboto Light"));
        font3.setPointSize(7);
        pressureUnit->setFont(font3);
        pressureUnit->setStyleSheet(QStringLiteral("color:#616161"));
        pressureUnit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayoutDiagnosis->addWidget(pressureFrame);

        flowFrame = new QFrame(verticalLayoutWidget);
        flowFrame->setObjectName(QStringLiteral("flowFrame"));
        flowFrame->setStyleSheet(QLatin1String("background-color:#3D3D3D;\n"
"border-radius:3px;\n"
""));
        flowFrame->setFrameShape(QFrame::StyledPanel);
        flowFrame->setFrameShadow(QFrame::Raised);
        floTitle = new QLabel(flowFrame);
        floTitle->setObjectName(QStringLiteral("floTitle"));
        floTitle->setGeometry(QRect(3, 2, 81, 16));
        floTitle->setFont(font1);
        floTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        flowValue = new QLabel(flowFrame);
        flowValue->setObjectName(QStringLiteral("flowValue"));
        flowValue->setGeometry(QRect(62, 0, 151, 35));
        flowValue->setFont(font2);
        flowValue->setStyleSheet(QStringLiteral("color:#2196F3"));
        flowValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        flowUnit = new QLabel(flowFrame);
        flowUnit->setObjectName(QStringLiteral("flowUnit"));
        flowUnit->setGeometry(QRect(3, 20, 61, 16));
        flowUnit->setFont(font3);
        flowUnit->setStyleSheet(QStringLiteral("color:#616161"));
        flowUnit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayoutDiagnosis->addWidget(flowFrame);

        blowerSpeedFBFrame = new QFrame(verticalLayoutWidget);
        blowerSpeedFBFrame->setObjectName(QStringLiteral("blowerSpeedFBFrame"));
        blowerSpeedFBFrame->setStyleSheet(QLatin1String("background-color:#3D3D3D;\n"
"border-radius:3px;\n"
""));
        blowerSpeedFBFrame->setFrameShape(QFrame::StyledPanel);
        blowerSpeedFBFrame->setFrameShadow(QFrame::Raised);
        blowerFBTitle = new QLabel(blowerSpeedFBFrame);
        blowerFBTitle->setObjectName(QStringLiteral("blowerFBTitle"));
        blowerFBTitle->setGeometry(QRect(3, 2, 71, 16));
        blowerFBTitle->setFont(font1);
        blowerFBTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        blowerFBValue = new QLabel(blowerSpeedFBFrame);
        blowerFBValue->setObjectName(QStringLiteral("blowerFBValue"));
        blowerFBValue->setGeometry(QRect(72, 0, 141, 35));
        blowerFBValue->setFont(font2);
        blowerFBValue->setStyleSheet(QStringLiteral("color:#2196F3"));
        blowerFBValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        blowerFBUnit = new QLabel(blowerSpeedFBFrame);
        blowerFBUnit->setObjectName(QStringLiteral("blowerFBUnit"));
        blowerFBUnit->setGeometry(QRect(3, 20, 61, 16));
        blowerFBUnit->setFont(font3);
        blowerFBUnit->setStyleSheet(QStringLiteral("color:#616161"));
        blowerFBUnit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayoutDiagnosis->addWidget(blowerSpeedFBFrame);

        motorTemFrame = new QFrame(verticalLayoutWidget);
        motorTemFrame->setObjectName(QStringLiteral("motorTemFrame"));
        motorTemFrame->setStyleSheet(QLatin1String("background-color:#3D3D3D;\n"
"border-radius:3px;\n"
""));
        motorTemFrame->setFrameShape(QFrame::StyledPanel);
        motorTemFrame->setFrameShadow(QFrame::Raised);
        motorTempTitle = new QLabel(motorTemFrame);
        motorTempTitle->setObjectName(QStringLiteral("motorTempTitle"));
        motorTempTitle->setGeometry(QRect(3, 2, 81, 16));
        motorTempTitle->setFont(font1);
        motorTempTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        motorTempValue = new QLabel(motorTemFrame);
        motorTempValue->setObjectName(QStringLiteral("motorTempValue"));
        motorTempValue->setGeometry(QRect(82, 0, 131, 35));
        motorTempValue->setFont(font2);
        motorTempValue->setStyleSheet(QStringLiteral("color:#2196F3"));
        motorTempValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        motorTempUnit = new QLabel(motorTemFrame);
        motorTempUnit->setObjectName(QStringLiteral("motorTempUnit"));
        motorTempUnit->setGeometry(QRect(3, 20, 41, 12));
        motorTempUnit->setFont(font3);
        motorTempUnit->setStyleSheet(QStringLiteral("color:#616161"));
        motorTempUnit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayoutDiagnosis->addWidget(motorTemFrame);

        voltageInputFrame = new QFrame(verticalLayoutWidget);
        voltageInputFrame->setObjectName(QStringLiteral("voltageInputFrame"));
        voltageInputFrame->setStyleSheet(QLatin1String("background-color:#3D3D3D;\n"
"border-radius:3px;\n"
""));
        voltageInputFrame->setFrameShape(QFrame::StyledPanel);
        voltageInputFrame->setFrameShadow(QFrame::Raised);
        voltageInputTitle = new QLabel(voltageInputFrame);
        voltageInputTitle->setObjectName(QStringLiteral("voltageInputTitle"));
        voltageInputTitle->setGeometry(QRect(3, 2, 81, 16));
        voltageInputTitle->setFont(font1);
        voltageInputTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        voltageInputValue = new QLabel(voltageInputFrame);
        voltageInputValue->setObjectName(QStringLiteral("voltageInputValue"));
        voltageInputValue->setGeometry(QRect(82, 0, 131, 35));
        voltageInputValue->setFont(font2);
        voltageInputValue->setStyleSheet(QStringLiteral("color:#2196F3"));
        voltageInputValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        voltageInputUnit = new QLabel(voltageInputFrame);
        voltageInputUnit->setObjectName(QStringLiteral("voltageInputUnit"));
        voltageInputUnit->setGeometry(QRect(3, 20, 41, 12));
        voltageInputUnit->setFont(font3);
        voltageInputUnit->setStyleSheet(QStringLiteral("color:#616161"));
        voltageInputUnit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayoutDiagnosis->addWidget(voltageInputFrame);

        bldcCurrentFrame = new QFrame(verticalLayoutWidget);
        bldcCurrentFrame->setObjectName(QStringLiteral("bldcCurrentFrame"));
        bldcCurrentFrame->setStyleSheet(QLatin1String("background-color:#3D3D3D;\n"
"border-radius:3px;\n"
""));
        bldcCurrentFrame->setFrameShape(QFrame::StyledPanel);
        bldcCurrentFrame->setFrameShadow(QFrame::Raised);
        bldcCurrentTitle = new QLabel(bldcCurrentFrame);
        bldcCurrentTitle->setObjectName(QStringLiteral("bldcCurrentTitle"));
        bldcCurrentTitle->setGeometry(QRect(3, 2, 91, 16));
        bldcCurrentTitle->setFont(font1);
        bldcCurrentTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        bldcCurrentValue = new QLabel(bldcCurrentFrame);
        bldcCurrentValue->setObjectName(QStringLiteral("bldcCurrentValue"));
        bldcCurrentValue->setGeometry(QRect(82, 0, 131, 35));
        bldcCurrentValue->setFont(font2);
        bldcCurrentValue->setStyleSheet(QStringLiteral("color:#2196F3"));
        bldcCurrentValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        bldcCurrentUnit = new QLabel(bldcCurrentFrame);
        bldcCurrentUnit->setObjectName(QStringLiteral("bldcCurrentUnit"));
        bldcCurrentUnit->setGeometry(QRect(3, 20, 41, 12));
        bldcCurrentUnit->setFont(font3);
        bldcCurrentUnit->setStyleSheet(QStringLiteral("color:#616161"));
        bldcCurrentUnit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayoutDiagnosis->addWidget(bldcCurrentFrame);

        lightIntensityFrame = new QFrame(verticalLayoutWidget);
        lightIntensityFrame->setObjectName(QStringLiteral("lightIntensityFrame"));
        lightIntensityFrame->setStyleSheet(QLatin1String("background-color:#3D3D3D;\n"
"border-radius:3px;\n"
""));
        lightIntensityFrame->setFrameShape(QFrame::StyledPanel);
        lightIntensityFrame->setFrameShadow(QFrame::Raised);
        lightIntensityTitle = new QLabel(lightIntensityFrame);
        lightIntensityTitle->setObjectName(QStringLiteral("lightIntensityTitle"));
        lightIntensityTitle->setGeometry(QRect(3, 2, 91, 16));
        lightIntensityTitle->setFont(font1);
        lightIntensityTitle->setStyleSheet(QStringLiteral("color:#BDBDBD"));
        lightIntensityValue = new QLabel(lightIntensityFrame);
        lightIntensityValue->setObjectName(QStringLiteral("lightIntensityValue"));
        lightIntensityValue->setGeometry(QRect(92, 0, 121, 35));
        lightIntensityValue->setFont(font2);
        lightIntensityValue->setStyleSheet(QStringLiteral("color:#2196F3"));
        lightIntensityValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lightIntensityUnit = new QLabel(lightIntensityFrame);
        lightIntensityUnit->setObjectName(QStringLiteral("lightIntensityUnit"));
        lightIntensityUnit->setGeometry(QRect(3, 20, 41, 12));
        lightIntensityUnit->setFont(font3);
        lightIntensityUnit->setStyleSheet(QStringLiteral("color:#616161"));
        lightIntensityUnit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayoutDiagnosis->addWidget(lightIntensityFrame);

        scrollAreaDiagnosis->setWidget(scrollAreaWidgetContentsDiagnosis);
        startBlowerButton = new QPushButton(ManufacturingDiagnosisScreen);
        startBlowerButton->setObjectName(QStringLiteral("startBlowerButton"));
        startBlowerButton->setGeometry(QRect(51, 126, 70, 87));
        QFont font4;
        font4.setPointSize(10);
        startBlowerButton->setFont(font4);
        startBlowerButton->setFocusPolicy(Qt::NoFocus);
        startBlowerButton->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color:#3B3B3B;\n"
"color:#BDBDBD;\n"
"border:none;\n"
"border-radius:3px;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color:#606060;\n"
"color:#BDBDBD;\n"
"border:none;\n"
"border-radius:3px;\n"
"}\n"
""));
        incrementBlowerSpeed = new QPushButton(ManufacturingDiagnosisScreen);
        incrementBlowerSpeed->setObjectName(QStringLiteral("incrementBlowerSpeed"));
        incrementBlowerSpeed->setGeometry(QRect(133, 126, 70, 40));
        incrementBlowerSpeed->setFont(font4);
        incrementBlowerSpeed->setFocusPolicy(Qt::NoFocus);
        incrementBlowerSpeed->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color:#3B3B3B;\n"
"color:#BDBDBD;\n"
"border:none;\n"
"border-radius:3px;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color:#606060;\n"
"color:#BDBDBD;\n"
"border:none;\n"
"border-radius:3px;\n"
"}\n"
""));
        decrementBlowerSpeed = new QPushButton(ManufacturingDiagnosisScreen);
        decrementBlowerSpeed->setObjectName(QStringLiteral("decrementBlowerSpeed"));
        decrementBlowerSpeed->setGeometry(QRect(133, 173, 70, 40));
        decrementBlowerSpeed->setFont(font4);
        decrementBlowerSpeed->setFocusPolicy(Qt::NoFocus);
        decrementBlowerSpeed->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color:#3B3B3B;\n"
"color:#BDBDBD;\n"
"border:none;\n"
"border-radius:3px;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color:#606060;\n"
"color:#BDBDBD;\n"
"border:none;\n"
"border-radius:3px;\n"
"}\n"
""));
        faultManufacturingDiagnosis = new QLabel(ManufacturingDiagnosisScreen);
        faultManufacturingDiagnosis->setObjectName(QStringLiteral("faultManufacturingDiagnosis"));
        faultManufacturingDiagnosis->setGeometry(QRect(3, 245, 235, 25));
        QFont font5;
        font5.setFamily(QStringLiteral("Roboto"));
        font5.setPointSize(10);
        faultManufacturingDiagnosis->setFont(font5);
        faultManufacturingDiagnosis->setStyleSheet(QLatin1String("color:#FFFFFF;\n"
"background-color: rgb(192, 36, 37);\n"
""));
        faultManufacturingDiagnosis->setAlignment(Qt::AlignCenter);
        titleBlowerSpeed = new QLabel(ManufacturingDiagnosisScreen);
        titleBlowerSpeed->setObjectName(QStringLiteral("titleBlowerSpeed"));
        titleBlowerSpeed->setGeometry(QRect(10, 87, 115, 18));
        titleBlowerSpeed->setFont(font5);
        titleBlowerSpeed->setStyleSheet(QLatin1String("color:#BDBDBD\n"
""));
        valueBlowerSpeed = new QLabel(ManufacturingDiagnosisScreen);
        valueBlowerSpeed->setObjectName(QStringLiteral("valueBlowerSpeed"));
        valueBlowerSpeed->setGeometry(QRect(141, 80, 61, 29));
        valueBlowerSpeed->setFont(font);
        valueBlowerSpeed->setStyleSheet(QLatin1String("color:#1788c3\n"
""));
        valueBlowerSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        unitBlowerSpeed = new QLabel(ManufacturingDiagnosisScreen);
        unitBlowerSpeed->setObjectName(QStringLiteral("unitBlowerSpeed"));
        unitBlowerSpeed->setGeometry(QRect(210, 85, 31, 20));
        unitBlowerSpeed->setFont(font5);
        unitBlowerSpeed->setStyleSheet(QLatin1String("color:#666666\n"
""));

        retranslateUi(ManufacturingDiagnosisScreen);

        QMetaObject::connectSlotsByName(ManufacturingDiagnosisScreen);
    } // setupUi

    void retranslateUi(QDialog *ManufacturingDiagnosisScreen)
    {
        ManufacturingDiagnosisScreen->setWindowTitle(QApplication::translate("ManufacturingDiagnosisScreen", "Dialog", nullptr));
        titleManufacturingDiagnosis->setText(QApplication::translate("ManufacturingDiagnosisScreen", "Manufacturing Diagnosis", nullptr));
        backManufacturingDiagnosis->setText(QString());
        pressureTitle->setText(QApplication::translate("ManufacturingDiagnosisScreen", "Pressure", nullptr));
        pressureValue->setText(QString());
        pressureUnit->setText(QApplication::translate("ManufacturingDiagnosisScreen", "ADC/cmH<sub>2</sub>O", nullptr));
        floTitle->setText(QApplication::translate("ManufacturingDiagnosisScreen", "Flow", nullptr));
        flowValue->setText(QString());
        flowUnit->setText(QApplication::translate("ManufacturingDiagnosisScreen", "ADC/LPM", nullptr));
        blowerFBTitle->setText(QApplication::translate("ManufacturingDiagnosisScreen", "Speed FB", nullptr));
        blowerFBValue->setText(QString());
        blowerFBUnit->setText(QApplication::translate("ManufacturingDiagnosisScreen", "kHz/RPM", nullptr));
        motorTempTitle->setText(QApplication::translate("ManufacturingDiagnosisScreen", "Motor Temp.", nullptr));
        motorTempValue->setText(QString());
        motorTempUnit->setText(QApplication::translate("ManufacturingDiagnosisScreen", "ADC/`C", nullptr));
        voltageInputTitle->setText(QApplication::translate("ManufacturingDiagnosisScreen", "Vin", nullptr));
        voltageInputValue->setText(QString());
        voltageInputUnit->setText(QApplication::translate("ManufacturingDiagnosisScreen", "ADC/V", nullptr));
        bldcCurrentTitle->setText(QApplication::translate("ManufacturingDiagnosisScreen", "BLDC Current", nullptr));
        bldcCurrentValue->setText(QString());
        bldcCurrentUnit->setText(QApplication::translate("ManufacturingDiagnosisScreen", "ADC/A", nullptr));
        lightIntensityTitle->setText(QApplication::translate("ManufacturingDiagnosisScreen", "Light Intensity", nullptr));
        lightIntensityValue->setText(QString());
        lightIntensityUnit->setText(QApplication::translate("ManufacturingDiagnosisScreen", "lux", nullptr));
        startBlowerButton->setText(QApplication::translate("ManufacturingDiagnosisScreen", "Start", nullptr));
        incrementBlowerSpeed->setText(QApplication::translate("ManufacturingDiagnosisScreen", "+", nullptr));
        decrementBlowerSpeed->setText(QApplication::translate("ManufacturingDiagnosisScreen", "-", nullptr));
        faultManufacturingDiagnosis->setText(QApplication::translate("ManufacturingDiagnosisScreen", "Fault Condition", nullptr));
        titleBlowerSpeed->setText(QApplication::translate("ManufacturingDiagnosisScreen", "Blower Speed", nullptr));
        valueBlowerSpeed->setText(QString());
        unitBlowerSpeed->setText(QApplication::translate("ManufacturingDiagnosisScreen", "rpm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManufacturingDiagnosisScreen: public Ui_ManufacturingDiagnosisScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANUFACTURINGDIAGNOSISSCREEN_H
