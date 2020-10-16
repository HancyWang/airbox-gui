#ifndef SELECTLANGUAGEWINDOWCLINICAL_H
#define SELECTLANGUAGEWINDOWCLINICAL_H

#include <QDialog>
#include <QGraphicsColorizeEffect>

#include "application.h"

namespace Ui {
class SelectLanguageWindowClinical;
}

class SettingsWindowBasic;
class DataValidation;

class SelectLanguageWindowClinical : public QDialog
{
    Q_OBJECT

public:
    explicit SelectLanguageWindowClinical(QWidget *parent,
                                              SettingsWindowBasic * settingsBasicBackend,
                                              DataValidation * dataValidationBackend);
    ~SelectLanguageWindowClinical();

    void updateLangInLangSelectProcessBeforeShow(void);

    QGraphicsColorizeEffect * parentEffect;
    void changeEvent(QEvent* e);
signals:
    void dialogClose();
    void writeParameterToEeprom(void);

public slots:
    void showSelectLanguageClinicalScreen();

private slots:
    void on_languageAccept_released();

    void on_languageCancel_released();

    void on_english_pressed();

    void on_chinese_pressed();

    void on_japanese_pressed();



public:
    void updateLanguageAfterSelected();

private:
    Ui::SelectLanguageWindowClinical *ui;
    SettingsWindowBasic * settingsBasicScreen;
    DataValidation * dataValidation;

    languageParam localLanguage;
};

#endif // SELECTLANGUAGEWINDOWCLINICAL_H
