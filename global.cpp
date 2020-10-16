#include "global.h"
#include "ex_variables.h"

#include <QtMath>

Providers::Providers()
{

}

const QStringList Providers::onOffText = {
    "Off",
    "On",
};
const QString & Providers::getOnOffStr(int index) {
    if(index >= onOffText.count()){
        qWarning() << Q_FUNC_INFO << "Invalid count" << index;
        index = 0;
    }
    return onOffText.at(index);
}

const QString Providers::autoStrText = "Auto";
const QString & Providers::getAutoStr() {
    return autoStrText;
}

const QStringList Providers::levelStrText = {
    "Level 1",
    "Level 2",
    "Level 3",
    "Level 4",
    "Level 5"
};
const QString & Providers::getlevelStr(int index) {
    if(index >= levelStrText.count()){
        qWarning() << Q_FUNC_INFO << "Invalid count" << index;
        index = 0;
    }
    return levelStrText.at(index);
}


const QStringList Providers::titleTextList_EN = {
    "Therapy",
    "Sleep Report",
    "Mask Options",
    "Settings",
    "Mask Fit Test",
    "Mask Dry",
    "GoTo Sleep",
    "Ramp",
    "Comfort Level",
    "Auto Therapy",
    "Mask",
    "Hose",                 //"Tube",
    "Airplane Mode",
    "Bluetooth",
    "Snooze",
    "Power Savings",
    "Display Settings",
    "Device Info",
    "Brightness",
    "Display Dim Duration",
    "Comfort",
    "Accessories",
    "Options",
    "Reminders",
    "Configurations",
    "Mode",
    "Set Pressure",
    "Set Min Pressure",
    "Set Max Pressure",
    "Exhale Pressure Comfort",
    "Hose",//"Air Tube",
    "Air Filter",
    "Auto Start Therapy",
    "Sleep Lab Titration Mode",
    "Language",
    "Date",
    "Time",
    "Pressure Unit",
    "Diagnostic Data",
    "Restore Defaults",
    "Erase Data",
    "Power Off",
    "Manufacturing Option",
    "Manufacturing Diagnosis",
    "Manufacturing Setup",
    "Blower Test Application",
    "Parameter Tune",
    "English",
    "Chinese",
    "Japanese"
};


const QStringList Providers::titleTextList_ZH = {
    "治疗",
    "睡眠报告",
    "面罩选项",
    "设置",
    "面罩适配测试",
    "烘干面罩",
    "睡眠",
    "爬坡",
    "舒适等级",
    "自动治疗",
    "面罩",
    "软管",
    "飞行模式",
    "蓝牙",
    "小憩",
    "省电",
    "显示设置",
    "设备信息",
    "亮度",
    "显示亮度间隔",
    "舒适",
    "辅助",
    "选项",
    "提醒",
    "配置",
    "模式",
    "设置压力",
    "设置最小压力",
    "设置最大压力",
    "呼气压力舒适",
    "软管",
    "空气过滤器",
    "自动开始治疗",
    "睡眠实验滴定模式",
    "语言",
    "日期",
    "时间",
    "压力单位",
    "诊断数据",
    "恢复默认",
    "删除数据",
    "关机",
    "工厂选项",
    "工厂诊断",
    "制造建立",
    "风机测试程序",
    "参数调节",
    "英文",
    "中文",
    "日文"
};

const QStringList Providers::titleTextList_JP = {
    "治療",
    "睡眠レポート",
    "マスクのオプション",
    "設定",
    "マスク適合テスト",
    "乾燥マスク",
    "眠りにつく",
    "坂をのぼる",
    "快適レベル",
    "自動治療",
    "マスク",
    "ホース",
    "飛行モード",
    "ブルートゥース",
    "ちょっと休憩する",
    "電力を節約する",
    "設定を表示",
    "デバイス情報",
    "明るさ",
    "輝度の間隔を表示",
    "快適である",
    "補助",
    "オプション",
    "リマインダ",
    "設定",
    "モード",
    "圧力を設定",
    "最小圧力を設定",
    "最大圧力を設定",
    "呼気圧が快適です",
    "ホース",
    "エアフィルター",
    "自動的に治療を開始する",
    "睡眠試験滴定モード",
    "言語",
    "日付",
    "時間",
    "圧力単位",
    "診断データ",
    "デフォルトに戻す",
    "データを削除",
    "電源を切る",
    "工場オプション",
    "工場診断",
    "製造の確立",
    "ファンテストプログラム",
    "パラメータ調整",
    "英語",
    "中国語",
    "日本語"
};

