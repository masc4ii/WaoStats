# Include common configurations.
include(QMapControl.pri)

# Capture whether this is a release/debug build.
#CONFIG(debug, debug|release) {
#    # Target name.
#    TARGET = qmapcontrold
#}
#CONFIG(release, debug|release) {
#    # Target name.
#    TARGET = qmapcontrol
#}

macx{equals(QT_ARCH, arm64) {
    QMAKE_CC = /opt/homebrew/opt/llvm/bin/clang
    QMAKE_CXX = /opt/homebrew/opt/llvm/bin/clang++
    QMAKE_LINK = /opt/homebrew/opt/llvm/bin/clang++
    QMAKE_CFLAGS += -fopenmp -ftree-vectorize
    QMAKE_CXXFLAGS += -fopenmp -std=c++15 -ftree-vectorize
    INCLUDEPATH += -I/opt/homebrew/opt/llvm/include
    LIBS += -L/opt/homebrew/opt/llvm/lib -lomp -L/opt/homebrew/opt/openssl/lib -lssl
    QMAKE_APPLE_DEVICE_ARCHS = arm64
}}

# Target version.
VERSION = 1.0.0

# Build a library.
#TEMPLATE = lib

# Required defines.
DEFINES += QMAPCONTROL_LIBRARY

# Add header files.
HEADERS +=                                      \
    QMapControl/qmapcontrol_global.h                        \
    QMapControl/MapCopyrightString.h                        \
    QMapControl/Geometry.h                                  \
    QMapControl/GeometryLineString.h                        \
    QMapControl/GeometryPoint.h                             \
    QMapControl/GeometryPointShape.h                        \
    QMapControl/GeometryPointShapeScaled.h                  \
    QMapControl/GeometryPointArrow.h                        \
    QMapControl/GeometryPointCircle.h                       \
    QMapControl/GeometryPointImage.h                        \
    QMapControl/GeometryPointImageScaled.h                  \
    QMapControl/GeometryPolygon.h                           \
    QMapControl/GeometryPolygonImage.h                      \
    QMapControl/GeometryWidget.h                            \
    QMapControl/GPS_Position.h                              \
    QMapControl/ImageManager.h                              \
    QMapControl/Layer.h                                     \
    QMapControl/LayerGeometry.h                             \
    QMapControl/LayerMapAdapter.h                           \
    QMapControl/MapAdapter.h                                \
    QMapControl/MapAdapterGoogle.h                          \
    QMapControl/MapAdapterBing.h                            \
    QMapControl/MapAdapterOSM.h                             \
    QMapControl/MapAdapterOCM.h                             \
    QMapControl/MapAdapterOTM.h                             \
    QMapControl/MapAdapterMtbMap.h                          \
    QMapControl/MapAdapter4UM.h                             \
    QMapControl/MapAdapterThunderCycle.h                    \
    QMapControl/MapAdapterTile.h                            \
    QMapControl/MapAdapterWMS.h                             \
    QMapControl/MapAdapterYahoo.h                           \
    QMapControl/MapAdapterSigma.h                           \
    QMapControl/MapAdapterKomoot.h                          \
    QMapControl/NetworkManager.h                            \
    QMapControl/Point.h                                     \
    QMapControl/Projection.h                                \
    QMapControl/ProjectionEquirectangular.h                 \
    QMapControl/ProjectionSphericalMercator.h               \
    QMapControl/QMapControl.h                               \
    QMapControl/QuadTreeContainer.h                         \
# Third-party headers: QProgressIndicator
    QMapControl/QProgressIndicator.h                        \

# Add source files.
SOURCES +=                                      \
    QMapControl/MapCopyrightString.cpp                      \
    QMapControl/Geometry.cpp                                \
    QMapControl/GeometryLineString.cpp                      \
    QMapControl/GeometryPoint.cpp                           \
    QMapControl/GeometryPointShape.cpp                      \
    QMapControl/GeometryPointShapeScaled.cpp                \
    QMapControl/GeometryPointArrow.cpp                      \
    QMapControl/GeometryPointCircle.cpp                     \
    QMapControl/GeometryPointImage.cpp                      \
    QMapControl/GeometryPointImageScaled.cpp                \
    QMapControl/GeometryPolygon.cpp                         \
    QMapControl/GeometryPolygonImage.cpp                    \
    QMapControl/GeometryWidget.cpp                          \
    QMapControl/GPS_Position.cpp                            \
    QMapControl/ImageManager.cpp                            \
    QMapControl/Layer.cpp                                   \
    QMapControl/LayerGeometry.cpp                           \
    QMapControl/LayerMapAdapter.cpp                         \
    QMapControl/MapAdapter.cpp                              \
    QMapControl/MapAdapterGoogle.cpp                        \
    QMapControl/MapAdapterBing.cpp                          \
    QMapControl/MapAdapterOSM.cpp                           \
    QMapControl/MapAdapterOCM.cpp                           \
    QMapControl/MapAdapterOTM.cpp                           \
    QMapControl/MapAdapterMtbMap.cpp                        \
    QMapControl/MapAdapter4UM.cpp                           \
    QMapControl/MapAdapterThunderCycle.cpp                  \
    QMapControl/MapAdapterTile.cpp                          \
    QMapControl/MapAdapterWMS.cpp                           \
    QMapControl/MapAdapterYahoo.cpp                         \
    QMapControl/MapAdapterSigma.cpp                         \
    QMapControl/MapAdapterKomoot.cpp                        \
    QMapControl/NetworkManager.cpp                          \
    QMapControl/Projection.cpp                              \
    QMapControl/ProjectionEquirectangular.cpp               \
    QMapControl/ProjectionSphericalMercator.cpp             \
    QMapControl/QMapControl.cpp                             \
# Third-party sources: QProgressIndicator
    QMapControl/QProgressIndicator.cpp                      \

# Include GDAL-required files.
contains(DEFINES, QMC_GDAL) {
    message(Building with GDAL support...)

    # Add header files.
    HEADERS +=                                  \
        ESRIShapefile.h                         \
        LayerESRIShapefile.h                    \

    # Add source files.
    SOURCES +=                                  \
        ESRIShapefile.cpp                       \
        LayerESRIShapefile.cpp                  \

    # Add GDAL include path.
    INCLUDEPATH += $$(QMC_GDAL_INC)

    # Add GDAL library path and library (windows).
    win32:LIBS += -L$$(QMC_GDAL_LIB) -lgdal_i

    # Add GDAL library path and library (unix).
    unix:LIBS += -L$$(QMC_GDAL_LIB) -lgdal
}

# Capture whether this is a release/debug build.
CONFIG(debug, debug|release) {
    TARGET_TYPE = debug
}
CONFIG(release, debug|release) {
    TARGET_TYPE = release
}

# # Install details.
# # Has a prefix been specified?
# !isEmpty(prefix) {
#     # Change prefix to PREFIX.
#     PREFIX = $${prefix}/$$TARGET_TYPE
# }
# isEmpty(PREFIX) {
#     # Default to parent directory.
#     PREFIX = ../../../$$TARGET_TYPE
# }
# # Install headers to $${PREFIX}/include/QMapControl
# headers.path = $${PREFIX}/include/QMapControl
# headers.files = $${HEADERS}
# # Install target to $${PREFIX}/lib.
# target.path = $${PREFIX}/lib
# # Install headers and target.
# INSTALLS += target headers
