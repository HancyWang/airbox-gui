#ifndef CONSTANTS_H
#define CONSTANTS_H




#define DEBUG_AIRBOX_APP    1

//#define DEBUG_AIRBOX_WIDGETS    0

#define WINDOW_ANIMATION_OPEN_DURATION      250
#define WINDOW_ANIMATION_CLOSE_DURATION     250

#define WINDOW_CHILD_EFFECT_COLOR       0x505050

#define WINDOW_OPEN_TRANSITION       QEasingCurve::InOutCubic
#define WINDOW_CLOSE_TRANSITION      QEasingCurve::InOutCubic

//#define WINDOW_OPEN_TRANSITION       QEasingCurve::InOutCubic
//#define WINDOW_CLOSE_TRANSITION      QEasingCurve::OutInCubic


#define THERAPY_SNOOZE_FILL_COLOR      0xFFA500 //Orange
#define THERAPY_GO_TO_SLEEP_COLOR      0xFFFF00 //Yellow
#define THERAPY_NORMAL_FILL_COLOR      0x1979BA //Blue
#define THERAPY_NORMAL_BLANK_COLOR     0x999999

#define RAMP_START_PRESSURE(a)      (a/10)

#define PRODUCT_START_YEAR      2017


#define USER_CLINICAL_MODE_SWITCHING_TIME       1000

/*
 *
 * Parameter Max and Min Values
 *
 */

#define TARGET_PRESSURE_MIN     4
#define TARGET_PRESSURE_MAX     20

#define AIR_FILTER_TYPE_MIN     0
#define AIR_FILTER_TYPE_MAX     1

#define PRESSURE_UNIT_MIN       0
#define PRESSURE_UNIT_MAX       1

#define PRESSURE_OFFSET_MIN       0
#define PRESSURE_OFFSET_MAX       4000

#define FLOW_SLOP_MIN       0
#define FLOW_SLOP_MAX       4000

#define DISPLAY_DIM_DURATION_MIN        1
#define DISPLAY_DIM_DURATION_MAX        10
#define DISPLAY_DIM_DURATION_INTERVAL   1

#define SNOOZE_TIME_MIN     1
#define SNOOZE_TIME_MAX     30
#define SNOOZE_CHANGE_INTERVAL      1

#define SLEEP_REPORT_DURATION_MIN   1
#define SLEEP_REPORT_DURATION_MAX   6

#define BRIGHTNESS_LEVEL_MIN    25//1
#define BRIGHTNESS_LEVEL_MAX    100

#define RAMP_TIME_MIN   0
#define RAMP_TIME_MAX   45
#define RAMP_CHANGE_INTERVAL    1//5

#define GO_TO_SLEEP_TIME_MIN   0
#define GO_TO_SLEEP_TIME_MAX   45
#define GO_TO_SLEEP_TIME_CHANGE_INTERVAL    1//5

#define SLEEP_REPORT_TYPE_CUSTOM    0
#define SLEEP_REPORT_TYPE_DEFAULT   1

#define SLEEP_REPORT_BASIC          1
#define SLEEP_REPORT_EXTENDED       2

#define REM_MASK_DURATION_MIN      3
#define REM_MASK_DURATION_MAX      24

#define REM_AIRTUBE_DURATION_MIN      3
#define REM_AIRTUBE_DURATION_MAX      24

#define REM_AIRFILTER_DURATION_MIN      1
#define REM_AIRFILTER_DURATION_MAX      24

#define HOSE_SIZE_MM        9

enum openCloseStatus {
    Close=0,
    Open
};

enum onOffStatus {
    off=0,
    on
};



#endif // CONSTANTS_H