const QString & Providers::getTitleTextString(int index) {
    if(globalVar.language == language_chinese)
    {
        globalVar.titleTextList_choose=titleTextList_ZH;
    }
    else if(globalVar.language==language_japanese)
    {
        globalVar.titleTextList_choose=titleTextList_JP;
    }
    //else if(globalVar.language==language_english)
    else
    {
        globalVar.titleTextList_choose=titleTextList_EN;
    }

//    if(index >= titleTextList.count()) {
//        qWarning() << Q_FUNC_INFO << "Invalid count" << index;
//        index = 0;
//    }
//    return titleTextList.at(index);

    if(index >= globalVar.titleTextList_choose.count()) {
        qWarning() << Q_FUNC_INFO << "Invalid count" << index;
        index = 0;
    }
    return globalVar.titleTextList_choose.at(index);
}

const QStringList Providers::iconString = {
    ":/icons/therapy.png",
    ":/icons/sleep_report.png",
    ":/icons/mask_options.png",
    ":/icons/settings.png",
    ":/icons/mask_fit.png",
    ":/icons/mask_dry.png",
    ":/icons/go_to_sleep.png",
    ":/icons/ramp.png",
    ":/icons/comfort_level.png",
    ":/icons/auto_start_therapy.png",
    ":/icons/mask.png",
    ":/icons/tube.png",
    ":/icons/airplane_mode.png",
    ":/icons/bluetooth_settings.png",
    ":/icons/snooze.png",
    ":/icons/power_saving.png",
    ":/icons/display_settings.png",
    ":/icons/device_info.png",
    ":/icons/brightness.png",
    ":/icons/display_dim_duration.png",
    ":/icons/comfort.png",
    ":/icons/accessories.png",
    ":/icons/options.png",
    ":/icons/reminders32.png",
    ":/icons/configuration.png",
    ":/icons/mode.png",
    ":/icons/ramp_start_pressure.png",
    ":/icons/exhale_pressure_comfort.png",
    ":/icons/air_tube.png",
    ":/icons/air_filter.png",
    ":/icons/auto_start_therapy.png",
    ":/icons/sleep_lab_titration_mode.png",
    ":/icons/language.png",
    ":/icons/date.png",
    ":/icons/time.png",
    ":/icons/pressure_units.png",
    ":/icons/engineer_debug.png",
    ":/icons/restore_defaults.png",
    ":/icons/erase_data.png",
    ":/icons/clinical_therapy.png",
    ":/icons/option_sleep report.png",
    ":/icons/manufacturing_diagnosis.png",
    ":/icons/manufacturing_setup.png",
    ":/icons/power.png",
};


const QString & Providers::getIconString(int index) {
    if(index >= iconString.count()) {
        qWarning() << Q_FUNC_INFO << "Invalid count" << index;
        index = 0;
    }
    return iconString.at(index);
}

//const QString navigationIconStr = ":/icons/navigation_icon.png";
const QString Providers::navigationIconStr = ":/icons/navigation_icon2.png";
const QString & Providers::getNavigationIconString() {
    return navigationIconStr;
}

const QStringList Providers::pressureUnitTextStr = {
    "cmH2O",//    "cmH<sub>2</sub>O",
    "hPa"
};
const QString & Providers::getPressureUnitTextString(int index) {
    if(index >= pressureUnitTextStr.count()) {
        qWarning() << Q_FUNC_INFO << "Invalid count" << index;
        index = 0;
    }
    return pressureUnitTextStr.at(index);
}

const QStringList Providers::unitTextStr = {
    "min",
    "%"
};
const QString & Providers::getUnitTextString(int index) {
    if(index >= unitTextStr.count()) {
        qWarning() << Q_FUNC_INFO << "Invalid count" << index;
        index = 0;
    }
    return unitTextStr.at(index);
}

const QStringList Providers::airFilterTypeStr = {
    "Standard",
    "HEPA"
};
const QString & Providers::getAirFilterTypeString(int index) {
    if(index >= airFilterTypeStr.count()) {
        qWarning() << Q_FUNC_INFO << "Invalid count" << index;
        index = 0;
    }
    return airFilterTypeStr.at(index);
}


