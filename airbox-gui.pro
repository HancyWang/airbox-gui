#-------------------------------------------------
#
# Project created by QtCreator 2017-11-11T08:59:07
#
#-------------------------------------------------

QT       += core gui bluetooth widgets # webkitwidgets

CONFIG += c++11
TEMPLATE = lib
CONFIG  += plugin

# Enable IPC related routines
DEFINES += ENABLE_IPC
# Enable Hardware related routines
DEFINES += ENABLE_HARDWARE

# Enable Bluetooth related routines
DEFINES += ENABLE_BLUETOOTH

# Enable Password Prompt related routines
DEFINES += ENABLE_PASSWORD

TARGET = airbox_gui
TEMPLATE = app

#TRANSLATIONS = chinese.ts \
#                japanese.ts \

SOURCES += main.cpp \
    screens/backgroundwindow.cpp \
    screens/diagnosticdatascreen.cpp \
    screens/selectlanguagewindowclinical.cpp \
    widgets/button1.cpp \
    widgets/button2.cpp \
    widgets/switch.cpp \
    widgets/button3.cpp \
    widgets/button4.cpp \
    widgets/button5.cpp \
    widgets/therapy_widget.cpp \
    screens/settingswindowbasic.cpp \
    screens/gotosleepsettingsbasic.cpp \
    screens/rampstartsettingsbasic.cpp \
    screens/snoozetimesettingsbasic.cpp \
    screens/bluetoothsettingsbasic.cpp \
    screens/displaysettingssettingsbasic.cpp \
    screens/brightnessadjustbrightnesssettingsbasic.cpp \
    screens/displaydimbrightnesssettingsbasic.cpp \
    screens/deviceinfosettingsbasic.cpp \
    screens/sleepreportwindowbasic.cpp \
    screens/sleepreportmorewindowbasic.cpp \
    screens/homewindowbasic.cpp \
    screens/maskoptionsbasic.cpp \
    screens/maskdryoptionsbasic.cpp \
    screens/maskfittestoptionsbasic.cpp \
    screens/therapywindowbasic.cpp \
    screens/snoozeexitscreenbasic.cpp \
    widgets/waitingspinnerwidget.cpp \
    screens/notificationtray.cpp \
    screens/dropdownselector.cpp \
    screens/homewindowclinical.cpp \
    screens/settingswindowclinical.cpp \
    screens/therapywindowclinical.cpp \
    screens/setpressureclinical.cpp \
    screens/comfortwindowclinical.cpp \
    screens/exhalepressurecomfortlevel.cpp \
    screens/accessorieswindowclinical.cpp \
    screens/airfilterwindowclinical.cpp \
    screens/optionswindowclinical.cpp \
    screens/configurationwindowclinical.cpp \
    screens/erasedataconfigurationclinical.cpp \
    screens/restoredefaultswindowclinical.cpp \
    screens/pressureunitconfigurationclinical.cpp \
    screens/reminderwindowsettingsclinical.cpp \
    screens/airfilterwindowreminderclinical.cpp \
    screens/maskwindowreminderclinical.cpp \
    screens/airtubewindowreminderclinical.cpp \
    widgets/wheelwidget.cpp \
    screens/datewindowclinical.cpp \
    screens/timewindowclinical.cpp \
    global.cpp \
    application/datalogging.cpp \
    screens/blowertestapplication.cpp \
    application/datavalidation.cpp \
    application/brightnesscontrolthread.cpp \
    screens/modewindowtherapyclinical.cpp \
    screens/maskoptionstherapywindowclinical.cpp \
    screens/setminpressureclinical.cpp \
    screens/setmaxpressureclinical.cpp \
    screens/manufacturingdiagnosisscreen.cpp \
    screens/manufacturingsetupscreen.cpp \
    screens/brightnessoffsetscreen.cpp \
    screens/parametertunningscreen.cpp \
    screens/enterserialnumber.cpp \
    screens/poweroffoptions.cpp \
    ble/bluetoothinit.cpp \
    screens/pressureoffsetscreen.cpp \
    logging/edfgenerator.cpp \
    screens/passwordcheckscreen.cpp \
    screens/manufacturingoptionsscreen.cpp \
    screens/bluetoothdebugscreen.cpp \
    screens/activereminderscreen.cpp \
    screens/resetreminderwarning.cpp \
    screens/sdcardformatscreen.cpp \
    logging/edflib.c \
    application/peripheralcontrol.cpp \
    screens/warninginfoscreen.cpp \
    application/prucontrolclass.cpp \
    screens/flowslopscreen.cpp \
    ble/blesetlogtypecommand.cpp \
    ble/blesenddatacommand.cpp \
    ble/bleretrievecommand.cpp \
    ble/bleretransmitcommand.cpp \
    ble/blepacketdelaycommand.cpp \
    ble/blecommand.cpp \
    ble/blecancelcommand.cpp \
    ble/airboxfiletransferservice.cpp

