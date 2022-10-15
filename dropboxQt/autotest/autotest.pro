################################################################
# autotest generation (internal profiling usage)               #
#                                                              #
################################################################


QT       += core network
QT       -= gui
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE = app

SRC_DIR = ../src
INCLUDEPATH += $${SRC_DIR}

##############################################################
#  specify path to the dropboxQt lib, on windows it can be   #
#   ../../prj/debug/ on unix - shadow build path             #
##############################################################

unix {
     LIBS += -L../prj/ -ldropboxQt
}

win32 {
      LIBS += -L../prj/debug/ -ldropboxQt
}

DEFINES += API_QT_AUTOTEST

SOURCES += main.cpp