const QStringList Providers::emojiIconString = {
    " ",
    ":/icons/bad_icon.png",
    ":/icons/intermediate_icon.png",
    ":/icons/good_icon.png"
};
const QString & Providers::getEmojiIconString(int index) {
    if(index >= emojiIconString.count()) {
        qWarning() << Q_FUNC_INFO << "Invalid count" << index;
        index = 0;
    }
return emojiIconString.at(index);
}

const QStringList Providers::monthStr = {
    "Jan","Feb","Mar","Apr","May","Jun","Jul",
    "Aug","Sep","Oct","Nov","Dec"
};
const QString & Providers::getMonthsTextString(int index) {
    if(index >= monthStr.count()) {
        qWarning() << Q_FUNC_INFO << "Invalid count" << index;
        index = 0;
    }
    return monthStr.at(index);
}
const QStringList & Providers::getMonthStringList(void) {
    return monthStr;
}

const QStringList Providers::dateStr = {
    "1","2","3","4","5","6","7","8","9","10",
    "11","12","13","14","15","16","17","18","19","20",
    "21","22","23","24","25","26","27","28","29","30","31"
};
const QString & Providers::getDateTextString(int index) {
    if(index >= dateStr.count()) {
        qWarning() << Q_FUNC_INFO << "Invalid count" << index;
        index = 0;
    }
    return dateStr.at(index);
}
const QStringList & Providers::getDateStringList(void) {
    return dateStr;
}

const QStringList Providers::yearStr = {
    "2017","2018","2019","2020","2021","2022","2023","2024","2025","2026","2027",
    "2028","2029","2030","2031","2032","2033","2034","2035","2036","2037","2038",
    "2039","2040"
};
const QString & Providers::getYearTextString(int index) {
    if(index >= yearStr.count()) {
        qWarning() << Q_FUNC_INFO << "Invalid count" << index;
        index = 0;
    }
    return yearStr.at(index);
}
const QStringList & Providers::getYearStringList(void) {
    return yearStr;
}

const QStringList Providers::hourStr = {
    "0",
    "1","2","3","4","5","6","7","8","9","10",
    "11","12","13","14","15","16","17","18","19","20",
    "21","22","23"
};
const QString & Providers::getHourTextString(int index) {
    if(index >= hourStr.count()) {
        qWarning() << Q_FUNC_INFO << "Invalid count" << index;
        index = 0;
    }
    return hourStr.at(index);
}
const QStringList & Providers::getHourStringList(void) {
    return hourStr;
}

const QStringList Providers::minuteStr = {
    "00",
    "01","02","03","04","05","06","07","08","09","10",
    "11","12","13","14","15","16","17","18","19","20",
    "21","22","23","24","25","26","27","28","29","30",
    "31","32","33","34","35","36","37","38","39","40",
    "41","42","43","44","45","46","47","48","49","50",
    "51","52","53","54","55","56","57","58","59"
};
const QString & Providers::getMinuteTextString(int index) {
    if(index >= minuteStr.count()) {
        qWarning() << Q_FUNC_INFO << "Invalid count" << index;
        index = 0;
    }
    return minuteStr.at(index);
}
const QStringList & Providers::getMinuteStringList(void) {
    return minuteStr;
}

const QStringList Providers::languageString = {
    "",
    "English",
    "Chinese",
    "Spanish"
};


const QStringList Providers::maskString = {
    "",
    "Nasal Pillow",
    "Nasal Mask"
};

const QString & Providers::getLanguageString(int index) {
    if(index >= languageString.count()) {
        qWarning() << Q_FUNC_INFO << "Invalid count" << index;
        index = 0;
    }
    return languageString.at(index);
}

const QString & Providers::getMaskTypeString(int index) {
    if(index >= maskString.count()) {
        qWarning() << Q_FUNC_INFO << "Invalid count" << index;
        index = 0;
    }
    return maskString.at(index);
}

const QStringList Providers::deviceInformation = {
    "HANCY001",
    "0000-0001",
    QString("%1.%2").arg(FIRMWARE_MAJOR_VERSION).arg(FIRMWARE_MINOR_VERSION),
    QString("%1.%2").arg(SOFTWARE_MAJOR_VERSION).arg(SOFTWARE_MINOR_VERSION),
    "Fresca",
    QString("X%1").arg(FRESCA_REV),//"X3"
};

