QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

macx{
    equals(QT_ARCH, arm64) {
        QMAKE_CC = /opt/homebrew/opt/llvm/bin/clang
        QMAKE_CXX = /opt/homebrew/opt/llvm/bin/clang++
        QMAKE_LINK = /opt/homebrew/opt/llvm/bin/clang++
        QMAKE_CFLAGS += -fopenmp -ftree-vectorize
        QMAKE_CXXFLAGS += -fopenmp -std=c++17 -ftree-vectorize
        INCLUDEPATH += -I/opt/homebrew/opt/llvm/include
        LIBS += -L/opt/homebrew/opt/llvm/lib -lomp -L/opt/homebrew/opt/openssl/lib -lssl
        QMAKE_APPLE_DEVICE_ARCHS = arm64
    }
    else: QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.13
}

#Define for FIT C SDK
DEFINES += FIT_USE_STDINT_H
DEFINES += FITC
include( fitc.pri )
#Define for FIT CPP SDK
#include( fitcpp.pri )

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include( QMapControl/QMapControl.pro )

#dropbox (run qmake and make in dropboxQt/prj/ before!)
INCLUDEPATH += dropboxQt/src
macx:  LIBS += -L$${PWD}/dropboxQt/prj/ -ldropboxQt
win32: LIBS += -L$${PWD}/dropboxQt/prj/release/ -ldropboxQt
linux-g++:  LIBS += -L$${PWD}/dropboxQt/prj/ -ldropboxQt

SOURCES += \
    AdbSelectDeviceDialog.cpp \
    AdbWrapper.cpp \
    DropBoxAuthDialog.cpp \
    GpxParser.cpp \
    LineEditEscDelete.cpp \
    OsmWidget.cpp \
    ProgressDialog.cpp \
    ServiceDialog.cpp \
    ServiceEntryDialog.cpp \
    Splash.cpp \
    StatisticsDialog.cpp \
    StatisticsPlot.cpp \
    ThreadTrack2Point.cpp \
    TourData.cpp \
    TourDataPlot.cpp \
    VScrollArea.cpp \
    main.cpp \
    MainWindow.cpp \
    qcustomplot/qcustomplot.cpp

HEADERS += \
    AdbSelectDeviceDialog.h \
    AdbWrapper.h \
    BikeEditingDelegate.h \
    DropBoxAuthDialog.h \
    Globals.h \
    GpxParser.h \
    HelperFunctions.h \
    LineEditEscDelete.h \
    MainWindow.h \
    OsmWidget.h \
    ProgressDialog.h \
    ServiceDialog.h \
    ServiceEntryDialog.h \
    Splash.h \
    StatisticsDialog.h \
    StatisticsPlot.h \
    ThreadTrack2Point.h \
    TourData.h \
    TourDataPlot.h \
    VScrollArea.h \
    qcustomplot/qcustomplot.h

FORMS += \
    AdbSelectDeviceDialog.ui \
    DropBoxAuthDialog.ui \
    MainWindow.ui \
    ProgressDialog.ui \
    ServiceDialog.ui \
    ServiceEntryDialog.ui \
    StatisticsDialog.ui

INCLUDEPATH += -I FitSDKRelease_21.105.00/cpp/

#Application version
VERSION_MAJOR = 1
VERSION_MINOR = 2
VERSION_PATCH = 0
VERSION_BUILD = 0

#Target version
DEFINES += "VERSION_MAJOR=$$VERSION_MAJOR"\
           "VERSION_MINOR=$$VERSION_MINOR"\
           "VERSION_PATCH=$$VERSION_PATCH"\
           "VERSION_BUILD=$$VERSION_BUILD"
VERSION = $${VERSION_MAJOR}.$${VERSION_MINOR}.$${VERSION_PATCH}.$${VERSION_BUILD}

win32{
    RC_ICONS = WaoStatsLogoMapSmall.ico
    QMAKE_TARGET_COMPANY = masc
    QMAKE_TARGET_DESCRIPTION = "Tool for Wahoo ELEMNT track statistics"
    QMAKE_TARGET_PRODUCT = WaoStats
    RC_CODEPAGE = 1252
}
macx{
    ICON = WaoStatsLogoMapSmall.icns
    QMAKE_INFO_PLIST = Info.plist
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc

#unpack & install adb on OSX
macx: QMAKE_POST_LINK += unzip -o ../WaoStats/adb/macOS/adb.zip $$escape_expand(\n\t)
macx: QMAKE_POST_LINK += "mv adb WaoStats.app/Contents/MacOS/" $$escape_expand(\n\t)