FORMS += \
    screens/backgroundwindow.ui \
    screens/diagnosticdatascreen.ui \
    screens/selectlanguagewindowclinical.ui \
    screens/settingswindowbasic.ui \
    screens/gotosleepsettingsbasic.ui \
    screens/rampstartsettingsbasic.ui \
    screens/snoozetimesettingsbasic.ui \
    screens/bluetoothsettingsbasic.ui \
    screens/displaysettingssettingsbasic.ui \
    screens/brightnessadjustbrightnesssettingsbasic.ui \
    screens/displaydimbrightnesssettingsbasic.ui \
    screens/deviceinfosettingsbasic.ui \
    screens/sleepreportmorewindowbasic.ui \
    screens/sleepreportwindowbasic.ui \
    screens/homewindowbasic.ui \
    screens/maskoptionsbasic.ui \
    screens/maskdryoptionsbasic.ui \
    screens/maskfittestoptionsbasic.ui \
    screens/therapywindowbasic.ui \
    screens/snoozeexitscreenbasic.ui \
    screens/notificationtray.ui \
    screens/dropdownselector.ui \
    screens/homewindowclinical.ui \
    screens/settingswindowclinical.ui \
    screens/therapywindowclinical.ui \
    screens/setpressureclinical.ui \
    screens/comfortwindowclinical.ui \
    screens/exhalepressurecomfortlevel.ui \
    screens/accessorieswindowclinical.ui \
    screens/airfilterwindowclinical.ui \
    screens/optionswindowclinical.ui \
    screens/configurationwindowclinical.ui \
    screens/erasedataconfigurationclinical.ui \
    screens/restoredefaultswindowclinical.ui \
    screens/pressureunitconfigurationclinical.ui \
    screens/reminderwindowsettingsclinical.ui \
    screens/airfilterwindowreminderclinical.ui \
    screens/maskwindowreminderclinical.ui \
    screens/airtubewindowreminderclinical.ui \
    screens/datewindowclinical.ui \
    screens/timewindowclinical.ui \
    screens/blowertestapplication.ui \
    screens/modewindowtherapyclinical.ui \
    screens/maskoptionstherapywindowclinical.ui \
    screens/setminpressureclinical.ui \
    screens/setmaxpressureclinical.ui \
    screens/manufacturingdiagnosisscreen.ui \
    screens/manufacturingsetupscreen.ui \
    screens/brightnessoffsetscreen.ui \
    screens/parametertunningscreen.ui \
    screens/enterserialnumber.ui \
    screens/poweroffoptions.ui \
    screens/pressureoffsetscreen.ui \
    screens/passwordcheckscreen.ui \
    screens/manufacturingoptionsscreen.ui \
    screens/bluetoothdebugscreen.ui \
    screens/activereminderscreen.ui \
    screens/resetreminderwarning.ui \
    screens/sdcardformatscreen.ui \
    screens/warninginfoscreen.ui \
    screens/flowslopscreen.ui

