QT       += network xml
QT       -= gui
CONFIG += staticlib
CONFIG -= flat
TEMPLATE = lib

CONFIG += c++17

macx{equals(QT_ARCH, arm64) {
    QMAKE_CC = /opt/homebrew/opt/llvm/bin/clang
    QMAKE_CXX = /opt/homebrew/opt/llvm/bin/clang++
    QMAKE_LINK = /opt/homebrew/opt/llvm/bin/clang++
    QMAKE_CFLAGS += -fopenmp -ftree-vectorize
    QMAKE_CXXFLAGS += -fopenmp -std=c++17 -ftree-vectorize
    INCLUDEPATH += -I/opt/homebrew/opt/llvm/include
    LIBS += -L/opt/homebrew/opt/llvm/lib -lomp -L/opt/homebrew/opt/openssl/lib -lssl
    QMAKE_APPLE_DEVICE_ARCHS = arm64
}}

API_MODULES = async auth files properties sharing team team_common team_policies users endpoint
SRC_DIR = ../src
API_DIR = $${SRC_DIR}/dropbox

for(m, API_MODULES){
       d = $${API_DIR}/$${m}
       exists($${d}){
	   HEADERS += $${d}/*.h	
	   SOURCES += $${d}/*.cpp
       }
}

HEADERS += $${API_DIR}/*.h
SOURCES += $${API_DIR}/*.cpp

################################################################
# autotest generation (internal profiling usage)               #
#                                                              #
# HEADERS += $${API_DIR}/AUTOTEST/*.h                          #
# SOURCES += $${API_DIR}/AUTOTEST/*.cpp                        #
# DEFINES += API_QT_AUTOTEST                                   #
################################################################


INCLUDEPATH += $${SRC_DIR}