const QString & Providers::getDeviceInformationString(int index) {
//    if(index == FIRMWARE_VERSION){
//        const QString localStr = QString("%1.%2").arg(FIRMWARE_MAJOR_VERSION).arg(FIRMWARE_MINOR_VERSION);
//        return localStr;
//    }else {
        return deviceInformation.at(index);
//    }
}


#define P_SLOP  758
#define F_SLOP  240
#define MOTOR_TEMP_COEFF_A      349
#define MOTOR_TEMP_COEFF_B      -38.66

double Providers::getFlowEngineeringValues(int rawData)
{
//return static_cast<double>(rawData)/F_SLOP;
return static_cast<double>(rawData)/globalVar.flow.slop;
}
double Providers::getPressureEngineeringValues(int rawData)
{
return static_cast<double>(rawData)/100;
}
double Providers::getPressureRawToEngineeringWithSlopValues(int rawData)
{
return static_cast<double>(rawData - globalVar.pressure.pressureOffset)/100;
}

double Providers::getMotorTempratureEngineeringValues(int rawData)
{
return (MOTOR_TEMP_COEFF_A + (MOTOR_TEMP_COEFF_B * qLn(rawData)));
}
double Providers::getBlowerSpeedEngineeringValues(int rawData)
{
return static_cast<double>(1000000)/rawData;
}
double Providers::getVoltageInEngineeringValues(int rawData)
{
return (static_cast<double>(rawData) * 3.3 * 57)/(4096 * 10);
}
double Providers::getCurrentInEngineeringValues(int rawData)
{
return (static_cast<double>(rawData) * 3.3)/(4096 * 0.039);
}

//const QString Providers::basePath = "/home/jigar/airbox/";
//const QString Providers::basePath = "/home/root/";
const QString Providers::basePath = "/run/media/mmcblk1p4/";

const QString Providers::localLogFiles = Providers::basePath +"LOCAL";
//const QString localLogFiles = "/root/LOCAL";
const QString & Providers::getLocalLogFilesPath(void)
{
return localLogFiles;
}

#ifdef _APP_DEVELOPMENT_BUILD
/* Finale required path */
//const QString edfLogFiles = "/home/root/LOG";
//const QString edfLogFiles = "/root/LOG";
#elif defined(_APP_PRODUCTION_BUILD)
/* Required to realize transfer at App developers */
//const QString edfLogFiles = "/run/media/mmcblk0p1/LOG";
//const QString edfLogFiles = "/sdcard/";
#endif
const QString Providers::edfLogFiles = Providers::basePath + "LOG";
const QString & Providers::getEdfLogFilesPath(void)
{
return edfLogFiles;
}

//const QString sdcardEdfLogFiles = "/sdcard/";
const QString Providers::sdcardEdfLogFiles = "/run/media/mmcblk0p1/";
const QString & Providers::getSdcardEdfLogFilesPath(void)
{
return sdcardEdfLogFiles;
}

/* Finale required path */
//const QString softwareUpdateFiles = "/home/root/updates";

/* Required to realize transfer at App developers */
//const QString softwareUpdateFiles = "/run/media/mmcblk0p1/updates";

const QString Providers::softwareUpdateFiles = Providers::sdcardEdfLogFiles + "updates";
const QString & Providers::getsoftwareUpdateFilesPath(void)
{
return softwareUpdateFiles;
}

const QString Providers::errorLogFiles = Providers::basePath + "error.txt";
const QString & Providers::getErrorLogFilesPath(void)
{
return errorLogFiles;
}


void Providers::getGoToSleepTime(int * tMinutes,int * tSeconds)
{
    *tMinutes = 0;
    *tSeconds = 0;

    if(globalVar.goToSleep.state == On){
        *tMinutes = globalVar.goToSleep.goToSleepTime;
    } else {
        globalVar.goToSleep.countMinutes = 0;
        globalVar.goToSleep.countSeconds = 0;
    }
}

void Providers::getRampTime(int * tMinutes,int * tSeconds)
{
    *tMinutes = 0;
    *tSeconds = 0;

    if(globalVar.rampTime.state == On){
        *tMinutes = globalVar.rampTime.rampTime;
    } else {
        globalVar.rampTime.countMinutes = 0;
        globalVar.rampTime.countSeconds = 0;
    }
}