HEADERS += \
    screens/backgroundwindow.h \
    constants.h \
    screens/diagnosticdatascreen.h \
    screens/selectlanguagewindowclinical.h \
    widgets/button1.h \
    widgets/button2.h \
    widgets/button3.h \
    widgets/button4.h \
    widgets/button5.h \
    widgets/switch.h \
    widgets/therapy_widget.h \
    screens/settingswindowbasic.h \
    screens/gotosleepsettingsbasic.h \
    screens/rampstartsettingsbasic.h \
    screens/snoozetimesettingsbasic.h \
    screens/bluetoothsettingsbasic.h \
    screens/displaysettingssettingsbasic.h \
    screens/brightnessadjustbrightnesssettingsbasic.h \
    screens/displaydimbrightnesssettingsbasic.h \
    screens/deviceinfosettingsbasic.h \
    screens/sleepreportmorewindowbasic.h \
    screens/sleepreportwindowbasic.h \
    screens/homewindowbasic.h \
    screens/maskoptionsbasic.h \
    screens/maskdryoptionsbasic.h \
    screens/maskfittestoptionsbasic.h \
    screens/therapywindowbasic.h \
    screens/snoozeexitscreenbasic.h \
    variables.h \
    ex_variables.h \
    application.h \
    widgets/waitingspinnerwidget.h \
    screens/notificationtray.h \
    screens/dropdownselector.h \
    screens/homewindowclinical.h \
    screens/settingswindowclinical.h \
    screens/therapywindowclinical.h \
    screens/setpressureclinical.h \
    screens/comfortwindowclinical.h \
    screens/exhalepressurecomfortlevel.h \
    screens/accessorieswindowclinical.h \
    screens/airfilterwindowclinical.h \
    screens/optionswindowclinical.h \
    screens/configurationwindowclinical.h \
    screens/erasedataconfigurationclinical.h \
    screens/restoredefaultswindowclinical.h \
    screens/pressureunitconfigurationclinical.h \
    screens/reminderwindowsettingsclinical.h \
    screens/airfilterwindowreminderclinical.h \
    screens/maskwindowreminderclinical.h \
    screens/airtubewindowreminderclinical.h \
    widgets/wheelwidget.h \
    screens/datewindowclinical.h \
    screens/timewindowclinical.h \
    global.h \
    application/datalogging.h \
    screens/blowertestapplication.h \
    application/datavalidation.h \
    application/brightnesscontrolthread.h \
    screens/modewindowtherapyclinical.h \
    screens/maskoptionstherapywindowclinical.h \
    screens/setminpressureclinical.h \
    screens/setmaxpressureclinical.h \
    screens/manufacturingdiagnosisscreen.h \
    screens/manufacturingsetupscreen.h \
    screens/brightnessoffsetscreen.h \
    screens/parametertunningscreen.h \
    screens/enterserialnumber.h \
    screens/poweroffoptions.h \
    ble/bluetoothinit.h \
    screens/pressureoffsetscreen.h \
    logging/edfgenerator.h \
    screens/passwordcheckscreen.h \
    screens/manufacturingoptionsscreen.h \
    screens/bluetoothdebugscreen.h \
    screens/activereminderscreen.h \
    screens/resetreminderwarning.h \
    screens/sdcardformatscreen.h \
    logging/edflib.h \
    application/peripheralcontrol.h \
    screens/warninginfoscreen.h \
    application/ipc_application.h \
    application/prucontrolclass.h \
    screens/flowslopscreen.h \
    ble/blesetlogtypecommand.h \
    ble/blesenddatacommand.h \
    ble/bleretrievecommand.h \
    ble/bleretransmitcommand.h \
    ble/blepacketdelaycommand.h \
    ble/blecommandfactory.h \
    ble/blecommand.h \
    ble/blecancelcommand.h \
    ble/airboxfiletransferservice.h \
    ble/airboxdeviceinformationservice.h \
    application.h \
    shareddata.h


target.path += /home/root
INSTALLS += target

MOC_DIR = mocs
UI_DIR = ui_dir
OBJECTS_DIR = objects
DESTDIR = bin

RESOURCES += \
    rsc/resource.qrc \
    translations.qrc

# Required to speed up compilation time as default
# qt files are not going to recompile again
#PRECOMPILED_HEADER = pre_compiled.h
#CONFIG += precompile_header
#


DISTFILES +=

QMAKE_CXXFLAGS_RELEASE *= -O3
QMAKE_RESOURCE_FLAGS += -no-compress
# -mno-unaligned-access

## Differentiate production & development environment
#_APP_PRODUCTION_BUILD
#_APP_DEVELOPMENT_BUILD
#DEFINES += _APP_DEVELOPMENT_BUILD
DEFINES += _APP_PRODUCTION_BUILD

##################################################
#    Defines for production use
##################################################
QT_NO_DEBUG_OUTPUT
QT_NO_INFO_OUTPUT
QT_NO_WARNING_OUTPUT


